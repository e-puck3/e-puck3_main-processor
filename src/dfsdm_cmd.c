#include <ch.h>
#include <hal.h>
#include "stdlib.h"
#include "string.h"
#include "chprintf.h"
#include "dfsdm.h"
#include "dfsdm_cmd.h"
#include "fatfs_cmd.h"

#define AUDIO_BUFFER_SIZE   4096
#define TIME_TO_RECORD_S    4
#define SAMPLE_RATE         43600

typedef struct wav_header {
    // RIFF Header
    char riff_header[4]; // Contains "RIFF"
    int32_t wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
    char wave_header[4]; // Contains "WAVE"

    // Format Header
    char fmt_header[4]; // Contains "fmt " (includes trailing space)
    int32_t fmt_chunk_size; // Should be 16 for PCM
    int16_t audio_format; // Should be 1 for PCM. 3 for IEEE Float
    int16_t num_channels;
    int32_t sample_rate;
    int32_t byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    int16_t sample_alignment; // num_channels * Bytes Per Sample
    int16_t bit_depth; // Number of bits per sample

    // Data
    char data_header[4]; // Contains "data"
    int32_t data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // uint8_t bytes[]; // Remainder of wave file is bytes
} wav_header;

// Pre filled WAV header for 32bits int mono channel PCM
static uint8_t wav_header_raw[] = { 0x52, 0x49, 0x46, 0x46,
                                    0xe4, 0x9e, 0x0a, 0x00,
                                    0x57, 0x41, 0x56, 0x45,
                                    0x66, 0x6d, 0x74, 0x20,
                                    0x10, 0x00, 0x00, 0x00,
                                    0x01, 0x00,
                                    0x01, 0x00,
                                    0x44, 0xac, 0x00, 0x00,
                                    0x10, 0xb1, 0x02, 0x00,
                                    0x04, 0x00,
                                    0x20, 0x00,
                                    0x64, 0x61, 0x74, 0x61,
                                    0xc0, 0x9e, 0x0a, 0x00};

static BSEMAPHORE_DECL(data_ready, true);
static int32_t *samples;

static void dfsdm_err_cb(void *p)
{
    (void) p;
    chSysHalt("DFSDM DMA error");
}

static void dfsdm_data_callback(void *p, int32_t *buffer, size_t n)
{
    (void) n;
    (void) buffer;

    /* Only a half buffer is used at a time. This means that while we are
     * processing one half of the buffer, the other half already captures the
     * new data. */
    osalDbgAssert(n == AUDIO_BUFFER_SIZE / 2, "Buffer size is invalid.");

    /* Check if it is the microphone we are using. */
    if ((int) p) {
        chSysLockFromISR();
        samples = buffer;
        chBSemSignalI(&data_ready);
        chSysUnlockFromISR();
    }
}

static int32_t mic1_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic1_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic1_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

static int32_t mic2_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic2_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic2_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

static int32_t mic3_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic3_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic3_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

static int32_t mic4_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic4_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic4_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

void cmd_dfsdm_usb(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    if (argc != 1) {
        chprintf(chp, "Usage: dfsdm_usb mic1|mic2|mic3|mic4\r\n");
        return;
    }

    /* We use the callback arg to store which microphone is used. */
    if (!strcmp(argv[0], "mic1")) {
        mic1_cfg.cb_arg = (void*) 1;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic2")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 1;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic3")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 1;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic4")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 1;
    } else{
        return;
    }

    dfsdm_start_conversion(&mic1_cfg, &mic2_cfg, &mic3_cfg, &mic4_cfg);

    chprintf(chp, "Done !\r\n");

    /* High pass filter params */
    const float tau = 1 / 20.; /* 1 / cutoff */
    const float dt = 1./44e3;  /* Sampling period */

    const float alpha = tau / (tau + dt);

    int32_t x_prev = 0, y = 0, x;

    while (true) {
        chBSemWait(&data_ready);

        /* First order high pass filtering is used to remove the DC component
         * of the signal. */
        for (uint32_t i = 0; i < AUDIO_BUFFER_SIZE / 2; i++) {
            x = samples[i];
            y = alpha * y + alpha * (x - x_prev);
            x_prev = x;
            samples[i] = (y<<13); // we have a 19bits encoded on a 32 bits
        }


        streamWrite(chp, (uint8_t *)samples, sizeof(mic1_buffer) / 2);
    }

}

void cmd_dfsdm_sd(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    FIL file_dat;   /* file object */
    FIL file_wav;   /* file object */
    FRESULT err;
    UINT nb_bytes;
    uint32_t bytes_written = 0;
    systime_t begin_time = 0;

    if (argc != 3) {
        chprintf(chp, "Usage: dfsdm_sd mic1|mic2|mic3|mic4 miliseconds_to_record file_name.wav\r\n");
        return;
    }

    /* We use the callback arg to store which microphone is used. */
    if (!strcmp(argv[0], "mic1")) {
        mic1_cfg.cb_arg = (void*) 1;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic2")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 1;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic3")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 1;
        mic4_cfg.cb_arg = (void*) 0;
    } else if(!strcmp(argv[0], "mic4")) {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 0;
        mic3_cfg.cb_arg = (void*) 0;
        mic4_cfg.cb_arg = (void*) 1;
    } else{
        return;
    }

    char *endptr;
    uint32_t milliseconds_to_read = strtol(argv[1], &endptr, 0);

    uint32_t bytes_to_Write = (SAMPLE_RATE * milliseconds_to_read * 4)/1000;

    char* file_name = argv[2];


    if (!mountSDCard()) {
        chprintf(chp, "FS: f_mount() failed. Is the SD card inserted?\r\n");
        return;
    }

     /*
     * Open the text file
     */
    err = f_open(&file_dat, "sound.dat", FA_READ | FA_WRITE | FA_CREATE_ALWAYS);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_open(\"sound.dat\") failed.\r\n");
        fverbose_error(chp, err);
        return;
    } else {
        chprintf(chp, "FS: f_open(\"sound.dat\") succeeded\r\n");
    }

    begin_time = chVTGetSystemTime();

    dfsdm_start_conversion(&mic1_cfg, &mic2_cfg, &mic3_cfg, &mic4_cfg);

    chprintf(chp, "Done !\r\n");

    /* High pass filter params */
    const float tau = 1 / 20.; /* 1 / cutoff */
    const float dt = 1./44e3;  /* Sampling period */

    const float alpha = tau / (tau + dt);

    int32_t x_prev = 0, y = 0, x;

    while (true) {
        chBSemWait(&data_ready);

        /* First order high pass filtering is used to remove the DC component
         * of the signal. */
        for (uint32_t i = 0; i < AUDIO_BUFFER_SIZE / 2; i++) {
            x = samples[i];
            y = alpha * y + alpha * (x - x_prev);
            x_prev = x;
            samples[i] = (y<<13); // we have a 19bits encoded on a 32 bits
        }

        err = f_write(&file_dat, (uint8_t *)samples, sizeof(mic1_buffer) / 2, &nb_bytes);
        if (err != FR_OK) {
            f_close(&file_dat);
            fverbose_error(chp, err);
        }
        bytes_written += nb_bytes;

        if(bytes_written >= bytes_to_Write){
            f_close(&file_dat);
            dfsdm_stop_conversion();
            chprintf(chp, "Captured %d samples in %d msec\r\n", bytes_written/4, chVTGetSystemTime() - begin_time);

            err = f_open(&file_dat, "sound.dat", FA_READ);
            if (err != FR_OK) {
                fverbose_error(chp, err);
                return;
            }
            err = f_open(&file_wav, file_name, FA_READ | FA_WRITE | FA_CREATE_ALWAYS);
            if (err != FR_OK) {
                fverbose_error(chp, err);
                return;
            }

            uint32_t* pointer = (uint32_t*)wav_header_raw;

            pointer[1] = 36 + bytes_written;
            pointer[10] = bytes_written;


            err = f_write(&file_wav, wav_header_raw, sizeof(wav_header_raw), &nb_bytes);
            if (err != FR_OK) {
                fverbose_error(chp, err);
                return;
            }
            uint8_t buffer[4];
            UINT nb_written = 0;
            chprintf(chp, "Creating the WAV file\r\n");
             /*
             * Do while the number of bytes read is equal to the number of bytes to read
             * (the buffer is filled)
             */
            do {
                /*
                 * Read the file.
                 */
                err = f_read(&file_dat, buffer, 4, &nb_bytes);
                if (err != FR_OK) {
                    fverbose_error(chp, err);
                    return;
                }
                err = f_write(&file_wav, buffer, nb_bytes, &nb_written);
                if (err != FR_OK) {
                    fverbose_error(chp, err);
                    return;
                }
            } while (nb_bytes>=4);

            f_close(&file_dat);
            f_close(&file_wav);
            unmountSDCard();
            return;
        }
    }

}
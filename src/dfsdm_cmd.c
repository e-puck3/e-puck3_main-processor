#include <ch.h>
#include <hal.h>
#include "string.h"
#include "chprintf.h"
#include "dfsdm.h"
#include "dfsdm_cmd.h"
#include "fatfs_cmd.h"

#define AUDIO_BUFFER_SIZE 1024
#define TIME_TO_RECORD_S 4
#define NB_BYTES_TO_WRITE (43600 * TIME_TO_RECORD_S * 4)

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
static wav_header my_wav;

BSEMAPHORE_DECL(data_ready, true);
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

// static int32_t mic2_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic2_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic1_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

void cmd_dfsdm(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    FIL file_dat;   /* file object */
    FIL file_wav;   /* file object */
    FRESULT err;
    UINT nb_bytes;
    uint32_t bytes_written = 0;
    systime_t begin_time = 0;
    // uint8_t samples_to_read = 4; // we read 4 bytes at a time (one uint32_t sample)
    // uint8_t buffer[samples_to_read] ;

    if (argc != 1) {
        chprintf(chp, "Usage: dfsdm mic1|mic2\r\n");
        return;
    }

    /* We use the callback arg to store which microphone is used. */
    if (!strcmp(argv[0], "mic1")) {
        mic1_cfg.cb_arg = (void*) 1;
        mic2_cfg.cb_arg = (void*) 0;
    } else {
        mic1_cfg.cb_arg = (void*) 0;
        mic2_cfg.cb_arg = (void*) 1;
    }

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
    dfsdm_start_conversion(&mic1_cfg, &mic2_cfg);

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
            samples[i] = y;
        }

        err = f_write(&file_dat, (uint8_t *)samples, sizeof(mic1_buffer) / 2, &nb_bytes);
        if (err != FR_OK) {
            f_close(&file_dat);
            fverbose_error(chp, err);
        }
        bytes_written += nb_bytes;
        // streamWrite(chp, (uint8_t *)samples, sizeof(mic1_buffer) / 2);

        if(bytes_written >= NB_BYTES_TO_WRITE){
            f_close(&file_dat);
            dfsdm_stop_conversion();
            chprintf(chp, "Captured %d samples in %d msec\r\n", bytes_written/4, chVTGetSystemTime() - begin_time);

            // err = f_open(&file_dat, "sound.dat", FA_READ);
            // if (err != FR_OK) {
            //     fverbose_error(chp, err);
            //     return;
            // }
            // err = f_open(&file_wav, "sound.wav", FA_READ | FA_WRITE | FA_CREATE_ALWAYS);
            // if (err != FR_OK) {
            //     fverbose_error(chp, err);
            //     return;
            // }
            // strcpy(my_wav.riff_header, "RIFF");
            // my_wav.wav_size = 36 + bytes_written; //Given in bytes: 36 bytes for header
            // strcpy(my_wav.wave_header, "WAVE");
            // strcpy(my_wav.fmt_header, "fmt ");
            // my_wav.fmt_chunk_size = 16;
            // my_wav.audio_format = 1;
            // my_wav.num_channels = 1;
            // my_wav.sample_rate = 44100;
            // my_wav.byte_rate = 44100;
            // my_wav.sample_alignment = 2;
            // my_wav.bit_depth = 16;
            // strcpy(my_wav.data_header, "data");
            // my_wav.data_bytes = bytes_written;

            // err = f_write(&file_wav, &my_wav, sizeof(my_wav), &nb_bytes);
            // if (err != FR_OK) {
            //     fverbose_error(chp, err);
            //     return;
            // }

            //  /*
            //  * Do while the number of bytes read is equal to the number of bytes to read
            //  * (the buffer is filled)
            //  */
            // do {
            //     /*
            //      * Clear the buffer.
            //      */
            //     memset(Buffer,0,sizeof(Buffer));
            //     /*
            //      * Read the file.
            //      */
            //     err=f_read(&fsrc, Buffer, ByteToRead, &nb_bytes);
            //     if (err != FR_OK) {
            //         chprintf(chp, "FS: f_read() failed\r\n");
            //         fverbose_error(chp, err);
            //         f_close(&fsrc);
            //         return;
            //     }
            //     chprintf(chp, "%s", Buffer);
            // } while (nb_bytes>=ByteToRead);

            unmountSDCard();
            return;
        }
    }

}
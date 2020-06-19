#include <ch.h>
#include <hal.h>
#include "string.h"
#include "chprintf.h"
#include "dfsdm.h"
#include "dfsdm_cmd.h"

#define AUDIO_BUFFER_SIZE 1000

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

static int32_t mic2_buffer[AUDIO_BUFFER_SIZE];
static DFSDM_config_t mic2_cfg = {
    .end_cb = dfsdm_data_callback,
    .error_cb = dfsdm_err_cb,
    .samples = mic2_buffer,
    .samples_len = AUDIO_BUFFER_SIZE
};

void cmd_dfsdm(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void) argc;
    (void) argv;

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

    dfsdm_start_conversion(&mic1_cfg, &mic2_cfg);

    chprintf(chp, "Done !\r\n");

    /* High pass filter params */
    const float tau = 1 / 20.; /* 1 / cutoff */
    const float dt = 1./44e3;  /* Sampling period */

    const float alpha = tau / (tau + dt);

    int32_t x_prev = 0, y = 0, x;

    while (true) {
        chBSemWait(&data_ready);
        size_t i;

        /* First order high pass filtering is used to remove the DC component
         * of the signal. */
        for (i = 0; i < AUDIO_BUFFER_SIZE / 2; i++) {
            x = samples[i];
            y = alpha * y + alpha * (x - x_prev);
            x_prev = x;
            samples[i] = y;
        }

        streamWrite(chp, (uint8_t *)samples, sizeof(mic1_buffer) / 2);
    }
}
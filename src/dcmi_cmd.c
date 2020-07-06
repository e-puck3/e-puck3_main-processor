#include <ch.h>
#include <hal.h>
#include "string.h"
#include "chprintf.h"
#include "dcmi.h"
#include "dcmi_cmd.h"

#define TOTAL_SAMPLES_TO_SEND  ((320*240)/4)
#define CAM_BUFFER_SIZE         1200


static BSEMAPHORE_DECL(data_ready, true);
static uint32_t *samples;

static void dcmi_err_cb(void *p)
{
    (void) p;
    chSysHalt("DCMI DMA error");
}
static uint32_t cam_counter = 0;
static volatile uint32_t byte_sent = 0;
static void dcmi_data_callback(void *p, uint32_t *buffer, size_t n)
{
    (void) p;

    cam_counter += n;
    samples = buffer;
    chSysLockFromISR();
    chBSemSignalI(&data_ready);
    chSysUnlockFromISR();
}

static uint32_t cam_buffer[CAM_BUFFER_SIZE];
static DCMI_config_t cam_cfg = {
    .end_cb = dcmi_data_callback,
    .error_cb = dcmi_err_cb,
    .samples = cam_buffer,
    .samples_len = CAM_BUFFER_SIZE
};

void cmd_dcmi(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    cam_counter = 0;
    byte_sent = 0;
    dcmi_start_capture();

    chprintf(chp, "Done !\r\n");

    while (true) {
        chBSemWait(&data_ready);

        byte_sent += streamWrite(chp, (uint8_t *)samples, sizeof(cam_buffer) / 2); 

        if(cam_counter == TOTAL_SAMPLES_TO_SEND){
            return;
        }
    }

}

void dcmi_start_from_shell(void){
    dcmi_start(&cam_cfg);
}
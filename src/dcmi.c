#include <ch.h>
#include <hal.h>
#include "dcmi.h"


typedef struct {
    const stm32_dma_stream_t *dma_stream;
    DCMI_config_t *cfg;
} DCMI_driver_t;

DCMI_driver_t cam1_drv;

/** Function called on DMA DCMI interrupt. */
static void dcmi_serve_dma_interrupt(void *p, uint32_t flags){
    DCMI_driver_t *drv = (DCMI_driver_t *) p;

    /* DMA errors handling.*/
    if ((flags & (STM32_DMA_ISR_TEIF | STM32_DMA_ISR_DMEIF)) != 0) {
        if (drv->cfg->error_cb != NULL) {
            drv->cfg->error_cb(drv->cfg->cb_arg);
        }
    } else if ((flags & STM32_DMA_ISR_TCIF) != 0) {
        /* End of the second half of the circular buffer. */
        if (drv->cfg->end_cb != NULL) {
            size_t half = drv->cfg->samples_len / 2;
            drv->cfg->end_cb(drv->cfg->cb_arg,
                             &drv->cfg->samples[half],
                             half);
        }
    } else if ((flags & STM32_DMA_ISR_HTIF) != 0) {
        /* End of the first half of the circular buffer. */
        if (drv->cfg->end_cb != NULL) {
            size_t half = drv->cfg->samples_len / 2;
            drv->cfg->end_cb(drv->cfg->cb_arg,
                             drv->cfg->samples,
                             half);
        }
    }
}

void dcmi_start(void){
    /* Send clock to peripheral. */
    rccEnableAHB2(RCC_AHB2ENR_DCMIEN, false);

    /* DCMI config */

    /* Allocate DMA streams. */
   

}

void dcmi_start_capture(DCMI_config_t *cam_config){

}

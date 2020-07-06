#include <ch.h>
#include <hal.h>
#include "dcmi.h"


typedef struct {
    const stm32_dma_stream_t *dma_stream;
    DCMI_config_t *cfg;
} DCMI_driver_t;

DCMI_driver_t cam_drv;

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
            // size_t half = drv->cfg->samples_len / 2;
            // drv->cfg->end_cb(drv->cfg->cb_arg,
            //                  &drv->cfg->samples[half],
            //                  half);
            drv->cfg->end_cb(drv->cfg->cb_arg,
                             drv->cfg->samples,
                             drv->cfg->samples_len);
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

void dcmi_start(DCMI_config_t *cam_config){

    cam_drv.cfg = cam_config;

    /* Send clock to peripheral. */
    rccEnableAHB2(RCC_AHB2ENR_DCMIEN, false);

    /* DCMI config */
    // nvicEnableVector(DCMI_IRQn, STM32_DCMI_IRQ_PRIORITY);

    DCMI->CR  &= ~(DCMI_CR_CAPTURE | DCMI_CR_ENABLE); // Do not enable here because we don't still know the capture mode that will be used.
    DCMI->CR |= DCMI_CR_PCKPOL;
    DCMI->CR |= DCMI_CR_EDM_1; // 12bits data capture
    // Interrupt enable register.
    // DCMI->IER |= DCMI_IER_FRAME_IE; // Capture complete.
    //DCMI->IER |= DCMI_IER_VSYNC_IE; // Interrupt generated when vsync become active (start of frame).
    // DCMI->IER |= DCMI_IER_OVF_IE; // Overrun (by DMA).
    // Control Register.


    /* Allocate DMA streams. */
    cam_drv.dma_stream = dmaStreamAlloc(STM32_DCMI_DMA_STREAM,
                                STM32_DCMI_DMA_IRQ_PRIORITY,
                                dcmi_serve_dma_interrupt,
                                &cam_drv);
    osalDbgAssert(cam_drv.dma_stream != NULL, "unable to allocate stream");

    uint32_t dma_mode = STM32_DMA_CR_CHSEL(1) |                     // Channel 1.
                        STM32_DMA_CR_PL(STM32_DCMI_DMA_PRIORITY) |  // High priority level.
                        STM32_DMA_CR_DIR_P2M |                      // Peripheral to memory.
                        STM32_DMA_CR_TCIE |                         // Transfer complete interrupt enabled.
                        STM32_DMA_CR_DMEIE |                        // Direct mode error interrupt enabled.
                        STM32_DMA_CR_TEIE |                         // Transfer error interrupt enabled.
                        STM32_DMA_CR_PBURST_SINGLE |                // Single transfer (no burst).
                        STM32_DMA_CR_MBURST_SINGLE |                // Single transfer (no burst).
                        STM32_DMA_CR_PSIZE_WORD |                   // Peripheral data size = 4 bytes.
                        STM32_DMA_CR_MSIZE_WORD |                   // Memory data size = 4 bytes.
                        STM32_DMA_CR_MINC |                         // Increment memory address after each data transfer.
                        STM32_DMA_CR_CIRC/* |                         // Circular mode.
                        STM32_DMA_CR_HTIE*/;                          // Half transfer interrupt enabled.

    /* Configure CAM DMA stream. */
    dmaStreamSetPeripheral(cam_drv.dma_stream, &DCMI->DR);
    dmaStreamSetFIFO(cam_drv.dma_stream, STM32_DMA_FCR_DMDIS | STM32_DMA_FCR_FTH_FULL);
    dmaStreamSetMemory0(cam_drv.dma_stream, cam_drv.cfg->samples);
    dmaStreamSetTransactionSize(cam_drv.dma_stream, cam_drv.cfg->samples_len);
    dmaStreamSetMode(cam_drv.dma_stream, dma_mode);
    dmaStreamEnable(cam_drv.dma_stream);
   

}

void dcmi_start_capture(void){
    //enable DCMI in one shot mode
    DCMI->CR |= DCMI_CR_CM;
    DCMI->CR |= DCMI_CR_ENABLE;
    DCMI->CR |= DCMI_CR_CAPTURE;
}

#include <ch.h>
#include <hal.h>
#include "dfsdm.h"

#ifndef STM32_DMA_REQUIRED
#error "DFSDM driver requires DMA functions. Please define STM32_DMA_REQUIRED."
#endif

typedef struct {
    const stm32_dma_stream_t *dma_stream;
    DFSDM_config_t *cfg;
} DFSDM_driver_t;

DFSDM_driver_t mic1_drv, mic2_drv, mic3_drv, mic4_drv;

/** Function called on DFSDM interrupt. */
static void dfsdm_serve_dma_interrupt(void *p, uint32_t flags)
{
    DFSDM_driver_t *drv = (DFSDM_driver_t *) p;

    /* DMA errors handling.*/
    if ((flags & (STM32_DMA_ISR_TEIF | STM32_DMA_ISR_DMEIF)) != 0) {
        if (drv->cfg->error_cb != NULL) {
            drv->cfg->error_cb(drv->cfg->cb_arg);
        }
    } else if ((flags & STM32_DMA_ISR_TCIF) != 0) {
        /* End of the second halt of the circular buffer. */
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

void dfsdm_start(void)
{
    /* Send clock to peripheral. */
    rccEnableAPB2(RCC_APB2ENR_DFSDM1EN, true);

    /* Configure DFSDM clock output (must be before enabling interface).
     *
     * The clock output is used by the microphones to send their data out.
     * DFSDM is on APB2 @ 108 Mhz. The MP34DT01 MEMS microphone runs @ 2.4 Mhz,
     * requiring a prescaler of 45.
     */
    const unsigned clkout_div = 44;
    DFSDM1_Channel0->CHCFGR1 |= (clkout_div & 0xff) << DFSDM_CHCFGR1_CKOUTDIV_Pos;

    /* Enable DFSDM interface */
    DFSDM1_Channel0->CHCFGR1 |= DFSDM_CHCFGR1_DFSDMEN;

    /* Serial input configuration.
     *
     * The two microphones (MIC1 and MIC2) are connected to the same input pin.
     * As the microphone dont have a clock output, we reuse the internal clock.
     *
     * Channel 2 is connected on the input from channel 3 (CHINSEL=1)
     * Channel 3 data are on falling edge (SITP=1), while channel 2 are on rising edge(SITP=1).
     */
    DFSDM1_Channel2->CHCFGR1 |= DFSDM_CHCFGR1_CHINSEL;
    DFSDM1_Channel2->CHCFGR1 |= DFSDM_CHCFGR1_SPICKSEL_0;
    DFSDM1_Channel2->CHCFGR1 |= DFSDM_CHCFGR1_SITP_0;

    DFSDM1_Channel3->CHCFGR1 |= DFSDM_CHCFGR1_SPICKSEL_0;

    /* Enable channel 0 and 1. */
    DFSDM1_Channel2->CHCFGR1 |= DFSDM_CHCFGR1_CHEN;
    DFSDM1_Channel3->CHCFGR1 |= DFSDM_CHCFGR1_CHEN;

    /* Serial input configuration.
     *
     * The two microphones (MIC3 and MIC4) are connected to the same input pin.
     * As the microphone dont have a clock output, we reuse the internal clock.
     *
     * Channel 4 is connected on the input from channel 5 (CHINSEL=1)
     * Channel 5 data are on falling edge (SITP=1), while channel 2 are on rising edge(SITP=1).
     */
    DFSDM1_Channel4->CHCFGR1 |= DFSDM_CHCFGR1_CHINSEL;
    DFSDM1_Channel4->CHCFGR1 |= DFSDM_CHCFGR1_SPICKSEL_0;
    DFSDM1_Channel4->CHCFGR1 |= DFSDM_CHCFGR1_SITP_0;

    DFSDM1_Channel5->CHCFGR1 |= DFSDM_CHCFGR1_SPICKSEL_0;

    /* Enable channel 0 and 1. */
    DFSDM1_Channel4->CHCFGR1 |= DFSDM_CHCFGR1_CHEN;
    DFSDM1_Channel5->CHCFGR1 |= DFSDM_CHCFGR1_CHEN;

    /* Filter units configuration:
     * - Fast mode enabled
     * - Corresponding channel must be selected
     * - Continuous mode
     * - For channel 1: start synchronously with channel 0
     * - Sinc3 filter (from ST application example)
     * - Oversampling factor (OF) = 55, integrator oversampling (IF) = 1
     *   -> acquisition rate = APB2 / (clkout_div * OF * IF)
     *                       = 108 Mhz / (45 * 55) = 43.6 Khz.
     *   -> resolution = +/- (OF)^3
     *                 = +/- 166375
     *                 = ~ 19 bits (including sign bit)
     *    For details on filter configuration see section 17.3.8 of the
     *    reference manual (Digital Filter Configuration).
     *
     * TODO: Get to a precise 44.1 Khz clock using audio PLL
     */
    DFSDM1_Filter0->FLTCR1 = DFSDM_FLTCR1_FAST \
                             | (1 << DFSDM_FLTCR1_RDMAEN_Pos)
                             | (2 << DFSDM_FLTCR1_RCH_Pos);     /* channel */
    DFSDM1_Filter0->FLTFCR = (3 << DFSDM_FLTFCR_FORD_Pos)       /* filter order */ \
                             | (55 << DFSDM_FLTFCR_FOSR_Pos)    /* filter oversampling */ \
                             | (0 << DFSDM_FLTFCR_IOSR_Pos);   /* integrator oversampling */

    /* Filter 1 is identical, except that RSYNC is enabled. */
    DFSDM1_Filter1->FLTCR1 = DFSDM_FLTCR1_FAST \
                             | DFSDM_FLTCR1_RSYNC \
                             | (1 << DFSDM_FLTCR1_RDMAEN_Pos)
                             | (3 << DFSDM_FLTCR1_RCH_Pos);     /* channel */
    DFSDM1_Filter1->FLTFCR = (3 << DFSDM_FLTFCR_FORD_Pos)       /* filter order */ \
                             | (55 << DFSDM_FLTFCR_FOSR_Pos)    /* filter oversampling */ \
                             | (0 << DFSDM_FLTFCR_IOSR_Pos);   /* integrator oversampling */
    /* Filter 2 is identical, except that RSYNC is enabled. */
    DFSDM1_Filter2->FLTCR1 = DFSDM_FLTCR1_FAST \
                             | DFSDM_FLTCR1_RSYNC \
                             | (1 << DFSDM_FLTCR1_RDMAEN_Pos)
                             | (4 << DFSDM_FLTCR1_RCH_Pos);     /* channel */
    DFSDM1_Filter2->FLTFCR = (3 << DFSDM_FLTFCR_FORD_Pos)       /* filter order */ \
                             | (55 << DFSDM_FLTFCR_FOSR_Pos)    /* filter oversampling */ \
                             | (0 << DFSDM_FLTFCR_IOSR_Pos);   /* integrator oversampling */
    /* Filter 2 is identical, except that RSYNC is enabled. */
    DFSDM1_Filter3->FLTCR1 = DFSDM_FLTCR1_FAST \
                             | DFSDM_FLTCR1_RSYNC \
                             | (1 << DFSDM_FLTCR1_RDMAEN_Pos)
                             | (5 << DFSDM_FLTCR1_RCH_Pos);     /* channel */
    DFSDM1_Filter3->FLTFCR = (3 << DFSDM_FLTFCR_FORD_Pos)       /* filter order */ \
                             | (55 << DFSDM_FLTFCR_FOSR_Pos)    /* filter oversampling */ \
                             | (0 << DFSDM_FLTFCR_IOSR_Pos);   /* integrator oversampling */



    /* Enable the filters */
    DFSDM1_Filter0->FLTCR1 |= DFSDM_FLTCR1_DFEN;
    DFSDM1_Filter1->FLTCR1 |= DFSDM_FLTCR1_DFEN;
    DFSDM1_Filter2->FLTCR1 |= DFSDM_FLTCR1_DFEN;
    DFSDM1_Filter3->FLTCR1 |= DFSDM_FLTCR1_DFEN;

    /* Allocate DMA streams. */
    mic1_drv.dma_stream = dmaStreamAlloc(STM32_DFSDM_FLT0_DMA_STREAM,
                                STM32_DFSDM_FLT0_DMA_IRQ_PRIORITY,
                                dfsdm_serve_dma_interrupt,
                                &mic1_drv);
    osalDbgAssert(mic1_drv.dma_stream != NULL, "unable to allocate stream");

    mic2_drv.dma_stream = dmaStreamAlloc(STM32_DFSDM_FLT1_DMA_STREAM,
                                STM32_DFSDM_FLT1_DMA_IRQ_PRIORITY,
                                dfsdm_serve_dma_interrupt,
                                &mic2_drv);
    osalDbgAssert(mic2_drv.dma_stream != NULL, "unable to allocate stream");

    mic3_drv.dma_stream = dmaStreamAlloc(STM32_DFSDM_FLT2_DMA_STREAM,
                                STM32_DFSDM_FLT2_DMA_IRQ_PRIORITY,
                                dfsdm_serve_dma_interrupt,
                                &mic3_drv);
    osalDbgAssert(mic3_drv.dma_stream != NULL, "unable to allocate stream");

    mic4_drv.dma_stream = dmaStreamAlloc(STM32_DFSDM_FLT3_DMA_STREAM,
                                STM32_DFSDM_FLT3_DMA_IRQ_PRIORITY,
                                dfsdm_serve_dma_interrupt,
                                &mic4_drv);
    osalDbgAssert(mic4_drv.dma_stream != NULL, "unable to allocate stream");

}

void dfsdm_start_conversion(DFSDM_config_t *mic1_config, DFSDM_config_t *mic2_config, DFSDM_config_t *mic3_config, DFSDM_config_t *mic4_config)
{
    uint32_t dma_mode, mic1_dma_mode, mic2_dma_mode, mic3_dma_mode, mic4_dma_mode;

    mic1_drv.cfg = mic1_config;
    mic2_drv.cfg = mic2_config;
    mic3_drv.cfg = mic3_config;
    mic4_drv.cfg = mic4_config;

    /* Configure DMA mode */
    dma_mode =    /* Transfer from peripheral to memory */
               STM32_DMA_CR_DIR_P2M |
               /* Transfer 32 bit words at a time. */
               STM32_DMA_CR_MSIZE_WORD | STM32_DMA_CR_PSIZE_WORD |
               /* Increment the memory address after each transfer. */
               STM32_DMA_CR_MINC |
               /* Circular mode (automatically restart). */
               STM32_DMA_CR_CIRC |
               /* Enable one interrupt after each half of the buffer. */
               STM32_DMA_CR_TCIE | STM32_DMA_CR_HTIE |
               /* Enable interrupt on errors. */
               STM32_DMA_CR_DMEIE | STM32_DMA_CR_TEIE;

    /* channel specfic settings. */
    mic1_dma_mode = dma_mode |  STM32_DMA_CR_CHSEL(DFSDM_FLT0_DMA_CHN) |
                                STM32_DMA_CR_PL(STM32_DFSDM_FLT0_DMA_PRIORITY);
    mic2_dma_mode = dma_mode | STM32_DMA_CR_CHSEL(DFSDM_FLT1_DMA_CHN) |
                                STM32_DMA_CR_PL(STM32_DFSDM_FLT1_DMA_PRIORITY);
    mic3_dma_mode = dma_mode | STM32_DMA_CR_CHSEL(DFSDM_FLT2_DMA_CHN) |
                                STM32_DMA_CR_PL(STM32_DFSDM_FLT2_DMA_PRIORITY);
    mic4_dma_mode = dma_mode | STM32_DMA_CR_CHSEL(DFSDM_FLT3_DMA_CHN) |
                                STM32_DMA_CR_PL(STM32_DFSDM_FLT3_DMA_PRIORITY);

    /* Configure MIC1 DMA stream. */
    dmaStreamSetPeripheral(mic1_drv.dma_stream, &DFSDM1_Filter0->FLTRDATAR);
    dmaStreamSetMemory0(mic1_drv.dma_stream, mic1_drv.cfg->samples);
    dmaStreamSetTransactionSize(mic1_drv.dma_stream, mic1_drv.cfg->samples_len);
    dmaStreamSetMode(mic1_drv.dma_stream, mic1_dma_mode);
    dmaStreamEnable(mic1_drv.dma_stream);

    /* Configure MIC2 DMA stream. */
    dmaStreamSetPeripheral(mic2_drv.dma_stream, &DFSDM1_Filter1->FLTRDATAR);
    dmaStreamSetMemory0(mic2_drv.dma_stream, mic2_drv.cfg->samples);
    dmaStreamSetTransactionSize(mic2_drv.dma_stream, mic2_drv.cfg->samples_len);
    dmaStreamSetMode(mic2_drv.dma_stream, mic2_dma_mode);
    dmaStreamEnable(mic2_drv.dma_stream);

    /* Configure MIC2 DMA stream. */
    dmaStreamSetPeripheral(mic3_drv.dma_stream, &DFSDM1_Filter2->FLTRDATAR);
    dmaStreamSetMemory0(mic3_drv.dma_stream, mic3_drv.cfg->samples);
    dmaStreamSetTransactionSize(mic3_drv.dma_stream, mic3_drv.cfg->samples_len);
    dmaStreamSetMode(mic3_drv.dma_stream, mic3_dma_mode);
    dmaStreamEnable(mic3_drv.dma_stream);

    /* Con figure MIC2 DMA stream. */
    dmaStreamSetPeripheral(mic4_drv.dma_stream, &DFSDM1_Filter3->FLTRDATAR);
    dmaStreamSetMemory0(mic4_drv.dma_stream, mic4_drv.cfg->samples);
    dmaStreamSetTransactionSize(mic4_drv.dma_stream, mic4_drv.cfg->samples_len);
    dmaStreamSetMode(mic4_drv.dma_stream, mic4_dma_mode);
    dmaStreamEnable(mic4_drv.dma_stream);

    /* Enable continuous conversion. */
    DFSDM1_Filter0->FLTCR1 |= DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter1->FLTCR1 |= DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter2->FLTCR1 |= DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter3->FLTCR1 |= DFSDM_FLTCR1_RCONT;

    /* Start acquisition */
    DFSDM1_Filter0->FLTCR1 |= DFSDM_FLTCR1_RSWSTART;
}

void dfsdm_stop_conversion(void)
{
    /* Halting the DFSDM conversions is done by clearing the continous
     * conversion bit. */
    DFSDM1_Filter0->FLTCR1 &= ~DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter1->FLTCR1 &= ~DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter2->FLTCR1 &= ~DFSDM_FLTCR1_RCONT;
    DFSDM1_Filter3->FLTCR1 &= ~DFSDM_FLTCR1_RCONT;

    dmaStreamDisable(mic1_drv.dma_stream);
    dmaStreamDisable(mic2_drv.dma_stream);
    dmaStreamDisable(mic3_drv.dma_stream);
    dmaStreamDisable(mic4_drv.dma_stream);
}

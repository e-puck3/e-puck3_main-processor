#ifndef DCMI_H
#define DCMI_H

#include <stdint.h>
#include <unistd.h>

/** Callback type for data received
 *
 * @param [in] drv Pointer provided by the user in the DCMI config.
 * @param [in] buffer A pointer to the buffer holding the samples.
 * @param [in] n number of samples in the buffer.
 */
typedef void (*dcmicallback_t)(void *drv, int32_t *buffer, size_t n);

/** Callback type for DMA errors.
 *
 * @param [in] drv Pointer provided by the user in the DCMI config.
 */
typedef void (*dcmierrorcallback_t)(void *drv);

/** Configuration for one DCMI camera. */
typedef struct {
    /** Callback called when samples_len/2 samples have been read. */
    dcmicallback_t end_cb;

    /** Callback in case of DMA error. */
    dcmierrorcallback_t error_cb;

    /** Argument passed to the callbacks. */
    void *cb_arg;

    /** Pointer to a buffer to hold the samples. */
    int32_t *samples;

    /** Length of the samples buffer, in number of elements. */
    size_t samples_len;
} DCMI_config_t;

/** Configure the hardware peripherals. */
void dcmi_start(DCMI_config_t *cam_config);

/** Starts a capture. */
void dcmi_start_capture(void);

#endif

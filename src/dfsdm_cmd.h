
#ifndef DFSDM_CMD_H
#define DFSDM_CMD_H


/**
 * @brief Shell command to send raw audio data to the shell
 */
void cmd_dfsdm_usb(BaseSequentialStream *chp, int argc, char *argv[]);

/**
 * @brief Shell command to record the audio to the sd card
 */
void cmd_dfsdm_sd(BaseSequentialStream *chp, int argc, char *argv[]);

#define DFSDM_SHELL_CMD                 \
    {"dfsdm_usb",cmd_dfsdm_usb},          \
    {"dfsdm_sd",cmd_dfsdm_sd},          \

#endif /* DFSDM_CMD_H */


#ifndef DFSDM_CMD_H
#define DFSDM_CMD_H


void cmd_dfsdm(BaseSequentialStream *chp, int argc, char *argv[]);

#define DFSDM_SHELL_CMD                 \
    {"dfsdm",cmd_dfsdm},          \

#endif /* DFSDM_CMD_H */


#ifndef DCMI_CMD_H
#define DCMI_CMD_H


void cmd_dcmi(BaseSequentialStream *chp, int argc, char *argv[]);
void dcmi_start_from_shell(void);

#define DCMI_SHELL_CMD                 \
    {"dcmi",cmd_dcmi},          \

#endif /* DCMI_CMD_H */

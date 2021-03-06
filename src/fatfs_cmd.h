/*

File    : fat.h
Author  : Eliot Ferragni
Date    : 9 may 2018
REV 1.0

Some functions to use fatFS library

Adapted from the code written by Jed Frey
taken at https://github.com/jed-frey/ARMCM4-STM32F407-STF4BB-FATFS
*/


#ifndef FAT_H
#define FAT_H

/**
 * Provides functions to use the fatfs library
 */

#include <ch.h>
#include <hal.h>
//fatfs include
#include <ff.h>
#include <chprintf.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Mount the sd card with fatFS.
 * @return  true if it worked and false it not
 */
bool mountSDCard(void);

/**
 * @brief   Unmount the sd card with fatFS.
 * @return  true if it worked and false it not
 */
bool unmountSDCard(void);

/**
 * @brief   Returns if the sd card is mounted or not
 * @return  true = mounted, false = not mounted
 */
bool isSDCardMounted(void);

/**
 * @brief Prints the directory tree to the given stream
 * 
 * @param chp   Output stream to use for the chprintf
 * @param path  path to use to begin the scan (0 means the root). Also used as working area (bigger is better)
 * @return      result. See FRESULT
 */
FRESULT scan_files(BaseSequentialStream *chp, char *path);

/**
 * @brief   Returns the size of the clusters of the sd card mounted
 * @return  number of elements per cluster
 */
BYTE getSDCardClusterSize(void);

/**
 * @brief Prints a complete error string depending on the error given
 * 
 * @param chp   Output stream to use for the chprintf
 */
void fverbose_error(BaseSequentialStream *chp, FRESULT err);



void cmd_mount(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_unmount(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_free(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_hello(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_mkdir(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_setlabel(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_getlabel(BaseSequentialStream *chp, int argc, char *argv[]);
void cmd_cat(BaseSequentialStream *chp, int argc, char *argv[]);

#define FATFS_SHELL_CMD                 \
    {"fatfs_mount",cmd_mount},          \
    {"fatfs_unmount",cmd_unmount},      \
    {"fatfs_free", cmd_free}, \
    {"fatfs_tree", cmd_tree}, \
    {"fatfs_hello", cmd_hello},             \
    {"fatfs_mkdir", cmd_mkdir},                 \
    {"fatfs_setlabel", cmd_setlabel},                 \
    {"fatfs_getlabel", cmd_getlabel},                 \
    {"fatfs_cat", cmd_cat},                 \

#ifdef __cplusplus
}
#endif

#endif /* FAT_H */

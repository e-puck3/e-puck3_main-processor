
#include <ch.h>
#include <hal.h>

#include <chprintf.h>
#include <string.h>

#include <fatfs_cmd.h>

static FATFS SDC_FS;
static bool sd_card_mounted = false;

/*
*   fatFS related variables
*/
/* Generic large buffer.*/
#define SIZE_GENERIC_BUFFER 256
static char fbuff[SIZE_GENERIC_BUFFER];

/**
 * @brief Returns a complete string depending on the error given
 * 
 * @param stat  The error to interprete
 * @return      A pointer to a string containing the text of the error
 */
char* fresult_str(FRESULT stat) {
    // static char str[SIZE_ERROR_BUFFER];
    // memset(str,0,sizeof(str));

    switch (stat) {
        case FR_OK:
            return "Succeeded";
        case FR_DISK_ERR:
            return "A hard error occurred in the low level disk I/O layer";
        case FR_INT_ERR:
            return "Assertion failed";
        case FR_NOT_READY:
            return "The physical drive cannot work";
        case FR_NO_FILE:
            return "Could not find the file";
        case FR_NO_PATH:
            return "Could not find the path";
        case FR_INVALID_NAME:
            return "The path name format is invalid";
        case FR_DENIED:
            return "Access denied due to prohibited access or directory full";
        case FR_EXIST:
            return "Access denied due to prohibited access";
        case FR_INVALID_OBJECT:
            return "The file/directory object is invalid";
        case FR_WRITE_PROTECTED:
            return "The physical drive is write protected";
        case FR_INVALID_DRIVE:
            return "The logical drive number is invalid";
        case FR_NOT_ENABLED:
            return "The volume has no work area";
        case FR_NO_FILESYSTEM:
            return "There is no valid FAT volume";
        case FR_MKFS_ABORTED:
            return "The f_mkfs() aborted due to any parameter error";
        case FR_TIMEOUT:
            return "Could not get a grant to access the volume within defined period";
        case FR_LOCKED:
            return "The operation is rejected according to the file sharing policy";
        case FR_NOT_ENOUGH_CORE:
            return "LFN working buffer could not be allocated";
        case FR_TOO_MANY_OPEN_FILES:
            return "Number of open files > _FS_SHARE";
        case FR_INVALID_PARAMETER:
            return "Given parameter is invalid";
        default:
            return "Unknown";
    }
    return "";
}

//////////////////////////////PUBLIC FUNCTIONS////////////////////////////
/**
 * @brief Mount the sd card
 */
bool mountSDCard(void){

    if(!sd_card_mounted){
        /*
        * Attempt to mount the drive.
        */
        if (sdcConnect(&SDCD1) != HAL_SUCCESS) {
            return false;
        }
        if(f_mount(&SDC_FS,"/",0) != FR_OK){
            return false;
        }
        sd_card_mounted = true;
    }
    return true;
}

/**
 * @brief Unmount the sd card
 */
bool unmountSDCard(void){
    if(sd_card_mounted){
        /*
        * Attempt to mount the drive.
        */
        if(sdcDisconnect(&SDCD1) != HAL_SUCCESS) {
            return false;
        }
        if(f_mount(NULL,"/",0) != FR_OK){
            return false;
        }
        sd_card_mounted = false;
    }
    
    return true;
}

/**
 * @brief   Returns if the sd card is mounted or not
 */
bool isSDCardMounted(void){
    return sd_card_mounted;
}

/*
 * Scan Files in a path and print them to the given stream.
 */
FRESULT scan_files(BaseSequentialStream *chp, char *path) {
    FRESULT res;
    FILINFO fno;
    DIR dir;
    int fyear,fmonth,fday,fhour,fminute,fsecond;

    int i;
    char *fn;

// #if _USE_LFN
//     fno.lfname = 0;
//     fno.lfsize = 0;
// #endif
    /*
     * Open the Directory.
     */
    res = f_opendir(&dir, path);
    if (res == FR_OK) {
        /*
         * If the path opened successfully.
         */
        i = strlen(path);
        while (true) {
            /*
             * Read the Directory.
             */
            res = f_readdir(&dir, &fno);
            /*
             * If the directory read failed or end of dir
             */
            if (res != FR_OK || fno.fname[0] == 0) {
                break;
            }
            /*
             * If the directory or file begins with a '.' (hidden), continue
             */
            if (fno.fname[0] == '.') {
                continue;
            }
            fn = fno.fname;
            /*
             * Extract the date.
             */
            fyear = ((0b1111111000000000&fno.fdate) >> 9)+1980;
            fmonth= (0b0000000111100000&fno.fdate) >> 5;
            fday  = (0b0000000000011111&fno.fdate);
            /*
             * Extract the time.
             */
            fhour   = (0b1111100000000000&fno.ftime) >> 11;
            fminute = (0b0000011111100000&fno.ftime) >> 5;
            fsecond = (0b0000000000011111&fno.ftime)*2;
            /*
             * Print date and time of the file.
             */
            chprintf(chp, "%4d-%02d-%02d %02d:%02d:%02d ", fyear, fmonth, fday, fhour, fminute, fsecond);
            /*
             * If the 'file' is a directory.
             */
            if (fno.fattrib & AM_DIR) {
                /*
                 * Add a slash to the end of the path
                 */
                path[i++] = '/';
                strcpy(&path[i], fn);
                /*
                 * Print that it is a directory and the path.
                 */
                chprintf(chp, "<DIR> %s/\r\n", path);
                /*
                 * Recursive call to scan the files.
                 */
                res = scan_files(chp, path);
                if (res != FR_OK) {
                    break;
                }
                path[--i] = 0;
            } else {
                /*
                 * Otherwise print the path as a file.
                 */
                chprintf(chp, "      %s/%s\r\n", path, fn);
            }
        }
    } else {
        chprintf(chp, "FS: f_opendir() failed\r\n");
    }
    return res;
}

/**
 * @brief   Returns the size of the clusters of the sd card mounted
 * @return  number of elements per cluster
 */
BYTE getSDCardClusterSize(void){
    return SDC_FS.csize;
}
/*
*   Prints a complete error string depending on the error given
*/
void fverbose_error(BaseSequentialStream *chp, FRESULT err) {
    chprintf(chp, "\t%s.\r\n",fresult_str(err));
}

void cmd_mount(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    /*
     * Attempt to mount the drive.
     */
    if (!mountSDCard()) {
        chprintf(chp, "FS: f_mount() failed. Is the SD card inserted?\r\n");
        return;
    }
    chprintf(chp, "FS: f_mount() succeeded\r\n");
}

void cmd_unmount(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    if (!unmountSDCard()) {
        chprintf(chp, "FS: f_mount() unmount failed\r\n");
        return;
    }
}

void cmd_free(BaseSequentialStream *chp, int argc, char *argv[]) {
    FRESULT err;
    uint32_t clusters;
    FATFS *fsp;
    BYTE cluster_size;
    (void)argc;
    (void)argv;

    err = f_getfree("/", &clusters, &fsp);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_getfree() failed\r\n");
        return;
    }

    cluster_size = getSDCardClusterSize();
    /*
     * Print the number of free clusters and size free in B, KiB and MiB.
     */
    chprintf(chp,"FS: %lu free clusters\r\n    %lu sectors per cluster\r\n",
        clusters, (uint32_t)cluster_size);
    chprintf(chp,"%lu B free\r\n",
        clusters * (uint32_t)cluster_size * (uint32_t)MMCSD_BLOCK_SIZE);
    chprintf(chp,"%lu KB free\r\n",
        (clusters * (uint32_t)cluster_size * (uint32_t)MMCSD_BLOCK_SIZE)/(1024));
    chprintf(chp,"%lu MB free\r\n",
        (clusters * (uint32_t)cluster_size * (uint32_t)MMCSD_BLOCK_SIZE)/(1024*1024));
}

void cmd_tree(BaseSequentialStream *chp, int argc, char *argv[]) {
    (void)argv;
    (void)argc;
    
    /*
    * Set the file path buffer to 0. Also means we will open the root directory
    */
    memset(fbuff,0,sizeof(fbuff));

    scan_files(chp, fbuff);
}

//create a file called hello.txt and write "Hello World" in it
void cmd_hello(BaseSequentialStream *chp, int argc, char *argv[]) {
    FIL fsrc;   /* file object */
    FRESULT err;
    int written;
    (void)argv;
    /*
     * Print the input arguments.
     */
    if (argc > 0) {
        chprintf(chp, "Usage: hello\r\n");
        chprintf(chp, "       Creates hello.txt with 'Hello World'\r\n");
        return;
    }
    /*
     * Open the text file
     */
    err = f_open(&fsrc, "hello.txt", FA_READ | FA_WRITE | FA_CREATE_ALWAYS);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_open(\"hello.txt\") failed.\r\n");
        fverbose_error(chp, err);
        return;
    } else {
        chprintf(chp, "FS: f_open(\"hello.txt\") succeeded\r\n");
    }
    /*
     * Write text to the file.
     */
    written = f_puts("Hello World", &fsrc);
    if (written == -1) {
        chprintf(chp, "FS: f_puts(\"Hello World\",\"hello.txt\") failed\r\n");
    } else {
        chprintf(chp, "FS: f_puts(\"Hello World\",\"hello.txt\") succeeded\r\n");
    }
    /*
     * Close the file
     */
    f_close(&fsrc);
}

void cmd_mkdir(BaseSequentialStream *chp, int argc, char *argv[]) {
    FRESULT err;
    if (argc != 1) {
        chprintf(chp, "Usage: mkdir dirName\r\n");
        chprintf(chp, "       Creates directory with dirName (no spaces)\r\n");
        return;
    }
    /*
     * Attempt to make the directory with the name given in argv[0]
     */
    err=f_mkdir(argv[0]);
    if (err != FR_OK) {
        /*
         * Display failure message and reason.
         */
        chprintf(chp, "FS: f_mkdir(%s) failed\r\n",argv[0]);
        fverbose_error(chp, err);
        return;
    } else {
        chprintf(chp, "FS: f_mkdir(%s) succeeded\r\n",argv[0]);
    }
    return;
}

void cmd_setlabel(BaseSequentialStream *chp, int argc, char *argv[]) {
    FRESULT err;
    if (argc != 1) {
        chprintf(chp, "Usage: setlabel label\r\n");
        chprintf(chp, "       Sets FAT label (no spaces)\r\n");
        return;
    }
    /*
     * Attempt to set the label with the name given in argv[0].
     */
    err=f_setlabel(argv[0]);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_setlabel(%s) failed.\r\n");
        fverbose_error(chp, err);
        return;
    } else {
        chprintf(chp, "FS: f_setlabel(%s) succeeded.\r\n");
    }
    return;
}

void cmd_getlabel(BaseSequentialStream *chp, int argc, char *argv[]) {
    FRESULT err;
    char lbl[12];
    DWORD sn;
    (void)argv;
    if (argc > 0) {
        chprintf(chp, "Usage: getlabel\r\n");
        chprintf(chp, "       Gets and prints FAT label\r\n");
        return;
    }
    memset(lbl,0,sizeof(lbl));
    /*
     * Get volume label & serial of the default drive
     */
    err = f_getlabel("", lbl, &sn);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_getlabel failed.\r\n");
        fverbose_error(chp, err);
        return;
    }
    /*
     * Print the label and serial number
     */
    chprintf(chp, "LABEL: %s\r\n",lbl);
    chprintf(chp, "  S/N: 0x%X\r\n",sn);
    return;
}

/*
 * Print a text file to screen
 */
void cmd_cat(BaseSequentialStream *chp, int argc, char *argv[]) {
    FRESULT err;
    FIL fsrc;   /* file object */
    char Buffer[255];
    UINT ByteToRead=sizeof(Buffer);
    UINT ByteRead;
    /*
     * Print usage
     */
    if (argc != 1) {
        chprintf(chp, "Usage: cat filename\r\n");
        chprintf(chp, "       Echos filename (no spaces)\r\n");
        return;
    }
    /*
     * Attempt to open the file, error out if it fails.
     */
    err=f_open(&fsrc, argv[0], FA_READ);
    if (err != FR_OK) {
        chprintf(chp, "FS: f_open(%s) failed.\r\n",argv[0]);
        fverbose_error(chp, err);
        return;
    }
    /*
     * Do while the number of bytes read is equal to the number of bytes to read
     * (the buffer is filled)
     */
    do {
        /*
         * Clear the buffer.
         */
        memset(Buffer,0,sizeof(Buffer));
        /*
         * Read the file.
         */
        err=f_read(&fsrc,Buffer,ByteToRead,&ByteRead);
        if (err != FR_OK) {
            chprintf(chp, "FS: f_read() failed\r\n");
            fverbose_error(chp, err);
            f_close(&fsrc);
            return;
        }
        chprintf(chp, "%s", Buffer);
    } while (ByteRead>=ByteToRead);
    chprintf(chp,"\r\n");
    /*
     * Close the file.
     */
    f_close(&fsrc);
    return;
}
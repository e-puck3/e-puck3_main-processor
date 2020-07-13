# FATFS files.
FATFSSRC = $(CHIBIOS)/os/various/fatfs_bindings/fatfs_diskio.c \
           $(CHIBIOS)/os/various/fatfs_bindings/fatfs_syscall.c \
           ../fatfs/src/ff.c \
           ../fatfs/src/ffunicode.c

FATFSINC = ../fatfs/src

# Shared variables
ALLCSRC += $(FATFSSRC)
ALLINC  += $(FATFSINC)

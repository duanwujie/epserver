#ifndef __AESECRYPT_H_
#define __AESECRYPT_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aes.h"

#define PHY_PAGE_SIZE 4096
//#define PHY_PAGE_SIZE 8192

//#define CRYPT_BLOCK_SIZE 256
#define CRYPT_BLOCK_SIZE 1024


int ecryptAES128(const char *pathname , const char * password , int mode);
int ecryptAES128Parallel(const char *pathname , const char * password , int mode);


#endif

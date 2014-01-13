

#include "AESEncrypt.h"

/* 
 *
 *
 *
 */

/**
 * @brief 加密/解密接口
 *
 * @param pathname 需要加密的文件
 * @param password 加密密码
 * @param flag 加密解密标志,0为加密,1为解密
 *
 * @return 成功返回0,失败返回-1
 */
int ecryptAES128(const char * pathname , const char * password , int flag) 
{
    int ret;

    AES_KEY key;
    unsigned char iv[16]={1};

    if(pathname == NULL || password == NULL) return -1;

    char key16[128]={0};
    unsigned char out[CRYPT_BLOCK_SIZE]={0x0};
    strncpy(key16,password,strlen(password));
    

    struct stat sinfo;
    unsigned int filesize=0;
    int fd = open(pathname,O_RDWR);
    if(fd < -1){
        printf("Open file error!\n");
        return -1;
    }
    if(fstat(fd,&sinfo) < 0){
        printf("Get file stat error!\n");
        return -1;
    }else{
        filesize = sinfo.st_size;
    }

    if(1 == flag){
        ret = AES_set_decrypt_key((const unsigned char *)key16,128,&key);
    }else if (0 == flag){
        ret = AES_set_encrypt_key((const unsigned char *)key16,128,&key);
    }else{
        printf("Mode not support\n");
        return -1;
    }
    if(ret < 0){
        printf("AES_set_encrypt_key error!\n");
        return -1;
    }
    memset(iv,0x0,16);

    unsigned int starpos=0;

    //void * address= 0;
    unsigned char * mapmem = 0;
    unsigned int ecryptsize=filesize;

    //printf("ecryptsize :%d\n",ecryptsize);
    //int i=1;

    unsigned int pagecout = filesize/PHY_PAGE_SIZE + 1;


    unsigned int processSize=0;
    unsigned int umapsize = 0;
    while(pagecout != 0){
        if(ecryptsize >= PHY_PAGE_SIZE){
            mapmem = (unsigned char * )mmap(NULL,PHY_PAGE_SIZE,PROT_WRITE|PROT_READ,MAP_SHARED,fd,starpos);
            processSize = PHY_PAGE_SIZE;
            umapsize = PHY_PAGE_SIZE;
        }
        else{
            mapmem = (unsigned char * )mmap(NULL,filesize,PROT_WRITE|PROT_READ,MAP_SHARED,fd,starpos);
            processSize = filesize;
            umapsize = filesize;
        }
        //printf("processSize:%d\n",processSize);
        unsigned char * pmap=mapmem;
        while(processSize != 0){
            if(processSize >= CRYPT_BLOCK_SIZE){
                if(1 == flag)AES_cbc_encrypt(pmap,out,CRYPT_BLOCK_SIZE,&key,iv,AES_DECRYPT);
                else if(0 == flag)AES_cbc_encrypt(pmap,out,CRYPT_BLOCK_SIZE,&key,iv,AES_ENCRYPT);
                memcpy(pmap,out,CRYPT_BLOCK_SIZE);
                starpos+=CRYPT_BLOCK_SIZE;
                processSize-=CRYPT_BLOCK_SIZE;
                pmap+=CRYPT_BLOCK_SIZE;
            }else if(processSize < CRYPT_BLOCK_SIZE && processSize >= 1){
                if(1 == flag){
                    AES_cbc_encrypt(pmap,out,processSize,&key,iv,AES_DECRYPT);
                    memcpy(pmap,out,processSize);
                    processSize = 0;
                }

                else if(0 == flag){
                        AES_cbc_encrypt(pmap,out,processSize,&key,iv,AES_ENCRYPT);
                        ret = processSize;
                        processSize = (processSize & 0xFFFFFFF0) +((processSize & 0xF)?16:0);
                        *(out+processSize) = (processSize - ret);
                        memcpy(pmap,out,processSize+1);
                        processSize = 0; 
                }

            }
        }
        pagecout--;
        munmap(mapmem,umapsize);
    }
    close(fd);
    return 0;
}

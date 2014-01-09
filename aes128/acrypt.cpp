
#include "AESEncrypt.h"

void Usage()
{
        printf("Usage: aencrypt -f filename -p password -m mode\n");
}


int ecryptAES128(const char *pathname, const char * password, int flag);

int main(int argc, char * argv[])
{
    //cryptfWithAES128("./a.txt","1234567890abcdef");

    //if(argc != 2){
    //    printf("arg error do noting\n");
    //    return -1;
    //}
    //
    char pathname[128]={0};
    char password[64]={0};
    int  flag=0;

    char opt;

    if(argc != 7){
            Usage();
            return -1;
    }
    while ((opt = getopt(argc, argv, "f:p:m:")) != -1){
            switch(opt){
            case 'f':
                    strcpy(pathname,optarg);
                    break;
            case 'p':
                    strcpy(password,optarg);
                    break;
            case 'm':
                    flag=atoi(optarg);
                    break;
defalut:
                    Usage();
                    return -1;

            }

    }


    //ecryptAES128(pathname,password,flag);
    ecryptAES128Parallel(NULL,NULL,0);
    return 0;
}

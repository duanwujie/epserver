/**
* @file Sock.c
* @brief 常用的socket读写函数实现
* @author fU9ANg (bb.newlife@gmail.com)
* @version v1.0
* @date 2014-01-03
*/

#include "Sock.h"

ssize_t send_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf || NULL == timeout){
        return -1;
    }

    ssize_t recved = 0;
    fd_set st;
    while(0 != left) {
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, NULL, &st, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = send(fd, (void*)((char*)buf + recved), left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return 0;
}

ssize_t recv_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf || NULL == timeout){
        return -1;
    }
    ssize_t recved = 0;
    fd_set st;
    while(0 != left){
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, &st, NULL, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = recv(fd, (void*)((char*)buf + recved), left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return recved;
}

int send_v(int fd,
        void* buf,
        ssize_t left){
    if (NULL == buf){
        return -1;
    }

    int sended = 0;
    while(0 != left) {
            int len = send(fd, (void*)((char*)buf + sended), left, 0);
            if (EAGAIN == errno) {
                usleep (100);
                continue;
            }
            if (errno == EINTR) {
                usleep (100);
                continue;
            }
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            sended += len;
    }
    return sended;
}

int recv_v(int fd,
        void* buf,
        ssize_t left){
    if (NULL == buf){
        return -1;
    }

    int recved = 0;
    while(0 != left) {
            int len = recv(fd, (void*)((char*)buf + recved), left, 0);
            if (EAGAIN == errno) {
                usleep (100);
                continue;
            }
            if (errno == EINTR) {
                usleep (100);
                continue;
            }
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
    }
    return recved;
}

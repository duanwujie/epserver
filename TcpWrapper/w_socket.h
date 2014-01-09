
#ifndef __W_SOCKET_H
#define __W_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <winsock.h>
typedef int socklen_t;
#else
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/epoll.h>
#endif
#include <string.h>
#include <string>
#include <errno.h>

#ifdef _WIN32
#pragma comment(lib, "wsock32")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define w_false 0
#define w_true  1

#define INVALID_SOCK_FD -1

using namespace std;

typedef enum eSocketType
{
    ESOCKINVALID = 0,
    ESOCKIPV4,
    ESOCKIPV6,    
}   eSocketType;

class wSocket
{
public:
    wSocket (string ip);
    wSocket (string ip, enum eSocketType type)
    wSocket (string ip, unsigned int port);
    wSocket (string ip, unsigned int port, enum eSocketType type);

public:
    #ifdef  _RETURN_WSOCKET_RECV
    int  recv (void* buffer, int len, int flags);
    #else
    void recv (void* buffer, int len, int flags);
    #endif

    #ifdef  _RETURN_WSOCKET_SEND
    int  send (void* buffer, int len, int flags);
    #else
    void send (void* buffer, int len, int flags);
    #endif

    int  create (void);

    int  bind (void);

    int  listen (int backlog);

    int  connect (void);

    int  accept (struct sockaddr* client_addr);

public:
    int m_fd;
    string m_ip;
    unsigned int m_port;

    enum eSocketType m_type;
}

#ifdef __cplusplus
}
#endif

#endif // __W_SOCKET_H

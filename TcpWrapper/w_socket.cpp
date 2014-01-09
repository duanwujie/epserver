
#include "w_socket.h"

using namespace std;

wSocket::wSocket (string ip)
{
    if (!ip.empty ())
        m_ip = ip;
}

wSocket::wSocket (string ip, enum eSocketType type);
{
    ::wSocket (ip);

    if (type > 0)
        m_type = type;
}

wSocket::wSocket (string ip, unsigned int port)
{
    ::wSocket (ip);
    if (type > 0)
        m_port = port;
}

wSocket::wSocket (string ip, unsigned int port, enum eSocketType type)
{
    ::wSocket (ip, port);
    if (type > 0)
        m_type = type;
}

int wSocket::Init (void)
{
#ifdef  _WIN32
    WSADATA wsaData;
    WORD version = MAKEWORD (2, 0);
    int rult;
    if ((rult = WSAStartup (version, &wsaData)) < 0)
        return (w_false);
#endif
    return (w_true);
}

int wSocket::Clean (void)
{
#ifdef  _WIN32
    return (WSACleanup ());
#else
    return (0);
#endif
}

#ifdef  _RETURN_WSOCKET_RECV
int wSocket::recv (void* buffer, int len, int flags)
{
    int read;
    int rult = 0;

    while (rult < len) {
        read = recv (m_fd, (char*) buffer+rult, len-rult, flags);

        if (read == -1 || read == 0)
            return (w_false);
        rult += read;
    }

    return (rult);
}
#else
void wSocket::recv (void* buffer, int len, int flags)
{
    int byte_left = len;
    int read_bytes;
    char* pbuf = (char*) buffer;

    while (byte_left > 0) {
        read_bytes = recv (m_fd, pbuf, byte_left, flags);
        if (read_bytes <= 0) {
            if (errno == EINTR || errno == EAGAIN) {
                if (read_bytes < 0)
                    read_bytes = 0;
                usleep (100);
                continue;
            }
            else {
                break;
            }
        }

        bytes_left -= read_bytes;
        ptr += read_bytes;
    }
}
#endif

#ifdef  _RETURN_WSOCKET_SEND
int wSocket::send (void* buffer, int len, int flags)
{
    int written;
    int rult = 0;

    while (rult < len) {
        written = send (m_fd, (char*) buffer+rult, len-rult, flags);

        if (written == -1 || written == 0)
            return (w_false);
        rult += written; 
    }

    return (rult);
}
#else
void wSocket::send (void* buffer, int len, int flags)
{
    int byte_left = len;
    int written_byte;
    char* pbuf = (char*) buffer;

    while (byte_left > 0) {
        written_bytes = send (m_fd, pbuf, bytes_left, flags);
        if (written_bytes <= 0) {
            if (errno == EINTR || errno == EAGAIN) {
                if (written_bytes < 0)
                    written_bytes = 0;
                usleep (100);
                continue;
            }
            else {
                break;
            }
        }

        bytes_left -= written_bytes;
        pbuf += written_bytes;
    }
}
#endif

int wSocket::create (void)
{
    if (m_type == ESOCKIPV4) {
        m_fd = socket (AF_INET, SOCK_STREAM, 0);
    }
    else if (m_type == ESOCKIPV6) {
    }

    // check valid socket fd for create socket
    if (m_fd == INVALID_SOCK_FD)
        return (w_false);

    return (w_true);
}

int wSocket::bind (void)
{
    struct sockaddr_in in_sockaddr;
    int result;
    (void) memset (&in_sockaddr, 0x00, sizeof (in_sockaddr));

    in_sockaddr.sin_family = AF_INET;
    in_sockaddr.sin_addr.s_addr = inet_addr (m_ip.c_str());
    in_sockaddr.sin_port = htons (m_port);

    if ((result = bind (m_fd, (struct sockaddr*) &in_sockaddr, \
        sizeof (in_sockaddr))) < 0) {

        return (w_false);
    }

    return (w_true);
}

int wSocket::listen (int backlog)
{
    int result;
    if ((result = listen (m_fd, backlog)) < 0)
        return (w_false);
    return (w_true);
}

int wSocket::connect (void)
{
    struct sockaddr_in sockaddr;
    int result;

    if (type == ESOCKIPV4) {
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_addr.s_addr = inet_addr (m_ip.c_str());
        sockaddr.sin_port = htons (m_port);
    }
    else if (type == ESOCKIPV6) {
        // TODO:
    }

    if ((result = connect (m_fd, (struct sockaddr*) &in_sockaddr, \
        sizeof (in_sockaddr))) < 0)
        return (w_false);

    return (w_true);
}

int wSocket::accept (struct sockaddr* client_addr)
{
    struct sockaddr_in cliaddr;
    socklen_t addrlen = sizeof (cliaddr);

    int result;
    if ((result = accept (m_fd, (struct sockaddr*)&cliaddr, &addrlen)) < 0)
        return (w_false);

    return (w_true);
}

int wSocket::close ()
{
#ifdef _WIN32
    return (closesocket (m_fd));
#else
    return (close (m_fd));
#endif
}

int wSocket::error ()
{
#ifdef _WIN32
    return (WSAGetLastError ());
#else
    return (errno);
#endif
}

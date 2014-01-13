/**
* @file Buf.h
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#ifndef _ECSERVER_BUF_H_
#define _ECSERVER_BUF_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define     MAX_BUF     5120

/**
* @brief 缓存Buffer类
*/
class Buf 
{
public:
    Buf (size_t inSize = MAX_BUF)
    {
        m_size  = inSize;
        m_ptr   = malloc (m_size);
        m_fd    = 0;
        m_id    = 0;
    };

    ~Buf ()
    {
        if  (m_ptr != NULL)
        {
            free (m_ptr);
            m_ptr = NULL;
        }
    }

    Buf (Buf& rhs)
    {
        m_size = rhs.m_size;
        m_used = rhs.m_used;
        m_fd = rhs.getfd();
        this->m_ptr = malloc (m_size);
        memcpy (this->m_ptr, rhs.m_ptr, m_size);
    };

    void* ptr ()
    {
        return m_ptr;
    }

    size_t setsize (size_t in)
    {
        return m_used = in;
    }

    size_t maxsize ()
    {
        return m_size;
    }

    size_t size ()
    {
        return m_used;
    }

    void reset ()
    {
        memset (m_ptr, 0x00, m_size);
    }

    int getfd ()
    {
        return m_fd;
    }

    void setfd (int fd)
    {
        m_fd = fd;
    }

    int getid ()
    {
        return m_id;
    }

    void setid (int id)
    {
        m_id = id;
    }

    Buf& operator=(Buf& rhs)
    {
            if (this != &rhs) {
                    memcpy (this->m_ptr, rhs.ptr (), m_size);
                    m_fd = rhs.getfd();
                    m_used = rhs.size();
            }

            return *this;
    }

private:
    void*   m_ptr;
    size_t  m_size;
    size_t  m_used;
    int     m_fd;
    int     m_id;
};

#endif  // _ECSERVER_BUF_H

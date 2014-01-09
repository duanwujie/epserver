/**
* @file QueueT.h
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
* @addtogroup framework
* @{
*/

#ifndef RECVTASK_H_
#define RECVTASK_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "task.h"
#include "Sock.h"
#include "Single.h"
#include "Buf.h"
#include "HandleMessage.h"
#include "protocol.h"

/**
 * @class 
 * @brief 收包处理线程类
 */
class RecvTask: public task
{
    public:
        RecvTask ();
        ~RecvTask ();
        virtual int work ();
};

#endif

///@}

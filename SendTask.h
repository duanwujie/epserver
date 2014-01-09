/**
* @file SendTask.h
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
* @addtogroup framework
* @{
*/


#ifndef SENDTASK_H_
#define SENDTASK_H_

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

/**
 * @class SendTask
 * @brief 发送线程类
 */
class SendTask: public task
{
    public:
        SendTask ();
        ~SendTask ();
        virtual int work ();
};

#endif
///@}

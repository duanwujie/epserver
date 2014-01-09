/**
* @file RecvTask.cpp
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#include "RecvTask.h"
#include "LoginCheck.h"

/**
* @brief 
*/
RecvTask::RecvTask ()
{
}

/**
* @brief 
*/
RecvTask::~RecvTask ()
{
}

/**
* @brief 
*
* @return 
*/
int RecvTask::work ()
{
    while (true)
    {
        Buf* p = NULL;
        if (SINGLE->recvqueue.dequeue (p, 3) != 0)
        {
            continue;
        }

        if (p == NULL)
        {
            cout << "ERROR: p==NULL in RecvTask::work()" << endl;
            return (0);
        }

        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        if (head != NULL)
        {
            debugProtocol (p);
            cout << "recvTask: cType=" << head->cType << endl;
            handlefunc pfun = CHandleMessage::getHandler (head->cType); 
            if (NULL == pfun)
            {
                printf ("ERROR: the pointer of callback, cType=[%d]\n", head->cType);
                p->reset ();
                SINGLE->bufpool.free (p);
                continue;
            }
            pfun (p);
        }
    }
    return 0;
}

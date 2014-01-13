
/*
 * HandleMessage.cpp
 */
#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"
#include "../message/proto/protocol.pb.h"

/////////////////////
HANDLEMAP CHandleMessage::m_HandleMap;



/*
=====================
 转发信息的通用接口
=====================
*/
bool CHandleMessage::postMessage (Buf* p, enum CommandType iCommandType, void* data, unsigned int iLen)
{
    if (p == NULL)
        return false;

    MSG_HEAD* head = (MSG_HEAD*)p->ptr();
    head->cLen = sizeof (MSG_HEAD);
    head->cType = iCommandType;

    if (data != NULL) {
        head->cLen = head->cLen + iLen;
        (void) memcpy ((char*)p->ptr() + sizeof (MSG_HEAD), (char*)data, iLen);
    }

    p->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (p);

    return true;
}

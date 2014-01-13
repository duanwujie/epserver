#include "HandleMessage.h"

#include "../protocol.h"
#include "../Buf.h"
#include "../Single.h"
#include "../database.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"

#include "../content/epUser.h"
#include "../content/epManager.h"
#include "../netdef.h"

void CHandleMessage::handleGetContent (Buf* p)
{
        /**
         * @brief 用户端请求课程列表。
         *        1. 根据用户ID，查找用户所在教室。
         *        2. 将该教室的课程列表返回。
         */

#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetClassList\n";
#endif
        // TODO:

        sGetContent tmp;
        epClassroom* pClassroom = EPMANAGER->getClassroomByFd(p->getfd());
        if (NULL == pClassroom) {
                tmp.set_result(false);
        } else {
                tmp.set_result(true);
                tmp.set_course_list(pClassroom->getCourseList());
        }

        SINGLE->sendqueue.enqueue(packet(ST_GetClassList, tmp, p->getfd()));
        SINGLE->bufpool.free(p);
}

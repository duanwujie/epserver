#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"

#include "../content/epClassroom.h"
#include "../content/epManager.h"
#include "../netdef.h"

void CHandleMessage::handleSetContent (Buf* p)
{
        /**
         * @brief 教师设置上课信息。
         *        1. 检查该用户类型是否为教师。
         *        2. 查看该教师所选教室是否已经被使用。
         *        3. 查看该教师所选班级是否已经在上课。
         *        4. 查看该教师是否不处理游离状态，上课或者没有登录。
         *        5. 将班级加入到教室。
         *        6. 将属于该班的学生加入到上课的班级中。
         *        7. 将教室加入到已经使用教室的列表中。
         *        8. 将教师加入到教室中。
         */

#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_SetContent\n";
#endif
        // TODO:

        CHECK_USER(epTeacher, pTeacher);

        cSetContent sc;
        unpacket(p, sc);
        int classroom_id = sc.classroom_id();

        sSetContent tmp;
        epClassroom* pClassroom = EPMANAGER->getClassroomById(sc.classroom_id());
        if (NULL != pClassroom) { // 该教室已经占用。
                tmp.set_result(false);
                tmp.set_msg("该教室已经被使用！");
                SINGLE->sendqueue.enqueue(packet(ST_SetContent, tmp, p->getfd()));
                SINGLE->bufpool.free(p);
        }

        epClass* pClass = EPMANAGER->getClassById(sc.class_id());
        if (NULL != pClass) { // 该班已经在上课了。
                tmp.set_result(false);
                tmp.set_msg("该班已经在上课了！");
                SINGLE->sendqueue.enqueue(packet(ST_SetContent, tmp, p->getfd()));
                SINGLE->bufpool.free(p);
        }

        pClassroom = new epClassroom(sc.classroom_id());
        pClass     = new epClass(sc.class_id());

        pClassroom->setTeacher(*pTeacher);
        pClassroom->insertClass(*pClass);

        EPMANAGER->insertClassroom(*pClassroom);
        EPMANAGER->insertStudentFromUserIntoClassroom(classroom_id);
}

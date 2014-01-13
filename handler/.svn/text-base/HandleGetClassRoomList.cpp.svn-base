#include "HandleMessage.h"

#include "../protocol.h"
#include "../Buf.h"
#include "../Single.h"
#include "../database.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"

#include "../content/epUser.h"
#include "../content/epTeacher.h"
#include "../content/epManager.h"

void CHandleMessage::handleGetClassRoomList (Buf* p)
{
        /**
         * @brief 教师请求所在学校的教室列表。
         *        1. 检查用户类型是否为教师。
         *        2. 根据教师所在学校ID，查找数据库，返回该学校所有教室的列表。
         */

#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetClassRoomList\n";
#endif
        epUser* pUser = EPMANAGER->getUserByFd(p->getfd());
        if (NULL == pUser) {
                SINGLE->bufpool.free(p);
                return;
        }

        epTeacher* pTeacher = dynamic_cast<epTeacher*>(pUser);
        if (NULL == pTeacher) {
                SINGLE->bufpool.free(p);
                return;
        }

        int school_id = pTeacher->getSchoolId();

        sGetClassRoomList tmp;
        std::vector<sGetClassRoomList> vc;
        string strpwd;
        string Account;
        try {
                MutexLockGuard guard(DATABASE->m_mutex);
                PreparedStatement* pstmt = DATABASE->preStatement (SQL_GET_CLASSROOM_LIST_BY_SCHOOL_ID);
                pstmt->setInt (1, school_id);
                ResultSet* prst = pstmt->executeQuery ();
                while (prst->next ()) {
                        tmp.set_classroom_id  (prst->getInt   ("classroom_id"));
                        tmp.set_classroom_name(prst->getString("classroom_name"));
                        vc.push_back(tmp);
                }
                delete prst;
                delete pstmt;
        }catch (SQLException e) {
        }

        SINGLE->sendqueue.enqueue(packet(ST_GetClassList, vc, p->getfd()));
        SINGLE->bufpool.free(p);
}

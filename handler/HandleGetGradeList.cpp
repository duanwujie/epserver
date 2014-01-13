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
#include "../netdef.h"

void CHandleMessage::handleGetGradeList (Buf* p)
{
        /**
         * @brief 教师请求其所在学校的年级列表。
         *        1. 查检该用户类型是否为教师。
         *        2. 如果是教师，则根据该教室所在学校，查找数据库，返回年级列表。
         */

#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetGradeList\n";
#endif
        // TODO:

        CHECK_USER(epTeacher, pTeacher)

        int school_id = pTeacher->getSchoolId();
        sGetGradeList tmp;
        std::vector<sGetGradeList> vc;
        std::string strpwd;
        std::string Account;
        try {
                MutexLockGuard guard(DATABASE->m_mutex);
                PreparedStatement* pstmt = DATABASE->preStatement (SQL_GET_ALL_GRADE_LIST_BY_SCHOOL_ID);
                pstmt->setInt (1, school_id);
                ResultSet* prst = pstmt->executeQuery ();
                while (prst->next ()) {
                        tmp.set_grade_id(prst->getInt("grade_id"));
                        tmp.set_grade_name(prst->getString("grade_name"));
                        vc.push_back(tmp);
                }
                delete prst;
                delete pstmt;
        }catch (SQLException e) {
        }

        SINGLE->sendqueue.enqueue(packet(ST_GetGradeList, tmp, p->getfd()));
        SINGLE->bufpool.free(p);
}

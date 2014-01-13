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

void CHandleMessage::handleGetFuncList (Buf* p) {

        /**
         * @brief 用户请求功能列表。
         *        1. 检查该用户是否在游离列表中，并有一定的类型（教师，学生等）。
         *        2. 根据用户类型，查找数据库，返回功能列表。
         */

#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetFuncList\n";
#endif
        // TODO:

        epUser* pUser = EPMANAGER->getUserByFd(p->getfd());
        if (NULL == pUser) {
                SINGLE->bufpool.free(p);
                return;
        }

        enum LoginType lt = pUser->getType();
        if (lt == LT_USER) {
            SINGLE->bufpool.free(p);
            return;
        }

        sGetFuncList tmp;
        std::vector<sGetFuncList> vc;
        string strpwd;
        string Account;
        try {
                MutexLockGuard guard(DATABASE->m_mutex);
                PreparedStatement* pstmt = DATABASE->preStatement (SQL_GET_FUNC_LIST_BY_TYPE);
                pstmt->setInt (1, lt);
                ResultSet* prst = pstmt->executeQuery ();
                while (prst->next ()) {
                        tmp.set_id(prst->getInt("id"));
                        tmp.set_name(prst->getString("name"));
                        tmp.set_res_path(prst->getString("res_path"));
                        vc.push_back(tmp);
                }
                delete prst;
                delete pstmt;
        }catch (SQLException e) {
        }

        SINGLE->sendqueue.enqueue(packet(ST_GetFuncList, vc, p->getfd()));
        SINGLE->bufpool.free(p);
}

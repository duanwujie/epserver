#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"
#include "../database.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"
#include "../netdef.h" // for EPCLASSROOM_INVALID_CLASSROOM_ID

#include "../content/epManager.h"

void CHandleMessage::handleGetStudentInfo (Buf* p)
{
#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetStudentInfo\n";
#endif
        // TODO:

        epUser* pUser = EPMANAGER->getUserByFd(p->getfd());
        if (NULL == pUser) {
                SINGLE->bufpool.free(p);
                return;
        }

        cGetStudentInfo gsi;
        unpacket(p, gsi);

        sGetStudentInfo tmp;
        epStudent* pStudent = EPMANAGER->getStudentById(gsi.id());
        if (NULL == pStudent) { // 没有该学生。到数据库中进行查找。
                string strpwd;
                string Account;
                try {
                        MutexLockGuard guard(DATABASE->m_mutex);
                        PreparedStatement* pstmt = DATABASE->preStatement (SQL_GET_STU_INFO_BY_NUM);
                        pstmt->setInt (1, gsi.id());
                        ResultSet* prst = pstmt->executeQuery ();
                        while (prst->next ()) {
                                tmp.set_id        (prst->getInt("id"));
                                tmp.set_number    (prst->getString("number"));
                                tmp.set_name      (prst->getString("name"));
                                tmp.set_sex       (prst->getString("sex"));
                                tmp.set_race      (prst->getString("race"));
                                tmp.set_birthday  (prst->getString("birthday"));
                                tmp.set_native    (prst->getString("native"));
                                tmp.set_class_name(prst->getString("class_name"));
                        }
                        delete prst;
                        delete pstmt;
                }catch (SQLException e) {
                }
        } else {
                tmp.set_id        (pStudent->getId());
                tmp.set_number    (pStudent->getStudentNum());
                tmp.set_name      (pStudent->getName());
                tmp.set_sex       (pStudent->getSex());
                tmp.set_race      (pStudent->getRace());
                tmp.set_birthday  (pStudent->getBirthday());
                tmp.set_native    (pStudent->getNative());
                tmp.set_class_name(pStudent->getClassName());
        }

        SINGLE->sendqueue.enqueue(packet(ST_GetStudentInfo, tmp, p->getfd()));
        SINGLE->bufpool.free(p);
}

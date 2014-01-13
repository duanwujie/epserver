#include "HandleMessage.h"

#include "../protocol.h"
#include "../Buf.h"
#include "../Single.h"
#include "../database.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"

#include "../content/epManager.h"

void CHandleMessage::handleGetActiveStudentList (Buf* p)
{
#ifdef __DEBUG_HANDLE_HEAD_
        cout << "CT_GetClassList\n";
#endif
        // TODO:

        cGetActiveStudentList casl;
        unpacket(p, casl);

        std::vector<int> vi = EPMANAGER->getActiveStudentListFromClass(casl.class_id());
        SINGLE->sendqueue.enqueue(packet(ST_GetActiveStudentList, vi, p->getfd()));
}

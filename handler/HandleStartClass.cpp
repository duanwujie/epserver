#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"
#include "../message/proto/protocol.pb.h"

void CHandleMessage::handleStartClass (Buf* p)
{
#ifdef __DEBUG_HANDLE_HEAD_
    cout << "CT_StartClass\n";
#endif
    // TODO:
}

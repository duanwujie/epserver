/*
 * HandleClassRoom.cpp
 */

#include "HandleMessage.h"

#include "../protocol.h"
#include "../Buf.h"
#include "../global_functions.h"
#include "../message/proto/protocol.pb.h"
#include "../netdef.h" // for __DEBUG__

#include "../content/epManager.h"
#include "../content/epUser.h"
#include "../content/epStudent.h"
#include "../content/epTeacher.h"
#include "../content/epWhiteBoard.h"


void CHandleMessage::handleLogin (Buf* p) {
        /**
         * @brief 用户登录处理函数。
         *        1. 用户发送用户类型，帐号，密码请求登录。
         *        2. 创建相应类型的登录对象。
         *        3. 使用数据库初始化对象。
         *        4. 返回登录成功与否。
         *        5. 如果登录成功，则将对象加入到游离列表中。
         */
        bool result = false;
        cLogin clogin;
        unpacket(p, clogin);
        printf("clogin.type    = %d\n", clogin.type());
        printf("clogin.account = %s\n", clogin.account().c_str());
        printf("clogin.passwd  = %s\n", clogin.passwd().c_str());

        epUser* pUser = EPMANAGER->getUserByAccount(clogin.account());
        if (NULL == pUser) {
                switch (clogin.type()) {
                case LT_STUDENT :
                        pUser = new epStudent();
                        break;
                case LT_HEADMASTER :
                        // pUser = new epHeadmaster();
                        break;
                case LT_TEACHER :
                        pUser = new epTeacher();
                        break;
                case LT_PARENTS :
                        // pUser = new epParents();
                        break;
                case LT_WHITEBOARD :
                        pUser = new epWhiteBoard();
                        break;
                default :
                        break;
                }

                result = pUser->init(clogin.account(), clogin.passwd());
                if (!result) {
                        printf("[INFO] handleLogin : epUser init fault!\n");
                        delete pUser;
                        pUser = NULL;
                } else {
                        EPMANAGER->insertUser(p->getfd(), pUser);
                        pUser->setFd(p->getfd());
                }
        } else {
                result = false;
        }
#ifdef __DEBUG_DUMP__
        EPMANAGER->dumpUser();
#endif

        sLogin slogin;
        slogin.set_result(result);

        SINGLE->sendqueue.enqueue(packet(ST_Login, slogin, p->getfd()));
        SINGLE->bufpool.free(p);
}

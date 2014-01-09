
#include "LoginCheck.h"
#include "protocol.h"
#include "message/proto/protocol.pb.h"

LoginCheck::LoginCheck() {
}

LoginCheck::~LoginCheck() {
}

void LoginCheck::check(Buf* pbuf) {
#if 0
    struct sLogin login;
    memcpy(&login, ((MSG_HEAD*)pbuf->ptr())->cData(), sizeof(login));
    //printf ("username = [%s], password = [%s]\n", login.username, login.password);
    int result = 0;

    switch(login.type) {
        case MCT_STUDENT:
            result = LoginCheck::login_student(pbuf->getfd(), login);
            break;
        case MCT_TEACHER:
            result = LoginCheck::login_teacher(pbuf->getfd(), login);
            break;
        case MCT_WHITEBOARD:
            result = LoginCheck::login_whiteboard(pbuf->getfd(), login);
            break;
        default:
            result = -1;
            break;
    }
#if 0
    // add
    Buf* p = SINGLE->bufpool.malloc();
    if (NULL == p) {
        printf("null buf\n");
        return;
    }

    p->setfd(pbuf->getfd());
#endif

    struct sLoginOutResult loginout;
    (void) memset (&loginout, 0x00, sizeof (loginout));
    loginout.succeed = (0 == result) ? RES_SUCCEED : RES_FAIL;
    strcpy (loginout.message, (0 == result) ? "Login succeed" : ((2 == result) ? "Logined" : "Login failed"));
    cout << "loginout.succeed: " << loginout.succeed << " loginout.message: " << loginout.message << endl;
    MSG_HEAD* head = (MSG_HEAD*)pbuf->ptr();
    head->cLen = sizeof(MSG_HEAD) + sizeof(loginout);
    head->cType = CT_LoginResult;
    memcpy(head->cData(), &loginout, sizeof(loginout));
    pbuf->setsize (head->cLen);     // fixed:
    SINGLE->sendqueue.enqueue(pbuf);
#endif
    return;
}

int LoginCheck::login_teacher(int fd, sLogin login) {
#if 0
    string strpwd;
    string Account;
    try {
        MutexLockGuard guard(DATABASE->m_mutex);
        PreparedStatement* pstmt = DATABASE->preStatement (SQL_SELECT_TEACHER);
        pstmt->setString (1, login.username);
        ResultSet* prst = pstmt->executeQuery ();
        while (prst->next ()) {
            strpwd = prst->getString ("password");
#if 0
            //id = prst->getInt("teacher_id");
            Account = prst->getString("account");
            Account = prst->getString("first_name");
            Account = prst->getString("last_name");
#endif
        }
        delete prst;
        delete pstmt;
    }catch (SQLException e) {
    }

    if ( 0 == strncmp(login.password, strpwd.c_str(), strlen (login.password)) && \
            strlen(login.password) > 0) {
        printf("teacher: login success!\n"); // ADD student_name to CLASS
        return 0;
    }
#endif
    return -1;
}

int LoginCheck::login_student(int fd, struct sLogin login)
{
#if 0
    string strpwd;
    string strFirstName;
    string strLastName;
    string strAccount;
    string strPictureName;
    int id = 0;
    try {
        MutexLockGuard guard(DATABASE->m_mutex);
        PreparedStatement* pstmt = DATABASE->preStatement(SQL_SELECT_STU);
        pstmt->setString(1, login.username);
        pstmt->setString(2, login.password);
        ResultSet* prst = pstmt->executeQuery();
        while(prst->next()) {
            strpwd = prst->getString("password");
            id = prst->getInt("student_id");
            strFirstName = prst->getString("first_name");
            strLastName = prst->getString("last_name");
            strAccount = prst->getString ("account");
            strPictureName = prst->getString ("picture_name");
        }
        delete prst;
        delete pstmt;
    }
    catch(SQLException e) {
        printf("[%s] %s\n",__FUNCTION__, e.what());
        LOG(ERROR) << e.what() <<endl;
    }

    if ( 0 == strncmp(login.password, strpwd.c_str(), strlen(login.password))) {
        printf("student: login success!\n"); // ADD student_name to CLASS

        CRoom* pRoom = ROOMMANAGER->get_room_by_fd (fd);
        if (pRoom == NULL) {
            LOG(ERROR) << "in login_student function. error: not found CLASS in CLASSMANAGER with fd" << endl;
            return -1;
        }

        printf("room[%d] get a sutdent\n", pRoom->get_room_id());

        LOG(INFO) << "room ["<<pRoom->get_room_id()<<"] get a student " << id <<endl;
        CStudent* pStudent = pRoom->get_student_by_fd (fd);
        if (pStudent == NULL) {
            LOG(ERROR) << "in login_student function. error: not found STUDENT in CLASSMANGER with fd" << endl;
            return -1;
        }

        string u_name = login.username;
        string p_word = login.password;
        if (pRoom->is_exist_in_class (u_name, p_word))
        {
            printf ("Exist in Class: username=%s, password=%s\n", \
                    login.username, login.password);
            return (2); // student logined.
        }

        pStudent->setName (strFirstName, strLastName);
        pStudent->setAccount (strAccount);
        pStudent->setPassword (strpwd);
        pStudent->setId (id);
        pStudent->setPictureName (strPictureName);
        pStudent->setOnLine (true);
        pStudent->setStudentStatus (eCS_ONLINE);

        // send student state to teacher.
        Buf* pp = SINGLE->bufpool.malloc();
        MSG_HEAD* p_head = (MSG_HEAD*)pp->ptr();
        p_head->cLen = sizeof(MSG_HEAD) + sizeof (unsigned int) + sizeof(TSendStudentStatusReq); 
        p_head->cType = ST_SendStudentStatus;

        TSendStudentStatusReq body;    
        body.student_id = pStudent->getId();
        body.status = eCS_ONLINE;
        *((unsigned int *)p_head->cData()) = 1;      // 设置变化状态的个数为1
        (void) memcpy((char*)p_head->cData() + sizeof (unsigned int), &body, sizeof(body));

        pp->setsize(p_head->cLen);      
        pp->setfd(pRoom->get_teacher_fd());        
        SINGLE->sendqueue.enqueue(pp);

        // send student state to whiteboard.
        Buf* ppp = SINGLE->bufpool.malloc ();
        MSG_HEAD* ppp_head = (MSG_HEAD*) ppp->ptr();
        ppp_head->cLen = sizeof (MSG_HEAD) + sizeof (unsigned int) + sizeof (TSendStudentStatusReq);
        ppp_head->cType = ST_SendStudentStatus;
        (void) memset (&body, 0x00, sizeof (body));
        body.student_id = pStudent->getId();
        body.status = eCS_ONLINE;
        *((unsigned int *)ppp_head->cData()) = 1;
        (void) memcpy ((char*)ppp_head->cData() + sizeof (unsigned int), &body, sizeof (body));

        ppp->setsize(ppp_head->cLen);      
        ppp->setfd(pRoom->get_white_fd());        
        SINGLE->sendqueue.enqueue(ppp);

        // send student state to other students.
        CRoom::STUDENTMAP::iterator it;
        char tempbuf[512];
        char* ptempbuf = tempbuf;
        int idx = 0;
        memset (&tempbuf, 0x00, sizeof (tempbuf));
        for (it = pRoom->m_student_map.begin(); it != pRoom->m_student_map.end(); ++it)
        {
            idx++;
            cout << "id:" << it->second->getId() << ", status:" << it->second->getStudentStatus() << endl;
            ((TSendStudentStatusReq*)ptempbuf)->student_id = it->second->getId();
            ((TSendStudentStatusReq*)ptempbuf)->status = it->second->getStudentStatus();
            ptempbuf += sizeof (TSendStudentStatusReq);

        }

        cout << "idx:" << idx << ", total len:" << idx * sizeof (TSendStudentStatusReq) << endl;
        //
        for (it = pRoom->m_student_map.begin(); it != pRoom->m_student_map.end(); ++it)
        {
            pp = SINGLE->bufpool.malloc ();
            if (pp != NULL)
            {
                p_head = (MSG_HEAD*) pp->ptr();
                p_head->cLen = MSG_HEAD_LEN + sizeof (TSendStudentStatusReq) * idx + sizeof (int);
                p_head->cType = ST_SendStudentStatus;

                memcpy (p_head->cData(), &idx, sizeof (int));
                //cout << "  idx ;; " << *(int *)p_head->cData() << endl;
                memcpy ((char*)p_head->cData() + sizeof (int), tempbuf, sizeof (TSendStudentStatusReq)*idx);
                //cout << " ID: " << ((TSendStudentStatusReq*) ((char*) p_head->cData() + sizeof (int)))->student_id << endl;
                //cout << " STATUS: " << ((TSendStudentStatusReq*) ((char*) p_head->cData()+ sizeof (int)))->status << endl;

                pp->setsize (p_head->cLen);
                //cout << "p_head->cLen = " << p_head->cLen << endl;
                pp->setfd (it->first);
                SINGLE->sendqueue.enqueue (pp);
            }
        }
        return 0;
    }
    printf("login failed: [%s][%s]", login.password, strpwd.c_str());
#endif
    return -1;
}

int LoginCheck::login_whiteboard(int fd, struct sLogin login) {
#if 0
    string roomName;
    try {
        MutexLockGuard guard(DATABASE->m_mutex);
        PreparedStatement* pstmt = DATABASE->preStatement (SQL_SELECT_CLASSROOM1);
        pstmt->setString (1, login.username);
        ResultSet* prst = pstmt->executeQuery ();
        while (prst->next ()) {
            roomName = prst->getString ("classroom_name");
        }
        delete prst;
        delete pstmt;
    }catch(SQLException e) {
    }
#endif
    // ADD classroom_name and whiteboard_name to CLASS
    return 0;
}

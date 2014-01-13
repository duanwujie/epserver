#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <iostream>
#include <string>

#include "../protocol.h"
#include "../Sock.h"
#include "../message/proto/protocol.pb.h"
#define SERV_IP "192.168.0.194"
#define SERV_PORT 9999 

#define MAX_BUFF_SIZE   1024
#define BUFCLR(buf)    (void)memset(buf, 0x00, sizeof(buf))
#define MEMCPYSTRTOBUF(buf) \
    (void) memcpy (buffer+MSG_HEAD_LEN, g_tmp_str.c_str(), g_tmp_str.size())

using namespace std;

int sfd;
char buf[MAX_BUFF_SIZE];
char* buffer = buf;
MSG_HEAD* head = NULL;
string g_tmp_str;
    
void recv_data (int sfd, char** buffer)
{
    int i = recv_v (sfd, (*buffer), sizeof (int));
    if (sizeof (int) != i) {
        cout << "ST_Login: recv head error! actually received len = " << i
            <<", info = "<< strerror (errno)<<endl;
        close (sfd);
    }
    int *p =  (int*) (*buffer);
    i = recv_v (sfd,  (*buffer) + sizeof(int), *p-sizeof(int));

    if ((*p - sizeof(int)) != (int)i) {
        cout <<"ST_Login: recv body error! hope = "<< *p <<", actually received len = "<< i 
            <<", info = "<< strerror (errno) <<endl;
        close (sfd);
    }
}

void dumpHead (string proto, char* buffer)
{
    cout << "-------------------" << endl;
    cout << proto  << ":" << endl;
    cout << "message head.cLen=" << ((MSG_HEAD*) buffer)->cLen << endl;
    cout << "message head.cType=" << ((MSG_HEAD*) buffer)->cType << endl;
}

void dumpTail (char* buffer)
{
    cout << "-------------------" << endl;
}

void dumpLogin (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strLogin = buffer + MSG_HEAD_LEN;

    sLogin sl;
    sl.ParseFromString (strLogin);

    if (sl.result())
        cout << "result of Server: true" << endl;
    else
        cout << "result of Server: false" << endl;

    dumpTail (buffer);  
}

void dumpGetFuncList (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetFuncList;
   
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i<count; i++) {
        sGetFuncList fl;
        strGetFuncList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetFuncList);
        fl.ParseFromString (strGetFuncList);
        //
        cout << "grade(" << i << ") id=" << fl.id () << endl;
        cout << "grade(" << i << ") name=" << fl.name () << endl;
        cout << "grade(" << i << ") res_path=" << fl.res_path () << endl;
    }
    dumpTail (buffer);
}

void dumpSetFunc (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strSetFunc;

    sSetFunc sf;
    strSetFunc = buffer + MSG_HEAD_LEN;
    sf.ParseFromString (strSetFunc);

    //
    cout << "function result=" << sf.result () << endl;
    dumpTail (buffer);
}

void dumpGetGradeList (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetGradeList;
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i < count; i++) {
        sGetGradeList ggl;
        strGetGradeList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetGradeList);
        ggl.ParseFromString (strGetGradeList);
        //
        cout << "grade(" << i << ") id=" << ggl.grade_id () << endl;
        cout << "grade(" << i << ") name=" << ggl.grade_name () << endl;
    }

    dumpTail (buffer);
}

void dumpGetCourseList (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetCourseList;
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i < count; i++) {
        sGetCourseList gcl;
        strGetCourseList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetCourseList);
        gcl.ParseFromString (strGetCourseList);
        //
        cout << "course(" << i << ") id=" << gcl.course_id() << endl;
        cout << "course(" << i << ") name=" << gcl.course_name() << endl;
        cout << "course(" << i << ") language=" << gcl.language() << endl;
        cout << "course(" << i << ") art=" << gcl.art() << endl;
        cout << "course(" << i << ") comunity=" << gcl.community() << endl;
        cout << "course(" << i << ") health=" << gcl.health() << endl;
        cout << "course(" << i << ") science=" << gcl.science() << endl;
        cout << "course(" << i << ") res_path=" << gcl.res_path() << endl;
    }
    dumpTail (buffer);
}

void dumpGetClassRoomList (string proto, char* buffer)
{    
    dumpHead (proto, buffer);
    string strGetClassRoomList;
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i < count; i++) {
        sGetClassRoomList crl;
        strGetClassRoomList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetClassRoomList);
        crl.ParseFromString (strGetClassRoomList);
        //
        cout << "ClassRoom(" << i << ") id=" << crl.classroom_id() << endl;
        cout << "ClassRoom(" << i << ") name=" << crl.classroom_name() << endl;
    }
    dumpTail (buffer);
}

void dumpGetClassList (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetClassList;
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i < count; i++) {
        sGetClassList gcl;
        strGetClassList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetClassList);
        gcl.ParseFromString (strGetClassList);
        //
        cout << "class(" << i << ") id=" << gcl.class_id() << endl;
        cout << "class(" << i << ") name=" << gcl.class_name() << endl;
    }
    dumpTail (buffer);
}

void dumpGetStudentList (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetStudentList;
    int count = *(int*) (buffer + MSG_HEAD_LEN);
    int i = 0;

    for (; i < count; i++) {
        sGetStudentList gsl;
        strGetStudentList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetStudentList);
        gsl.ParseFromString (strGetStudentList);
        //
        cout << "Student(" << i << ") id=" << gsl.id() << endl;
        cout << "Student(" << i << ") name=" << gsl.name() << endl;
        cout << "Student(" << i << ") res_path=" << gsl.res_path() << endl;
    }
    dumpTail (buffer);
}

void dumpGetActiveStudentList (string proto, char* buffer)
{
	 dumpHead (proto, buffer);
	 string strGetActiveStudentList;
	 int count = *(int*) (buffer + MSG_HEAD_LEN);
	 int i = 0;
	 	
	 for(; i < count; i++) {
		  sGetActiveStudentList gasl;
		  strGetActiveStudentList = buffer + MSG_HEAD_LEN + sizeof (int) + i * sizeof (sGetActiveStudentList);
		  gasl.ParseFromString (strGetActiveStudentList);
		  //
		  cout << "ActiveStudent(" << i << ") id=" << gasl.id() << endl;
	 }
	 dumpTail (buffer);
}

void dumpGetStudentInfo (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetStudentInfo;
    sGetStudentInfo gsi;
    strGetStudentInfo = buffer + MSG_HEAD_LEN;
    gsi.ParseFromString (strGetStudentInfo);

    cout << "student id=" << gsi.id() << endl;
    cout << "student number=" << gsi.number() << endl;
    cout << "student name=" << gsi.name() << endl;
    cout << "student sex=" << gsi.sex() << endl;
    cout << "student race=" << gsi.race() << endl;
    cout << "student birthday=" << gsi.birthday() << endl;
    cout << "student native=" << gsi.native() << endl;
    cout << "student class_name=" << gsi.class_name() << endl;

    dumpTail (buffer);
}


void dumpGetTeacherInfo (string proto, char* buffer)
{
    dumpHead (proto, buffer);
    string strGetTeacherInfo;
    sGetTeacherInfo gti;
    strGetTeacherInfo = buffer + MSG_HEAD_LEN;
    gti.ParseFromString (strGetTeacherInfo);

    cout << "teacher id=" << gti.id() << endl;
    cout << "teacher number=" << gti.number() << endl;
    cout << "teacher name=" << gti.name() << endl;
    cout << "teacher sex=" << gti.sex() << endl;
    cout << "teacher race=" << gti.race() << endl;
    cout << "teacher birthday=" << gti.birthday() << endl;
    cout << "teacher native=" << gti.native() << endl;
    cout << "teacher school_name=" << gti.school_name() << endl;

    dumpTail (buffer);
}

void handlerLogin()
{
    string client_account, client_passwd;
    int client_type;
    ///// CT_Login
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_Login;
    head->cLen = MSG_HEAD_LEN + sizeof (cLogin);

    cout << "ClientType:";
    cin >> client_type;
    cout << "Account:";
    cin >> client_account;
    cout << "Password:";
    cin >> client_passwd;

    cLogin login;
#ifdef _STANDARD
    login.set_type(client_type);
    login.set_account(client_account);
    login.set_passwd (client_passwd);
#else
    login.set_type(LT_TEACHER);
    login.set_account("张三");
    login.set_passwd ("123456");
#endif

    g_tmp_str.clear();
    login.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF(buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);

    // ST_Login
    recv_data (sfd, &buffer);
    dumpLogin ("ST_Login", buffer);
}

void handlerLogout()
{
}

void handlerGetFuncList()
{
    ///// CT_GetFuncList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetFuncList;
    head->cLen = MSG_HEAD_LEN;

    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
    
    // ST_GetFuncList
    recv_data (sfd, &buffer);
    dumpGetFuncList ("ST_GetFuncList", buffer);
}

void handlerSetFunc()
{
    int func_type;
    ///// CT_SetFunc
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_SetFunc;
    head->cLen = MSG_HEAD_LEN + sizeof (cSetFunc);

    cSetFunc sf;
    cout << "function type:";
    cin >> func_type;
#ifdef _STANDARD
    sf.set_func_type(func_type);
#else
    sf.set_func_type(1);
#endif

    g_tmp_str.clear();
    sf.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF(buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR (buffer);

    // ST_SetFunc
    recv_data (sfd, &buffer);
    dumpSetFunc ("ST_SetFunc", buffer);
}

void handlerGetGradeList()
{
    ///// CT_GetGradeList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetGradeList;
    head->cLen = MSG_HEAD_LEN + sizeof (cGetGradeList);

    send_v (sfd, buffer, head->cLen);
    BUFCLR (buffer);
    
    // ST_GetGradeList
    recv_data (sfd, &buffer);
    dumpGetGradeList ("ST_GetGradeList", buffer);
}

void handlerGetCourseList()
{
    int grade_id;
    ///// CT_GetCourseList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetCourseList;
    head->cLen = MSG_HEAD_LEN + sizeof (cGetCourseList);

    cout << "grade id:";
    cin >> grade_id;
    cGetCourseList cl;
#ifdef _STANDARD
    cl.set_func_id(grade_id);
#else
    cl.set_grade_id(1);
#endif

    g_tmp_str.clear();
    cl.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF(buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);

    // ST_GetCourseList
    recv_data (sfd, &buffer);
    dumpGetCourseList ("ST_GetCourseList", buffer);
}

void handlerGetClassList()
{
    int grade_id;
    ///// CT_GetClassList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetClassList;
    head->cLen = MSG_HEAD_LEN + sizeof (cGetClassList);

    cout << "grade id:";
    cin >> grade_id;
    cGetClassList cgcl;

#ifdef _STANDARD
    cgcl.set_grade_id (grade_id);
#else
    cgcl.set_grade_id (1);
#endif

    cgcl.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF (buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
   
    // ST_GetClassList
    recv_data (sfd, &buffer);
    dumpGetClassList ("ST_GetClassList", buffer);
}

void handlerGetClassRoomList()
{
    ///// CT_GetClassRoomList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetClassRoomList;
    head->cLen = MSG_HEAD_LEN;

    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
 
    // ST_GetClassRoomList
    recv_data (sfd, &buffer);
    dumpGetClassRoomList ("ST_GetClassRoomList", buffer);
}

void handlerSetContentList()
{
    int class_id, classroom_id;
    string course_list;
    //// CT_SetContent
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_SetContent;
    head->cLen = MSG_HEAD_LEN;
   
    cout << "class id:"; 
    cin >> class_id;
    cout << "classroom id:"; 
    cin >> classroom_id;
    cout << "course list:"; 
    cin >> course_list;

    cSetContent sc;
#ifdef _STANDARD
    sc.set_class_id (class_id);
    sc.set_classroom_id (classroom_id);
    sc.set_course_list(course_list);
#else
    sc.set_class_id (1);
    sc.set_classroom_id (1);
    sc.set_course_list("this is a course list.");
#endif

    g_tmp_str.clear();
    sc.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF(buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
 
    // ST_SetContent
    recv_data (sfd, &buffer);
    dumpGetStudentInfo ("ST_SetContent", buffer);
}

void handlerGetStudentList()
{
    int class_id;
    // CT_GetStudentList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetStudentList;
    head->cLen = MSG_HEAD_LEN;
   
    cout << "class id:";
    cin >> class_id;
 
    cGetStudentList sl;
#ifdef _STANDARD
    sl.set_class_id (class_id);
#else
    sl.set_class_id (1);
#endif

    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);

    // ST_GetStudentList
    recv_data (sfd, &buffer);
    dumpGetStudentList ("ST_GetStudentList", buffer);
}

void handlerGetStudentInfo()
{
    int student_id;
    ///// CT_GetStudentInfo
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetStudentInfo;
    head->cLen = MSG_HEAD_LEN;
   
    cout << "student id:";
    cin >> student_id; 
    cGetStudentInfo si;
#ifdef _STANDARD
    si.set_id (student_id);
#else
    si.set_id (1);
#endif

    g_tmp_str.clear();
    si.SerializeToString (&g_tmp_str);
    MEMCPYSTRTOBUF(buffer);
    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
 
    // ST_GetStudentInfo
    recv_data (sfd, &buffer);
    dumpGetStudentInfo ("ST_GetStudentInfo", buffer);
}

void handlerGetTeacherInfo()
{
    int teacher_id;
    //// CT_GetTeacherInfo
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetTeacherInfo;
    head->cLen = MSG_HEAD_LEN;
   
    cout << "teacher id:";
    cin >> teacher_id; 
    cGetTeacherInfo ti;
#ifdef _STANDARD
    ti.set_id (teacher_id);
#else
    ti.set_id (1);
#endif

    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
 
    // ST_GetTeacherInfo
    recv_data (sfd, &buffer);
    dumpGetTeacherInfo ("ST_GetTeacherInfo", buffer);
}

void handlerGetActiveStudentList()
{   
    int class_id;
    //// CT_GetActiveStudentList
    BUFCLR(buffer);
    head = (MSG_HEAD*) buffer;
    head->cType = CT_GetActiveStudentList;
    head->cLen = MSG_HEAD_LEN;
   
    cout << "class id:";
    cin >> class_id; 
    cGetActiveStudentList sl;
#ifdef _STANDARD
    sl.set_class_id (class_id);
#else
    sl.set_class_id (1);
#endif

    send_v (sfd, buffer, head->cLen);
    BUFCLR(buffer);
 
    // ST_GetActiveStudentList
    recv_data (sfd, &buffer);
    dumpGetActiveStudentList ("ST_GetActiveStudentList", buffer);
}

int main (int argc, char** argv)
{
    string strMessageType;

    if ((sfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("socket: ");
        return (-1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr (SERV_IP);
    addr.sin_port = htons (SERV_PORT);

    if (connect (sfd, (struct sockaddr*) &addr, sizeof (struct sockaddr)) < 0) {
        perror ("connect: ");
        return (-1);
    }
    while (1) {
        cout << "input message type: ";
        cin >> strMessageType;

        if (strMessageType == "CT_Login") {
            handlerLogin();
        }
        else if (strMessageType == "CT_Logout") {
            handlerLogout();
        }
        else if (strMessageType == "CT_GetFuncList") {
            handlerGetFuncList();
        }
        else if (strMessageType == "CT_SetFunc") {
            handlerSetFunc();
        }
        else if (strMessageType == "CT_GetGradeList") {
            handlerGetGradeList();
        }
        else if (strMessageType == "CT_GetCourseList") {
            handlerGetCourseList();
        }
        else if (strMessageType == "CT_GetClassList") {
            handlerGetClassList();
        }
        else if (strMessageType == "CT_GetClassRoomList") {
            handlerGetClassRoomList();
        }
        else if (strMessageType == "CT_SetContent") {
            handlerSetContentList();
        }
        else if (strMessageType == "CT_GetStudentList") {
            handlerGetStudentList();
        }
        else if (strMessageType == "CT_GetStudentInfo") {
            handlerGetStudentInfo();
        }
        else if (strMessageType == "CT_GetTeacherInfo") {
            handlerGetTeacherInfo();
        }
        else if (strMessageType == "ST_GetActiveStudentList") {
            handlerGetActiveStudentList();
        }

        else if ((strMessageType == "Exit") ||
                 (strMessageType == "EXIT") ||
                 (strMessageType == "exit") ||
                 (strMessageType == "Quit") ||
                 (strMessageType == "QUIT") ||
                 (strMessageType == "quit") ||
                 (strMessageType == "q"   ) ||
                 (strMessageType == "Q")) {
            cout << "Bye." << endl;
            break;
        }
        else {
            cout << "no handler" << endl;
        }
    }
    
    return (0);
}

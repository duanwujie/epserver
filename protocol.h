#include <string.h>

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#pragma pack(1)
enum CommandType {
	CT_Test = 1,
	ST_Test,

	CT_Heart,
	ST_Heart,

	CT_Auth,
	ST_Auth,

        // 登录/*{{{*/
        CT_Login = 100,
        ST_Login,

        CT_Logout,
        ST_Logout,

        CT_GetFuncList,
        ST_GetFuncList,

        CT_SetFunc,
        ST_SetFunc,

        CT_GetGradeList,
        ST_GetGradeList,

        CT_GetCourseList,
        ST_GetCourseList,

        CT_GetClassList,
        ST_GetClassList,

        CT_GetClassRoomList,
        ST_GetClassRoomList,

        // 设置上课内容。设置课程，班级，教室。
        CT_SetContent,
        ST_SetContent,

        CT_GetContent,
        ST_GetContent,
/*}}}*/
        // 开始上课。/*{{{*/
        CT_StartClass = 200,
        ST_StartClass,

        // 获取学生列表。
        CT_GetStudentList,
        ST_GetStudentList,

        // 获取在线学生列表。教师点击上课时由教师端或学生端主动请求的活动学生列表。
        CT_GetActiveStudentList,
        ST_GetActiveStudentList,

        // 当晚来的学生登录并选择学校功能时，需要将该学生的上线信息通知给该教室内上课的其它学生。
        ST_UpdateStudentStatus,

        // 获取学生详细信息。
        CT_GetStudentInfo,
        ST_GetStudentInfo,

        // 获取老师详细信息。
        CT_GetTeacherInfo,
        ST_GetTeacherInfo,
        /*}}}*/
};

enum LoginType {
        LT_USER,
        LT_HEADMASTER,
        LT_TEACHER,
        LT_PARENTS,
        LT_STUDENT,
        LT_WHITEBOARD,
};

enum FuncType {
        FT_INVALID,
        FT_PERSONAL = 1,
        FT_SCHOOL,
        FT_FAMILY,
        FT_FRIEND,
        FT_OFFICE,
};

// 下面是所有用到的数据结构体
//

///////////////////

typedef struct sSubmitData {
	unsigned int cLen;          // 数据长度
	enum CommandType cType;     // 数据编号
	void* cData() {             // 指向数据的指针
		return this + 1;
	}
} MSG_HEAD;

#define MSG_HEAD_LEN    sizeof(struct sSubmitData)

#pragma pack()

#endif //_PROTOCOL_H

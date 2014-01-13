#ifndef	__NETDEF_H__
#define __NETDEF_H__

#ifndef __DEBUG__
#       define __DEBUG__
#endif

// for Buf.h
#ifndef BUF_MAX_SIZE
#    define BUF_MAX_SIZE	(512)
#endif

#ifndef BUF_INVALIED_FD
#    define BUF_INVALIED_FD	(-1)
#endif

#ifndef BUF_INVALIED_ID
#    define BUF_INVALIED_ID	(-1)
#endif

// for PoolT.h
#ifndef POOLT_MAX_SIZE
#    define POOLT_MAX_SIZE	(20000)
#endif

// for MsgReceiver.cpp
#ifndef MSGRECEIVER_SERV_IP
#    define MSGRECEIVER_SERV_IP	("192.168.0.194")
#endif

#ifndef MSGRECEIVER_SERV_PORT
#    define MSGRECEIVER_SERV_PORT	(8888)
#endif

// for epClass.h
#ifndef EPCLASS_INVALID_CLASS_ID
#       define EPCLASS_INVALID_CLASS_ID (-1)
#endif

// for epSchool.h
#ifndef EPSCHOOL_INVALID_SCHOOL_ID
#       define EPSCHOOL_INVALID_SCHOOL_ID      (-1)
#endif

// for epClassroom.h
#ifndef EPCLASSROOM_INVALID_CLASSROOM_ID
#       define EPCLASSROOM_INVALID_CLASSROOM_ID (-1)
#endif

// for epPerson.h
#ifndef EPPERSON_INVALID_PERSON_AGE
#       define EPPERSON_INVALID_PERSON_AGE      (-1)
#endif

// for epTeacher.h
#ifndef EPTEACHER_INVALID_TEACHER_ID
#       define EPTEACHER_INVALID_TEACHER_ID     (-1)
#endif

// for epStudent.h
#ifndef EPSTUDENT_INVALIED_ID
#       define EPSTUDENT_INVALIED_STUDENT_ID    (-1)
#endif

// for epWhiteBoard.h
#ifndef EPWHITEBOARD_INVALID_WHITEBOARD_ID
#       define EPWHITEBOARD_INVALID_WHITEBOARD_ID       (-1)
#endif

// for epGroup.h
#ifndef EPGROUP_INVALID_GROUP_ID
#       define EPGROUP_INVALID_GROUP_ID (-1)
#endif

// for handle content
#ifndef CHECK_USER
#define CHECK_USER(T, obj) \
        epUser* user = EPMANAGER->getUserByFd(p->getfd()); \
        if (NULL == user) { \
                SINGLE->bufpool.free(p); \
                return; \
        } \
        T* obj = dynamic_cast<T*>(user);\
        if (NULL == obj) { \
                SINGLE->bufpool.free(p); \
                return; \
        }
#endif

// for epUser.cpp
#ifndef EPUSER_INVALID_USER_ID
#       define EPUSER_INVALID_USER_ID   (-1)
#endif

#ifndef EPUSER_INVALID_USER_FD
#       define EPUSER_INVALID_USER_FD (-1)
#endif

#endif // __NETDEF_H__

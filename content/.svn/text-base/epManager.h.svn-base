/**
 * @file epManager.h
 * @brief 管理类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-08
 */

#ifndef __EPMANAGER_H__
#define __EPMANAGER_H__

#include <map>

#include "Uncopyable.h"
#include "epClassroom.h"
#include "epUser.h"

typedef std::map<int, epClassroom> EPCLASSROOM_MAP;
typedef std::map<int, epUser*> EPUSER_MAP;

/**
 * @brief 管理类。
 */
class epManager : public Uncopyable {
public :
        static epManager*  instance(void);

        /**
         * @brief 插入指定教室到管理类。
         *
         * @param epClassroom[in] 指定教室。
         *
         * @return 插入成功返回true，否则返回false。
         */
        bool insertClassroom(epClassroom&);
        /**
         * @brief 移除指定ID的教室，并不删除教室类。
         *
         * @param int[in] 指定教室ID。
         *
         * @return 移除成功返回true，否则返回false。
         */
        bool removeClassroomById(int);
        /**
         * @brief 根据用户FD获取其当前上课教室对象指针。
         *
         * @param int[in] 用户FD。
         *
         * @return 查找成功返回教室对象指针，否则返回NULL。
         */
        epClassroom* getClassroomByFd(const int);
        /**
         * @brief 获取指定班级ID所对象的教室。
         *
         * @param int[in] 指定班级ID。
         *
         * @return 该班级所使用的教室。
         */
        epClassroom* getClassroomByClassId(const int);
        /**
         * @brief 从教室列表中获取指定ID的教室对象指针。
         *
         * @param int[in] 指定教室ID。
         *
         * @return 成功返回指定教室ID所对应的教室对象指针，否则返回NULL。
         */
        epClassroom* getClassroomById(int);
        /**
         * @brief 根据班级ID查找当前上课的班级对象。
         *
         * @param int[in] 班级ID。
         *
         * @return 成功返回班级对象指针，否则返回NULL。
         */
        epClass* getClassById(int);

        /**
         * @brief 将指定FD的对象插入到游离列表中。
         *
         * @param int[in] 指定FD。
         * @param epUser 指定对象指针。
         *
         * @return 插入成功返回true，否则返回false。
         */
        bool insertUser(int, epUser*);
        /**
         * @brief 从列表中删除指定FD的对象。并不delete对象，只是在列表中删除关系。
         *
         * @param int 指定FD
         *
         * @return 移除成功返回true, 失败返回 false.
         */
        bool removeUserByFd(const int);
        /**
         * @brief 根据登录帐号查找处于游离状态的用户。
         *
         * @param std::string[in] 帐号。
         *
         * @return 成功返回指向相应对象的指针，失败返回NULL。
         */
        epUser* getUserByAccount(const std::string&);
        /**
         * @brief 获取指定FD的对象指针。
         *
         * @param int[in] 需要查找对象的FD。
         *
         * @return 成功返回指向相应对象的指针，失败返回NULL。
         */
        epUser* getUserByFd(const int);
        /**
         * @brief 根据学生ID获取学生对象指针。
         *
         * @param int[in] 学生ID。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        epStudent* getStudentById(const int);
        /**
         * @brief 根据学生ID获取学生对象指针。
         *
         * @param int[in] 学生ID。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        epStudent* getStudentByIdFromUser(const int);
        /**
         * @brief 根据学生ID获取学生对象指针。
         *
         * @param int[in] 学生ID。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        epStudent* getStudentByIdFromClassroom(const int);
        /**
         * @brief 根据客户FD获取教师对象指针。
         *
         * @param int[in] 客户FD。
         *
         * @return 成功返回教师对象指针，否则返回NULL。
         */
        epTeacher* getTeacherByFd(const int);
        /**
         * @brief 根据教师ID获取教师对象指针。
         *
         * @param int[in] 教师ID。
         *
         * @return 成功返回教师对象指针，否则返回NULL。
         */
        epTeacher* getTeacherById(const int);
        /**
         * @brief 根据教师ID获取教师对象指针。
         *
         * @param int[in] 教师ID。
         *
         * @return 成功返回教师对象指针，否则返回NULL。
         */
        epTeacher* getTeacherByIdFromUser(const int);
        /**
         * @brief 根据教师ID获取教师对象指针。
         *
         * @param int[in] 教师ID。
         *
         * @return 成功返回教师对象指针，否则返回NULL。
         */
        epTeacher* getTeacherByIdFromClassroom(const int);
        /**
         * @brief 根据指定班级ID获取该班级在线学生列表。
         *
         * @param int[in] 指定班级ID。
         *
         * @return 在线学生列表。
         */
        std::vector<int> getActiveStudentListFromClass(const int);
        /**
         * @brief 将处于游离状态，并选择了学校功能，
         *        且在指定班级ID的学生加入到指定班级。
         *
         * @param int[in] 班级ID。
         *
         * @return 成功返回true，否则返回false。
         */
        bool insertStudentFromUserIntoClass(const int);
        /**
         * @brief 从游离列表中将学生加入到刚上课的指定ID的教室中。
         *
         * @param int[in] 指定教室ID。
         *
         * @return 成功返回true，否则返回false。
         */
        bool insertStudentFromUserIntoClassroom(const int);
        /**
         * @brief 将指定消息内容发送给当前上课的班级。
         *
         * @param Buf[in] 指定消息内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoAllClassroom(Buf*);
        /**
         * @brief 将指定消息内容发送给指定班级。
         *
         * @param int[in] 指定班级ID。
         * @param Buf[in] 指定消息内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoClassroom(const int, Buf*);
        /**
         * @brief 将指定消息内容发送给所有游离用户。
         *
         * @param Buf[in] 指定消息。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoAllUser(Buf*);
        /**
         * @brief 将指定消息内容发送给指定游离用户。
         *
         * @param int[in] 指定用户FD。
         * @param Buf[in] 指定消息。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoUser(const int, Buf*);

        /**
         * @name Just for debug
         * @{ */
        /**
         * @brief 打印教室列表。
         */
        virtual void dumpClassroom(void);
        /**
         * @brief 打印游离状态的 client。
         */
        virtual void dumpUser(void);
        /**  @} */

private :
        static epManager* p_;
        epManager (void);
        ~epManager(void);

private :
        /**
         * @brief 教室列表。first为教室ID
         */
        EPCLASSROOM_MAP classroomMap_;
        /**
         * @brief 存入游离的FD，first为FD。
         */
        EPUSER_MAP userMap_;
};

#define EPMANAGER       (epManager::instance())

#endif // __EPMANAGER_H__

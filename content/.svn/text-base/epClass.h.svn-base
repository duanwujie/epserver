/**
 * @file epClass.h
 * @brief 班级类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-08
 */

#ifndef __EPCLASS_H__
#define __EPCLASS_H__

#include <map>
#include <vector>

#include "epStudent.h"
#include "../Buf.h"

typedef std::map<int, epStudent> EPSTUDENT_MAP;

/**
 * @brief 班级类。
 */
class epClass {
public :
        epClass(const int);
        ~epClass(void);

        /**
         * @name get
         * @{ */
        /**
         * @brief 获取该班ID。
         *
         * @return 成功返回该班级ID，否则返回EPCLASS_INVALID_CLASS_ID
         */
        int getId(void);
        /**
         * @brief 根据学生ID获取学生对象指针。
         *
         * @param int[in] 学生ID。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        epStudent* getStudentById(const int);
        /**
         * @brief 获取在线学生列表。
         *
         * @return 在线学生列表。
         */
        std::vector<int> getActiveStudent(void);
        /**  @} */

        /**
         * @name set
         * @{ */
        /**
         * @brief 设置班级ID。
         *
         * @param int[in] 班级ID。
         *
         * @return 设置成功返回TRUE，否则返回FALSE。
         */
        bool setId(const int);
        /**
         * @brief 将指定fd和学生对象插入到学生列表中。
         *
         * @param int[in] 指定FD。
         * @param epStudent[in] 指定学生对象。
         *
         * @return 插入成功返回true，否则返回false。
         */
        bool insertStudent(int, const epStudent&);
        /**
         * @brief 从学生列表中移除指定FD的学生对象，并不delete该学生对象。
         *
         * @param int[in] 指定FD。
         *
         * @return 移除成功返回true，否则返回false。
         */
        bool removeStudentByFd(const int);
        /**  @} */

        /**
         * @name get by ???
         * @{ */
        /**
         * @brief 获取指定fd的学生对象指针。
         *
         * @param int[in] 指定FD。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        const epStudent* getStudentByFd(const int);
        /**  @} */

        /**
         * @name sendto
         * @{ */
        /**
         * @brief 将指定消息内容发送给该班所有学生。
         *
         * @param Buf[in] 指定消息内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoAllStudent(Buf*);
        /**
         * @brief 将指定消息发送给指定FD的学生。
         *
         * @param int[in] 指定FD。
         * @param Buf[in] 指定消息内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoStudentByFd(const int, Buf*);
        /**  @} */


        /**
         * @name Just for debug
         * @{ */
        virtual void dump(void);
        /**  @} */


private :
        /**
         * @brief 班级ID。
         */
        int id_;
        /**
         * @brief 学生列表。first为FD，second为学生对象。
         */
        EPSTUDENT_MAP studentMap_;
};

#endif // __EPCLASS_H__

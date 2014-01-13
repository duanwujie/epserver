/**
 * @file epGroup.h
 * @brief 组别类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-09
 */

#ifndef __EPGROUP_H__
#define __EPGROUP_H__

#include <map>
#include "../Buf.h"

#include "epStudent.h"

typedef std::map<int, epStudent> STUDENT_MAP;

/**
 * @brief 组别类。
 */
class epGroup {
public :
        epGroup(void);
        ~epGroup(void);
        /**
         * @name set
         * @{ */
        /**
         * @brief 设置组ID。
         *
         * @param int[in] 指定组ID。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setId(const int);
        /**
         * @brief 向学生列表中插入指定FD和学生对象。
         *
         * @param int[in] 指定FD。
         * @param epStudent 指定学生对象。
         *
         * @return 成功返回true，否则返回false。
         */
        bool insertStudent(int, const epStudent&);
        /**
         * @brief 移除学生列表中的指定FD的学生对象，并不delete学生对象。
         *
         * @param int[in] 指定FD。
         *
         * @return 成功返回true，否则返回false。
         */
        bool removeStudentByFd(const int);
        /**  @} */

        /**
         * @name get
         * @{ */
        /**
         * @brief 获取组ID。
         *
         * @return 成功返回组ID，否则返回EPGROUP_INVALID_GROUP_ID。
         */
        int getId(void) const;
        /**  @} */

        /**
         * @name get by ???
         * @{ */
        /**
         * @brief 获取学生列表中指定FD的学生对象指针。
         *
         * @param int[in] 指定FD。
         *
         * @return 成功返回学生对象指针，否则返回NULL。
         */
        const epStudent* getStudentByFd(const int);
        /**  @} */

        /**
         * @brief 将指定消息发送给该组所有学生。
         *
         * @param Buf*[in] 指定消息内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool sendtoAllStudent(Buf*);
        bool sendtoStudentByFd(const int, Buf*);

        /**
         * @name Just for debug
         * @{ */
        virtual void dump(void);
        /**  @} */


private :
        /**
         * @brief 组ID
         */
        int id_;
        /**
         * @brief 该组学生列表。
         */
        STUDENT_MAP studentMap_;
};

#endif // __EPGROUP_H__

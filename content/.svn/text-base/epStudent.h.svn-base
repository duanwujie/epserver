/**
 * @file epStudent.h
 * @brief 学生类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-08
 */

#ifndef __EPSTUDENT_H__
#define __EPSTUDENT_H__

#include "epPerson.h"
#include "epUser.h"
#include "../protocol.h"

/**
 * @brief 学生类。
 */
class epStudent : public epPerson, public epUser {
public :
        epStudent(void);
        ~epStudent(void);

        /**
         * @name set
         * @{ */
        /**
         * @brief 设置学号。
         *
         * @param int[in] 指定学号。
         *
         * @return 设置成功返回true，否则返回false。
         */
        virtual bool setStudentNum(const std::string&);
        /**
         * @brief 设置所属班级号。
         *
         * @param int[in] 班级号。
         *
         * @return 设置成功返回true，否则返回false。
         */
        bool setClassId(const int);
        /**
         * @brief 设置所属班级名称。
         *
         * @param std::string[in] 班级名称。
         *
         * @return 设置成功返回true，否则返回false。
         */
        bool setClassName (const std::string&);
        /**
         * @brief 使用用户名和密码初始化学生对象。
         *
         * @param std::string[in] 用户名。
         * @param std::string[in] 密码。
         *
         * @return 设置成功返回true，否则返回false。
         */
        virtual bool init(const std::string&, const std::string&);
        /**  @} */

        /**
         * @name get
         * @{ */
        /**
         * @brief 获取学号。
         *
         * @return 成功返回该学生学号，否则返回EPSTUDENT_INVALID_STUDENT_NUM。
         */
        virtual std::string getStudentNum(void) const;
        /**
         * @brief 获取所属班号。
         *
         * @return 成功返回所属班号，否则返回EPCLASS_INVALID_CLASS_ID。
         */
        int getClassId(void) const;
        /**
         * @brief 获取所属班名称。
         *
         * @return 成功返回所属班名称，否则返回EPCLASS_INVALID_CLASS_NAME。
         */
        const std::string getClassName (void) const;
        /**
         * @brief 获取客户端类型。
         *
         * @return 相应客户端类型。
         */
        virtual enum LoginType getType(void) const;
        /**  @} */

        /**
         * @name get by ???
         * @{ */
        /**  @} */
        /**
         * @name Just for debug
         * @{ */
        virtual void dump(void);
        /**  @} */

private :
        /**
         * @brief 学号。
         */
        std::string studentNum_;
        /**
         * @brief 存放所属班名称。
         */
        std::string className_;
        /**
         * @brief 所属班级ID。
         */
        int classId_;
};

#endif // __EPSTUDENT_H__

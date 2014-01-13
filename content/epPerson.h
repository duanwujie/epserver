/**
 * @file epPerson.h
 * @brief 人物基类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-08
 */

#ifndef __EPPERSON_H__
#define __EPPERSON_H__

#include <iostream>

/**
 * @brief 人物基类。
 */
class epPerson {
public :
        epPerson (void);
        virtual ~epPerson(void);

        /**
         * @name set
         * @{ */
        bool setName     (const std::string&);
        /**
         * @brief 设置姓名。
         *
         * @param std::string 姓。
         * @param std::string 名。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setName     (const std::string&, const std::string&);
        /**
         * @brief 设置性别。
         *
         * @param std::string 性别。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setSex      (const std::string&);
        /**
         * @brief 设置年龄。
         *
         * @param int[in] 年龄。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setAge      (const int);
        /**
         * @brief 设置民族。
         *
         * @param std::string 民族。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setRace     (const std::string&);
        /**
         * @brief 设置生日。
         *
         * @param std::string[in] 生日的字符串形式。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setBirthday (const std::string&);
        /**
         * @brief 设置地区。
         *
         * @param std::string 地区字符串。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setNative   (const std::string&);
        /**  @} */

        /**
         * @name get
         * @{ */
        /**
         * @brief 获取名字。
         *
         * @return 名字。
         */
        const std::string getName      (void) const;
        /**
         * @brief 获取姓。
         *
         * @return 姓。
         */
        const std::string& getFirstname(void) const;
        /**
         * @brief 获取性别。
         *
         * @return 性别。
         */
        const std::string& getSex      (void) const;
        /**
         * @brief 获取年龄。
         *
         * @return 年龄。
         */
        int                getAge      (void) const;
        /**
         * @brief 获取民族。
         *
         * @return 民族。
         */
        const std::string& getRace     (void) const;
        /**
         * @brief 获取生日。
         *
         * @return 生日。
         */
        const std::string& getBirthday (void) const;
        /**
         * @brief 获取地区。
         *
         * @return 地区。
         */
        const std::string& getNative   (void) const;
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
         * @brief 存放姓。
         */
        std::string firstName_;

        /**
         * @brief 存入名。
         */
        std::string lastName_;

        /**
         * @brief 存放性别。
         */
        std::string sex_;

        /**
         * @brief 存放年龄。
         */
        int         age_;

        /**
         * @brief 存放民族。
         */
        std::string race_;

        /**
         * @brief 存放生日的字符串形式。
         */
        std::string birthday_;

        /**
         * @brief 存放国籍，地区。
         */
        std::string native_;
};

#endif // __EPPERSON_H__

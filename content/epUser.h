/**
 * @file epUser.h
 * @brief 用户类。
 * @author nvngliu@gmail.com
 * @version 1.0
 * @date 2014-01-08
 */

#ifndef __EPUSER_H__
#define __EPUSER_H__

#include <iostream>
#include "../protocol.h"

/**
 * @brief 用户类。
 */
class epUser {
public :
        epUser(void);
        virtual ~epUser(void);

        /**
         * @name set
         * @{ */
        /**
         * @brief 设置客户端ID。
         *
         * @param int[in] 客户端ID。
         *
         * @return 设置成功返回TRUE，否则返回FALSE。
         */
        virtual bool setId(const int);
        /**
         * @brief 设置客户端FD。
         *
         * @param int[in] 客户FD。
         *
         * @return 设置成功返回TRUE，否则返回FALSE。
         */
        bool setFd(const int);
        /**
         * @brief 设置帐号。
         *
         * @param std::string[in] 指定帐号内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setAccount(const std::string&);
        /**
         * @brief 设置密码。
         *
         * @param std::string[in] 指定密码内容。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setPasswd (const std::string&);
        /**
         * @brief 设置该客户的功能类型。
         *
         * @param FuncType[in] 功能类型。
         *
         * @return 成功返回true，否则返回false。
         */
        bool setFuncType(const enum FuncType);
        /**
         * @brief 使用传入的用户名和密码初始化对象。
         *
         * @param std::string[in] 用户名。
         * @param std::string[in] 密码。
         *
         * @return 成功返回true，否则返回false。
         */
        virtual bool init(const std::string&, const std::string&);
        /**  @} */

        /**
         * @name get
         * @{ */
        /**
         * @brief 获取帐号。
         *
         * @return 成功返回帐号。
         */
        const std::string& getAccount(void) const;
        /**
         * @brief 获取密码。
         *
         * @return 成功返回密码。
         */
        const std::string& getPasswd (void) const;
        /**
         * @brief 获取该客户端类型。
         *
         * @return 相应相应客户端类型。
         */
        virtual enum LoginType getType(void) const;
        /**
         * @brief 获取该客户端ID。
         *
         * @return 客户端ID。
         */
        virtual int getId(void) const;
        /**
         * @brief 获取该客户端FD。
         *
         * @return 客户端FD。
         */
        int getFd(void) const;
        /**
         * @brief 获取该客户所选择的功能。
         *
         * @return 功能。
         */
        enum FuncType getFuncType(void) const;
        /**  @} */

        /**
         * @name Just for debug
         * @{ */
        virtual void dump(void);
        /**  @} */

private :
        enum FuncType funcType_;
        /**
         * @brief 用户ID。
         */
        int id_;
        /**
         * @brief 用户FD。
         */
        int fd_;
        /**
         * @brief 存放账号。
         */
        std::string account_;
        /**
         * @brief 存放密码。
         */
        std::string passwd_;
};

#endif // __EPUSER_H__

/**
 * @addtogroup content
 * @{
 */
#ifndef LOGIN_H_
#define LOGIN_H_
#include "database.h"
#include "protocol.h"
#include "Buf.h"
#include "SQL.h"
#include "Single.h"

/**
 * @brief 登录管理类
 */
class LoginCheck{
public:
    LoginCheck();
    ~LoginCheck();
    static void check(Buf* pbuf);

    static int login_teacher(int fd, struct sLogin login);
    static int login_student(int fd, struct sLogin login);
    static int login_whiteboard(int fd, struct sLogin login);
};
#endif
///@}

#include "epUser.h"
#include <stdio.h> // for printf
#include "../netdef.h"

epUser::epUser(void)
        : funcType_(FT_INVALID)
          , id_(EPUSER_INVALID_USER_ID)
          , fd_(EPUSER_INVALID_USER_FD)
{
}

epUser::~epUser(void) {
}

bool
epUser::setId(const int id) {
        id_ = id;
        return true;
}

bool
epUser::setFd(const int fd) {
        fd_ = fd;
        return true;
}

bool
epUser::setAccount(const std::string& account) {
        account_ = account;
        return true;
}

bool
epUser::setPasswd(const std::string& passwd) {
        passwd_ = passwd;

        return true;
}

bool
epUser::setFuncType(const enum FuncType funcType) {
        funcType_ = funcType;
        return true;
}

bool
epUser::init(const std::string& account, const std::string& passwd) {
        setAccount(account);
        setPasswd(passwd);
        return true;
}

const std::string&
epUser::getAccount(void) const {
        return account_;
}

const std::string&
epUser::getPasswd(void) const {
        return passwd_;
}

enum LoginType
epUser::getType(void) const {
        return LT_USER;
}

int
epUser::getId(void) const {
        return id_;
}

int
epUser::getFd(void) const {
        return fd_;
}

enum FuncType
epUser::getFuncType(void) const {
        return funcType_;
}

void
epUser::dump(void) {
        printf("=======================================\n");
        printf("id       = %d\n", id_);
        printf("fd       = %d\n", fd_);
        printf("funcType = %d\n", funcType_);
        printf("account  = %s\n", account_.c_str());
        printf("passwd   = %s\n", passwd_.c_str());
}

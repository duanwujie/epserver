#include "epStudent.h"
#include "database.h"
#include "SQL.h"
#include <stdio.h> // for printf

epStudent::epStudent(void) {
}

epStudent::~epStudent(void) {
}

bool
epStudent::setClassId (const int iid) {
    classId_ = iid;
    return true;
}

bool
epStudent::setStudentNum(const std::string& studentNum) {
        studentNum_ = studentNum;
        return true;
}

bool
epStudent::setClassName (const std::string& className) {
        className_ = className;
        return true;
}

bool
epStudent::init(const std::string& account, const std::string& passwd) {
        epUser::init(account, passwd);
        bool result = false;
        std::string strpwd;
        try {
                MutexLockGuard guard(DATABASE->m_mutex);
                PreparedStatement* pstmt = DATABASE->preStatement (SQL_GET_STU_INFO_BY_ACCOUT);
                pstmt->setString (1, account);
                ResultSet* prst = pstmt->executeQuery ();
                while (prst->next ()) {
                        strpwd = prst->getString ("password");
                        if (0 == strncmp(passwd.c_str(), strpwd.c_str(), passwd.size()) && passwd.size() > 0) {

                                setName (prst->getString("last_name"), prst->getString ("first_name"));
                                setSex (prst->getString ("sex"));
                                setAge (prst->getInt ("age"));
                                setRace (prst->getString ("race_name"));
                                //setBirthday (prst->getString ("birthday"));
                                setNative (prst->getString ("native_name"));

                                setStudentNum (prst->getString ("number"));
                                setClassId (prst->getInt ("class_id"));
                                setClassName (prst->getString ("class_name"));
                                result = true;
                        } else {
                                result = false;
                        }
                }
                delete prst;
                delete pstmt;
        }catch (SQLException e) {
                printf ("SQLException: %s\n", e.what());    
                result = false;
        }

        return result;
}

std::string
epStudent::getStudentNum(void) const {
        return studentNum_;
}

const std::string
epStudent::getClassName (void) const {
        return className_;
}

int
epStudent::getClassId(void) const {
        return classId_;
}

enum LoginType
epStudent::getType(void) const {
        return LT_STUDENT;
}

void
epStudent::dump(void) {
        printf("for user :\n");
        epUser::dump();
        printf("for person :\n");
        epPerson::dump();
        printf("for student :\n");
        printf("student number = %s\n", studentNum_.c_str());
        printf("class id       = %d\n", classId_);
        printf("class name     = %s\n", className_.c_str());
}

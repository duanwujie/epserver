#include "epManager.h"
#include "../Single.h"
#include <iostream>

epManager* epManager::p_ = NULL;

epManager* epManager::instance(void) {
        if (NULL == p_) {
                p_ = new epManager();
        }

        return p_;
}

epManager::epManager(void) {
}

epManager::~epManager(void) {
}

bool
epManager::insertClassroom(epClassroom& obj) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                if (obj.getId() == it->first) {
                        return false;
                }
        }

        classroomMap_.insert(std::make_pair<int, epClassroom>(obj.getId(), obj));
        return true;
}

bool
epManager::removeClassroomById(int id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                if (id == it->first) {
                        classroomMap_.erase(it);
                        return true;
                }
        }

        return false;
}

epClassroom*
epManager::getClassroomByFd(const int fd) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();
        for (; cie!=it; ++it) {
                if (NULL != (it->second).getStudentById(fd)) { // 学生
                        return &(it->second);
                }

                if (fd == (it->second).getTeacher().getFd()) { // 教室。
                        return &(it->second);
                }

                if (fd == (it->second).getWhiteBoard().getFd()) { // 白板。
                        return &(it->second);
                }
        }

        return NULL;
}

epClassroom*
epManager::getClassroomByClassId(const int class_id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                if (NULL != (it->second).getClassById(class_id)) {
                        return &(it->second);
                }
        }

        return NULL;
}

epClassroom*
epManager::getClassroomById(int id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                if (id == it->first) {
                        return &(it->second);
                }
        }

        return NULL;
}

epClass*
epManager::getClassById(int id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        epClass* pClass = NULL;
        for (; cie!=it; ++it) {
                pClass = (it->second).getClassById(id);
                if (NULL != pClass) {
                        return pClass;
                }
        }

        return NULL;
}

bool
epManager::insertUser(const int fd, epUser* user) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        return false;
                }
        }

        userMap_.insert(std::make_pair<int, epUser*>(fd, user));
        return true;
}

bool
epManager::removeUserByFd(const int fd) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        userMap_.erase(it);
                        return true;
                }
        }

        return false;
}

epUser*
epManager::getUserByAccount(const std::string& account) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                if (account == (it->second)->getAccount()) {
                        return it->second;
                }
        }

        return NULL;
}

epUser*
epManager::getUserByFd(const int fd) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();
        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        epUser* pu = new epUser(*(it->second));
                        return pu;
                }
        }

        return NULL;
}

epStudent*
epManager::getStudentByIdFromUser(const int id) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                if (LT_STUDENT == (it->second)->getType()) {
                        if (id == (it->second)->getId()) {
                                return dynamic_cast<epStudent*>(it->second);
                        }
                }
        }

        return NULL;
}

epStudent*
epManager::getStudentByIdFromClassroom(const int id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        epStudent* pStudent = NULL;
        for (; cie!=it; ++it) {
                pStudent = (it->second).getStudentById(id);
                if (NULL != pStudent) {
                        return pStudent;
                }
        }

        return NULL;
}

epStudent*
epManager::getStudentById(const int id) {
        epStudent* pStudent = getStudentByIdFromUser(id);
        if (NULL != pStudent) {
                return pStudent;
        }

        pStudent = getStudentByIdFromClassroom(id);
        return pStudent;
}

epTeacher*
epManager::getTeacherByFd(const int fd) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();
        for (; cie!=it; ++it) {
                if (fd == (it->second).getTeacher().getFd()) {
                        return &((it->second).getTeacher());
                }
        }

        return NULL;
}

epTeacher*
epManager::getTeacherByIdFromUser(const int id) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                if (LT_TEACHER == (it->second)->getType()) {
                        if (id == (it->second)->getId()) {
                                return dynamic_cast<epTeacher*>(it->second);
                        }
                }
        }

        return NULL;
}

epTeacher*
epManager::getTeacherByIdFromClassroom(const int id) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                if ((it->second).getId() == id) {
                        return &((it->second).getTeacher());
                }
        }

        return NULL;
}

std::vector<int>
epManager::getActiveStudentListFromClass(const int class_id) {
        return getClassById(class_id)->getActiveStudent();
}

bool
epManager::insertStudentFromUserIntoClass(const int class_id) {
        epClass* pClass = getClassById(class_id);

        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        epStudent* pStudent = NULL;
        for (; cie!=it; ++it) {
                if (FT_SCHOOL == (it->second)->getFuncType()) {
                        pStudent = dynamic_cast<epStudent*>(it->second);
                        if (NULL!=pStudent && class_id==pStudent->getClassId()) {
                                pClass->insertStudent(it->first, *pStudent);
                                userMap_.erase(it);
                        }
                }
        }

        return true;
}

bool
epManager::insertStudentFromUserIntoClassroom(const int classroom_id) {
        epClassroom* pClassroom = getClassroomById(classroom_id);
        if (NULL != pClassroom) {
                std::vector<epClass*> vc = pClassroom->getClassList();
                for(unsigned int i=0; i<vc.size(); ++i) {
                        insertStudentFromUserIntoClass(vc[i]->getId());
                }
                return true;
        }

        return false;
}

epTeacher*
epManager::getTeacherById(const int id) {
        epTeacher* pTeacher = getTeacherByIdFromUser(id);
        if (NULL != pTeacher) {
                return pTeacher;
        }

        pTeacher = getTeacherByIdFromClassroom(id);
        return pTeacher;
}

bool
epManager::sendtoAllClassroom(Buf* pBuf) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();
        Buf* p = NULL;
        for (; cie!=it; ++it) {
                p = pBuf;
                (it->second).sendtoAllClass(p);
        }
        SINGLE->bufpool.free(pBuf);

        return true;
}

bool
epManager::sendtoClassroom(const int id, Buf* pBuf) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        SINGLE->sendqueue.enqueue(pBuf);
                        return true;
                }
        }
        return false;
}

bool
epManager::sendtoAllUser(Buf* pBuf) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();
        Buf* p = NULL;
        for (; cie!=it; ++it) {
                if (pBuf->getfd() == it->first) { // not to send self.
                        continue;
                }
                p = pBuf;
                p->setfd(it->first);
                SINGLE->sendqueue.enqueue(p);
        }

        SINGLE->bufpool.free(pBuf);
        return true;
}

bool
epManager::sendtoUser(const int fd, Buf* pBuf) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();
        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        SINGLE->sendqueue.enqueue(pBuf);
                        return true;
                }
        }
        return false;
}

void
epManager::dumpClassroom(void) {
        EPCLASSROOM_MAP::iterator it = classroomMap_.begin();
        EPCLASSROOM_MAP::const_iterator cie = classroomMap_.end();

        for (; cie!=it; ++it) {
                (it->second).dump();
        }
}

void
epManager::dumpUser(void) {
        EPUSER_MAP::iterator it = userMap_.begin();
        EPUSER_MAP::const_iterator cie = userMap_.end();

        for (; cie!=it; ++it) {
                (it->second)->dump();
        }
}

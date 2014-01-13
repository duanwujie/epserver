#include "epGroup.h"
#include "../netdef.h" // for EPGROUP_INVALID_GROUP_ID
#include "../Single.h"

epGroup::epGroup(void) : id_(EPGROUP_INVALID_GROUP_ID) {
}

epGroup::~epGroup(void) {
}

bool
epGroup::setId(const int id) {
        id_ = id;
        return true;
}

bool
epGroup::insertStudent(int fd, const epStudent& student) {
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();

        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        return false;
                }
        }

        studentMap_.insert(std::make_pair<int, epStudent>(fd, student));
        return true;
}

bool
epGroup::removeStudentByFd(const int fd) {
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();

        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        studentMap_.erase(it);
                        return true;
                }
        }
        return false;
}

int
epGroup::getId(void) const {
        return id_;
}

const epStudent*
epGroup::getStudentByFd(const int fd) {
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();

        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        return &(it->second);
                }
        }
        return false;
}

bool
epGroup::sendtoAllStudent(Buf* pBuf) {
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();
        Buf* p = NULL;
        for (; cie!=it; ++it) {
                p = SINGLE->bufpool.malloc();
                p = pBuf;
                p->setfd(it->first);
                SINGLE->sendqueue.enqueue(p);
        }

        SINGLE->bufpool.free(pBuf);
        return true;
}

bool
epGroup::sendtoStudentByFd(const int fd, Buf* pBuf) {
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();
        for (; cie!=it; ++it) {
                if (fd == it->first) {
                        SINGLE->sendqueue.enqueue(pBuf);
                        return true;
                }
        }

        return false;
}

void
epGroup::dump(void) {
        printf("group id = %d\n", id_);
        printf("for student :\n");
        STUDENT_MAP::iterator it = studentMap_.begin();
        STUDENT_MAP::const_iterator cie = studentMap_.end();
        for (; cie!=it; ++it) {
                (it->second).dump();
        }
}

#include "epClassroom.h"
#include "../Single.h"
#include "../netdef.h" // for EPCLASSROOM_INVALID_CLASSROOM_ID

epClassroom::epClassroom(const int classroom_id=EPCLASSROOM_INVALID_CLASSROOM_ID) : id_(classroom_id) {
}

epClassroom::~epClassroom(void) {
}

const int
epClassroom::getId(void) const {
        return id_;
}

epStudent*
epClassroom::getStudentById(const int id) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();

        epStudent* pStudent = NULL;
        for (; cie!=it; ++it) {
                pStudent = (it->second).getStudentById(id);
                if (NULL != pStudent) {
                        return pStudent;
                }
        }

        return NULL;
}

epTeacher&
epClassroom::getTeacher(void) {
        return teacher_;
}

const epWhiteBoard
epClassroom::getWhiteBoard(void) const {
        return whiteboard_;
}

std::string
epClassroom::getCourseList(void) const {
        return courseList_;
}

bool
epClassroom::setId(const int id) {
        id_ = id;
        return true;
}

bool
epClassroom::setTeacher(const epTeacher& teacher) {
        teacher_ = teacher;
        return true;
}

bool
epClassroom::setWhiteBoard(const epWhiteBoard& whiteboard) {
        whiteboard_ = whiteboard;
        return true;
}

bool
epClassroom::setCourseList(const std::string& courseList) {
        courseList_ = courseList;
        return true;
}

bool
epClassroom::sendtoAllClass(Buf* pBuf) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        Buf* p = NULL;
        for (; cie!=it; ++it) {
                p = pBuf;
                (it->second).sendtoAllStudent(p);
        }

        SINGLE->bufpool.free(pBuf);
        return true;
}

bool
epClassroom::sendtoClassById(const int id, Buf* pBuf) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        (it->second).sendtoAllStudent(pBuf);
                        return true;
                }
        }

        return false;
}

bool
epClassroom::sendtoAllGroup(Buf* pBuf) {
        EPGROUP_MAP::iterator it = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie = groupMap_.end();
        Buf* p = NULL;
        for (; cie!=it; ++it) {
                p = pBuf;
                (it->second).sendtoAllStudent(p);
        }

        SINGLE->bufpool.free(pBuf);
        return true;
}

bool
epClassroom::sendtoGroupById(const int id, Buf* pBuf) {
        EPGROUP_MAP::iterator it = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie = groupMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        (it->second).sendtoAllStudent(pBuf);
                        return true;
                }
        }

        return false;
}

bool
epClassroom::sendtoTeacher(Buf* pBuf) {
        pBuf->setfd(teacher_.getFd());
        SINGLE->sendqueue.enqueue(pBuf);
        return true;
}

bool
epClassroom::sendtoWhiteBoard(Buf* pBuf) {
        pBuf->setfd(whiteboard_.getFd());
        SINGLE->sendqueue.enqueue(pBuf);
        return true;
}

bool
epClassroom::insertClass(epClass& obj) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                if (obj.getId() == it->first) {
                        return false;
                }
        }

        classMap_.insert(std::make_pair<int, epClass>(obj.getId(), obj));
        return true;
}

bool
epClassroom::removeClassById(const int id) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        classMap_.erase(it);
                        return true;
                }
        }
        return false;
}

epClass*
epClassroom::getClassById(const int id) {
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        return &(it->second);
                }
        }
        return NULL;
}

std::vector<epClass*>
epClassroom::getClassList(void) {
        std::vector<epClass*> vc;
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                vc.push_back(&(it->second));
        }
        return vc;
}

bool
epClassroom::insertGroup(const epGroup& obj) {
        EPGROUP_MAP::iterator it = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie = groupMap_.end();
        for (; cie!=it; ++it) {
                if (obj.getId() == it->first) {
                        return false;
                }
        }

        groupMap_.insert(std::make_pair<int, epGroup>(obj.getId(), obj));
        return true;
}

bool
epClassroom::removeGroupById(const int id) {
        EPGROUP_MAP::iterator it = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie = groupMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        groupMap_.erase(it);
                        return true;
                }
        }
        return false;
}

epGroup*
epClassroom::getGroupById(const int id) {
        EPGROUP_MAP::iterator it = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie = groupMap_.end();
        for (; cie!=it; ++it) {
                if (id == it->first) {
                        return &(it->second);
                }
        }
        return NULL;
}

void
epClassroom::dump(void) {
        printf("class room id = %d\n", id_);
        printf("for class :\n");
        EPCLASS_MAP::iterator it = classMap_.begin();
        EPCLASS_MAP::const_iterator cie = classMap_.end();
        for (; cie!=it; ++it) {
                (it->second).dump();
        }

        printf("for group :\n");
        EPGROUP_MAP::iterator it_g = groupMap_.begin();
        EPGROUP_MAP::const_iterator cie_g = groupMap_.end();
        for (; cie_g!=it_g; ++it_g) {
                (it_g->second).dump();
        }

        printf("for teacher :\n");
        teacher_.dump();

        printf("for whiteboard_ :\n");
        whiteboard_.dump();
}

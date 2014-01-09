#ifndef __EPMANAGER_H__
#define __EPMANAGER_H__

#include <map>

#include "Uncopyable.h"
#include "epClassroom.h"

typedef std::map<int, epClassroom> EPCLASSROOM_MAP;

class epManager : public Uncopyable {
public :
        static epManager* instance(void);

private :
        static epManager* p_;
        epManager(void);
        ~epManager(void);

private :
        EPCLASSROOM_MAP classroomMap_;

        bool insertClassroom(const epClassroom&);
        bool deleteClassroomById(int);
        const epClassroom& getClassroomById(int);
};

#define EPMANAGER       (epManager::instance())

#endif // __EPMANAGER_H__

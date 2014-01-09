#ifndef __EPCLASSROOM_H__
#define __EPCLASSROOM_H__

#include <map>

#include "epClass.h"
#include "epTeacher.h"

typedef std::map<int, epClass> EPCLASS_MAP;

class epClassroom {
public :
        bool insertClass(const epClass&);
        bool deleteClassById(int);
        const epClass& getClassById(int);

private :
        EPCLASS_MAP classMap_;
        epTeacher teacher;
};

#endif // __EPCLASSROOM_H__

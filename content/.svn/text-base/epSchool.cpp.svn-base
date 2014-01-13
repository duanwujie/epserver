#include <stdio.h> // for printf
#include "epSchool.h"

epSchool::epSchool(void) {
}

epSchool::~epSchool(void) {
}

int
epSchool::getSchoolId(void) const {
		  return id_;
}

const std::string
epSchool::getSchoolName(void) const {
		  return schoolName_;
}

const std::string
epSchool::getNative(void) const {
		  return native_;
}

bool
epSchool::setSchoolId(const int id) {
		  id_ = id;
		  return true;
}

bool
epSchool::setSchoolName(const std::string& schoolname) {
		  schoolName_ = schoolname;
		  return true;
}

bool
epSchool::setSchoolNative(const std::string& native) {
		  native_ = native;
		  return true;
}

void
epSchool::dump(void) const {
        printf("school id     = %d\n", id_);
        printf("school name   = %s\n", schoolName_.c_str());
        printf("school native = %s\n", native_.c_str());
}

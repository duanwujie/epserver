#include <stdio.h> // for printf
#include "epWhiteBoard.h"

epWhiteBoard::epWhiteBoard (void) {
}

epWhiteBoard::~epWhiteBoard(void) {
}

bool
epWhiteBoard::setWhiteboardNum(const std::string& whiteboardNum) {
        whiteboardNum_ = whiteboardNum;
	return true;
}

bool
epWhiteBoard::setClassroomName(const std::string& classroomName) {
        classroomName_ = classroomName;
        return true;
}

bool
epWhiteBoard::setClassroomId(const int classroomId) {
        classroomId_ = classroomId;
        return true;
}

bool
epWhiteBoard::init(const std::string& account, const std::string& passwd) {
        epUser::init(account, passwd);
        // TODO :
        return true;
}

std::string
epWhiteBoard::getWhiteboardNum(void) const {
		return whiteboardNum_;
}

enum LoginType
epWhiteBoard::getType(void) const {
        return LT_WHITEBOARD;
}

std::string
epWhiteBoard::getClassroomName(void) const {
        return classroomName_;
}

int
epWhiteBoard::getClassroomId(void) const {
        return classroomId_;
}

void
epWhiteBoard::dump(void) {
        epUser::dump();
        printf("whileboard number = %s\n", whiteboardNum_.c_str());
}

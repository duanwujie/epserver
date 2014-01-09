#include "epManager.h"
#include <iostream>

epManager* epManager::p_ = NULL;

epManager* epManager::instance(void) {
        if (NULL == p_) {
                p_ = new epManager();
        }

        return p_;
}

epManager::epManager(void) {}

epManager::~epManager(void) {}

bool
epManager::insertClassroom(const epClassroom& obj) {
        return true;
}

bool
epManager::deleteClassroomById(int id) {
        return true;
}

/*
const epClassroom&
epManager::getClassroomById(int id) {
        return epClassroom();
}
*/

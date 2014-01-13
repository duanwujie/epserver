#include "epPerson.h"
#include <stdio.h> // for printf
#include "../netdef.h"

epPerson::epPerson (void) : age_(EPPERSON_INVALID_PERSON_AGE) {
}

epPerson::~epPerson(void) {
}

bool epPerson::setName(const std::string& name) {
        return true;
}

bool epPerson::setName(const std::string& firstName
                , const std::string& lastName) {
        firstName_ = firstName;
        lastName_ = lastName;

        return true;
}

bool epPerson::setSex(const std::string& sex) {
        sex_ = sex;
        return true;
}

bool epPerson::setAge(const int age) {
        age_ = age;
        return true;
}

bool epPerson::setRace(const std::string& race) {
        race_ = race;
        return true;
}

bool epPerson::setBirthday(const std::string& str) {
		  birthday_ = str;
        return true;
}

bool epPerson::setNative(const std::string& nat) {
		  native_ = nat;
        return true;
}

const std::string epPerson::getName(void) const {
        return firstName_ + lastName_;
}

const std::string& epPerson::getFirstname(void) const {
        return firstName_;
}

const std::string& epPerson::getSex(void) const {
        return sex_;
}

int epPerson::getAge(void) const {
        return age_;
}

const std::string& epPerson::getRace(void) const {
        return race_;
}

const std::string& epPerson::getBirthday(void) const {
        return birthday_;
}

const std::string& epPerson::getNative(void) const {
        return native_;
}

void
epPerson::dump(void) {
        printf("name     = %s\n", (firstName_ + lastName_).c_str());
        printf("sex      = %s\n", sex_.c_str());
        printf("age      = %d\n", age_);
        printf("race     = %s\n", race_.c_str());
        printf("birthday = %s\n", birthday_.c_str());
        printf("native   = %s\n", native_.c_str());
}

#ifndef __EPPERSON_H__
#define __EPPERSON_H__

#include <iostream>

class epPerson {
public :
        epPerson (void) : age_() {}
        ~epPerson(void) {}

        /**
         * @name set
         * @{ */
        bool setName     (const std::string&);
        bool setSex      (const std::string&);
        bool setAge      (const int);
        bool setRace     (const std::string&);
        bool setBirthday (const std::string&);
        bool setNative   (const std::string&);
        /**  @} */

        /**
         * @name get
         * @{ */
        const std::string& getName     (void) const;
        const std::string& getSex      (void) const;
        int                getAge      (void) const;
        const std::string& getRace     (void) const;
        const std::string& getBirthday (void) const;
        const std::string& getNative   (void) const;
        /**  @} */

        /**
         * @name get by ???
         * @{ */
        /**  @} */


private :
        std::string firstName_;
        std::string lastName_;
        std::string sex_;
        int         age_;
        std::string race_;
        std::string birthday_;
        std::string native_;
};

#endif // __EPPERSON_H__

/**
* @file AuthTask.cpp
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#include "AuthTask.h"
#include "confirm.hpp"

/**
* @brief 
*/
AuthTask::AuthTask ()
{
    m_oldtime = time (NULL);
}

/**
* @brief 
*/
AuthTask::~AuthTask ()
{
}

/**
* @brief 
*
* @return 
*/
int AuthTask::work ()
{
    while (true)
    {
        time_t now_time = time (NULL);
        if ((now_time - m_oldtime) > INTERVAL_TIME)
        {
            m_oldtime = now_time;
            if (Confirm().confirm())
#ifdef ___DEBUG
                cout << "auth success" << endl;
#endif
            ;
            else {
                cout << "authorize failed" << endl;
                exit (1);
            }
        }
        sleep (10);
    }

    return (0);
}

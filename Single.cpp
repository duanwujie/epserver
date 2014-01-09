/**
* @file Single.cpp
* @brief 全局单例实现
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#include "Single.h"

Single* Single::p_ = NULL;
/**
* @brief 
*/
Single* Single::instance() 
{
    if (NULL == p_) {
        p_ = new Single(); 
    }
    return p_;
}

/**
* @brief 
*/
Single::Single()
{
}
    
/**
* @brief 
*/
Single::~Single()
{
}

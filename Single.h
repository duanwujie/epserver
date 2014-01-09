/**
* @file Single.h
* @brief 全局单例
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
* @ingroup framework
*/

#ifndef _GLOBAL_DATA_H_
#define _GLOBAL_DATA_H_

#include <stdio.h>
#include "AtomicT.h"
#include "QueueT.h"
#include "PoolT.h"
#include "Buf.h"

/**
 * @class Single
 * @brief 全局单例类
 */
class Single 
{
    public:
        ~Single();
        static class Single* instance();
        /**接收队列*/
        QueueT<Buf*> recvqueue;
        /**发送队列*/
        QueueT<Buf*> sendqueue;
        /**buf池*/
        PoolT<Buf> bufpool;

    private:
        Single();
        static class Single* p_;
};

#define SINGLE Single::instance()

///@}
#endif

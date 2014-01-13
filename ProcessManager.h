/**
* @file ProcessManager.h
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
* @ingroup framework
* @{
*/

#ifndef _PROCESSMAMAGER_H_
#define _PROCESSMAMAGER_H_

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <sys/file.h>

#include "glog/logging.h"

#include "ThreadPool.h"
#include "task.h"
#include "RecvTask.h"
#include "SendTask.h"
#include "Evloop.h"
#include "Buf.h"

#include "HandleMessage.h"

#include "AuthTask.h"

#define CONFIGFILE "./config.lua"

enum
{
    LOCK_WAIT   = LOCK_EX,            /**<阻塞锁*/
    LOCK_NOWAIT = LOCK_EX | LOCK_NB,  /**<非阻塞锁*/
    UNLOCK      = LOCK_UN             /**<解锁*/
};

/**
 * @class   ProcessManager
 * @brief   管理类
 */
class ProcessManager
{
    public:
        ProcessManager ();
        ~ProcessManager ();
        /**
         * @brief 启动逻辑
         * @param argc 参数个数
         * @param argv 参数数组指针
         */
        int process_logic (int argc, char** argv);

        /**
         * @brief 主循环
         */
        int run ();


        /**
         * @brief 使用提示
         */
        void Usage();

        /**
         * @brief 信号处理函数
         * @param signo 信号
         */
        static void sig_term (int signo);


        /**
         * @brief 信号处理函数
         *
         * @param signo
         */
        static void sig_int (int signo);

    private:
        /**
         * @brief 文件锁
         * @param mode 加锁方式
         */
        bool lock (int mode);
        ThreadPool* m_thrpool;   /**线程池*/
        int m_lockfd;            /**文件锁句柄*/
};

#endif
///@}

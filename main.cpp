/**
* @file main.cpp
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

/**
 * @ingroup framework
 * @{
 */

#include <stdio.h>
#include "ThreadPool.h"
#include "AtomicT.h"
#include "PoolT.h"
#include "Buf.h"

#include "ProcessManager.h"

/**
* @brief 
*
* @param argc
* @param argv[]
*
* @return 
*/
int main (int argc, char* argv[])
{
    ProcessManager* process = NULL;

    if ((process = new ProcessManager ()) == NULL)
    {
        cout << "ERROR: ProcessManager is NULL" << endl;
        abort ();
    }

    process->process_logic (argc, argv);

    delete process;
    return 0;
}
///@}

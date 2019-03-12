


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

#include "TTC_Schedular.h"
#include "Tasks/Tasks.h"





void main ()
{


     Tasks_init();

     Task task1,task2;


     task1.pointer=Debouncing_Task;
     task1.Periodicity=5;
     task1.Remain=5;
     task1.Priority=2;

     task2.pointer=K2T;
     task2.Periodicity=30;
     task2.Remain=30;
     task2.Priority=FIRST_PRIORITY;



   scheduler_Add_Task(&task1);

   scheduler_Add_Task(&task2);



   OS_scheduler_Init ();

   OS_scheduler_Start();

}



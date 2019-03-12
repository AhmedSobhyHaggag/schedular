/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:28:42 PM
 *  Author: AVE-LAP-032
 */ 
#include "Tasks/Tasks.h"
#include "driverlib/sysctl.h"

/************************************************************************/
/* FUNCTION NAME: Tasks_init                                            */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of uart and keypad              */
/************************************************************************/
void Tasks_init(void)
{
    Keypad_init(); /*initialization of keypad*/
    UART0_INIT();  /*initialization of uart0*/
}


/************************************************************************/
/* FUNCTION NAME: Debouncing_Task                                       */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of uart and keypad              */
/************************************************************************/
void Debouncing_Task(void)
{

    static uint8_t count_num=0,x=0;

    x=Keypad_getPressedKey();
    if(x)
    {
        count_num++;
        if(count_num>=4)
        {
            flag=1;
            count_num=0;
        }
    }
    else
    {
        count_num=0;
        flag=0;
    }

}

void K2T(void)
{
    uint8_t num =0;

    if(get_keypad_flag())
    {
        flag=0;
        num=Keypad_getPressedKey();
        UARTCharPut(UART0_BASE,num+ZeroAscii); /* transmiter */


    }
}


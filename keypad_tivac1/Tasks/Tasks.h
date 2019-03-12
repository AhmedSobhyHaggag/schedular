/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:28:25 PM
 *  Author: AVE-LAP-032
 */ 


#ifndef TASKS_H_
#define TASKS_H_


#include "BitwiseOperations.h"
#include "Timer.h"

#include "Keypad_FILE/Keypad.h"
#include "UART_FILE/UART.h"



#define MAX_NO_OF_TASKS 3

/************************************************************************/
/* FUNCTION NAME: Tasks_init                                            */
/* @Param: void                                                         */
/* return: void                                                         */
/* FUNCTION Description: Initialization of uart and keypad              */
/************************************************************************/
void Tasks_init(void);

void Debouncing_Task(void);
void K2T(void);

#endif /* TASKS_H_ */

/*
 * Debouncing_task.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-025
 */

#ifndef DEBOUNCING_TASK_H_
#define DEBOUNCING_TASK_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"


extern uint8_t flag;

#define ZERO                            0
#define ONE                             1
#define TWO                             2
#define THREE                           3
#define FOUR                            4
#define FIVE                            5
#define SIX                             6
#define SEVEN                           7
#define EIGHT                           8
#define NINE                            9
#define TEN                             10
#define ELEVEN                          11
#define TWELVE                          12
#define THIRTEEN                        13
#define FOURTEEN                        14
#define FIFTEEN                         15
#define SIXTEEN                         16


#define C0 GPIO_PIN_7 /*names of column*/
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_5

#define R0 GPIO_PIN_2/*names of row*/
#define R1 GPIO_PIN_3
#define R2 GPIO_PIN_6

#define no_col 3
#define no_row 3

void Keypad_init();
uint8_t Keypad_getPressedKey();
uint8_t get_keypad_flag();


#endif /* DEBOUNCING_TASK_H_ */

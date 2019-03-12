/*
 * Debouncing_task.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-025
 */

#include "Keypad_FILE/Keypad.h"

uint8_t flag=0;


void Keypad_init()
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
     while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    /*determine direction of bin*/
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,C0|C1);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,C2);/*output*/

    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,R0|R1|R2);/*input*/

    GPIOPinWrite(GPIO_PORTD_BASE,C0|C1,C0|C1);/*OUTPUT on pin 1*/
    GPIOPinWrite(GPIO_PORTA_BASE,C2,C2);
    /*pull up*/
    GPIOPadConfigSet(GPIO_PORTB_BASE,R0|R1|R2,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
}

uint8_t Keypad_getPressedKey()
{
    uint8_t row[no_row]={R0,R1,R2};
    uint8_t col[no_col]={C0,C1,C2};
    uint8_t i,j;
    uint8_t val =ZERO;
    for(i=0;i<no_col;i++)/*check Rows and column */
    {
        /*set all pin*/
        GPIOPinWrite(GPIO_PORTD_BASE,col[0]|col[1],col[0]|col[1]);
        GPIOPinWrite(GPIO_PORTA_BASE,col[2],col[2]);

        if(i>=0 && i<=1)
        GPIOPinWrite(GPIO_PORTD_BASE,col[i],0);/*reset one pin only*/
        else
        GPIOPinWrite(GPIO_PORTA_BASE,col[2],0);

        for (j=0;j<no_row;j++)
        {
            if(!GPIOPinRead (GPIO_PORTB_BASE,row[j]))
            {

                //while(!GPIOPinRead (GPIO_PORTB_BASE,row[j]));
                switch(i)
                {
                    case ZERO:
                        if(j==ZERO){
                            val= ONE;

                        }
                        else if (j==ONE)
                        {
                            val= FOUR;
                        }
                        else if (j==TWO)
                        {
                            val= SEVEN;
                        }
                        break;
                    case 1:
                        if(j==ZERO){
                            val= TWO;
                        }
                        else if (j==ONE)
                        {
                            val= FIVE;
                        }
                        else if (j==TWO)
                        {
                            val= EIGHT;
                        }
                        break;
                    case 2:
                        if(j==ZERO){
                            val= THREE;
                        }
                        else if (j==ONE)
                        {
                            val= SIX;
                        }
                        else if (j==TWO)
                        {
                            val= NINE;
                        }
                        break;
                }
            }
        }
    }
    return val;

}



uint8_t get_keypad_flag()
{
    return flag;
}



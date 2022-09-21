/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
// each interrupt has a number/index to use in case of enabling/disabling the Interrupt
// includes all exceptions/faults with the same order in Vector Table

GGPIO_Port_A 		= 		0		,
GPIO_PORT_B 		= 		1		,
GPIO_PORT_C 		= 		2		,    	
GPIO_PORT_D 		= 		3		,     			
GPIO_PORT_E 		= 		4		,   
GPIO_PORT_F         =       30      ,

UART_0              =   	5		,
UART_1              =       6       ,
UART_2              =       33      ,
UART_3              =       59      ,
UART_4              =       60      ,
UART_5              =       61      ,
UART_6              =       62      ,
UART_7              =       63      ,

SSI0                =       7       ,
SSI1                =       34      ,
SSI2                =       57      ,
SSI3                =       58      ,


I2C_0               =       8       ,
I2C_1               =       37      ,
I2C_2               =       68      ,
I2C_3               =       69      ,


PWM_0_Fault         =       9       ,
PWM_0_Gen0          =       10      ,
PWM_0_Gen1          =       11      ,
PWM_0_Gen2          =       12      ,
PWM_0_Gen3          =       45      ,
PWM_1_Fault         =       138     ,
PWM_1_Gen0          =       134     ,
PWM_1_Gen1          =       135     ,
PWM_1_Gen2          =       136     ,
PWM_1_Gen3          =       137     ,

QEI0                =       13      ,
QEI1                =       38      ,

ADC_0_Seq0          =       14      ,
ADC_0_Seq1          =       15      ,
ADC_0_Seq2          =       16      ,
ADC_0_Seq3          =       17      ,
ADC_1_Seq0          =       48      ,
ADC_1_Seq1          =       49      ,
ADC_1_Seq2          =       50      ,
ADC_1_Seq3          =       51      ,

WDT_0_1             =       18      ,
Timer_0A_16_32B     =       19      ,
Timer_0B_16_32B     =       20      ,
Timer_1A_16_32B     =       21      ,
Timer_1B_16_32B     =       22      ,
Timer_2A_16_32B     =       23      ,
Timer_2B_16_32B     =       24      ,
Timer_3A_16_32B     =       35      ,
Timer_3B_16_32B     =       36      ,
Timer_4A_16_32B     =       70      ,
Timer_4B_16_32B     =       71      ,
Timer_5A_16_32B     =       92      ,
Timer_5B_16_32B     =       93      ,

Timer_0A_32_64B     =       94      ,
Timer_0B_32_64B     =       95      ,
Timer_1A_32_64B     =       96      ,
Timer_1B_32_64B     =       97      ,
Timer_2A_32_64B     =       98      ,
Timer_2B_32_64B     =       99      ,
Timer_3A_32_64B     =       100     ,
Timer_3B_32_64B     =       101     ,
Timer_4A_32_64B     =       102     ,
Timer_4B_32_64B     =       103     ,
Timer_5A_32_64B     =       104     ,
Timer_5B_32_64B     =       105     ,



Analog_Comparator_0 =       25      ,
Analog_Comparator_1 =       26      ,

Sys_Ctrl            =       28      ,
Flash_EEPROM_Mem    =       29      ,

CAN_0               =       39      ,
CAN_1               =       40      ,

Hiber_Modu          =       43      ,
USB                 =       44      ,

uDMA_SW             =       46      ,
uDMA_Err            =       47      ,

}IntCtrl_InterruptType;


typedef enum
 {	
	 GPIO_PORTA    = 0    ,
	 GPIO_PORTB     			,
	 GPIO_PORTC     			,
	 GPIO_PORTD     			,
	 GPIO_PORTE     			,
	 
	UART0         			  ,
	UART1     
	 
 }IRQ_Type ;
 
typedef struct{
	IRQ_Type	       		    IRQn;
	uint8					    Group_Pr;
	uint8					    SubGroup_Pr;
	uint8						State;   //enable-disable
}IRQ_CfgType;


 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

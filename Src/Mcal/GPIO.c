/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  General Purpose Port Driver
 *
 *      \details  The Driver Configure MCU Ports 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init( const Port_ConfigType* ConfigPtr)                                     
* \Description     : Initialize & Configure GPIO Ports                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pointer to Structure (ConfigPtr)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr)
{

	switch (ConfigPtr->PortNo)
	{
		case PORT_A: //1.Enable Port_A Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_A = 	0x01  ;
					//GPIO_CLK_GATE = (uint32)0x0001 ;
					switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P0 = 0;
						else (GPIODIR_PortA).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P1 = 0;
						else (GPIODIR_PortA).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P2 = 0;
						else (GPIODIR_PortA).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P3 = 0;
						else (GPIODIR_PortA).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P4 = 0;
						else (GPIODIR_PortA).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P5 = 0;
						else (GPIODIR_PortA).PIN.P5 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P5 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC5 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P5 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P5 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P5 = 1;
						break;
							//------------------------------------------------//
					case PIN6://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P6 = 0;
						else (GPIODIR_PortA).PIN.P6 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P6 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC6 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P6 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P6 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P6 = 1;
						break;
							//------------------------------------------------//
					case PIN7://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortA).PIN.P7 = 0;
						else (GPIODIR_PortA).PIN.P7 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortA).PIN.P7 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortA).PMC.PMC7 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortA).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortA).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortA).PIN.P7 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortA).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortA).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortA).PIN.P7 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortA).PIN.P7 = 1;
						break;
							//------------------------------------------------//		
					}
					break;
//PORT_B					
		case PORT_B: //1.Enable Port_B Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_B = 	0x01  ; 
					switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P0 = 0;
						else (GPIODIR_PortB).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P1 = 0;
						else (GPIODIR_PortB).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P2 = 0;
						else (GPIODIR_PortB).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P3 = 0;
						else (GPIODIR_PortB).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P4 = 0;
						else (GPIODIR_PortB).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P5 = 0;
						else (GPIODIR_PortB).PIN.P5 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P5 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC5 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P5 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P5 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P5 = 1;
						break;
							//------------------------------------------------//
					case PIN6://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P6 = 0;
						else (GPIODIR_PortB).PIN.P6 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P6 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC6 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P6 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P6 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P6 = 1;
						break;
							//------------------------------------------------//
					case PIN7://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortB).PIN.P7 = 0;
						else (GPIODIR_PortB).PIN.P7 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortB).PIN.P7 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortB).PMC.PMC7 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortB).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortB).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortB).PIN.P7 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortB).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortB).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortB).PIN.P7 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortB).PIN.P7 = 1;
						break;
							//------------------------------------------------//		
					}
					break;
//PORT_C					
		case PORT_C: //1.Enable Port_C Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_C = 	0x01  ; 
					switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P0 = 0;
						else (GPIODIR_PortC).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P1 = 0;
						else (GPIODIR_PortC).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P2 = 0;
						else (GPIODIR_PortC).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P3 = 0;
						else (GPIODIR_PortC).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P4 = 0;
						else (GPIODIR_PortC).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P5 = 0;
						else (GPIODIR_PortC).PIN.P5 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P5 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC5 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P5 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P5 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P5 = 1;
						break;
							//------------------------------------------------//
					case PIN6://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P6 = 0;
						else (GPIODIR_PortC).PIN.P6 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P6 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC6 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P6 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P6 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P6 = 1;
						break;
							//------------------------------------------------//
					case PIN7://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortC).PIN.P7 = 0;
						else (GPIODIR_PortC).PIN.P7 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortC).PIN.P7 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortC).PMC.PMC7 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortC).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortC).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortC).PIN.P7 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortC).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortC).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortC).PIN.P7 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortC).PIN.P7 = 1;
						break;
							//------------------------------------------------//		
					}
					break;	
//PORT_D					
		case PORT_D: //1.Enable Port_D Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_D = 	0x01  ; 
					switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P0 = 0;
						else (GPIODIR_PortD).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P1 = 0;
						else (GPIODIR_PortD).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P2 = 0;
						else (GPIODIR_PortD).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P3 = 0;
						else (GPIODIR_PortD).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P4 = 0;
						else (GPIODIR_PortD).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P5 = 0;
						else (GPIODIR_PortD).PIN.P5 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P5 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC5 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P5 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P5 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P5 = 1;
						break;
							//------------------------------------------------//
					case PIN6://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P6 = 0;
						else (GPIODIR_PortD).PIN.P6 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P6 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC6 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P6 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P6 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P6 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P6 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P6 = 1;
						break;
							//------------------------------------------------//
					case PIN7://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortD).PIN.P7 = 0;
						else (GPIODIR_PortD).PIN.P7 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortD).PIN.P7 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortD).PMC.PMC7 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortD).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortD).PIN.P7 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortD).PIN.P7 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortD).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortD).PIN.P7 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortD).PIN.P7 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortD).PIN.P7 = 1;
						break;
							//------------------------------------------------//		
					}
					break;
//PORT_E					
		case PORT_E: //1.Enable Port_E Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_E = 	0x01  ; 
					switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P0 = 0;
						else (GPIODIR_PortE).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P1 = 0;
						else (GPIODIR_PortE).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P2 = 0;
						else (GPIODIR_PortE).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P3 = 0;
						else (GPIODIR_PortE).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P4 = 0;
						else (GPIODIR_PortE).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortE).PIN.P5 = 0;
						else (GPIODIR_PortE).PIN.P5 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortE).PIN.P5 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortE).PMC.PMC5 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortE).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortE).PIN.P5 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortE).PIN.P5 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortE).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortE).PIN.P5 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortE).PIN.P5 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortE).PIN.P5 = 1;
						break;
							//------------------------------------------------//
					case PIN6: break;
							//------------------------------------------------//
					case PIN7: break;
							//------------------------------------------------//		
					}
					break;
//PORT_F					
		case PORT_F: //1.Enable Port_F Clock
					(GPIO_CLK_GATE).PORT_NO.PORT_F = 	0x01  ; 
						switch (ConfigPtr->PinNO)
					{
					case PIN0: //2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortF).PIN.P0 = 0;
						else (GPIODIR_PortF).PIN.P0 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortF).PIN.P0 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortF).PMC.PMC0 = 0x1; //example			
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortF).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortF).PIN.P0 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortF).PIN.P0 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortF).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortF).PIN.P0 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortF).PIN.P0 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortF).PIN.P0 = 1;
						break;	
							//------------------------------------------------//							
					case PIN1://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortF).PIN.P1 = 0;
						else (GPIODIR_PortF).PIN.P1 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortF).PIN.P1 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortF).PMC.PMC1 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortF).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortF).PIN.P1 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortF).PIN.P1 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortF).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortF).PIN.P1 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortF).PIN.P1 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortF).PIN.P1 = 1;
						break;
							//------------------------------------------------//							
					case PIN2://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortF).PIN.P2 = 0;
						else (GPIODIR_PortF).PIN.P2 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortF).PIN.P2 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortF).PMC.PMC2 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortF).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortF).PIN.P2 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortF).PIN.P2 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortF).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortF).PIN.P2 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortF).PIN.P2 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortF).PIN.P2 = 1;
						break;
							//------------------------------------------------//
					case PIN3://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortF).PIN.P3 = 0;
						else (GPIODIR_PortF).PIN.P3 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortF).PIN.P3 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortF).PMC.PMC3 = 1;
							}								
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortF).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortF).PIN.P3 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortF).PIN.P3 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortF).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortF).PIN.P3 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortF).PIN.P3 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortF).PIN.P3 = 1;
						break;
							//------------------------------------------------//
					case PIN4://2.Direction as 1 Output, 0 Input
						if(ConfigPtr->PinDirection==Input)(GPIODIR_PortF).PIN.P4 = 0;
						else (GPIODIR_PortF).PIN.P4 = 1;
									//3.Configure Alternative Func.
						if((ConfigPtr->PinMode != GPIO)&&(ConfigPtr->PinMode != DIO))
							{
								(GPIOAFSEL_PortF).PIN.P4 = 1;
								//GPIOPCTL CONFIGURATION - ALTERNATIVE FUNCTION
								(GPIOPCTL_PortF).PMC.PMC4 = 1;
							}
									//4.Driver Strength.
						if			(ConfigPtr->PinOC == _2mA) (GPIODR2R_PortF).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _4mA) (GPIODR4R_PortF).PIN.P4 = 1;
						else if (ConfigPtr->PinOC == _8mA) (GPIODR8R_PortF).PIN.P4 = 1;		
									//5.Pad Programming: Pull-Up, Pull_Down and Open_Drain.
						if			(ConfigPtr->PinAttach == PULL_UP) 	 (GPIOPUR_PortF).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == PULL_DOWN)  (GPIOPDR_PortF).PIN.P4 = 1;
						else if (ConfigPtr->PinAttach == OPEN_DRAIN) (GPIOODR_PortF).PIN.P4 = 1;
									//6.Enable/disable DIO
						if			(ConfigPtr->PinMode == DIO) 	 (GPIODEN_PortF).PIN.P4 = 1;
						break;
							//------------------------------------------------//
					case PIN5: break;
							//------------------------------------------------//
					case PIN6: break;
							//------------------------------------------------//
					case PIN7: break;
							//------------------------------------------------//		
					}
					break;
		default: break;
	}				
}



/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/


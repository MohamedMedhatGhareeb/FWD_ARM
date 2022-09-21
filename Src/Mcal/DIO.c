/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Digital Input Output Pins Driver
 *
 *      \details  The Driver Configure MCU Digital Input and output pins 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO.h"
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
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)                                      
* \Description     : Read from Selected Pin Channel and return its value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID                     
* \Parameters (out): None                                                      
* \Return value:   : Level of Selected Channel
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
{
	uint8 port = ChannelID/8;
	uint8 pin  = ChannelID%8;
	if (port ==0) //PORT_A
	{
		if(pin ==0) return (Dio_LevelType)(GPIODATA_PortA).PIN.P0;
		if(pin ==1) return (Dio_LevelType)(GPIODATA_PortA).PIN.P1;
		if(pin ==2) return (Dio_LevelType)(GPIODATA_PortA).PIN.P2;
		if(pin ==3) return (Dio_LevelType)(GPIODATA_PortA).PIN.P3;
		if(pin ==4) return (Dio_LevelType)(GPIODATA_PortA).PIN.P4;
		if(pin ==5) return (Dio_LevelType)(GPIODATA_PortA).PIN.P5;
		if(pin ==6) return (Dio_LevelType)(GPIODATA_PortA).PIN.P6;
		if(pin ==7) return (Dio_LevelType)(GPIODATA_PortA).PIN.P7;	
	}
	if (port ==1) //PORT_B
	{
		if(pin ==0) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P0;
		if(pin ==1) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P1;
		if(pin ==2) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P2;
		if(pin ==3) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P3;
		if(pin ==4) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P4;
		if(pin ==5) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P5;
		if(pin ==6) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P6;
		if(pin ==7) return  (Dio_LevelType)(GPIODATA_PortB).PIN.P7;	
	}
	if (port ==2) //PORT_C
	{
		if(pin ==0) return (Dio_LevelType)(GPIODATA_PortC).PIN.P0;
		if(pin ==1) return (Dio_LevelType)(GPIODATA_PortC).PIN.P1;
		if(pin ==2) return (Dio_LevelType)(GPIODATA_PortC).PIN.P2;
		if(pin ==3) return (Dio_LevelType)(GPIODATA_PortC).PIN.P3;
		if(pin ==4) return (Dio_LevelType)(GPIODATA_PortC).PIN.P4;
		if(pin ==5) return (Dio_LevelType)(GPIODATA_PortC).PIN.P5;
		if(pin ==6) return (Dio_LevelType)(GPIODATA_PortC).PIN.P6;
		if(pin ==7) return (Dio_LevelType)(GPIODATA_PortC).PIN.P7;
	}
	if (port ==3) //PORT_D
	{
		if(pin ==0) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P0;
		if(pin ==1) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P1;
		if(pin ==2) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P2;
		if(pin ==3) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P3;
		if(pin ==4) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P4;
		if(pin ==5) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P5;
		if(pin ==6) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P6;
		if(pin ==7) return  (Dio_LevelType)(GPIODATA_PortD).PIN.P7;
	}
	if (port ==4) //PORT_E
	{
		if(pin ==0) return (Dio_LevelType)(GPIODATA_PortE).PIN.P0;
		if(pin ==1) return (Dio_LevelType)(GPIODATA_PortE).PIN.P1;
		if(pin ==2) return (Dio_LevelType)(GPIODATA_PortE).PIN.P2;
		if(pin ==3) return (Dio_LevelType)(GPIODATA_PortE).PIN.P3;
		if(pin ==4) return (Dio_LevelType)(GPIODATA_PortE).PIN.P4;
		if(pin ==5) return (Dio_LevelType)(GPIODATA_PortE).PIN.P5;
	}
	if (port ==5) //PORT_F
	{
		if(pin ==0) return (Dio_LevelType)(GPIODATA_PortF).PIN.P0;
		if(pin ==1) return (Dio_LevelType)(GPIODATA_PortF).PIN.P1;
		if(pin ==2) return (Dio_LevelType)(GPIODATA_PortF).PIN.P2;
		if(pin ==3) return (Dio_LevelType)(GPIODATA_PortF).PIN.P3;
		if(pin ==4) return (Dio_LevelType)(GPIODATA_PortF).PIN.P4;
	}
	return (Dio_LevelType)0; //default
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)                                      
* \Description     : Write on Selected Pin Channel with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID , Level                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)
{
	uint8 port = ChannelID/8;
	uint8 pin  = ChannelID%8;
	if (port ==0) //PORT_A
	{
		if(pin ==0) (GPIODATA_PortA).PIN.P0 = Level;
		if(pin ==1) (GPIODATA_PortA).PIN.P1 = Level;
		if(pin ==2) (GPIODATA_PortA).PIN.P2 = Level;
		if(pin ==3) (GPIODATA_PortA).PIN.P3 = Level;
		if(pin ==4) (GPIODATA_PortA).PIN.P4 = Level;
		if(pin ==5) (GPIODATA_PortA).PIN.P5 = Level;
		if(pin ==6) (GPIODATA_PortA).PIN.P6 = Level;
		if(pin ==7) (GPIODATA_PortA).PIN.P7 = Level;	
	}
	if (port ==1) //PORT_B
	{
		if(pin ==0)  (GPIODATA_PortB).PIN.P0 = Level ;
		if(pin ==1)  (GPIODATA_PortB).PIN.P1 = Level ;
		if(pin ==2)  (GPIODATA_PortB).PIN.P2 = Level ;
		if(pin ==3)  (GPIODATA_PortB).PIN.P3 = Level ;
		if(pin ==4)  (GPIODATA_PortB).PIN.P4 = Level ;
		if(pin ==5)  (GPIODATA_PortB).PIN.P5 = Level ;
		if(pin ==6)  (GPIODATA_PortB).PIN.P6 = Level ;
		if(pin ==7)  (GPIODATA_PortB).PIN.P7 = Level ;	
	}
	if (port ==2) //PORT_C
	{
		if(pin ==0)  (GPIODATA_PortC).PIN.P0 = Level;
		if(pin ==1)  (GPIODATA_PortC).PIN.P1 = Level;
		if(pin ==2)  (GPIODATA_PortC).PIN.P2 = Level;
		if(pin ==3)  (GPIODATA_PortC).PIN.P3 = Level;
		if(pin ==4)  (GPIODATA_PortC).PIN.P4 = Level;
		if(pin ==5)  (GPIODATA_PortC).PIN.P5 = Level;
		if(pin ==6)  (GPIODATA_PortC).PIN.P6 = Level;
		if(pin ==7)  (GPIODATA_PortC).PIN.P7 = Level;
	}
	if (port ==3) //PORT_D
	{
		if(pin ==0)  (GPIODATA_PortD).PIN.P0 = Level;
		if(pin ==1)  (GPIODATA_PortD).PIN.P1 = Level;
		if(pin ==2)  (GPIODATA_PortD).PIN.P2 = Level;
		if(pin ==3)  (GPIODATA_PortD).PIN.P3 = Level;
		if(pin ==4)  (GPIODATA_PortD).PIN.P4 = Level;
		if(pin ==5)  (GPIODATA_PortD).PIN.P5 = Level;
		if(pin ==6)  (GPIODATA_PortD).PIN.P6 = Level;
		if(pin ==7)  (GPIODATA_PortD).PIN.P7 = Level;
	}
	if (port ==4) //PORT_E
	{
		if(pin ==0)  (GPIODATA_PortE).PIN.P0 = Level;
		if(pin ==1)  (GPIODATA_PortE).PIN.P1 = Level;
		if(pin ==2)  (GPIODATA_PortE).PIN.P2 = Level;
		if(pin ==3)  (GPIODATA_PortE).PIN.P3 = Level;
		if(pin ==4)  (GPIODATA_PortE).PIN.P4 = Level;
		if(pin ==5)  (GPIODATA_PortE).PIN.P5 = Level;
	}
	if (port ==5) //PORT_F
	{
		if(pin ==0)  (GPIODATA_PortF).PIN.P0 = Level;
		if(pin ==1)  (GPIODATA_PortF).PIN.P1 = Level;
		if(pin ==2)  (GPIODATA_PortF).PIN.P2 = Level;
		if(pin ==3)  (GPIODATA_PortF).PIN.P3 = Level;
		if(pin ==4)  (GPIODATA_PortF).PIN.P4 = Level;
	}
	
}
 
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)                                      
* \Description     : Read Selected Port and return its value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID                   
* \Parameters (out): None                                                      
* \Return value:   : value of selected Port
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)
{
	switch (PortID)
	{
		case PORT_A: return (GPIODATA_PortA).R;
		case PORT_B: return (GPIODATA_PortB).R;
		case PORT_C: return (GPIODATA_PortC).R;
		case PORT_D: return (GPIODATA_PortD).R;
		case PORT_E: return (GPIODATA_PortE).R;
		case PORT_F: return (GPIODATA_PortF).R;	
		default: return 0;
	}
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)                                      
* \Description     : Write on Selected Port with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID , Level                  
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)
{
	switch (PortID)
	{
		case PORT_A:  (GPIODATA_PortA).R = Level ;
		case PORT_B:  (GPIODATA_PortB).R = Level;
		case PORT_C:  (GPIODATA_PortC).R = Level;
		case PORT_D:  (GPIODATA_PortD).R = Level;
		case PORT_E:  (GPIODATA_PortE).R = Level;
		case PORT_F:  (GPIODATA_PortF).R = Level;	
		default: break;
	}
	
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)                                      
* \Description     : Write on Selected Port with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID , Level                  
* \Parameters (out): None                                                      
* \Return value:   : Current Level of Channel
*******************************************************************************/
Dio_LevelType	Dio_FlipChannel(Dio_ChannelType ChannelID)
{
	return (Dio_LevelType)0;
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/


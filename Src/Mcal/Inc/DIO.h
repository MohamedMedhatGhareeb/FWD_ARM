/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"

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
	 PA0    = 0   ,
	 PA1     			,
	 PA2     			,
	 PA3     			,
	 PA4     			,
	 PA5     			,
	 PA6     			,
	 PA7     			,
	 
	 PB0     			,
	 PB1     			,
	 PB2     			,
	 PB3     			,
	 PB4     			,
	 PB5     			,
	 PB6     			,
	 PB7     			,
	
	 PC0     			,
	 PC1     			,
	 PC2     			,
	 PC3     			,
	 PC4     			,
	 PC5     			,
	 PC6     			,
	 PC7     			,
	 
	 PD0     			,
	 PD1     			,
	 PD2     			,
	 PD3     			,
	 PD4     			,
	 PD5     			,
	 PD6     			,
	 PD7     			,
	 
	 PE0     			,
	 PE1     			,
	 PE2     			,
	 PE3     			,
	 PE4     			,
	 PE5     			,
	 
	 PF0     			,
	 PF1     			,
	 PF2     			,
	 PF3     			,
	 PF4     			
	 
 }Dio_ChannelType;

 typedef enum 
 {
	 PORT_A  = 0 	,
	 PORT_B  			,
	 PORT_C				,
	 PORT_D				,
	 PORT_E				,
	 PORT_F
 }Dio_PortType;
 
 typedef enum 
 {
	 Level_Low  = 0 	,
	 Level_High
 }Dio_LevelType;
 
typedef uint8 Dio_PortLevelType ;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
//extern const IRQ_CfgType IRQ_Cfg[NVIC_IQR_ACTIVE_NO] ;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID);

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level)                                      
* \Description     : Write on Selected Pin Channel with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID , Level                   
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level);
 
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)                                      
* \Description     : Read Selected Port and return its value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID                   
* \Parameters (out): None                                                      
* \Return value:   : value of selected Port
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID);

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)                                      
* \Description     : Write on Selected Port with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID , Level                  
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level);

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level)                                      
* \Description     : Write on Selected Port with input value                                                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID , Level                  
* \Parameters (out): None                                                      
* \Return value:   : Current Level of Channel
*******************************************************************************/
Dio_LevelType	Dio_FlipChannel(Dio_ChannelType ChannelID);

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  header file for GPT Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT_Cfg.h"
#include "GPT_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define System_CLock        16000000
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
//void (*ptr) (void) = NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Gpt_ConfigType Gpt_Config[GPT_ACTIVE_NO];
	
extern  CallBackFunc_Type GPT_Notification[3]; //pointers to callback functions
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void GPT_Init (const Gpt_ConfigType *ConfigPtr)                                    
* \Description     : Initialize & Configure GPT TIMERS                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pointer to Structure (ConfigPtr)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_Init (const Gpt_ConfigType *ConfigPtr);

/******************************************************************************
* \Syntax          : void GPT_DisableNotification (Gpt_ChannelType GPT_ChannelID)                                
* \Description     : Disable Interrupt on Timer with Channel ID GPT_ChannelID                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_DisableNotification (Gpt_ChannelType GPT_ChannelID);

/******************************************************************************
* \Syntax          : void GPT_EnableNotification (Gpt_ChannelType GPT_ChannelID)                                
* \Description     : Enable Interrupt on Timer with Channel ID GPT_ChannelID                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_EnableNotification (Gpt_ChannelType GPT_ChannelID);

/******************************************************************************
* \Syntax          : void GPT_StartTime (Gpt_ChannelType GPT_ChannelID,Gpt_ValueType Value)                               
* \Description     : Set a target Value (Value) and select a timer to start counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID) ,Gpt_ValueType (Value)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_StartTime (Gpt_ChannelType GPT_ChannelID,Gpt_ValueType Value);

/******************************************************************************
* \Syntax          : void GPT_StopTime (Gpt_ChannelType GPT_ChannelID)                               
* \Description     : Stop selected timer from counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_StopTime (Gpt_ChannelType GPT_ChannelID);

/******************************************************************************
* \Syntax          : void GPT_StopTime (Gpt_ChannelType GPT_ChannelID)                               
* \Description     : Stop selected timer from counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_Notification_TIM_0 (void);

/******************************************************************************
* \Syntax          : Gpt_ValueType GPT_GetTickElapsed (Gpt_ChannelType GPT_ChannelID)                              
* \Description     : return current count in timer register                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): Gpt_ValueType (Value)                                                      
* \Return value:   : uint32
*******************************************************************************/
Gpt_ValueType GPT_GetTickElapsed (Gpt_ChannelType GPT_ChannelID);

/******************************************************************************
* \Syntax          : Gpt_ValueType GPT_GetTickRemaining (Gpt_ChannelType GPT_ChannelID)                              
* \Description     : return remaining tick in timer count register till it reaches max value                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): Gpt_ValueType (Value)                                                      
* \Return value:   : uint32
*******************************************************************************/
Gpt_ValueType GPT_GetTickRemaining (Gpt_ChannelType GPT_ChannelID);

/******************************************************************************
* \Syntax          : void GPT_StopTime (Gpt_ChannelType GPT_ChannelID)                               
* \Description     : Stop selected timer from counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Std_ReturnType GPT_GetPredefTimerValue (Gpt_PredefTimerType PredefTimer, uint32* TimerValuePtr);

#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/

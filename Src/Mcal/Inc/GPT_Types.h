/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  GPT
 *
 *  Description:  Includes all Typedefs used in GPT Driver     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

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
  
typedef enum {
	TIM_0 =0,
	TIM_1   ,
	TIM_2   ,
	TIM_3   ,
	TIM_4   ,
	TIM_5   ,
	WTIM_0   ,
	WTIM_1   ,
	WTIM_2   ,
	WTIM_3   ,
	WTIM_4  ,
	WTIM_5  
}Gpt_ChannelType;

typedef uint32 Gpt_ValueType;
typedef uint32 Gpt_Callback_Func_Ptr_AddressType;
typedef void (*CallBackFunc_Type) (void);

typedef enum{
	GPT_MODE_NORMAL =0, //CONTINOUS MODE
	GPT_MODE_SLEEP			//ONE-SHOT MODE
}Gpt_ModeType;

typedef enum{
	GPT_COUNT_UP =0, 		
	GPT_COUNT_DOWN			
}Gpt_DirType;

typedef enum{
	DISABLE_NOTI =0, 
	ENABLE_NOTI			
}Gpt_Notification_StatusType;

typedef enum{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;


typedef struct{
	Gpt_ChannelType GptChannelID;
	uint32 GptChannelTickFreq;
	Gpt_ValueType GptChannelTickValueMax;
	Gpt_ModeType GPT_MODE;
	Gpt_DirType GPT_COUNT_DIR;
	//GptNotification
	//uint8 Notification_Enable;
	//Gpt_Callback_Func_Ptr_AddressType Gpt_Callback_Func_Adress;
	CallBackFunc_Type CallBackFunc_Type;
	
}Gpt_ConfigType;


 
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/

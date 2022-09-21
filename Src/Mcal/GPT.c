/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  General Purpose Timer Driver
 *
 *      \details  The Driver Configure MCU Timer 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
//static CallBackFunc_Type CallBackFunc_TIM_0= NULL_PTR;
//static CallBackFunc_Type CallBackFunc_TIM_1= NULL_PTR;
//static CallBackFunc_Type CallBackFunc_TIM_2= NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
//void GPT_callback_register(CallBackFunc_Type callback)
//{
//	CallBackFunc_TIM_0	= callback;
//}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void GPT_Init (const Gpt_ConfigType *ConfigPtr)                                     
* \Description     : Initialize & Configure General Purpose Timers                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pointer to Structure (ConfigPtr)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_Init (const Gpt_ConfigType *ConfigPtr)
{
	switch (ConfigPtr->GptChannelID)
	{
		case TIM_0: //1.Enable Timer_0 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_0 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_0).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_0).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_0).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_0).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_0).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_0).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case TIM_1: //1.Enable Timer_1 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_1 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_1).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_1).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_1).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_1).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_1).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_1).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case TIM_2: //1.Enable Timer_2 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_2 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_2).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_2).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_2).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_2).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_2).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_2).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case TIM_3: //1.Enable Timer_3 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_3 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_3).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_3).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_3).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_3).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_3).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_3).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case TIM_4: //1.Enable Timer_4 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_4 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_4).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_4).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_4).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_4).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_4).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_4).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case TIM_5: //1.Enable Timer_5 Clock
					(RCGCTIMER_CLK_GATE).TIM_NO.TIM_5 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_TIMER_5).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_TIMER_5).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_TIMER_5).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_TIMER_5).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_TIMER_5).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_TIMER_5).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_0: //1.Enable Wide Timer_0 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_0 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_0).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_0).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_0).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_0).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_0).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_0).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_1: //1.Enable Wide Timer_1 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_1 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_1).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_1).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_1).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_1).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_1).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_1).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_2: //1.Enable Wide Timer_2 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_2 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_2).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_2).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_2).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_2).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_2).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_2).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_3: //1.Enable Wide Timer_3 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_3 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_3).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_3).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_3).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_3).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_3).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_3).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_4: //1.Enable Wide Timer_4 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_4 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_4).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_4).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_4).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_4).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_4).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_4).TnMR.TnCDIR = 	0x00  ;
				break;	
		
		case WTIM_5: //1.Enable Wide Timer_5 Clock
					(RCGCWTIMER_CLK_GATE).TIM_NO.TIM_5 = 	0x01  ;
					//2.Ensure timer is disabled
					(GPTMCTL_WTIMER_5).TIM_EN.TIM_EN = 	0x00  ;
					//3.Initialte GPTM Reg with a value of 0x00000000
					(GPTMCFG_WTIMER_5).R = 	0x00000000  ;
					//4.Configure Timer Mode
					if(ConfigPtr->GPT_MODE == GPT_MODE_SLEEP)  (GPTMTAMR_WTIMER_5).TnMR.TnMR = 	0x01  ;
					if(ConfigPtr->GPT_MODE == GPT_MODE_NORMAL) (GPTMTAMR_WTIMER_5).TnMR.TnMR = 	0x02  ;
					//5.Configure Count Direction
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_UP) 	 (GPTMTAMR_WTIMER_5).TnMR.TnCDIR = 	0x01  ;
					if(ConfigPtr->GPT_COUNT_DIR == GPT_COUNT_DOWN) (GPTMTAMR_WTIMER_5).TnMR.TnCDIR = 	0x00  ;
				break;	
			
	}
//	//Assigning User Callback Func
//	CallBackFunc_TIM_0 = ConfigPtr->UserCallBackFunc;
	
}

/******************************************************************************
* \Syntax          : void GPT_DisableNotification (Gpt_ChannelType GPT_ChannelID)                                
* \Description     : Disable Interrupt on Timer with Channel ID GPT_ChannelID                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_DisableNotification (Gpt_ChannelType GPT_ChannelID)
{
	switch (GPT_ChannelID)
	{
		case TIM_0: (GPTMIMR_TIMER_0).MIMR.TATOIM = 	0x00  ; break;
		case TIM_1: (GPTMIMR_TIMER_1).MIMR.TATOIM = 	0x00  ; break;
		case TIM_2: (GPTMIMR_TIMER_2).MIMR.TATOIM = 	0x00  ; break;
		case TIM_3: (GPTMIMR_TIMER_3).MIMR.TATOIM = 	0x00  ; break;
		case TIM_4: (GPTMIMR_TIMER_4).MIMR.TATOIM = 	0x00  ; break;
		case TIM_5: (GPTMIMR_TIMER_5).MIMR.TATOIM = 	0x00  ; break;
		
		case WTIM_0: (GPTMIMR_WTIMER_0).MIMR.TATOIM = 	0x00  ; break;
		case WTIM_1: (GPTMIMR_WTIMER_1).MIMR.TATOIM = 	0x00  ; break;
		case WTIM_2: (GPTMIMR_WTIMER_2).MIMR.TATOIM = 	0x00  ; break;
		case WTIM_3: (GPTMIMR_WTIMER_3).MIMR.TATOIM = 	0x00  ; break;
		case WTIM_4: (GPTMIMR_WTIMER_4).MIMR.TATOIM = 	0x00  ; break;
		case WTIM_5: (GPTMIMR_WTIMER_5).MIMR.TATOIM = 	0x00  ; break;
	}
}

/******************************************************************************
* \Syntax          : void GPT_EnableNotification (Gpt_ChannelType GPT_ChannelID)                                
* \Description     : Enable Interrupt on Timer with Channel ID GPT_ChannelID                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_EnableNotification (Gpt_ChannelType GPT_ChannelID)
{
	switch (GPT_ChannelID)
	{
		case TIM_0: (GPTMIMR_TIMER_0).MIMR.TATOIM = 	0x01  ; break;
		case TIM_1: (GPTMIMR_TIMER_1).MIMR.TATOIM = 	0x01  ; break;
		case TIM_2: (GPTMIMR_TIMER_2).MIMR.TATOIM = 	0x01  ; break;
		case TIM_3: (GPTMIMR_TIMER_3).MIMR.TATOIM = 	0x01  ; break;
		case TIM_4: (GPTMIMR_TIMER_4).MIMR.TATOIM = 	0x01  ; break;
		case TIM_5: (GPTMIMR_TIMER_5).MIMR.TATOIM = 	0x01  ; break;
		
		case WTIM_0: (GPTMIMR_WTIMER_0).MIMR.TATOIM = 	0x01  ; break;
		case WTIM_1: (GPTMIMR_WTIMER_1).MIMR.TATOIM = 	0x01  ; break;
		case WTIM_2: (GPTMIMR_WTIMER_2).MIMR.TATOIM = 	0x01  ; break;
		case WTIM_3: (GPTMIMR_WTIMER_3).MIMR.TATOIM = 	0x01  ; break;
		case WTIM_4: (GPTMIMR_WTIMER_4).MIMR.TATOIM = 	0x01  ; break;
		case WTIM_5: (GPTMIMR_WTIMER_5).MIMR.TATOIM = 	0x01  ; break;
	}
}

/******************************************************************************
* \Syntax          : void GPT_StartTime (Gpt_ChannelType GPT_ChannelID,Gpt_ValueType Value)                               
* \Description     : Set a target Value (Value) and select a timer to start counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID) ,Gpt_ValueType (Value)                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_StartTime (Gpt_ChannelType GPT_ChannelID,Gpt_ValueType Value)
{
	switch (GPT_ChannelID)
	{
		case TIM_0: 
				(GPTMTAILR_TIMER_0) = Value ;         		 //load value
				(GPTMCTL_TIMER_0).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case TIM_1: 
				(GPTMTAILR_TIMER_1) = Value ;         		 //load value
				(GPTMCTL_TIMER_1).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case TIM_2:  
				(GPTMTAILR_TIMER_2) = Value ;         		 //load value
				(GPTMCTL_TIMER_2).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case TIM_3:  
				(GPTMTAILR_TIMER_3) = Value ;         		 //load value
				(GPTMCTL_TIMER_3).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case TIM_4:  
				(GPTMTAILR_TIMER_4) = Value ;         		 //load value
				(GPTMCTL_TIMER_4).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case TIM_5:  
				(GPTMTAILR_TIMER_5) = Value ;         		 //load value
				(GPTMCTL_TIMER_5).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		
		case WTIM_0:  
				(GPTMTAILR_WTIMER_0) = Value ;         		 //load value
				(GPTMCTL_WTIMER_0).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case WTIM_1:  
				(GPTMTAILR_WTIMER_1) = Value ;         		 //load value
				(GPTMCTL_WTIMER_1).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case WTIM_2:  
				(GPTMTAILR_WTIMER_2) = Value ;         		 //load value
				(GPTMCTL_WTIMER_2).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case WTIM_3:  
				(GPTMTAILR_WTIMER_3) = Value ;         		 //load value
				(GPTMCTL_WTIMER_3).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case WTIM_4:  
				(GPTMTAILR_WTIMER_4) = Value ;         		 //load value
				(GPTMCTL_WTIMER_4).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
		case WTIM_5:  
				(GPTMTAILR_WTIMER_5) = Value ;         		 //load value
				(GPTMCTL_WTIMER_5).TIM_EN.TIM_EN = 	0x01  ;//Enable Timer 
				break;
	}
}

/******************************************************************************
* \Syntax          : void GPT_StopTime (Gpt_ChannelType GPT_ChannelID)                               
* \Description     : Stop selected timer from counting                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPT_StopTime (Gpt_ChannelType GPT_ChannelID)
{
	switch (GPT_ChannelID)
	{
		case TIM_0: (GPTMCTL_TIMER_0).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer 
		case TIM_1: (GPTMCTL_TIMER_1).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case TIM_2: (GPTMCTL_TIMER_2).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case TIM_3: (GPTMCTL_TIMER_3).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case TIM_4: (GPTMCTL_TIMER_4).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case TIM_5: (GPTMCTL_TIMER_5).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		
		case WTIM_0: (GPTMCTL_WTIMER_0).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case WTIM_1: (GPTMCTL_WTIMER_1).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case WTIM_2: (GPTMCTL_WTIMER_2).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case WTIM_3: (GPTMCTL_WTIMER_3).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case WTIM_4: (GPTMCTL_WTIMER_4).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
		case WTIM_5: (GPTMCTL_WTIMER_5).TIM_EN.TIM_EN = 	0x00  ;//Disable Timer
	}
}

/******************************************************************************
* \Syntax          : Gpt_ValueType GPT_GetTickElapsed (Gpt_ChannelType GPT_ChannelID)                              
* \Description     : return current count in timer register                                                                                                          
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): Gpt_ValueType (Value)                                                      
* \Return value:   : uint32
*******************************************************************************/
Gpt_ValueType GPT_GetTickElapsed (Gpt_ChannelType GPT_ChannelID)
{
	 switch (GPT_ChannelID)
	{
		case TIM_0: return GPTMTAV_TIMER_0  ; 
		case TIM_1: return GPTMTAV_TIMER_1  ; 
		case TIM_2: return GPTMTAV_TIMER_2  ; 
		case TIM_3: return GPTMTAV_TIMER_3  ; 
		case TIM_4: return GPTMTAV_TIMER_4  ; 
		case TIM_5: return GPTMTAV_TIMER_5  ; 
		
		case WTIM_0: return GPTMTAV_WTIMER_0  ; 
		case WTIM_1: return GPTMTAV_WTIMER_1  ; 
		case WTIM_2: return GPTMTAV_WTIMER_2  ; 
		case WTIM_3: return GPTMTAV_WTIMER_3  ; 
		case WTIM_4: return GPTMTAV_WTIMER_4  ; 
		case WTIM_5: return GPTMTAV_WTIMER_5  ; 
	}
	return 0;
}

/******************************************************************************
* \Syntax          : Gpt_ValueType GPT_GetTickRemaining (Gpt_ChannelType GPT_ChannelID)                              
* \Description     : return remaining tick in timer count register till it reaches max value                                                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType (GPT_ChannelID)                    
* \Parameters (out): Gpt_ValueType (Value)                                                      
* \Return value:   : uint32
*******************************************************************************/
Gpt_ValueType GPT_GetTickRemaining (Gpt_ChannelType GPT_ChannelID)
{
	 switch (GPT_ChannelID)
	{
		case TIM_0: return GPTMTAILR_TIMER_0-GPTMTAV_TIMER_0  ; 
		case TIM_1: return GPTMTAILR_TIMER_1-GPTMTAV_TIMER_1  ; 
		case TIM_2: return GPTMTAILR_TIMER_2-GPTMTAV_TIMER_2  ; 
		case TIM_3: return GPTMTAILR_TIMER_3-GPTMTAV_TIMER_3  ; 
		case TIM_4: return GPTMTAILR_TIMER_4-GPTMTAV_TIMER_4  ; 
		case TIM_5: return GPTMTAILR_TIMER_5-GPTMTAV_TIMER_5  ; 
		
		case WTIM_0: return GPTMTAILR_WTIMER_0-GPTMTAV_WTIMER_0  ; 
		case WTIM_1: return GPTMTAILR_WTIMER_1-GPTMTAV_WTIMER_1  ; 
		case WTIM_2: return GPTMTAILR_WTIMER_2-GPTMTAV_WTIMER_2  ; 
		case WTIM_3: return GPTMTAILR_WTIMER_3-GPTMTAV_WTIMER_3  ; 
		case WTIM_4: return GPTMTAILR_WTIMER_4-GPTMTAV_WTIMER_4  ; 
		case WTIM_5: return GPTMTAILR_WTIMER_5-GPTMTAV_WTIMER_5  ; 
	}
	return 0;
}



/******************************************************************************
* \Syntax          : ISRs                                     
* \Description     : Execute Call Back Functions in Interrupt Service Routine of Timer [0-1-2]                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void TIMER0A_Handler (void)
{
	GPT_Notification[0]();
	(GPTMICR_TIMER_0).MICR.TATOCINT = 0x01; // clear pending interrupt
}
void TIMER0B_Handler (void)
{
	GPT_Notification[0]();
	(GPTMICR_TIMER_0).MICR.TBTOCINT = 0x01; // clear pending interrupt
}

void TIMER1A_Handler (void)
{
	GPT_Notification[1]();
	(GPTMICR_TIMER_1).MICR.TATOCINT = 0x01; // clear pending interrupt
}
void TIMER1B_Handler (void)
{
	GPT_Notification[1]();
	(GPTMICR_TIMER_1).MICR.TBTOCINT = 0x01; // clear pending interrupt
}

void TIMER2A_Handler (void)
{
	GPT_Notification[2]();
	(GPTMICR_TIMER_2).MICR.TATOCINT = 0x01; // clear pending interrupt
}
void TIMER2B_Handler (void)
{
	GPT_Notification[2]();
	(GPTMICR_TIMER_2).MICR.TBTOCINT = 0x01; // clear pending interrupt
}
         

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/


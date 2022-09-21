/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Types.h
 *       Module:  GPIO
 *
 *  Description:  Includes all Typedefs used in GPIO Driver    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

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
	 PA0    = 0   ,
	 PA1     			,
	 PA2     			,
	 PA3     			,
	 PA4     			,
	 PA5     			,
	 PA6     			,
	 PA7     			,
	 PA8     			,
	 
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
	 PF4     			,
 
 }Port_PinType;
 
 typedef enum
 {	
	 PIN0    = 0    ,
	 PIN1           ,
	 PIN2           ,
	 PIN3           ,
	 PIN4           ,
	 PIN5           ,
	 PIN6           ,
	 PIN7           
 }Port_PinIDType ;
 
 typedef enum
 {	
	 PORT_A    = 0    ,
	 PORT_B           ,
	 PORT_C           ,
	 PORT_D           ,
	 PORT_E           ,
	 PORT_F           
 }Port_IDType ;
 
 typedef enum
 {	
	 Input    = 0    ,
	 Output    
 }Port_PinDirectionType ;
 
 typedef enum
 {	
	 GPIO    = 0    ,
	 DIO						,							//Digital I/O
	 ALT_Func	    
 }PinModeType ;
 
 typedef enum
 {	
	 No_AF    = 0   ,
	 ADC_TRIG				,							//ADC Trigger
	 AF_SPI	    		,							//SPI Func.
	 AF_I2C	    		,							//I2C Func.
	 AF_UART	    	,							//UART Func.
	 AF_CCP	    		,							//CCP Func.
	 AF_CAN	    		,							//CAN Func.
	 AF_AIN	    		 							//Analog Input
 }PinAFType ;
 
 typedef enum
 {	
	 PULL_UP    = 0  			  ,
	 PULL_DOWN							,							
	 OPEN_DRAIN	    
 }PinInternalAttachType ;
 
 typedef enum
 {	
	 No_OC		 = 0,
	 _2mA     			  ,
	 _4mA							,							
	 _8mA	    				
 }PinOutputCurrentType ;
 
 
 
typedef struct{
	Port_PinType	       		    PinID;
	Port_PinIDType							PinNO;
	Port_IDType									PortNo;
	Port_PinDirectionType				PinDirection;
	PinModeType					    		PinMode;
	PinAFType										PinAF;   
	PinInternalAttachType				PinAttach;
	PinOutputCurrentType				PinOC;
}Port_ConfigType;


 
#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/

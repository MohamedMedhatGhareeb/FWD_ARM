/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


//Interrupt Control
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;   //Bit-Field

typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

//GPIO
typedef struct 
{
    uint32 PORT_A   :1;
    uint32 PORT_B   :1;
    uint32 PORT_C   :1;
    uint32 PORT_D   :1;
    uint32 PORT_E   :1;
    uint32 PORT_F   :1;
    uint32      :26;
}RCGCGPIO_BF; 

typedef struct 
{
    uint32 P0   :1;
    uint32 P1   :1;
    uint32 P2   :1;
    uint32 P3   :1;
    uint32 P4   :1;
    uint32 P5   :1;
    uint32 P6   :1;
    uint32 P7   :1;
    uint32      :24;
}GPIO_BF; 
/*GPIODATA_BF,GPIODIR_BF,
  GPIOIS_BF,GPIOIBE_BF,GPIOIEV_BF,GPIOIM_BF,GPIORIS_BF,GPIOMIS_BF,GPIOICR_BF,
  GPIOAFSEL_BF,
  GPIODR2R_BF,GPIODR4R_BF,GPIODR8R_BF,GPIOODR_BF,GPIOPUR_BF,GPIOPDR_BF,
  GPIOSLR_BF,GPIODEN_BF,GPIOCR_BF,GPIOAMSEL_BF,GPIOADCCTL_BF,GPIODMACTL_BF
 ;   //Bit-Field
*/
typedef struct 
{
    uint32 PMC0   :4;
    uint32 PMC1   :4;
    uint32 PMC2   :4;
    uint32 PMC3   :4;
    uint32 PMC4   :4;
    uint32 PMC5   :4;
    uint32 PMC6   :4;
    uint32 PMC7   :4;
}GPIOPCTL_BF;

typedef union 
{
    uint32 R;
    RCGCGPIO_BF PORT_NO;
}RCGCGPIO_Tag;

typedef union 
{
    uint32 R;
    GPIO_BF PIN;
}GPIO_Tag;

typedef union 
{
    uint32 R;
    GPIOPCTL_BF PMC;
}GPIOPCTL_Tag;

//GPT
typedef struct 
{
    uint32 TIM_0   :1;
    uint32 TIM_1   :1;
    uint32 TIM_2   :1;
    uint32 TIM_3   :1;
    uint32 TIM_4   :1;
    uint32 TIM_5   :1;
    uint32     		 :26;
}RCGCTIMER_BF; 

typedef union 
{
    uint32 R;
    RCGCTIMER_BF TIM_NO;
}RCGCTIMER_Tag;

typedef struct 
{
    uint32 TIM_EN   :1; 
    uint32     	 	 :31;
}GPTMCTL_BF; 

typedef union 
{
    uint32 R;
    GPTMCTL_BF TIM_EN;
}GPTMCTL_Tag;

typedef struct 
{
    uint32 GPTMCFG   :3; 
    uint32     	 	 :29;
}GPTMCFG_BF; 

typedef union 
{
    uint32 R;
    GPTMCFG_BF TIM_EN;
}GPTMCFG_Tag;

typedef struct 
{
    uint32 TnMR      :2;
    uint32 TnCMR     :1;
    uint32 TnAMS     :1;
    uint32 TnCDIR    :1;
    uint32 TnMIE     :1;
    uint32 TnWOT     :1;
    uint32 TnSNAPS   :1;
    uint32 TnILD     :1;
    uint32 TnPWMIE   :1;
    uint32 TnMRSU    :1;
    uint32 TnPLO     :1;
    
    uint32     	 	 :20;
}GPTMTnMR_BF; 

typedef union 
{
    uint32 R;
    GPTMTnMR_BF TnMR;
}GPTMTnMR_Tag;

typedef struct 
{
    uint32 TATOIM      :1;
    uint32 CAMIM       :1;
    uint32 CAEIM       :1;
    uint32 RTCIM       :1;
    uint32 TAMIM       :1;
    uint32             :3;
    uint32 TBTOIM      :1;
    uint32 CBMIM       :1;
    uint32 CBEIM       :1;
    uint32 TBMIM       :1;
    uint32             :4;
    uint32 WUEIM       :1;
    uint32     	 	     :15;
}GPTMIMR_BF; 

typedef union 
{
    uint32 R;
    GPTMIMR_BF MIMR;
}GPTMIMR_Tag;

typedef struct 
{
    uint32 TATOCINT      :1;
    uint32 CAMCINT       :1;
    uint32 CAECINT       :1;
    uint32 RTCCINT       :1;
    uint32 TAMCINT       :1;
    uint32            	 :3;
    uint32 TBTOCINT      :1;
    uint32 CBMCINT       :1;
    uint32 CBECINT       :1;
    uint32 TBMCINT       :1;
    uint32           	   :4;
    uint32 WUECINT       :1;
    uint32     	 	 		   :15;
}GPTMICR_BF; 

typedef union 
{
    uint32 R;
    GPTMICR_BF MICR;
}GPTMICR_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//Private Peripherals
#define CORTEXM4_CORE_PERI_BASE                          0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_CORE_PERI_BASE+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_CORE_PERI_BASE+0xD04))
#define VECTKEY_APINT                          0x05FA

//-------------------------------------GPIO-------------------------------------------------------------------//


#define SYSTEM_CONTROL_BASE_ADDRESS												0x400FE000
#define RCGCGPIO_Offset																		0x608
#define RCGCTIMER_Offset																	0x604
#define RCGCWTIMER_Offset																	0x65C
#define GPIO_CLK_GATE                                     *((volatile RCGCGPIO_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+RCGCGPIO_Offset))
#define RCGCTIMER_CLK_GATE                                *((volatile RCGCTIMER_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+RCGCTIMER_Offset))
#define RCGCWTIMER_CLK_GATE                               *((volatile RCGCTIMER_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+RCGCWTIMER_Offset))
	

#define PORTA_APB_BASE																	  0x40004000 
#define PORTA_AHB_BASE																	  0x40058000 
#define PORTB_APB_BASE																	  0x40005000 
#define PORTB_AHB_BASE																	  0x40059000 
#define PORTC_APB_BASE																	  0x40006000 
#define PORTC_AHB_BASE																	  0x4005A000 
#define PORTD_APB_BASE																	  0x40007000 
#define PORTD_AHB_BASE																	  0x4005B000 
#define PORTE_APB_BASE																	  0x40024000 
#define PORTE_AHB_BASE																	  0x4005C000 
#define PORTF_APB_BASE																	  0x40025000 
#define PORTF_AHB_BASE																	  0x4005D000 

#define GPIODATA_Offset																		0x000
#define GPIODIR_Offset																		0x400
#define GPIOIS_Offset																			0x404
#define GPIOIBE_Offset																		0x408
#define GPIOIEV_Offset																		0x40C
#define GPIOIM_Offset																			0x410
#define GPIORIS_Offset																		0x414
#define GPIOMIS_Offset																		0x418
#define GPIOICR_Offset																		0x41C
#define GPIOAFSEL_Offset																	0x420
#define GPIODR2R_Offset																		0x500
#define GPIODR4R_Offset																		0x504
#define GPIODR8R_Offset																		0x508
#define GPIOODR_Offset																		0x50C
#define GPIOPUR_Offset																		0x510
#define GPIOPDR_Offset																		0x514
#define GPIOSLR_Offset																		0x518
#define GPIODEN_Offset																		0x51C
#define GPIOLOCK_Offset																		0x520
#define GPIOCR_Offset																			0x524
#define GPIOAMSEL_Offset																	0x528
#define GPIOPCTL_Offset																		0x52C
#define GPIOADCCTL_Offset																	0x530
#define GPIODMACTL_Offset																	0x534

#define GPIODATA_PortA                                  *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODATA_Offset))
#define GPIODATA_PortB                                  *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODATA_Offset))
#define GPIODATA_PortC                                  *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODATA_Offset))
#define GPIODATA_PortD                                  *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODATA_Offset))
#define GPIODATA_PortE                                  *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODATA_Offset))
#define GPIODATA_PortF                                  *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODATA_Offset))

#define GPIODIR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODIR_Offset))
#define GPIODIR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODIR_Offset))
#define GPIODIR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODIR_Offset))
#define GPIODIR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODIR_Offset))
#define GPIODIR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODIR_Offset))
#define GPIODIR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODIR_Offset))

#define GPIOIS_PortA                                    *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOIS_Offset))
#define GPIOIS_PortB                                    *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOIS_Offset))
#define GPIOIS_PortC                                    *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOIS_Offset))
#define GPIOIS_PortD                                    *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOIS_Offset))
#define GPIOIS_PortE                                    *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOIS_Offset))
#define GPIOIS_PortF                                    *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOIS_Offset))

#define GPIOIBE_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOIBE_Offset))
#define GPIOIBE_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOIBE_Offset))
#define GPIOIBE_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOIBE_Offset))
#define GPIOIBE_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOIBE_Offset))
#define GPIOIBE_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOIBE_Offset))
#define GPIOIBE_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOIBE_Offset))

#define GPIOIEV_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOIEV_Offset))
#define GPIOIEV_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOIEV_Offset))
#define GPIOIEV_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOIEV_Offset))
#define GPIOIEV_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOIEV_Offset))
#define GPIOIEV_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOIEV_Offset))
#define GPIOIEV_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOIEV_Offset))

#define GPIOIM_PortA                                    *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOIM_Offset))
#define GPIOIM_PortB                                    *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOIM_Offset))
#define GPIOIM_PortC                                    *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOIM_Offset))
#define GPIOIM_PortD                                    *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOIM_Offset))
#define GPIOIM_PortE                                    *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOIM_Offset))
#define GPIOIM_PortF                                    *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOIM_Offset))

#define GPIORIS_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIORIS_Offset))
#define GPIORIS_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIORIS_Offset))
#define GPIORIS_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIORIS_Offset))
#define GPIORIS_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIORIS_Offset))
#define GPIORIS_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIORIS_Offset))
#define GPIORIS_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIORIS_Offset))

#define GPIOMIS_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOMIS_Offset))
#define GPIOMIS_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOMIS_Offset))
#define GPIOMIS_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOMIS_Offset))
#define GPIOMIS_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOMIS_Offset))
#define GPIOMIS_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOMIS_Offset))
#define GPIOMIS_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOMIS_Offset))

#define GPIOICR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOICR_Offset))
#define GPIOICR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOICR_Offset))
#define GPIOICR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOICR_Offset))
#define GPIOICR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOICR_Offset))
#define GPIOICR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOICR_Offset))
#define GPIOICR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOICR_Offset))

#define GPIOAFSEL_PortA                                 *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOAFSEL_Offset))
#define GPIOAFSEL_PortB                                 *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOAFSEL_Offset))
#define GPIOAFSEL_PortC                                 *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOAFSEL_Offset))
#define GPIOAFSEL_PortD                                 *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOAFSEL_Offset))
#define GPIOAFSEL_PortE                                 *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOAFSEL_Offset))
#define GPIOAFSEL_PortF                                 *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOAFSEL_Offset))

#define GPIODR2R_PortA                                  *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODR2R_Offset))
#define GPIODR2R_PortB                                  *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODR2R_Offset))
#define GPIODR2R_PortC                                  *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODR2R_Offset))
#define GPIODR2R_PortD                                  *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODR2R_Offset))
#define GPIODR2R_PortE                                  *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODR2R_Offset))
#define GPIODR2R_PortF                                  *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODR2R_Offset))

#define GPIODR4R_PortA                                  *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODR4R_Offset))
#define GPIODR4R_PortB                                  *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODR4R_Offset))
#define GPIODR4R_PortC                                  *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODR4R_Offset))
#define GPIODR4R_PortD                                  *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODR4R_Offset))
#define GPIODR4R_PortE                                  *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODR4R_Offset))
#define GPIODR4R_PortF                                  *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODR4R_Offset))

#define GPIODR8R_PortA                                 *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODR8R_Offset))
#define GPIODR8R_PortB                                 *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODR8R_Offset))
#define GPIODR8R_PortC                                 *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODR8R_Offset))
#define GPIODR8R_PortD                                 *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODR8R_Offset))
#define GPIODR8R_PortE                                 *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODR8R_Offset))
#define GPIODR8R_PortF                                 *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODR8R_Offset))

#define GPIOODR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOODR_Offset))
#define GPIOODR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOODR_Offset))
#define GPIOODR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOODR_Offset))
#define GPIOODR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOODR_Offset))
#define GPIOODR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOODR_Offset))
#define GPIOODR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOODR_Offset))

#define GPIOPUR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOPUR_Offset))
#define GPIOPUR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOPUR_Offset))
#define GPIOPUR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOPUR_Offset))
#define GPIOPUR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOPUR_Offset))
#define GPIOPUR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOPUR_Offset))
#define GPIOPUR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOPUR_Offset))

#define GPIOPDR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOPDR_Offset))
#define GPIOPDR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOPDR_Offset))
#define GPIOPDR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOPDR_Offset))
#define GPIOPDR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOPDR_Offset))
#define GPIOPDR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOPDR_Offset))
#define GPIOPDR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOPDR_Offset))

#define GPIOSLR_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOSLR_Offset))
#define GPIOSLR_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOSLR_Offset))
#define GPIOSLR_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOSLR_Offset))
#define GPIOSLR_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOSLR_Offset))
#define GPIOSLR_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOSLR_Offset))
#define GPIOSLR_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOSLR_Offset))

#define GPIODEN_PortA                                   *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODEN_Offset))
#define GPIODEN_PortB                                   *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODEN_Offset))
#define GPIODEN_PortC                                   *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODEN_Offset))
#define GPIODEN_PortD                                   *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODEN_Offset))
#define GPIODEN_PortE                                   *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODEN_Offset))
#define GPIODEN_PortF                                   *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODEN_Offset))

#define GPIOLOCK_PortA                                   *((volatile uint32*)(PORTA_APB_BASE+GPIOLOCK_Offset))
#define GPIOLOCK_PortB                                   *((volatile uint32*)(PORTB_APB_BASE+GPIOLOCK_Offset))
#define GPIOLOCK_PortC                                   *((volatile uint32*)(PORTC_APB_BASE+GPIOLOCK_Offset))
#define GPIOLOCK_PortD                                   *((volatile uint32*)(PORTD_APB_BASE+GPIOLOCK_Offset))
#define GPIOLOCK_PortE                                   *((volatile uint32*)(PORTE_APB_BASE+GPIOLOCK_Offset))
#define GPIOLOCK_PortF                                   *((volatile uint32*)(PORTF_APB_BASE+GPIOLOCK_Offset))

#define GPIOCR_PortA                                    *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOCR_Offset))
#define GPIOCR_PortB                                    *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOCR_Offset))
#define GPIOCR_PortC                                    *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOCR_Offset))
#define GPIOCR_PortD                                    *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOCR_Offset))
#define GPIOCR_PortE                                    *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOCR_Offset))
#define GPIOCR_PortF                                    *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOCR_Offset))

#define GPIOAMSE_PortA                                  *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOAMSE_Offset))
#define GPIOAMSE_PortB                                  *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOAMSE_Offset))
#define GPIOAMSE_PortC                                  *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOAMSE_Offset))
#define GPIOAMSE_PortD                                  *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOAMSE_Offset))
#define GPIOAMSE_PortE                                  *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOAMSE_Offset))
#define GPIOAMSE_PortF                                  *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOAMSE_Offset))

#define GPIOADCCTL_PortA                                *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIOADCCTL_Offset))
#define GPIOADCCTL_PortB                                *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIOADCCTL_Offset))
#define GPIOADCCTL_PortC                                *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIOADCCTL_Offset))
#define GPIOADCCTL_PortD                                *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIOADCCTL_Offset))
#define GPIOADCCTL_PortE                                *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIOADCCTL_Offset))
#define GPIOADCCTL_PortF                                *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIOADCCTL_Offset))

#define GPIODMACTL_PortA                                *((volatile GPIO_Tag*)(PORTA_APB_BASE+GPIODMACTL_Offset))
#define GPIODMACTL_PortB                                *((volatile GPIO_Tag*)(PORTB_APB_BASE+GPIODMACTL_Offset))
#define GPIODMACTL_PortC                                *((volatile GPIO_Tag*)(PORTC_APB_BASE+GPIODMACTL_Offset))
#define GPIODMACTL_PortD                                *((volatile GPIO_Tag*)(PORTD_APB_BASE+GPIODMACTL_Offset))
#define GPIODMACTL_PortE                                *((volatile GPIO_Tag*)(PORTE_APB_BASE+GPIODMACTL_Offset))
#define GPIODMACTL_PortF                                *((volatile GPIO_Tag*)(PORTF_APB_BASE+GPIODMACTL_Offset))

#define GPIOPCTL_PortA                                  *((volatile GPIOPCTL_Tag*)(PORTA_APB_BASE+GPIOPCTL_Offset))
#define GPIOPCTL_PortB                                  *((volatile GPIOPCTL_Tag*)(PORTB_APB_BASE+GPIOPCTL_Offset))
#define GPIOPCTL_PortC                                  *((volatile GPIOPCTL_Tag*)(PORTC_APB_BASE+GPIOPCTL_Offset))
#define GPIOPCTL_PortD                                  *((volatile GPIOPCTL_Tag*)(PORTD_APB_BASE+GPIOPCTL_Offset))
#define GPIOPCTL_PortE                                  *((volatile GPIOPCTL_Tag*)(PORTE_APB_BASE+GPIOPCTL_Offset))
#define GPIOPCTL_PortF                                  *((volatile GPIOPCTL_Tag*)(PORTF_APB_BASE+GPIOPCTL_Offset))

//----------------------------------------GPT------------------------------------------------------------------------//
#define TIMER_0_BASE																	  0x40030000 
#define TIMER_1_BASE																	  0x40031000 
#define TIMER_2_BASE																	  0x40032000 
#define TIMER_3_BASE																	  0x40033000 
#define TIMER_4_BASE																	  0x40034000 
#define TIMER_5_BASE																	  0x40035000 
#define WTIMER_0_BASE																	  0x40036000 
#define WTIMER_1_BASE																	  0x40037000 
#define WTIMER_2_BASE																	  0x4004C000 
#define WTIMER_3_BASE																	  0x4004D000 
#define WTIMER_4_BASE																	  0x4004E000 
#define WTIMER_5_BASE																	  0x4004F000 

#define GPTMCFG_Offset																	0x000
#define GPTMTAMR_Offset																	0x004
#define GPTMTBMR_Offset																	0x008
#define GPTMCTL_Offset																	0x00C
#define GPTMIMR_Offset																	0x018
#define GPTMICR_Offset																	0x024
#define GPTMTAILR_Offset																0x028
#define GPTMTBILR_Offset																0x02C
#define GPTMTAV_Offset																	0x050
#define GPTMTBV_Offset																	0x054


#define GPTMCTL_TIMER_0                                  *((volatile GPTMCTL_Tag*)(TIMER_0_BASE+GPTMCTL_Offset))
#define GPTMCTL_TIMER_1                                  *((volatile GPTMCTL_Tag*)(TIMER_1_BASE+GPTMCTL_Offset))
#define GPTMCTL_TIMER_2                                  *((volatile GPTMCTL_Tag*)(TIMER_2_BASE+GPTMCTL_Offset))
#define GPTMCTL_TIMER_3                                  *((volatile GPTMCTL_Tag*)(TIMER_3_BASE+GPTMCTL_Offset))
#define GPTMCTL_TIMER_4                                  *((volatile GPTMCTL_Tag*)(TIMER_4_BASE+GPTMCTL_Offset))
#define GPTMCTL_TIMER_5                                  *((volatile GPTMCTL_Tag*)(TIMER_5_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_0                                 *((volatile GPTMCTL_Tag*)(WTIMER_0_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_1                                 *((volatile GPTMCTL_Tag*)(WTIMER_1_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_2                                 *((volatile GPTMCTL_Tag*)(WTIMER_2_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_3                                 *((volatile GPTMCTL_Tag*)(WTIMER_3_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_4                                 *((volatile GPTMCTL_Tag*)(WTIMER_4_BASE+GPTMCTL_Offset))
#define GPTMCTL_WTIMER_5                                 *((volatile GPTMCTL_Tag*)(WTIMER_5_BASE+GPTMCTL_Offset))

#define GPTMCFG_TIMER_0                                  *((volatile GPTMCFG_Tag*)(TIMER_0_BASE+GPTMCFG_Offset))
#define GPTMCFG_TIMER_1                                  *((volatile GPTMCFG_Tag*)(TIMER_1_BASE+GPTMCFG_Offset))
#define GPTMCFG_TIMER_2                                  *((volatile GPTMCFG_Tag*)(TIMER_2_BASE+GPTMCFG_Offset))
#define GPTMCFG_TIMER_3                                  *((volatile GPTMCFG_Tag*)(TIMER_3_BASE+GPTMCFG_Offset))
#define GPTMCFG_TIMER_4                                  *((volatile GPTMCFG_Tag*)(TIMER_4_BASE+GPTMCFG_Offset))
#define GPTMCFG_TIMER_5                                  *((volatile GPTMCFG_Tag*)(TIMER_5_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_0                                 *((volatile GPTMCFG_Tag*)(WTIMER_0_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_1                                 *((volatile GPTMCFG_Tag*)(WTIMER_1_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_2                                 *((volatile GPTMCFG_Tag*)(WTIMER_2_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_3                                 *((volatile GPTMCFG_Tag*)(WTIMER_3_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_4                                 *((volatile GPTMCFG_Tag*)(WTIMER_4_BASE+GPTMCFG_Offset))
#define GPTMCFG_WTIMER_5                                 *((volatile GPTMCFG_Tag*)(WTIMER_5_BASE+GPTMCFG_Offset))

#define GPTMTAMR_TIMER_0                                  *((volatile GPTMTnMR_Tag*)(TIMER_0_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_TIMER_1                                  *((volatile GPTMTnMR_Tag*)(TIMER_1_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_TIMER_2                                  *((volatile GPTMTnMR_Tag*)(TIMER_2_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_TIMER_3                                  *((volatile GPTMTnMR_Tag*)(TIMER_3_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_TIMER_4                                  *((volatile GPTMTnMR_Tag*)(TIMER_4_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_TIMER_5                                  *((volatile GPTMTnMR_Tag*)(TIMER_5_BASE+GPTMTAMR_Offset))
#define GPTMTBMR_TIMER_0                                  *((volatile GPTMTnMR_Tag*)(TIMER_0_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_TIMER_1                                  *((volatile GPTMTnMR_Tag*)(TIMER_1_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_TIMER_2                                  *((volatile GPTMTnMR_Tag*)(TIMER_2_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_TIMER_3                                  *((volatile GPTMTnMR_Tag*)(TIMER_3_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_TIMER_4                                  *((volatile GPTMTnMR_Tag*)(TIMER_4_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_TIMER_5                                  *((volatile GPTMTnMR_Tag*)(TIMER_5_BASE+GPTMTBMR_Offset))

#define GPTMTAMR_WTIMER_0                                  *((volatile GPTMTnMR_Tag*)(WTIMER_0_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_WTIMER_1                                  *((volatile GPTMTnMR_Tag*)(WTIMER_1_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_WTIMER_2                                  *((volatile GPTMTnMR_Tag*)(WTIMER_2_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_WTIMER_3                                  *((volatile GPTMTnMR_Tag*)(WTIMER_3_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_WTIMER_4                                  *((volatile GPTMTnMR_Tag*)(WTIMER_4_BASE+GPTMTAMR_Offset))
#define GPTMTAMR_WTIMER_5                                  *((volatile GPTMTnMR_Tag*)(WTIMER_5_BASE+GPTMTAMR_Offset))
#define GPTMTBMR_WTIMER_0                                  *((volatile GPTMTnMR_Tag*)(WTIMER_0_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_WTIMER_1                                  *((volatile GPTMTnMR_Tag*)(WTIMER_1_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_WTIMER_2                                  *((volatile GPTMTnMR_Tag*)(WTIMER_2_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_WTIMER_3                                  *((volatile GPTMTnMR_Tag*)(WTIMER_3_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_WTIMER_4                                  *((volatile GPTMTnMR_Tag*)(WTIMER_4_BASE+GPTMTBMR_Offset))
#define GPTMTBMR_WTIMER_5                                  *((volatile GPTMTnMR_Tag*)(WTIMER_5_BASE+GPTMTBMR_Offset))

#define GPTMIMR_TIMER_0                                  *((volatile GPTMIMR_Tag*)(TIMER_0_BASE+GPTMIMR_Offset))
#define GPTMIMR_TIMER_1                                  *((volatile GPTMIMR_Tag*)(TIMER_1_BASE+GPTMIMR_Offset))
#define GPTMIMR_TIMER_2                                  *((volatile GPTMIMR_Tag*)(TIMER_2_BASE+GPTMIMR_Offset))
#define GPTMIMR_TIMER_3                                  *((volatile GPTMIMR_Tag*)(TIMER_3_BASE+GPTMIMR_Offset))
#define GPTMIMR_TIMER_4                                  *((volatile GPTMIMR_Tag*)(TIMER_4_BASE+GPTMIMR_Offset))
#define GPTMIMR_TIMER_5                                  *((volatile GPTMIMR_Tag*)(TIMER_5_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_0                                 *((volatile GPTMIMR_Tag*)(WTIMER_0_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_1                                 *((volatile GPTMIMR_Tag*)(WTIMER_1_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_2                                 *((volatile GPTMIMR_Tag*)(WTIMER_2_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_3                                 *((volatile GPTMIMR_Tag*)(WTIMER_3_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_4                                 *((volatile GPTMIMR_Tag*)(WTIMER_4_BASE+GPTMIMR_Offset))
#define GPTMIMR_WTIMER_5                                 *((volatile GPTMIMR_Tag*)(WTIMER_5_BASE+GPTMIMR_Offset))

#define GPTMICR_TIMER_0                                  *((volatile GPTMICR_Tag*)(TIMER_0_BASE+GPTMICR_Offset))
#define GPTMICR_TIMER_1                                  *((volatile GPTMICR_Tag*)(TIMER_1_BASE+GPTMICR_Offset))
#define GPTMICR_TIMER_2                                  *((volatile GPTMICR_Tag*)(TIMER_2_BASE+GPTMICR_Offset))
#define GPTMICR_TIMER_3                                  *((volatile GPTMICR_Tag*)(TIMER_3_BASE+GPTMICR_Offset))
#define GPTMICR_TIMER_4                                  *((volatile GPTMICR_Tag*)(TIMER_4_BASE+GPTMICR_Offset))
#define GPTMICR_TIMER_5                                  *((volatile GPTMICR_Tag*)(TIMER_5_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_0                                 *((volatile GPTMICR_Tag*)(WTIMER_0_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_1                                 *((volatile GPTMICR_Tag*)(WTIMER_1_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_2                                 *((volatile GPTMICR_Tag*)(WTIMER_2_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_3                                 *((volatile GPTMICR_Tag*)(WTIMER_3_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_4                                 *((volatile GPTMICR_Tag*)(WTIMER_4_BASE+GPTMICR_Offset))
#define GPTMICR_WTIMER_5                                 *((volatile GPTMICR_Tag*)(WTIMER_5_BASE+GPTMICR_Offset))

#define GPTMTAILR_TIMER_0                                  *((volatile uint32*)(TIMER_0_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_TIMER_1                                  *((volatile uint32*)(TIMER_1_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_TIMER_2                                  *((volatile uint32*)(TIMER_2_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_TIMER_3                                  *((volatile uint32*)(TIMER_3_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_TIMER_4                                  *((volatile uint32*)(TIMER_4_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_TIMER_5                                  *((volatile uint32*)(TIMER_5_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_0                                 *((volatile uint32*)(WTIMER_0_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_1                                 *((volatile uint32*)(WTIMER_1_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_2                                 *((volatile uint32*)(WTIMER_2_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_3                                 *((volatile uint32*)(WTIMER_3_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_4                                 *((volatile uint32*)(WTIMER_4_BASE+GPTMTAILR_Offset))
#define GPTMTAILR_WTIMER_5                                 *((volatile uint32*)(WTIMER_5_BASE+GPTMTAILR_Offset))

#define GPTMTAV_TIMER_0                                  *((volatile uint32*)(TIMER_0_BASE+GPTMTAV_Offset))
#define GPTMTAV_TIMER_1                                  *((volatile uint32*)(TIMER_1_BASE+GPTMTAV_Offset))
#define GPTMTAV_TIMER_2                                  *((volatile uint32*)(TIMER_2_BASE+GPTMTAV_Offset))
#define GPTMTAV_TIMER_3                                  *((volatile uint32*)(TIMER_3_BASE+GPTMTAV_Offset))
#define GPTMTAV_TIMER_4                                  *((volatile uint32*)(TIMER_4_BASE+GPTMTAV_Offset))
#define GPTMTAV_TIMER_5                                  *((volatile uint32*)(TIMER_5_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_0                                 *((volatile uint32*)(WTIMER_0_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_1                                 *((volatile uint32*)(WTIMER_1_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_2                                 *((volatile uint32*)(WTIMER_2_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_3                                 *((volatile uint32*)(WTIMER_3_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_4                                 *((volatile uint32*)(WTIMER_4_BASE+GPTMTAV_Offset))
#define GPTMTAV_WTIMER_5                                 *((volatile uint32*)(WTIMER_5_BASE+GPTMTAV_Offset))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/

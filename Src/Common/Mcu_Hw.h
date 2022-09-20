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

/*
typedef union 
{
    uint32 R;
    GPIODATA_BF PIN;
}GPIODATA_Tag;

typedef union 
{
    uint32 R;
    GPIODIR_BF PIN;
}GPIODIR_Tag;

typedef union 
{
    uint32 R;
    GPIOIS_BF PIN;
}GPIOIS_Tag;

typedef union 
{
    uint32 R;
    GPIOIBE_BF PIN;
}GPIOIBE_Tag;
*/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//Private Peripherals
#define CORTEXM4_CORE_PERI_BASE                          0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_CORE_PERI_BASE+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_CORE_PERI_BASE+0xD04))
#define VECTKEY_APINT                          0x05FA

//-----------------------------------GPIO-------------------------------------------------------------------


#define SYSTEM_CONTROL_BASE_ADDRESS												0x400FE000
#define RCGCGPIO_Offset																		0x608
#define GPIO_CLK_GATE                                     *((volatile RCGCGPIO_Tag*)(SYSTEM_CONTROL_BASE_ADDRESS+RCGCGPIO_Offset))
																											
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

//#define GPIODATA

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/

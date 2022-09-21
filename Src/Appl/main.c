#include "Platform_Types.h"
#include "IntCtrl.h"
#include "GPIO.h"
#include "GPT.h"

void x()
{
	
}

int main (void)
{	
	/* user need to input :
		1- Interrupt/exceptions needed to be enabledd
		2- Group Priority
		3- Sub-group Priority
	*/
	
	//IntCrtl_Init() ;
	
	
	//Gpt_Config[0].CallBackFunc_Type = &x;
	GPT_Notification[0]=&x;
	//GPIO Test
	for(uint8 i =0 ; i < GPIOPin_ACTIVE_NO  ; i++)
	{
		Port_Init(&GPIOPin_Cfg[i]);
	}
	GPT_Init(Gpt_Config);
//	Port_Init(GPIOPin_Cfg);
//	Port_Init(&GPIOPin_Cfg[0]);
//	Port_Init(&GPIOPin_Cfg[1]);
//	Port_Init(&GPIOPin_Cfg[2]);
	//GPIO_CLK_GATE = 0x0001 ;
	while(1) ;
}

#include "Platform_Types.h"
#include "IntCtrl.h"
#include "GPIO.h"


int main (void)
{	
	/* user need to input :
		1- Interrupt/exceptions needed to be enabledd
		2- Group Priority
		3- Sub-group Priority


	*/
	//IntCrtl_Init() ;
	//GPIO_CLK_GATE = 0x0001 ;
	Port_Init(GPIOPin_Cfg);
	Port_Init(&GPIOPin_Cfg[0]);
	Port_Init(&GPIOPin_Cfg[1]);
	Port_Init(&GPIOPin_Cfg[2]);
	//GPIO_CLK_GATE = 0x0001 ;
	while(1) ;
}

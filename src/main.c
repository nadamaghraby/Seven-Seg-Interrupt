#include "stm32f4xx.h"
#include "gpio.h"
//void ISR_OF_EXTI0(void);
//void ISR_OF_EXTI1(void);
//void (*ptrToFunction)(void)= 0x00000058;

int main(void)
{
	Init();
	while(1)
	{
	}

}
void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0();
}

void EXTI1_IRQHandler(void){
	ISR_OF_EXTI1();
}

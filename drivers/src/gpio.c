#include "stm32f4xx.h"
#include "gpio.h"
//1 for pull up,0 for pull down
//0 push pull ,1 open drain
//dir -> input(0) output(1)
//set default to pull up & push pull
void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin, char type)
{   //Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);
	//set output data
	if(dir)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}
	else
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}
	if(type)
	{
		if(dir){
			//push pull
			GPIOx-> OTYPER &=~ (1u<<pin);
		}
		else{
			//pull up
			GPIOx->PUPDR  |= (1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}
	}
	else{
		if(dir){
			//open drain
			GPIOx->OTYPER |=(1u<<pin);
		}
		else{
			//pull down
			GPIOx->PUPDR  &=~ (1u<<(2*pin));
			GPIOx->PUPDR |=(1u<<(2*pin+1));
		}
	}
}


//state ->  high(1) , low(0)

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if ((GPIOx->MODER & (1u<<(2*pin))) && !(GPIOx->MODER & (1u<<(2*pin+1))))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}


char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{
	if(! ((GPIOx-> MODER &(1u<<(2*pin))) && (GPIOx -> MODER&(1u<<(2*pin+1)))))
	{
		int x=GPIOx->IDR &(1<<pin);
		return x;
	}
	else
	{
		return 2;
	}
}


#include "stm32f4xx.h"
#include "gpio.h"
void Init(void){
	GPIO_Init(GPIOA,1,1,0,1);
	GPIO_Init(GPIOA,2,1,0,1);
	GPIO_Init(GPIOA,3,1,0,1);
	GPIO_Init(GPIOA,4,1,0,1);
	//buttons
	GPIO_Init(GPIOB,0,0,1,1);
	GPIO_Init(GPIOB,1,0,1,1);
	interrupt_Init('B',0);
	interrupt_Init('B',1);
}
void interrupt_Init(char gpio,char pin){
	RCC->APB2ENR|=(1u<<14);
	EXTI->IMR |=(1u<<pin);
	EXTI->FTSR |=(1u<<pin);
	NVIC->ISER[0]|=(1u<<(6+pin));
	int p;
	int  c;
	if(pin>=0 && pin<=3){
		c=0;
		p=pin;
	}

	else if( pin>3 && pin<=7)
	{
		c=1;
	p=pin-4;
	}

	else if (pin>7&& pin<=11){
		c=2;
		p=pin-8;
	}

	else if ( pin>11 && pin<=15){
		c=3;
		p=pin-12;
	}

	switch(gpio){
	case 'A' :
		SYSCFG->EXTICR[c] &=~(1u<<4*p);
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+1));
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+2));
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+3));
		break;
	case 'B' :
		SYSCFG->EXTICR[c] |=(1u<<4*p);
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+1));
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+2));
		SYSCFG->EXTICR[c] &=~(1u<<(4*p+3));
		break;
	}
}
void ISR_OF_EXTI0(void)
{
//7 seg code
	char c=GPIO_Read(GPIOB,0);
	char x=GPIO_Read(GPIOA,1);
	char y=GPIO_Read(GPIOA,2);
	char z=GPIO_Read(GPIOA,3);
	char k=GPIO_Read(GPIOA,4);
	if(!(c)){
	  if(!(k) && !(z) && !(y) && !(x)) //0
		{
					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
		}

		else if(!(k) && !(z) && !(y) && (x)) //1
		{
					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && !(z) && (y) && !(x))//2
		{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && !(z) && (y) && (x))//3
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && (z) && !(y) && !(x)) //4
		{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && (z) && !(y) && (x))//5
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && (z) && (y) && !(x))//6
		{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && (z) && (y) && (x))//7
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,1);
		}
		else if((k) && !(z) && !(y) && !(x)) //8
			{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,1);

			}
		else if((k) && !(z) && !(y) && (x)) //9
			{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
			}
	}
	else {}
	for(int i =0 ; i<50000;i++){}
}

void ISR_OF_EXTI1(void)
{
//7seg code
	char c=GPIO_Read(GPIOB,1);
	char x=GPIO_Read(GPIOA,1);
	char y=GPIO_Read(GPIOA,2);
	char z=GPIO_Read(GPIOA,3);
	char k=GPIO_Read(GPIOA,4);

	if(!(c)){
		 if(!(k) && !(z) && !(y) && (x)) //1
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && !(z) && (y) && !(x))//2
					{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
					}
		else if(!(k) && !(z) && (y) && (x))//3
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);
		}
		else if(!(k) && (z) && !(y) && !(x)) //4
		{

					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,0);
					  GPIO_Write(GPIOA,4,0);

		}
		else if(!(k) && (z) && !(y) && (x))//5
		{

					  GPIO_Write(GPIOA,1,0);
					  GPIO_Write(GPIOA,2,0);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);

		}
		else if(!(k) && (z) && (y) && !(x))//6
			{

						  GPIO_Write(GPIOA,1,1);
						  GPIO_Write(GPIOA,2,0);
						  GPIO_Write(GPIOA,3,1);
						  GPIO_Write(GPIOA,4,0);

			}
		else if(!(k) && (z) && (y) && (x))//7
			{

						  GPIO_Write(GPIOA,1,0);
						  GPIO_Write(GPIOA,2,1);
						  GPIO_Write(GPIOA,3,1);
						  GPIO_Write(GPIOA,4,0);

			}
		else if((k) && !(z) && !(y) && !(x)) //8
				{
					  GPIO_Write(GPIOA,1,1);
					  GPIO_Write(GPIOA,2,1);
					  GPIO_Write(GPIOA,3,1);
					  GPIO_Write(GPIOA,4,0);

				}


		else if((k) && !(z) && !(y) && (x)) //9
	{

				  GPIO_Write(GPIOA,1,0);
				  GPIO_Write(GPIOA,2,0);
				  GPIO_Write(GPIOA,3,0);
				  GPIO_Write(GPIOA,4,1);
	}

		else if(!(k) && !(z) && !(y) && !(x)) //0
 		{
 			GPIO_Write(GPIOA,1,1);
 			GPIO_Write(GPIOA,2,0);
 					  GPIO_Write(GPIOA,3,0);
 					  GPIO_Write(GPIOA,4,1);

 		}

	}
	else {}
	for(int i =0 ; i<50000;i++){}

}



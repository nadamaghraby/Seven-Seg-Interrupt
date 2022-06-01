#ifndef INC_GPIO_H_
#define INC_GPIO_H_
void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin,char type);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);
void interrupt_Init(char gpio,char pin);
void Init(void);
void ISR_OF_EXTI0(void);
void ISR_OF_EXTI1(void);
#endif /* INC_GPIO_H_ */

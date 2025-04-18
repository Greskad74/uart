#include "stm32f1xx.h"
#include "timers.h"
  

/*
Frecuencia determinada por ARR
CCRX -> SALIDA = (TIEMPO DE TRABAJO * (ARR + 1))

*/

void timer2_pwm(){
RCC  -> APB1ENR |= 1<<0;
TIM2 -> PSC = 27;
TIM2 -> ARR = 64284;
TIM2 -> CCMR1 |= (1 << 6) | (1<<5);
TIM2 -> CCER |= 1 << 0; // salida por el canal 1  del timer 2
TIM2 ->  CR1 |= 1 << 0;






}


void timer3_pwm(){

RCC -> APB1ENR |= 1<<1;
TIM3 -> PSC= 27;
TIM3 -> ARR =  64284;
TIM3 -> CCMR1 |= (1<< 6) | (1<<5);
TIM3 -> CCER |= (1 <<0);  // salida por el canal 1 del timer 3
TIM3 -> CR1 |= (1<<0);


}
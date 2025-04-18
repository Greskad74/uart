#include "stm32f1xx.h"
#include"systickdelay.h"


void systickdelay(int delay)
{
// valor = 72MHZ * 1 ms =7.2

SysTick -> LOAD = 7200;

// limpia el valor wey 
SysTick -> VAL=0;

//control de registros 

SysTick -> CTRL = (1 << 0 ) | (1 << 2);
for (int i = delay; i > 0; i--)

{
    while (!(SysTick -> CTRL & (1 << 16)));
    
    
    
    
}

SysTick -> CTRL = 0;

}
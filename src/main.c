#include "stm32f1xx.h"
#include "gpio.h"
#include "usart.h"
int main(void) {
  init_gpio();
  usart_polling();
  
  while (1)
  {
    
  }
  
    }

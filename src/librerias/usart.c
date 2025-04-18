#include "stm32f1xx.h"


void usart1_sendbyte(uint16_t data){
	USART1->DR = data;
	while((USART1->SR&(1<<6))==0);
	USART1->SR &= ~(1<<6);
}


void usart1_sendstring(char s[]){
	int i = 0;
	while(i < 64){
		if (s[i] == '\0') break;
		usart1_sendbyte(s[i++]);
	}
}


void usart_polling(){
	RCC->APB2ENR |= 0xFC | (1 << 14);
	//usart1_tx PA9
	//usart1_rx PA10
	GPIOA->ODR |= (1 << 10);
	GPIOA->CRH = 0x444448B4;
	USART1->CR1 = 0x200C;
	USART1->BRR = 7500;
	while(1){
		usart1_sendbyte('H');
		usart1_sendbyte('o');
		usart1_sendbyte('l');
		usart1_sendbyte('a');
		usart1_sendstring("USART");
		usart1_sendbyte('\n');
		usart1_sendbyte('\r');
	}
}



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
	RCC->APB2ENR |= (1 << 14);
	RCC->APB2ENR |= (1 << 2);  // Habilita el reloj para GPIOA
	//usart1_tx PA9
	//usart1_rx PA10
	GPIOA->ODR |= (1 << 10);

	GPIOA->CRH &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4));  // LIMPIA PA 9
	GPIOA->CRH |= (1 << 7) | (1 << 5) | (1 << 4);   // PA9 SALIDA A 50 MHZ PUSHPULL
	GPIOA->CRH &= ~((1 << 11) | (1 << 10) | (1 << 9) | (1 << 8));  // Reseteo a Pa10, Entrada 
	GPIOA->CRH |= (1 << 10); // Opendrai 



	USART1->CR1 |= (1 << 2) | (1 << 3) | (1 << 13);  // Activa RX, TX y USART
	USART1->BRR = 0x341;
	while(1){
		usart1_sendbyte('H');
		usart1_sendbyte('E');
		usart1_sendbyte('Y');
		usart1_sendbyte(' ');
		usart1_sendstring("NANA");
		usart1_sendbyte('\n');
		usart1_sendbyte('\r');
	}
}



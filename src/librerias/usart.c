#include "stm32f1xx.h"
#include "usart.h"

void usart1_sendbyte(uint16_t data){
    USART1->DR = data;
    while((USART1->SR & (1 << 6)) == 0);  // Esperar transmisión completa
}

void usart1_sendstring(const char *s){
    int i = 0;
    while(s[i] != '\0'){
        usart1_sendbyte(s[i++]);
    }
}

void usart_polling(){
    // Habilitar reloj para GPIOA y USART1
    RCC->APB2ENR |= (1 << 2) | (1 << 14);

    // Configurar PA9 (TX) como salida alternativa push-pull
    GPIOA->CRH &= ~(0xF << 4);
    GPIOA->CRH |= (0xB << 4);

    // Configurar PA10 (RX) como entrada flotante
    GPIOA->CRH &= ~(0xF << 8);
    GPIOA->CRH |= (0x4 << 8);

    // Configurar USART1
    USART1->CR1 = 0x200C;  // Habilitar USART, sin paridad, 1 stop bit
    USART1->BRR = 7500;    // Configurar baud rate (9600 baudios si PCLK=72MHz)

    while(1){
        usart1_sendstring("Hey nana USART\n\r");

    }
}



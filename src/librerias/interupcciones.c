#include "stm32f1xx.h"
#include "garra.h"
/*
EXTI program:
- Enable the clocks for GPIOs and AFIO.
- Configure the Alternate Function to use a GPIO (usually standard after reset).
- Configure the interrupt input pin as input using CRL and CRH registers.
- Select the interrupt input pin using AFIO_EXTICR.
- Configure the RTSR and FTSR registers to choose the interrupt edge.
- Set the EXTI_IMR register to enable the interrupt for the line.
- Enable the EXTI interrupt using the ISER register or NVIC_EnableIRQ function.
- Clear the PR flag in the interrupt routine.
*/


/*
	Selects PB4 as the input for external interrupt.
	On each falling edge, an interrupt is generated.
	Interrupt service routine toggles Led on PC13.
*/
void EXTI1_IRQHandler()
{
	EXTI->PR |= (1 << 4); //verifica la interrupccion
	motor1_secuencia();
	
	motor1_secuencia2();
	stoptim2();
	
}

void ext_interrupt(void){
	AFIO->EXTICR[0] = (1 << 0); //Selects PA1 for line 1
	EXTI->FTSR |= (1 << 1);	//interrupt on falling edge
	EXTI->IMR |= (1 << 1);	//enable interrupt
	NVIC->ISER[0] |= 1 << 7;
	
	AFIO->EXTICR[0] |= (1 << 8);   
  EXTI->FTSR |= (1 << 2);        
  EXTI->IMR |= (1 << 2);     
  NVIC->ISER[0] |= 1 << 8;

}





void EXTI2_IRQHandler()
{
	EXTI->PR |= (1 << 2); //verifica la interrupccion 
	motor2_secuencia1();
	motor2_secuencia2();
	stoptim3();	
	
}


#include "stm32f1xx.h"
#include "timers.h"
#include "garra.h"

void motor1_secuencia(){
        timer2_pwm();
                for (volatile int i = 0;i < 100;i++)
        {
        TIM2->CCR2 = 1800;
        for (int j = 0;j < 75453;j++);
        }
        
        for (volatile int i = 100;i > 0;i--)
                                {
        TIM2->CCR2 = 3857;
        for (int j = 0;j < 75453;j++);
        }
                                
        for (volatile int i = 0;i < 100;i++)
        {
        TIM2->CCR2 = 5914;
        for (int j = 0;j < 75453;j++);
                }
        }
        
        
        
        //180°->90°->0°
        void motor1_secuencia2(){
                timer2_pwm();
                for (volatile int i = 0;i < 100;i++)
                {
                TIM2->CCR2 = 5914;
                for (int j = 0;j < 75453;j++);
                }

                for (volatile int i = 100;i > 0;i--)
                {
                TIM2->CCR2 = 3857;
                for (int j = 0;j < 75453;j++);
                }

                for (volatile int i = 0;i < 100;i++)
                {
                TIM2->CCR2 = 1800;
                for (int j = 0;j < 75453;j++);
                        }
                }
        
        
        
                
                
        //0°->90°->180°
                void motor2_secuencia1(){
                        
        timer3_pwm();        //SEGUNDO MOTOR TIMER 3
        
        for (volatile int i = 0;i < 100;i++)
                {
                TIM3->CCR2 = 1800;
                for (int j = 0;j < 65453;j++);
                }

                for (volatile int i = 100;i > 0;i--)
                {
                TIM3->CCR2 = 3857;
                for (int j = 0;j < 65453;j++);
                        }
                        
                for (volatile int i = 0;i < 100;i++)
                        {
                TIM3->CCR2 = 5914;
                for (int j = 0;j < 65453;j++);
                                }
                }
        
        
                
                //180°->90°->0°
                void motor2_secuencia2(){
                        timer3_pwm();
                for (volatile int i = 0;i < 100;i++)
                        {
                        TIM3->CCR2 = 5914;
                        for (int j = 0;j < 65453;j++);
                        }
        
                for (volatile int i = 100;i > 0;i--)
                {
                TIM3->CCR2 = 3857;
                for (int j = 0;j < 65453;j++);
                }
                
                for (volatile int i = 0;i < 100;i++)
                {
                TIM3->CCR2 = 1800;
                for (int j = 0;j < 65453;j++);
                }
                        
                }
                void stoptim3(){
                        TIM3->CR1		|=	~(1 << 0);
                }
                void stoptim2(){
                        TIM2->CR1 |= ~(1 << 0);
                }
                
                
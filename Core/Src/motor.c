#include "motor.h"
volatile uint8_t motorpos[8] = {0x00,0x01,0x02,0x04,0x08};

void motorInit(void){
    GPIO_InitTypeDef port;
    port.Pin= GPIO_PIN_12 | GPIO_PIN_13|GPIO_PIN_14| GPIO_PIN_15 ;
    port.Mode = GPIO_MODE_OUTPUT_PP;
    port.Pull = GPIO_NOPULL;
    port.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &port);
    GPIOB->ODR = GPIOB->ODR & 0x0000;
}
void motor_Update(void){
    volatile uint8_t i; 
    if(i>3||i<0) i=0;
    if(FLAGS.MOTOR){
    if(ESTADOS==LIFTUP) i++;
    if(ESTADOS==LIFTDN) i--;
    GPIOB->ODR = GPIOB->ODR | motorpos[i]<<12;
    }
}
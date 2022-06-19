#include "lift.h"

void liftInit(void){
    GPIO_InitTypeDef port;
    port.Pin= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    port.Mode = GPIO_MODE_OUTPUT_PP;
    port.Pull = GPIO_NOPULL;
    port.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &port);}
void liftUp(void){
    position=-1;
}
void liftDown(void){
    
    position=-1;

}
volatile uint8_t liftIsMoving(void){
    return position;
}

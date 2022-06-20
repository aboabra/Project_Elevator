#include "lift.h"

void liftInit(void){
    GPIO_InitTypeDef port;
    port.Pin= GPIO_PIN_9 | GPIO_PIN_11;
    port.Mode = GPIO_MODE_OUTPUT_PP;
    port.Pull = GPIO_NOPULL;
    port.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &port);
}
void liftUp(void){
    /*if(FLAGS.PWMMMovementON==FLAG_SET){
    REDLEDOFF;
    FLAGS.PWMMMovementON = FLAG_RESET;
    }
    if(FLAGS.PWMMMovementOFF==FLAG_SET){
    REDLEDON;
    FLAGS.PWMMMovementOFF = FLAG_RESET;*/
    //}
    position=1;
    ESTADOS=UP;
    
}
void liftDown(void){
    
    position=0;

}
volatile uint8_t liftIsMoving(void){
    uint8_t moving;
    if(position==-1)
    {
        moving=1;
    }
    else{
        moving=0;
    }
        return moving;
}

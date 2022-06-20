#include "main.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    if(position==0){
    timeStartMotor=currentms;
    ESTADOS = LIFTUP;
    position=-1;
    }
    if(position==1){
    timeStartMotor=currentms;
    ESTADOS = LIFTDN;
    position=-1;
    }
}
#include "main.h"

void LED_Init(void){
    GPIO_InitTypeDef port;
    __HAL_RCC_GPIOD_CLK_ENABLE();
    port.Pin= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    port.Mode = GPIO_MODE_OUTPUT_PP;
    port.Pull = GPIO_NOPULL;
    port.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &port);
}

void LED_Update(void){
    /*RED, GREEN AND BLUE LEDs (MOTOR MOVEMENT AND LIFT STATE)*/
    if(uwTick<=(timeStartMotor+5000)){
    if(ESTADOS==LIFTUP||ESTADOS==LIFTDN){
        BLUELEDOFF;
        GREENLEDOFF;
        if(FLAGS.PWMMMovementON==FLAG_SET){
        REDLEDOFF;
        FLAGS.PWMMMovementON = FLAG_RESET;
        }
        else if(FLAGS.PWMMMovementOFF==FLAG_SET){
        REDLEDON;
        FLAGS.PWMMMovementOFF = FLAG_RESET;
        }
    }
    }
    /*LIFT POSITION*/
    else if(ESTADOS==LIFTUP){
        ESTADOS=UP;
        GREENLEDON;
        BLUELEDOFF;
    }
    else if(ESTADOS==LIFTDN){
        ESTADOS=DOWN;
        GREENLEDOFF;
        BLUELEDON;
    }
    
    /*ORANGE LED (MOTOR DIRECTION)*/
    if(uwTick<=(timeStartMotor+5000)){
    /* DOWN */
    if(ESTADOS==LIFTDN){
    if(FLAGS.PWMMDirectionDNON==FLAG_SET){
    ORANGELEDOFF;
    FLAGS.PWMMDirectionDNON = FLAG_RESET;
    }
    if(FLAGS.PWMMDirectionDNOFF==FLAG_SET){
    ORANGELEDON;
    FLAGS.PWMMDirectionDNOFF = FLAG_RESET;
    }
    }
    else if(ESTADOS==LIFTUP){
    /* UP */
    if(FLAGS.PWMMDirectionUPON==FLAG_SET){
    ORANGELEDOFF;
    FLAGS.PWMMDirectionUPON = FLAG_RESET;
    }
    if(FLAGS.PWMMDirectionUPOFF==FLAG_SET){
    ORANGELEDON;
    FLAGS.PWMMDirectionUPOFF = FLAG_RESET;
    }
}
}
}
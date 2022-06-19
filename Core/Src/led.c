#include "main.h"

void LED_Init(void){
    GPIO_InitTypeDef port;
    port.Pin= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    port.Mode = GPIO_MODE_OUTPUT_PP;
    port.Pull = GPIO_NOPULL;
    port.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &port);
}

void LED_Update(void){
    /*RED LED (MOTOR MOVEMENT)*/
    if(FLAGS.PWMMMovementON==FLAG_SET){
    REDLEDOFF;
    FLAGS.PWMMMovementON = FLAG_RESET;
    }
    if(FLAGS.PWMMMovementOFF==FLAG_SET){
    REDLEDON;
    FLAGS.PWMMMovementOFF = FLAG_RESET;
    }
    /*ORANGE LED (MOTOR DIRECTION)*/
    /* DOWN */
    if(FLAGS.PWMMDirectionDNON==FLAG_SET){
    ORANGELEDOFF;
    FLAGS.PWMMDirectionDNON = FLAG_RESET;
    }
    if(FLAGS.PWMMDirectionDNOFF==FLAG_SET){
    ORANGELEDON;
    FLAGS.PWMMDirectionDNOFF = FLAG_RESET;
    }
    /* UP */
    if(FLAGS.PWMMDirectionUPON==FLAG_SET){
    ORANGELEDOFF;
    FLAGS.PWMMDirectionUPON = FLAG_RESET;
    }
    if(FLAGS.PWMMDirectionUPOFF==FLAG_SET){
    ORANGELEDON;
    FLAGS.PWMMDirectionUPOFF = FLAG_RESET;
    }
    /*BLUE AND GREEN LEDS (LIFT POSITION)*/
    
}
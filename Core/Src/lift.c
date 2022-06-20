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
     position=1;
    
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
void lift_Update(void){
    if(ESTADOS==DOWN){
        if(FLAGS.PWMSERVO0ON1==FLAG_SET){
        SERVO1ON;
        FLAGS.PWMSERVO0ON1 = FLAG_RESET;
        }
        else if(FLAGS.PWMSERVO0OFF1==FLAG_SET){
        SERVO1OFF;
        FLAGS.PWMSERVO0OFF1 = FLAG_RESET;
        }
    }
    else if(ESTADOS==UP){
        if(FLAGS.PWMSERVO0ON2==FLAG_SET){
        SERVO2ON;
        FLAGS.PWMSERVO0ON2 = FLAG_RESET;
        }
        else if(FLAGS.PWMSERVO0OFF2==FLAG_SET){
        SERVO2OFF;
        FLAGS.PWMSERVO0OFF2 = FLAG_RESET;
        }
    }
    else if(ESTADOS==LIFTUP){
        if(FLAGS.PWMSERVO180ON1==FLAG_SET){
        SERVO1ON;
        FLAGS.PWMSERVO180ON1 = FLAG_RESET;
        }
        else if(FLAGS.PWMSERVO180OFF1==FLAG_SET){
        SERVO1OFF;
        FLAGS.PWMSERVO180OFF1 = FLAG_RESET;
        }
    }
     else if(ESTADOS==LIFTDN){
        if(FLAGS.PWMSERVO180ON2==FLAG_SET){
        SERVO2ON;
        FLAGS.PWMSERVO180ON2 = FLAG_RESET;
        }
        else if(FLAGS.PWMSERVO180OFF2==FLAG_SET){
        SERVO2OFF;
        FLAGS.PWMSERVO180OFF2 = FLAG_RESET;
        }
    }

}


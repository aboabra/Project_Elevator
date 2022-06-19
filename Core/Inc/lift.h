#include "main.h"

#define SERVO1ON HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET)
#define BLUELEDON HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET)

#define GREENLEDOFF HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET)
#define ORANGELEDOFF HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET)

void liftInit(void);
void liftUp(void);
void liftDown(void);
volatile uint8_t liftIsMoving(void);
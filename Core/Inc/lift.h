#include "main.h"

#define SERVO1ON HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET)
#define SERVO2ON HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET)

#define SERVO1OFF HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET)
#define SERVO2OFF HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET)

void liftInit(void);
void liftUp(void);
void liftDown(void);
volatile uint8_t liftIsMoving(void);
void lift_Update(void);
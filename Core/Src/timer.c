#include "timer.h"

void HAL_SYSTICK_Callback(void)
{
   volatile uint32_t uwTick = HAL_GetTick();
    

    /* FLAGS FOR PWM OF MOTOR MOVEMENT*/

	if(!FLAGS.PWMMMovementON && !(uwTick % MMOVEMENTON) && (uwTick % MMOVEMENTOFF) )
		FLAGS.PWMMMovementON = FLAG_SET;
	if(!FLAGS.PWMMMovementOFF && !((uwTick % MMOVEMENTOFF)))
		FLAGS.PWMMMovementOFF = FLAG_SET;
    
    /* FLAGS FOR PWM OF MOTOR DIRECTION*/
    /* DOWN */
    if(!FLAGS.PWMMDirectionDNON && !(uwTick % MDIRECTIONDOWN) && (uwTick % MDIRECTIONOFF) )
		FLAGS.PWMMDirectionDNON = FLAG_SET;
    if(!FLAGS.PWMMDirectionDNOFF && !((uwTick % MDIRECTIONOFF)))
		FLAGS.PWMMDirectionDNOFF = FLAG_SET;

    /* UP */
    if(!FLAGS.PWMMDirectionUPON && !(uwTick % MDIRECTIONUP) && (uwTick % MDIRECTIONOFF))
		FLAGS.PWMMDirectionDNON = FLAG_SET;
    if(!FLAGS.PWMMDirectionDNOFF && !((uwTick % MDIRECTIONOFF)))
		FLAGS.PWMMDirectionDNOFF  = FLAG_SET;
}
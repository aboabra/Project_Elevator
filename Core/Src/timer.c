#include "timer.h"

void setFlag(void){
    volatile uint32_t uwTick = HAL_GetTick();
    currentms=uwTick;
    ticks+=(currentms-lastuwTick);
    if(ticks>=1000) ticks=0;
    /* FLAGS FOR PWM OF MOTOR MOVEMENT*/
    if(ESTADOS==LIFTUP||ESTADOS==LIFTDN){
	if(!FLAGS.PWMMMovementON && !(ticks % MMOVEMENTON) && (ticks % MMOVEMENTOFF) )
    {
		FLAGS.PWMMMovementON = FLAG_SET;
    }
	if(!FLAGS.PWMMMovementOFF && !((ticks % MMOVEMENTOFF)))
		FLAGS.PWMMMovementOFF = FLAG_SET;
    }

    /* FLAGS FOR PWM OF MOTOR DIRECTION*/
    /* DOWN */
    if(ESTADOS==LIFTDN){
    if(!FLAGS.PWMMDirectionDNON && !(ticks % MDIRECTIONDOWN) && (ticks % MDIRECTIONOFF) )
    {
		FLAGS.PWMMDirectionDNON = FLAG_SET;
    }
    if(!FLAGS.PWMMDirectionDNOFF && !(ticks % MDIRECTIONOFF))
    {
		FLAGS.PWMMDirectionDNOFF = FLAG_SET;
    }
}
    /* UP */
    if(ESTADOS==LIFTUP){
    if(!FLAGS.PWMMDirectionUPON && !(ticks % MDIRECTIONUP) && (ticks % MDIRECTIONOFF)&& (ticks % AVOIDERROR1)&& (ticks % AVOIDERROR2))
    {
		FLAGS.PWMMDirectionUPON = FLAG_SET;
    }
    if(!FLAGS.PWMMDirectionDNOFF && !((ticks % MDIRECTIONOFF)))
    {
		FLAGS.PWMMDirectionUPOFF  = FLAG_SET;
    }
}
}

void ServoON(void){
    

}
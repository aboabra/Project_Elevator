#include "timer.h"

void setFlag(void){
    volatile uint32_t uwTick = HAL_GetTick();
    currentms=uwTick;
    
    /* FLAGS FOR PWM OF MOTOR MOVEMENT*/
    if(ESTADOS==LIFTUP||ESTADOS==LIFTDN){
	if(!FLAGS.PWMMMovementON && !(uwTick % MMOVEMENTON) && (uwTick % MMOVEMENTOFF) )
    {
		FLAGS.PWMMMovementON = FLAG_SET;
    }
	if(!FLAGS.PWMMMovementOFF && !((uwTick % MMOVEMENTOFF)))
		FLAGS.PWMMMovementOFF = FLAG_SET;
    }

    /* FLAGS FOR PWM OF MOTOR DIRECTION*/
    /* DOWN */
    if(ESTADOS==LIFTDN){
    if(!FLAGS.PWMMDirectionDNON && !(uwTick % MDIRECTIONDOWN) && (uwTick % MDIRECTIONOFF) )
    {
		FLAGS.PWMMDirectionDNON = FLAG_SET;
    }
    if(!FLAGS.PWMMDirectionDNOFF && !(uwTick % MDIRECTIONOFF))
    {
		FLAGS.PWMMDirectionDNOFF = FLAG_SET;
    }
}
    /* UP */
    if(ESTADOS==LIFTUP){
    if(!FLAGS.PWMMDirectionUPON && !(uwTick % MDIRECTIONUP) && (uwTick % MDIRECTIONOFF))
    {
		FLAGS.PWMMDirectionDNON = FLAG_SET;
    }
    if(!FLAGS.PWMMDirectionDNOFF && !((uwTick % MDIRECTIONOFF)))
    {
		FLAGS.PWMMDirectionDNOFF  = FLAG_SET;
    }
}
}

void ServoON(void){
    

}
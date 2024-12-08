#include <Arduino.h>

/**
 * @brief             Non-blocking delay which is used like an if statement
 * 
 * @param duration_ms Duration of delay
 * @return true       Proceed with program
 * @return false      Do not proceed
 */
bool delay_nb( unsigned long duration_ms ) 
{
    static unsigned long last_time = 0;

    if( ( millis() - last_time ) >= duration_ms ) 
    {
        last_time = millis();  // last time is now what ever millis is when it does pass the delay duration value
        return true;
    }

    return false;
}

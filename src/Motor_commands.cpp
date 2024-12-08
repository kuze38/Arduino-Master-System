#include <Arduino.h>
#include <LoRa.h>
#include "Comms.h"
#include "Motor_commands.h"
#include "Delay_nb.h"

#define JOYSTICK_UPDATE_DELAY  500
#define LOWER_MEDIAN_VALUE     350 // lower limit for constraining movement
#define HIGHER_MEDIAN_VALUE    700 // higher limit for constraining movement
#define FIRST_DIRECTION_VALUE  800 // for going forward or left
#define SECOND_DIRECTION_VALUE 200 // for going backward or right

/**
 * @brief            Sends a message to slave depending on joystick movement
 * 
 * @param joystick_x Joystick direction along x axis
 * @param joystick_y Joystick direction along y axis
 */
void handle_joystick(int joystick_x, int joystick_y)
{
    if( !delay_nb( JOYSTICK_UPDATE_DELAY ) ) 
    {
        return; // EXIT
    }

    int x_value = analogRead( joystick_x );
    int y_value = analogRead( joystick_y );

    tMovement command;

    if ( ( x_value > LOWER_MEDIAN_VALUE ) && ( x_value < HIGHER_MEDIAN_VALUE ) && ( y_value > FIRST_DIRECTION_VALUE ) )      // forward
    {
        command = MOVEMENT_FORWARD;
    }
    else if ( ( x_value > LOWER_MEDIAN_VALUE ) && ( x_value < HIGHER_MEDIAN_VALUE ) && ( y_value < SECOND_DIRECTION_VALUE ) ) // backward
    {
        command = MOVEMENT_BACKWARD;
    }
    else if ( ( x_value < SECOND_DIRECTION_VALUE ) && ( y_value > LOWER_MEDIAN_VALUE ) && ( y_value < HIGHER_MEDIAN_VALUE ) ) // right
    {
        command = MOVEMENT_RIGHT;
    }
    else if ( ( x_value > FIRST_DIRECTION_VALUE ) && ( y_value > LOWER_MEDIAN_VALUE ) && ( y_value < HIGHER_MEDIAN_VALUE ) ) // left
    {
        command = MOVEMENT_LEFT;
    }
    else
    {
        return;
    }

    LoRa.beginPacket();
    LoRa.write( ( uint8_t )command );
    LoRa.endPacket();
}

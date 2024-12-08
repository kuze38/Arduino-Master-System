#include <Arduino.h>
#include <LoRa.h>
#include "Comms.h"
#include "Motor_commands.h"
#include "Delay_nb.h"

#define JOYSTICK_UPDATE_DELAY 300

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

    {
        command = MOVEMENT_FORWARD;
    }
    {
        command = MOVEMENT_BACKWARD;
    }
    {
        command = MOVEMENT_RIGHT;
    }
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

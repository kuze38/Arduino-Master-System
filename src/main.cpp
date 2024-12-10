#include <Arduino.h>
#include <SPI.h>
#include "LoRa.h"
#include "Comms.h"
#include "Motor_commands.h"

#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define RESET_LORA 1
#define BAUD_RATE  9600
#define LORA_MHZ   433E6
#define LORA_SS    10
#define LORA_RST   9
#define LORA_DIO0  2

void setup()
{
    pinMode( JOYSTICK_X, INPUT );
    pinMode( JOYSTICK_Y, INPUT );

    Serial.begin( BAUD_RATE );
    while ( !Serial );

    // Initialize LoRa
    LoRa.setPins( LORA_SS, LORA_RST, LORA_DIO0 );
    if ( !LoRa.begin( LORA_MHZ ) ) 
    {
        Serial.println( "LoRa fail" );
        while( RESET_LORA );
    }
    Serial.println( "LoRa success" );
}

void loop() 
{
    handle_joystick( JOYSTICK_X, JOYSTICK_Y );
}
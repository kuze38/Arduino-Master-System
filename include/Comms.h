#ifndef COMMS_H
#define COMMS_H

typedef enum {
    MOVEMENT_FORWARD = 0x2,
    MOVEMENT_BACKWARD = 0x3,
    MOVEMENT_RIGHT = 0x4,
    MOVEMENT_LEFT = 0x5,
    MOVEMENT_STOP = 0x6
} tMovement;

typedef enum {
    FUNCTION_ON = 0x7,
    FUNCTION_OFF = 0x8
} tFunction;

#endif // COMMS_H

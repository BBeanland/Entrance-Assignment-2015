#ifndef __QUADCOPTER_H__
#define __QUADCOPTER_H__

#include <stdint.h>

// get the orientation: 0 -> flat, (-)127 -> max tilt
int8_t getPitch(); // leaning forwards / backwards: positive -> forwards
int8_t getRoll(); // leaning right / left: positive -> right

// set the motor strength: 0 -> off, 255 -> max thrust
void setFR(uint8_t); // front right
void setFL(uint8_t); // front left
void setBR(uint8_t); // back right
void setBL(uint8_t); // back left

#endif

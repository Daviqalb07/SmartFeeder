/*
 * keypad.h
 *
 *  Created on: Feb 3, 2022
 *      Author: daviq
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include <stdint.h>
#include "LiquidCrystal.h"
void resetAllPinsB();
int readKeypad();
uint32_t getTimeFromKeypad(LiquidCrystal* lcd);

#endif /* INC_KEYPAD_H_ */

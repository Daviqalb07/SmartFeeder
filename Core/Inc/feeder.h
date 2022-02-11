/*
 * feeder.h
 *
 *  Created on: 10 de fev de 2022
 *      Author: daviq
 */

#ifndef INC_FEEDER_H_
#define INC_FEEDER_H_

#include <stdbool.h>
#include "stm32f103x6.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_gpio_ex.h"

typedef struct{
	bool empty;
	int quantity;
	int portion;

	GPIO_TypeDef* portEmptyLed;
	uint16_t pinEmptyLed;

	GPIO_TypeDef* portOnLed;
	uint16_t pinOnLed;
} Feeder;

void feederInit(Feeder* feeder, int quantity, GPIO_TypeDef* portOnLed, uint16_t pinOnLed, GPIO_TypeDef* portEmptyLed, uint16_t pinEmptyLed);
int getQuantity(Feeder* feeder);
bool isFeederEmpty(Feeder* feeder);
void feederOn(Feeder* feeder, bool* isFeederOn);
#endif /* INC_FEEDER_H_ */

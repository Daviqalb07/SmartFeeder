/*
 * feeder.c
 *
 *  Created on: 10 de fev de 2022
 *      Author: daviq
 */

#include "feeder.h"
#include "stdlib.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_gpio_ex.h"

void feederInit(Feeder* feeder, int quantity, GPIO_TypeDef* portOnLed, uint16_t pinOnLed, GPIO_TypeDef* portEmptyLed, uint16_t pinEmptyLed){
	feeder->quantity = quantity; // Quantidade de ração no reservatório
	feeder->portEmptyLed = portEmptyLed;
	feeder->pinEmptyLed = pinEmptyLed;
	feeder->portOnLed = portOnLed;
	feeder->pinOnLed = pinOnLed;
	feeder->portion = 50; // porção de 50 gramas
	if(quantity < feeder->portion)
		feeder->empty = true;
	else
		feeder->empty = false;
	isFeederEmpty(feeder);
	HAL_GPIO_WritePin(portOnLed, pinOnLed, GPIO_PIN_SET);
}

int getQuantity(Feeder* feeder){
	return feeder->quantity;
}

bool isFeederEmpty(Feeder* feeder){
	if(feeder->quantity < feeder->portion)
		feeder->empty = true;
	else
		feeder->empty = false;

	uint16_t pinState = (uint16_t)(!feeder->empty);
	HAL_GPIO_WritePin(feeder->portEmptyLed, feeder->pinEmptyLed, pinState);
	return feeder->empty;
}

void feederOn(Feeder* feeder, bool* isFeederOn){
	if(!isFeederEmpty(feeder)){
		HAL_GPIO_WritePin(feeder->portOnLed, feeder->pinOnLed, GPIO_PIN_RESET);
		feeder->quantity -= feeder->portion;
		*isFeederOn = true;
	}
}

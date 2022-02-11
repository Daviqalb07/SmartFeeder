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

/* feederInit
 * Inicializa o sistema do comedouro e os ponteiros para os LEDs de aviso
 *
 * @param: endereço para o feeder, quantidade inicial no reservatório, endereços
 * para portas e pinos dos LEDs FEEDER_ON e FEEDER_EMPTY
 *
 * @return: void
 * */

void feederInit(Feeder* feeder, int quantity, GPIO_TypeDef* portOnLed, uint16_t pinOnLed, GPIO_TypeDef* portEmptyLed, uint16_t pinEmptyLed){
	feeder->quantity = quantity; // Quantidade de ração no reservatório
	// LED para reservatório vazio
	feeder->portEmptyLed = portEmptyLed;
	feeder->pinEmptyLed = pinEmptyLed;
	// LED para acionamento do sistema
	feeder->portOnLed = portOnLed;
	feeder->pinOnLed = pinOnLed;
	// Porção default de 50 gramas
	feeder->portion = 50;

	if(quantity < feeder->portion)
		feeder->empty = true;
	else
		feeder->empty = false;
	isFeederEmpty(feeder); // Já aciona LED se vazio
	HAL_GPIO_WritePin(portOnLed, pinOnLed, GPIO_PIN_SET);
}

/* getQuantity
 * Retorna a quantidade contida no reservatório do comedouro
 *
 * @param: o feeder
 * @return: int
 * */
int getQuantity(Feeder* feeder){
	return feeder->quantity;
}

/* isFeederEmpty
 * Retorna true se o estoque do reservatório é contém menos que uma porção e
 * false, caso contrário.
 *
 * @param: o feeder
 * @return bool
 * */
bool isFeederEmpty(Feeder* feeder){
	if(feeder->quantity < feeder->portion)
		feeder->empty = true;
	else
		feeder->empty = false;

	uint16_t pinState = (uint16_t)(!feeder->empty);
	HAL_GPIO_WritePin(feeder->portEmptyLed, feeder->pinEmptyLed, pinState);
	return feeder->empty;
}

/* feederOn
 * Ativa o mecanismo para liberar ração no prato do pet.
 *
 * @param: o feeder, flag para sinalizar que o sistema foi ativado
 * @return: void
 * */
void feederOn(Feeder* feeder, bool* isFeederOn){
	if(!isFeederEmpty(feeder)){
		HAL_GPIO_WritePin(feeder->portOnLed, feeder->pinOnLed, GPIO_PIN_RESET);
		feeder->quantity -= feeder->portion; // Em virtude da limitação de não usar balnça real
		*isFeederOn = true;
	}
}

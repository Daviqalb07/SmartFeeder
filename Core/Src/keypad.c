#include "keypad.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_gpio_ex.h"
#include "LiquidCrystal.h"
#include <stdio.h>
#include <stdlib.h>

void resetAllPinsB(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
}


int readKeypad(){
	uint16_t columns[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2};
	uint16_t rows[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};

	for(int i=0 ; i < 4 ; i++){
		resetAllPinsB();
		HAL_GPIO_WritePin(GPIOB, rows[i], GPIO_PIN_SET);

		if(HAL_GPIO_ReadPin(GPIOB, columns[0])){
			if(i == 0)
				return 1;
			else if(i == 1)
				return 4;
			else if(i == 2)
				return 7;
		}
		else if(HAL_GPIO_ReadPin(GPIOB, columns[1])){
			if(i == 0)
				return 2;
			else if(i == 1)
				return 5;
			else if(i == 2)
				return 8;
			else if(i == 3)
				return 0;
		}
		else if(HAL_GPIO_ReadPin(GPIOB, columns[2])){
			if(i == 0)
				return 3;
			else if(i == 1)
				return 6;
			else if(i == 2)
				return 9;
			else if(i == 3)
				return 10; // Apertou "ENTER"
		}

	}
	return 11; // definido para indicar que não foi pressionado nada
}

uint32_t getTimeFromKeypad(LiquidCrystal* lcd){
	uint32_t time = 0;
	int minutos, segundos, key;
	char timeDisplay[20];

	while(1){
		key = readKeypad();
		minutos = (int)(time / 100); // Somente para imprimir na tela.
		segundos = time - minutos*100;

		sprintf(timeDisplay, "%02d:%02d", minutos, segundos);
		setCursor(lcd, 0, 3);
		print(lcd, timeDisplay);

		if(key == 10)
			break;
		if(key < 10){
			time = time*10 + (uint32_t)key;
			HAL_Delay(220); // Evita contar a leitura repetidas vezes
		}
		else{
			HAL_Delay(1000/30);
		}
	}
	resetAllPinsB();
	return (minutos*60 + segundos);
}

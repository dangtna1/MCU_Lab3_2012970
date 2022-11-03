/*
 * led_controller.c
 *
 *  Created on: Nov 1, 2022
 *      Author: tamqu
 */
#include "led_controller.h"
#include "main.h"
#include "software_timer.h"

//setTimer5(500);
//void led_control() {
////	if (timer4_flag == 1) {
////		if (timer5_flag != 1) {
////			setTimer4(500);
////			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
////			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
////			//todo
////		} else {
////
////		}
//	if (timer5_flag == 1) {
//		setTimer5(500);
//		HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
//		HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
//	}
//
//}

void enableLed7Seg1() {
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
}
void enableLed7Seg2() {
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
}
void enableLed7Seg3() {
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
}
void enableLed7Seg4() {
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
}

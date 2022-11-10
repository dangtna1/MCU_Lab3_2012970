/*
 * led_controller.c
 *
 *  Created on: Nov 1, 2022
 *      Author: tamqu
 */
#include "led_controller.h"
#include "main.h"
#include "software_timer.h"

uint8_t segmentNumber[10] = {
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x67   // 9
};

void display7SEG_1(uint8_t number){
	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ((number>>0)&0x01)^0x01);
	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ((number>>1)&0x01)^0x01);
	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ((number>>2)&0x01)^0x01);
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ((number>>3)&0x01)^0x01);
	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ((number>>4)&0x01)^0x01);
	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ((number>>5)&0x01)^0x01);
	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ((number>>6)&0x01)^0x01);
}
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

void initTrafficLight1() {
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}

void initTrafficLight2() {
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}
void setTrafficRed1() {
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}
void setTrafficRed2() {
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void setTrafficGreen1() {
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}
void setTrafficGreen2() {
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void setTrafficYellow1() {
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
}

void setTrafficYellow2() {
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
}

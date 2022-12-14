/*
 * input_processing.c
 *
 *  Created on: Oct 31, 2022
 *      Author: tamqu
 */
#include "input_processing.h"
#include "main.h"
#include "input_reading.h"
#include "software_timer.h"
#include "fsm_automatic.h"
#include "led_controller.h"
#include "global.h"

enum ButtonState { NORMAL, SET_TIME_RED, SET_TIME_YELLOW, SET_TIME_GREEN } ;
enum ButtonState buttonState = NORMAL ;
int counterForRed = 0;
int counterForGreen = 0;
int counterForYellow = 0;
int flag = 0;

int led7SegScanning = 1;
void fsm_for_input_processing(void){
	switch(buttonState){
		case NORMAL: //Mode 1
			//các led đơn và led7seg sáng bthg
			countDownGreen1 = 0;
			countDownGreen2 = 0;
			countDownRed1 = 0;
			countDownRed2 = 0;
			countDownYellow1 = 0;
			countDownYellow2 = 0;
			LANE1_STATUS = LANE1_INIT;
			LANE2_STATUS = LANE2_INIT;
			while(1) {
				fsm_automatic_run1();
				fsm_automatic_run2();
				if(isButton1Press() == 1) {
					buttonState = SET_TIME_RED;
					timer1_flag = 1;
					timer2_flag = 1; //for scanning led7seg
					setTrafficRed1();
					setTrafficRed2();
					flag = 0; //reset
					break;
				}
			}
			break;
		case SET_TIME_RED: //Mode 2
			//điều chỉnh duration cho led red
			while (flag == 0) {
				if (timer1_flag == 1) {
					setTimer1(500);
					HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
					HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
				}
				if (timer2_flag == 1) {
					setTimer2(250);
					switch(led7SegScanning) {
						case 1:
							enableLed7Seg1();
							display7SEG_1(segmentNumber[0]);
							led7SegScanning = 2;
							break;
						case 2:
							enableLed7Seg2();
							display7SEG_1(segmentNumber[2]);
							led7SegScanning = 3;
							break;
						case 3:
							enableLed7Seg3();
							display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]+counterForRed)]);
							led7SegScanning = 4;
							break;
						case 4:
							enableLed7Seg4();
							display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]+counterForRed)]);
							led7SegScanning = 1;
							break;
					}
				}
				if (isButton2Press() == 1) counterForRed++;

				if(isButton3Press() == 1) {
					led_duration[0] += counterForRed;
					if (led_duration[0] > 99) led_duration[0] = 1;
					counterForRed = 0; //reset
				}
				if(isButton1Press() == 1) {
					buttonState = SET_TIME_YELLOW;
					timer1_flag = 1;
					timer2_flag = 1;
					setTrafficYellow1();
					setTrafficYellow2();
					flag = 1;
					led7SegScanning = 1; //reset
					counterForRed = 0; //rest
				}
			}
			break;
		case SET_TIME_YELLOW: //Mode 3
			//todo
			flag = 0;
			while (flag == 0) {
				if (timer1_flag == 1) {
					setTimer1(500);
					HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
					HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				}
				if (timer2_flag == 1) {
					setTimer2(250);
					switch(led7SegScanning) {
						case 1:
							enableLed7Seg1();
							display7SEG_1(segmentNumber[0]);
							led7SegScanning = 2;
							break;
						case 2:
							enableLed7Seg2();
							display7SEG_1(segmentNumber[3]);
							led7SegScanning = 3;
							break;
						case 3:
							enableLed7Seg3();
							display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]+counterForYellow)]);
							led7SegScanning = 4;
							break;
						case 4:
							enableLed7Seg4();
							display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]+counterForYellow)]);
							led7SegScanning = 1;
							break;
					}
				}
				if (isButton2Press() == 1) counterForYellow++;

				if(isButton3Press() == 1) {
					led_duration[1] += counterForYellow;
					if (led_duration[1] > 99) led_duration[1] = 1;
					counterForYellow = 0; //reset
				}
				if(isButton1Press() == 1) {
					buttonState = SET_TIME_GREEN;
					timer1_flag = 1;
					timer2_flag = 1;
					setTrafficGreen1();
					setTrafficGreen2();
					flag = 1;
					led7SegScanning = 1; //reset
					counterForYellow = 0; //reset
				}
			}
			break;
		case SET_TIME_GREEN: //Mode 4
			flag = 0;
			while (flag == 0) {
				if (timer1_flag == 1) {
					setTimer1(500);
					HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
					HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				}
				if (timer2_flag == 1) {
					setTimer2(250);
					switch(led7SegScanning) {
						case 1:
							enableLed7Seg1();
							display7SEG_1(segmentNumber[0]);
							led7SegScanning = 2;
							break;
						case 2:
							enableLed7Seg2();
							display7SEG_1(segmentNumber[4]);
							led7SegScanning = 3;
							break;
						case 3:
							enableLed7Seg3();
							display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]+counterForGreen)]);
							led7SegScanning = 4;
							break;
						case 4:
							enableLed7Seg4();
							display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]+counterForGreen)]);
							led7SegScanning = 1;
							break;
					}
				}
				if (isButton2Press() == 1) counterForGreen++;

				if(isButton3Press() == 1) {
					led_duration[2] += counterForGreen;
					if (led_duration[2] > 99) led_duration[2] = 1;
					counterForGreen = 0; //reset
				}
				if(isButton1Press() == 1) {
					buttonState = NORMAL;
					flag = 1;
					led7SegScanning = 1; //reset
					counterForGreen = 0; //reset
				}
			}
			break;
	}
}




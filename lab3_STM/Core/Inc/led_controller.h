/*
 * led_controller.h
 *
 *  Created on: Nov 1, 2022
 *      Author: tamqu
 */

#ifndef INC_LED_CONTROLLER_H_
#define INC_LED_CONTROLLER_H_
#include "main.h"

extern uint8_t segmentNumber[10];
void enableLed7Seg1();
void enableLed7Seg2();
void enableLed7Seg3();
void enableLed7Seg4();

void setTrafficGreen1();
void setTrafficRed1();
void setTrafficYellow1();
void setTrafficGreen2();
void setTrafficRed2();
void setTrafficYellow2();
void initTrafficLight1();
void initTrafficLight2();


#endif /* INC_LED_CONTROLLER_H_ */

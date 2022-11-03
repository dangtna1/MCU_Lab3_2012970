/*
 * fsm_automatic.h
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

extern int led_duration[3];
extern int led7SegState;
extern int led7segState2;
extern uint8_t segmentNumber[10];

void fsm_automatic_run1();
//void fsm_automatic_run1();
int getTimeAtIndex0(int time);
int getTimeAtIndex1(int time);

//void setTempDurationAt0(){
//	temp_duration[0] =
//}

#endif /* INC_FSM_AUTOMATIC_H_ */

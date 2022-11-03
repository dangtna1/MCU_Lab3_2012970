/*
 * global.h
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"
#include "main.h"

#define LANE1_INIT 1
//#define LANE1_RED0 2
//#define LANE1_RED1 3
#define LANE1_RED 2
#define LANE1_GREEN 3
#define LANE1_YELLOW 4

#define LANE2_INIT 11
#define LANE2_RED 12
#define LANE2_GREEN 13
#define LANE2_YELLOW 14

extern int LANE1_STATUS;
extern int LANE2_STATUS;
extern int countDownRed1;
extern int countDownYellow1;
extern int countDownGreen1;

extern int countDownRed2;
extern int countDownYellow2;
extern int countDownGreen2;

void setTrafficGreen1();
void setTrafficRed1();
void setTrafficYellow1();
void setTrafficGreen2();
void setTrafficRed2();
void setTrafficYellow2();
void initTrafficLight1();
void initTrafficLight2();

#endif /* INC_GLOBAL_H_ */

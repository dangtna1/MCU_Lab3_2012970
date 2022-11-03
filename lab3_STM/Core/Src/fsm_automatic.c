/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */
#include "fsm_automatic.h"
#include "led_controller.h"

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

//}
int getTimeAtIndex0(int time) {
	int temp = time/10;
	return temp;
}
int getTimeAtIndex1(int time) {
	return time%10;
}


int led_duration[3] = {5, 2, 3}; //red, yellow, green
int led7SegState = 1;
int led7SegState2 = 1;


//void fsm_automatic_run1() {
////	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
////	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//	switch(LANE1_STATUS) { //for lane 1
//		case LANE1_INIT:
//			initTrafficLight1();
//			LANE1_STATUS = LANE1_RED0;
//			setTimer1(led_duration[2]*1000); //
//			timer4_flag = 1;
//			led7SegState = 1;
////			setTimer3(250);
//			break;
//		case LANE1_RED0:
//			setTrafficRed1();
//			setTrafficGreen2();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					//todo
//
////					if (timer4_flag == 1) {
//						enableLed7Seg1();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed1)]);
//						setTimer4(250);
//						led7SegState = 2;
////					}
//					break;
//				case 2:
//					//todo
////					if (timer4_flag == 1) {
//						enableLed7Seg2();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed1)]);
//						setTimer4(250);
//						led7SegState = 3;
////					}
//					break;
//				case 3:
////					if (timer4_flag == 1) {
//						enableLed7Seg3();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen2)]);
//						setTimer4(250);
//						led7SegState = 4;
////					}
//					break;
//				case 4:
//					//todo
////					if (timer4_flag == 1) {
//						enableLed7Seg4();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen2)]);
//						countDownRed1++;
//						countDownGreen2++;
//						setTimer4(250);
//						led7SegState = 1;
////					}
//					break;
//				}
//				default:
//					break;
//			}
//			if(timer1_flag == 1) {
//				setTimer1(led_duration[1]*1000); //
//				LANE1_STATUS = LANE1_RED1;
//				countDownGreen2 = 0; //reset
//				timer4_flag = 1;
//				led7SegState = 1; //
//				setTimer3(500);
//			}
//			break;
//
//		case LANE1_RED1:
//			setTrafficYellow2();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					//todo
//						enableLed7Seg1();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed1)]);
//						setTimer4(250);
//						led7SegState = 2;
//					break;
//				case 2:
//					//todo
//						enableLed7Seg2();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed1)]);
//						setTimer4(250);
//						led7SegState = 3;
//					break;
//				case 3:
//						enableLed7Seg3();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow2)]);
//						setTimer4(250);
//						led7SegState = 4;
//					break;
//				case 4:
//					//todo
//						enableLed7Seg4();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownYellow2)]);
//						countDownRed1++;
//						countDownYellow2++;
//						setTimer4(250);
//						led7SegState = 1;
//					break;
//				}
//			}
//			if(timer1_flag == 1) {
//				setTimer1(led_duration[2]*1000); //
//				LANE1_STATUS = LANE1_GREEN;
//				countDownRed1 = 0; //reset
//				countDownYellow2 = 0; //reset
//				timer4_flag = 1;
//				led7SegState = 1;//
//				setTimer3(500);
//			}
//			break;
//
//		case LANE1_GREEN:
//			setTrafficGreen1();
//			setTrafficRed2();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					//todo
//						enableLed7Seg1();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen1)]);
//						setTimer4(250);
//						led7SegState = 2;
//					break;
//				case 2:
//					//todo
//						enableLed7Seg2();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen1)]);
//						setTimer4(250);
//						led7SegState = 3;
//					break;
//				case 3:
//						enableLed7Seg3();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed2)]);
//						setTimer4(250);
//						led7SegState = 4;
//					break;
//				case 4:
//					//todo
//						enableLed7Seg4();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed2)]);
//						countDownGreen1++;
//						countDownRed2++;
//						setTimer4(250);
//						led7SegState = 1;
//					break;
//				}
//			}
//
//			if(timer1_flag == 1) {
//				setTimer1(led_duration[1]*1000); //
//				LANE1_STATUS = LANE1_YELLOW;
//				countDownGreen1 = 0; //reset
//				timer4_flag = 1;
//				led7SegState = 1;//
//				setTimer3(500);
//			}
//			break;
//		case LANE1_YELLOW:
//			setTrafficYellow1();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					//todo
//						enableLed7Seg1();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow1)]);
//						setTimer4(250);
//						led7SegState = 2;
//					break;
//				case 2:
//					//todo
//						enableLed7Seg2();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownGreen1)]);
//						setTimer4(250);
//						led7SegState = 3;
//					break;
//				case 3:
//						enableLed7Seg3();
//						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed2)]);
//						setTimer4(250);
//						led7SegState = 4;
//					break;
//				case 4:
//					//todo
//						enableLed7Seg4();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed2)]);
//						countDownYellow1++;
//						countDownRed2++;
//						setTimer4(250);
//						led7SegState = 1;
//					break;
//				}
//			}
//
//			if(timer1_flag == 1) {
//				setTimer1(led_duration[2]*1000); //
//				LANE1_STATUS = LANE1_RED0;
//				countDownYellow1 = 0; //reset
//				countDownRed2 = 0; //reset
//				timer4_flag = 1;
//				setTimer3(500);
//				led7SegState = 1;//
//			}
//			break;
//	}
//}

void fsm_automatic_run1() {
	switch(LANE1_STATUS) { //for lane 1
		case LANE1_INIT:
			initTrafficLight1();
			LANE1_STATUS = LANE1_RED;
			setTimer1(led_duration[0]*1000); //
			timer4_flag = 1;
			led7SegState = 1;
			break;
		case LANE1_RED:
			setTrafficRed1();

			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg1();
						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed1)]);
						setTimer4(250);
						led7SegState = 2;
//					}
					break;
				case 2:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg2();
						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed1)]);
						setTimer4(250);
						led7SegState = 3;
//					}
					break;
				case 3:
//					if (timer4_flag == 1) {
						enableLed7Seg3();
						setTimer4(250);
						led7SegState = 4;
//					}
					break;
				case 4:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg4();
						countDownRed1++;
						setTimer4(250);
						led7SegState = 1;
//					}
					break;
				}
				default:
					break;
			}

//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					enableLed7Seg1();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed1)]);
//					setTimer4(250);
//					led7SegState = 2;
//					break;
//				case 2:
//					enableLed7Seg2();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed1)]);
//					setTimer4(750);
//					led7SegState = 1;
//					countDownRed1++;
//					break;
//				default:
//					break;
//				}
//			}
			if(timer1_flag == 1) {
				setTimer1(led_duration[2]*1000); //
				LANE1_STATUS = LANE1_GREEN;
				countDownRed1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1; //
//				setTimer3(500);
			}
			break;
		case LANE1_GREEN:
			setTrafficGreen1();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					enableLed7Seg1();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen1)]);
//					setTimer4(250);
//					led7SegState = 2;
//					break;
//				case 2:
//					enableLed7Seg2();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen1)]);
//					setTimer4(750);
//					countDownGreen1++;
//					led7SegState = 1;
//					break;
//				}
//			}


			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg1();
						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen1)]);
						setTimer4(250);
						led7SegState = 2;
//					}
					break;
				case 2:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg2();
						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen1)]);
						setTimer4(250);
						led7SegState = 3;
//					}
					break;
				case 3:
//					if (timer4_flag == 1) {
//						enableLed7Seg3();
						setTimer4(250);
						led7SegState = 4;
//					}
					break;
				case 4:
					//todo
//					if (timer4_flag == 1) {
//						enableLed7Seg4();
						countDownGreen1++;
						setTimer4(250);
						led7SegState = 1;
//					}
					break;
				}
			}


			if(timer1_flag == 1) {
				setTimer1(led_duration[1]*1000); //
				LANE1_STATUS = LANE1_YELLOW;
				countDownGreen1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1;//
//				setTimer3(500);
			}
			break;

		case LANE1_YELLOW:
			setTrafficYellow1();
//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					enableLed7Seg1();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow1)]);
//					setTimer4(250);
//					led7SegState = 2;
//					break;
//				case 2:
//						enableLed7Seg2();
//						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownYellow1)]);
//						setTimer4(750);
//						countDownYellow1++;
//						led7SegState = 1;
//					break;
//				}
//			}


			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg1();
						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow1)]);
						setTimer4(250);
						led7SegState = 2;
//					}
					break;
				case 2:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg2();
						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownYellow1)]);
						setTimer4(250);
						led7SegState = 3;
//					}
					break;
				case 3:
//					if (timer4_flag == 1) {
						enableLed7Seg3();
						setTimer4(250);
						led7SegState = 4;
//					}
					break;
				case 4:
					//todo
//					if (timer4_flag == 1) {
						enableLed7Seg4();
						countDownYellow1++;
						setTimer4(250);
						led7SegState = 1;
//					}
					break;
				}
			}


			if(timer1_flag == 1) {
				setTimer1(led_duration[0]*1000); //
				LANE1_STATUS = LANE1_RED;
				countDownYellow1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1;//
//				setTimer3(500);
			}
			break;
	}
}

void fsm_automatic_run2() {
	switch(LANE2_STATUS) { //for lane 2
		case LANE2_INIT:
			initTrafficLight2();
			LANE2_STATUS = LANE2_GREEN;
			setTimer2(led_duration[2]*1000);
			timer3_flag = 1; //
			led7SegState2 = 1;
			break;
		case LANE2_RED:
			setTrafficRed2();
//			if (timer3_flag == 1) {
//				switch(led7SegState2) {
//				case 1:
//					enableLed7Seg3();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed2)]);
//					setTimer3(250);
//					led7SegState2 = 2;
//					break;
//				case 2:
//					enableLed7Seg4();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed2)]);
//					setTimer3(750);
//					led7SegState2 = 1;
//					countDownRed2++;
//					break;
//				default:
//					break;
//				}
//			}
			if (timer3_flag == 1) {
				switch(led7SegState2) {
				case 1:
					//todo
									enableLed7Seg1();
						setTimer3(250);
						led7SegState2 = 2;
					break;
				case 2:
					//todo
									enableLed7Seg2();
						setTimer3(250);
						led7SegState2 = 3;
					break;
				case 3:
						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed2)]);
						enableLed7Seg3();
						setTimer3(250);
						led7SegState2 = 4;
					break;
				case 4:
					//todo
						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed2)]);
						enableLed7Seg4();
						countDownRed2++;
						setTimer3(250);
						led7SegState2 = 1;
					break;
				}
			}
			if(timer2_flag == 1) {
				setTimer2(led_duration[2]*1000);
				LANE2_STATUS = LANE2_GREEN;
				countDownRed2 = 0; //reset
				led7SegState2 = 1; //
//				setTimer3(750);
				timer3_flag = 1;
			}
			break;
		case LANE2_GREEN:
			setTrafficGreen2();
//			if (timer3_flag == 1) {
//				switch(led7SegState2) {
//				case 1:
//					enableLed7Seg3();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen2)]);
//					setTimer3(250);
//					led7SegState2 = 2;
//					break;
//				case 2:
//					enableLed7Seg4();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen2)]);
//					setTimer3(750);
//					countDownGreen2++;
//					led7SegState2 = 1;
//					break;
//				}
//			}


						if (timer3_flag == 1) {
							switch(led7SegState2) {
							case 1:
								//todo
									enableLed7Seg1();
									setTimer3(250);
									led7SegState2 = 2;
								break;
							case 2:
								//todo
									enableLed7Seg2();
									setTimer3(250);
									led7SegState2 = 3;
								break;
							case 3:
									display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[2]-countDownGreen2)]);
									enableLed7Seg3();
									setTimer3(250);
									led7SegState2 = 4;
								break;
							case 4:
								//todo
									display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[2]-countDownGreen2)]);
									enableLed7Seg4();
									countDownGreen2++;
									setTimer3(250);
									led7SegState2 = 1;
								break;
							}
						}



			if(timer2_flag == 1) {
				setTimer2(led_duration[1]*1000); //
				LANE2_STATUS = LANE2_YELLOW;
				countDownGreen2 = 0; //reset
				led7SegState2 = 1;//
//				setTimer3(750);
				timer3_flag = 1;
			}
			break;

		case LANE2_YELLOW:
			setTrafficYellow2();
//			if (timer3_flag == 1) {
//				switch(led7SegState2) {
//				case 1:
//					enableLed7Seg3();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow2)]);
//					setTimer3(250);
//					led7SegState2 = 2;
//					break;
//				case 2:
//					enableLed7Seg4();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownYellow2)]);
//					setTimer3(750);
//					countDownYellow2++;
//					led7SegState2 = 1;
//					break;
//				}
//			}

			if (timer3_flag == 1) {
				switch(led7SegState2) {
				case 1:
					//todo
									enableLed7Seg1();
						setTimer3(250);
						led7SegState2 = 2;
					break;
				case 2:
					//todo
									enableLed7Seg2();
						setTimer3(250);
						led7SegState2 = 3;
					break;
				case 3:
						display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[1]-countDownYellow2)]);
						enableLed7Seg3();
						setTimer3(250);
						led7SegState2 = 4;
					break;
				case 4:
					//todo
						display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[1]-countDownYellow2)]);
						enableLed7Seg4();
						countDownYellow2++;
						setTimer3(250);
						led7SegState2 = 1;
					break;
				}
			}

			if(timer2_flag == 1) {
				setTimer2(led_duration[0]*1000);
				LANE2_STATUS = LANE2_RED;
				countDownYellow2 = 0; //reset
				led7SegState2 = 1;//
//				setTimer3(750);
				timer3_flag = 1;
			}
			break;
	}
}
//void fsm_automatic_run2() {
//	switch(LANE2_STATUS) { //for lane 2
//		case LANE2_INIT:
//			initTrafficLight2();
//			LANE2_STATUS = LANE2_GREEN;
//			setTimer2(led_duration[2]*1000);
//
//			timer4_flag = 1;
//						setTimer3(500);
//
//			break;
//		case LANE2_RED:
//			setTrafficRed2();
//
//
//
//
//			if (timer4_flag == 1) {
//							if (timer3_flag != 1) {
//								setTimer4(500);
//								display7SEG_2(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed)]);
//							} else {
//								setTimer4(500);
//								setTimer3(1000);
//								display7SEG_2(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed)]);
//								countDownRed++;
//							}
//						}
//
//
//			if(timer2_flag == 1) {
//				setTimer2(led_duration[2]*1000);
//				LANE2_STATUS = LANE2_GREEN;
//			}
//			break;
//		case LANE2_GREEN:
//			setTrafficGreen2();
//			if(timer2_flag == 1) {
//				setTimer2(led_duration[1]*1000);
//				LANE2_STATUS = LANE2_YELLOW;
//
//				timer4_flag = 1;
//										setTimer3(500);
//			}
//			break;
//		case LANE2_YELLOW:
//			setTrafficYellow2();
//			if(timer2_flag == 1) {
//				setTimer2(led_duration[0]*1000);
//				LANE2_STATUS = LANE2_RED;
//
//				timer4_flag = 1;
//										setTimer3(500);
//			}
//			break;
//	}
//}


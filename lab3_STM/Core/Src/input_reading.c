/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tamqu
 */
#include "input_reading.h"
#include "main.h"

//#define NO_OF_BUTTONS 3
//#define DURATION_FOR_AUTO_INCREASING 100
////#define DURATION_FOR_AUTO_INCREASING_Every_01ms 100
//
//#define BUTTON_IS_PRESSED GPIO_PIN_RESET
//#define BUTTON_IS_RELEASED GPIO_PIN_SET
//
//static GPIO_PinState buttonBuffer[NO_OF_BUTTONS] ={GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET};
//
//
//static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
//static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
//
//static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
//static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
//
//void button_reading(void) {
//	for (char i=0; i<NO_OF_BUTTONS; i++) {
//		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
//		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port , BUTTON1_Pin) ;
//		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
//			buttonBuffer [ i ] = debounceButtonBuffer1 [ i ];
//			if ( buttonBuffer [ i ] == BUTTON_IS_PRESSED ) {
//				if ( counterForButtonPress1s [ i ] < DURATION_FOR_AUTO_INCREASING ) {
//					counterForButtonPress1s [ i ]++;
//				} else {
//					flagForButtonPress1s [ i ] = 1;
//					//todo
//				}
//			}
//		} else {
//			counterForButtonPress1s [ i ] = 0;
//			flagForButtonPress1s [ i ] = 0;
//		}
//	}
//}
//
//unsigned char is_button_pressed ( uint8_t index ) {
////	if ( index >= NO_OF_BUTTONS || buttonBuffer [ index ] != BUTTON_IS_PRESSED) return 0;
////	buttonBuffer[index] = BUTTON_IS_RELEASED; //reset flag
////	return 1;
//	if ( index >= NO_OF_BUTTONS ) return 0;
//		return ( buttonBuffer[ index ] == BUTTON_IS_PRESSED) ;
////	return 0;
//}
//
//unsigned char is_button_pressed_1s ( unsigned char index ) {
//	if ( index >= NO_OF_BUTTONS ) return 0xff;
//	return ( flagForButtonPress1s [ index ] == 1) ;
//}
//int KeyReg0 = NORMAL_STATE;
//int KeyReg1 = NORMAL_STATE;
//int KeyReg2 = NORMAL_STATE;
//int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Press() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Press() {
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Press() {
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}
//void subKeyProcess(){
//	//todo
//	//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//	button1_flag = 1;
//	button2_flag = 1;
//	button3_flag = 1;
//}
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
void getKeyInput(){

  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;
      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 200;
        button1_flag = 1;
      }
    } else{
    	TimeOutForKeyPress--;

		if (TimeOutForKeyPress == 0){
			if (KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				button1_flag = 1;
			 }
//			KeyReg3 = NORMAL_STATE; // nếu không cần xử lý nhấn đè
		}
    }
  }
}
	int KeyReg02 = NORMAL_STATE;
	int KeyReg12 = NORMAL_STATE;
	int KeyReg22 = NORMAL_STATE;
	int KeyReg32 = NORMAL_STATE;
void getKeyInput2(){

  KeyReg22 = KeyReg12;
  KeyReg12 = KeyReg02;
  KeyReg02 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
  if ((KeyReg12 == KeyReg02) && (KeyReg12 == KeyReg22)){
    if (KeyReg22 != KeyReg32){
      KeyReg32 = KeyReg22;
      if (KeyReg32 == PRESSED_STATE){
        TimeOutForKeyPress = 200;
        button2_flag = 1;
      }
    } else{
    	TimeOutForKeyPress--;

		if (TimeOutForKeyPress == 0){
			if (KeyReg32 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				button2_flag = 1;
			 }
//			KeyReg3 = NORMAL_STATE; // nếu không cần xử lý nhấn đè
		}
    }
  }
}
	int KeyReg03 = NORMAL_STATE;
	int KeyReg13 = NORMAL_STATE;
	int KeyReg23 = NORMAL_STATE;
	int KeyReg33 = NORMAL_STATE;
void getKeyInput3(){

  KeyReg23 = KeyReg13;
  KeyReg13 = KeyReg03;
  KeyReg03 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
  if ((KeyReg13 == KeyReg03) && (KeyReg13 == KeyReg23)){
    if (KeyReg23 != KeyReg33){
      KeyReg33 = KeyReg23;
      if (KeyReg33 == PRESSED_STATE){
        TimeOutForKeyPress = 200;
        button3_flag = 1;
      }
    } else{
    	TimeOutForKeyPress--;

		if (TimeOutForKeyPress == 0){
			if (KeyReg33 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				button3_flag = 1;
			 }
//			KeyReg3 = NORMAL_STATE; // nếu không cần xử lý nhấn đè
		}
    }
  }
}


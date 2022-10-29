/*
 * button.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();
void getKeyInput();

#endif /* INC_BUTTON_H_ */

/*
 * Led_Display.h
 *
 *  Created on: Oct 25, 2022
 *      Author: ADMIN
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_


void Display_Init();
void Display_Led_Red1();
void Display_Led_Green1();
void Display_Led_Yellow1();

void Display_Led_Red2();
void Display_Led_Green2();
void Display_Led_Yellow2();

void display7SEG(int num);

extern int led_buffer[4];
void updateClockBuffer();
void Run_7SEG();

#endif /* INC_DISPLAY_H_ */

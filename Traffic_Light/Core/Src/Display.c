/*
 * Display.c
 *
 *  Created on: Oct 25, 2022
 *      Author: ADMIN
 */

#include "Display.h"
#include "main.h"
#include "global.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {0, 0, 0, 0};

void Display_Init(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
}

void Display_Led_Red1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
}
void Display_Led_Green1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
}
void Display_Led_Yellow1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
}

void Display_Led_Red2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
}
void Display_Led_Green2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
}
void Display_Led_Yellow2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
}


void display7SEG(int num){
	//outputs: SEG7 -> SEG0
	//outputs with value of 0 (RESET) will be turn on
	//outputs with value of 1 (SET) will be turn off
	if (num == 0){ //100 0000
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin
								|SEG3_Pin|SEG4_Pin|SEG5_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 1){ //111 1001
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin
								|SEG5_Pin|SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 2){ //010 0100
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG3_Pin
								|SEG4_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, GPIO_PIN_SET);
	}
	else if (num == 3){ //011 0000
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin
								|SEG3_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin|SEG5_Pin, GPIO_PIN_SET);
	}
	else if (num == 4){ //001 1001
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG2_Pin|SEG5_Pin
								|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, GPIO_PIN_SET);
	}
	else if (num == 5){ //001 0010
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin
								|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, GPIO_PIN_SET);
	}
	else if (num == 6){ //000 0010
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG2_Pin|SEG3_Pin
								|SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
	}
	else if (num == 7){ //111 1000
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin
								|SEG6_Pin, GPIO_PIN_SET);
	}
	else if (num == 8){ //000 0000
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin
								|SEG3_Pin|SEG4_Pin|SEG5_Pin
								|SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (num == 9){ //001 0000
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin
								|SEG3_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
	}
}


void update7SEG(int index){
	switch (index){
		case 0:
			//turn on first 7seg led only
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break;
		case 1:
			//turn on second 7seg led only
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break;
		case 2:
			//turn on third 7seg led only
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break;
		case 3:
			//turn on fourth 7seg led only
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
	//display number according to led_buffer and index
	display7SEG(led_buffer[index]);
}

void updateClockBuffer(int Clock1, int Clock2){
	led_buffer[0] = Clock1 / 10;
	led_buffer[1] = Clock1 % 10;
	led_buffer[2] = Clock2 / 10;
	led_buffer[3] = Clock2 % 10;
}

int status_time1 = 0;
int status_time2 = 0;
int time1 = 0;//don vi s
int time2 = 0;//don vi s

void Run_7SEG(){
	if(status_col==MAN_RED || status_col==MAN_GREEN || status_col==MAN_YELLOW){
		time1 = Time_Auto_Red/1000;//don vi s
		time2 = Time_Auto_Green/1000;//don vi s
	}
	// for normal states
	if(status_col!=MAN_RED && status_col!=MAN_GREEN && status_col!=MAN_YELLOW){
		if(time1<=0){
			if(status_time1==0) {
				time1=Time_Auto_Red/1000;
			}
			else if(status_time1==1 ){
				time1=Time_Auto_Green/1000;
			}
			else if(status_time1==2 ){
				time1=Time_Auto_Yellow/1000;
			}
			status_time1 = (status_time1+1)%3;
		}
		if(time2<=0){
			if(status_time2==0 ) {
				time2=Time_Auto_Green/1000;
			}
			else if(status_time2==1){
				time2=Time_Auto_Yellow/1000;
			}
			else if(status_time2==2){
				time2=Time_Auto_Red/1000;
			}
			status_time2 = (status_time2+1)%3;
		}
		if(timer2_flag==1){
			setTimer2(1000);

			updateClockBuffer(time1,time2);
			time1--;
			time2--;
		}
	}


	if (timer3_flag == 1){
		//set timer for 1Hz frequency
		setTimer3(250);
		//updated index_led to stay in valid range, which is from 0 to 3
		index_led %= MAX_LED;
		//update 7seg leds
		update7SEG(index_led++);
	}
}

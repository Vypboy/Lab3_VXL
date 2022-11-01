/*
 * fsm_automatic.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#include "global.h"
#include "fsm_automatic.h"
#include "Display.h"

void fsm_automatic_run(){
	//quan ly den tin hieu hang doc
	//cac mode duoc hien thuc tren den tin hieu hang doc(thong qua cac button)
	switch(status_col){
		case INIT:
			Display_Init();

			//chuyen trang thai ko dk
			status_col=AUTO_RED;
			setTimer1(Time_Auto_Red);
			break;
		case AUTO_RED:
			Display_Led_Red1();

			//chuyen trang thai co dk
			if(timer1_flag==1){
				status_col=AUTO_GREEN;
				setTimer1(Time_Auto_Green);
			}
			//trang thai mode 2
			if(isButton1Pressed()==1){
				status_col=MAN_RED;
				//trong trang thai mode, chi co Red_Led hang ngang se luon duoc bat
				status_row=MAN_RED;
				setTimer1(MODE_TIME);
			}
			break;
		case AUTO_GREEN:
			Display_Led_Green1();

			//chuyen trang thai co dk
			if(timer1_flag==1){
				status_col=AUTO_YELLOW;
				setTimer1(Time_Auto_Yellow);
			}
			if(isButton1Pressed()==1){
				status_col=MAN_GREEN;
				//trong trang thai mode, chi co Red_Led hang ngang se luon duoc bat
				status_row=MAN_GREEN;

				setTimer1(MODE_TIME);
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow1();

			//chuyen trang thai co dk
			if(timer1_flag==1){
				status_col=AUTO_RED;
				setTimer1(Time_Auto_Red);
			}
			if(isButton1Pressed()==1){
				status_col=MAN_YELLOW;
				//trong trang thai mode, chi co Red_Led hang ngang se luon duoc bat
				status_row=MAN_YELLOW;

				setTimer1(MODE_TIME);
			}
			break;
		default:
			break;
	}

	//quan ly den tin hieu hang ngang
	//trong time_mode, cac den hang ngang se chi doi den khi hoan tat mode
	switch(status_row){
		case INIT:
			Display_Init();

			//chuyen trang thai ko dk
			status_row=AUTO_GREEN;
			setTimer4(Time_Auto_Green);
			break;
		case AUTO_RED:
			Display_Led_Red2();

			//chuyen trang thai co dk
			if(timer4_flag==1){
				status_row=AUTO_GREEN;
				setTimer4(Time_Auto_Green);
			}
			break;
		case AUTO_GREEN:
			Display_Led_Green2();

			//chuyen trang thai co dk
			if(timer4_flag==1){
				status_row=AUTO_YELLOW;
				setTimer4(Time_Auto_Yellow);
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow2();

			//chuyen trang thai co dk
			if(timer4_flag==1){
				status_row=AUTO_RED;
				setTimer4(Time_Auto_Red);
			}
			break;
		default:
			break;
	}
}


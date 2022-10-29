/*
 * fsm_manual.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */
#include "global.h"
#include "fsm_manual.h"
#include "Display.h"
#include "modification_mode.h"

void fsm_manial_run(){
	//quan ly va chinh sua thu cong tren cac den duoc the hien tren hang doc
	switch(status_col){
		case MAN_RED:
			//TODO for mode1(NORMAL_STATE)
			Display_Led_Red1();
			//TODO for mode2(RED_STATE)
			modification_mode();


			if(timer1_flag==1){
				status_col=AUTO_RED;
				setTimer1(Time_Auto_Red);
				status_row=AUTO_GREEN;
				setTimer4(Time_Auto_Green);
			}

			//chuyen trang thai co dk
			//reset system khi ket thuc mode
//			if(timer1_flag==1){
//				status_col=INIT;
//				status_row=INIT;
//			}

			if(isButton1Pressed()==1){
				status_col=MAN_GREEN;
				setTimer1(10000);
			}
			break;
		case MAN_GREEN:
			//TODO for mode1(NORMAL_STATE)
			Display_Led_Green1();

			//TODO for mode2(GREEN_STATE)
			modification_mode();

			//chuyen trang thai co dk
			if(timer1_flag==1){
				status_col=INIT;
				status_row=INIT;
			}
			if(isButton1Pressed()==1){
				status_col=MAN_YELLOW;
				setTimer1(10000);
			}
			break;
		case MAN_YELLOW:
			//TODO for mode1(NORMAL_STATE)
			Display_Led_Yellow1();

			//TODO for mode4(YELLOW_STATE)
			modification_mode();

			//chuyen trang thai co dk
			if(timer1_flag==1){
				status_col=INIT;
				status_row=INIT;
			}
			if(isButton1Pressed()==1){
				status_col=MAN_RED;
				setTimer1(10000);
			}
			break;
		default:
			break;
	}

//	switch(status_row){
//		case MAN_RED:
//			Display_Led_Red2();
//
//
//			//chuyen trang thai co dk
//			if(timer4_flag==1){
//				status_row=AUTO_RED;
//				setTimer4(Time_Auto_Red);
//			}
//			if(isButton1Pressed()==1){
//				status_row=MAN_GREEN;
//				setTimer4(10000);
//			}
//			break;
//		case MAN_GREEN:
//			Display_Led_Green2();
//
//			//chuyen trang thai co dk
//			if(timer4_flag==1){
//				status_row=AUTO_GREEN;
//				setTimer4(Time_Auto_Green);
//			}
//			if(isButton1Pressed()==1){
//				status_row=MAN_YELLOW;
//				setTimer4(10000);
//			}
//			break;
//		case MAN_YELLOW:
//			Display_Led_Yellow2();
//
//			//chuyen trang thai co dk
//			if(timer4_flag==1){
//				status_row=AUTO_YELLOW;
//				setTimer4(Time_Auto_Yellow);
//			}
//			if(isButton1Pressed()==1){
//				status_row=MAN_RED;
//				setTimer4(10000);
//			}
//			break;
//		default:
//			break;
//	}
}

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

			//chuyen trang thai co dk
			//reset system khi ket thuc mode
			if(timer1_flag==1){
				status_col=INIT;
				status_row=INIT;
			}

			if(isButton1Pressed()==1){
				status_col=MAN_GREEN;
				setTimer1(MODE_TIME);
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
				setTimer1(MODE_TIME);
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
				setTimer1(MODE_TIME);
			}
			break;
		default:
			break;
	}

}

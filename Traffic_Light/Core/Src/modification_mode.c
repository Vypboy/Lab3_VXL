/*
 * modification_mode.c
 *
 *  Created on: Oct 27, 2022
 *      Author: ADMIN
 */

#include "modification_mode.h"
#include "global.h"
#include "Display.h"
#include "button.h"
// mode duoc the hien qua cac den tin hieu hang doc
//
void modification_mode(){
	switch(status_col){
		case MAN_RED:
			//nhan button2 de tang gia tri Time_Auto_Red (1->99)
			if(isButton2Pressed()==1){
				Time_Auto_Red = (Time_Auto_Red+1000)%100000;//ms
				set_Time_Auto_Red(Time_Auto_Red);
			}

			updateClockBuffer(Time_Auto_Red/1000,2);
			break;

		case MAN_GREEN:
			if(isButton2Pressed()==1){
				Time_Auto_Green = (Time_Auto_Green+1000)%100000;//ms
				set_Time_Auto_Green(Time_Auto_Green);
			}

			updateClockBuffer(Time_Auto_Green/1000,3);
			break;

		case MAN_YELLOW:
			if(isButton2Pressed()==1){
				Time_Auto_Yellow = (Time_Auto_Yellow+1000)%100000;//ms
				set_Time_Auto_Yellow(Time_Auto_Yellow);
			}

			updateClockBuffer(Time_Auto_Yellow/1000,4);
			break;
		default:
			break;
	}
	//nhan button3 de ket thuc mode
	if(isButton3Pressed()==1){
		status_col=INIT;
		status_row=INIT;
	}
}

/*
 * global.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#include "global.h"

int status_col=0;
int status_row=0;

//quan ly thoi gian cac den bang cac bien ben duoi
int Time_Auto_Red = 5000;
int Time_Auto_Green = 3000;
int Time_Auto_Yellow = 2000;


void set_Time_Auto_Red(int duration){
	Time_Auto_Red = duration;
}
void set_Time_Auto_Green(int duration){
	Time_Auto_Green = duration;
}
void set_Time_Auto_Yellow(int duration){
	Time_Auto_Yellow = duration;
}

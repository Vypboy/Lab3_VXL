/*
 * global.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "Software_timer.h"
#include "button.h"
#include "main.h"

#define INIT       	1
#define AUTO_RED  	2
#define AUTO_GREEN 	3
#define AUTO_YELLOW 4

#define MAN_RED	 	12
#define MAN_GREEN	13
#define MAN_YELLOW 	14

extern int status_col;
extern int status_row;

extern int Time_Auto_Red;
extern int Time_Auto_Green;
extern int Time_Auto_Yellow;

void set_Time_Auto_Red(int duration);
void set_Time_Auto_Green(int duration);
void set_Time_Auto_Yellow(int duration);
#endif /* INC_GLOBAL_H_ */

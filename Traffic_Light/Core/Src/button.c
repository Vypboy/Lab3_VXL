/*
 * button.c
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#include "button.h"
#include "main.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int Key1Reg0= NORMAL_STATE;
int Key1Reg1= NORMAL_STATE;
int Key1Reg2= NORMAL_STATE;
int Key1Reg3= NORMAL_STATE;
int TimeForKey1Press = 200;

int Key2Reg0= NORMAL_STATE;
int Key2Reg1= NORMAL_STATE;
int Key2Reg2= NORMAL_STATE;
int Key2Reg3= NORMAL_STATE;
int TimeForKey2Press = 200;

int Key3Reg0= NORMAL_STATE;
int Key3Reg1= NORMAL_STATE;
int Key3Reg2= NORMAL_STATE;
int Key3Reg3= NORMAL_STATE;
int TimeForKey3Press = 200;

void subKey1Process(){
	button1_flag=1;
}
void subKey2Process(){
	button2_flag=1;
}
void subKey3Process(){
	button3_flag=1;
}

int isButton1Pressed(){
	if(button1_flag==1){
		button1_flag=0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag==1){
		button2_flag=0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag==1){
		button3_flag=0;
		return 1;
	}
	return 0;
}

void getKeyInput1(){
	Key1Reg0= Key1Reg1;
	Key1Reg1= Key1Reg2;
	Key1Reg2= HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if ((Key1Reg1 == Key1Reg0) && (Key1Reg1 == Key1Reg2)){
		if (Key1Reg3 != Key1Reg2){
	      Key1Reg3 = Key1Reg2;
	      if (Key1Reg2 == PRESSED_STATE){
	    	  TimeForKey1Press = 200;
	    	  //TODO
	    	  subKey1Process();
	      }
	    } else {
	    	TimeForKey1Press--;
	        if (TimeForKey1Press == 0){
	        	//TODO
	        	Key1Reg3= NORMAL_STATE;
	        }
	    }
	}
}

void getKeyInput2(){
	Key2Reg0= Key2Reg1;
	Key2Reg1= Key2Reg2;
	Key2Reg2= HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	if ((Key2Reg1 == Key2Reg0) && (Key2Reg1 == Key2Reg2)){
		if (Key2Reg3 != Key2Reg2){
	      Key2Reg3 = Key2Reg2;
	      if (Key2Reg2 == PRESSED_STATE){
	    	  TimeForKey2Press = 200;
	    	  //TODO
	    	  subKey2Process();
	      }
	    } else {
	    	TimeForKey2Press--;
	        if (TimeForKey2Press == 0){
	        	//TODO
	        	Key2Reg3= NORMAL_STATE;
	        }
	    }
	}
}

void getKeyInput3(){
	Key3Reg0= Key3Reg1;
	Key3Reg1= Key3Reg2;
	Key3Reg2= HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
	if ((Key3Reg1 == Key3Reg0) && (Key3Reg1 == Key3Reg2)){
		if (Key3Reg3 != Key3Reg2){
	      Key3Reg3 = Key3Reg2;
	      if (Key3Reg2 == PRESSED_STATE){
	    	  TimeForKey3Press = 200;
	    	  //TODO
	    	  subKey3Process();
	      }
	    } else {
	    	TimeForKey3Press--;
	        if (TimeForKey3Press == 0){
	        	//TODO
	        	Key3Reg3= NORMAL_STATE;
	        }
	    }
	}
}

void getKeyInput(){
	getKeyInput1();
	getKeyInput2();
	getKeyInput3();
}


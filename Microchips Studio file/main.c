/*
 * CLCD.c
 *
 * Created: 2020-12-01 오후 4:39:00
 * Author : kccistc
 */ 
#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "lcd_4bit.h"
#include "button.h"
#include "buzzer_and_PWM.h"

#define MENU  0
#define AUTO  1
#define WASH  2
#define DRY   3
#define START_WASH 4
#define START_DRY  5

uint8_t state = MENU;
uint8_t mode = 0;
uint16_t counter = 0;
uint16_t counter_time =0;
uint16_t counter_time1 =0;


ISR(TIMER0_OVF_vect) //인터럽트 서비스 루틴 1ms 주기로 인터럽트 발생
{
	TCNT0 = 0;
	static uint16_t secCount = 0;
	
	if (++secCount >= 1000)
	{
		
		secCount = 0;
		counter++;
		counter_time++; 
	}
}

int main(void)
{
	pwmInit();
	buttonInit();
	buzzer_sound(OFF);
	
	uint16_t state_time = 0;
	char buff[30];
	LCD_Init();
	
	TCCR0 |= ((1<<CS02) | (0<<CS01) | (0<<CS00));	//111 => 분주비를 1024로 설정 //100 => 분주비를 64로 설정
	TIMSK |= (1<<TOIE0);	//타이머 오버플로 인터럽트 설정
	sei();
	
    while (1) 
    {
		switch(state)
		{
			case MENU: 
		
			sprintf(buff, "washing machine");
			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "AUTO  WASH  DRY");
			LCD_WriteStringXY(1, 0, buff);
			if(getButton1State())
			{
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
				buzzerPowerOn();
				state = AUTO;
			}
			if(getButton2State())
			{
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
				buzzerPowerOn();
				state = WASH;
			}
			if(getButton3State())
			{
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
				buzzerPowerOn();
				state = DRY;
			}
			
			break;
			case AUTO:
			sprintf(buff, "Washing Machine");
			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "! AUTO MODE !");
			LCD_WriteStringXY(1, 0, buff);
			if(counter >= 5)
			{
				motor(ON,0,1);
			}
			if(counter >= 10)
			{
				motor(ON,1,0);
			}
			if(counter >= 15)
			{
				motor(ON,1,1);
			}
			if(counter >= 20)
			{
				motor(OFF,0,0);
				counter =0;
				buzzerschoolsong();
				state =MENU;
			}
			if(getButton3State())
			{
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
				buzzerPowerOn();
				state =MENU;
			}
			break;
 			case WASH:
 			sprintf(buff, "!SET WASH TIME!");
 			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "set time: %3ds", state_time);
			LCD_WriteStringXY(1, 0, buff);
			if(getButton1State())
			{
				buzzerPowerOn();
				state_time = state_time + 5;
			}
			if(getButton2State())
			{
				buzzerPowerOn();
				state_time = 0;
			}
			if(getButton3State())
			{
				buzzerPowerOn();
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
			    counter_time = 0;
				state = START_WASH;
			}
			break;
			case DRY:
			sprintf(buff, "!SET DRY TIME!");
			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "set time: %3ds", state_time);
			LCD_WriteStringXY(1, 0, buff);
			if(getButton1State())
			{
				buzzerPowerOn();
				state_time = state_time + 5;
			}
			if(getButton2State())
			{
				buzzerPowerOn();
				state_time = 0;
			}
			if(getButton3State())
			{
				buzzerPowerOn();
				LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
				counter_time = 0;
				state = START_DRY;
			}
			break;
			case START_WASH:
			motor(ON,1,1);
			counter_time1 =	state_time -  counter_time;
			sprintf(buff, "SET WASH TIME");
			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "set time: %3ds",  counter_time1);
			LCD_WriteStringXY(1, 0, buff);
			
 			if(counter_time1 == 0)
 			{
				counter_time = 0;
				state_time =0;
				motor(OFF,0,0);
				buzzerschoolsong();
 				state = MENU;	
 			}
			break;
			case START_DRY:
			motor(ON,1,1);
			counter_time1 =	state_time -  counter_time;
			sprintf(buff, "SET DRY TIME");
			LCD_WriteStringXY(0, 0, buff);
			sprintf(buff, "set time: %3ds",  counter_time1);
			LCD_WriteStringXY(1, 0, buff);
			
			if(counter_time1 == 0)
			{
				counter_time = 0;
				state_time =0;
				motor(OFF,0,0);
				buzzerschoolsong();
				state = MENU;
			}
			break;	
 			default:
			break;
		}
		
    }
}







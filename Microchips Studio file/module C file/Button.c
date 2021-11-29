/*
 * Button.c
 *
 * Created: 2021-11-09 오전 10:12:23
 *  Author: kccistc
 */ 
#include "button.h"
#include <util/delay.h>
void buttonInit()
{
	BUTTON1_DDR &= ~(1<<BUTTON1);
	BUTTON2_DDR &= ~(1<<BUTTON2);
	BUTTON3_DDR &= ~(1<<BUTTON3);
}

uint8_t getButton1State()
{
	static uint8_t prevButton1State = RELEASED;  //변수가 유지
	uint8_t curButtonState = BUTTON1_PIN & (1 << BUTTON1);
	if(curButtonState == PUSHED && prevButton1State == RELEASED)  //첫번쨰 눌렀을때
	{
		_delay_ms(20);
		prevButton1State = PUSHED;
		return TRUE;
	}
	else if (curButtonState != PUSHED && prevButton1State == PUSHED) //누르지 않았을때
	{
		_delay_ms(20);
		prevButton1State = RELEASED;
		return FALSE;
	}
	return FALSE;
}
uint8_t getButton2State()
{
	static uint8_t prevButton2State = RELEASED;  //변수가 유지
	uint8_t curButtonState = BUTTON2_PIN & (1 << BUTTON2);
	if(curButtonState == PUSHED && prevButton2State == RELEASED)  //첫번쨰 눌렀을때
	{
		_delay_ms(20);
		prevButton2State = PUSHED;
		return TRUE;
	}
	else if (curButtonState != PUSHED && prevButton2State == PUSHED) //누르지 않았을때
	{
		_delay_ms(20);
		prevButton2State = RELEASED;
		return FALSE;
	}
	return FALSE;
}
uint8_t getButton3State()
{
	static uint8_t prevButton3State = RELEASED;  //변수가 유지
	uint8_t curButtonState = BUTTON3_PIN & (1 << BUTTON3);
	if(curButtonState == PUSHED && prevButton3State == RELEASED)  //첫번쨰 눌렀을때
	{
		_delay_ms(20);
		prevButton3State = PUSHED;
		return TRUE;
	}
	else if (curButtonState != PUSHED && prevButton3State == PUSHED) //누르지 않았을때
	{
		_delay_ms(20);
		prevButton3State = RELEASED;
		return FALSE;
	}
	return FALSE;
}
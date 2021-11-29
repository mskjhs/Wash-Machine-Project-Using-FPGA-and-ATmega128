#include "buzzer_and_PWM.h"


void pwmInit()
{
	PWM_MOTOR_DDR0 |= (1 << PWM_MOTOR_SW0);
	PWM_MOTOR_DDR1 |= (1 << PWM_MOTOR_SW1);
	PWM_ADDR_DDR |= (1<<PWM_ADDR);
	PWM_DATA_DDR = 0xff;
	PWM_CLK_DDR |= (1<<PWM_CLK);
	PWM_EN_DDR  |= (1<<PWM_EN);
	PWM_CS_DDR  |= (1<<PWM_CS);
}


void motor(uint8_t onOff,uint8_t a, uint8_t b)
{
	if( onOff == ON)
	{
		if(a==1)
		{
			PWM_MOTOR_PORT |=(a << PWM_MOTOR_SW0);
			if(b==1)
			PWM_MOTOR_PORT |=(b <<PWM_MOTOR_SW1);
			else
			PWM_MOTOR_PORT &= ~(1 << PWM_MOTOR_SW1);
		}
		else
		{
			PWM_MOTOR_PORT &= ~(a << PWM_MOTOR_SW0);
			if(b==1)
			PWM_MOTOR_PORT |=(b <<PWM_MOTOR_SW1);
			else
			PWM_MOTOR_PORT &= ~(1 << PWM_MOTOR_SW1);
		}
		
		
	}
	else
	{
		PWM_MOTOR_PORT &= ~(1 <<  PWM_MOTOR_SW0);
		PWM_MOTOR_PORT &= ~(1 <<  PWM_MOTOR_SW1);
		
	}
}

void buzzer_sound(uint8_t onOff)
{
	if( onOff == ON)
	{
		PWM_EN_PORT |=(1 << PWM_EN);
	}
	else
	{
		PWM_EN_PORT &= ~(1 << PWM_EN);
	}
}
void buzzerHzValue(uint16_t hz)
{
	PWM_CS_PORT &= ~(1<<PWM_CS);
	//Low chip select
	PWM_ADDR_PORT = (PWM_ADDR_PORT & 0xfe) | 0;                //Addr 0
	PWM_DATA_PORT = (uint8_t)hz;                             //data
	PWM_CLK_PORT &= ~(1<<PWM_CLK);                             //write
	PWM_CLK_PORT |= (1<<PWM_CLK);
	PWM_CLK_PORT &= ~(1<<PWM_CLK);
	
	PWM_ADDR_PORT = (PWM_ADDR_PORT & 0xfe) | 1;
	PWM_DATA_PORT = (uint8_t)(hz >>8);
	PWM_CLK_PORT &= ~(1<<PWM_CLK);
	PWM_CLK_PORT |= (1<<PWM_CLK);
	PWM_CLK_PORT &= ~(1<<PWM_CLK);
	
	PWM_CS_PORT |= (1<<PWM_CS);
	
}
void buzzerPowerOn()
{
	buzzer_sound(ON);
	buzzerHzValue(1568);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
}
void buzzerschoolsong()
{
	buzzer_sound(ON);
	buzzerHzValue(1568);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1568);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1760);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1760);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1568);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1568);    //1khz
	_delay_ms(200);
	buzzer_sound(OFF);
	_delay_ms(100);
	buzzer_sound(ON);
	buzzerHzValue(1318);    //1khz
	_delay_ms(300);
	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1318);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1318);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1174);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1760);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1760);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1568);    //1khz
// 	_delay_ms(200);
// 	buzzer_sound(OFF);
// 	_delay_ms(100);
// 	buzzer_sound(ON);
// 	buzzerHzValue(1318);    //1khz
// 	_delay_ms(300);
// 	buzzer_sound(OFF);
}
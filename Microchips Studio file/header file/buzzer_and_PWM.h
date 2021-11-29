/*
 * buzzer_and_PWM.h
 *
 * Created: 2021-11-13 오후 2:57:02
 *  Author: kccistc
 */ 


#ifndef BUZZER_AND_PWM_H_
#define BUZZER_AND_PWM_H_
#define PWM_ADDR_DDR   DDRD
#define PWM_ADDR_PORT   PORTD
#define PWM_DATA_DDR   DDRF
#define PWM_DATA_PORT   PORTF
#define PWM_CLK_DDR      DDRD
#define PWM_EN_DDR      DDRD
#define PWM_CS_DDR      DDRD
#define PWM_CLK_PORT   PORTD
#define PWM_EN_PORT      PORTD
#define PWM_CS_PORT      PORTD

#define PWM_MOTOR_DDR0  DDRE
#define PWM_MOTOR_DDR1  DDRE
#define PWM_MOTOR_PORT PORTE
#define PWM_MOTOR_SW0   0
#define PWM_MOTOR_SW1   3
#define PWM_MOTOR_RST 7

#define PWM_ADDR 0
#define PWM_CLK  1
#define PWM_EN   2
#define PWM_CS   3
#define ON  1
#define OFF 0

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
void pwmInit();
void motor(uint8_t onOff,uint8_t a, uint8_t b);
void buzzer_sound(uint8_t onOff);
void buzzerHzValue(uint16_t hz);
void buzzerPowerOn();
void buzzerschoolsong();




#endif /* BUZZER_AND_PWM_H_ */
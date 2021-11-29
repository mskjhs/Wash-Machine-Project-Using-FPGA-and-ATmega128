/*
 * button.h
 *
 * Created: 2021-11-09 오전 10:12:37
 *  Author: kccistc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>
#define TRUE      1
#define FALSE     0
#define PUSHED    0
#define RELEASED  1
#define BUTTON1   0
#define BUTTON1_DDR DDRA
#define BUTTON1_PIN PINA

#define BUTTON2   1
#define BUTTON2_DDR DDRA
#define BUTTON2_PIN PINA

#define BUTTON3   2
#define BUTTON3_DDR DDRA
#define BUTTON3_PIN PINA

void buttonInit();
uint8_t getButton1State();
uint8_t getButton2State();
uint8_t getButton3State();
#endif /* BUTTON_H_ */
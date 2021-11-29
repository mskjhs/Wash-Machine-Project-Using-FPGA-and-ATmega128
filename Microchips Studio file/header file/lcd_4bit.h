
#ifndef LCD_H_
#define LCD_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA_DDR	DDRF
#define LCD_DATA_PORT	PORTF
#define LCD_DATA_PIN	PINF
#define LCD_RS_DDR		DDRF
#define LCD_RW_DDR		DDRF
#define LCD_E_DDR		DDRF
#define LCD_RS_PORT		PORTF
#define LCD_RW_PORT		PORTF
#define LCD_E_PORT		PORTF
#define LCD_RS			0
#define LCD_RW			1
#define LCD_E			2

#define COMMAND_DISPLAY_CLEAR	0X01
#define COMMAND_DISPLAY_ON		0X0C
#define COMMAND_DISPLAY_OFF		0X08
#define COMMAND_8_BIT_MODE		0X38
#define COMMAND_4_BIT_MODE		0X28
#define COMMAND_ENTRY_MODE		0X06


#define LOW					0
#define HIGH				1
#define LCD_MOSI_DDR		DDRE
#define LCD_MOSI_PORT		PORTE
#define LCD_SHIFT_CLK_DDR	DDRE
#define LCD_SHIFT_CLK_PORT	PORTE
#define LCD_SS_DDR			DDRE
#define LCD_SS_PORT			PORTE

#define LCD_MOSI			5
#define LCD_SHIFT_CLK		6
#define LCD_SS				7





void LCD_Data(uint8_t data);
void LCD_Data4bit(uint8_t data);
void LCD_WriteMode();
void LCD_ReadPin();
void LCD_EnablePin();
void LCD_WriteCommand(uint8_t commadData);
void LCD_WriteData(uint8_t charData);
void LCD_GotoXY(uint8_t row, uint8_t col);
void LCD_WriteString(char *string);
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string);
void LCD_Init();


#endif /* LCD_H_ */
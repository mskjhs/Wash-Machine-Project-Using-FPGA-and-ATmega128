
#include "CLCD.h"

void LCD_Data(uint8_t data)
{
	//LCD_DATA_PORT = data;
	LCD_Data4bit(data);
}

void LCD_Data4bit(uint8_t data) // data = 0x12;
{
	//                (PORTD & 0x0f) | (data & 0xf0);
	//             PORTD = 0b0000xxxx|0x10 => 0b0001xxxx
	//             PORTD = 0b0001xxxx
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	LCD_EnablePin();
	//                      PORTD & 0x0f   |  (0x12 & 0x0f) << 4
	//                      PORTD & 0x0f   |  (0x02) << 4
	//                     (PORTD & 0x0f)  |  (0x20)
	//                     (0b0000xxxx)  |  (0x20)
	//             PORTD = (0b0010xxxx)
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((data & 0x0f) << 4); // 하위 4bit 출력
	LCD_EnablePin();
}

void LCD_WritePin()
{
	LCD_RW_PORT &= ~(1<<LCD_RW);
}

void LCD_ReadPin()
{
	LCD_RW_PORT |= (1<<LCD_RW);
}


void LCD_EnablePin()
{
	LCD_E_PORT &= ~(1<<LCD_E);
	LCD_E_PORT |= (1<<LCD_E);
	_delay_ms(1);
	LCD_E_PORT &= ~(1<<LCD_E);
	_delay_ms(1);
}

void LCD_WriteCommand(uint8_t commadData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS);
	LCD_WritePin();
	LCD_Data(commadData);
	LCD_EnablePin();
}

void LCD_WriteData(uint8_t charData)
{
	LCD_RS_PORT |= (1<<LCD_RS);
	LCD_WritePin();
	LCD_Data(charData);
	LCD_EnablePin();
}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	
	uint8_t address = (0x40 * row) + col;
	uint8_t command = 0x80 + address;
	LCD_WriteCommand(command);
}

void LCD_WriteString(char *string)
{
	for (uint8_t i=0; string[i]; i++)
	{
		LCD_WriteData(string[i]);
	}
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row, col);
	LCD_WriteString(string);
}

void LCD_Init()
{
	LCD_DATA_DDR = 0xff;
	LCD_RS_DDR |= (1<<LCD_RS);
	LCD_RW_DDR |= (1<<LCD_RW);
	LCD_E_DDR |= (1<<LCD_E);
	
	_delay_ms(50);
	
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	
	LCD_WriteCommand(0x03);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(COMMAND_4_BIT_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
}

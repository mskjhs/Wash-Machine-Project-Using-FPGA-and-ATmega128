

#include "lcd_4bit.h"

uint8_t lcdData = 0;

void slaveSelect(uint8_t state)
{
	if(state == LOW)
	{
		LCD_SS_PORT &= ~(1 << LCD_SS);
	}
	else 
	{
		LCD_SS_PORT |= (1 << LCD_SS);
	}
}
void shiftClock()
{
	LCD_SHIFT_CLK_PORT |= (1<<LCD_SHIFT_CLK);
	LCD_SHIFT_CLK_PORT &= ~(1<<LCD_SHIFT_CLK);
}
void LCD_Data(uint8_t data)
{
	//LCD_DATA_PORT = data;       //8bit 데이터 전송
	// 8bit serial전송
	//i_ss핀을 Low로 만든다
	slaveSelect(LOW);
	for (int i=0; i<8; i++)
	{
 		if(data & (0x80 >> i)) LCD_MOSI_PORT |= (1<<LCD_MOSI);
 		else LCD_MOSI_PORT &= ~(1 << LCD_MOSI);
//		(data & (0x08 >> i)) ? (LCD_MOSI_PORT |= (1<<LCD_MOSI)) : (LCD_MOSI_PORT &= ~(1 << LCD_MOSI));
		shiftClock();
	}
	//i_ss핀을 HIGH로 만든다
	slaveSelect(HIGH);
}

void LCD_Data4bit(uint8_t data)
{
	lcdData = (lcdData & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	LCD_EnablePin();
	lcdData = (lcdData & 0x0f) | ((data & 0x0f) << 4); // 하위 4bit 출력
	LCD_EnablePin();
}

void LCD_Data4bitInit(uint8_t data)
{
	lcdData = (lcdData & 0x0f) | (data & 0xf0); // 상위 4bit 출력
	LCD_EnablePin();
}


void LCD_WriteMode()
{
	lcdData &= ~(1<<LCD_RW);
}


void LCD_EnablePin()
{
	lcdData &= ~(1<<LCD_E);
	LCD_Data(lcdData);
	lcdData |= (1<<LCD_E);
	LCD_Data(lcdData);
	lcdData &= ~(1<<LCD_E);
	LCD_Data(lcdData);
	_delay_us(1600);
}

void LCD_WriteCommand(uint8_t commadData)
{
	lcdData &= ~(1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bit(commadData);
}

void LCD_WriteCommandInit(uint8_t commadData)
{
	lcdData &= ~(1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bitInit(commadData);
}

void LCD_WriteData(uint8_t charData)
{
	lcdData |= (1<<LCD_RS);
	LCD_WriteMode();
	LCD_Data4bit(charData);
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
	LCD_SHIFT_CLK_DDR |= (1 <<LCD_SHIFT_CLK);
	LCD_MOSI_DDR |= (1<<LCD_MOSI);
	LCD_SS_DDR |= (1<< LCD_SS);
	
	_delay_ms(20);
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	LCD_WriteCommand(0x03);
	_delay_ms(1);
	LCD_WriteCommand(0x03);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(COMMAND_4_BIT_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
}

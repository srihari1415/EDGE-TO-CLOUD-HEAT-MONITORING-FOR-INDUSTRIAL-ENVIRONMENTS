#include<LPC21xx.h>

#include "delay.h"
#include "lcd.h"
#include "defines.h"

#define LCD_DAT 16
#define RS 16
#define RW 18
#define EN 17

void LCD_Init(void)
{
		WRITEBYTE(IODIR1,LCD_DAT,0xFF);
		WRITEBIT(IODIR0,RS,1);
		WRITEBIT(IODIR0,RW,1);
		WRITEBIT(IODIR0,EN,1);
		delay_ms(16);
    Write_CMD_LCD(0x30);
    delay_ms(6);
		Write_CMD_LCD(0x30);
    delay_ms(1);
    Write_CMD_LCD(0x30);
    delay_ms(1);
    Write_CMD_LCD(0x38);//set 8-bit mode of operation with 2 lines
						// and 5X7 character font 
		Write_CMD_LCD(0x10);//Turning OFF the display
		Write_CMD_LCD(0x01);//clearing the display
    Write_CMD_LCD(0x06);//Shifting the cursor to the right side
                        //after writing each byte onto the display
		Write_CMD_LCD(0x0f);//Enabling the display with blinking cursor

}
void Write_CMD_LCD(char cmd)
{
  WRITEBIT(IOCLR0,RS,1);
	Write_LCD(cmd);
}
void Write_DAT_LCD(char dat)
{
	WRITEBIT(IOSET0,RS,1);
	Write_LCD(dat);
}
void Write_LCD(char ch)
{
	WRITEBIT(IOCLR0,RW,1);
	WRITEBYTE(IOPIN1,LCD_DAT,ch);
	WRITEBIT(IOSET0,EN,1);
	WRITEBIT(IOCLR0,EN,1);
	delay_ms(2);
}
void Write_str_LCD(char *p)
{
	while(*p)
		Write_DAT_LCD(*p++);	
}
void Write_int_LCD(signed int n)
{
	char a[10],i=0;
    if(n<0)
	{
		Write_DAT_LCD('-');
		n=-n;
	}
	do                       
	{
		a[i++]=n%10+48;	
		n=n/10;
	}while(n);
  for(;i>0;i--)
		Write_DAT_LCD(a[i-1]);
}
void Write_float_LCD(float f,char i)
//1st arg(f) is the float number to be displayed  on LCD
//2nd arg(i) is number digits to be displayed after the dot('.')                      
{
  unsigned long int n=f;
	Write_int_LCD(n);
	Write_DAT_LCD('.');
  for(;i>0;i--)
	{
		f=f*10;
    n=f;	
		Write_DAT_LCD(n%10+48);
	}	
}

/*void SetCursor(unsigned char row, unsigned char col)
{
    unsigned char pos;
    if (row == 0)
        pos = 0x80 + col;
    else
        pos = 0xC0 + col;

    Write_CMD_LCD(pos);
} */
void LCD_SetCursor(unsigned int row, unsigned char col)
{
    unsigned char pos;
    switch (row)
    {
        case 0: pos = 0x80 + col; break;
        case 1: pos = 0xC0 + col; break;
        case 2: pos = 0x94 + col; break;
        case 3: pos = 0xD4 + col; break;
        default: pos = 0x80;
    }
    Write_CMD_LCD(pos);
}


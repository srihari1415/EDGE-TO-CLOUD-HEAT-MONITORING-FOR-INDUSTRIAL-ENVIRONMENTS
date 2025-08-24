#include<lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "delay.h"
#include "adc.h"
#include "rtc.h"
#include "lcd.h"
#include "uart0.h"
#include "esp01.h"

#define BUZZER 13 // p0.13
#define MQ2 14 // p0.14

u8 min,flag=0;u32 temp;
f32 adc;

int main()
{
	InitUART0();
	LCD_Init();
	Write_str_LCD("**WELCOME TO MAJOR**");
	Write_CMD_LCD(0XC0);
	Write_str_LCD("******PROJECT*******");
	delay_ms(2000);
	Write_CMD_LCD(0X01);
	Init_ADC();
	RTC_Init();
	RTCSetTime(7,25,0);
	esp01_connectAP();
	Write_CMD_LCD(0X01);	
	min=MIN;
	while(1)
	{
		adc=Read_ADC(1);
		temp=adc*100;
		Write_CMD_LCD(0X80);
		Write_str_LCD("TEMP: ");
		Write_int_LCD(temp);
		Write_DAT_LCD(223);
		Write_DAT_LCD('C');
		Write_CMD_LCD(0XC0);
		Write_str_LCD("SMOKE: ");
		if(((IOPIN0>>MQ2)&1))
		{
			Write_CMD_LCD(0XC0+7);
			Write_str_LCD("NOT DETECTED");
		}
		if(min==MIN)
		{
			esp01_sendToThingspeak(temp,1);
			min+=3;
		}
		if(((IOPIN0>>MQ2)&1)==0)
		{
			Write_CMD_LCD(0XC0+7);
			Write_str_LCD("                ");
			Write_CMD_LCD(0XC0+8);
			Write_str_LCD("DETECTED");
			esp01_sendToThingspeak(1,2);
		}
		if(MIN==59)
		{
			min=0;
		}
		delay_ms(1000);
	}
}

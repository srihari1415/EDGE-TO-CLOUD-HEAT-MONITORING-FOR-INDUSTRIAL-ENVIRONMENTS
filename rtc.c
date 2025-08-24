#include <LPC21xx.H>
#include "rtc.h"
#include "rtc_defines.h"
#include "types.h"
#include "lcd.h"

signed char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

// RTC Initialization: Configures and enables the RTC
void RTC_Init(void) 
{
  // Reset the RTC
	CCR = RTC_CTC_RESET;	
  // Set prescaler integer part
	PREINT = PREINT_VAL;
  // Set prescaler fractional part
	PREFRAC = PREFRAC_VAL;
	
  // Enable the RTC for LPC2129
	//CCR = RTC_CCR_EN;
	
	// Enable the RTC for LPC2148 with external clock source
	CCR = RTC_CCR_EN | RTC_CLKSRC;
}

void RTCGetTime(u32 *hr,u32 *mi,u32 *se)
{
	*hr = HOUR;
	*mi = MIN;
	*se = SEC;	
}
/*
void DisplayRTCTime(u32 hr,u32 mi,u32 se)
{
	SetCursor(1,0);
	Write_DAT_LCD((hr/10)+48);
	Write_DAT_LCD((hr%10)+48);
	Write_DAT_LCD(':');
	Write_DAT_LCD((mi/10)+48);
	Write_DAT_LCD((mi%10)+48);
	Write_DAT_LCD(':');
	Write_DAT_LCD((se/10)+48);
	Write_DAT_LCD((se%10)+48);	
}
  */
void RTCGetDate(u32 *dt,u32 *mo,u32 *yr)
{
	*dt = DOM;
	*mo = MONTH;
	*yr = YEAR;	
}
/*
void DisplayRTCDate(u32 dt,u32 mo,u32 yr)
{
	SetCursor(2,0);
	Write_DAT_LCD((dt/10)+48);
	Write_DAT_LCD((dt%10)+48);
	Write_DAT_LCD('/');
	Write_DAT_LCD((mo/10)+48);
	Write_DAT_LCD((mo%10)+48);
	Write_DAT_LCD('/');
	Write_int_LCD(yr);	
}
	*/
void RTCGetDay(u32 *day)
{
	*day = DOW;
}
/*void DisplayRTCDay(u32 day)
{
	LCD_SetCursor(1,10);
	Write_str_LCD(week[day]);	
}
  */
void RTCSetTime(u32 hr,u32 mi,u32 se)
{
	HOUR = hr;
	MIN = mi;
	SEC = se;
}
void RTCSetDate(u32 dt,u32 mo,u32 yr)
{
	DOM = dt;
	MONTH = mo;
	YEAR = yr;
}
void RTCSetDay(u32 day)
{
	DOW = day;
}

/*
#include "types.h"
#include <lpc21xx.h>
#include "rtc.h"
#include "adc.h"
#include "esp01.h"
#include "lcd.h"
#include "delay.h"
#include "stdlib.h"
#include <stdio.h>

void RTC_Init(void)
{
    CCR = 0x00;
    //ILR = 0x03; // Clear interrupt flags
    //CIIR = 0x00; // Disable periodic interrupts
    //AMR = 0xFC; // Unmask minute and second for alarm
   // VICIntEnable |= (1 << 13); // Enable RTC interrupt
   // VICVectAddr13 = (unsigned long)RTC_IRQHandler;
    //VICVectCntl13 = 0x2D; // Enable slot and assign to RTC
    CCR = 0x11; // Enable RTC and alarm
}

void RTCSetTime(unsigned int hr, unsigned int min, unsigned int sec)
{
    HOUR = hr;
    MIN = min;
    SEC = sec;
}

void RTCSetDate(unsigned int day, unsigned int mon, unsigned int year)
{
    DOM = day;
    MONTH = mon;
    YEAR = year;
}

void RTCSetDay(unsigned int day)
{
    DOW = day;
}

void RTCGetTime(unsigned int *hr, unsigned int *min, unsigned int *sec)
{
    *hr = HOUR;
    *min = MIN;
    *sec = SEC;
}

void SetRTCAlarmAfter3Min(unsigned int min, unsigned int sec)
{
    ALMIN = (min + 3) % 60;
    ALSEC = sec;
    AMR = 0xFC;  // Mask all except ALMIN and ALSEC
    ILR = 0x03;  // Clear interrupt flags
    CIIR = 0x00;
    CCR |= (1 << 1);  // Enable alarm
}

void __irq RTC_IRQHandler(void)
{
    float voltage, temperature;
	unsigned int hr, min, sec;
    char temp_str[10];

    voltage = Read_ADC(1);
    temperature = voltage * 100.0;

    // Display temperature update status
    LCD_SetCursor(3, 0);
    Write_str_LCD("Temp Log Check  ");

    if (temperature > TEMP_THRESHOLD)
    {
        sprintf(temp_str, "%.2f", temperature);
        esp01_sendToThingspeak(temp_str, 1);

        LCD_SetCursor(3, 0);
        Write_str_LCD("Temp Sent: ");
        Write_str_LCD(temp_str);
    }
    else
    {
	    sprintf(temp_str, "%.2f", temperature);
        esp01_sendToThingspeak(temp_str, 1);
        LCD_SetCursor(3, 0);
        Write_str_LCD("Temp Normal :    ");
		Write_str_LCD(temp_str);
    }

    // Reconfigure next alarm
    
    RTCGetTime(&hr, &min, &sec);
    SetRTCAlarmAfter3Min(min, sec);

    ILR = 0x01;  // Clear RTC alarm interrupt
    VICVectAddr = 0; // Signal end of interrupt
}
*/

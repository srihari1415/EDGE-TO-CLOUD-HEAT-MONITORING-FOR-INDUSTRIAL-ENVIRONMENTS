#include <LPC214x.H>

#include "adc_defines.h"
#include "types.h"
#include "defines.h"
#include "delay.h"


void Init_ADC(void)
{
  
  AD0CR = (1<<PDN_BIT)|(CLKDIV<<8);
  PINSEL1=0x15400000;	
}

f32 Read_ADC(u8 chNo)
{
	u16 adcVal=0;f32 eAR;
  //select channel
	//WRITEBYTE(AD0CR,0,chNo);
	  AD0CR&=0XFFFFFFF0;
	  AD0CR|=1<<chNo;
	//start the adc conversion
	//SETBIT(AD0CR,ADC_START_BIT);
	AD0CR|=1<<24;  
	//wait for conversion time (10 bit conversion time: 2.44 us)
  delay_us(3);
	//wait for done bit
  while(((AD0GDR>>31)&1) == 0);
	//stop the adc conversion
  //CLRBIT(AD0CR,ADC_START_BIT);  
	AD0CR&=~(1<<24);
	//collect the ADDR register content into adcVal variable
  adcVal = (AD0GDR>>6)&0x3FF;
	//eAR=((converted voltage*vref)/2^n-1);
	eAR = (adcVal*3.3)/1023;
  return eAR;
}

/*f32 ear;
main()
{
	Init_ADC();
	while(1)
	{
		ear=Read_ADC(1);
	}
}
*/

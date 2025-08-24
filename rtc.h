/*#ifndef _RTC_H
#define _RTC_H

#include "types.h"

void RTC_Init(void);

void RTCGetTime(u32 *,u32 *,u32 *);
void DisplayRTCTime(u32,u32,u32);

void RTCGetDate(u32 *,u32 *,u32 *);
void DisplayRTCDate(u32,u32,u32);

void RTCGetDay(u32 *);
void DisplayRTCDay(u32);

void RTCSetTime(u32,u32,u32);
void RTCSetDate(u32,u32,u32);
void RTCSetDay(u32);


#endif*/
#ifndef _RTC_H_
#define _RTC_H_

#include "types.h"

void RTC_Init(void);
void RTCSetTime(unsigned int hr, unsigned int min, unsigned int sec);
void RTCSetDate(unsigned int day, unsigned int mon, unsigned int year);
void RTCSetDay(unsigned int day);
void RTCGetTime(unsigned int *hr, unsigned int *min, unsigned int *sec);
void SetRTCAlarmAfter3Min(unsigned int min, unsigned int sec);

#endif


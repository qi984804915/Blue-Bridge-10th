#ifndef _LED_H
#define _LED_H

extern u8 LedChar[];
extern u8 LedBuff[];

void LedScan();
void ShowNumber(u32 dat);

#endif
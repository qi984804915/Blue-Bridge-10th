#include "config.h"

extern u8 flag18b20;

KeySta[4] = {1, 1, 1, 1};
KeyCodeMap[4] = {'1', '2', '3', '4'};

extern void KeyAction(u8 keycode);

void KeyDriver()
{
	static u8 backup[4] = {1, 1, 1, 1};
	u8 i;
	for(i = 0; i<4; i++)
	{
		if(KeySta[i] != backup[i])
		{
			if(backup[i] == 1)
			{
				KeyAction(KeyCodeMap[i]);
			}
			backup[i] = KeySta[i];
		}
	}
}

void KeyScan()
{
	static u8 keybuff[4] = {0xFF, 0xFF, 0xFF, 0xFF};
	u8 i;
	
	keybuff[0] = (keybuff[0] << 1) | KEY_IN_1;
	keybuff[1] = (keybuff[1] << 1) | KEY_IN_2;
	keybuff[2] = (keybuff[2] << 1) | KEY_IN_3;
	keybuff[3] = (keybuff[3] << 1) | KEY_IN_4;
	
	for(i = 0; i<4; i++)
	{
		if(keybuff[i] == 0x00)
			KeySta[i] = 0;
		else
			KeySta[i] = 1;
		if(keybuff[3] == 0x00)
		{
			flag18b20 = 1;
		}
		else if(keybuff[3] == 0xFF)
		{
			flag18b20 = 0;
		}
	}
}
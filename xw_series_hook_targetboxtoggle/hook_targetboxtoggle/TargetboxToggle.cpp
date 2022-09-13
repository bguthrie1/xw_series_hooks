#include "targetver.h"
#include "TargetboxToggle.h"
#include "config.h"

void* hexstr_to_char_address(unsigned char* address, const char* hexstr)
{
	size_t len = strlen(hexstr);
	if (len % 2 != 0)
		return NULL;
	size_t final_len = len / 2;
	unsigned char* chrs = address;
	for (size_t i = 0, j = 0; j < final_len; i += 2, j++)
		chrs[j] = (hexstr[i] % 32 + 9) % 25 * 16 + (hexstr[i + 1] % 32 + 9) % 25;
	return 0;
}

bool ConfigTargetBox()
{
	vector<string> lines = GetFileLines("hook_targetboxtoggle.cfg");

	if (lines.size())
	{
		if (GetFileKeyValueInt(lines, "TargetBox") == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	return true;
}

int TargetboxToggleHookXW(int* params)
{
	static bool TargetBox = true;

	if (*KeyPressedXW == KeyCode_CTRLT)
	{
		if (TargetBox)
		{
			hexstr_to_char_address((unsigned char*)0x42E1D0, "C3");
			TargetBox = false;
		}
		else
		{
			hexstr_to_char_address((unsigned char*)0x42E1D0, "51");
			TargetBox = true;
		}
	}

	JoystickRawWrapAndDeadZoneXW();

	return 0;
}

int TargetboxToggleHookTF(int* params)
{
	static bool TargetBox = true;

	if (*KeyPressedTF == KeyCode_CTRLT)
	{
		if (TargetBox)
		{
			hexstr_to_char_address((unsigned char*)0x4971A0, "C3");
			TargetBox = false;
		}
		else
		{
			hexstr_to_char_address((unsigned char*)0x4971A0, "51");
			TargetBox = true;
		}
	}

	JoystickRawWrapAndDeadZoneTF();

	return 0;
}

int TargetboxToggleHookXVT(int* params)
{
	int playerIndex = params[-2];
	BOPPlayer* XVTPlayerPtr = (BOPPlayer*)0x71B730;
	params[-9] = XVTPlayerPtr[playerIndex].curCraftIndex;

	if (!ConfigTargetBox())
	{
		hexstr_to_char_address((unsigned char*)0x442720, "C39090");
		return 0;
	}
	else
	{
		hexstr_to_char_address((unsigned char*)0x442720, "83EC08");
	}

	if (*KeyPressedXVT == KeyCode_CTRLT)
	{
		XVTPlayerPtr[playerIndex].ShowTargetBox = XVTPlayerPtr[playerIndex].ShowTargetBox == 0;
	}

	return 0;
}

int TargetboxToggleHookBOP(int* params)
{
	int playerIndex = params[-2];
	BOPPlayer* BOPPlayerPtr = (BOPPlayer*)0x9E9670;
	params[-9] = BOPPlayerPtr[playerIndex].curCraftIndex;

	if (!ConfigTargetBox())
	{
		hexstr_to_char_address((unsigned char*)0x482EB0, "C39090");
		return 0;
	}
	else
	{
		hexstr_to_char_address((unsigned char*)0x482EB0, "83EC0C");
	}

	if (*KeyPressedBOP == KeyCode_CTRLT)
	{
		BOPPlayerPtr[playerIndex].ShowTargetBox = BOPPlayerPtr[playerIndex].ShowTargetBox == 0;
	}

	return 0;
}

int TargetboxToggleHookXWA(int* params)
{
	int playerIndex = params[-10];
	XWAPlayer* XWAPlayerPtr = (XWAPlayer*)0x8B94E0;
	params[-2] = XWAPlayerPtr[playerIndex].ObjectIndex;

	if (!ConfigTargetBox())
	{
		hexstr_to_char_address((unsigned char*)0x503A30, "C39090");
		return 0;
	}
	else
	{
		hexstr_to_char_address((unsigned char*)0x503A30, "83EC08");
	}

	if (*KeyPressedXWA == Key_CONTROL_T)
	{
		XWAPlayerPtr[playerIndex].ShowTargetBox = XWAPlayerPtr[playerIndex].ShowTargetBox == 0;
		PlaySoundFromObject(Sound_Click1, 0xFFFF, playerIndex);
	}

	
	return 0;
}
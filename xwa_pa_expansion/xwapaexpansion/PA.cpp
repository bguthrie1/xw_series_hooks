#include "targetver.h"
#include "PA.h"
#include "XWAFramework.h"
#include <cstring>
#include <cstdlib>
#include <filesystem>

using namespace std;

string StringToUpper(string strToConvert)
{
	std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

	return strToConvert;
}

int GetNumOfExtraPA()
{
	int PACount = 0;

	for (const auto& file : std::experimental::filesystem::directory_iterator(".\\Wave\\Frontend"))
	{
		if (StringToUpper(file.path().extension().string()) != ".WAV")
		{
			continue;
		}

		const auto& filename = file.path().filename().string();

		if (filename.find("T01PA") != 0 && filename.find("t01pa") != 0)
		{
			continue;
		}

		++PACount;
	}

	return PACount - 37;
}

int PAHook(int* params)
{
	int randNum1;
	int randNum2;
	int randNum3;
	int randNum4;
	int randNum5;
	int randModified;
	__int8 briefingLogo;
	QuickMissionData* QuickMissionDataPtr = *(QuickMissionData**)0x9EB8E0;
	int PACount = GetNumOfExtraPA();
	int newRandChance = 0;

	if (PACount > 0)
	{
		newRandChance = 30;
	}

	switch (randXWA() % (24 + newRandChance))
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		goto Copy_Announcement_1Through9;
	case 6:
	case 7:
	case 8:
		randNum1 = randXWA();
		sprintf_(*mainStringBuffer, "wave\\frontend\\T01PA1%d.wav", randNum1 % 3 + 1);
		break;
	case 9:
	case 10:
		if (!*campaignIncomplete)
			goto Copy_Independence_PA;
		briefingLogo = QuickMissionDataPtr->header.BriefingLogo;
		if (briefingLogo == BriefingLogo_Liberty2)
		{
			memcpy(*mainStringBuffer, "wave\\frontend\\T01PA14.wav", 0x1Au);
		}
		else if (briefingLogo == BriefingLogo_Independence2)
		{
		Copy_Independence_PA:
			memcpy(*mainStringBuffer, "wave\\frontend\\T01PA15.wav", 0x1Au);
		}
		else
		{
		Copy_Announcement_1Through9:
			randNum2 = randXWA();
			sprintf_(*mainStringBuffer, "wave\\frontend\\T01PA0%d.wav", randNum2 % 6 + 3);
		}
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		randNum3 = randXWA();
		randModified = ((randNum3 >> 31) ^ abs(randNum3) & 3) - (randNum3 >> 31) + 16;
		goto Copy_Almost_Any_Announcement;
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
		randNum4 = randXWA();
		randModified = ((randNum4 >> 31) ^ abs(randNum4) & 7) - (randNum4 >> 31) + 28;
	Copy_Almost_Any_Announcement:
		// Copy almost any announcement to the string buffer.
		sprintf_(*mainStringBuffer, "wave\\frontend\\T01PA%d.wav", randModified);
		break;
	case 23:
		sprintf_(*mainStringBuffer, "wave\\frontend\\T01PA37.wav");
		break;
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
	case 30:
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
	case 40:
	case 41:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 50:
	case 51:
	case 52:
	case 53:
		randNum5 = randXWA();
		randModified = ((randNum5 >> 31) ^ abs(randNum5) & PACount - 1) - (randNum5 >> 31) + 38;
		sprintf_(*mainStringBuffer, "wave\\frontend\\T01PA%d.wav", randModified);
		break;
	default:
		*(*mainStringBuffer) = 0;
		break;
	}

	params[-1] = 0x53B06C;

	return 0;
}
#include "targetver.h"
#include "PA.h"
#include "XWAFramework.h"
#include <string>
#include <algorithm>
#include <filesystem>

using namespace std;

// Stack contents for function params
enum ParamsEnum
{
	Params_ReturnAddress = -1,
	Params_EAX = -3,
	Params_ECX = -4,
	Params_EDX = -5,
	Params_EBX = -6,
	Params_EBP = -8,
	Params_ESI = -9,
	Params_EDI = -10,
};

string StringToUpper(string strToConvert)
{
	std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

	return strToConvert;
}

int GetNumOfExtraPA()
{
	int PACount = 0;

	for (const auto& file : filesystem::directory_iterator(".\\Wave\\Frontend"))
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

int SetRandomChanceToCallPAFunction(int* params)
{
	// This is how XWA gets the random chance to play the PA Function.
	*randomChanceToCallPAFunction = rand() % 480;

	return 0;
}

int CheckToCallPAFunction(int* params)
{
	int frameCounter = params[Params_EBP];
	
	// If the random chance matches the frame number, play a PA.
	if (*randomChanceToCallPAFunction == frameCounter)
		PlayPublicAnnouncement();

	return 0;
}

void PlayPublicAnnouncement()
{
	int randNum;
	int randNum1;
	int randNum2;
	int randNum3;
	int randNum4;
	int randNum5;
	int randModified;
	int numPlayers = 0;
	char battleChar = 0;
	char battleCharDummy = 0;
	int battleNum = 0;
	int missionNum = 0;
	char strBuffer[12];
	__int8 briefingLogo;
	FrontEndMissionData* FrontEndMissionDataPtr = *(FrontEndMissionData**)0x9EB8E0;
	int ExtraPACount = GetNumOfExtraPA();
	int newRandChance = 0;
	unsigned int tickCount = GetTickCountXWA();

	// Set random seed for picking a random standard announcement.
	srand(tickCount);

	if (!*campaignIncomplete || FrontEndMissionDataPtr->header.MissionType == MissionType_Family)
		goto Pick_PA_Announcement;

	int missionIndex = 0;
	// Scan for missions.
	// If there are missions then we check to see if we can play an announcement based on the current battle and mission number.
	// Certain announcements are specific to that mission.
	MissionLSTEntry* missionLstPtr = *(MissionLSTEntry**)0x9F4B98;
	if (*numberMissionEntriesInLST > 0)
	{
		int *missionIDPtr = &missionLstPtr->IDNumber;
		while (*missionIDPtr != *currentMissionInCampaign)
		{
			++missionIndex;
			missionIDPtr += 82;
			if (missionIndex >= *numberMissionEntriesInLST)
				goto Scan_Missions_File_Characters;
		}
	}

Scan_Missions_File_Characters:

	sscanf(missionLstPtr[missionIndex].missionFileName,
		"%d%c%d%c%d",
		& numPlayers,
		& battleChar,
		& battleNum,
		& battleCharDummy,
		& missionNum);

	// There is a limit of 99 battles and 99 missions for this scan.
	if (battleNum < 0 || battleNum > 99 || missionNum < 0 || missionNum > 99)
	{
		xwaTempString[0] = 0;
	}
	else
	{
		// Play the PA that is dependent on the battle and mission number.
		sprintf(strBuffer, "%2d%2d%2d", battleNum, missionNum, 1);
		if (strBuffer[0] == ' ')
			strBuffer[0] = '0';
		if (strBuffer[2] == ' ')
			strBuffer[2] = '0';
		if (strBuffer[4] == ' ')
			strBuffer[4] = '0';
		sprintf(xwaTempString, "wave\\frontend\\T%s.wav", strBuffer);
	}

	// If we got a string and the wav file played successfully, leave the function.
	// else determine a random PA to play.
	if (!xwaTempString[0] || !PlayWavFile(xwaTempString, 0))
	{
	Pick_PA_Announcement:
		// If new craft were added to the tech room, only play one of two announcements.
		// Announce that new craft were added to the tech database.
		if (!PilotTableFrontEnd->newCraftAddedToTechRoom
			|| (randNum = rand(),
				sprintf(xwaTempString, "wave\\frontend\\T01PA0%d.wav", randNum % -2 + 1),
				!PlayWavFile(xwaTempString, 0)))
		{
			if (ExtraPACount > 0)
			{
				newRandChance = 30;
			}

			// Get a random number out of 0 - 24.
			// This will determine what announcement to play.
			// Numbers 0 - 5 will play announcements 1 - 9.
			// Numbers 6 - 8 will play Announcements 10 - 14.
			// Numbers 9 - 10 will play either Liberty or Independence or Announcements 1 - 9.
			// Numbers 11 - 14 will play Announcements 16 - 19.
			// Numbers 15 - 22 will play Announcements 28 - 35.
			// Number 23 will play announcement T01PA37.wav.
			// Default will play nothing.


			switch (rand() % (24 + newRandChance))
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
				randNum1 = rand();
				sprintf_(xwaTempString, "wave\\frontend\\T01PA1%d.wav", randNum1 % 3 + 1);
				break;
			case 9:
			case 10:
				if (!*campaignIncomplete)
					goto Copy_Independence_PA;
				briefingLogo = FrontEndMissionDataPtr->header.BriefingLogo;
				if (briefingLogo == BriefingLogo_Liberty2)
				{
					memcpy(xwaTempString, "wave\\frontend\\T01PA14.wav", 0x1Au);
				}
				else if (briefingLogo == BriefingLogo_Independence2)
				{
				Copy_Independence_PA:
					memcpy(xwaTempString, "wave\\frontend\\T01PA15.wav", 0x1Au);
				}
				else
				{
				Copy_Announcement_1Through9:
					randNum2 = rand();
					sprintf_(xwaTempString, "wave\\frontend\\T01PA0%d.wav", randNum2 % 6 + 3);
				}
				break;
			case 11:
			case 12:
			case 13:
			case 14:
				randNum3 = rand();
				// bitwise AND for the number of PAs to be used.
				// + for the minimum number of the PA ID.
				// 3 and 16 in this case.
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
				randNum4 = rand();
				// bitwise AND for the number of PAs to be used.
				// + for the minimum number of the PA ID.
				// 7 and 28 in this case.
				randModified = ((randNum4 >> 31) ^ abs(randNum4) & 7) - (randNum4 >> 31) + 28;
			Copy_Almost_Any_Announcement:
				// Copy almost any announcement to the string buffer.
				sprintf_(xwaTempString, "wave\\frontend\\T01PA%d.wav", randModified);
				break;
			case 23:
				sprintf_(xwaTempString, "wave\\frontend\\T01PA37.wav");
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
				randNum5 = rand();
				randModified = ((randNum5 >> 31) ^ abs(randNum5) & ExtraPACount - 1) - (randNum5 >> 31) + 38;
				sprintf_(xwaTempString, "wave\\frontend\\T01PA%d.wav", randModified);
				break;
			default:
				xwaTempString[0] = 0;
				break;
			}
			if (xwaTempString[0])
				PlayWavFile(xwaTempString, 0);
		}
	}
}
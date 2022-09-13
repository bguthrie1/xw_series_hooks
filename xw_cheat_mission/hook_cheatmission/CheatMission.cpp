#include "targetver.h"
#include "CheatMission.h"
#include "config.h"

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

bool ConfigCheatMission()
{
	vector<string> lines = GetFileLines("hook_cheatmission.cfg");

	if (lines.size())
	{
		if (GetFileKeyValueInt(lines, "PassMissionWithCheats") == 0)
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

int CheatMissionHook(int* params)
{
	int playerScore = params[Params_EBX];

	if (*playerCheatedDuringMission)
	{
		playerScore /= 10;
	}

	if (playerScore < 0)
	{
		playerScore = 0;
	}

	params[Params_EBX] = playerScore;

	return 0;
}
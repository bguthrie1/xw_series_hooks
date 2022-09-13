#include "targetver.h"
#include "tacofficer.h"
#include <cstring>

const char* wavePath = "wave\\";

int TacticalOfficerHook(int* params)
{
	char waveLstPath[128];

	if (*configTacticalOfficerMessages && !*provingGrounds)
	{
		switch (*tacOfficerInMission)
		{
		case TacticalOfficer_Devers:
			strcpy_s(waveLstPath, "wave\\devers.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_Kupalo:
			strcpy_s(waveLstPath, "wave\\kupalo.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_Zaletta:
			strcpy_s(waveLstPath, "wave\\zaletta.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_TacOfficer3:
			strcpy_s(waveLstPath, "wave\\tacof3.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_TacOfficer4:
			strcpy_s(waveLstPath, "wave\\tacof4.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_TacOfficer5:
			strcpy_s(waveLstPath, "wave\\tacof5.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_TacOfficer6:
			strcpy_s(waveLstPath, "wave\\tacof6.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_TacOfficer7:
			strcpy_s(waveLstPath, "wave\\tacof7.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		case TacticalOfficer_Emkay:
			strcpy_s(waveLstPath, "wave\\EmkayTac.lst");
			LoadSoundLstFile(waveLstPath, 2646, wavePath);
			break;
		default:
			break;
		}
	}

	params[-1] = 0x43A882;

	return 0;
}
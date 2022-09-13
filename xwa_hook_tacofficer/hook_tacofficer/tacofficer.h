#pragma once

int TacticalOfficerHook(int* params);

const auto provingGrounds = (__int8*)0x8053E5;
const auto configTacticalOfficerMessages = (__int8*)0xB0C884;
const auto tacOfficerInMission = (__int8*)0x7B6FAE;
const auto LoadSoundLstFile = (int(*)(char* lstFileName, int sourceMasterStringIndex, const char* wavePath))0x43A150;

enum TacticalOfficer : __int8
{
	TacticalOfficer_Devers = 0,
	TacticalOfficer_Kupalo = 1,
	TacticalOfficer_Zaletta = 2,
	TacticalOfficer_TacOfficer3 = 3,
	TacticalOfficer_TacOfficer4 = 4,
	TacticalOfficer_TacOfficer5 = 5,
	TacticalOfficer_TacOfficer6 = 6,
	TacticalOfficer_TacOfficer7 = 7,
	TacticalOfficer_Emkay = 8,
};
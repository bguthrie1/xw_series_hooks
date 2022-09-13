#pragma once

int MissionFailureTimerHook(int* params);
int MissionFailureTimerHook2(int* params);
int MissionSuccessTimerHook(int* params);
int PlayIFFArrivalMusicSequence(int* params);
int ImuseMissionFlowHook(int* params);
void PlayMusicState(int musicState);
void PlayProvingGroundsMusic();
void GetForceWeightsAndEnemyDistance();
void PlayNoEnemiesMusic();
void FindHomingProjectilesOrPlayIntroMusic();
void GetFGUnresolvedAndCompletedGoals();
void CheckIfPlayerHasCriticalDamage();
void CheckEnemyAndFriendlyForcesAndPlayMusic();
void PlayEnemyIFFMusic();
int GoodDestructionMusicHook(int* params);
int BadDestructionMusicHook(int* params);
bool IsTFTC();

const auto g_thisPlayerExitedMission = (int*)0x80B604;
const auto g_iMuseSequenceRestrictedTime = (int*)0x694064;
const auto g_thisPlayerIndex = (int*)0x8C1CC8;
const auto g_iMuseCurrentMusicState = (int*)0x9B631C;
const auto g_iMuseMusicStateToChangeTo = (int*)0x9B6318;
const auto g_elapsedTimeLastFrame = (int*)0x8C1640;
const auto g_Imuse = (char*)0x694068;
const auto g_configMusic = (int*)0xB0C88C;
const auto g_playerInHangar = (int*)0x9C6E40;
const auto g_iMuseMusicStateOverride = (int*)0x694070;
const auto g_craftSlotMinIndex = (int*)0x8BF378;
const auto g_craftSlotMaxIndex = (int*)0x7CA3B8;
const auto g_DistanceBetweenObjects = (unsigned int*)0x7B4BF8;
const auto g_iMusePlayerEncounteredEnemy = (char*)0x69406C;
const auto g_minProjectileIndex = (int*)0x8D9628;
const auto g_maxProjectileIndex = (int*)0x8BF368;
const auto g_tickCount = (int*)0x7D4B8C;
const auto g_hangarPhase = (int*)0x686B94;


const auto OptHasMeshFuselage = (bool(*)(int objectType))0x4872D0;
const auto Imuse_ChangeMusicSequence = (void(*)(int sequence, int regionToPlayIn, char restrictions))0x49ABE0;
const auto Imuse_ChangeMusicState = (void(*)(int musicState))0x49AA40;
const auto Imuse_PlayMusic = (void(*)())0x49ADE0;
const auto IsObjectEnemy = (bool(*)(unsigned __int16 objectIndex, int playerTeam))0x505D40;
const auto GetManhattanDistanceWaypointOrNormalPositions = (void(*)(unsigned int objectAIndex, unsigned int objectBIndex))0x4A2D30;
const auto Multiply32And16BitPercentage = (unsigned int(*)(unsigned int numerator, unsigned __int16 denominator))0x494CC0;
const auto GetPercentage16bit = (unsigned int (*)(unsigned __int16 numerator, unsigned __int16 denominator))0x494D00;
const auto IsObjectFriendly = (bool(*)(unsigned __int16 objectIndex, int playerTeam))0x505DF0;
const auto GetFrontTxtString = (char*(*)(unsigned int stringIndex))0x55CB50;
#include "targetver.h"
#include "imuse.h"
#include "XWA_Enums.h"
#include "XWA_Structs.h"
#include <string>
#include "config.h"
#include <algorithm>

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

PlayerTimerEntry* PlayerTimersTable = (PlayerTimerEntry*)0x80DB80;
Player* PlayerTable = (Player*)0x8B94E0;
InflightMissionData* InFlightMissionDataTable = (InflightMissionData*)0x8053E0;
MissionDataFrontEndFileHeader* MissionFileHeader = (MissionDataFrontEndFileHeader*)0x7B4C00;
FlightGroup* FlightGroupTable = (FlightGroup*)0x80DC80;
FGStats* FGStatsTable = (FGStats*)0x7B7020;
unsigned int g_DistOfClosestLargeEnemyCraft;
unsigned int g_DistOfClosestEnemy;
int g_closestEnemyObjectIndex;
int g_ForceWeightsEnemy;
int g_ForceWeightsFriendly;
int g_FGGoalsCompleted;
int g_FGGoalsUnresolved;
int ForceWeightsPerEnemyIFF[6];

class Config
{
public:
	Config()
	{
		auto lines = GetFileLines("hook_imuse.cfg");

		if (lines.empty())
		{
			lines = GetFileLines("hooks.ini", "hook_imuse");
		}

		this->MusicLogicType = GetFileKeyValueInt(lines, "MusicLogicType", 0);

	}

	int MusicLogicType;
};

Config g_config;

int MissionFailureTimerHook(int* params)
{
	// Divide values by 236 to get actual seconds.
	if (!IsTFTC())
		PlayerTimersTable[*g_thisPlayerIndex].MissionFailureMusicTimer = 2360;
	else
		PlayerTimersTable[*g_thisPlayerIndex].MissionFailureMusicTimer = 32767;

	return 0;
}

int MissionFailureTimerHook2(int* params)
{
	if (!IsTFTC())
		PlayerTimersTable[*g_thisPlayerIndex].MissionFailureMusicTimer = 2360;
	else
		PlayerTimersTable[*g_thisPlayerIndex].MissionFailureMusicTimer = 32767;

	return 0;
}

int MissionSuccessTimerHook(int* params)
{
	if (!IsTFTC())
		PlayerTimersTable[*g_thisPlayerIndex].MissionSuccessMusicTimer = 2360;
	else
		PlayerTimersTable[*g_thisPlayerIndex].MissionSuccessMusicTimer = 32767;

	return 0;
}

int GoodDestructionMusicHook(int* params)
{
	params[Params_ReturnAddress] = 0x410FDF;
	int targetObjIndex = params[Params_EBX] / sizeof(Object);

	
	Object* ObjectTable = *(Object**)0x7B33C4;
	ObjectGenus genus = ObjectTable[targetObjIndex].Genus;
	int region = ObjectTable[targetObjIndex].Region;

	if (!IsTFTC())
	{
		if (OptHasMeshFuselage(ObjectTable[targetObjIndex].Type)
			|| genus == Genus_Starfighter)
		{
			if (MissionFileHeader->Header.MissionType == MissionType_Family)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqfamgdsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqrebgdsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else if (MissionFileHeader->Header.MissionType == MissionType_Family)
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqfamgdlg4, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebgdlg2, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
	}
	else
	{
		if (OptHasMeshFuselage(ObjectTable[targetObjIndex].Type) || genus < Genus_Starship)
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebgdsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebgdlg2, region, ImuseSequenceRestrictions_NoRestrictions);
		}
	}

	return 0;
}

int BadDestructionMusicHook(int* params)
{
	params[Params_ReturnAddress] = 0x41160F;
	int objectIndex = params[Params_ESI] / sizeof(Object);

	Object* ObjectTable = *(Object**)0x7B33C4;

	ObjectGenus genus = ObjectTable[objectIndex].Genus;
	int region = ObjectTable[objectIndex].Region;

	if (!IsTFTC())
	{
		if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
		{
			if (MissionFileHeader->Header.MissionType == MissionType_Family)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqfambdsm1, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqrebbdsm1, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else if (MissionFileHeader->Header.MissionType == MissionType_Family)
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqfambdlg3, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebbdlg1, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
	}
	else
	{
		if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || genus < Genus_Starship)
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebbdsm1, region, ImuseSequenceRestrictions_NormalRestrictions);
		else
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebbdlg1, region, ImuseSequenceRestrictions_NoRestrictions);
	}

	return 0;
}

int PlayIFFArrivalMusicSequence(int* params)
{
	int objectIndex = params[Params_EAX];

	Object* ObjectTable = *(Object**)0x7B33C4;
	ObjectGenus genus = ObjectTable[objectIndex].Genus;
	int region = ObjectTable[objectIndex].Region;
	//IFFCode iff = FlightGroupTable[ObjectTable[objectIndex].FGIndex].IFF;
	MobileObject* pMobileObj = ObjectTable[objectIndex].pMobileObject;
	IFFCode iff = pMobileObj->IFF;

	if (!IsTFTC())
	{
		if (iff == IFF_Imperial)
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqempsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqemplg1, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else if (iff)
		{
			if (MissionFileHeader->Header.MissionType == MissionType_Family)
			{
				if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
					Imuse_ChangeMusicSequence(ImuseSequence_Sqrivsm, region, ImuseSequenceRestrictions_NormalRestrictions);
				else
					Imuse_ChangeMusicSequence(ImuseSequence_Sqrivlg, region, ImuseSequenceRestrictions_NormalRestrictions);
			}
			else if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqpirsm, region, ImuseSequenceRestrictions_NormalRestrictions);
			}
			else
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqpirlg, region, ImuseSequenceRestrictions_NormalRestrictions);
			}
		}
		else if (MissionFileHeader->Header.MissionType == MissionType_Family)
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqfamsm1, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqfamlg, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || !genus)
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrebsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
		else
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqreblg3, region, ImuseSequenceRestrictions_NormalRestrictions);
		}
	}
	else
	{
		if (iff == IFF_Imperial)
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || genus < Genus_Starship)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqempsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqemplg1, region, ImuseSequenceRestrictions_NoRestrictions);
		}
		else if (iff == IFF_Blue || iff == IFF_Yellow || iff == IFF_Purple)
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || genus < Genus_Starship)
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqpirsm, region, ImuseSequenceRestrictions_NormalRestrictions);
			}
			else
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqpirlg, region, ImuseSequenceRestrictions_NoRestrictions);
			}
		}
		else if (iff == IFF_Red)
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || genus < Genus_Starship)
				Imuse_ChangeMusicSequence(ImuseSequence_Sqrivsm, region, ImuseSequenceRestrictions_NormalRestrictions);
			else
				Imuse_ChangeMusicSequence(ImuseSequence_Sqrivlg, region, ImuseSequenceRestrictions_NoRestrictions);
		}
		else
		{
			if (OptHasMeshFuselage(ObjectTable[objectIndex].Type) || genus < Genus_Starship)
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqrebsm2, region, ImuseSequenceRestrictions_NormalRestrictions);
			}
			else
			{
				Imuse_ChangeMusicSequence(ImuseSequence_Sqreblg3, region, ImuseSequenceRestrictions_NoRestrictions);
			}
		}
	}

	return 0;
}

int ImuseMissionFlowHook(int* params)
{
	params[Params_ReturnAddress] = 0x4F5273;
	
	int newMusicState;
	int thisPlayerIndex = *g_thisPlayerIndex;
	static int hangarMusicTimer = *g_tickCount;

	if (!*g_Imuse)
		return 0;
	if (!*g_configMusic)
		return 0;
	if (PlayerTimersTable[thisPlayerIndex].iMuseMissionFlowDelayTimer)
		return 0;

	// Imuse mission flow delay timer is 250 milliseconds.
	PlayerTimersTable[thisPlayerIndex].iMuseMissionFlowDelayTimer = 59;

	if (InFlightMissionDataTable->IsProvingGrounds)
	{
		PlayProvingGroundsMusic();
		return 0;
	}

	if (PlayerTimersTable[thisPlayerIndex].MissionFailureMusicTimer)
	{
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StFailReb : ImuseMusicState_StFailFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(256, "Music state set to %d, Mission Loss.\n", MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StFailReb : ImuseMusicState_StFailFam);*/
		PlayMusicState(newMusicState);
		return 0;
	}

	if (PlayerTimersTable[thisPlayerIndex].MissionSuccessMusicTimer)
	{
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StSuccReb : ImuseMusicState_StSuccFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(256, "Music state set to %d, Mission Success.\n", MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StSuccReb : ImuseMusicState_StSuccFam);*/
		PlayMusicState(newMusicState);
		return 0;
	}

	if (IsTFTC())
	{
		if (*g_hangarPhase == HangarPhase_StartedInHangar)
		{
			// Play Hangar track for 28 seconds.
			if (*g_tickCount - hangarMusicTimer < 6608)
			{
				newMusicState = ImuseMusicState_FrHangar;;
				PlayMusicState(newMusicState);
				return 0;
			}
		}
		else
			hangarMusicTimer = *g_tickCount;
	}
	

	GetForceWeightsAndEnemyDistance();
	
	if (g_closestEnemyObjectIndex == 0xFFFF)
	{
		PlayNoEnemiesMusic();
		return 0;
	}
	else
	{
		FindHomingProjectilesOrPlayIntroMusic();
	}

	return 0;
}

void PlayProvingGroundsMusic()
{
	ProvingGroundsData* ProvingGroundsDataTable = (ProvingGroundsData*)0x7B2320;
	int thisPlayerIndex = *g_thisPlayerIndex;

	int newMusicState; 

	/*Proving grounds music.

		- Plays StWaitReb when in hangar.
		- Plays StSuccReb when the player has completed the race.
		- If there are less than 30 rings left, play StClimReb.
		- If there are 30 rings or more, check if they are inside an object.
		- If they are inside the compactor or tube, play StPanicReb.
		- If the player reached the end container or are carrying R2, play StConfReb.
		- Otherwise, play StChalReb normally.
		- If the player is not inside or passed through any object, play StWaitReb.*/

	if (*g_playerInHangar)
	{
		newMusicState = ImuseMusicState_StWaitReb;
	}
	else if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].CompletedRace)
	{
		newMusicState = ImuseMusicState_StSuccReb;
	}
	else if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].Rings >= 30)
	{
		if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].InsideOrPassedThruObject)
		{
			if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].InsideOrPassedThruObject == InsideObject_Compactor)
			{
				newMusicState = ImuseMusicState_StPanicReb;
			}
			else if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].InsideOrPassedThruObject == InsideObject_Tube)
			{
				newMusicState = ImuseMusicState_StPanicReb;
			}
			else if (ProvingGroundsDataTable->PlayerData[thisPlayerIndex].ReachedEndContainer || ProvingGroundsDataTable->PlayerData[thisPlayerIndex].CarryingR2)
			{
				newMusicState = ImuseMusicState_StConfReb;
			}
			else
			{
				newMusicState = ImuseMusicState_StChalReb;
			}
		}
		else
		{
			newMusicState = ImuseMusicState_StWaitReb;
		}
	}
	else
	{
		newMusicState = ImuseMusicState_StClimReb;
	}
	PlayMusicState(newMusicState);
}

void GetForceWeightsAndEnemyDistance()
{
	g_DistOfClosestLargeEnemyCraft = -1;
	g_DistOfClosestEnemy = -1;
	g_closestEnemyObjectIndex = 0xFFFF;
	g_ForceWeightsEnemy = 0;
	g_ForceWeightsFriendly = 0;
	g_FGGoalsCompleted = 0;
	g_FGGoalsUnresolved = 0;

	for (int iffCount = 0; iffCount < 6; ++iffCount)
	{
		ForceWeightsPerEnemyIFF[iffCount] = 0;
	}

	Object* pObject = *(Object**)0x7B33C4;

	if (*g_craftSlotMinIndex < *g_craftSlotMaxIndex)
	{
		for (int objectIndex = *g_craftSlotMinIndex; objectIndex < *g_craftSlotMaxIndex; ++objectIndex)
		{
			// Object must be in play.
			if (pObject[objectIndex].Type == ObjectType_NONE)
				continue;
			MobileObject* pMobileObj = pObject[objectIndex].pMobileObject;
			// We are checking mobile objects only. Ex. Not a mine or satellite.
			if (!pMobileObj)
				continue;
			Craft* pCraft = pMobileObj->pCraft;
			// Not a craft/doesn't exist or its state is something other than normal, skip.
			if (!pCraft || pCraft->CraftState)
				continue;

			bool isEnemy = IsObjectEnemy(objectIndex, PlayerTable[*g_thisPlayerIndex].Team);
			ObjectGenus genus = pObject[objectIndex].Genus;
			//IFFCode iff = FlightGroupTable[pObject[objectIndex].FGIndex].IFF;
			IFFCode iff = pMobileObj->IFF;

			// Get the force weight of the object.
			// In X-Wing/TIE Fighter, containers were not apart of this check.
			// XWA checks for them. I'll leave them in for now.
			if (genus == Genus_Starship || genus == Genus_Platform)
			{
				if (isEnemy)
				{
					g_ForceWeightsEnemy += 4;
					ForceWeightsPerEnemyIFF[iff] += 4;
				}
				else
					g_ForceWeightsFriendly += 4;
			}
			else if (genus == Genus_Transport || genus == Genus_Container || genus == Genus_Freighter)
			{
				if (isEnemy)
				{
					g_ForceWeightsEnemy += 2;
					ForceWeightsPerEnemyIFF[iff] += 2;
				}
				else
					g_ForceWeightsFriendly += 2;
			}
			else
			{
				if (isEnemy)
				{
					++g_ForceWeightsEnemy;
					++ForceWeightsPerEnemyIFF[iff];
				}
				else
					++g_ForceWeightsFriendly;
			}
			// Don't check for allies or disabled craft for the enemy distance check.
			if (!isEnemy || !pObject[objectIndex].pMobileObject->pCraft->SubsystemStatus)
				continue;

			// Don't play combat music if the player is on the map.
			if (PlayerTable[*g_thisPlayerIndex].ObjectIndex == 0xFFFF)
				continue;
			
			// Get distance between enemy and player.
			GetManhattanDistanceWaypointOrNormalPositions(objectIndex, PlayerTable[*g_thisPlayerIndex].ObjectIndex);
			if (*g_DistanceBetweenObjects < g_DistOfClosestEnemy)
			{
				g_DistOfClosestEnemy = *g_DistanceBetweenObjects;
				g_closestEnemyObjectIndex = objectIndex;
			}
			// Save the distance in another variable if the enemy is a large ship.
			// In X-Wing/TIE Fighter, there is no seperate distance variable for larger craft.
			// They instead used only one and divided the distance by 4 if it was a platform or starship.
			// Divided by 2 if it was a freighter.
			// This is the XWA way of doing this. I decided to leave this as it is for now.
			if (genus == Genus_Starship
				|| genus == Genus_Platform
				|| genus == Genus_Freighter
				|| genus == Genus_Container)
			{
				g_DistOfClosestLargeEnemyCraft = *g_DistanceBetweenObjects;
			}
		}
	}
}

void PlayNoEnemiesMusic()
{
	int newMusicState;

	if (InFlightMissionDataTable->TeamMissionOutcome[3 * PlayerTable[*g_thisPlayerIndex].Team] == MissionOutcome_Victory)
	{
		// Player's team won the mission. This only plays when the Mission Success Music Timer is not up and no enemies are in play.
		// Play waiting music state.
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StWaitReb : ImuseMusicState_StWaitFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugStringA(
				256,
				"Music state set to %d, Mission Completed, no enemies.\n",
				MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StWaitReb : ImuseMusicState_StWaitFam);*/
	}
	else if (*g_iMusePlayerEncounteredEnemy)
	{
		// If the player previously encountered an enemy, play the waiting state.
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StWaitReb : ImuseMusicState_StWaitFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(
				256,
				"Music state set to %d, Waiting, no enemies.\n",
				MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StWaitReb : ImuseMusicState_StWaitFam);*/
	}
	else
	{
		// The mission just started so there shouldn't be any enemies.
		// Play the intro music state.
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StIntroReb : ImuseMusicState_StIntroFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(
				256,
				"Music state set to %d, Intro, no enemies.\n",
				MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StIntroReb : ImuseMusicState_StIntroFam);*/
	}

	PlayMusicState(newMusicState);
}

void FindHomingProjectilesOrPlayIntroMusic()
{
	Object* pObject = *(Object**)0x7B33C4;

	/*The safe distance threshold is determined if the player encountered an enemy previously.
	If they did, the safe distance is 25.6km
	Otherwise, its 12.8km.
	In TIE Fighter, the safe distance threshold is 6.4km if they encountered an enemy.
	3.2km if they hadn't. I'm keeping it how XWA does until a reason is found to do otherwise.
	Another tidbit of information of X-wing: 1.6km if no enemy encountered, 6.4km if so.*/
	unsigned int safeDistanceFromEnemyThreshold = *g_iMusePlayerEncounteredEnemy != 0 ? 1048576 : 524288;
	/*If the dist of the closest enemy(large or otherwise) is less than the safe distance, the player has "encountered" the enemy.
	Otherwise, we play the intro music state.*/
	bool ProjectileHomingInOnPlayer = false;
	int newMusicState;

	if (g_DistOfClosestEnemy <= safeDistanceFromEnemyThreshold
		|| g_DistOfClosestLargeEnemyCraft <= safeDistanceFromEnemyThreshold)
	{
		int projectileIndexIteration = *g_minProjectileIndex;
		*g_iMusePlayerEncounteredEnemy = 1;
		//Check and see if there are any projectiles homing onto the player.
		if (*g_minProjectileIndex < *g_maxProjectileIndex)
		{
			MobileObject** pMobileObject = &pObject[*g_minProjectileIndex].pMobileObject;

			for (; projectileIndexIteration < *g_maxProjectileIndex; ++projectileIndexIteration)
			{
				if (pMobileObject)
				{
					Projectile* pProjectile = (*pMobileObject)->pProjectile;
					if (pProjectile->LockStrength)
					{
						if (pProjectile->TargetCraftIndex == PlayerTable[*g_thisPlayerIndex].ObjectIndex)
						{
							ProjectileHomingInOnPlayer = true;
							break;
						}
					}
				}
				pMobileObject = (MobileObject**)((char*)pMobileObject + sizeof(Object));
			}
		}
		if (!ProjectileHomingInOnPlayer)
		{
			GetFGUnresolvedAndCompletedGoals();
		}
		else
		{
			// Play panic state.
			newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam;
			/*if (*g_iMuseCurrentMusicState != newMusicState)
			{
				OutputDebugString(
					256,
					"Music state set to %d, Targeted by missile.\n",
					MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam);
			}*/
			PlayMusicState(newMusicState);
		}
	}
	else
	{
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StIntroReb : ImuseMusicState_StIntroFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(
				256,
				"Music state set to %d, Intro.\n",
				MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StIntroReb : ImuseMusicState_StIntroFam);*/
		
		PlayMusicState(newMusicState);
	}
}

void GetFGUnresolvedAndCompletedGoals()
{
	/*If the last known enemy distance is less or equal to 2.4km...
	Get the unresolved and completed FG goals for the player.
	Otherwise, play the IFF music.
	In TIE Fighter, the IFF music is played when further than 1.6km away from the enemy.
	I'm keeping it as it was in XWA unless told otherwise or I think of a good reason.*/

	if (g_DistOfClosestEnemy <= 98304 || g_DistOfClosestLargeEnemyCraft <= 98304)
	{

		if (MissionFileHeader->FlightGroupsCount > 0)
		{
			int playerTeam = PlayerTable[*g_thisPlayerIndex].Team;
			
			// Get both resolved and unresolved flight goals for the player's team.
			for (int FGIndexIteration = 0; FGIndexIteration < MissionFileHeader->FlightGroupsCount; ++FGIndexIteration)
			{
				int FGGoalIndex = 0;
				for (int FGGoalsRemaining = 8 ; FGGoalsRemaining > 0; --FGGoalsRemaining)
				{
					FlightGroupGoal* fgGoal = FlightGroupTable[FGIndexIteration].Goals;
					char* playerFGGoalPtr = &FlightGroupTable[FGIndexIteration].Goals[0].AppliesToTeams[playerTeam];

					if (*playerFGGoalPtr && fgGoal->Argument != GoalCategory_Prevent)
					{
						char fgGoalStatus = FGStatsTable[FGIndexIteration].FGGoalCompletionStatus[playerTeam].FGGoalCompletionStatus[FGGoalIndex];
						if (fgGoalStatus == FGGoal_Completed)
						{
							++g_FGGoalsCompleted;
						}
						else if (fgGoalStatus == FGGoal_Unresolved)
						{
							++g_FGGoalsUnresolved;
						}
					}
					++fgGoal;
					++FGGoalIndex;
					playerFGGoalPtr += sizeof(FlightGroupGoal);
				}
			}
		}
		CheckIfPlayerHasCriticalDamage();
	}
	else
	{
		PlayEnemyIFFMusic();
	}
	
}

void CheckIfPlayerHasCriticalDamage()
{
	// TIE Fighter did not check if the player was critically damaged.
	// Otherwise the panic state would play a lot.
	// X-Wing did though. 
	// If the total shields were 0 and it is 15 seconds or less on the mission clock from when it was started (not counting minutes), it plays the panic state.
	if (!IsTFTC())
	{
		Object* pObject = *(Object**)0x7B33C4;

		int playerObjectIndex = PlayerTable[*g_thisPlayerIndex].ObjectIndex;
		Craft* pPlayerCraft = 0;
		int newMusicState;

		if (playerObjectIndex != 0xFFFF)
		{
			MobileObject* pPlayerMobile = pObject[playerObjectIndex].pMobileObject;
			if (pPlayerMobile)
				pPlayerCraft = pPlayerMobile->pCraft;
		}
		// Check if the player has less than 1000 shield hitpoints total.
		if (pPlayerCraft != 0 && (pPlayerCraft->FrontShieldHitpoints[1] + pPlayerCraft->FrontShieldHitpoints[0] < 1000))
		{
			// Check if the player has less than 50% hull strength.
			// Originally XWA had it check for more than 50% hull strength.
			// Based on the debug string, it doesn't make sense. 
			// I think they intended panic to play at less than 50% hull strength.
			if (pPlayerCraft->HullDamageReceived > Multiply32And16BitPercentage(pPlayerCraft->HullStrength, 32768))
			{
				newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam;
				/*if (*g_iMuseCurrentMusicState != newMusicState)
					OutputDebugString(
						256,
						"Music state set to %d, Almost dead: panic!\n",
						MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam);*/

				PlayMusicState(newMusicState);
				return;
			}
		}
		CheckEnemyAndFriendlyForcesAndPlayMusic();
	}
	else
	{
		CheckEnemyAndFriendlyForcesAndPlayMusic();
	}
}

void CheckEnemyAndFriendlyForcesAndPlayMusic()
{
	int newMusicState;
	int playerTeam = 3 * PlayerTable[*g_thisPlayerIndex].Team;

	if (g_DistOfClosestLargeEnemyCraft >= 32768)
	{
		// If we are not on our last goal or the player's team has lost or the player's team + 1 has won....
		// These are fixed teams. As it was originally in XWA. 
		// This should be changed eventually with a loop.
		// Also, TIE Fighter checked goals a little differently.
		// If the number of completed goals is more than 3 (primary or secondary) and there is only one goal left to complete, it plays climax.
		// X-Wing did not check goals at all.
		// I've left it how it is in XWA. Seems fine to me unless someone gives me a good reason otherwise.
		if (g_FGGoalsUnresolved != 1
			|| (InFlightMissionDataTable->TeamMissionOutcome[playerTeam] == MissionOutcome_Loss
				|| InFlightMissionDataTable->TeamMissionOutcome[playerTeam + 1] == MissionOutcome_Victory))
		{
			// Check force weights.
			if (g_ForceWeightsFriendly < g_ForceWeightsEnemy)
			{
				unsigned __int16 friendlyForcesRatio = GetPercentage16bit(g_ForceWeightsFriendly, g_ForceWeightsEnemy);
				if (friendlyForcesRatio < 57344)
				{
					if (friendlyForcesRatio < 32768)
					{
						// Friendly forces at less than 50% strength compared to enemy.
						// Play Panic music.
						newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam;
						/*if (*g_iMuseCurrentMusicState != newMusicState)
							OutputDebugString(
								256,
								"Music state set to %d, way outnumbered.  Aaaaa!\n",
								MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam);*/
						PlayMusicState(newMusicState);
					}
					else
					{
						//Friendly forces are at 50%+ strength, but enemy is still stronger.
						// Play Challenge music.
						newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StChalReb : ImuseMusicState_StChalFam;
						/*if (*g_iMuseCurrentMusicState != newMusicState)
							OutputDebugString(
								256,
								"Music state set to %d, outnumbered, challenged.\n",
								MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StChalReb : ImuseMusicState_StChalFam);*/
						PlayMusicState(newMusicState);
					}
				}
				else
				{
					// Friendly Forces are at 87%+ strength, but enemy forces are stronger.
					// Play confident music.
					newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StConfReb : ImuseMusicState_StConfFam;
					/*if (*g_iMuseCurrentMusicState != newMusicState)
						OutputDebugString(
							256,
							"Music state set to %d, not good, but confident.\n",
							MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StConfReb : ImuseMusicState_StConfFam);*/
					PlayMusicState(newMusicState);
				}
			}
			else
			{
				// Friendly forces outnumber enemy forces.
				newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StConfReb : ImuseMusicState_StConfFam;
				/*if (*g_iMuseCurrentMusicState != newMusicState)
					OutputDebugString(
						256,
						"Music state set to %d, outnumbering, confident.\n",
						MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StConfReb : ImuseMusicState_StConfFam);*/

				PlayMusicState(newMusicState);
			}
		}
		else
		{
			// Only one unresolved goal remains. Play climax music.
			newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StClimReb : ImuseMusicState_StClimFam;
			/*if (*g_iMuseCurrentMusicState != newMusicState)
				OutputDebugString(
					256,
					"Music state set to %d, Climax.\n",
					MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StClimReb : ImuseMusicState_StClimFam);*/

			PlayMusicState(newMusicState);
		}
	}
	else
	{
		// Player is within 800m of a platform, starship, freighter or container. Play panic music.
		// In TIE Fighter, it only checked starships and platforms for this.
		// X-Wing did not check for this.
		// I'm keeping it as it is in XWA unless provided a good reason.
		newMusicState = MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam;
		/*if (*g_iMuseCurrentMusicState != newMusicState)
			OutputDebugString(
				256,
				"Music state set to %d, Starship: panic!\n",
				MissionFileHeader->Header.MissionType != MissionType_Family ? ImuseMusicState_StPanicReb : ImuseMusicState_StPanicFam);*/
		
		PlayMusicState(newMusicState);
	}
}

void PlayEnemyIFFMusic()
{
	int newMusicState;

	if (IsTFTC())
	{
		// This is set as it is in TIE Fighter. Rebel state will play (StEmpire) if enemy Rebels have any weight.
		// If no Rebels, IFF Red or IFF Imperial, if enemies, will play the Intrigue/INTR state (StRival).
		// Otherwise, there are hostile "neutral" IFFs such as Blue, Yellow or Purple in the area.
		// Play Police/POL (StPirate).

		if (ForceWeightsPerEnemyIFF[IFF_Rebel])
		{
			newMusicState = ImuseMusicState_StEmpire;
		}
		else if (ForceWeightsPerEnemyIFF[IFF_Red] || ForceWeightsPerEnemyIFF[IFF_Imperial])
		{
			newMusicState = ImuseMusicState_StRival;
		}
		else
		{
			newMusicState = ImuseMusicState_StPirate;
		}
	}
	else
	{
		newMusicState = ImuseMusicState_StEmpire;
	/*if (*g_iMuseCurrentMusicState != ImuseMusicState_StEmpire)
		OutputDebugString(256, "Music state set to %d, Conflict.\n", ImuseMusicState_StEmpire);*/
	}

	PlayMusicState(newMusicState);
}

void PlayMusicState(int musicState)
{
	static int musicStateDelayTimer = 0;

	if (*g_iMuseMusicStateOverride)
		musicState = *g_iMuseMusicStateOverride;

	*g_iMuseMusicStateToChangeTo = musicState;
	if (*g_iMuseCurrentMusicState != musicState)
	{
		Imuse_ChangeMusicState(musicState);
		if ((*g_iMuseCurrentMusicState == ImuseMusicState_StIntroReb
			|| *g_iMuseCurrentMusicState == ImuseMusicState_StIntroFam)
			&& (*g_iMuseMusicStateToChangeTo == ImuseMusicState_StEmpire
				|| *g_iMuseMusicStateToChangeTo == ImuseMusicState_StRival
				|| *g_iMuseMusicStateToChangeTo == ImuseMusicState_StPirate))
		{
			Imuse_ChangeMusicSequence(ImuseSequence_Sqrampreb, PlayerTable[*g_thisPlayerIndex].Region, 2);
		}
		*g_iMuseCurrentMusicState = *g_iMuseMusicStateToChangeTo;
	}

	Imuse_PlayMusic();
}

void low_string(std::string &lower)
{
	transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
}

bool IsTFTC()
{
	static bool init = false;
	static bool result = false;

	if (!init)
	{
		if (g_config.MusicLogicType == 1)
		{
			result = false;
		}
		else if (g_config.MusicLogicType == 2)
		{
			result = true;
		}
		else
		{
			std::string sVersion(GetFrontTxtString(STR_CONFIG_VERSION));
			low_string(sVersion);
			result = (sVersion.find("tie") != std::string::npos);
		}		
		init = true;
	}
	return result;
}
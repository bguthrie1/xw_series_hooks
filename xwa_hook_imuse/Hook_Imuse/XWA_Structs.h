#pragma once
#include "XWA_Enums.h"
#include "XWA_Types.h"

struct Object;

#pragma pack(push, 1)

struct Vector3_float
{
	float x;
	float y;
	float z;
};


struct PlayerTimerEntry
{
	__int16 messageTimer;
	__int16 shieldHighlightTimer;
	__int16 hullHighlightTimer;
	__int16 systemMessageTimer;
	__int16 unknownTimer;
	__int16 craftListRefreshTimer;
	__int16 goalListRefreshTimer;
	__int16 field_E;
	__int16 iMuseMissionFlowDelayTimer;
	__int16 spaceDebrisTimer;
	__int16 MissionSuccessMusicTimer;
	__int16 MissionFailureMusicTimer;
	__int16 UnusedTimer;
};

static_assert(sizeof(PlayerTimerEntry) == 26, "size of PlayerTimer Entry must be 26");

struct RotationMatrix3D
{
	__int16 Front_X;
	__int16 Front_Y;
	__int16 Front_Z;
	__int16 Right_X;
	__int16 Right_Y;
	__int16 Right_Z;
	__int16 Up_X;
	__int16 Up_Y;
	__int16 Up_Z;
};

struct PlayerCollision
{
	unsigned __int8 CollisionChecksActive;
	int CollisionCheckTimers[16];
	__int16 CollisionCheckObjectIndex[16];
	int CollisionCheckMasterCountdown;
};

struct Projectile
{
	char FiredByPlayerIndex;
	char LockStrength;
	short TargetedComponentIndex;
	short TargetCraftIndex;
	short TargetObjectTagID;
	short LaunchSpeedMPH;
};

struct CraftInstanceHardpoints
{
	__int16 ProjectileType;
	char WeaponType;
	char LaserIndex;
	char Energy;
	char Count;
	__int16 TurretCooldown;
	char MeshID;
	char HardpointID;
	__int16 TurretTargetIndex;
	__int16 TurretTargetSearchCooldown;
};

struct XwaAIData
{
	char XwaAIData_m00;
	char meshStates[5][4];
	char waypointLoopsCompleted[5][4];
	char XwaAIData_m29;
	PloEnum currentFlightPln;
	PloEnum startingFlightPlan;
	char CurrentTargetWaypoint;
	PloEnum savedAwaitingOrder;
	int CycleTime;
	int CycleTimer;
	__int16 RandomSeed;
	__int16 TargetObjectIndex;
	__int16 TargetObjectTagID;
	__int16 XwaAIData_m3C;
	char XwaAIData_m3E;
	int TargetWaypointPositionX;
	int TargetWaypointPositionY;
	int TargetWaypointPositionZ;
	int angleDistanceToWaypoint;
	int XwaAIData_m4F;
	__int16 playerAttackOrderTargetIndex;
	char XwaAIData_m55;
	__int16 DesiredPitch;
	__int16 DesiredRoll;
	__int16 DesiredYaw;
	AIManrEnum currentManr;
	char FlyState;
	int FlyStateTimer;
	int OperationStepTimer;
};

struct XwaChar
{
	__int16 AISkill;
	__int16 unk02;
	__int16 unk6A;
	char field_6[5];
	char SfoilsState;
	XwaAIData AIData;
};

struct Craft
{
	int NumberInFG;
	CraftTypeEnum CraftType;
	int LeaderCraftIndex;
	char VirtualCraftPointerSet;
	CraftState CraftState;
	char RemovedFromPlay;
	__int16 AiSkill;
	__int16 field_F;
	__int16 unknown2;
	int IsUnderBeamEffect[5];
	char SfoilsState;
	char XwaAIData_m00;
	char meshStates[5][4];
	char waypointLoopsCompleted[5][4];
	char XwaAIData_m29;
	PloEnum currentFlightPln;
	PloEnum startingFlightPlan;
	char currentTargetWaypoint;
	PloEnum savedAwaitingOrder;
	int CycleTime;
	int CycleTimer;
	__int16 RandomSeed;
	__int16 TargetObjectIndex;
	__int16 TargetObjectTagID;
	__int16 XwaAIData_m3C;
	char XwaAIData_m3E;
	int TargetWaypointPositionX;
	int TargetWaypointPositionY;
	int TargetWaypointPositionZ;
	int angleDistanceToWaypoint;
	int XwaAIData_m4F;
	__int16 playerAttackOrderTargetIndex;
	char XwaAIData_m55;
	__int16 DesiredPitch;
	__int16 DesiredRoll;
	__int16 DesiredYaw;
	AIManrEnum currentManr;
	char FlyState;
	int FlyStateTimer;
	int OperationStepTimer;
	__int16 PickedUpObjectIndex;
	__int16 field_90;
	__int16 field_92;
	__int16 field_94;
	__int16 field_96;
	__int16 field_98;
	__int16 field_9A;
	__int16 ThreatenedByIndex;
	__int16 field_9E;
	__int16 field_A0;
	__int16 field_A2;
	BYTE field_A4;
	char field_A5;
	char field_A6;
	char field_A7;
	char field_A8;
	char field_A9;
	char field_AA;
	BYTE field_AB;
	char DoneBoardedCount;
	char BeingBoarded;
	char DoneDockingCount;
	char IsDocking;
	__int16 ObjectTagID2;
	__int16 field_B2;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	__int16 TopSpeedMPH;
	__int16 SpeedPercentage;
	char RotationRelatedUnk1;
	char RotationRelatedUnk2;
	__int16 PitchRate;
	__int16 PitchPercentage;
	char PitchState;
	char RotationRelatedUnk3;
	__int16 PitchMaxPercentage;
	__int16 RollRate;
	__int16 RollPercentage;
	char RollState;
	__int16 RollMaxPercentage;
	__int16 YawRate;
	__int16 YawPercentage;
	char YawState;
	__int16 YawMaxPercentage;
	char FormationType;
	char FormationSpacing;
	char SpecialCraft;
	char field_E3;
	int DriftXPos;
	int DriftYPos;
	int DriftZPos;
	__int16 EngineThrottleInput;
	__int16 PercentOfActiveEngines;
	__int16 MissionSetSpeed;
	__int16 EngineSLAMInput;
	unsigned int HullDamageReceived;
	int CriticalDamageThreshold;
	int HullStrength;
	__int16 SystemStrength;
	int field_106;
	char field_10A;
	int TotalDmgReceived;
	int TotalDmgToPlayer;
	int TotalDmgFromCollisions;
	int TotalDmgFromTurrets;
	int TotalDmgFromMines;
	int field_11F[8];
	char field_13F[8];
	int field_147[8];
	int field_167[6];
	__int16 InitialCockpitInstruments;
	__int16 CockpitInstrumentStatus;
	__int16 InitialSubsystems;
	__int16 SubsystemStatus;
	__int16 MagTimeRemaining;
	char field_189;
	char field_18A;
	char CapturedBy;
	char AttackedByTeam[10];
	char InspectedByTeam[10];
	char CargoIndex;
	char field_1A1;
	int FrontShieldHitpoints[2];
	char ElsShields;
	char ShieldDirection;
	char NumberOfLaserSets;
	char ElsLasers;
	char NumberOfLasers;
	LaserConvergenceMode ConvergenceMode;
	__int16 LaserType[3];
	char LaserLinkStatus[3];
	char LaserAiTriggerRemain[3];
	char LaserNextHardpoint[3];
	__int16 LaserCooldown[3];
	int LaserLastFireAttempt[3];
	char NumWarheadLauncherGroups;
	__int16 WarheadType[2];
	char WarheadNextHardpoint[2];
	__int16 WarheadCooldown[2];
	__int16 LockTime;
	char BeamType;
	char ElsBeam;
	__int16 BeamEnergy;
	char BeamActive;
	__int16 BeamEffectRate;
	char field_1E5;
	char field_1E6;
	char CountermeasureType;
	char CountermeasureAmount;
	__int16 ChaffLifespan;
	__int16 FlareLifespan;
	__int16 PrimaryLasersFired;
	__int16 PrimaryLasersHit;
	__int16 SecondaryLasersFired;
	__int16 SecondaryLasersHit;
	char WarheadsFired;
	char WarheadsHit;
	char SysRepairPriority[11];
	__int16 SysRepairPercent[11];
	__int16 SysRepairTimeRemaining[11];
	char MeshState[50];
	char MeshRotationAngles[50];
	char MeshHP[50];
	__int16 field_2C4;
	char field_2C6;
	char PlayerIndex;
	__int16 field_2C8;
	char field_2CA;
	PloEnum field_2CB;
	PloEnum field_2CC;
	__int16 field_2CD;
	char EngineThrottles[16];
	CraftInstanceHardpoints Hardpoints[16];
	__int16 ObjectTagID;
	__int16 RotGunAngles[2];
	__int16 RotBeamAngles[2];
	int field_3C9[2];
	int field_3D1[2];
	char Cargo[16];
	int field_3E9;
	int field_3ED;
	int field_3F1;
	Object* pObject;
};

static_assert(sizeof(Craft) == 1017, "size of Craft must be 1017");

struct MobileObject
{
	ObjectFamily Family;
	char SpriteDrawScale;
	int SpriteScale;
	int LastUpdateTime;
	int PosXDelta;
	int PosYDelta;
	int PosZDelta;
	PlayerCollision Collisions;
	__int16 CurrentSpeedFraction;
	__int16 field_7D;
	__int16 field_7F;
	__int16 field_81;
	__int16 DeathRotationRate;
	__int16 CurrentSpeed;
	__int16 SpeedRelease;
	int CollisionPower;
	int Duration;
	__int16 TimeAlive;
	ObjectTypeEnum MotherObjectIndex;
	ObjectTypeEnum MotherObjectSpecies;
	IFFCode IFF;
	char Team;
	char MarkingColor;
	__int16 EjectionObjects;
	int field_9C;
	char InCollision;
	__int16 Velocity;
	__int16 field_A3;
	__int16 field_A5;
	__int16 field_A7;
	__int16 field_A9;
	__int16 field_AB;
	__int16 field_AD;
	__int16 field_AF;
	__int16 field_B1;
	float DeathRotationPitch;
	float DeathRotationRoll;
	float DeathRotationYaw;
	char RecalculateForwardVector;
	__int16 ForwardX;
	__int16 ForwardY;
	__int16 ForwardZ;
	char RecalculateTransformMatrix;
	RotationMatrix3D TransformMatrix;
	Projectile* pProjectile;
	Craft* pCraft;
	XwaChar* pChar;
};

static_assert(sizeof(MobileObject) == 229, "size of MobileObject must be 229");

struct Object
{
	__int16 IndexInGlobalUnit;
	ObjectTypeEnum Type;
	ObjectGenus Genus;
	char FGIndex;
	char Region;
	int PosX;
	int PosY;
	int PosZ;
	__int16 Yaw;
	__int16 Pitch;
	__int16 Roll;
	__int16 Rotation;
	__int16 field_1B;
	__int16 field_1D;
	int PlayerIndex;
	MobileObject* pMobileObject;
};

static_assert(sizeof(Object) == 39, "size of Object must be 39");

struct MissionTrigger
{
	BYTE Condition;
	BYTE VariableType;
	BYTE Variable;
	BYTE Amount;
	__int16 Parameter;
};


struct MissionTriggerPair
{
	MissionTrigger Triggers[2];
	char field_C;
	char field_D;
	BYTE AorB;
	char field_F;
};

struct TieFlightGroupOrderSecondaryTarget
{
	TriggerVariableType ClassA;
	TriggerVariableType ClassB;
	char ClassAParameter;
	char ClassBParameter;
	char Operator;
	char field_5;
};

struct TieFlightGroupOrderPrimaryTarget
{
	TriggerVariableType ClassA;
	char ClassAParameter;
	TriggerVariableType ClassB;
	char ClassBParameter;
	char Operator;
	char field_5;
};

struct TieFlightGroupWaypoint
{
	__int16 X;
	__int16 Y;
	__int16 Z;
	__int16 TieFlightGroupWaypoint_m06;
};


struct FlightGroupOrder
{
	BYTE Order;
	BYTE Throttle;
	BYTE Variable1;
	BYTE Variable2;
	__int16 Variable3;
	TieFlightGroupOrderSecondaryTarget SecondaryTarget;
	TieFlightGroupOrderPrimaryTarget PrimaryTarget;
	__int16 Speed;
	TieFlightGroupWaypoint Waypoints[8];
	char field_54[64];
};

struct FlightGroupGoal
{
	BYTE Argument;
	BYTE Condition;
	BYTE Amount;
	BYTE Points;
	char AppliesToTeams[10];
	BYTE TimeLimit;
	char field_F;
	char field_10[64];
};

static_assert(sizeof(FlightGroupGoal) == 80, "size of FlightGroupGoal must be 80");


struct FlightGroup
{
	char Name[20];
	RoleTeamEnum TacticalRoleTeam[2];
	char TacticalRoleType[2];
	char field_18;
	char GlobalCargoIndex;
	char SpecialCargoIndex;
	char field_1B[13];
	char Cargo[20];
	char SpecialCargo[20];
	char Role[25];
	char SpecialCraft;
	char RandomSpecialCraft;
	MissionObjectSpecies ObjectType;
	char NumberOfCraft;
	FGStatus Status1;
	char WarheadType;
	BeamWeaponType Beam;
	IFFCode IFF;
	char Team;
	AIRating AiRating;
	char MarkingColor;
	char RadioChannel;
	char field_75;
	char Formation;
	char FormationSpacing;
	char GlobalGroupID;
	char LeaderSpacing;
	char NumberOfWaves;
	char field_7B;
	char field_7C;
	char PlayerNumber;
	char ArriveOnlyIfPlayer;
	char PlayerCraft;
	__int16 StartingPitch;
	__int16 StartingYaw;
	__int16 StartingRoll;
	char field_86;
	char ArrivalDifficulty;
	MissionTriggerPair ArrivalTriggers[2];
	char ArrivalTriggerOperator;
	char field_A9;
	unsigned __int8 ArrivalDelayMinutes;
	unsigned __int8 ArrivalDelaySeconds;
	MissionTriggerPair DepartureTrigger;
	unsigned __int8 DepartureDelayMinutes;
	unsigned __int8 DepartureDelaySeconds;
	TieAbortConditionEnum AbortCondition;
	char field_BF;
	__int16 field_C0;
	char field_C2;
	char field_C3;
	char field_C4;
	char field_C5;
	char field_C6;
	char field_C7;
	char field_C8;
	char field_C9;
	FlightGroupOrder Orders[16];
	MissionTriggerPair JumpTriggers[16];
	FlightGroupGoal Goals[8];
	TieFlightGroupWaypoint StartPoints[4];
	char field_DAA[20];
	char field_DBE;
	char field_DBF;
	char field_DC0;
	char field_DC1;
	char field_DC2;
	char field_DC3;
	char PreventCraftNumbering;
	char field_DC5;
	char field_DC6;
	CountermeasureType CounterMeasuresType;
	char CraftExplosionTime;
	FGStatus Status2;
	char GlobalUnitID;
	char field_DCB;
	char OptionalWarheads[8];
	char OptionalBeams[6];
	char OptionalCounterMeasures[4];
	char OptionalCraftCategory;
	char OptionalCraftsId[10];
	char OptionalCraftsCount[10];
	char OptionalCraftsWaves[10];
	char PilotVoice[20];
	char field_E11;
	int PlanetId;
	char field_E16[40];
	int PlayerIndex;
};


static_assert(sizeof(FlightGroup) == 3650, "size of FlightGroup must be 3650");


struct S0x0807E88
{
	int S0x0807E88_m00;
	int S0x0807E88_m04;
	int S0x0807E88_m08;
};

struct InflightMissionData
{
	int MissionFileVersion;
	char CurrentPlayerRemovedFromPlay;
	char IsProvingGrounds;
	char field_6;
	char provingGroundsMissionSelected;
	__int16 field_8;
	__int16 field_A;
	__int16 field_C;
	__int16 field_E;
	__int16 field_10;
	__int16 field_12;
	char field_14[3];
	char TimeHours;
	char TimeMinutes;
	char TimeSeconds;
	__int16 TimeUnitsUntilNextSecond;
	char field_1C[3];
	char field_1F;
	char MissionEndMinutes;
	char field_21;
	__int16 field_22;
	__int16 currentNumberOfObjectTagIDs;
	int field_26;
	char Difficulty;
	char StarfighterCollisions;
	char CraftJumping;
	char field_2D;
	char field_2E;
	char LocatePlayers;
	char AIOpponents;
	char field_31;
	char field_32;
	char LastTeamTimeLimit;
	char field_34;
	char field_35;
	int numberOfPlayersInGame3;
	int numberOfPlayersInGame4;
	int PlayerScores[10];
	int TeamScores[10];
	__int16 field_8E[10];
	__int16 field_A2[10];
	__int16 field_B6[10];
	__int16 field_CA[10];
	__int16 FGInspectionTeamCountTable[1920];
	__int16 field_FDE[1920];
	char field_1EDE[1920];
	char field_265E;
	__int16 field_265F;
	char field_2661;
	char field_2662[30];
	char TeamMissionOutcome[30];
	__int16 field_269E[120];
	__int16 field_278E[120];
	int field_287E[10];
	char field_28A6[10];
	char field_28B0[10];
	char field_28BA[10];
	char field_28C4[64];
	int field_2904[64];
	int NumOfGlobalUnitDeployed[40];
	int RegionsCount;
	S0x0807E88 field_2AA8[25];
	char field_2BD4[25];
	S0x0807E88 field_2BED[25];
	char field_2D19[25];
};


static_assert(sizeof(InflightMissionData) == 11570, "size of InflightMissionData must be 11570");

struct ProvingGroundsPlayerData
{
	int PlayerNumber;
	int InsideOrPassedThruObject;
	int field_8;
	int field_C;
	int field_10;
	int RingsCompleted;
	int field_18;
	int ReachedEndContainer;
	int field_20;
	int CarryingR2;
	int field_28;
	int CompletedRace;
	int CompletedTime;
	int TimeLastDeath;
	int field_38;
	int Rings;
	int ControlBoxesDestroyed;
	int Laps;
	int field_48;
	int DiedLastPosX;
	int DiedLastPosY;
	int DiedLastPosZ;
	__int16 DiedLastYaw;
	__int16 DiedLastPitch;
};

static_assert(sizeof(ProvingGroundsPlayerData) == 92, "size of ProvingGroundsPlayerData must be 92");

struct ProvingGroundsData
{
	ProvingGroundsPlayerData PlayerData[8];
	char stuff[3228];
};


static_assert(sizeof(ProvingGroundsData) == 3964, "size of ProvingGroundsData must be 3964");

struct PlayerCamera
{
	int PositionX;
	int PositionY;
	int PositionZ;
	int CraftIndex;
	int RelatedToMap;
	__int16 CraftPitch;
	__int16 CraftYaw;
	__int16 CraftRoll;
	__int16 Roll;
	__int16 Pitch;
	__int16 Yaw;
	int ShakeX;
	int ShakeY;
	int ShakeZ;
	__int16 collisionPitch;
	__int16 collisionYaw;
	__int16 collisionRoll;
	__int16 field_32;
	char ViewMode1;
	char ViewMode2;
	char field_36;
	char S0x08B94E0_B48_m37;
	char unk38;
	__int16 S0x08B94E0_B48_m39;
	__int16 S0x08B94E0_B48_m3B;
	__int16 MapMode;
	__int16 S0x08B94E0_B48_m3F;
	__int16 ExternalCamera;
	int ExternalCameraZoomDist;
	__int16 S0x08B94E0_B48_m47;
	__int16 S0x08B94E0_B48_m49;
	char unk4B[2];
};


struct Player
{
	int ObjectIndex;
	int JumpNextCraftID;
	__int16 PilotRating;
	__int16 IFF;
	__int16 Team;
	__int16 FGIndex;
	char Region;
	char ParticipationState;
	char IsEjecting;
	AutopilotActionEnum AutopilotAction;
	char EnginesCount;
	char MapState;
	char Autopilot;
	char HyperspacePhase;
	char HyperingToRegion;
	char HyperspaceCooldown;
	char HyperedToRegion[5];
	int TimeInHyperspace;
	char ShowTargetBox;
	char WarheadLockState;
	__int16 CurrentTargetIndex;
	char TargetTimeTargetedSeconds;
	char TargetTimeTargetedMinutes;
	__int16 LastTargetIndex;
	__int16 CraftMemory1;
	__int16 CraftMemory2;
	__int16 CraftMemory3;
	__int16 CraftMemory4;
	char PrimarySecondaryArmed;
	char WarheadArmed;
	__int16 ComponentTargetIndex;
	__int16 field_37;
	__int16 EngineWashCraftIndex;
	__int16 EngineWashAmount;
	__int16 ThrottlePreset[2];
	char ElsPresetLasers[2];
	char ElsPresetShields[2];
	char ElsPresetBeam[2];
	__int16 EngineThrottleInput;
	char ElsLasers;
	char ElsShields;
	char ElsBeam;
	char ShieldDirection;
	char PrimaryLaserLinkStatus;
	__int16 SecondaryLaserLinkStatus;
	__int16 TiertiaryLaserLinkStatus;
	char CriticalMessageType;
	__int16 CriticalMessageTargetObjectIndex;
	char field_55;
	char field_56;
	char JoystickRollHeld;
	char field_58;
	__int16 JoystickYawDrift;
	__int16 JoystickPitchDrift;
	__int16 JoystickRollDrift;
	char JoystickTriggerFlags;
	char field_60;
	__int16 JoystickRollDelayTimer;
	char SwapXR;
	char HudActive1;
	char HudActive2;
	char SimpleHUD;
	char BottomLeftPanel;
	char BottomRightPanel;
	char ActiveWeapon;
	char field_6A;
	char ConsoleActivated;
	char MFDLeftPanelEnabled;
	char MFDRightPanelEnabled;
	HudMfdTypeEnum HudMfdType[3];
	HudMfdTypeEnum field_71[3];
	char FlightCommandMenuType;
	char FlightCommandSelection;
	char field_76;
	char field_77;
	char FlightCommandNumWingmenSelectable;
	char FlightCommandWingmanSelected;
	char WingmenAlive[7];
	int WingmenObjectIndex[7];
	int field_9D[7];
	char field_B9[12];
	char NumOfSupportCraftAvailable;
	__int16 WingmanIndexInGlobalUnit[7];
	__int16 field_D4[7];
	char field_E2[6];
	char FlightCommandReinforcementsOption;
	char ConsoleString[256];
	char field_1E9;
	__int16 ConsoleCharacterLength;
	int AiObjectIndex;
	char FlightCommandMainNumOfOptions;
	char FlightCommandWingmenNumOfOptions[8];
	char CockpitDisplayed;
	char HasCockpitOpt;
	char HasTurretOpt;
	char field_1FC;
	__int16 MousePositionX;
	__int16 MousePositionY;
	Vector3_float CockpitPositionTranformed;
	Vector3_float CockpitPosition;
	__int16 TurretIndexActive;
	__int16 NumberOfGunnerHardpoints;
	char CurrentGunnerHardpointActive;
	RotationMatrix3D GunnerRotationMatrix;
	int Score;
	int PromoPoints;
	int WorsePromoPoints;
	int field_23C;
	int field_240;
	int field_244;
	int field_248;
	__int16 EnergyWeapon1Fired;
	__int16 EnergyWeapon1Hits;
	__int16 EnergyWeapon2Fired;
	__int16 EnergyWeapon2Hits;
	__int16 WarheadsFired;
	__int16 WarheadHits;
	__int16 NumOfCraftInspected;
	__int16 NumOfSpecialCraftInspected;
	__int16 KillsOnFG[192];
	__int16 KillsSharedOnFG[192];
	__int16 KillsAssistOnFG[192];
	__int16 KillsFullOnPlayerRating[25];
	__int16 KillsSharedOnPlayerRating[25];
	__int16 KillsAssistOnPlayerRating[25];
	__int16 KillsFullOnAIRating[6];
	__int16 KillsSharedOnAIRating[6];
	__int16 KillsAssistOnAIRating[6];
	__int16 KillsFullOnPlayer[8];
	__int16 KillsSharedOnPlayer[8];
	__int16 FriendliesKilled;
	__int16 TotalLosses;
	__int16 TotalLossesByCollision;
	__int16 TotalLossesByStarship;
	__int16 TotalLossesByMine;
	__int16 KilledByFullFromPlayer[8];
	__int16 KilledBySharedFromPlayer[8];
	__int16 KilledFullByFG[192];
	__int16 KilledSharedByFG[192];
	__int16 KilledByPlayerRating[25];
	__int16 KilledByAI;
	char ChatString[50];
	char ChatStringLength;
	char MultiChatMode;
	PlayerCamera Camera;
	__int16 FlightScreenRes;
	int DirectPlayID;
	int MissionTime;
	int PosX;
	int PosY;
	int PosZ;
	__int16 Roll2;
	__int16 Pitch2;
	__int16 Yaw2;
	int Duration;
	__int16 CurrentSpeed;
	__int16 SpeedRelease;
	__int16 CurrentSpeedFraction;
	__int16 ObjectID;
	char IsEjectingDelta;
	int CriticalMessageTimer;
	int BeamActivityTimer;
	int field_BC6;
	int TimeInMissionDelta;
	char CoPilotControlled;
};


static_assert(sizeof(Player) == 3023, "size of Player must be 3023");

struct XwaTieRegion
{
	char Name[64];
	int XwaTieRegion_m40;
	char unk44[64];
};

struct MissionGlobalCargo
{
	char Cargo[64];
	BYTE unknown_0x40[4];
	BYTE Unknown1;
	BYTE unknown_0x45[3];
	BYTE Unknown2;
	BYTE Unknown3;
	BYTE Unknown4;
	BYTE Unknown5;
	BYTE unknown_0x4C[64];
};

struct S0x07B4C00_0B32
{
	char S0x07B4C00_0B32_m00[64];
	char unk40[2];
	char S0x07B4C00_0B32_m42[20];
	char unk56[1];
};

struct S0x07B4C00_1612
{
	char S0x07B4C00_1612_m00[64];
	char unk40[2];
	char S0x07B4C00_1612_m42[20];
	char unk56[1];
};


struct MissionDataFrontEndHeader
{
	char field_0;
	char field_1;
	BYTE Unknown1;
	char RandomSeed;
	char field_4;
	BYTE Unknown2;
	int field_6;
	int field_A;
	char IffNames[4][20];
	XwaTieRegion RegionNames[4];
	MissionGlobalCargo GlobalCargo[16];
	S0x07B4C00_0B32 GlobalGroupNames[32];
	S0x07B4C00_1612 field_160E[40];
	MissionType MissionType;
	BYTE IsGoalMelee;
	BYTE TimeLimitMinutes;
	BYTE EndMissionWhenComplete;
	TacticalOfficer TacticalOfficer;
	BYTE AssignedTo;
	BYTE unknown_0x23AC;
	char BriefingCodeSizeType;
	char field_23AE[60];
};


struct MissionDataFrontEndFileHeader
{
	__int16 FlightGroupsCount;
	__int16 RadioMessagesCount;
	MissionDataFrontEndHeader Header;
};

struct FGGoalCompletionTeams
{
	char FGGoalCompletionStatus[8];
};


struct FGStats
{
	char HasArrived;
	char WavesRemaining;
	char IsArrivalTriggerActivated;
	char ArrivesOnThisDifficulty;
	__int16 ArrivalDelayTime;
	__int16 SelectedWaypointIndex;
	__int16 NextSpawnCraftNumber;
	__int16 TotalShipsInFG;
	__int16 NormalCraftTriggerStats[32];
	char TotalSpecialCraft;
	char SpecialCraftTriggerStats[32];
	char NumOfCraftInspectedByTeam[10];
	char SpecialCraftInspectedByTeam[10];
	char NumNotInspectedByTeam[10];
	char NumSpecialNotInspectedByTeam[10];
	char NumOfTimesIDedByTeam[10];
	char SpecialCraftIDedByTeam[10];
	char UnknownByTeam[10];
	char UnknownByTeam_2[10];
	char UnknownByTeam_3[10];
	char UnknownByTeam_4[10];
	char UnknownByTeam_5[10];
	char UnknownByTeam_6[10];
	char UnknownByTeam_7[10];
	char UnknownByTeam_8[10];
	char UnknownByTeam_9[10];
	char UnknownByTeam_10[10];
	FGGoalCompletionTeams FGGoalCompletionStatus[10];
	char EnteredRegion[5];
	char SpecialEnteredRegion[5];
	char NumExitedRegion[5];
	char SpecialNumExitedRegion[5];
	char field_171;
};


#pragma pack(pop)
#include "targetver.h"
#include "multiplayer.h"
#include "XWAFramework.h"
#include "hex.h"
#include "config.h"


// Stack contents for function params:

// Params[1] = 2nd on stack
// Params[0] = 1st on stack
// Params[-1] = RETURN ADDRESS
// Params[-2] = EAX
// Params[-3] = EAX2
// Params[-4] = ECX
// Params[-5] = EDX
// Params[-6] = EBX
// Params[-9] = ESI
// Params[-10] = EDI
// Params[-11] = ESP
// Params[-15] = EBP

bool shiftMPressed = false;

string ConfigSimulatorBackground()
{
	vector<string> lines = GetFileLines("hook_tourmultiplayer.cfg");

	if (lines.size())
	{
		if (GetFileKeyValue(lines, "SimulatorBackground") == "" || GetFileKeyValue(lines, "SimulatorBackground") == "blank")
		{
			return "frontres\\combat\\multiplayer.bmp";
		}
		else
		{
			return GetFileKeyValue(lines, "SimulatorBackground");
		}
		
	}
	else
	{
		return "frontres\\concourse\\create.bmp";
	}

	return 0;
}

bool ConfigSettingBar()
{
	vector<string> lines = GetFileLines("hook_tourmultiplayer.cfg");

	if (lines.size())
	{
		return GetFileKeyValueInt(lines, "SettingsBar");
	}
	else
	{
		return false;
	}
		
	return 0;
}

bool ConfigCombatSimMusic()
{
	vector<string> lines = GetFileLines("hook_tourmultiplayer.cfg");

	if (lines.size())
	{
		return GetFileKeyValueInt(lines, "ChangeCombatSimMusic");
	}
	else
	{
		return true;
	}

	return 0;
}

int PatchMemoryHook(int* params)
{
	// Entry for patching memory
	hexstr_to_char_address((unsigned char*)0x692FDA, "BF602AAE009068201F6000E9DB5BE9FF");
	
	// Fix Roster FG names
	hexstr_to_char_address((unsigned char*)0x54D8AD, "0F849E581400");
	hexstr_to_char_address((unsigned char*)0x693151, "8B4424100FBF8EB82E0B004081C23E0E000039C8894424100F8C35A7EBFFE957AAEBFF");

	// Fixes FG Roster names for clients
	hexstr_to_char_address((unsigned char*)0x5721DE, "E9400B1200");
	hexstr_to_char_address((unsigned char*)0x692D23, "833D8A2AAE0003740FE85F40EDFFE8EAA8EBFFE895A9EBFFB950000000E99EF4EDFF");

	// Loads proper panel buttons for Combat and Tour directories
	hexstr_to_char_address((unsigned char*)0x544F94, "E9A6E91400");
	hexstr_to_char_address((unsigned char*)0x69393F, "B80400000083F9020F845016EBFF39C10F8C7616EBFFE94316EBFF");

	// Loads briefing button instead of Ready if Combat or Tour modes
	hexstr_to_char_address((unsigned char*)0x54508C, "E9C9E814009090");
	hexstr_to_char_address((unsigned char*)0x69395A, "833D8A2AAE00020F842E17EBFF833D8A2AAE00040F8C5017EBFFE91C17EBFF");

	// Fixes back button on Racing mode
	hexstr_to_char_address((unsigned char*)0x545349, "E92BE61400");
	hexstr_to_char_address((unsigned char*)0x693979, "B80300000083F9010F84CB19EBFF39C10F85DE19EBFFE9BE19EBFF");

	// Prevents AI Rank from being shown on Roster unless its Skirmish
	hexstr_to_char_address((unsigned char*)0x551275, "E9E11C1400");
	hexstr_to_char_address((unsigned char*)0x692F5B, "833D8A2AAE0003750AE89731ECFFE90CE3EBFFE907E3EBFF");
	hexstr_to_char_address((unsigned char*)0x5512CE, "E9A01C1400");
	hexstr_to_char_address((unsigned char*)0x692F73, "833D8A2AAE0003750AE88F43ECFFE94DE3EBFFE948E3EBFF");


	// Loads briefing text on loading screen for Combat Engagement missions
	//hexstr_to_char_address((unsigned char*)0x53199A, "E956201600");
	//hexstr_to_char_address((unsigned char*)0x6939F5, "A18A2AAE0083F8040F83D7E1E9FF83F8020F84CEE1E9FF83F8010F84C5E1E9FFE997DFE9FF");

	// Fixes player hyperspace sideways bug
	//hexstr_to_char_address((unsigned char*)0x4EF060, "E9AB00000090");

	return 0;
}

int PanelButtonsHook(int* params)
{
	int playerIsHost = DP_PlayerIsHost();
	RECT rectButton[4] = { 0,0,0,0 };
	// Orginally: 70, 449, 97, 473 
	RECT rectImpLogo[4] = { 246, 449, 263, 473 };

	CopyRectToFrom(rectButton, rectImpLogo);

	// Create Combat Engagements button
	if (*missionDirectory != MissionDirectory_Combat)
	{
		if (*thisPlayerType == PlayerType_Singleplayer || playerIsHost)
		{
			if (CreateButtonWithHighlightAndSnd(rectButton, "implogo1", "implogo1", GetFrontTxtString(STR_COMBAT), *highlightedTextColor, *normalColor, 12, "jewelsound"))
			{
				LoadSkirmishFile("temp\temp6753908", 0);
				// Fixes background
				params[-12] = 2;
				*missionDirectory = MissionDirectory_Combat;
				*combatSimScreenDisplayed = CombatSimulatorScreenType_Roster;

				if (*rightPanelState2 != 1)
				{
					*rightPanelState2 = 0;
					*rightPanelState = 1;
					PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
				}
				*leftPanelState = 4;
				if (*configDifficulty == Difficulty_NULL)
				{
					*configDifficulty = Difficulty_Easy;
				}
				LoadMissionsFromLstFile();
				SetNumOfPlayerSlotsPerTeam();
				FormatFGRoster();
				DisplayMissionDescription(missionDescriptionPtr);
				*missionDescriptionScrollPosition = 0;
				params[-1] = 0x546C6A;
			}
		}
		else
		{
			//Client Version
			CreateSelectedButton(rectButton, "implogo1", GetFrontTxtString(STR_COMBAT), *normalColor);
		}
	}
	else
	{
		// Create a selected Combat Engagements button that does nothing when clicked
		CreateSelectedButton(rectButton, "implogo1", GetFrontTxtString(STR_COMBAT), *selectedColor);
	}

	// Create Load button
	if (*missionDirectory != MissionDirectory_Skirmish)
	{
		CopyRectToFrom(rectButton, rectStandard3);
		if (*thisPlayerType == PlayerType_Singleplayer || playerIsHost)
		{
			if (CreateButtonWithHighlightAndSnd(rectButton, "load", "load", GetFrontTxtString(STR_GAME_LOAD), *highlightedTextColor, *normalColor, 13, "jewelsound"))
			{
				*combatSimScreenDisplayed = CombatSimulatorScreenType_Load;
				*battleSelectScrollMovement = 0;
				*battleSelectScrollReturnMovement = 0;
				*missionSelectedOnLoadScrn = 0;
				*loadScrnTotalMissionsListed = *missionCountInLst;
				
				signed int missionsListed = *missionCountInLst;
				int missionIndex = 0;
				char missionTitleBuffer[128];
				memset(&missionTitleBuffer, 0, 128);
				int missionIndexSelected = 0;
				MissionLSTEntry* missionLst = *(MissionLSTEntry**)0x9F4B98;
				char missionTitle[128];


				if (*missionCountInLst > 0)
				{
					do
					{
						if (missionLst[missionIndex].IsUnselectable)
						{
							*loadScrnTotalMissionsListed = --missionsListed;
						}
						else
						{
							*(char**)missionTitle = missionLst[missionIndex].MissionTitle;
							if (strcmp(missionLst[missionIndex].MissionTitle, missionTitleBuffer))
							{
								*loadScrnTotalMissionsListed = ++missionsListed;
								strcpy_s(missionTitleBuffer, missionTitle);
							}
						}
						missionIndexSelected = ++missionIndex;
					} 
					while (missionIndex < *missionCountInLst);
				}


				if (*rightPanelState2 != 3)
				{
					*rightPanelState2 = 2;
					PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
				}
			}
		}
		else
		{
			// Create Client version of button
			CreateSelectedButton(rectButton, "load", GetFrontTxtString(STR_GAME_LOAD), *normalColor);
		}
	}

	// Create Campaign button

	//RECT campaignRect[4] = { 10, 349, 17, 373 };

	//CopyRectToFrom(rectButton, campaignRect);
	//if (*missionDirectory != 5)
	//{
	//	if (*localPlayerConnectedAs == PlayerType_Singleplayer || playerIsHost)
	//	{
	//		if (CreateButtonWithHighlightAndSnd(rectButton, "azrecord", "azrecord", "Campaign", *highlightedTextColor, *normalColor, 12, "jewelsound"))
	//		{

	//		}
	//	}
	//	else
	//	{
	//		// Client version
	//		CreateSelectedButton(rectButton, "azrecord", "Campaign", *normalColor);
	//	}
	//}
	//else
	//{
	//	CreateSelectedButton(rectButton, "azrecord", "Campaign", *selectedColor);
	//}

	// Create Racing Button

	RECT racingRect[4] = { 278, 449, 295, 473 };

	CopyRectToFrom(rectButton, racingRect);

	if (*missionDirectory != MissionDirectory_Melee)
	{
		if (*thisPlayerType == PlayerType_Singleplayer || playerIsHost)
		{
			if (CreateButtonWithHighlightAndSnd(rectButton, "yard", "yard", GetFrontTxtString(STR_MELEE), *highlightedTextColor, *normalColor, 12, "jewelsound"))
			{
				params[-1] = 0x546A6E;
			}
			else
			{
				params[-1] = 0x546B59;
			}
		}
		else
		{
			// Client version
			CreateSelectedButton(rectButton, "yard", GetFrontTxtString(STR_MELEE), *normalColor);
			params[-1] = 0x546B59;
		}
	}
	else
	{
		int curX, curY;
		CreateSelectedButton(rectButton, "yard", GetFrontTxtString(STR_MELEE), *selectedColor);
		GetMousePosition(&curX, &curY);
		if (!playerIsHost || !MouseCursorCollidedWithRect(rectButton, curX, curY))
		{
			params[-1] = 0x546B59;
		}
		else
		{
			params[-1] = 0x547566;
		}
	}
	

	return 0;
}

int FixCraftSelectionTourHook(int* params)
{
	int* fg = (int*)(276 * *FGCreationSlotNum_ + 0x9F4BE0);
	if (fg[30] == MissionCraftOptions_AllFlyable || *missionDirectory == MissionDirectory_Melee)
	{
		*FGCreationSelectCraftMenu = FGCreationSelectCraftMenu_AutoDetect;
		params[-1] = 0x5514DB;
	}
	else if (fg[30] == MissionCraftOptions_None)
	{
		params[-1] = 0x551503;
	}
	else if (fg[30] == MissionCraftOptions_AllRebelFlyable || fg[30] == MissionCraftOptions_AllImperialFlyable)
	{
		if (fg[30] == MissionCraftOptions_AllRebelFlyable)
			*FGCreationSelectCraftMenu = FGCreationSelectCraftMenu_AllRebelFlyable;
		else if (fg[30] == MissionCraftOptions_AllImperialFlyable)
			*FGCreationSelectCraftMenu = FGCreationSelectCraftMenu_AllImperialFlyable;
		params[-1] = 0x551503;
	}
	else if (fg[30] == MissionCraftOptions_Custom)
	{
		int _edx = fg[31];
		int _esi = fg[32] + 1;
		fg[32] = _esi;
		if (_esi >= _edx)
		{
			fg[32] = 0;
		}
		*FGCreationSpecies = fg[fg[32] + 33];
		// 0 craft is interpreted as 0 craft so it will be buggy.
		// Set Number of craft to 1 if so.
		if (fg[fg[32] + 45] == 0)
		{
			*FGCreationNumCraft = 1;
		}
		else
		{
			*FGCreationNumCraft = fg[fg[32] + 45];
		}
		// 0 Waves on the other hand is interpreted as 1 wave which is fine.
		*FGCreationNumWaves = fg[fg[32] + 57];
		params[-1] = 0x551503;
	}
	return 0;
}

int ForcePlayerInSlotHook(int* params)
{
	if (*thisPlayerType != PlayerType_Singleplayer && *missionDirectory != MissionDirectory_Melee)
	{
		params[-1] = 0x545E07;
	}

	return 0;
}

int IFFColorsCraftSpeciesHook(int* params)
{
	__int8 targetIFF_ = params[-2];

	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x472FFA, "51");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x472FFA, "49");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x472FFA, "4A");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x472FFA, "45");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x472FFA, "55");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x472FFA, "4D");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x472FFA, "4D");
		break;
	}

	return 0;
}

int IFFColorsCraftNameHook(int* params)
{
	__int8 targetIFF_ = params[-2];


	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x4730D8, "52");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x4730D8, "4A");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x4730D8, "4B");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x4730D8, "46");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x4730D8, "56");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x4730D8, "4E");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x4730D8, "4E");
		break;
	}
	

	return 0;
}

int IFFColorsFGIDHook(int* params)
{
	__int8 targetIFF_ = params[-2];


	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x4733BA, "51");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x4733BA, "49");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x4733BA, "4A");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x4733BA, "45");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x4733BA, "55");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x4733BA, "4D");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x4733BA, "4D");
		break;
	}

	return 0;
}

int IFFColorsFGNameHook(int* params)
{
	__int8 targetIFF_ = params[-2];


	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x473452, "52");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x473452, "4A");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x473452, "4B");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x473452, "46");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x473452, "56");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x473452, "4E");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x473452, "4E");
		break;
	}

	return 0;
}

int IFFColorsPlayerTargetBoxHook(int* params)
{
	__int8 targetIFF_ = params[-2];

	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x5038C1, "3F");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x5038C1, "C3");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x5038C1, "33");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x5038C1, "3B");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x5038C1, "C2");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x5038C1, "D3");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x5038C1, "86");
		break;
	}

	return 0;
}

int IFFColorsMapPlayerTargetBoxHook(int* params)
{
	__int8 targetIFF_ = params[-2];

	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x49FA35, "3F");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x49FA35, "C3");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x49FA35, "46");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x49FA35, "3B");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x49FA35, "C2");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x49FA35, "D3");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x49FA35, "86");
		break;
	}

	return 0;
}

int IFFColorFGMapMarkerHook(int* params)
{
	__int8 targetIFF_ = params[-2];

	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x49FE66, "51");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x49FE66, "49");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x49FE66, "45");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x49FE66, "4D");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x49FE66, "4A");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x49FE66, "55");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x49FE66, "86");
		break;
	}

	return 0;
}

int IFFColorCraftListNames(int* params)
{
	__int8 targetIFF_ = params[-2];

	switch (targetIFF_)
	{
	case IFF_Rebel:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A52");
		break;
	case IFF_Imperial:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A4A");
		break;
	case IFF_Blue:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A46");
		break;
	case IFF_Yellow:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A4E");
		break;
	case IFF_Red:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A4B");
		break;
	case IFF_Purple:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A56");
		break;
	default:
		hexstr_to_char_address((unsigned char*)0x4C292E, "6A87");
		break;
	}
	return 0;
}

int IFFColorOrangeMessageHook(int* params)
{
	// Change IFF Red message to IFF Orange

	 params[-5] = *missionMessageBufferColor;

	 if (*missionMessageBufferColor == IFF_Red)
		 params[-2] = 0x4B;
	 else
		 params[-2] = MissionMessageColorTable[*missionMessageBufferColor];

	 params[-1] = 0x47A9A0;

	return 0;
}

int IFFColorOrangeMessageLogHook(int* params)
{
	// Change IFF Red message in message log to IFF Orange

	__int16 messageIFF = params[-4];

	if (messageIFF == IFF_Red)
		params[-2] = 0x4B;
	else
		params[-2] = MissionMessageColorTable[messageIFF];

	params[-1] = 0x49A159;

	return 0;
}

int LoadCancelDeleteButtonHook(int* params)
{
	params[-1] = 0x54CE44;

	if (*combatSimScreenDisplayed != CombatSimulatorScreenType_Load)
	{
		return 0;
	}

	int curX, curY;
	GetMousePosition(&curX, &curY);
	int highlightColor = *highlightedTextColor;
	RECT pRect;
	RECT pRect2;


	// Load button
	
	if (*missionDirectory == MissionDirectory_Skirmish)
	{
		SetRectDimensions(&pRect, 170, 351, 269, 425);
	}
	else
	{
		SetRectDimensions(&pRect, 220, 351, 319, 425);
	}
	
	CopyRectToFrom(&pRect2, &pRect);
	AlignRectToDatapad(&pRect2.left);
	if (MouseCursorCollidedWithRect(&pRect2, curX, curY))
	{
		highlightColor = *highlightedTextColor2;
	}
	int loadSettingClicked = CreateSettingButton(&pRect, "loadsetting", "loadsetting", 0, 10, *normalColor, 20, "settingsound");
	
	if (*missionDirectory == MissionDirectory_Skirmish)
	{
		SetRectDimensions(&pRect, 170, 351, 269, 363);
	}
	else
	{
		SetRectDimensions(&pRect, 220, 351, 319, 363);
	}
	
	UI_DisplayTextWithRect(10, GetFrontTxtString(STR_GAME_LOAD), &pRect, highlightColor);

	if (loadSettingClicked)
	{
		if (*missionDirectory == MissionDirectory_Skirmish)
		{
			if ((*(char*)*missionLstPtr + 82 * *missionSelectedOnLoadScrn + 80))
			{
				ReadSkirmishFile(*(char**)missionLstPtr + 328 * *missionSelectedOnLoadScrn, 1);
				*combatSimScreenDisplayed = 1;
			}
			else
			{
				memset(FGCreationPlayerInSlotTable, 0, 0x140);
				LoadMissionsFromLstFile();
				SetNumOfPlayerSlotsPerTeam();
				FormatFGRoster();
				DisplayMissionDescription(missionDescriptionPtr);
			}
			*missionDescriptionScrollPosition = 0;
			SyncCombatSimulatorConfig(0);
			SyncRoster(1);
			*combatSimScreenDisplayed = 1;
			*rightPanelState2 = 0;
			*dword_7833D4 = 0;
			PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
		}
		else
		{
			int missionSelected = *missionSelectedOnLoadScrn;
			int* missionLst = missionLstPtr;
			int missionOffset = (*missionLstPtr + missionSelected * 328);
			
			if (*thisPlayerType == PlayerType_Singleplayer)
			{
				missionDirectoryMissionSelected[*missionDirectory] = *(int*)(missionOffset + 320);
				int missionCount = 0;
				*missionIndexLoaded = 0;

				if (*missionCountInLst > 0)
				{
					int missionFromMissionDirectory = missionDirectoryMissionSelected[*missionDirectory];
					do
					{
						if (missionLst[82 * missionCount + 80] == missionFromMissionDirectory)
							break;
						*missionIndexLoaded = ++missionCount;
					} while (missionCount < *missionCountInLst);
				}
				LoadMissionsFromLstFile();
				SetNumOfPlayerSlotsPerTeam();
				FormatFGRoster();
				DisplayMissionDescription(missionDescriptionPtr);
				*missionDescriptionScrollPosition = 0;
				*combatSimScreenDisplayed = CombatSimulatorScreenType_Roster;
				*rightPanelState2 = 0;
				*dword_7833D4 = 0;
				PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
			}
			else
			{
				if (*(char*)(*missionLstPtr + missionSelected * 328) != '1')
				{
					int missionOffset = (*missionLstPtr + missionSelected * 328);
					missionDirectoryMissionSelected[*missionDirectory] = *(int*)(missionOffset + 320);
					int missionCount = 0;
					*missionIndexLoaded = 0;

					if (*missionCountInLst > 0)
					{
						int missionFromMissionDirectory = missionDirectoryMissionSelected[*missionDirectory];
						do
						{
							if (missionLst[82 * missionCount + 80] == missionFromMissionDirectory)
								break;
							*missionIndexLoaded = ++missionCount;
						} while (missionCount < *missionCountInLst);
					}

					LoadMissionsFromLstFile();
					SetNumOfPlayerSlotsPerTeam();
					FormatFGRoster();
					DisplayMissionDescription(missionDescriptionPtr);
					*missionDescriptionScrollPosition = 0;
					SyncCombatSimulatorConfig(0);
					*combatSimScreenDisplayed = CombatSimulatorScreenType_Roster;
					*rightPanelState2 = 0;
					*dword_7833D4 = 0;
					PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
				}
			}
		}
	}

	// Cancel Button

	highlightColor = *highlightedTextColor;
	if (*missionDirectory == MissionDirectory_Skirmish)
	{
		SetRectDimensions(&pRect, 270, 351, 369, 425);
	}
	else
	{
		SetRectDimensions(&pRect, 320, 351, 419, 425);
	}
	
	CopyRectToFrom(&pRect2, &pRect);
	AlignRectToDatapad(&pRect2.left);
	if (MouseCursorCollidedWithRect(&pRect2, curX, curY))
	{
		highlightColor = *highlightedTextColor2;
	}
	int cancelSettingClicked = CreateSettingButton(&pRect, "cancelsetting", "cancelsetting", 0, 10, *normalColor, 21, "settingsound");
	if (*missionDirectory == MissionDirectory_Skirmish)
	{
		SetRectDimensions(&pRect, 270, 351, 369, 363);
	}
	else
	{
		SetRectDimensions(&pRect, 320, 351, 419, 363);
	}
	
	UI_DisplayTextWithRect(10, GetFrontTxtString(STR_CANCEL), &pRect, highlightColor);
	if (cancelSettingClicked)
	{
		*combatSimScreenDisplayed = CombatSimulatorScreenType_Roster;
		*rightPanelState2 = 0;
		*dword_7833D4 = 0;
		PlayDirectSound("panelarm", 1, 0, 255, 12 * *configConcourseSFXVolume, 63);
	}

	if (*missionDirectory != MissionDirectory_Skirmish)
	{
		return 0;
	}

	// Delete Button

	highlightColor = *highlightedTextColor;
	SetRectDimensions(&pRect, 370, 351, 469, 425);
	CopyRectToFrom(&pRect2, &pRect);
	AlignRectToDatapad(&pRect2.left);
	if (MouseCursorCollidedWithRect(&pRect2, curX, curY))
	{
		highlightColor = *highlightedTextColor2;
	}
	int deleteButtonWasClicked = CreateSettingButton(&pRect, "deletesetting", "deletesetting", 0, 10, *normalColor, 22, "settingsound");
	SetRectDimensions(&pRect, 370, 351, 469, 363);
	UI_DisplayTextWithRect(10, GetFrontTxtString(STR_GAME_DELETE), &pRect, highlightColor);

	if (!deleteButtonWasClicked || !*missionSelectedOnLoadScrn)
	{
		return 0;
	}

	sprintf_(*mainStringBuffer, aSS_3, "skirmish", *missionLstPtr + 328 * *missionSelectedOnLoadScrn);
	remove_(*mainStringBuffer);
	LoadMissionLst(*missionDirectory);
	*missionSelectedOnLoadScrn = 0;

	params[-1] = 0x54AEE8;

	return 0;
}

int DifficultySettingHook(int* params)
{
	if (*missionDirectory == MissionDirectory_Combat || *missionDirectory == MissionDirectory_Missions)
	{
		params[-1] = 0x54C746;
	}
	else
	{
		params[-1] = 0x54C916;
	}

	return 0;
}

int CraftSelectionSettingHook(int* params)
{
	// Changes the Craft Selection setting button in different modes.
	if ((*thisPlayerType != PlayerType_Singleplayer || *missionDirectory != MissionDirectory_Skirmish || *configGoalType) && *missionDirectory != 4)
	{
		params[-1] = 0x54B4AD;
	}
	else
	{
		params[-1] = 0x54B6BB;
	}

	return 0;
}

int XVTCraftSelectionHook(int* params)
{
	// This allows XvT Craft Selection if set in the mission file.

	if (*FGCreationSelectCraftMenu != FGCreationSelectCraftMenu_AllFlyableCraft)
	{
		if (*FGCreationSelectCraftMenu != FGCreationSelectCraftMenu_AllImperialFlyable && *FGCreationSelectCraftMenu != FGCreationSelectCraftMenu_AllRebelFlyable)
		{
			// Jump to AutoDetect code
			return 0;
		}
	}

	if (*FGCreationSelectCraftMenu == FGCreationSelectCraftMenu_AllImperialFlyable || *FGCreationSelectCraftMenu == FGCreationSelectCraftMenu_AllRebelFlyable)
	{
		*FGCreationNumOfCraftListed = 6;

		char displayCraftMenuName[30];
		if (*FGCreationSelectCraftMenu == FGCreationSelectCraftMenu_AllRebelFlyable)
		{
			strcpy_s(displayCraftMenuName, GetFrontTxtString(STR_REBEL1));
			strcat_s(displayCraftMenuName, " ");
			strcat_s(displayCraftMenuName, GetFrontTxtString(STR_CRAFT_CAPS));
		}
		else
		{
			strcpy_s(displayCraftMenuName, GetFrontTxtString(STR_IMPERIAL));
			strcat_s(displayCraftMenuName, " ");
			strcat_s(displayCraftMenuName, GetFrontTxtString(STR_CRAFT_CAPS));
		}
		
		UI_CreateTransparentImage("leftframe", 70, 86);
		UI_DisplayTextWidthHeight(10, (unsigned char*)displayCraftMenuName, 70, 90, *selectedColor);
		int curX, curY;
		RECT rect;
		GetMousePosition(&curX, &curY);
		if (*FGCreationNumOfCraftListed > 16)
		{
			SetRectDimensions(&rect, 551, 90, 570, 330);
			*FGCreationScrollPosition = UI_CreateScrollBar(&rect, *FGCreationScrollPosition, *FGCreationNumOfCraftListed - 16, 0, 5, *dword_B07C6C, 10);
		}
		SetRectDimensions(&rect, 280, 90, 550, 104);
		int scrollIteration = 0;
		*FGCreationCraftIteration = 0;
		int craftInTableOffset = 0;
		if (*totalCraftInCraftTable <= 0)
		{
			params[-1] = 0x551EFE;
			return 0;
		}

		char* fgCreationCraftListString = (char*)*speciesShipListPtr;
		int statOffset = 0;
		int rectHeight = params[-8];
		while (1)
		{
			int shipFound = 0;
			if (*FGCreationPlayerNum || *FGCreationPlayerGunnerNum)
			{
				if (*&fgCreationCraftListString[statOffset + 268] && *&fgCreationCraftListString[statOffset + 276])
				{
				Locate_Ship:
					if (*FGCreationSelectCraftMenu == FGCreationSelectCraftMenu_AllRebelFlyable)
					{
						if (*&fgCreationCraftListString[statOffset + 256] == 1 || *&fgCreationCraftListString[statOffset + 256] == 2 || *&fgCreationCraftListString[statOffset + 256] == 3 || *&fgCreationCraftListString[statOffset + 256] == 4 || *&fgCreationCraftListString[statOffset + 256] == 14)
						{
							shipFound = 1;
							goto Ship_Found;
						}
					}
					else if (*FGCreationSelectCraftMenu == FGCreationSelectCraftMenu_AllImperialFlyable)
					{
						if (*&fgCreationCraftListString[statOffset + 256] == 5 || *&fgCreationCraftListString[statOffset + 256] == 6 || *&fgCreationCraftListString[statOffset + 256] == 7 || *&fgCreationCraftListString[statOffset + 256] == 8 || *&fgCreationCraftListString[statOffset + 256] == 16)
						{
							shipFound = 1;
							goto Ship_Found;
						}
					}
				}
			}
			else if (*&fgCreationCraftListString[statOffset + 260] == *FGCreationGenusSelected && *&fgCreationCraftListString[statOffset + 276])
			{
				goto Locate_Ship;
			}
		Ship_Found:
			if (shipFound)
			{
				if (scrollIteration >= *FGCreationScrollPosition)
				{
					if (GetCraftSpeciesShortNamePtr(*&fgCreationCraftListString[statOffset + 256]))
					{
						int speciesShortName = GetCraftSpeciesShortNamePtr(*((char*)*speciesShipListPtr + statOffset + 256));
						sprintf_(*mainStringBuffer, aSS_4, *speciesShipListPtr + statOffset, speciesShortName);
					}
					else
					{
						sprintf_(*mainStringBuffer, aS_0, *speciesShipListPtr + statOffset);
					}
					
					int speciesTextClicked = UI_CreateClickableText(rect.left, rectHeight + 3, *mainStringBuffer, 10, *highlightedTextColor, craftInTableOffset + 80, 0, "settingsound");
					rectHeight += 15;

					if (speciesTextClicked)
					{
						*FGCreationSpecies = *((char*)*speciesShipListPtr + statOffset + 256);
						unsigned __int16 fgCreationSpecies = *FGCreationSpecies;
						if (*FGCreationSpecies)
						{
							int fgCreationSpeciesBuffer[49];
							memset(fgCreationSpeciesBuffer, 0, 0x30u);
							GetSpeciesExternalData(fgCreationSpeciesBuffer);
							fgCreationSpecies = *FGCreationSpecies;
						}
						*FGCreationSelectCraftMenu = 0;
						if (fgCreationSpecies)
							GetShipBMP(fgCreationSpecies);
						else
							DisplayShipBMP();
						CombatSimulatorBackgrounds(0);
					}
					SetRectWidthHeight(&rect, 0, 15);
					*FGCreationCraftIteration += 1;
					unsigned int incrementedCraftIteration = *FGCreationCraftIteration + 1;
					if (*FGCreationCraftIteration >= *FGCreationNumOfCraftListed || incrementedCraftIteration >= 16)
					{
						params[-1] = 0x551EFE;
						return 0;
					}
					fgCreationCraftListString = (char*)*speciesShipListPtr;
				}
				++scrollIteration;
			}
			statOffset += 296;
			if (++craftInTableOffset >= *totalCraftInCraftTable)
			{
				params[-1] = 0x551EFE;
				return 0;
			}
		}
	}
	else
	{
		// Jump to AllFlyableCraft code
		params[-1] = 0x550338;
	}


	return 0;
}

int CombatSimMusicHook(int* params)
{
	if (ConfigCombatSimMusic())
	{
		if (*campaignIncomplete)
		{
			if (*currentMissionInCampaign >= 7)
			{
				*currentMusicPlaying = ImuseMusicState_StRival;
				if (*configDatapadMusic)
				{
					Imuse_ChangeMusicState(ImuseMusicState_StRival);
					params[-1] = 0x54397D;
					return 0;
				}
			}
			else
			{
				*currentMusicPlaying = ImuseMusicState_StRival;
				if (*configDatapadMusic)
				{
					Imuse_ChangeMusicState(ImuseMusicState_StRival);
					params[-1] = 0x54397D;
					return 0;
				}
			}
		}
		else
		{
			*currentMusicPlaying = ImuseMusicState_StRival;
			if (*configDatapadMusic)
			{
				Imuse_ChangeMusicState(ImuseMusicState_StRival);
				params[-1] = 0x54397D;
				return 0;
			}
		}
		Imuse_StopMusic();
		params[-1] = 0x54397D;
	}
	

	return 0;
}

int CombatSimBackgroundGeneralHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundBriefingHook(int* params)
{
	QuickMissionData* QuickMissionDataPtr = *(QuickMissionData**)0x9EB8E0;
	if (*thisPlayerType == PlayerType_Singleplayer && PilotDataFrontEndPtr->campaignMode == 1)
	{
		if (QuickMissionDataPtr->header.MissionType == MissionType_Azzameen)
		{
			TryLoadFrontResEntryForceEncode("frontres\\family\\markoholo.bmp", "background");
		}
		else
			TryLoadFrontResEntryForceEncode("frontres\\combat\\solo.bmp", "background");
	}
	else
	{
		TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	}
	
	return 0;
}

int CombatSimBackgroundUnknownHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundJoinRoomHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundConnectToLobbyHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundMultiHostStartedLobbyHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundDebriefingRoomHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	return 0;
}

int CombatSimBackgroundHostOrJoinHook(int* params)
{
	TryLoadFrontResEntryForceEncode((char*)ConfigSimulatorBackground().c_str(), "background");
	params[-1] = 0x53C23D;
	return 0;
}

int CombatSimSettingBarGeneral(int* params)
{
	if (ConfigSettingBar())
	{
		DrawDatapadFrontResRLETransparent("settingbar", 57, 348);
	}

	return 0;
}

int CombatSimSettingBarGeneral2(int* params)
{
	if (ConfigSettingBar())
	{
		DrawDatapadFrontResRLETransparent("settingbar", 57, 348);
	}

	return 0;
}

int CombatSimSettingBarHostOrJoinHook1(int* params)
{
	if (ConfigSettingBar())
	{
		DrawDatapadFrontResRLETransparent("settingbar", 57, 348);
	}
	params[-1] = 0x53D859;

	return 0;
}

int CombatSimSettingBarHostOrJoinHook2(int* params)
{
	if (ConfigSettingBar())
	{
		DrawDatapadFrontResRLETransparent("settingbar", 57, 348);
	}

	return 0;
}

int QuitMessageHook(int* params)
{
	// Displays a different quit message if Player is to be captured
	int playerIndex = params[-10];

	if (PlayerPtr[playerIndex].participationState == Participation_InPlay)
	{
		if (*missionType == MissionType_Skirmish
			&& *isMelee
			&& *dword_AE2A7E == 1
			&& TeamMissionOutcomeTable[3 * *(&PlayerPtr[0].team + playerIndex)] != MissionOutcome_Victory)
		{
			PlaySoundFromObject(0x3Du, 0xFFFF, playerIndex);
			DisplayMessage(InFlightStrings_MSG_END_MISSION_PENALTY, playerIndex);
		}
		else if (*numberOfPlayersInGame == 1
			&& TeamMissionOutcomeTable[3 * *(&PlayerPtr[0].team + playerIndex)] == MissionOutcome_Victory
			&& WillPlayerBeCaptured(playerIndex))
		{
			PlaySoundFromObject(0x3Du, 0xFFFF, playerIndex);
			DisplayMessage(InFlightStrings_MSG_END_MISSION_INCOMPLETE, playerIndex);
		}
		else
		{
			PlaySoundFromObject(0x43u, 0xFFFF, playerIndex);
			DisplayMessage(InFlightStrings_MSG_END_MISSION, playerIndex);
		}

		PlayerPtr[playerIndex].criticalMessageType = CriticalMsg_HangarOrQuitGame;
		PlayerPtr[playerIndex].criticalMessageTargetObjIndex = -1;
		// 8 seconds
		PlayerPtr[playerIndex].criticalMessageTimer = 1888;
	}
	else
	{
		DisplayMessage(InFlightStrings_MSG_YOU_MUST_WAIT, playerIndex);
	}

	params[-1] = 0x4FE9CB;

	return 0;
}



int HangarMultiplayerHook(int* params)
{
	int playerIndex = params[-10];
	Object* ObjectTable = *(Object **)0x7B33C4;
	int playerObjectIndex = PlayerPtr[playerIndex].objectIndex;
	__int16 playerFGIndex = PlayerPtr[playerIndex].playerFG;
	__int16 DepartMothershipFGIndex = GetFlightGroupLeaderCraft(FlightGroupPtr[playerFGIndex].DepartureMothership);
	

	// If it's multiplayer, it will act like XvT when entering a hangar. 
	// Otherwise it will act like XWA's hangar.

	if (*numberOfPlayersInGame == 1)
	{
		ReEnterHangar(PlayerPtr[playerIndex].criticalMessageTargetObjIndex);
	}
	else if (*numberOfPlayersInGame > 1)
	{
		UpdateFGStatsOfRemovedObject(playerObjectIndex, playerFGIndex, ((DepartMothershipFGIndex - PlayerPtr[playerIndex].criticalMessageTargetObjIndex) < 1u) + 0x12);

		if (*missionType != MissionType_Melee && *missionType != MissionType_Skirmish && FlightGroupPtr[playerFGIndex].numberOfWaves != 99)
		{
			PlayerPtr[playerIndex].score += 40 * CraftDefinitionPtr[GetCraftDefinitionIndex(ObjectTable[playerObjectIndex].objectSpecies)].score;
		}

		if (PlayerPtr[playerIndex].objectIndex != 0xFFFF)
		{
			PlayOrStopBeamSound(0, playerIndex);
			PlayOrStopMissileLockWarningSound(0);
		}

		ObjectTable[playerObjectIndex].objectSpecies = 0;
		SavePlayerCraftSettings(playerIndex);
		ResetUnknownPlayerPtr(ObjectTable[playerObjectIndex].MobileObjectPtr->CraftPtr);
		CheckPlayerFGForNewWave(playerFGIndex);
		if (UnableToSpawnPlayer(playerIndex, -1, 0, 0))
		{
			RemovePlayerFromPlay(playerIndex);
			DisplayRemainingPlayersMessage(playerIndex);
		}
		else if (playerIndex == *thisPlayerIndex)
		{
			// This doesn't display for some reason.
			ActivateSubMessageWithCraftName(InFlightStrings_MSG_PREVIOUS_ENTERED_HANGAR);
		}
	}
	
	return 0;
}

int UpdateRateHostJoinRoomHook(int* params)
{
	char* updateRate = 0;

	// Reset UpdateRate if needed
	if (*configUpdateRate != 8 && *configUpdateRate != 29 && *configUpdateRate != 59)
	{
		*configUpdateRate = 8;
	}
		
	if (*configUpdateRate == 8)
	{
		updateRate = "8";
	}
	else if (*configUpdateRate == 29)
	{
		updateRate = "29";
	}
	else
	{
		updateRate = "59";
	}

	

	if (UI_CreateClickableText(410 + 93, 303, updateRate, 12, *highlightedTextColor, 28, 0, "settingsound"))
	{
		if (*configUpdateRate == 8)
		{
			*configUpdateRate = 29;
		}
		else if (*configUpdateRate == 29)
		{
			*configUpdateRate = 59;
		}
		else if (*configUpdateRate == 59)
		{
			*configUpdateRate = 8;
		}
	}

	return 0;
}

int UpdateRateOptionsMenuHook(int* params)
{

	char* updateRate = 0;

	// Reset UpdateRate if needed
	if (*configUpdateRate != 8 && *configUpdateRate != 29 && *configUpdateRate != 59)
	{
		*configUpdateRate = 8;
	}

	if (*configUpdateRate == 8)
	{
		updateRate = "Update Rate   8";
	}
	else if (*configUpdateRate == 29)
	{
		updateRate = "Update Rate   29";
	}
	else
	{
		updateRate = "Update Rate   59";
	}

	if (UI_CreateClickableText(240, 280, updateRate, 15, *highlightedTextColor, 29, 0, "settingsound"))
	{
		if (*configUpdateRate == 8)
		{
			*configUpdateRate = 29;
		}
		else if (*configUpdateRate == 29)
		{
			*configUpdateRate = 59;
		}
		else if (*configUpdateRate == 59)
		{
			*configUpdateRate = 8;
		}
	}

	return 0;
}

int UpdateRateOptionsMenuClientHook(int* params)
{
	char* updateRate = 0;

	// Reset UpdateRate if needed
	if (*configUpdateRate != 8 && *configUpdateRate != 29 && *configUpdateRate != 59)
	{
		*configUpdateRate = 8;
	}

	if (*configUpdateRate == 8)
	{
		updateRate = "Update Rate   8";
	}
	else if (*configUpdateRate == 29)
	{
		updateRate = "Update Rate   29";
	}
	else
	{
		updateRate = "Update Rate   59";
	}

	UI_DisplayTextWidthHeight(15, (unsigned char*)updateRate, 240, 280, *grayedOutTextColor);

	return 0;
}

int KeyHook1(int* params)
{
	__int16 keyPressed = *keyPressedAfterLocaleAfterMapping;
	params[-4] = keyPressed;

	if (keyPressed == KeyCode_SHIFTM)
	{
		shiftMPressed = true;
		// Do what 'M' key does
		params[-1] = 0x50142B;
	}
	else
	{
		shiftMPressed = false;
	}

	return 0;
}

int MapAIHook(int* params)
{
	int playerIndex = params[0];


	if (shiftMPressed)
	{
		IsCraftJumpPossible(playerIndex, 0, 1);
	}
	else
	{
		IsCraftJumpPossible(playerIndex, 0, 0);
	}

	return 0;
}

int SpecRegionChangeHook(int* params)
{
	// Allows players to change the region on the map if they are spectating.
	// Use "m" or "shift+m" to cycle through regions.

	int playerIndex = params[-10];

	if (PlayerPtr[playerIndex].participationState == Participation_Spectating)
	{
		if (!shiftMPressed)
		{
			if (PlayerPtr[playerIndex].region + 1 == *latestNonInstantiatedRegion)
			{
				PlayerPtr[playerIndex].region = 0;
			}
			else
			{
				PlayerPtr[playerIndex].region += 1;
			}
		}
		else
		{
			if (PlayerPtr[playerIndex].region - 1 < 0)
			{
				PlayerPtr[playerIndex].region = *latestNonInstantiatedRegion - 1;
			}
			else
			{
				PlayerPtr[playerIndex].region -= 1;
			}
		}
		params[-1] = 0x501884;
	}

	return 0;
}


#pragma once
#include "hook_function.h"
#include "CheatMission.h"
#include "common.h"



static const HookFunction g_hookFunctions[] =
{
	{ 0x409B6E, CheatMissionHook },
};

static const HookPatchItem g_Patch[] =
{
	{ 0x93C0, "743A", "9090" },
	{ 0x9171, "7526", "9090"},
	{ 0x8F69, "85DB7D0233DB", "E832880B0090"}
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("Allow missions to be completed with cheats", g_Patch),
};
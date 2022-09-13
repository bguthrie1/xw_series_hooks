#pragma once
#include "hook_function.h"
#include "imuse.h"


static const HookFunction g_hookFunctions[] =
{
	{ 0x4D5356, MissionFailureTimerHook},
	{ 0x4D973F, MissionFailureTimerHook2},
	{ 0x4D51AA, MissionSuccessTimerHook},
	{ 0x49AE2A, PlayIFFArrivalMusicSequence},
	{ 0x4F4A75, ImuseMissionFlowHook},
	{ 0x410F76, GoodDestructionMusicHook},
	{ 0x4115B4, BadDestructionMusicHook},
};

static const HookPatchItem g_changeMissionFailureTimer[] =
{
	{ 0xD4751, "66C7045596DB8000AE09", "E8CA370D009090909090"},
	{ 0xD8B3A, "66C7045596DB8000AE09", "E8E1F30C009090909090"},
};

static const HookPatchItem g_changeMissionSuccessTimer[] =
{
	{ 0xD45A5, "66C7044594DB8000AE09", "E876390D009090909090"},
};

static const HookPatchItem g_playIFFMusicSequence[] =
{
	{ 0x9A224, "8B15C4337B005333DB8D0C80", "50E8F6DC100083C404C39090"},
};

static const HookPatchItem g_patchImuseMissionFlow[] =
{
	{ 0xF3E70, "A068406900", "E8AB400B00"},
};

static const HookPatchItem g_goodDestructionMusic[] =
{
	{ 0x10371, "E85A630700", "E8AA7B1900"},
	{ 0x103E5, "83C40C", "83C404"},
};

static const HookPatchItem g_badDestructionMusic[] =
{
	{ 0x109AF, "8A4C300484C9", "E86C75190090"},
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("Change Mission Failure Timer", g_changeMissionFailureTimer),
	MAKE_HOOK_PATCH("Change Mission Success Timer", g_changeMissionSuccessTimer),
	MAKE_HOOK_PATCH("Hooks the PlayIFFMusicSequence Function", g_playIFFMusicSequence),
	MAKE_HOOK_PATCH("Hooks the Imuse Mission Flow Function", g_patchImuseMissionFlow),
	MAKE_HOOK_PATCH("Hooks Good destruction music sequence", g_goodDestructionMusic),
	MAKE_HOOK_PATCH("Hooks Bad Destruction music sequence", g_badDestructionMusic),
};

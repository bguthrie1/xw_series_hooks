#pragma once
#include "hook_function.h"
#include "PA.h"


static const HookFunction g_hookFunctions[] =
{
	//{ 0x53AF76, PlayPublicAnnouncement },
	{ 0x53A0EB, SetRandomChanceToCallPAFunction},
	{ 0x53A0F1, CheckToCallPAFunction},
};

static const HookPatchItem g_setRandomChanceToCallPAFunction[] =
{
	{ 0x1394E6, "8915F02F7800", "E835EA060090"}
};

static const HookPatchItem g_checkToCallPAFunction[] =
{
	{ 0x1394EC, "392DF02F78007509", "E82FEA0600EB0A90"}
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("Hooks random chance to play Public Announcement", g_setRandomChanceToCallPAFunction),
	MAKE_HOOK_PATCH("Hooks check to play Public Announcement", g_checkToCallPAFunction),
};

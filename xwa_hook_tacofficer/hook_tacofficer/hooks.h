#pragma once
#include "hook_function.h"
#include "tacofficer.h"


static const HookFunction g_hookFunctions[] =
{
	{ 0x43A77F, TacticalOfficerHook },
};

static const HookPatchItem g_patch[] =
{
	// Tactical Officer Hook
	{ 0x39B7A, "0F8402010000", "E8A1E3160090" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("Tactical Officer Hook", g_patch),
};

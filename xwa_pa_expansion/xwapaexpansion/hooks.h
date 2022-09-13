#pragma once
#include "hook_function.h"
#include "PA.h"


static const HookFunction g_hookFunctions[] =
{
	{ 0x53AF76, PAHook },
};

static const HookPatchItem g_Patch[] =
{
	{ 0x13A371, "FF24858CB05300", "E8AADB06009090" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("PrintData", g_Patch),
};

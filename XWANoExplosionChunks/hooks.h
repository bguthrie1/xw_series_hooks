#pragma once
#include "hook_function.h"
#include "NoChunks.h"


//static const HookFunction g_hookFunctions[] =
//{
//	{ 0x4055A9, NoExplosionChunksHook},
//};

static const HookPatchItem g_Patch[] =
{
	{ 0x49A4, "833DEC0D910001", "E9360300009090" },
};

static const HookPatch g_patches[] =
{
	MAKE_HOOK_PATCH("No Explosion Chunks patch", g_Patch),
};

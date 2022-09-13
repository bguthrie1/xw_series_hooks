#pragma once
#include "hook_function.h"

bool isPatched = false;

static const HookPatchItem g_setupXWDInputHookPatch[] =
{
	{ 0xC17A0, "00000000000000000000000000000000", "506033C054505050E82BF7FEFF6158C3" },
	{ 0xC17B0, "00000000000000000000000000000000", "536033C054505050E81BF7FEFF615BC3" },
};


static const HookPatchItem g_setupTIEDInputHookPatch[] =
{
	{ 0xDAC60, "00000000000000000000000000000000", "506033C054505050E88B2CFCFF6158C3" },
	{ 0xDAC70, "00000000000000000000000000000000", "536033C054505050E87B2CFCFF615BC3" },
};


static const HookPatchItem g_setupXVTDInputHookPatch[] =
{
	{ 0x11EA46, "00000000000000000000000000000000", "506033C054505050E8C55AF9FF6158C3" },
	{ 0x11EA56, "00000000000000000000000000000000", "506033C054505050E8B55AF9FF6158C3" },
};


static const HookPatchItem g_setupBOPDInputHookPatch[] =
{
	{ 0x116612, "00000000000000000000000000000000", "506033C054505050E8F998F9FF6158C3" },
	{ 0x116622, "00000000000000000000000000000000", "536033C054505050E8E998F9FF615BC3" },
};


static const HookPatchItem g_setupXWADInputHookPatch[] =
{
	{ 0x1A7F20, "00000000000000000000000000000000", "506033C054505050E8EB42F7FF6158C3" },
	{ 0x1A7F30, "00000000000000000000000000000000", "536033C054505050E8DB42F7FF615BC3" },
};

static const HookPatch g_XWpatches[] =
{
	MAKE_HOOK_PATCH("To setup the Xwing dinput hook", g_setupXWDInputHookPatch),
};

static const HookPatch g_TIEpatches[] =
{
	MAKE_HOOK_PATCH("To setup the TIE Fighter dinput hook", g_setupTIEDInputHookPatch),
};

static const HookPatch g_XVTpatches[] =
{
	MAKE_HOOK_PATCH("To setup the Xwing vs TIE Fighter dinput hook", g_setupXVTDInputHookPatch),
};

static const HookPatch g_BOPpatches[] =
{
	MAKE_HOOK_PATCH("To setup the Balance of Power dinput hook", g_setupBOPDInputHookPatch),
};

static const HookPatch g_XWApatches[] =
{
	MAKE_HOOK_PATCH("To setup the Xwing Alliance dinput hook", g_setupXWADInputHookPatch),
};


#pragma once
#include "hook_function.h"
#include "TargetboxToggle.h"
#include "common.h"


int GetXWExe()
{
	char filename[4096];

	if (GetModuleFileName(nullptr, filename, sizeof(filename)) == 0)
	{
		return 0;
	}

	int length = strlen(filename);

	if (length >= 11 && _stricmp(filename + length - 11, "xwing95.exe") == 0
		&& *(const unsigned long long *)0x410C00 == 0x0F663F7408000000ull)
	{
		return 1;
	}
	else if (length >= 9 && _stricmp(filename + length - 9, "tie95.exe") == 0 &&
		*(const unsigned long long *)0x410C00 == 0x000051003DC3ABB0ull)
	{
		return 2;
	}
	else if (length >= 11 && _stricmp(filename + length - 11, "z_xvt__.exe") == 0 &&
		*(const unsigned long long *)0x523aec == 0x54534c2e31505352ull &&
		*(const unsigned long long *)0x410C00 == 0xE0C08FE180C28A07ull)
	{
		return 3;
	}
	// Balance of Power
	else if (length >= 11 && _stricmp(filename + length - 11, "z_xvt__.exe") == 0 &&
		*(const unsigned long long *)0x5210bc == 0x54534c2e31505352ull &&
		*(const unsigned long long *)0x410C00 == 0xC58B402444DB4024ull)
	{
		return 4;
	}
	else if (length >= 17 && _stricmp(filename + length - 17, "xwingalliance.exe") == 0 &&
		* (const unsigned long long *)0x410C00 == 0x008B94E0823B0000ull)
	{
		return 5;
	}
	else
	{
		return 0;
	}

	return 0;
}

// X-Wing

static const HookFunction g_hookFunctionsXW[] =
{
	{ 0x42AEE7, TargetboxToggleHookXW },
};

static const HookPatchItem g_PatchXW[] =
{
	{ 0x2A2E2, "E8D905FEFF", "E8B9740900" },
};

static const HookPatch g_patchesXW[] =
{
	MAKE_HOOK_PATCH("XW Targetbox Toggle hook", g_PatchXW),
};

// TIE Fighter

static const HookFunction g_hookFunctionsTF[] =
{
	{ 0x494177, TargetboxToggleHookTF },
};

static const HookPatchItem g_PatchTF[] =
{
	{ 0x93572, "E8098DF8FF", "E8E9760400" },
};

static const HookPatch g_patchesTF[] =
{
	MAKE_HOOK_PATCH("TF Targetbox Toggle hook", g_PatchTF),
};

// X-Wing VS TIE Fighter

static const HookFunction g_hookFunctionsXVT[] =
{
	{ 0x43A0A2, TargetboxToggleHookXVT },
};

static const HookPatchItem g_PatchXVT[] =
{
	{ 0x3949D, "8BB48130B77100", "E8A4550E009090" },
};

static const HookPatch g_patchesXVT[] =
{
	MAKE_HOOK_PATCH("XVT Targetbox Toggle hook", g_PatchXVT),
};

// Balance Of Power

static const HookFunction g_hookFunctionsBOP[] =
{
	{ 0x47AC33, TargetboxToggleHookBOP },
};

static const HookPatchItem g_PatchBOP[] =
{
	{ 0x7A02E, "8BB48170969E00", "E8DFC509009090" },
};

static const HookPatch g_patchesBOP[] =
{
	MAKE_HOOK_PATCH("BOP Targetbox Toggle hook", g_PatchBOP),
};

// X-Wing Alliance

static const HookFunction g_hookFunctionsXWA[] =
{
	{ 0x4FBAA1, TargetboxToggleHookXWA },
};

static const HookPatchItem g_PatchXWA[] =
{
	{ 0xFAE9C, "8B86E0948B00", "E87FD00A0090" },
};

static const HookPatch g_patchesXWA[] =
{
	MAKE_HOOK_PATCH("XWA Targetbox Toggle hook", g_PatchXWA),
};
	

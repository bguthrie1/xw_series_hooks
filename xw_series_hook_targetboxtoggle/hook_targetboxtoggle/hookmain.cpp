#include "targetver.h"
#include "hook_function.h"

#include "hooks.h"

static const int g_hookFunctionsCountXW = sizeof(g_hookFunctionsXW) / sizeof(HookFunction);
static const int g_hookFunctionsCountTF = sizeof(g_hookFunctionsTF) / sizeof(HookFunction);
static const int g_hookFunctionsCountXVT = sizeof(g_hookFunctionsXVT) / sizeof(HookFunction);
static const int g_hookFunctionsCountBOP = sizeof(g_hookFunctionsBOP) / sizeof(HookFunction);
static const int g_hookFunctionsCountXWA = sizeof(g_hookFunctionsXWA) / sizeof(HookFunction);

extern "C" __declspec(dllexport) int GetHookFunctionsCount()
{
	int XWGame = GetXWExe();

	if (XWGame == 1)
	{
		return g_hookFunctionsCountXW;
	}
	else if (XWGame == 2)
	{
		return g_hookFunctionsCountTF;
	}
	else if (XWGame == 3)
	{
		return g_hookFunctionsCountXVT;
	}
	else if (XWGame == 4)
	{
		return g_hookFunctionsCountBOP;
	}
	else if (XWGame == 5)
	{
		return g_hookFunctionsCountXWA;
	}
}

extern "C" __declspec(dllexport) HookFunction GetHookFunction(int index)
{
	auto hook = HookFunction{};

	int XWGame = GetXWExe();

	if (XWGame == 1)
	{
		if (index >= 0 && index < g_hookFunctionsCountXW)
		{
			return g_hookFunctionsXW[index];
		}
	}
	if (XWGame == 2)
	{
		if (index >= 0 && index < g_hookFunctionsCountTF)
		{
			return g_hookFunctionsTF[index];
		}
	}
	if (XWGame == 3)
	{
		if (index >= 0 && index < g_hookFunctionsCountXVT)
		{
			return g_hookFunctionsXVT[index];
		}
	}
	if (XWGame == 4)
	{
		if (index >= 0 && index < g_hookFunctionsCountBOP)
		{
			return g_hookFunctionsBOP[index];
		}
	}
	if (XWGame == 5)
	{
		if (index >= 0 && index < g_hookFunctionsCountXWA)
		{
			return g_hookFunctionsXWA[index];
		}
	}

	return hook;
}

static const int g_patchesCountXW = sizeof(g_patchesXW) / sizeof(HookPatch);
static const int g_patchesCountTF = sizeof(g_patchesTF) / sizeof(HookPatch);
static const int g_patchesCountXVT = sizeof(g_patchesXVT) / sizeof(HookPatch);
static const int g_patchesCountBOP = sizeof(g_patchesBOP) / sizeof(HookPatch);
static const int g_patchesCountXWA = sizeof(g_patchesXWA) / sizeof(HookPatch);

extern "C" __declspec(dllexport) int GetHookPatchesCount()
{
	int XWGame = GetXWExe();

	if (XWGame == 1)
	{
		return g_patchesCountXW;
	}
	else if (XWGame == 2)
	{
		return g_patchesCountTF;
	}
	else if (XWGame == 3)
	{
		return g_patchesCountXVT;
	}
	else if (XWGame == 4)
	{
		return g_patchesCountBOP;
	}
	else if (XWGame == 5)
	{
		return g_patchesCountXWA;
	}

	return g_patchesCountXW;
}

extern "C" __declspec(dllexport) const HookPatch* GetHookPatch(int index)
{
	int XWGame = GetXWExe();

	if (XWGame == 1)
	{
		if (index < 0 || index >= g_patchesCountXW)
		{
			return nullptr;
		}

		return &g_patchesXW[index];
	}
	else if (XWGame == 2)
	{
		if (index < 0 || index >= g_patchesCountTF)
		{
			return nullptr;
		}

		return &g_patchesTF[index];
	}
	else if (XWGame == 3)
	{
		if (index < 0 || index >= g_patchesCountXVT)
		{
			return nullptr;
		}

		return &g_patchesXVT[index];
	}
	else if (XWGame == 4)
	{
		if (index < 0 || index >= g_patchesCountBOP)
		{
			return nullptr;
		}

		return &g_patchesBOP[index];
	}
	else if (XWGame == 5)
	{
		if (index < 0 || index >= g_patchesCountXWA)
		{
			return nullptr;
		}

		return &g_patchesXWA[index];
	}

	if (index < 0 || index >= g_patchesCountXW)
	{
		return nullptr;
	}

	return &g_patchesXW[index];
}

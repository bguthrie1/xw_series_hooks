#include "common.h"
#include "hook.h"
#include "hook_function.h"
#include "hooks.h"

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

bool MainPatchMemory()
{
	int xwexe = GetXWExe();

	if (xwexe == 0)
	{
		return false;
	}
	else if (xwexe == 1)
	{
		auto& g_patches = g_XWpatches;

		for (const auto& patch : g_patches)
		{
			if (!PatchMemory(patch))
			{
				return false;
			}
		}
	}
	else if (xwexe == 2)
	{
		auto& g_patches = g_TIEpatches;

		for (const auto& patch : g_patches)
		{
			if (!PatchMemory(patch))
			{
				return false;
			}
		}
	}
	else if (xwexe == 3)
	{
		auto& g_patches = g_XVTpatches;

		for (const auto& patch : g_patches)
		{
			if (!PatchMemory(patch))
			{
				return false;
			}
		}
	}
	else if (xwexe == 4)
	{
		auto& g_patches = g_BOPpatches;

		for (const auto& patch : g_patches)
		{
			if (!PatchMemory(patch))
			{
				return false;
			}
		}
	}
	else if (xwexe == 5)
	{
		auto& g_patches = g_XWApatches;

		for (const auto& patch : g_patches)
		{
			if (!PatchMemory(patch))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		if (GetXWExe())
		{
			if (MainPatchMemory())
			{
				isPatched = true;
				LoadAndPatchHooks();
				VirtualProtectHookMemory();
			}
		}
		break;

	}
	case DLL_THREAD_ATTACH:
	{
		if (!isPatched && GetXWExe())
		{
			if (MainPatchMemory())
			{
				isPatched = true;
				LoadAndPatchHooks();
				VirtualProtectHookMemory();
			}
		}
		break;
	}
	case DLL_THREAD_DETACH:
	{
		if (!isPatched && GetXWExe())
		{
			if (MainPatchMemory())
			{
				isPatched = true;
				LoadAndPatchHooks();
				VirtualProtectHookMemory();
			}
		}
		break;
	}
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Hook_TourMultiplayer
{
    static class Hooks
    {
        private static HookFunction[] hookFunctions = new HookFunction[]
        {
            // Original Hook
            new HookFunction(0x528BC0, TourMultiplayer.TourMultiplayerHook),
            //new HookFunction(0x50A68D, TourMultiplayer.CampaignModePreHook),
            //new HookFunction(0x692C25, TourMultiplayer.CampaignModeHook),
            //new HookFunction(0x4730B2, TourMultiplayer.TargetIFFColorHook),
        };

        public static HookFunctionPtr[] hookFunctionsPtr = Array.ConvertAll(hookFunctions, t => t.Struct);

        private static HookPatchItem[] tourMultiplayerPatch = new HookPatchItem[]
        {
            new HookPatchItem(0x127FBB, "BF602AAE00", "E860FF0700"),
            new HookPatchItem(0x127FC0, "68201F6000", "E915A41600"),
            
            // Campaign Hook
            //new HookPatchItem(0x109A88, "E8E3E7F7FF", "E893E40900"),
            //new HookPatchItem(0x146C42, "6878336000", "E9D9B31400"),

            // Change ship name color for IFF 4 to orange
            //new HookPatchItem(0x724AD, "8A809700000084C075", "E86E5A13009090EB23"),
            //new HookPatchItem(0x723D5, "84C075046A51EB1E3C0174183C0474143C02", "A2EA8F5A00E8415B13009090EB1890909090"),

        };

        public static HookPatchItemPtr[] tourMultiplayerPatchPtr = Array.ConvertAll(tourMultiplayerPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("Tour Multiplayer Patch", tourMultiplayerPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }
}

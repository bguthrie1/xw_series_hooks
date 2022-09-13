using System;

namespace Hook_FPS
{
    static class XWHooks
    {

        private static HookPatchItem[] FPSPatch = new HookPatchItem[]
        {
            // Inflight 60 FPS
            new HookPatchItem(0x2E7EC, "BF08", "BF04"),
        };

        public static HookPatchItemPtr[] fpsPatchPtr = Array.ConvertAll(FPSPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("X-Wing 60FPS Patch", fpsPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class TIEHooks
    {

        private static HookPatchItem[] FPSPatch = new HookPatchItem[]
        {
            // Inflight 60 FPS
            new HookPatchItem(0x8CDC1, "BE07000000", "BE03000000"),
        };

        public static HookPatchItemPtr[] fpsPatchPtr = Array.ConvertAll(FPSPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("TIE Fighter 60FPS Patch", fpsPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class XVTHooks
    {

        private static HookPatchItem[] FPSPatch = new HookPatchItem[]
        {
            // Inflight 60 FPS
            new HookPatchItem(0x36F46, "83F808", "83F804"),
            new HookPatchItem(0x3706C, "83F808", "83F804"),
        };

        public static HookPatchItemPtr[] fpsPatchPtr = Array.ConvertAll(FPSPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("X-Wing vs TIE Fighter 60FPS Patch", fpsPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class BOPHooks
    {

        private static HookPatchItem[] gameplayPatch = new HookPatchItem[]
        {
            // Inflight 60 FPS
            new HookPatchItem(0x473FC, "83F808", "83F804"),
            new HookPatchItem(0x474B5, "83F808", "83F804"),
            
            // Internet option set to off by default with TCP/IP
            new HookPatchItem(0xBAE13, "C6056F73BB0001", "90909090909090"),
            new HookPatchItem(0xC91F7, "B801000000", "B800000000"),
        };

        public static HookPatchItemPtr[] gameplayPatchPtr = Array.ConvertAll(gameplayPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("Balance Of Power 60FPS Patch", gameplayPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);

    }

    static class XWAHooks
    {

        private static HookPatchItem[] FPSPatch = new HookPatchItem[]
        {
            // Inflight 60 FPS
            new HookPatchItem(0x10FBF6, "83F808", "83F804"),
            new HookPatchItem(0x10FCB2, "83F808", "83F804"),

            new HookPatchItem(0x10FBD2, "83FA08", "83FA04"),
            new HookPatchItem(0x10FC8A, "83FA08", "83FA04"),

            // Remove Frame Limit
            //new HookPatchItem(0x10FBD5, "7D24", "EB24"),

            
            

            // Hangar 60FPS
            new HookPatchItem(0x58005, "83FA08", "83FA04"),
            new HookPatchItem(0x58027, "83F908", "83F904"),
        };

        public static HookPatchItemPtr[] fpsPatchPtr = Array.ConvertAll(FPSPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("X-Wing Alliance 60FPS Patch", fpsPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }
}

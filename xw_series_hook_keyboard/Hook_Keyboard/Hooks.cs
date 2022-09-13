using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Hook_Keyboard
{
    static class XWHooks
    {
        private static HookFunction[] hookFunctions = new HookFunction[]
        {
            new HookFunction(0x4AC3AD, XWKeyboard.FlightKeyboardHook),
            new HookFunction(0x4ABAAC, XWKeyboard.FrontEndKeyboardHook),
            //new HookFunction(0x47BFDC, XWKeyboard.MessageHook)
        };

        public static HookFunctionPtr[] hookFunctionsPtr = Array.ConvertAll(hookFunctions, t => t.Struct);

        private static HookPatchItem[] keyboardPatch = new HookPatchItem[]
        {
            new HookPatchItem(0xAB7A8, "FF1574314C008B0DF8785600", "E8F35F010090EB1490909090"),
            new HookPatchItem(0xAAEA7, "C7058068560001000000", "E8F46801009090909090"),

            new HookPatchItem(0x7B3D5, "741A", "EB1A"),
        };

        public static HookPatchItemPtr[] keyboardPatchPtr = Array.ConvertAll(keyboardPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("X-Wing Keyboard Reaquire Hook", keyboardPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class TIEHooks
    {
        private static HookFunction[] hookFunctions = new HookFunction[]
        {
            new HookFunction(0x49A11D, TIEKeyboard.FlightKeyboardHook),
            new HookFunction(0x499800, TIEKeyboard.FrontEndKeyboardHook),
        };

        public static HookFunctionPtr[] hookFunctionsPtr = Array.ConvertAll(hookFunctions, t => t.Struct);

        private static HookPatchItem[] keyboardPatch = new HookPatchItem[]
        {
            new HookPatchItem(0x99518, "FF15D0C14D003B056CCA5800", "E843170400EB219090909090"),
            new HookPatchItem(0x98BFB, "C705A4AB580001000000", "E8602004009090909090"),
            new HookPatchItem(0x164C5, "741A", "EB1A"),
            // Ignore stretch check for mouse cursor
            new HookPatchItem(0xAF977, "7510", "EB10"),
            // Set Film room to use 640x480 3D hardware
            //new HookPatchItem(0x7F06F, "BD01010000", "BDFF010000"),
        };

        public static HookPatchItemPtr[] keyboardPatchPtr = Array.ConvertAll(keyboardPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("TIE Fighter Keyboard Reaquire Hook", keyboardPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class BOPHooks
    {
        private static HookFunction[] hookFunctions = new HookFunction[]
        {
            new HookFunction(0x4AA72A, BOPKeyboard.KeyboardHook)
        };

        public static HookFunctionPtr[] hookFunctionsPtr = Array.ConvertAll(hookFunctions, t => t.Struct);

        private static HookPatchItem[] keyboardPatch = new HookPatchItem[]
        {
            new HookPatchItem(0xA9B25, "FF151096BB008B0DD0DD6600", "E8E8CA060090EB2290909090"),
        };

        public static HookPatchItemPtr[] keyboardPatchPtr = Array.ConvertAll(keyboardPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("Balance Of Power Keyboard Reaquire Hook", keyboardPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }

    static class XWAHooks
    {
        private static HookFunction[] hookFunctions = new HookFunction[]
        {
            new HookFunction(0x50B5C9, XWAKeyboard.KeyboardHook)
        };

        public static HookFunctionPtr[] hookFunctionsPtr = Array.ConvertAll(hookFunctions, t => t.Struct);

        private static HookPatchItem[] keyboardPatch = new HookPatchItem[]
        {
            new HookPatchItem(0x10A9C4, "FF1588925A008B0D38AD9100", "E857D50900EB269090909090"),
        };

        public static HookPatchItemPtr[] keyboardPatchPtr = Array.ConvertAll(keyboardPatch, t => t.Struct);

        private static HookPatch[] patches = new HookPatch[]
        {
            new HookPatch("X-Wing Alliance Keyboard Reaquire Hook", keyboardPatchPtr),
        };

        public static HookPatchPtr[] patchesPtr = Array.ConvertAll(patches, t => t.Struct);
    }
}

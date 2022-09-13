using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Hook_MusicFix
{
    static class HookMain
    {
        static string processName = Process.GetCurrentProcess().ProcessName;
        static IntPtr CheckAddressPtr = new IntPtr(0x410C00);

        [DllExport(CallingConvention.Cdecl)]
        public static int GetHookPatchesCount()
        {
            if (string.Equals(processName, "xwing95", StringComparison.CurrentCultureIgnoreCase))
            {
                return XWHooks.patchesPtr.Length;
            }
            //else if (string.Equals(processName, "tie95", StringComparison.CurrentCultureIgnoreCase))
            //{
            //    return TIEHooks.patchesPtr.Length;
            //}
            //else if (string.Equals(processName, "z_xvt__", StringComparison.CurrentCultureIgnoreCase) &&
            //    Marshal.ReadByte(CheckAddressPtr, 0) == 0x07)
            //{
            //    return XVTHooks.patchesPtr.Length;
            //}
            //else if (string.Equals(processName, "z_xvt__", StringComparison.CurrentCultureIgnoreCase) &&
            //    Marshal.ReadByte(CheckAddressPtr, 0) == 0x24)
            //{
            //    return BOPHooks.patchesPtr.Length;
            //}
            //else if (string.Equals(processName, "xwingalliance", StringComparison.CurrentCultureIgnoreCase))
            //{
            //    return XWAHooks.patchesPtr.Length;
            //}
            else
            {
                return XWHooks.patchesPtr.Length;
            }
            
        }

        [DllExport(CallingConvention.Cdecl)]
        public static IntPtr GetHookPatch(int index)
        {
            if (string.Equals(processName, "xwing95", StringComparison.CurrentCultureIgnoreCase))
            {
                if (index < 0 || index >= XWHooks.patchesPtr.Length)
                {
                    return IntPtr.Zero;
                }
                return Marshal.UnsafeAddrOfPinnedArrayElement(XWHooks.patchesPtr, index);
            }
            //else if (string.Equals(processName, "tie95", StringComparison.CurrentCultureIgnoreCase))
            //{
            //    if (index < 0 || index >= TIEHooks.patchesPtr.Length)
            //    {
            //        return IntPtr.Zero;
            //    }
            //    return Marshal.UnsafeAddrOfPinnedArrayElement(TIEHooks.patchesPtr, index);
            //}
            //else if (string.Equals(processName, "z_xvt__", StringComparison.CurrentCultureIgnoreCase) &&
            //    Marshal.ReadByte(CheckAddressPtr, 0) == 0x07)
            //{
            //    if (index < 0 || index >= XVTHooks.patchesPtr.Length)
            //    {
            //        return IntPtr.Zero;
            //    }
            //    return Marshal.UnsafeAddrOfPinnedArrayElement(XVTHooks.patchesPtr, index);
            //}
            //else if (string.Equals(processName, "z_xvt__", StringComparison.CurrentCultureIgnoreCase) &&
            //    Marshal.ReadByte(CheckAddressPtr, 0) == 0x24)
            //{
            //    if (index < 0 || index >= BOPHooks.patchesPtr.Length)
            //    {
            //        return IntPtr.Zero;
            //    }
            //    return Marshal.UnsafeAddrOfPinnedArrayElement(BOPHooks.patchesPtr, index);
            //}
            //else if (string.Equals(processName, "xwingalliance", StringComparison.CurrentCultureIgnoreCase))
            //{
            //    if (index < 0 || index >= XWAHooks.patchesPtr.Length)
            //    {
            //        return IntPtr.Zero;
            //    }
            //    return Marshal.UnsafeAddrOfPinnedArrayElement(XWAHooks.patchesPtr, index);
            //}
            else
            {
                if (index < 0 || index >= XWHooks.patchesPtr.Length)
                {
                    return IntPtr.Zero;
                }

                return Marshal.UnsafeAddrOfPinnedArrayElement(XWHooks.patchesPtr, index);
            }
        }
    }
}

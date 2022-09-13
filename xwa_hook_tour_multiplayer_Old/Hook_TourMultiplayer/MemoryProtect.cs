using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Hook_TourMultiplayer
{
    public static class MemoryProtect
    {
        [DllImport("kernel32.dll")]
        static extern bool VirtualProtect(IntPtr lpAddress,
        UIntPtr dwSize, uint flNewProtect, out uint lpflOldProtect);

        static uint oldProtection;
        static uint nullProtection;
        static IntPtr Start = new IntPtr(0x500000);
        static UIntPtr Size = new UIntPtr(0x200000);

        public static void VirtualProtectFunction()
        {
            VirtualProtect(Start, Size, 0x40, out oldProtection);
        }

        public static void VirtualProtectRestore()
        {
            VirtualProtect(Start, Size, oldProtection, out nullProtection);
        }

    }
}

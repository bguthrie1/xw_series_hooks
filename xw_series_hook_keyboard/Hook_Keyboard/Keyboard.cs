using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Hook_Keyboard
{
    static class XWKeyboard
    {
        [DllImport("user32.dll")]
        private static extern IntPtr GetForegroundWindow();

        public static bool GameWasSelected = true;

        public static int FlightKeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x47C2B0);
            IntPtr loadKeyboardPtr = new IntPtr(0x47BE60);
            IntPtr gameFocusedPtr = new IntPtr(0x5678F0);
            //IntPtr keyboardAquiredPtr = new IntPtr(0x4FC8B8);
            
            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;

            IntPtr selectedWindow = GetForegroundWindow();


            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    if (ConfigFile.FreezeGameAltTab)
                    {
                        Marshal.WriteByte(gameFocusedPtr, 0x1);
                    }
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
                if (ConfigFile.FreezeGameAltTab)
                {
                    Marshal.WriteByte(gameFocusedPtr, 0x0);
                }
            }

            return 0;
        }

        public static int FrontEndKeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x47C2B0);
            IntPtr loadKeyboardPtr = new IntPtr(0x47BE60);

            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;

            IntPtr selectedWindow = GetForegroundWindow();

            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
            }

            return 0;
        }

        //public static int MessageHook(IntPtr @params)
        //{
        //    //IntPtr gameFocusedPtr = new IntPtr(0x5678F0);
        //    //Marshal.WriteByte(gameFocusedPtr, 0x1);
            

        //    //IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;
        //    //MessageBoxA(windowHandle, "Direct Input Keyboard Acquire FAILED", "ERROR", 0x0);
        //    //return 0;
        //}
    }

    static class TIEKeyboard
    {
        [DllImport("user32.dll")]
        private static extern IntPtr GetForegroundWindow();
        //[DllImport("user32.dll")]
        //private static extern int SetForegroundWindow(IntPtr hwnd);


        public static bool GameWasSelected = true;

        public static int FlightKeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x4173C0);
            IntPtr loadKeyboardPtr = new IntPtr(0x416F50);
            IntPtr gameFocusedPtr = new IntPtr(0x58CA60);
            IntPtr flight_WindowSizeModePtr = new IntPtr(0x4F2AD0);
            


            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;

            IntPtr selectedWindow = GetForegroundWindow();

            
            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    if (ConfigFile.FreezeGameAltTab && Marshal.ReadInt32(flight_WindowSizeModePtr) >= 273)
                    {
                        Marshal.WriteByte(gameFocusedPtr, 0x1);
                    }
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
                if (ConfigFile.FreezeGameAltTab && Marshal.ReadInt32(flight_WindowSizeModePtr) >= 273)
                {
                    Marshal.WriteByte(gameFocusedPtr, 0x0);
                }
            }

            return 0;
        }

        public static int FrontEndKeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x4173C0);
            IntPtr loadKeyboardPtr = new IntPtr(0x416F50);
            IntPtr appActivePtr = new IntPtr(0x58ABA4);


            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;

            IntPtr selectedWindow = GetForegroundWindow();


            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
            }

            Marshal.WriteByte(appActivePtr, 0x1);

            return 0;
        }
    }
    static class BOPKeyboard
    {
        [DllImport("user32.dll")]
        private static extern IntPtr GetForegroundWindow();

        public static bool GameWasSelected = true;

        public static int KeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x443820);
            IntPtr loadKeyboardPtr = new IntPtr(0x443330);
            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;


            IntPtr selectedWindow = GetForegroundWindow();


            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
            }

            return 0;
        }
    }

    static class XWAKeyboard
    {
        [DllImport("user32.dll")]
        private static extern IntPtr GetForegroundWindow();

        public static bool GameWasSelected = true;

        public static int KeyboardHook(IntPtr @params)
        {
            IntPtr unloadKeyboardPtr = new IntPtr(0x42B4A0);
            IntPtr loadKeyboardPtr = new IntPtr(0x42AF80);
            IntPtr windowHandle = Process.GetCurrentProcess().MainWindowHandle;


            IntPtr selectedWindow = GetForegroundWindow();


            if (selectedWindow == windowHandle)
            {
                if (!GameWasSelected)
                {
                    GameWasSelected = true;
                    Invoker.InvokeCallback(unloadKeyboardPtr);
                    Invoker.InvokeCallback(loadKeyboardPtr);
                }
            }
            else
            {
                GameWasSelected = false;
            }

            return 0;
        }
    }
}

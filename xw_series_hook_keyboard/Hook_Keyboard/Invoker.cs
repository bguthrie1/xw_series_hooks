using System;
using System.Runtime.InteropServices;

namespace Hook_Keyboard
{
    public static class Invoker
    {
        private delegate void CallbackDelegate();
        
        public static int InvokeCallback(IntPtr address)
        {
            var callback = (CallbackDelegate)Marshal.GetDelegateForFunctionPointer(address, typeof(CallbackDelegate));
            callback();

            return 0;
        }
    }
}

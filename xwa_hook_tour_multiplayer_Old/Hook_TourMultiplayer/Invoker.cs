using System;
using System.Runtime.InteropServices;

namespace Hook_TourMultiplayer
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

        private delegate int CallbackParamDelegate(int param);
        
        public static int InvokeCallbackParam(IntPtr address, int param)
        {
            var callback = (CallbackParamDelegate)Marshal.GetDelegateForFunctionPointer(address, typeof(CallbackParamDelegate));
            callback(param);

            return 0;
        }
    }
}

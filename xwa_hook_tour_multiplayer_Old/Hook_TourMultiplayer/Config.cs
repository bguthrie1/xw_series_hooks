using System;
using System.IO;

namespace Hook_TourMultiplayer
{
    static class ConfigFile
    {
        static ConfigFile()
        {
            const string path = "hook_tourmultiplayer.cfg";

            if (!File.Exists(path))
            {
                using (StreamWriter sw = File.CreateText(path))
                {
                    sw.WriteLine("; hook_tourmultiplayer.cfg");
                    sw.WriteLine("");
                    sw.WriteLine("; XvtSimulatorBackground = 0 (no) or 1 (yes)");
                    sw.WriteLine("; When set to 0, combat simulator will have the default background and music.");
                    sw.WriteLine("; When set to 1, the combat simulator will have different music and an XvT background.");
                    sw.WriteLine("XvtSimulatorBackground = 1");
                }
            }

            using (StreamReader sr = new StreamReader(path))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    if (string.IsNullOrEmpty(line))
                    {
                        continue;
                    }

                    if (line[0] == '#' || line[0] == ';' || (line[0] == '/' && line[1] == '/'))
                    {
                        continue;
                    }

                    int pos = line.IndexOf('=');

                    if (pos == -1)
                    {
                        continue;
                    }

                    string name = line.Substring(0, pos).Trim();
                    string value = line.Substring(pos + 1).Trim();

                    if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(value))
                    {
                        continue;
                    }

                    if (name.Equals("xvtsimulatorbackground", StringComparison.OrdinalIgnoreCase))
                    {
                        XvtSimulatorBackground = value.Equals("1", StringComparison.OrdinalIgnoreCase);
                    }
                }
            }
        }

        public static bool XvtSimulatorBackground { get; } = true;
    }
}

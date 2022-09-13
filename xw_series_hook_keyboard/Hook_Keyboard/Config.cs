using System;
using System.IO;

namespace Hook_Keyboard
{
    static class ConfigFile
    {
        public static bool ConfigWasCreated = false;

        static ConfigFile()
        {
            const string path = "hook_keyboard.cfg";

            if (!ConfigWasCreated && !File.Exists(path))
            {
                using (StreamWriter sw = File.CreateText(path))
                {
                    sw.WriteLine("; hook_keyboard.cfg");
                    sw.WriteLine("");
                    sw.WriteLine("; FreezeGameAltTab = 0 (no) or 1 (yes)");
                    sw.WriteLine("; When set to 0, game will continue running in the background and take keyboard input.");
                    sw.WriteLine("; When set to 1, game will be frozen and not take any keyboard input (Does not apply to X-Wing vs TIE Fighter or X-Wing Alliance).");
                    sw.WriteLine("FreezeGameAltTab = 1");
                }
            }
            else
            {
                ConfigWasCreated = true;
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

                    if (name.Equals("FreezeGameAltTab", StringComparison.OrdinalIgnoreCase))
                    {
                        FreezeGameAltTab = value.Equals("1", StringComparison.OrdinalIgnoreCase);
                    }
                }
            }
        }

        public static bool FreezeGameAltTab { get; } = true;
    }
}

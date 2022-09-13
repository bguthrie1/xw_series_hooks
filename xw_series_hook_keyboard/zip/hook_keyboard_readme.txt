*** Description ***

- This hook will bring back keyboard functionality after using alt+tab. 
- You can also have the game freeze in flight after using alt+tab by changing the value in the config.

*** Requirements ***

- Either X-Wing, TIE Fighter, Balance of Power or X-Wing Alliance
- .NET Framework 4
- xw_series_hook_main

*** Install ***

Place hook_keyboard.dll in the folder with the game exe. Ex. Balance of Power would be in the XvT\BalanceOfPower\z_xvt__.exe

*** Credits ***

- Blake Guthrie (Justagai)
- Jérémy Ansel (JeremyaFr) for his work on the main hook and other hooks

*** Changelog ***

1.0.6
- Updated hook to be able to be used with xw_series_hook_main (dinput.dll) version 1.0.0.2 (WILL NOT WORK WITH PREVIOUS VERSIONS)
- Fixed hangup with TIE Fighter when loading a mission with an 8-bit resolution or when loading a film.
- Fixes cursor disappearing with TIE Fighter when alt+tabbing in a room set with 320x200 resolution.
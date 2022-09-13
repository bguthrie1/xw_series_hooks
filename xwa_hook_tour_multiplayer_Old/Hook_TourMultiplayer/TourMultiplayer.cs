using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Reflection;
using System.Reflection.Emit;

namespace Hook_TourMultiplayer
{
    static class TourMultiplayer
    {
        public static int TourMultiplayerHook(IntPtr @params)
        {
            MemoryProtect.VirtualProtectFunction();

            // Entry point for function
            IntPtr BeginPtr = new IntPtr(0x692FDA);
            IntPtr BeginPtr2 = new IntPtr(0x692FE0);
            IntPtr BeginPtr3 = new IntPtr(0x692FE5);

            // Tour in Multiplayer
            IntPtr bufferPtr5 = new IntPtr(0x546B60);
            IntPtr bufferPtr6 = new IntPtr(0x5469F9);
            IntPtr bufferPtr7 = new IntPtr(0x546A4F);
            IntPtr bufferPtr8 = new IntPtr(0x546A1F);
            IntPtr bufferPtr9 = new IntPtr(0x546A44);
            IntPtr bufferPtr10 = new IntPtr(0x5464DA);
            IntPtr bufferPtr11 = new IntPtr(0x54B4AD);
            //IntPtr bufferPtr12 = new IntPtr(0x54DBEC);
            IntPtr bufferPtr13 = new IntPtr(0x565778);
            IntPtr bufferPtr14 = new IntPtr(0x54C730);
            IntPtr bufferPtr15 = new IntPtr(0x546407);
            IntPtr bufferPtr16 = new IntPtr(0x543BD2);
            IntPtr bufferPtr17 = new IntPtr(0x506574);
            IntPtr bufferPtr18 = new IntPtr(0x4FBF94);
            IntPtr bufferPtr19 = new IntPtr(0x546B9A);
            //IntPtr bufferPtr20 = new IntPtr(0x545350); // obsolete
            IntPtr bufferPtr21 = new IntPtr(0x457E38);
            IntPtr bufferPtr22 = new IntPtr(0x692DE9);
            IntPtr bufferPtr23 = new IntPtr(0x4730BF);
            IntPtr bufferPtr24 = new IntPtr(0x69301E);
            IntPtr bufferPtr25 = new IntPtr(0x472FE1);
            IntPtr bufferPtr26 = new IntPtr(0x693036);
            IntPtr bufferPtr27 = new IntPtr(0x401689);
            IntPtr bufferPtr28 = new IntPtr(0x49FBFF);
            IntPtr bufferPtr29 = new IntPtr(0x5037EE);
            IntPtr bufferPtr30 = new IntPtr(0x503816);
            IntPtr bufferPtr31 = new IntPtr(0x49FA26);
            IntPtr bufferPtr32 = new IntPtr(0x69304E);
            IntPtr bufferPtr33 = new IntPtr(0x5038B4);
            IntPtr bufferPtr34 = new IntPtr(0x6930AA);
            IntPtr bufferPtr35 = new IntPtr(0x6930F8);
            IntPtr bufferPtr36 = new IntPtr(0x546A87);
            IntPtr bufferPtr37 = new IntPtr(0x69311F);
            IntPtr bufferPtr38 = new IntPtr(0x54D8AD);
            IntPtr bufferPtr39 = new IntPtr(0x693151);
            IntPtr bufferPtr40 = new IntPtr(0x545DA2);
            IntPtr bufferPtr41 = new IntPtr(0x546683);
            IntPtr bufferPtr42 = new IntPtr(0x693174);
            IntPtr bufferPtr43 = new IntPtr(0x692FA4);
            IntPtr bufferPtr44 = new IntPtr(0x6931A2);
            IntPtr bufferPtr45 = new IntPtr(0x5514C0);
            IntPtr bufferPtr46 = new IntPtr(0x692FC5);
            IntPtr bufferPtr47 = new IntPtr(0x5465B6);
            IntPtr bufferPtr48 = new IntPtr(0x5536BA);
            IntPtr bufferPtr49 = new IntPtr(0x602FE0);
            IntPtr bufferPtr50 = new IntPtr(0x603054);
            IntPtr bufferPtr51 = new IntPtr(0x551471);
            IntPtr bufferPtr52 = new IntPtr(0x692FA9);
            IntPtr bufferPtr53 = new IntPtr(0x49FBEE);
            IntPtr bufferPtr54 = new IntPtr(0x551275);
            IntPtr bufferPtr55 = new IntPtr(0x692F5B);
            IntPtr bufferPtr56 = new IntPtr(0x5544CB);
            IntPtr bufferPtr57 = new IntPtr(0x692F8B);
            IntPtr bufferPtr58 = new IntPtr(0x5512CE);
            IntPtr bufferPtr59 = new IntPtr(0x692F73);
            IntPtr bufferPtr60 = new IntPtr(0x549D76);
            IntPtr bufferPtr61 = new IntPtr(0x692F45);
            IntPtr bufferPtr62 = new IntPtr(0x40184B);
            IntPtr bufferPtr63 = new IntPtr(0x40184F);
            IntPtr bufferPtr64 = new IntPtr(0x401850);
            IntPtr bufferPtr65 = new IntPtr(0x5014D5);
            IntPtr bufferPtr66 = new IntPtr(0x692F2D);
            IntPtr bufferPtr67 = new IntPtr(0x4F804F);
            IntPtr bufferPtr68 = new IntPtr(0x692F04);
            //IntPtr bufferPtr69 = new IntPtr(0x54D30D);
            //IntPtr bufferPtr70 = new IntPtr(0x692EE5);
            IntPtr bufferPtr71 = new IntPtr(0x546BBF);
            IntPtr bufferPtr72 = new IntPtr(0x546BC8);
            IntPtr bufferPtr73 = new IntPtr(0x546F58);
            IntPtr bufferPtr74 = new IntPtr(0x546F81);
            IntPtr bufferPtr75 = new IntPtr(0x546BB4);
            IntPtr bufferPtr76 = new IntPtr(0x546F72);
            //IntPtr bufferPtr77 = new IntPtr(0x4EF060);
            IntPtr bufferPtr78 = new IntPtr(0x49FE6C);
            IntPtr bufferPtr79 = new IntPtr(0x692EEB);
            IntPtr bufferPtr80 = new IntPtr(0x49FDDF);
            IntPtr bufferPtr81 = new IntPtr(0x53D113);
            IntPtr bufferPtr82 = new IntPtr(0x692ECC);
            IntPtr bufferPtr83 = new IntPtr(0x53D17E);
            IntPtr bufferPtr84 = new IntPtr(0x692EA3);
            IntPtr bufferPtr85 = new IntPtr(0x528852);
            IntPtr bufferPtr86 = new IntPtr(0x692E89);
            IntPtr bufferPtr87 = new IntPtr(0x52889D);
            IntPtr bufferPtr88 = new IntPtr(0x692E63);
            IntPtr bufferPtr89 = new IntPtr(0x53D34E);
            IntPtr bufferPtr90 = new IntPtr(0x52974C);
            IntPtr bufferPtr91 = new IntPtr(0x543919);
            IntPtr bufferPtr92 = new IntPtr(0x543925);
            IntPtr bufferPtr93 = new IntPtr(0x54393B);
            IntPtr bufferPtr94 = new IntPtr(0x543947);
            IntPtr bufferPtr95 = new IntPtr(0x54395D);
            IntPtr bufferPtr96 = new IntPtr(0x543969);
            IntPtr bufferPtr97 = new IntPtr(0x457F36);
            IntPtr bufferPtr98 = new IntPtr(0x692DFD);
            IntPtr bufferPtr99 = new IntPtr(0x45FC56);
            IntPtr bufferPtr100 = new IntPtr(0x692DD1);
            //IntPtr bufferPtr101 = new IntPtr(0x4580D3);
            //IntPtr bufferPtr102 = new IntPtr(0x45806B);
            IntPtr bufferPtr103 = new IntPtr(0x5721DE);
            IntPtr bufferPtr104 = new IntPtr(0x692D23);
            //IntPtr bufferPtr105 = new IntPtr(0x4055AB);
            IntPtr bufferPtr106 = new IntPtr(0x5466B7);
            IntPtr bufferPtr107 = new IntPtr(0x692D89);
            IntPtr bufferPtr108 = new IntPtr(0x5466A9);
            IntPtr bufferPtr109 = new IntPtr(0x692D6C);
            IntPtr bufferPtr110 = new IntPtr(0x5466DD);
            IntPtr bufferPtr111 = new IntPtr(0x692D45);
            //IntPtr bufferPtr112 = new IntPtr(0x52BE20);
            //IntPtr bufferPtr113 = new IntPtr(0x692CCE);
            IntPtr bufferPtr114 = new IntPtr(0x43A78F);
            IntPtr bufferPtr115 = new IntPtr(0x69282C);
            IntPtr bufferPtr116 = new IntPtr(0x4C43F4);
            IntPtr bufferPtr117 = new IntPtr(0x543B1D);

            // Campaign / Custom Tour code
            IntPtr bufferPtr118 = new IntPtr(0x69295C);
            IntPtr bufferPtr119 = new IntPtr(0x60317C);
            IntPtr bufferPtr120 = new IntPtr(0x5473AF);
            IntPtr bufferPtr121 = new IntPtr(0x692C2F);
            IntPtr bufferPtr122 = new IntPtr(0x54783A);
            IntPtr bufferPtr123 = new IntPtr(0x692CCF);
            IntPtr bufferPtr124 = new IntPtr(0x546B82);
            IntPtr bufferPtr125 = new IntPtr(0x693863);
            IntPtr bufferPtr126 = new IntPtr(0x54679A);
            IntPtr bufferPtr127 = new IntPtr(0x69387D);
            IntPtr bufferPtr128 = new IntPtr(0x5467AB);
            IntPtr bufferPtr129 = new IntPtr(0x69389A);
            IntPtr bufferPtr130 = new IntPtr(0x5467B9);
            IntPtr bufferPtr131 = new IntPtr(0x6938B4);
            IntPtr bufferPtr132 = new IntPtr(0x546BE9);
            IntPtr bufferPtr133 = new IntPtr(0x6938E3);
            IntPtr bufferPtr134 = new IntPtr(0x54684B);
            IntPtr bufferPtr135 = new IntPtr(0x6938F4);
            IntPtr bufferPtr136 = new IntPtr(0x546A79);
            IntPtr bufferPtr137 = new IntPtr(0x693905);
            IntPtr bufferPtr138 = new IntPtr(0x5464D4);
            IntPtr bufferPtr139 = new IntPtr(0x693916);
            IntPtr bufferPtr140 = new IntPtr(0x546BF7);
            IntPtr bufferPtr141 = new IntPtr(0x693928);


            IntPtr bufferPtr142 = new IntPtr(0x544F94);
            IntPtr bufferPtr143 = new IntPtr(0x69393F);
            IntPtr bufferPtr144 = new IntPtr(0x54508C);
            IntPtr bufferPtr145 = new IntPtr(0x69395A);
            IntPtr bufferPtr146 = new IntPtr(0x545349);
            IntPtr bufferPtr147 = new IntPtr(0x693979);

            //Camapign / Custom Tour code
            IntPtr bufferPtr148 = new IntPtr(0x55524B);
            IntPtr bufferPtr149 = new IntPtr(0x693994);
            IntPtr bufferPtr150 = new IntPtr(0x53AAAF);
            IntPtr bufferPtr151 = new IntPtr(0x6939AC);
            IntPtr bufferPtr152 = new IntPtr(0x53AB24);
            IntPtr bufferPtr153 = new IntPtr(0x6939C3);


            //IntPtr bufferPtr154 = new IntPtr(0x546785);
            //IntPtr bufferPtr155 = new IntPtr(0x6939DA);


            IntPtr bufferPtr156 = new IntPtr(0x53199A);
            IntPtr bufferPtr157 = new IntPtr(0x6939F5);





            // Entry
            byte[] begin1 = HexStringToByteArray.StrToByteArray("BF602AAE0090");
            byte[] begin2 = HexStringToByteArray.StrToByteArray("68201F6000");
            byte[] begin3 = HexStringToByteArray.StrToByteArray("E9DB5BE9FF");

            // Tour in Multiplayer
            byte[] hex5 = HexStringToByteArray.StrToByteArray("909090909090"); // Enable Tour of Duty Button in Multiplayer
            byte[] hex6 = HexStringToByteArray.StrToByteArray("833DB4D7AB0008"); // Allow Combat Engagements and Racing missions to appear in Single player
            byte[] hex7 = HexStringToByteArray.StrToByteArray("E94EC71400"); // Combat Engagement Button Placement Part 1 (See below for part 2)
            byte[] hex8 = HexStringToByteArray.StrToByteArray("909090909090"); // Combat Engagement Button Prevent Crash
            byte[] hex9 = HexStringToByteArray.StrToByteArray("E9AFC614009090"); // Changes Racing missions hover description to Combat Engagements and vice versa depending on gamemode
            byte[] hex10 = HexStringToByteArray.StrToByteArray("909090909090"); // Enable Load/Save/Clear buttons for any gamemode
            byte[] hex11 = HexStringToByteArray.StrToByteArray("833D8A2AAE0008"); // Enable Craft Selection setting for any gamemode
            //byte[] hex12 = HexStringToByteArray.StrToByteArray("9090909090"); // Load player into first slot for multiplayer missions in singleplayer (OBSOLETE)
            byte[] hex13 = HexStringToByteArray.StrToByteArray("909090909090"); // Fix crash when loading Multiplayer mission briefings in Singleplayer
            byte[] hex14 = HexStringToByteArray.StrToByteArray("833D8A2AAE00030F84"); // Enable Difficulty setting for any gamemode except Skirmish
            byte[] hex15 = HexStringToByteArray.StrToByteArray("909090909090"); // Fix for panel
            byte[] hex16 = HexStringToByteArray.StrToByteArray("C705C4609F0005000000"); // Fix for panel 2
            byte[] hex17 = HexStringToByteArray.StrToByteArray("EB09"); // Allow waves for any gamemode set from mission file
            byte[] hex18 = HexStringToByteArray.StrToByteArray("EB08"); // Allow craft jumping for any gamemode set from mission file
            byte[] hex19 = HexStringToByteArray.StrToByteArray("909090909090"); // Allow new pilots to access Tour mode even if they haven't beaten the first mission
            //byte[] hex20 = HexStringToByteArray.StrToByteArray("771B"); // Back Button fix
            byte[] hex21 = HexStringToByteArray.StrToByteArray("E9ACAF230090"); // Hanger fix part 1
            byte[] hex22 = HexStringToByteArray.StrToByteArray("803DEC0D9100017706881DE4538000E94150DCFF"); // Hanger fix 2
            byte[] hex23 = HexStringToByteArray.StrToByteArray("E95AFF210090"); // Change ship name color for IFF 4 to orange part 1
            byte[] hex24 = HexStringToByteArray.StrToByteArray("3C04740D3C020F849D00DEFFE99C00DEFF6A4BE9A300DEFF"); // Change ship name color for IFF 4 to orange part 2
            byte[] hex25 = HexStringToByteArray.StrToByteArray("E95000220090"); // Change craft id color for IFF 4 to orange part 1
            byte[] hex26 = HexStringToByteArray.StrToByteArray("3C04740D3C020F84A7FFDDFFE9A6FFDDFF6A4AE9ADFFDDFF"); // Change craft id color for IFF 4 to orange part 2
            byte[] hex27 = HexStringToByteArray.StrToByteArray("6A2F"); // Changes Targeting box color to white
            byte[] hex28 = HexStringToByteArray.StrToByteArray("6A2F"); // Changes Targeting box color to white on map
            byte[] hex29 = HexStringToByteArray.StrToByteArray("EB15"); // Removes white target boxes in Skirmish/Melee
            byte[] hex30 = HexStringToByteArray.StrToByteArray("B2CB"); // Changes winning team Melee targeting box from purple to dark blue
            byte[] hex31 = HexStringToByteArray.StrToByteArray("E923361F00"); // Player IFF target box for map function retool part 1
            byte[] hex32 = HexStringToByteArray.StrToByteArray("85C07509C645F83FE9EDC9E0FF83F8017509C645F8C3E9DFC9E0FF83F8027509C645F833E9D1C9E0FF83F8037509C645F83BE9C3C9E0FF83F8047509C645F8C2E9B5C9E0FF83F8057509C645F8D3E9A7C9E0FFC645F83BE99EC9E0FF"); // Player IFF target box for map function retool part 2
            byte[] hex33 = HexStringToByteArray.StrToByteArray("E9F1F71800"); // Player IFF target box function retool part 1
            byte[] hex34 = HexStringToByteArray.StrToByteArray("85C07507B23FE91908E7FF83F8017507B2C3E90D08E7FF83F8027507B233E90108E7FF83F8037507B23BE9F507E7FF83F8047507B2C2E9E907E7FF83F8057507B2D3E9DD07E7FFB23BE9D607E7FF"); // Player IFF target box function retool part 2
            byte[] hex35 = HexStringToByteArray.StrToByteArray("83F80375046A5BEB1483F80475046A5AEB0B83F80175046A5BEB026A5AE8369AECFFE92C39EBFF"); // Retools Racing missions description to show Combat Engagements depending on the gamemode
            byte[] hex36 = HexStringToByteArray.StrToByteArray("E993C6140090"); // Loads Combat engagements or Racing missions depending on current gamemode part 1
            byte[] hex37 = HexStringToByteArray.StrToByteArray("50A18A2AAE0083F803750583E801EB1783F804750583E803EB0D83F801750340EB05B801000000A38A2AAE0058E93C39EBFF"); // Loads Combat engagements or Racing missions depending on current gamemode part 2
            byte[] hex38 = HexStringToByteArray.StrToByteArray("0F849E581400"); // Flight Roster Squadron name fix part 1
            byte[] hex39 = HexStringToByteArray.StrToByteArray("8B4424100FBF8EB82E0B004081C23E0E000039C8894424100F8C35A7EBFFE957AAEBFF"); // Flight Roster Squadron name fix part 2
            byte[] hex40 = HexStringToByteArray.StrToByteArray("E9FDD1140090"); // Force the player in a slot at all times unless its multiplayer or Racing part 1
            byte[] hex41 = HexStringToByteArray.StrToByteArray("E9ECCA140090909090"); // Removes save and clear buttons in every gamemode but Skirmish part 1
            byte[] hex42 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750E8D54242C68B8316000E90135EBFFE94C36EBFF"); // Removes save and clear buttons in every gamemode but Skirmish part 2
            byte[] hex43 = HexStringToByteArray.StrToByteArray("833DB4D7AB00027505E9F82DEBFF833D8A2AAE00010F84EB2DEBFFE9432EEBFF"); // Force the player in a slot at all times unless its multiplayer or Racing part 2
            byte[] hex44 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003751B682C496000C7442444200000008D44243C682C496000E99738EBFF833D8A2AAE000174DC6838336000C7442444200000008D44243C6838336000E97338EBFF"); // // Combat Engagement Button Placement Part 2
            byte[] hex45 = HexStringToByteArray.StrToByteArray("E9001B140090"); // Fix number of craft on roster going to 0 when no custom craft is set in the mission part 1
            byte[] hex46 = HexStringToByteArray.StrToByteArray("3C000F8436E5EBFF88158D4B9F00E9EEE4EBFF"); // Fix number of craft on roster going to 0 when no custom craft is set in the mission part 2
            byte[] hex47 = HexStringToByteArray.StrToByteArray("C705E8307800000000009090909090"); // Fixes an issue with the scroll button on mission load if some missions were hidden
            byte[] hex48 = HexStringToByteArray.StrToByteArray("E9F80D000090"); // Hides Mission arrow buttons unless on FG screen Part 1 (Too many bugs popped up otherwise with the arrows in place. They also look ugly and are made obsolete by the load button)
            byte[] hex49 = HexStringToByteArray.StrToByteArray("66726F6E747265735C636F6E636F757273655C6372656174652E626D7000"); // Loads the "create" (XvT) background for the Combat Simulator
            byte[] hex50 = HexStringToByteArray.StrToByteArray("00000000000000000000"); // Removes the setting bar
            //byte[] hex51 = HexStringToByteArray.StrToByteArray("E9331B1400"); // Checks craft category, part 1
            //byte[] hex52 = HexStringToByteArray.StrToByteArray("B80100000083FA000F84C3E4EBFF83FA040F84BAE4EBFFE916E5EBFF"); // Checks craft category part 2, To be moved
            byte[] hex53 = HexStringToByteArray.StrToByteArray("6AA8"); // Changes the camera target box to a bluish purple color (differentiates itself from the target box and is unlike any IFF player target box)
            byte[] hex54 = HexStringToByteArray.StrToByteArray("E9E11C1400"); // Prevents AI Rank from being shown on Roster unless its Skirmish part 1
            byte[] hex55 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750AE89731ECFFE90CE3EBFFE907E3EBFF"); // Prevents AI Rank from being shown on Roster unless its Skirmish part 2
            byte[] hex56 = HexStringToByteArray.StrToByteArray("E9BBEA130090"); // Hides Mission arrow buttons unless on FG screen Part 2
            byte[] hex57 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750B0F85B91AECFFE93215ECFFE9AF1AECFF"); // Hides Mission arrow buttons unless on FG screen Part 3
            byte[] hex58 = HexStringToByteArray.StrToByteArray("E9A01C1400"); // Prevents AI Rank from being shown on Roster unless its Skirmish part 3
            byte[] hex59 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750AE88F43ECFFE94DE3EBFFE948E3EBFF"); // Prevents AI Rank from being shown on Roster unless its Skirmish part 4
            byte[] hex60 = HexStringToByteArray.StrToByteArray("E9CA911400909090"); // Removes Load/Delete buttons on load screen part 1
            byte[] hex61 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750839F80F851B77EBFFE9236EEBFF"); // Removes Load/Delete buttons on load screen part 2
            byte[] hex62 = HexStringToByteArray.StrToByteArray("05"); // Removes S-foils from Missile Boat
            byte[] hex63 = HexStringToByteArray.StrToByteArray("05"); // Removes S-foils from Assault Gunboat
            byte[] hex64 = HexStringToByteArray.StrToByteArray("05"); // Removes S-foils from Skipray Blastboat
            byte[] hex65 = HexStringToByteArray.StrToByteArray("0F84521A1900"); // M key cycles through regions if player is out of play function part 1
            byte[] hex66 = HexStringToByteArray.StrToByteArray("508A86F0948B003C0373158086F0948B00013A86F0948B00740658E937E9E6FFB0008886F0948B0058E929E9E6FF"); // M key cycles through regions if player is out of play function part 2
            byte[] hex67 = HexStringToByteArray.StrToByteArray("E9B0AE190090"); // Prevents players from cycling invalid regions on the map part 1
            byte[] hex68 = HexStringToByteArray.StrToByteArray("8A91F0948B0039C2751A80B9F1948B0002751180B9F5948B00007408B2008891F0948B00E92851E6FF"); // Prevents players from cycling invalid regions on the map part 2
            //byte[] hex69 = HexStringToByteArray.StrToByteArray("E9D35B140090"); // Loads a battle background only if the mission value is less than 100 part 1
            //byte[] hex70 = HexStringToByteArray.StrToByteArray("83F8040F8523A5EBFF813D9E2AAE00640000007205E912A5EBFFE955A4EBFF"); // Loads a battle background only if the mission value is less than 100 part 2
            byte[] hex71 = HexStringToByteArray.StrToByteArray("68A0496000"); // Changes Tour button icon to Combat Simulator icon part 1
            byte[] hex72 = HexStringToByteArray.StrToByteArray("68A0496000"); // Changes Tour button icon to Combat Simulator icon part 2
            byte[] hex73 = HexStringToByteArray.StrToByteArray("68A0496000"); // Changes Pressed Tour button icon to Combat Simulator icon part 3
            byte[] hex74 = HexStringToByteArray.StrToByteArray("68A0496000"); // Changes Pressed Tour button icon to Combat Simulator icon part 4
            byte[] hex75 = HexStringToByteArray.StrToByteArray("6A60"); // Changes description for Tour of Duty button to "Training Exercises" part 1
            byte[] hex76 = HexStringToByteArray.StrToByteArray("6A60"); // Changes description for Tour of Duty button to "Training Exercises" part 2
            //byte[] hex77 = HexStringToByteArray.StrToByteArray("E9AB00000090"); // Fixes player hyperspace sideways bug
            byte[] hex78 = HexStringToByteArray.StrToByteArray("E97A301F00"); // Changes waypoint marker colors for IFF 1 and 4 part 1
            byte[] hex79 = HexStringToByteArray.StrToByteArray("83F801750AB84A000000E977CFE0FFB837000000E96DCFE0FF"); // Changes waypoint marker colors for IFF 1 and 4 part 2
            byte[] hex80 = HexStringToByteArray.StrToByteArray("6A2F"); // Changes normal waypoint marker color to white
            byte[] hex81 = HexStringToByteArray.StrToByteArray("E9B45D150090"); // Allows a server update rate of 30 (normal) and 8 (low) for the Connection type screen part 1
            byte[] hex82 = HexStringToByteArray.StrToByteArray("8A1D76C8B00083C41483C60A80FB1E7507B301E940A2EAFFB300E939A2EAFF"); // Allows a server update rate of 30 (normal) and 8 (low) for the Connection type screen part 2
            byte[] hex83 = HexStringToByteArray.StrToByteArray("E9205D150090"); // Allows a server update rate of 30 (normal) and 8 (low) for the Connection type screen part 3
            byte[] hex84 = HexStringToByteArray.StrToByteArray("881D76C8B00080FB08750FC70576C8B0001E000000E9C7A2EAFFC70576C8B00008000000E9B8A2EAFF"); // Allows a server update rate of 30 (normal) and 8 (low) for the Connection type screen part 4
            byte[] hex85 = HexStringToByteArray.StrToByteArray("E932A61600"); // Allows a server update rate of 30 (normal) and 8 (low) for the Settings screen part 1
            byte[] hex86 = HexStringToByteArray.StrToByteArray("A076C8B00083C4203C1E7507B001E9C359E9FFB000E9BC59E9FF"); // Allows a server update rate of 30 (normal) and 8 (low) for the Settings screen part 2
            byte[] hex87 = HexStringToByteArray.StrToByteArray("E9C1A51600"); // Allows a server update rate of 30 (normal) and 8 (low) for the Settings screen part 3
            byte[] hex88 = HexStringToByteArray.StrToByteArray("3C087511C70576C8B0001E000000B008E92A5AE9FFC70576C8B00008000000B006E9195AE9FF"); // Allows a server update rate of 30 (normal) and 8 (low) for the Settings screen part 4
            byte[] hex89 = HexStringToByteArray.StrToByteArray("C60575C8B00000"); // Sets the Internet option to off when selecting a TCP/IP game
            byte[] hex90 = HexStringToByteArray.StrToByteArray("C60575C8B00000"); // Sets the Internet option to off when launching a game with TCP/IP
            byte[] hex91 = HexStringToByteArray.StrToByteArray("C705442AAE005B040000"); // Changes the music in the Combat Simulator part 1
            byte[] hex92 = HexStringToByteArray.StrToByteArray("685B040000"); // Changes the music in the Combat Simulator part 2
            byte[] hex93 = HexStringToByteArray.StrToByteArray("C705442AAE005B040000"); // Changes the music in the Combat Simulator part 3
            byte[] hex94 = HexStringToByteArray.StrToByteArray("685B040000"); // Changes the music in the Combat Simulator part 4
            byte[] hex95 = HexStringToByteArray.StrToByteArray("C705442AAE005B040000"); // Changes the music in the Combat Simulator if loaded directly into the lobby part 1
            byte[] hex96 = HexStringToByteArray.StrToByteArray("685B040000"); // Changes the music in the Combat Simulator if loaded directly into the lobby part 2
            byte[] hex97 = HexStringToByteArray.StrToByteArray("E9C2AE2300"); // Hanger fix part 3
            byte[] hex98 = HexStringToByteArray.StrToByteArray("803DEC0D91000177346681FDFFFF890D406E9C00891D3C6E9C00891DB8BB6800891D04B68000891D54699C00890D18BC68000F846351DCFFE92751DCFF6681FDFFFFC705406E9C0001000000C705B8BB6800010000000F843F51DCFFE90351DCFF"); // Hanger fix part 4
            byte[] hex99 = HexStringToByteArray.StrToByteArray("E9763123009090909090"); // Hanger fix part 5
            byte[] hex100 = HexStringToByteArray.StrToByteArray("803DEC0D910001770AC7053C6E9C0001000000E977CEDCFF"); // Hanger fix part 6
            //byte[] hex101 = HexStringToByteArray.StrToByteArray("909090909090"); // Hanger fix part 7
            //byte[] hex102 = HexStringToByteArray.StrToByteArray("909090909090"); // Hanger fix part 8
            byte[] hex103 = HexStringToByteArray.StrToByteArray("E9400B1200"); // Fixes FG Roster names for clients part 1
            byte[] hex104 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003740FE85F40EDFFE8EAA8EBFFE895A9EBFFB950000000E99EF4EDFF"); // Fixes FG Roster names for clients part 2
            //byte[] hex105 = HexStringToByteArray.StrToByteArray("909090909090"); // Allow capital ship explosion debris in multiplayer Tour mode (WARNING: CAUSES DESYNCS)
            byte[] hex106 = HexStringToByteArray.StrToByteArray("E9CDC61400"); // Changes Save icon to mission overview icon if not Skirmish part 1
            byte[] hex107 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003751368483360008D5424446848336000E92039EBFF68905260008D5424446890526000E90D39EBFF"); // Changes Save icon to mission overview icon if not Skirmish part 2
            byte[] hex108 = HexStringToByteArray.StrToByteArray("E9BEC61400"); // Loads Save/Mission Overview description for button part 1
            byte[] hex109 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750A6865030000E92F39EBFF6891030000E92539EBFF"); // Loads Save/Mission Overview description for button part 2
            byte[] hex110 = HexStringToByteArray.StrToByteArray("E963C614009090909090"); // Loads Save/Mission Overview Screen if button is clicked part 1
            byte[] hex111 = HexStringToByteArray.StrToByteArray("833D8A2AAE0003750FC705C84B9F0003000000E98A39EBFFC705C84B9F0007000000E97B39EBFF"); // Loads Save/Mission Overview Screen if button is clicked part 2
            //byte[] hex112 = HexStringToByteArray.StrToByteArray("E9A96E1600"); // Fixes Ranks in Gameranger part 1
            //byte[] hex113 = HexStringToByteArray.StrToByteArray("833DD514A200007F0AA14914A200E94491E9FFC3"); // Fixes Ranks in Gameranger part 2
            byte[] hex114 = HexStringToByteArray.StrToByteArray("E9E9802500"); // Allows access to all Tactical Officers for seperate for Team 1 and Team 2 part 1
            byte[] hex115 = HexStringToByteArray.StrToByteArray("776176655C5461636F66332E6C737400776176655C5461636F66342E6C737400776176655C5461636F66352E6C737400776176655C5461636F66362E6C737400776176655C5461636F66372E6C73740000A1C81C8C0069C0CF0B00006683B8EC948B00007F1231C0A0AE6F7B0083F8080F87E07FDAFFEB1031C0A0B46F7B0083F8080F87CE7FDAFF3C000F84E87EDAFF3C010F841B7FDAFF3C020F843B7FDAFF3C0374153C0474243C0574333C0674423C077451E9547FDAFFA12C2869008B0D302869008B1534286900EB4AA13C2869008B0D402869008B1544286900EB37A14C2869008B0D502869008B1554286900EB24A15C2869008B0D602869008B1564286900EB11A16C2869008B0D702869008B15742869008944241CA138286900894C24208954242489442428E90F7FDAFF"); // Allows access to all Tactical Officers for seperate for Team 1 and Team 2 part 2
            byte[] hex116 = HexStringToByteArray.StrToByteArray("EB49"); // Fixes bug with wingmen menu and multiple waves
            byte[] hex117 = HexStringToByteArray.StrToByteArray("EB0A"); // Fixes a bug with Skirmish mode being loaded after a mission when it wasn't skirmish prior

            //Campaign / Custom Tour code
            byte[] hex118 = HexStringToByteArray.StrToByteArray("25735C746F75722E6C73740000746F75723100746F75723200746F75723300746F75723400746F75723500746F75723600746F75723700746F75723800746F75723900746F7572313000746F7572313100746F7572313200746F7572313300746F7572313400746F7572313500746F7572313600746F7572313700746F7572313800746F7572313900746F7572323000746F7572323100746F7572323200746F7572323300746F7572323400746F7572323500746F7572323600746F7572323700746F7572323800746F7572323900746F7572333000746F7572333100746F75723332"); // Adds Campaign/Tour mode strings
            byte[] hex119 = HexStringToByteArray.StrToByteArray("692969006F296900752969007B29690081296900872969008D29690093296900992969009F296900A6296900AD296900B4296900BB296900C2296900C9296900D0296900D7296900DE296900E5296900EC296900F3296900FA296900012A6900082A29000F2A6900162A6900BB010000C1010000D6010000D9010000DC010000C1010000F7010000D90100001D2A6900242A69002B2A6900322A6900392A69"); // Adds Campaign/Tour directories to directoryID array
            byte[] hex120 = HexStringToByteArray.StrToByteArray("E97BB814009090"); // Changes Clear button function to Load campaign/tour screen if not Skirmish part 1
            byte[] hex121 = HexStringToByteArray.StrToByteArray("833D8A2AAE00037429C605537BB00001C6059E2AAE0004B904000000C605C84B9F0005C705484B9F0003000000E89F4BEBFFE9D747EBFF6A14E8E39EECFFE94447EBFF"); // Changes Clear button function to Load campaign/tour screen if not Skirmish part 2
            byte[] hex122 = HexStringToByteArray.StrToByteArray("E990B414009090"); // Load tour.lst if campaign mode is activated part 1
            byte[] hex123 = HexStringToByteArray.StrToByteArray("803D537BB000017525833DC84B9F0005751CA19E2AAE00A38A2AAE008B04856831600050685C296900E94A4BEBFF8B048568316000506878336000E9384BEBFF"); // Load tour.lst if campaign mode is activated part 2
            byte[] hex124 = HexStringToByteArray.StrToByteArray("E9DCCC1400909090"); // Only highlight Training exercises button if campaign mode is off part 1
            byte[] hex125 = HexStringToByteArray.StrToByteArray("803D537BB000010F841A33EBFF39E80F83F336EBFFE90D33EBFF"); // Only highlight Training exercises button if campaign mode is off part 2
            byte[] hex126 = HexStringToByteArray.StrToByteArray("E9DED01400"); // Highlight Campaign button if selected part 1
            byte[] hex127 = HexStringToByteArray.StrToByteArray("803D537BB00001750AA1302AAE00E90F2FEBFFA128D2AB00E9052FEBFF"); // Highlight Campaign button if selected part 2
            byte[] hex128 = HexStringToByteArray.StrToByteArray("E9EAD01400"); // Campaign/Tour of Duty description if not Skirmish part 1
            byte[] hex129 = HexStringToByteArray.StrToByteArray("803D8A2AAE0003750A6862030000E9032FEBFF6A5CE9FC2EEBFF"); // Campaign/Tour of Duty description if not Skirmish part 2
            byte[] hex130 = HexStringToByteArray.StrToByteArray("E9F6D01400"); // Campaign/Tour of Duty button if not Skirmish part 1
            byte[] hex131 = HexStringToByteArray.StrToByteArray("803D8A2AAE0003751368403360008D4C24446840336000E9F72EEBFF68944960008D4C24446894496000E9E42EEBFF"); // Campaign/Tour of Duty button if not Skirmish part 2
            byte[] hex132 = HexStringToByteArray.StrToByteArray("E9F5CC1400"); // Set Tour mode to off if Training Exercises is clicked part 1
            byte[] hex133 = HexStringToByteArray.StrToByteArray("C605537BB00000A1484B9F00E9FA32EBFF"); // Set Tour mode to off if Training Exercises is clicked part 2
            byte[] hex134 = HexStringToByteArray.StrToByteArray("E9A4D01400"); // Set Tour mode to off if Skirmish is clicked part 1
            byte[] hex135 = HexStringToByteArray.StrToByteArray("C605537BB00000A1C0326000E94B2FEBFF"); // Set Tour mode to off if Skirmish is clicked part 2
            byte[] hex136 = HexStringToByteArray.StrToByteArray("E987CE1400"); // Set Tour mode to off if Racing/Combat is clicked part 1
            byte[] hex137 = HexStringToByteArray.StrToByteArray("C605537BB00000A1484B9F00E96831EBFF"); // Set Tour mode to off if Racing/Combat is clicked part 2
            byte[] hex138 = HexStringToByteArray.StrToByteArray("E93DD4140090909090909090"); // Remove Load button if Tour mode is on part 1
            byte[] hex139 = HexStringToByteArray.StrToByteArray("803D537BB000010F84602DEBFFE9B82BEBFF"); // Remove Load button if Tour mode is on part 2
            byte[] hex140 = HexStringToByteArray.StrToByteArray("E92CCD140090"); // Allow DirectoryID/Gamemode 4 and above to be loaded if Training Exercises is selected part 1
            byte[] hex141 = HexStringToByteArray.StrToByteArray("392D8A2AAE000F83C932EBFF892D8A2AAE00E9BE32EBFF"); // Allow DirectoryID/Gamemode 4 and above to be loaded if Training Exercises is selected part 2


            byte[] hex142 = HexStringToByteArray.StrToByteArray("E9A6E91400"); // Loads proper panel buttons for Combat and Tour directories part 1
            byte[] hex143 = HexStringToByteArray.StrToByteArray("B80400000083F9020F845016EBFF39C10F8C7616EBFFE94316EBFF"); // Loads proper panel buttons for Combat and Tour directories part 2
            byte[] hex144 = HexStringToByteArray.StrToByteArray("E9C9E814009090"); // Loads briefing button instead of Ready if Combat or Tour modes part 1
            byte[] hex145 = HexStringToByteArray.StrToByteArray("833D8A2AAE00020F842E17EBFF833D8A2AAE00040F8C5017EBFFE91C17EBFF"); // Loads briefing button instead of Ready if Combat or Tour modes part 2
            byte[] hex146 = HexStringToByteArray.StrToByteArray("E92BE61400"); // Fixes back button on Racing mode part 1
            byte[] hex147 = HexStringToByteArray.StrToByteArray("B80300000083F9010F84CB19EBFF39C10F85DE19EBFFE9BE19EBFF"); // Fixes back button on Racing mode part 2

            // Campaign/Custom Tour code
            byte[] hex148 = HexStringToByteArray.StrToByteArray("E944E71300"); // Loads Tour progress check part 1
            byte[] hex149 = HexStringToByteArray.StrToByteArray("803D537BB000017505E8EE70EAFFA1D04B9F00E9A418ECFF"); // Loads Tour progress check part 2
            byte[] hex150 = HexStringToByteArray.StrToByteArray("E9F88E1500"); // Prevent checking .lst file twice part 1
            byte[] hex151 = HexStringToByteArray.StrToByteArray("803DC84B9F00050F84FB70EAFFE8423EEBFFE9F170EAFF"); // Prevent checking .lst file twice part 2
            byte[] hex152 = HexStringToByteArray.StrToByteArray("E99A8E1500"); // Prevent checking .lst file twice part 3
            byte[] hex153 = HexStringToByteArray.StrToByteArray("803DC84B9F00050F845971EAFFE8BB33EDFFE94F71EAFF"); // Prevent checking .lst file twice part 4

            //byte[] hex154 = HexStringToByteArray.StrToByteArray("E950D2140090909090"); // Prevents clear button from displaying if not Skirmish part 1 (Will conflict with campaign code listed above)
            //byte[] hex155 = HexStringToByteArray.StrToByteArray("833D8A2AAE00030F85F52DEBFF8D4C242C68C8316000E9992DEBFF"); // Prevents clear button from displaying if not Skirmish part 2 (Will conflict with campaign code listed above)
            byte[] hex156 = HexStringToByteArray.StrToByteArray("E956201600"); // Loads briefing text on loading screen for Combat Engagement missions, part 1
            byte[] hex157 = HexStringToByteArray.StrToByteArray("A18A2AAE0083F8040F83D7E1E9FF83F8020F84CEE1E9FF83F8010F84C5E1E9FFE997DFE9FF"); // Loads briefing text on loading screen for Combat Engagement missions, part 2



            // Entry
            Marshal.Copy(begin1, 0, BeginPtr, begin1.Length);
            Marshal.Copy(begin2, 0, BeginPtr2, begin2.Length);
            Marshal.Copy(begin3, 0, BeginPtr3, begin3.Length);

            // Tour in Multiplayer
            Marshal.Copy(hex5, 0, bufferPtr5, hex5.Length);
            Marshal.Copy(hex6, 0, bufferPtr6, hex6.Length);
            Marshal.Copy(hex7, 0, bufferPtr7, hex7.Length);
            Marshal.Copy(hex8, 0, bufferPtr8, hex8.Length);
            Marshal.Copy(hex9, 0, bufferPtr9, hex9.Length);
            Marshal.Copy(hex10, 0, bufferPtr10, hex10.Length);
            Marshal.Copy(hex11, 0, bufferPtr11, hex11.Length);
            //Marshal.Copy(hex12, 0, bufferPtr12, hex12.Length);
            Marshal.Copy(hex13, 0, bufferPtr13, hex13.Length);
            Marshal.Copy(hex14, 0, bufferPtr14, hex14.Length);
            Marshal.Copy(hex15, 0, bufferPtr15, hex15.Length);
            Marshal.Copy(hex16, 0, bufferPtr16, hex16.Length);
            Marshal.Copy(hex17, 0, bufferPtr17, hex17.Length);
            Marshal.Copy(hex18, 0, bufferPtr18, hex18.Length);
            Marshal.Copy(hex19, 0, bufferPtr19, hex19.Length);
            //Marshal.Copy(hex20, 0, bufferPtr20, hex20.Length);
            Marshal.Copy(hex21, 0, bufferPtr21, hex21.Length);
            Marshal.Copy(hex22, 0, bufferPtr22, hex22.Length);
            //Marshal.Copy(hex23, 0, bufferPtr23, hex23.Length);
            //Marshal.Copy(hex24, 0, bufferPtr24, hex24.Length);
            //Marshal.Copy(hex25, 0, bufferPtr25, hex25.Length);
            //Marshal.Copy(hex26, 0, bufferPtr26, hex26.Length);
            Marshal.Copy(hex27, 0, bufferPtr27, hex27.Length);
            Marshal.Copy(hex28, 0, bufferPtr28, hex28.Length);
            Marshal.Copy(hex29, 0, bufferPtr29, hex29.Length);
            Marshal.Copy(hex30, 0, bufferPtr30, hex30.Length);
            Marshal.Copy(hex31, 0, bufferPtr31, hex31.Length);
            Marshal.Copy(hex32, 0, bufferPtr32, hex32.Length);
            Marshal.Copy(hex33, 0, bufferPtr33, hex33.Length);
            Marshal.Copy(hex34, 0, bufferPtr34, hex34.Length);
            Marshal.Copy(hex35, 0, bufferPtr35, hex35.Length);
            Marshal.Copy(hex36, 0, bufferPtr36, hex36.Length);
            Marshal.Copy(hex37, 0, bufferPtr37, hex37.Length);
            Marshal.Copy(hex38, 0, bufferPtr38, hex38.Length);
            Marshal.Copy(hex39, 0, bufferPtr39, hex39.Length);
            Marshal.Copy(hex40, 0, bufferPtr40, hex40.Length);
            //Marshal.Copy(hex41, 0, bufferPtr41, hex41.Length);
            //Marshal.Copy(hex42, 0, bufferPtr42, hex42.Length);
            Marshal.Copy(hex43, 0, bufferPtr43, hex43.Length);
            Marshal.Copy(hex44, 0, bufferPtr44, hex44.Length);
            Marshal.Copy(hex45, 0, bufferPtr45, hex45.Length);
            Marshal.Copy(hex46, 0, bufferPtr46, hex46.Length);
            Marshal.Copy(hex47, 0, bufferPtr47, hex47.Length);
            Marshal.Copy(hex48, 0, bufferPtr48, hex48.Length);
            //Marshal.Copy(hex51, 0, bufferPtr51, hex51.Length);
            //Marshal.Copy(hex52, 0, bufferPtr52, hex52.Length);
            Marshal.Copy(hex53, 0, bufferPtr53, hex53.Length);
            Marshal.Copy(hex54, 0, bufferPtr54, hex54.Length);
            Marshal.Copy(hex55, 0, bufferPtr55, hex55.Length);
            Marshal.Copy(hex56, 0, bufferPtr56, hex56.Length);
            Marshal.Copy(hex57, 0, bufferPtr57, hex57.Length);
            Marshal.Copy(hex58, 0, bufferPtr58, hex58.Length);
            Marshal.Copy(hex59, 0, bufferPtr59, hex59.Length);
            //Marshal.Copy(hex60, 0, bufferPtr60, hex60.Length);
            //Marshal.Copy(hex61, 0, bufferPtr61, hex61.Length);
            Marshal.Copy(hex62, 0, bufferPtr62, hex62.Length);
            Marshal.Copy(hex63, 0, bufferPtr63, hex63.Length);
            Marshal.Copy(hex64, 0, bufferPtr64, hex64.Length);
            Marshal.Copy(hex65, 0, bufferPtr65, hex65.Length);
            Marshal.Copy(hex66, 0, bufferPtr66, hex66.Length);
            Marshal.Copy(hex67, 0, bufferPtr67, hex67.Length);
            Marshal.Copy(hex68, 0, bufferPtr68, hex68.Length);
            //Marshal.Copy(hex69, 0, bufferPtr69, hex69.Length);
            //Marshal.Copy(hex70, 0, bufferPtr70, hex70.Length);
            Marshal.Copy(hex71, 0, bufferPtr71, hex71.Length);
            Marshal.Copy(hex72, 0, bufferPtr72, hex72.Length);
            Marshal.Copy(hex73, 0, bufferPtr73, hex73.Length);
            Marshal.Copy(hex74, 0, bufferPtr74, hex74.Length);
            Marshal.Copy(hex75, 0, bufferPtr75, hex75.Length);
            Marshal.Copy(hex76, 0, bufferPtr76, hex76.Length);
            //Marshal.Copy(hex77, 0, bufferPtr77, hex77.Length);
            Marshal.Copy(hex78, 0, bufferPtr78, hex78.Length);
            Marshal.Copy(hex79, 0, bufferPtr79, hex79.Length);
            Marshal.Copy(hex80, 0, bufferPtr80, hex80.Length);
            Marshal.Copy(hex81, 0, bufferPtr81, hex81.Length);
            Marshal.Copy(hex82, 0, bufferPtr82, hex82.Length);
            Marshal.Copy(hex83, 0, bufferPtr83, hex83.Length);
            Marshal.Copy(hex84, 0, bufferPtr84, hex84.Length);
            Marshal.Copy(hex85, 0, bufferPtr85, hex85.Length);
            Marshal.Copy(hex86, 0, bufferPtr86, hex86.Length);
            Marshal.Copy(hex87, 0, bufferPtr87, hex87.Length);
            Marshal.Copy(hex88, 0, bufferPtr88, hex88.Length);
            Marshal.Copy(hex89, 0, bufferPtr89, hex89.Length);
            Marshal.Copy(hex90, 0, bufferPtr90, hex90.Length);
            Marshal.Copy(hex97, 0, bufferPtr97, hex97.Length);
            Marshal.Copy(hex98, 0, bufferPtr98, hex98.Length);
            Marshal.Copy(hex99, 0, bufferPtr99, hex99.Length);
            Marshal.Copy(hex100, 0, bufferPtr100, hex100.Length);
            //Marshal.Copy(hex101, 0, bufferPtr101, hex101.Length);
            //Marshal.Copy(hex102, 0, bufferPtr102, hex102.Length);
            Marshal.Copy(hex103, 0, bufferPtr103, hex103.Length);
            Marshal.Copy(hex104, 0, bufferPtr104, hex104.Length);
            //Marshal.Copy(hex105, 0, bufferPtr105, hex105.Length);
            Marshal.Copy(hex106, 0, bufferPtr106, hex106.Length);
            Marshal.Copy(hex107, 0, bufferPtr107, hex107.Length);
            Marshal.Copy(hex108, 0, bufferPtr108, hex108.Length);
            Marshal.Copy(hex109, 0, bufferPtr109, hex109.Length);
            Marshal.Copy(hex110, 0, bufferPtr110, hex110.Length);
            Marshal.Copy(hex111, 0, bufferPtr111, hex111.Length);
            //Marshal.Copy(hex112, 0, bufferPtr112, hex112.Length);
            //Marshal.Copy(hex113, 0, bufferPtr113, hex113.Length);
            Marshal.Copy(hex114, 0, bufferPtr114, hex114.Length);
            Marshal.Copy(hex115, 0, bufferPtr115, hex115.Length);
            Marshal.Copy(hex116, 0, bufferPtr116, hex116.Length);
            Marshal.Copy(hex117, 0, bufferPtr117, hex117.Length);
            //Marshal.Copy(hex118, 0, bufferPtr118, hex118.Length);
            //Marshal.Copy(hex119, 0, bufferPtr119, hex119.Length);
            Marshal.Copy(hex120, 0, bufferPtr120, hex120.Length);
            Marshal.Copy(hex121, 0, bufferPtr121, hex121.Length);
            //Marshal.Copy(hex122, 0, bufferPtr122, hex122.Length);
            //Marshal.Copy(hex123, 0, bufferPtr123, hex123.Length);
            Marshal.Copy(hex124, 0, bufferPtr124, hex124.Length);
            Marshal.Copy(hex125, 0, bufferPtr125, hex125.Length);
            Marshal.Copy(hex126, 0, bufferPtr126, hex126.Length);
            Marshal.Copy(hex127, 0, bufferPtr127, hex127.Length);
            Marshal.Copy(hex128, 0, bufferPtr128, hex128.Length);
            Marshal.Copy(hex129, 0, bufferPtr129, hex129.Length);
            Marshal.Copy(hex130, 0, bufferPtr130, hex130.Length);
            Marshal.Copy(hex131, 0, bufferPtr131, hex131.Length);
            Marshal.Copy(hex132, 0, bufferPtr132, hex132.Length);
            Marshal.Copy(hex133, 0, bufferPtr133, hex133.Length);
            Marshal.Copy(hex134, 0, bufferPtr134, hex134.Length);
            Marshal.Copy(hex135, 0, bufferPtr135, hex135.Length);
            Marshal.Copy(hex136, 0, bufferPtr136, hex136.Length);
            Marshal.Copy(hex137, 0, bufferPtr137, hex137.Length);
            //Marshal.Copy(hex138, 0, bufferPtr138, hex138.Length);
            //Marshal.Copy(hex139, 0, bufferPtr139, hex139.Length);
            //Marshal.Copy(hex140, 0, bufferPtr140, hex140.Length);
            //Marshal.Copy(hex141, 0, bufferPtr141, hex141.Length);
            Marshal.Copy(hex142, 0, bufferPtr142, hex142.Length);
            Marshal.Copy(hex143, 0, bufferPtr143, hex143.Length);
            Marshal.Copy(hex144, 0, bufferPtr144, hex144.Length);
            Marshal.Copy(hex145, 0, bufferPtr145, hex145.Length);
            Marshal.Copy(hex146, 0, bufferPtr146, hex146.Length);
            Marshal.Copy(hex147, 0, bufferPtr147, hex147.Length);
            Marshal.Copy(hex148, 0, bufferPtr148, hex148.Length);
            Marshal.Copy(hex149, 0, bufferPtr149, hex149.Length);
            Marshal.Copy(hex150, 0, bufferPtr150, hex150.Length);
            Marshal.Copy(hex151, 0, bufferPtr151, hex151.Length);
            Marshal.Copy(hex152, 0, bufferPtr152, hex152.Length);
            Marshal.Copy(hex153, 0, bufferPtr153, hex153.Length);
            //Marshal.Copy(hex154, 0, bufferPtr154, hex154.Length);
            //Marshal.Copy(hex155, 0, bufferPtr155, hex155.Length);
            //Marshal.Copy(hex156, 0, bufferPtr156, hex156.Length);
            //Marshal.Copy(hex157, 0, bufferPtr157, hex157.Length);



            if (ConfigFile.XvtSimulatorBackground)
            {
                Marshal.Copy(hex49, 0, bufferPtr49, hex49.Length);
                Marshal.Copy(hex50, 0, bufferPtr50, hex50.Length);
                Marshal.Copy(hex91, 0, bufferPtr91, hex91.Length);
                Marshal.Copy(hex92, 0, bufferPtr92, hex92.Length);
                Marshal.Copy(hex93, 0, bufferPtr93, hex93.Length);
                Marshal.Copy(hex94, 0, bufferPtr94, hex94.Length);
                Marshal.Copy(hex95, 0, bufferPtr95, hex95.Length);
                Marshal.Copy(hex96, 0, bufferPtr96, hex96.Length);
            }

            MemoryProtect.VirtualProtectRestore();

            return 0;
        }

        public static int CampaignModePreHook(IntPtr @params)
        {
            IntPtr bufferPtr158 = new IntPtr(0x692C20);
            byte[] hex158 = HexStringToByteArray.StrToByteArray("E8FB5EF1FF9090909090E9184CEBFF"); // New Campaign Mode
            Marshal.Copy(hex158, 0, bufferPtr158, hex158.Length);

            IntPtr hookEntryPtr = new IntPtr(0x547842);
            byte[] hookEntry = HexStringToByteArray.StrToByteArray("E9D9B31400");
            Marshal.Copy(hookEntry, 0, hookEntryPtr, hookEntry.Length);

            // We replaced the call to this function earlier so we have to call it here to prevent issues
            IntPtr entryPtr = new IntPtr(0x488E70);
            Invoker.InvokeCallback(entryPtr);

            return 0;
        }

        public static int CampaignModeHook(IntPtr @params)
        {
            // call 005A8B20 while jumping to a far part of the memory
            // jmp to 00692C20
            //const string campaignPath = @"%s\campaign.lst";
            //const string missionPath = @"%s\mission.lst";
            IntPtr campaignPtr = new IntPtr(0xB07B53);
            IntPtr xwaMissionPathString = new IntPtr(0x603378);
            IntPtr newXWAMissionPathString = new IntPtr(0x692C25);
            byte[] missionPath = HexStringToByteArray.StrToByteArray("25735C6D697373696F6E2E6C737400");
            byte[] campaignPath = HexStringToByteArray.StrToByteArray("25735C63616D706169676E2E6C7374");


            if (Marshal.ReadByte(campaignPtr) >= 1)
            {
                Marshal.Copy(campaignPath, 0, xwaMissionPathString, campaignPath.Length);
            }
            else
            {
                Marshal.Copy(missionPath, 0, xwaMissionPathString, missionPath.Length);
            }

            byte[] newString = HexStringToByteArray.StrToByteArray("6878336000");
            Marshal.Copy(newString, 0, newXWAMissionPathString, newString.Length);

            //IntPtr callLSTPtr = new IntPtr(0x547800);
            //Invoker.InvokeCallback(callLSTPtr);

            return 0;
        }

        //[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        //[return: MarshalAs(UnmanagedType.LPStr)]
        //delegate string PushBytesDelegate(int index);

        //static PushBytesDelegate PushBytesString = (PushBytesDelegate)Marshal.GetDelegateForFunctionPointer(
        //    new IntPtr(0x4730B2), typeof(PushBytesDelegate));

        //public static int TargetIFFColorHook(IntPtr @params)
        //{
        //    IntPtr destinationPtr = new IntPtr(0x4730B2);
        //    IntPtr playerDataPtr = new IntPtr(0x8B94E0);
        //    IntPtr localPlayerPtr = new IntPtr(0x8C1CC8);
        //    int localPlayerIndex = Marshal.ReadByte(localPlayerPtr);


        //    int targetIndex = Marshal.ReadInt16(playerDataPtr + localPlayerIndex + 0x25);

        //    IntPtr baseEntityTargetPtr = new IntPtr(0x7B33C4 + targetIndex);
        //    IntPtr extendedEntityPtr = new IntPtr(Marshal.ReadInt32(baseEntityTargetPtr, 0));

        //    IntPtr loadColorCodePtr = new IntPtr(0x434E30);

        //    if (Marshal.ReadByte(extendedEntityPtr + 0x97) > 0)
        //    {
        //        switch (Marshal.ReadByte(extendedEntityPtr + 0x97))
        //        {
        //            case 1:
        //            case 4:
        //                byte[] iffImperial = HexStringToByteArray.StrToByteArray("6A4A");
        //                Marshal.Copy(iffImperial, 0, destinationPtr, iffImperial.Length);
        //                break;
        //            case 2:
        //                byte[] iffBlue = HexStringToByteArray.StrToByteArray("6A46");
        //                Marshal.Copy(iffBlue, 0, destinationPtr, iffBlue.Length);
        //                break;
        //            case 5:
        //                byte[] iffPurple = HexStringToByteArray.StrToByteArray("6A56");
        //                Marshal.Copy(iffPurple, 0, destinationPtr, iffPurple.Length);
        //                break;
        //            default:
        //                byte[] iffYellow = HexStringToByteArray.StrToByteArray("6A4E");
        //                Marshal.Copy(iffYellow, 0, destinationPtr, iffYellow.Length);
        //                break;
        //        }
        //    }
        //    else
        //    {
        //        byte[] iffRebel = HexStringToByteArray.StrToByteArray("6A52");
        //        Marshal.Copy(iffRebel, 0, destinationPtr, iffRebel.Length);
        //    }

        //    return 0;
        //}

    }
}

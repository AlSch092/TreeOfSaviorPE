#pragma once
#include "FindPattern.hpp"
#define ToS_Steam

const short SkillOpcode = 0x0C6B;


//00839B60

#ifdef ToS_Steam
//CONST DWORD dwSendPacket = 0x006C41D0; //55 8b ec 6a ff 68 ? ? ? ? 64 a1 00 00 00 00 50 81 ec 74 01 00 00 a1 ? ? ? ? 33 c5 89 45 f0 53 56 57 50 8d 45 f4 64 a3 00 00 00 00 8b f9
//CONST DWORD dwSendClass = 0x012DA058; //C7 05 ?? ?? ?? 01 ?? ?? ?? 01 8B 4D F4 64 89 0D 00 00 00 00 59 8B E5 5D C3 CC CC CC
CONST DWORD dwSendPacket = 0x0090A620;//FindPattern((BYTE*)SendPacketPattern, "xxxxxx????xxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxx", 0, 0x00400000);

CONST DWORD dwRecvPacket = FindPattern((BYTE*)RecvPacketPattern, "xxxxxx????xxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxxxxxxx", 0, 0x00B00000);
//55 8b ec 6a ff 68 ? ? ? ? 64 a1 00 00 00 00 50 81 EC 7C 01 00 00 a1 ? ? ? ? 33 c5 89 45 f0 53 56 57 50 8d 45 f4 64 a3 00 00 00 00 8b f1 8b 45 08


CONST DWORD TeleportXYZ = 0x00652590;

CONST DWORD dwActorBase = 0x02D53050; // cc cc 55 8b ec 8b 45 08 8b 4d 0c a3 ? ? ? ? 89 0d, start 0x00d00000

CONST DWORD dwFMA = 0x008959E5; // D9 41 04 D9 58 04 F3 0F 59 55 FC F3 0F 59 6D FC F3 0F 5c C5

CONST DWORD dwNPCList = 0x0077C6F0; // 55 8b ec 51 56 8b f1 8b 8e 98 09 00 00 85 c9 74 25 8d 45 fc 50 e8 ? ? ? ? 8b 45 fc 3b 05 ? ? ? ?
CONST DWORD dwNearbyNPC = 0x004F5F7C; //8b 86 e8 01 00 00 81 c7 20 01 00 00 89 07 e9 ? ? ? ? 8b 75 b4 80 7d be 00 75 24 6a 00

namespace Actor {
	const DWORD dwX = 0xF8;
	const DWORD dwZ = dwX+4;
};
#endif
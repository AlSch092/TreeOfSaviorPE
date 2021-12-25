#pragma once
#include "Packets.hpp"

struct HOOK {
	DWORD dwAddress;
	DWORD dwReturn;
	char* szOriginalBytes;
	INT nSize;
};

BOOL WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable);

CONST HOOK hkSend = { dwSendPacket, dwSendPacket + 5, "\x55\x8b\xec\x6a\xff", 5 };
VOID SendHook();

CONST HOOK hkRecv = { dwRecvPacket, dwRecvPacket + 5, "\x55\x8b\xEC\x6A\xff", 5 };
VOID RecvHook();

CONST HOOK hkFMA = { dwFMA, dwFMA + 6, "\xd0\x41\x04\xd9\x58\x04", 6 };
VOID UpdatePositionHook();

CONST HOOK hkSendMessageW = { (DWORD)GetProcAddress(LoadLibraryA("USER32.dll"), "SendMessageW"), (DWORD)GetProcAddress(LoadLibraryA("USER32.dll"), "SendMessageW") + 5, "\x8b\xFF\x55\x8B\xEC", 5 };
VOID SendMessageWHook();

CONST HOOK hkNPCList = { dwNPCList, dwNPCList + 5, "\x55\x8B\xEC\x51\x56", 5 };
VOID HookNPCList();

CONST HOOK hkNPCList1 = { dwNearbyNPC, dwNearbyNPC + 6, "\x8b\x86\xe8\x01\x00\x00", 6 };
VOID HookNPCList1();

CONST HOOK hkConnect = { (DWORD)GetProcAddress(LoadLibraryA("ws2_32.dll"), "connect"), (DWORD)GetProcAddress(LoadLibraryA("ws2_32.dll"), "connect") + 5, "\x8b\xFF\x55\x8B\xEC", 5 };
VOID HookConnect();
VOID SendCharacterLogin(SHORT ch, BYTE chIndex);

//037DD043
//hkRecv = { recvFunc, recvFunc + 5, "\x5F\x8B\xC6\x5E\x5D", 5 }; //8B 75 0C 3B F0 0F 4F F0 8B 45 08 56 50 8B CF
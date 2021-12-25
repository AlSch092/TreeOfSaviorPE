#include "Hooks.hpp"

BOOL isAutoLogin = FALSE;
short channelID;
byte charIndex;
extern BOOL isBottingSilver;
extern BOOL isDisconnected;
extern HANDLE BotThread;

BOOL WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable) {
	try {
		if (bEnable) {
			DWORD dwOldProt;
			if (!VirtualProtect((void*)hkHook.dwAddress, (DWORD)hkHook.dwReturn - (DWORD)hkHook.dwAddress, PAGE_EXECUTE_READWRITE, &dwOldProt))
				return false;
			*(UCHAR *)hkHook.dwAddress = 0xE9;
			*(UINT*)(hkHook.dwAddress + 1) = (DWORD)lpvHook - hkHook.dwAddress - 5;
			for (int i = 0; i < hkHook.nSize - 5; i++) {
				memcpy((VOID*)(hkHook.dwAddress + i + 5), (VOID*) "\x90", 1);
			}
		}
		else {
			DWORD dwOldProt;
			if (!VirtualProtect((void*)hkHook.dwAddress, (DWORD)hkHook.dwReturn - (DWORD)hkHook.dwAddress, PAGE_EXECUTE_READWRITE, &dwOldProt))
				return false;
			memcpy((VOID*)hkHook.dwAddress, (VOID*)hkHook.szOriginalBytes, hkHook.nSize);
		}
	}
	catch (...){
		MessageBoxA(0, "Failed to write bytes.", "Error", 0);
	}
	return true;
}


LPBYTE SendBuffer;
DWORD SendLength;
BOOL isNotBlocked; //since we can't init vars inside a naked func
VOID __declspec(naked) SendHook()
{
	__asm
	{
		push eax
			mov eax, [esp + 0x08] //data 
			mov SendBuffer, eax
			mov eax, [esp + 0x0C]//len
			mov SendLength, eax
			pop eax
			pushad
	}
	 
	CreatePacket(SendBuffer, SendLength);

	__asm
	{
		popad
		push ebp
		mov ebp, esp
		_emit 0x6a
		_emit 0xFF
		jmp hkSend.dwReturn
	}
}

LPBYTE RecvBuffer;
DWORD RecvLength;
VOID __declspec(naked) RecvHook()
{
	__asm
	{
		push eax
			mov eax, [esp + 0x08]
			mov RecvBuffer, eax
			mov eax, [esp + 0x0C]
			mov RecvLength, eax
			pop eax
			pushad
	}

	CreateRecvPacket(RecvBuffer, RecvLength);

	__asm
	{
		popad
			push ebp
			mov ebp, esp
			_emit 0x6a
			_emit 0xFF
			jmp hkRecv.dwReturn
	}
}


DWORD hiddenActorCoords = 0;
VOID __declspec(naked) UpdatePositionHook()
{
	__asm
	{
		mov hiddenActorCoords, ecx
			mov[ecx + 4], 0xFFFFFFFF
			fld dword ptr[ecx + 0x04]
			jmp hkFMA.dwReturn
	}
}

DWORD NPCRealID = 0;
DWORD NPCUniqueID = 0;

void __declspec(naked) HookNPCList1()
{
	__asm
	{
		push eax
		mov eax, [eax+0xB4]
		mov NPCUniqueID, eax
		pop eax
		mov eax, [esi + 0x000001E8]
		jmp hkNPCList1.dwReturn
	}
}

VOID __declspec(naked) HookNPCList()
{
	__asm
	{
		pushad
		push ebx
		mov ebx, esi
		cmp esi, 0
		mov ebx, [ebx+0x288]
		mov NPCRealID, ebx
	}

	if (NPCRealID == 147410)
	{
		__asm
		{
			mov NPCUniqueID, eax
		}
	}

	__asm
	{
		return:
		pop ebx
		popad
		push ebp
		mov ebp, esp
		push ecx
		push esi
		jmp hkNPCList.dwReturn
	}
}

VOID SendCharacterLogin(SHORT ch, BYTE chIndex)
{
	char buffer[39] = "0C 00 00 00 00 00 00 00 00 00 02 00 03"; //13 * 3 length

	char chBuff[5];
	char chIndexBuff[5];

	itoa(ch, chBuff, 16);
	itoa(chIndex, chIndexBuff, 16);

	memcpy(&buffer[31], &chBuff[0], 1);
	memcpy(&buffer[37], &chIndexBuff, 1);

	Send(buffer);
}

VOID PrepareRelog()
{
	TerminateThread(BotThread, 0);
	Sleep(10000);
	SendCharacterLogin(channelID, charIndex);
	Sleep(20000);
	isDisconnected = FALSE;
	if (isBottingSilver)
		BotThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Bot360Dungeon, 0, 0, 0);
}

void* OurConnectionPtr = 0;
sockaddr_in OurConnection;
VOID __declspec(naked) HookConnect()
{
	__asm
	{
		push eax
			mov eax, [esp + 0x0C]
			mov OurConnectionPtr, eax
			pop eax
			pushad
	}

	memcpy(&OurConnection, OurConnectionPtr, sizeof(sockaddr_in));

	if ((OurConnection.sin_port == (u_short)22811 || OurConnection.sin_port == (u_short)23067) && isAutoLogin)
	{
		TerminateThread(BotThread, 0);
		isDisconnected = TRUE;
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&PrepareRelog, 0, 0, 0);
		printf("Connect to char screen called.\n");
	}

	__asm
	{
		popad
			mov edi, edi
			push ebp
			mov ebp, esp
			jmp hkConnect.dwReturn
	}
}
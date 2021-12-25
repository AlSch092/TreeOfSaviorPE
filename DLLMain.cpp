#include "Hooks.hpp"
#include "HWID.hpp"

	
extern DWORD dwSendClass;
extern int Main();

DWORD ptrToNothing = 0x01524553;

VOID Startup()
{
	Sleep(500);

	//DWORD dwOld; //get rid of gay NtdllPVM hook
	//DWORD ntdll_ZwProtectVirtualMemory = (DWORD)GetProcAddress(GetModuleHandle(L"ntdll"), "ZwProtectVirtualMemory");
	//VirtualProtect((void*)ntdll_ZwProtectVirtualMemory, 5, PAGE_EXECUTE_WRITECOPY, &dwOld);
	//memcpy((void*)ntdll_ZwProtectVirtualMemory, (void*) "\xB8\x50\x00\x00\x00", 5);
	
	//dwSendClass = FindPattern((BYTE*)SendClassPattern, "xx???x???xxxxxxxxxxxxxxxxxxx", 6, 0x00400000);
	//dwSendClass = *(DWORD*)dwSendClass;
	
	//WriteHookBytes(hkNPCList1, HookNPCList1, TRUE); //NPC/Dungeon botting
	//WriteHookBytes(hkConnect, HookConnect, TRUE); //Auto-login
	WriteHookBytes(hkSend, SendHook, TRUE);
	//SetWindowTextA(FindWindowA(NULL, "Tree Of Savior"), "TOS");
	Main(); //GUI
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason) {
		case DLL_PROCESS_ATTACH: {
			 CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Startup, 0, 0, 0);
		}break;

		case DLL_PROCESS_DETACH:
			break;
	};
	
	return TRUE;
}
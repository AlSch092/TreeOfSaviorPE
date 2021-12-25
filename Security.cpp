#include "Security.hpp"

bool CheckDebugObjects()
{
	HANDLE hDebugObject = 0;
	ThinAPI* NT_API = new ThinAPI(); //helper class for raw syscalls
	NTSTATUS status = (NT_API->_NTQueryInfoProcess)(GetCurrentProcess(), 0x1E, &hDebugObject, 8, 0);

	if (status == 0 && NULL != hDebugObject)
	{
		return true;
	}

	return false;
}

//Uses ZwQuerySystemInformation to check whether a kernel debugger is present
bool SystemKernelDebuggerInformation()
{
	typedef long NTSTATUS;
	HANDLE hProcess = GetCurrentProcess();

	typedef struct _SYSTEM_KERNEL_DEBUGGER_INFORMATION {
		bool DebuggerEnabled;
		bool DebuggerNotPresent;
	} SYSTEM_KERNEL_DEBUGGER_INFORMATION, *PSYSTEM_KERNEL_DEBUGGER_INFORMATION;

	enum SYSTEM_INFORMATION_CLASS { SystemKernelDebuggerInformation = 35 };
	typedef NTSTATUS(__stdcall *ZW_QUERY_SYSTEM_INFORMATION)(IN SYSTEM_INFORMATION_CLASS SystemInformationClass, IN OUT PVOID SystemInformation, IN ULONG SystemInformationLength, OUT PULONG ReturnLength);
	ZW_QUERY_SYSTEM_INFORMATION ZwQuerySystemInformation;
	SYSTEM_KERNEL_DEBUGGER_INFORMATION Info;

	/* load the ntdll.dll */
	HMODULE hModule = LoadLibraryA("ntdll.dll");
	ZwQuerySystemInformation = (ZW_QUERY_SYSTEM_INFORMATION)GetProcAddress(hModule, "ZwQuerySystemInformation");
	if (ZwQuerySystemInformation == NULL)
		return false;

	if (0 == ZwQuerySystemInformation(SystemKernelDebuggerInformation, &Info, sizeof(Info), NULL)) { // 0 = STATUS_SUCCESS
		if (Info.DebuggerEnabled && !Info.DebuggerNotPresent)
			return true; //debugger FOUND
		else
			return false; //debugger NOT found
	}

	return false;
}


void __declspec(naked) BreakIDA_1(DWORD AddressToCall)
{
	__asm
	{
		push eax
		mov eax, esp
		add esp, 4
		jmp eax
	}
}
#include "HWID.hpp"

std::string GenerateHWID() {

	std::string HWID;

	__asm
	{
		pushad
		push eax
		xor eax, eax
		jz execute
		and esp, 0x00FFFFFF
		jmp $ + 3
		execute:
		pop eax
		popad
	}

	CHAR volumeName[MAX_PATH + 1] = { 0 };
	CHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;

	if (GetVolumeInformationA(
		"C:\\", //TODO: add dynamic pathing for drive
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{

		CHAR serialBuf[20];
		_itoa(serialNumber, serialBuf, 10);

		CHAR username[1024 + 1];
		DWORD size = 1024 + 1;
		GetUserNameA((CHAR*)username, &size);

		HWID = username;
		HWID += "-";
		HWID += serialBuf;
	}
	else {
		HWID = "Failed to generate HWID.";
		return NULL;
	}
	return HWID;
}
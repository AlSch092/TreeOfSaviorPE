#include "FindPattern.hpp"

BOOL Check(const BYTE* pData, const BYTE* bMask, const char* szMask) {
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask != '?' && *pData != *bMask)
			return false;

	return (*szMask) == NULL;
}

DWORD FindPattern(BYTE *bMask, char* szMask, DWORD dwOffset, DWORD dwStartAddress)
{
	DWORD dwLen = 0x01000000;
	__try
	{
		for (DWORD i = 0; i < dwLen; i++)
			if (Check((BYTE*)(dwStartAddress + i), bMask, szMask))
				return (DWORD)(dwStartAddress + i + dwOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		MessageBox(NULL, TEXT("Pattern Error"), TEXT("Error"), MB_OK);
	}

	MessageBoxA(NULL, szMask, "Pattern Error", MB_OK);
	return 0x00400000;
}
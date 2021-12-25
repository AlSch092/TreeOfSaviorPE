#pragma once
#include <Windows.h>

template<class T>
T ReadPointer(DWORD ulBase, int iOffset)
{
	__try
	{
		return *(T*)(*(DWORD*)ulBase + iOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) { return -1; }
}

template<class T>
bool WritePointer(DWORD ulBase, int iOffset, T iValue)
{
	__try { *(T*)(*(DWORD*)ulBase + iOffset) = iValue; return true; }
	__except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}
#pragma once
#include "Constants.hpp"
#include "Packets.hpp"
void __stdcall SendPacket(LPBYTE data, DWORD length);
VOID __stdcall RecvPacket(LPBYTE data, DWORD length);

VOID CastAdminBuffs();
VOID CastKillSkill();

VOID Bot300Dungeon();
VOID Bot360Dungeon();
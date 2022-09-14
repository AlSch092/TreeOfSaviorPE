#pragma once
#include "FindPattern.hpp"

namespace Offsets
{
	static DWORD dwSendPacket;

	static DWORD LastMonsterAttacked; //+14b21ec
	static DWORD DistanceFromMonsterAttacked; //+14b21c4

	static DWORD ActorAttack; //+0x9341D0
	static DWORD GetTargetedMonsterId; //+966554
}

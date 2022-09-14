#pragma once
#include "PacketWriter.hpp"
#include "Constants.hpp"

namespace Opcodes
{
	namespace Send
	{
		static const uint16_t Ping = 0x240e;

		static const uint16_t RangedAttack = 0x0C69;
	}

	namespace Recv
	{

	}
}

namespace Builder
{
	PacketWriter* RangedAttack(uint16_t skillId, int nMobs, uint32_t* monsterIds);
}

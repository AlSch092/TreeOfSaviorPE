#include "PacketBuilder.hpp"

PacketWriter* Builder::RangedAttack(uint16_t skillId, int nMobs, uint32_t* monsterIds)
{
	PacketWriter* p = new PacketWriter(Opcodes::Send::RangedAttack);
	p->WriteZeros(21);
	p->Write<uint32_t>(skillId);

	for (int i = 0; i < nMobs; i++)
	{
		p->Write<uint32_t>(monsterIds[0]);
	}

	p->WriteZeros(2);

	return p;
}

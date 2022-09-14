#pragma once
#include "PacketBuilder.hpp"
#include <queue>
#include <random>

namespace PacketHelper
{
	std::string randomStr(size_t size);
	std::wstring randomWStr(size_t size);

	uint16_t changeEndianness16(UINT16 val);
	int32_t changeEndianness32(int32_t val);

	LPBYTE ToPacketFormat(CHAR* input);
	std::string ToString(LPBYTE packetStr, int byteLength);

	int GetPacketLength(CHAR* input);

	int rand_lim(int limit);

	BOOL CreatePacket(LPBYTE data, UINT length);
	BOOL CreateRecvPacket(LPBYTE data, DWORD length);
};

struct OutPacket {
	DWORD dwLength;
	unsigned char bData[8192];
};

typedef enum PacketDirection {
	in,
	out
};

struct ModifyRule {
	PacketDirection direction;
	int len;
	char* pattern;
	uint8_t* replacement;
	uint16_t opcode;
};


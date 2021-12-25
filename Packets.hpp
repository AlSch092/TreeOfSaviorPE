#pragma once
#include "GameFunctions.hpp"
#include "PacketWriter.hpp"

unsigned char* convertStringToPacketFormat(char* convertStr);
char* convertPacketFormatToString(unsigned char* packetStr, int byteLength);
int getPacketLength(char* grabbedTextPacket);

BOOL CreatePacket(LPBYTE data, DWORD length);
BOOL CreateRecvPacket(LPBYTE data, DWORD length);

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

void Send(char* textPacket);
void Recv(char* textPacket);
#include "Packets.hpp"
#include <iostream>
#include <queue>

std::queue<PacketWriter*> SendPacketQueue;
std::vector<uint16_t> BlockedList;
std::vector<uint16_t> IgnoredList;
std::vector<ModifyRule*> ModifyList;

std::queue<PacketWriter*> RecvPacketQueue;
std::vector<uint16_t> RecvBlockedList;
std::vector<uint16_t> RecvIgnoredList;
std::vector<ModifyRule*> RecvModifyList;

extern BOOL isDisconnected;
extern BOOL isBottingSilver;

short changeEndianness16(short val)
{
	return (val << 8) |          // left-shift always fills with zeros
		((val >> 8) & 0x00ff); // right-shift sign-extends, so force to zero
}

int rand_lim(int limit) {
	/* return a random number between 0 and limit inclusive.
	*/

	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

unsigned char* convertStringToPacketFormat(char* convertStr) {

	char fixedString[4096 * 3] = { 0 };

	//strip spaces, bad text
	int i; int j = 0;

	for (i = 0; convertStr[i] != '\0'; i++) {
		if ((convertStr[i] >= 'A' && convertStr[i] <= 'F') || (convertStr[i] >= '0' && convertStr[i] <= '9') || (convertStr[i] >= 'a' && convertStr[i] <= 'f'))  {
			fixedString[j] = convertStr[i];
			j++;
		}
		else if (convertStr[i] == ' ') {

		}
		else if (convertStr[i] == '*') {

			int random = rand_lim(15);

			if (random >= 0 && random <= 9) {
				fixedString[j] = random + 0x30;
			}
			else if (random >= 9 && random <= 15) {
				fixedString[j] = random + 0x55;
			}

			j++;
		}
		else {
			MessageBoxA(0, "Bad Hex Character found in sent packet.", "TOS PE (X.)", 0);
			return NULL;
		}

	}

	unsigned char* bytestring = (unsigned char*)malloc((sizeof(char)*j * 2) + 1);
	ZeroMemory(bytestring, (sizeof(char)*j * 2) + 1);
	j = 0;

	for (i = 0; fixedString[i] != '\0'; i++) {

		if (i % 2 == 0) { //even number iterator
			if (fixedString[i] >= 'a' && fixedString[i] <= 'f') {
				bytestring[j] = ((fixedString[i] - 0x57) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
			else if (fixedString[i] >= '0' && fixedString[i] <= '9') {

				bytestring[j] = ((fixedString[i] - 0x30) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
			else if (fixedString[i] >= 'A' && fixedString[i] <= 'F') {
				bytestring[j] = ((fixedString[i] - 0x37) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
		}
	}
	return bytestring;
}

char* convertPacketFormatToString(unsigned char* packetStr, int byteLength) {

	if (byteLength < 2)
		return NULL;

	static char convertedStr[4096 * 5] = { 0 };

	char* tmpStr = (char*)calloc(sizeof(char), 4095 * 5);

	int i;
	unsigned char ch;

	for (i = 0; i < byteLength; i++) {
		ch = packetStr[i];
		sprintf(&convertedStr[i], "%.2X", ch);
		strcat(&tmpStr[i], &convertedStr[i]);
		strcat(tmpStr, " ");
	}
	return tmpStr;
}

int getPacketLength(char* grabbedTextPacket) {

	int length = 0;
	int i;

	for (i = 0; grabbedTextPacket[i] != '\0'; i++) {
		if (grabbedTextPacket[i] == ' ')
			length = length;
		else
			length++;
	}
	length = length / 2;
	return length;
}

void Send(char* grabbedTextPacket) {

	OutPacket packet;
	packet.dwLength = getPacketLength(grabbedTextPacket); //get packet len

	unsigned char* outPacket = convertStringToPacketFormat(grabbedTextPacket); //parse packet to unsigned char* from char*

	for (DWORD i = 0; i < packet.dwLength; i++) { //copy data bytes to data member of struct
		packet.bData[i] = outPacket[i];
	}

	SendPacket(packet.bData, packet.dwLength);
	free(outPacket);
}

void Recv(char* textPacket)
{
	OutPacket packet;
	packet.dwLength = getPacketLength(textPacket); //get packet len

	unsigned char* outPacket = convertStringToPacketFormat(textPacket); //parse packet to unsigned char* from char*

	for (DWORD i = 0; i < packet.dwLength; i++) { //copy data bytes to data member of struct
		packet.bData[i] = outPacket[i];
	}

	RecvPacket(packet.bData, packet.dwLength);
	free(outPacket);
}

unsigned short Opcode;
BOOL CreatePacket(LPBYTE data, DWORD length) {



	memcpy(&Opcode, (void*)&data[0], sizeof(uint16_t));

	Opcode = changeEndianness16(Opcode);

	for (auto & element : ModifyList) {

		if ((uint16_t)element->opcode == (uint16_t)Opcode) { //found modified

			//if (CheckPattern(element->pattern, &packet[2], packetLen - 2) == TRUE) {

			//	//send a packet which wont cause a recursive send via the modify
			//	//then return false to block it

			//	//need createthread
			//	thread_packet* pak = new thread_packet();
			//	pak->packet = convertPacketFormatToString(element->replacement, packetLen - 2);
			//	pak->size = packetLen - 2;

			//	Thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&_SendPacket, (LPVOID)pak, 0, 0);

			//	return false;
			//}

			return TRUE;
		}
	}


	for (auto & element : IgnoredList) {

		if ((uint16_t)element == (uint16_t)Opcode) { //found ignored
			return TRUE;
		}
	}

	//if (isBottingSilver == FALSE)
	//{
		PacketWriter* p = new PacketWriter();

		for (int i = 0; i < length; i++) {
			p->Write<byte>(data[i]);
		}

		SendPacketQueue.push(p);

		for (auto & element : BlockedList) {

			if ((uint16_t)element == (uint16_t)Opcode) { //found blocked, still log it?
				return FALSE;
			}
		}

		return TRUE;
	//}
	return FALSE;
}

uint16_t RecvOpcode;
BOOL CreateRecvPacket(LPBYTE data, DWORD length) {

	//if (length < 0)
	//	return FALSE;

	memcpy(&RecvOpcode, (void*)&data[0], sizeof(uint16_t));

	RecvOpcode = changeEndianness16(RecvOpcode);

	//lets do some blocking here.

	if (RecvOpcode == 0xC074|| RecvOpcode == 0x342A || RecvOpcode == 0x2009)
	{
		return TRUE;
	}


	for (auto & element : ModifyList) {

		if ((uint16_t)element->opcode == (uint16_t)RecvOpcode) { //found modified

			//if (CheckPattern(element->pattern, &packet[2], packetLen - 2) == TRUE) {

			//	//send a packet which wont cause a recursive send via the modify
			//	//then return false to block it

			//	//need createthread
			//	thread_packet* pak = new thread_packet();
			//	pak->packet = convertPacketFormatToString(element->replacement, packetLen - 2);
			//	pak->size = packetLen - 2;

			//	Thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&_SendPacket, (LPVOID)pak, 0, 0);

			//	return false;
			//}

			return TRUE;
		}
	}


	for (auto & element : RecvIgnoredList) {

		if ((uint16_t)element == (uint16_t)RecvOpcode) { //found ignored
			return TRUE;
		}
	}


	PacketWriter* p = new PacketWriter();

	for (int i = 0; i < length; i++) {
		p->Write<byte>(data[i]);
	}

	RecvPacketQueue.push(p);

	for (auto & element : RecvBlockedList) {

		if ((uint16_t)element == (uint16_t)RecvOpcode) { //found blocked, still log it?
			return FALSE;
		}
	}

	return FALSE;
}
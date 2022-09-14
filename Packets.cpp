#include "Packets.hpp"

std::queue<PacketWriter*> SendPacketQueue;
std::vector<uint16_t> BlockedList;
std::vector<uint16_t> IgnoredList;
std::vector<ModifyRule*> ModifyList;

std::queue<PacketWriter*> RecvPacketQueue;
std::vector<uint16_t> RecvBlockedList;
std::vector<uint16_t> RecvIgnoredList;
std::vector<ModifyRule*> RecvModifyList;

extern BOOL isDisconnected;

unsigned short Opcode;

BOOL PacketHelper::CreatePacket(LPBYTE data, UINT length) {

	memcpy(&Opcode, (void*)&data[0], sizeof(uint16_t));

	Opcode = PacketHelper::changeEndianness16(Opcode);

	if (Opcode == Opcodes::Send::Ping) //stuff we dont want logged
	{
		return FALSE;
	}

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
}

uint16_t RecvOpcode;
BOOL PacketHelper::CreateRecvPacket(LPBYTE data, DWORD length) {

	if (length == 0)
		return FALSE;

	memcpy(&RecvOpcode, (void*)&data[0], sizeof(uint16_t));

	RecvOpcode = PacketHelper::changeEndianness16(RecvOpcode);

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

	PacketWriter* p = new PacketWriter(); //push to queue

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

uint16_t PacketHelper::changeEndianness16(UINT16 val)
{
	return (val << 8) | ((val >> 8) & 0x00ff); // right-shift sign-extends, so force to zero
}

int32_t PacketHelper::changeEndianness32(int32_t val)
{
	int32_t tmp = (val << 16) |
		((val >> 16) & 0x00ffff);
	return ((tmp >> 8) & 0x00ff00ff) | ((tmp & 0x00ff00ff) << 8);
}

std::string PacketHelper::randomStr(size_t size)
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, size);    // assumes 32 < number of characters in str         
}

std::wstring PacketHelper::randomWStr(size_t size)
{
	std::wstring str(L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, size);    // assumes 32 < number of characters in str         
}


std::string PacketHelper::ToString(LPBYTE packetStr, int byteLength)
{
	if (byteLength <= 0)
		return NULL;

	std::string newStr = string();
	CHAR* convertStr = (CHAR*)malloc(byteLength * 3); //* 3 since 00[ ] an extra 0 with a space for each byte in the str.

	for (int i = 0; i < byteLength; i++) {
		byte ch = packetStr[i];
		sprintf(&convertStr[i], "%.2X", ch);
		newStr.append(&convertStr[i]);
		newStr.append(" ");
	}

	free(convertStr);
	return newStr;
}

int PacketHelper::GetPacketLength(CHAR* input)
{
	int length = 0;

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ')
			length = length;
		else
			length++;
	}

	length = length / 2;

	return length;
}

int PacketHelper::rand_lim(int limit)
{
	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

LPBYTE PacketHelper::ToPacketFormat(CHAR* input) //literally the worst old func left still... lmao
{
	char fixedString[2048] = { 0 };

	//strip spaces, bad text
	int i; int j = 0;

	for (i = 0; input[i] != '\0'; i++) {
		if ((input[i] >= 'A' && input[i] <= 'F') || (input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'f'))  {
			fixedString[j] = input[i];
			j++;
		}
		else if (input[i] == ' ') {

		}
		else if (input[i] == '*') {

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
			return NULL;
		}

	}

	LPBYTE bytestring = (unsigned char*)malloc((j * 2) + 1);

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

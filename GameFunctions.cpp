#include "GameFunctions.hpp"

extern BOOL castingKillSkill;
extern BOOL isBottingSilver;

//ESP + 8 = Data
//ESP + 16 = Len
DWORD dwLen = 0x00752A20;
DWORD dwSendClass = 0x019F9F7C;
VOID __stdcall SendPacket(LPBYTE data, DWORD length)
{
	dwLen = length;
	__asm
	{
		mov eax, dwSendClass
		mov eax, [eax]
		mov ecx, eax
		push dwLen
		push data
		call dwSendPacket
	}
}

int OMGWTF = 0;
VOID __stdcall RecvPacket(LPBYTE data, DWORD length)
{
	OMGWTF = length;
	__asm
	{
		push OMGWTF
		push data
		call dwRecvPacket
	}
}

VOID StartQuest(char* questID)
{
	PacketWriter* p = new PacketWriter();
	p->Write<SHORT>(0x0CEF);
	p->Write<UINT64>(0);
	p->Write<SHORT>(4);
	p->WriteNoLengthString(string(questID));
	p->WriteZeros(33 - strlen(questID));
	SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
}

VOID CastAdminBuffs()
{
	short skillIDs[] = { 2110, 2111, 2112, 2113, 2114, 2115, 2116 };

	for (int i = 0; i <= 6; i++)
	{
		PacketWriter* p = new PacketWriter();
		p->Write<SHORT>(0x0C6B); //opcode
		p->Write<UINT64>(0);
		p->Write<BYTE>(0);
		p->Write<SHORT>(skillIDs[i]);
		p->Write<UINT64>(0);
		p->Write<SHORT>(0);
		SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
		Sleep(1000);
	}
}

VOID CastKillSkill()//?????????
{
	while (castingKillSkill == TRUE)
	{
		PacketWriter* p = new PacketWriter();
		p->Write<SHORT>(0x0C6B); //opcode
		p->Write<UINT64>(0);
		p->Write<BYTE>(0);
		p->Write<SHORT>(0x05FC);
		p->Write<UINT64>(0);
		p->Write<SHORT>(0);
		SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
		Sleep(100);
	}
}


extern DWORD NPCUniqueID;
extern byte DungeonMultiplier;

VOID Bot360Dungeon()
{
	char buf[5];
	itoa(DungeonMultiplier, buf, 10);
	char EnterDungeonPacket[] = "3F 0E 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 ";
	memcpy(&EnterDungeonPacket[43], buf, 1);

	Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 D9 27 6D 43 5F FE 29 44 9E 0A B9 C4");
	Sleep(3000);

	BYTE packet[] = { 0x5D, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(&packet[10], &NPCUniqueID, sizeof(DWORD));
		
	SendPacket(&packet[0], 15); //npc enter

	Sleep(2500);
		
	Send("9E 0C 00 00 00 00 00 00 00 00 01 00 00 00");

	Sleep(3000);

	Send(EnterDungeonPacket);

	Sleep(30000);

	DWORD MinuteTimerTo50 = 3000; //3000 seconds, 60 sec * 50 minutes

	while (MinuteTimerTo50 >= 8)
	{
		if (isBottingSilver)
		{
			Send("6B 0C 00 00 00 00 00 00 00 00 00 df 05 00 00 00 00 00 00 00 00 00 00 00 00");
			Sleep(1250);
			Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");
			Sleep(1250);
			Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 89 F5 8B C4 DC 34 1D 43 22 9C 9B C1");
			Sleep(1250);
			Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 D4 3C A9 C4 E9 68 20 43 0A 4B 4B C3");
			Sleep(1250);
			Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 89 F5 8C C4 DF 32 11 43 22 9d 9c C3");
			Sleep(2250);

			MinuteTimerTo50 -= 7;
		}

		//add timer here, if its met, send 85 0e then call recursivel
	}

	Send("85 0E 00 00 00 00 00 00 00 00");

	Sleep(15000);

	Bot360Dungeon();
}

VOID Bot300Dungeon()
{
	BYTE EnterDungeonPacket[] = { 0x3F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	memcpy(&EnterDungeonPacket[14], &DungeonMultiplier, sizeof(DWORD));
	
	__asm
	{
		pushad
		push eax
		xor eax, eax
		je cont
		add esp, 0x00FFFF00
		jmp $+3
	cont:
		pop eax
		popad
		push eax
		xor eax, eax
		jz execute
		or esp, 0x00FFFFFF
		jmp $ + 172
	execute:
		pop eax
	}

	while (isBottingSilver)
	{
		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 A5 C3 EC 26 71 43 01 C0 50 44"); 
		
		//3F 0E 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 

		Sleep(2500);

		BYTE packet[] = { 0x5D, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		memcpy(&packet[10], &NPCUniqueID, sizeof(DWORD));
		SendPacket(&packet[0], 15);

		Sleep(2000);

		Send("9F 0C 00 00 00 00 00 00 00 00 01");

		Sleep(2000);

		Send("9E 0C 00 00 00 00 00 00 00 00 01 00 00 00");

		Sleep(1000);

		SendPacket(EnterDungeonPacket, 18);

		Sleep(700);

		Send("86 0E 00 00 00 00 00 00 00 00 01"); //enter if already inside dungeon

		Sleep(16500);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 df 05 00 00 00 00 00 00 00 00 00 00");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 35 C3 9F 44 B1 42 00 00 C6 C3");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 AD C3 00 00 C0 C0 00 00 BC C3 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 05 C4 00 00 C0 C0 00 00 C6 C3 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 39 C4 00 00 C0 C0 00 00 BC C3 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 3B C4 00 00 C0 C0 00 00 D2 C2 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 64 C4 00 00 10 C2 00 00 3B C3");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 E0 87 C4 00 00 B2 C2 00 00 3C C3 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 97 C4 00 00 B2 C2 00 80 90 C3 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 40 A7 C4 00 00 B2 C2 00 00 A3 C3 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 B4 C4 00 00 B2 C2 00 00 48 C3 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A1 C4 00 00 B2 C2 00 00 D0 C1 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 60 A1 C4 9F 44 B1 42 00 00 30 43 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 20 B1 C4 9F 44 B1 42 00 80 9D 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 E0 90 C4 9F 44 B1 42 00 00 8F 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 9F C4 9F 44 B1 42 00 00 B7 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 8D C4 9F 44 B1 42 00 80 F4 43 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 B2 C4 9F 44 B1 42 00 80 EB 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 20 A3 C4 9F 44 B1 42 00 80 F2 43 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 df 05 00 00 00 00 00 00 00 00 00 00");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 37 C4 00 00 C0 C0 00 00 9A 42 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 38 C4 00 00 C0 C0 00 00 73 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 37 C4 9F 44 B1 42 00 00 D4 43 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 37 C4 00 00 C0 C0 00 40 20 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 37 C4 00 00 C0 C0 00 00 4F 44 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 36 C4 00 00 C0 C0 00 C0 8A 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 5E C4 9F 44 B1 42 00 40 75 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 81 C4 00 00 B2 C2 00 40 76 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 97 C4 00 00 B2 C2 00 C0 60 44 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 60 A4 C4 9F 44 B1 42 00 00 70 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 A0 90 C4 00 00 B2 C2 00 40 8A 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 E0 AA C4 00 00 B2 C2 00 40 8A 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 20 B7 C4 00 00 B2 C2 00 C0 53 44 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 60 BB C4 00 00 B2 C2 00 20 82 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 FD C3 00 00 C0 C0 00 40 90 44");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 df 05 00 00 00 00 00 00 00 00 00 00");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 8F C3 00 00 C0 C0 00 40 90 44");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 9F 44 B1 42 41 00 00 C0 C0 00 C0 6D 44");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 E2 C2 9F 44 B1 42 00 00 2F 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 74 C3 9F 44 B1 42 00 40 53 44");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 71 C3 9F 44 B1 42 00 C0 0B 44");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 F7 C3 9F 44 B1 42 00 40 03 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 0B C4 9F 44 B1 42 00 80 2D 44");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 CF C3 9F 44 B1 42 00 C0 50 44 ");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C9 C3 00 00 86 C2 00 40 2E 44");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 DC C2 9F 44 B1 42 00 00 A2 42");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 84 C3 00 00 54 C2 00 00 A0 42");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 9F C3 9F 44 B1 42 00 00 D8 C2");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 02 C4 9F 44 B1 42 00 00 38 C2 ");

		Sleep(1250);

		Send("6B 0C 00 00 00 00 00 00 00 00 00 98 f3 00 00 96 DA 65 3E A2 77 79 3F");

		Sleep(1050);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 EC C3 9F 44 B1 42 00 00 3B 43");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 80 9E C3 9F 44 B1 42 00 00 7D 43");

		Sleep(1250);

		Send("54 0E 00 00 00 00 00 00 00 00 00 00 00 00 00 00 B1 C3 00 00 58 C2 00 00 92 42 ");

		Sleep(1500);

		Send("85 0E 00 00 00 00 00 00 00 00");
		//3F 0E 00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 


		Sleep(15000);
	}
}
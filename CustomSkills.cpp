#include "CustomSkills.hpp"
#include "Packets.hpp"

//FUCKING CANCER 
HANDLE CustomSkillThread1 = 0;
HANDLE CustomSkillThread2 = 0;
HANDLE CustomSkillThread3 = 0;
HANDLE CustomSkillThread4 = 0;
HANDLE CustomSkillThread5 = 0;
HANDLE CustomSkillThread6 = 0;
HANDLE CustomSkillThread7 = 0;

UINT32 CustomSkill1 = 0;
UINT32 CustomSkill2 = 0;
UINT32 CustomSkill3 = 0;
UINT32 CustomSkill4 = 0;
UINT32 CustomSkill5 = 0;
UINT32 CustomSkill6 = 0;
UINT32 CustomSkill7 = 0;

BOOL isCasting = false;

unordered_map <string, unsigned int> SkillMap = unordered_map<string, unsigned int>();

void InitializeSkillMap()
{
	SkillMap["God Shield"] = 62360;
	SkillMap["STR Buff"] = 105;
	SkillMap["Taunt"] = 62360;
	SkillMap["Reward"] = 19008;
	SkillMap["Quicken"] = 20801;
	SkillMap["Lightning AOE"] = 2028;
	SkillMap["EXP Bonus"] = 2116;
	SkillMap["Attack Bonus"] = 2114;
	SkillMap["Statue of Vakarine"] = 40401;
	SkillMap["Haste"] = 60814;
	SkillMap["Big red AOE Circle"] = 61680;
	SkillMap["Mitris AOE"] = 60308;
	SkillMap["Ice Vac"] = 62414;
	SkillMap["Swell Body"] = 20503;
	SkillMap["Clairvoyance"] = 41004;
	SkillMap["Resetting"] = 41007;
	SkillMap["Double Pay Earn"] = 11003;
	SkillMap["Aukuras"] = 40101;
	SkillMap["Daino"] = 40103;
	SkillMap["Rain Poop"] = 62313;
	SkillMap["Super Acid Man"] = 62312;
	SkillMap["Double Earthquake"] = 62310;
	SkillMap["Pink Planet"] = 62302;
	SkillMap["Shock Absorption"] = 62300;
	SkillMap["Star Attack"] = 2096;
	SkillMap["Fire Pillar"] = 2098;
	SkillMap["Ultimate AOE"] = 60308;
	SkillMap["Divine Aura"] = 49008;
	SkillMap["Super Mario Star"] = 1503;
}

void CastSkill(INT32 SkillID)
{
	PacketWriter* p = new PacketWriter();
	p->Write<SHORT>(0x0C6B); //opcode
	p->Write<UINT64>(0);
	p->Write<BYTE>(0);
	p->Write<USHORT>(SkillID);
	p->Write<UINT64>(0);
	p->Write<SHORT>(0);
	SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;
}

void UseCustomSkill1(LPVOID Timer)
{
	int time = *static_cast<int*>(Timer);
	delete Timer;

	while (CustomSkillThread1 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill1); 
		Sleep(time);
	}
}

void UseCustomSkill2(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread2 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill2);
		Sleep(SleepTime);
	}
}

void UseCustomSkill3(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread3 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill3);
		Sleep(SleepTime);
	}
}

void UseCustomSkill4(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread4 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill4);
		Sleep(SleepTime);
	}
}

void UseCustomSkill5(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread5 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill5);
		Sleep(SleepTime);
	}
}

void UseCustomSkill6(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread6 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill6);
		Sleep(SleepTime);
	}
}

void UseCustomSkill7(LPVOID Timer)
{
	int SleepTime = *static_cast<int*>(Timer);

	while (CustomSkillThread7 != INVALID_HANDLE_VALUE)
	{
		CastSkill(CustomSkill7);
		Sleep(SleepTime);
	}
}
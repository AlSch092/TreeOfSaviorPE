#pragma once
#include "LuaHelper.hpp"
#include "Hooks.hpp"
#include "Pointer.hpp"
#include "CustomSkills.hpp"
#include <queue>

//-----------Custom Skills---------------------------//
extern unordered_map <string, unsigned int> SkillMap;

extern HANDLE CustomSkillThread1;
extern HANDLE CustomSkillThread2;
extern HANDLE CustomSkillThread3;
extern HANDLE CustomSkillThread4;
extern HANDLE CustomSkillThread5;
extern HANDLE CustomSkillThread6;
extern HANDLE CustomSkillThread7;

extern UINT32 CustomSkill1;
extern UINT32 CustomSkill2;
extern UINT32 CustomSkill3;
extern UINT32 CustomSkill4;
extern UINT32 CustomSkill5;
extern UINT32 CustomSkill6;
extern UINT32 CustomSkill7;

extern BOOL isCasting;
//-----------Custom Skills---------------------------//

HANDLE ScriptThread; //lua

extern DWORD hiddenActorCoords;
extern std::queue<PacketWriter*> SendPacketQueue;
extern std::vector<uint16_t> BlockedList;
extern std::vector<uint16_t> IgnoredList;
extern std::vector<ModifyRule*> ModifyList;

extern std::queue<PacketWriter*> RecvPacketQueue;
extern std::vector<uint16_t> RecvBlockedList;
extern std::vector<uint16_t> RecvIgnoredList;
extern std::vector<ModifyRule*> RecvModifyList;

extern BOOL isAutoLogin;
extern short channelID;
extern byte charIndex;

BOOL castingKillSkill = FALSE;
BOOL isBottingSilver = FALSE;
BOOL isDisconnected = FALSE;
HANDLE BotThread;
BYTE DungeonMultiplier;

namespace TOSPE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_LogPackets;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  copySelectedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearLogToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_PacketRules;
	private: System::Windows::Forms::ToolStripMenuItem^  removeRuleToolStripMenuItem;
		Thread^ UpdateGUIThread;
		Thread^ SendLogThread;
		Thread^ RecvLogThread;

	private: System::Windows::Forms::Label^  label_Z;

	private: System::Windows::Forms::Label^  label_Y;

	private: System::Windows::Forms::Label^  label_X;







	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox2;



	private: System::Windows::Forms::CheckBox^  checkBox_HookRecv;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ListView^  listView_RecvPacketLog;

	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_LogRecvPackets;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::Button^  button_RecvPacket;
	private: System::Windows::Forms::TextBox^  textBox_RecvPacket;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::CheckBox^  checkBox_AdminBuffs;

	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button_EndScript;
	private: System::Windows::Forms::Button^  button_RunScript;
	private: System::Windows::Forms::TextBox^  textBox_ScriptText;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill7;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill6;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill5;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill4;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill3;
	private: System::Windows::Forms::TextBox^  textBox_CustomSkills7;

	private: System::Windows::Forms::TextBox^  textBox_CustomSkills6;

	private: System::Windows::Forms::TextBox^  textBox_CustomSkills5;

	private: System::Windows::Forms::TextBox^  textBox_CustomSkills4;

	private: System::Windows::Forms::TextBox^  textBox_CustomSkills3;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills7;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills6;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills5;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills4;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills3;

	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills1;

	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill1;
	private: System::Windows::Forms::CheckBox^  checkBox_CustomSkill2;
	private: System::Windows::Forms::ComboBox^  comboBox_CustomSkills2;
	private: System::Windows::Forms::TextBox^  textBox_CustomSkills2;


	private: System::Windows::Forms::TextBox^  textBox_CustomSkills1;

	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::GroupBox^  groupBox_AutoLogin;
	private: System::Windows::Forms::CheckBox^  checkBox_AutoLogin;
	private: System::Windows::Forms::Label^  label_CharIndex;
	private: System::Windows::Forms::Label^  label_Channel;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_CharID;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_ChannelID;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::CheckBox^  checkBox_SilverFarmBot;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::NumericUpDown^  numericUpDown_DungeonMultiplier;
private: System::Windows::Forms::Button^  button_SummonVelcoffer;
private: System::Windows::Forms::Button^  button_SummonFireSpirit;

	Thread^ SpamPacketThread;
	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView_PacketLog;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketLength;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketData;
	private: System::Windows::Forms::TextBox^  textBox_SendPacket;
	private: System::Windows::Forms::Button^  button_SendPacket;
	private: System::Windows::Forms::GroupBox^  groupBox_Options;
	private: System::Windows::Forms::TabControl^  tabControl_PacketOptions;
	private: System::Windows::Forms::TabPage^  tabPage_SendTools;


	private: System::Windows::Forms::TextBox^  textBox_SpamPacketDelay;
	private: System::Windows::Forms::CheckBox^  checkBox_SpamPacket;
	private: System::Windows::Forms::TabPage^  tabPage_LogTools;
	private: System::Windows::Forms::Button^  button_BlockPacket;
	private: System::Windows::Forms::Button^  button_IgnorePacket;
	private: System::Windows::Forms::ListView^  listView_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRulesData;
	private: System::Windows::Forms::Button^  button_ModifyPacket;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule2;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule1;
	private: System::Windows::Forms::CheckBox^  checkBox_HookSend;
	private: System::Windows::Forms::TabPage^  tabPage_Misc;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->listView_PacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketLength = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_LogPackets = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copySelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_SendPacket = (gcnew System::Windows::Forms::TextBox());
			this->button_SendPacket = (gcnew System::Windows::Forms::Button());
			this->groupBox_Options = (gcnew System::Windows::Forms::GroupBox());
			this->tabControl_PacketOptions = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_SendTools = (gcnew System::Windows::Forms::TabPage());
			this->textBox_SpamPacketDelay = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox_SpamPacket = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage_LogTools = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_HookRecv = (gcnew System::Windows::Forms::CheckBox());
			this->button_BlockPacket = (gcnew System::Windows::Forms::Button());
			this->button_IgnorePacket = (gcnew System::Windows::Forms::Button());
			this->listView_PacketRules = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketRules = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketRulesData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_PacketRules = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->removeRuleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_ModifyPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_PacketRule2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_PacketRule1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_HookSend = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Misc = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_DungeonMultiplier = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_SilverFarmBot = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_AutoLogin = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_AutoLogin = (gcnew System::Windows::Forms::CheckBox());
			this->label_CharIndex = (gcnew System::Windows::Forms::Label());
			this->label_Channel = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_CharID = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_ChannelID = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label_X = (gcnew System::Windows::Forms::Label());
			this->label_Y = (gcnew System::Windows::Forms::Label());
			this->label_Z = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_SummonFireSpirit = (gcnew System::Windows::Forms::Button());
			this->button_SummonVelcoffer = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_CustomSkill7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CustomSkill6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CustomSkill5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CustomSkill4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CustomSkill3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox_CustomSkills7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CustomSkills6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CustomSkills5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CustomSkills4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CustomSkills3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_CustomSkills7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_CustomSkills6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_CustomSkills5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_CustomSkills4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_CustomSkills3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_CustomSkills1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox_CustomSkill1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_CustomSkill2 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox_CustomSkills2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_CustomSkills2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_CustomSkills1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_AdminBuffs = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button_RecvPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_RecvPacket = (gcnew System::Windows::Forms::TextBox());
			this->listView_RecvPacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_LogRecvPackets = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button_EndScript = (gcnew System::Windows::Forms::Button());
			this->button_RunScript = (gcnew System::Windows::Forms::Button());
			this->textBox_ScriptText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->contextMenuStrip_LogPackets->SuspendLayout();
			this->groupBox_Options->SuspendLayout();
			this->tabControl_PacketOptions->SuspendLayout();
			this->tabPage_SendTools->SuspendLayout();
			this->tabPage_LogTools->SuspendLayout();
			this->contextMenuStrip_PacketRules->SuspendLayout();
			this->tabPage_Misc->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_DungeonMultiplier))->BeginInit();
			this->groupBox_AutoLogin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharID))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChannelID))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->contextMenuStrip_LogRecvPackets->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView_PacketLog
			// 
			this->listView_PacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_PacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketLength,
					this->columnHeader_PacketData
			});
			this->listView_PacketLog->ContextMenuStrip = this->contextMenuStrip_LogPackets;
			this->listView_PacketLog->FullRowSelect = true;
			this->listView_PacketLog->GridLines = true;
			this->listView_PacketLog->Location = System::Drawing::Point(6, 6);
			this->listView_PacketLog->Name = L"listView_PacketLog";
			this->listView_PacketLog->Size = System::Drawing::Size(440, 282);
			this->listView_PacketLog->TabIndex = 1;
			this->listView_PacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_PacketLog->View = System::Windows::Forms::View::Details;
			this->listView_PacketLog->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listView_PacketLog_MouseDoubleClick);
			// 
			// columnHeader_PacketLength
			// 
			this->columnHeader_PacketLength->Text = L"Length";
			// 
			// columnHeader_PacketData
			// 
			this->columnHeader_PacketData->Text = L"Data";
			this->columnHeader_PacketData->Width = 854;
			// 
			// contextMenuStrip_LogPackets
			// 
			this->contextMenuStrip_LogPackets->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copySelectedToolStripMenuItem,
					this->clearLogToolStripMenuItem
			});
			this->contextMenuStrip_LogPackets->Name = L"contextMenuStrip_LogPackets";
			this->contextMenuStrip_LogPackets->Size = System::Drawing::Size(153, 70);
			// 
			// copySelectedToolStripMenuItem
			// 
			this->copySelectedToolStripMenuItem->Name = L"copySelectedToolStripMenuItem";
			this->copySelectedToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copySelectedToolStripMenuItem->Text = L"Copy Selected";
			this->copySelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copySelectedToolStripMenuItem_Click);
			// 
			// clearLogToolStripMenuItem
			// 
			this->clearLogToolStripMenuItem->Name = L"clearLogToolStripMenuItem";
			this->clearLogToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->clearLogToolStripMenuItem->Text = L"Clear Log";
			this->clearLogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clearLogToolStripMenuItem_Click);
			// 
			// textBox_SendPacket
			// 
			this->textBox_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_SendPacket->Location = System::Drawing::Point(6, 294);
			this->textBox_SendPacket->Name = L"textBox_SendPacket";
			this->textBox_SendPacket->Size = System::Drawing::Size(379, 20);
			this->textBox_SendPacket->TabIndex = 2;
			this->textBox_SendPacket->Text = L"Enter Packet...";
			// 
			// button_SendPacket
			// 
			this->button_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_SendPacket->Location = System::Drawing::Point(391, 294);
			this->button_SendPacket->Name = L"button_SendPacket";
			this->button_SendPacket->Size = System::Drawing::Size(55, 22);
			this->button_SendPacket->TabIndex = 6;
			this->button_SendPacket->Text = L"Send";
			this->button_SendPacket->UseVisualStyleBackColor = true;
			this->button_SendPacket->Click += gcnew System::EventHandler(this, &MainForm::button_SendPacket_Click);
			// 
			// groupBox_Options
			// 
			this->groupBox_Options->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_Options->Controls->Add(this->tabControl_PacketOptions);
			this->groupBox_Options->Location = System::Drawing::Point(478, 6);
			this->groupBox_Options->Name = L"groupBox_Options";
			this->groupBox_Options->Size = System::Drawing::Size(258, 346);
			this->groupBox_Options->TabIndex = 7;
			this->groupBox_Options->TabStop = false;
			this->groupBox_Options->Text = L"Options";
			// 
			// tabControl_PacketOptions
			// 
			this->tabControl_PacketOptions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_SendTools);
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_LogTools);
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_Misc);
			this->tabControl_PacketOptions->Location = System::Drawing::Point(6, 17);
			this->tabControl_PacketOptions->Name = L"tabControl_PacketOptions";
			this->tabControl_PacketOptions->SelectedIndex = 0;
			this->tabControl_PacketOptions->Size = System::Drawing::Size(246, 323);
			this->tabControl_PacketOptions->TabIndex = 2;
			// 
			// tabPage_SendTools
			// 
			this->tabPage_SendTools->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_SendTools->Controls->Add(this->textBox_SpamPacketDelay);
			this->tabPage_SendTools->Controls->Add(this->button2);
			this->tabPage_SendTools->Controls->Add(this->checkBox_SpamPacket);
			this->tabPage_SendTools->Controls->Add(this->textBox1);
			this->tabPage_SendTools->Location = System::Drawing::Point(4, 22);
			this->tabPage_SendTools->Name = L"tabPage_SendTools";
			this->tabPage_SendTools->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_SendTools->Size = System::Drawing::Size(238, 297);
			this->tabPage_SendTools->TabIndex = 0;
			this->tabPage_SendTools->Text = L"Send Tools";
			// 
			// textBox_SpamPacketDelay
			// 
			this->textBox_SpamPacketDelay->Location = System::Drawing::Point(6, 6);
			this->textBox_SpamPacketDelay->Name = L"textBox_SpamPacketDelay";
			this->textBox_SpamPacketDelay->Size = System::Drawing::Size(100, 20);
			this->textBox_SpamPacketDelay->TabIndex = 0;
			this->textBox_SpamPacketDelay->Text = L"Delay (milliseconds)";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(67, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Use Skill";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// checkBox_SpamPacket
			// 
			this->checkBox_SpamPacket->AutoSize = true;
			this->checkBox_SpamPacket->Location = System::Drawing::Point(112, 9);
			this->checkBox_SpamPacket->Name = L"checkBox_SpamPacket";
			this->checkBox_SpamPacket->Size = System::Drawing::Size(90, 17);
			this->checkBox_SpamPacket->TabIndex = 1;
			this->checkBox_SpamPacket->Text = L"Spam Packet";
			this->checkBox_SpamPacket->UseVisualStyleBackColor = true;
			this->checkBox_SpamPacket->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_SpamPacket_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(5, 273);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(58, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Skill ID";
			this->textBox1->Visible = false;
			// 
			// tabPage_LogTools
			// 
			this->tabPage_LogTools->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_LogTools->Controls->Add(this->checkBox_HookRecv);
			this->tabPage_LogTools->Controls->Add(this->button_BlockPacket);
			this->tabPage_LogTools->Controls->Add(this->button_IgnorePacket);
			this->tabPage_LogTools->Controls->Add(this->listView_PacketRules);
			this->tabPage_LogTools->Controls->Add(this->button_ModifyPacket);
			this->tabPage_LogTools->Controls->Add(this->textBox_PacketRule2);
			this->tabPage_LogTools->Controls->Add(this->textBox_PacketRule1);
			this->tabPage_LogTools->Controls->Add(this->checkBox_HookSend);
			this->tabPage_LogTools->Location = System::Drawing::Point(4, 22);
			this->tabPage_LogTools->Name = L"tabPage_LogTools";
			this->tabPage_LogTools->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_LogTools->Size = System::Drawing::Size(238, 297);
			this->tabPage_LogTools->TabIndex = 1;
			this->tabPage_LogTools->Text = L"Log Tools";
			// 
			// checkBox_HookRecv
			// 
			this->checkBox_HookRecv->AutoSize = true;
			this->checkBox_HookRecv->Location = System::Drawing::Point(90, 6);
			this->checkBox_HookRecv->Name = L"checkBox_HookRecv";
			this->checkBox_HookRecv->Size = System::Drawing::Size(81, 17);
			this->checkBox_HookRecv->TabIndex = 11;
			this->checkBox_HookRecv->Text = L"Hook Recv";
			this->checkBox_HookRecv->UseVisualStyleBackColor = true;
			this->checkBox_HookRecv->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_HookRecv_CheckedChanged);
			// 
			// button_BlockPacket
			// 
			this->button_BlockPacket->Location = System::Drawing::Point(6, 272);
			this->button_BlockPacket->Name = L"button_BlockPacket";
			this->button_BlockPacket->Size = System::Drawing::Size(70, 20);
			this->button_BlockPacket->TabIndex = 10;
			this->button_BlockPacket->Text = L"Block";
			this->button_BlockPacket->UseVisualStyleBackColor = true;
			this->button_BlockPacket->Click += gcnew System::EventHandler(this, &MainForm::button_BlockPacket_Click);
			// 
			// button_IgnorePacket
			// 
			this->button_IgnorePacket->Location = System::Drawing::Point(78, 272);
			this->button_IgnorePacket->Name = L"button_IgnorePacket";
			this->button_IgnorePacket->Size = System::Drawing::Size(66, 20);
			this->button_IgnorePacket->TabIndex = 9;
			this->button_IgnorePacket->Text = L"Ignore";
			this->button_IgnorePacket->UseVisualStyleBackColor = true;
			this->button_IgnorePacket->Click += gcnew System::EventHandler(this, &MainForm::button_IgnorePacket_Click);
			// 
			// listView_PacketRules
			// 
			this->listView_PacketRules->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketRules,
					this->columnHeader_PacketRulesData
			});
			this->listView_PacketRules->ContextMenuStrip = this->contextMenuStrip_PacketRules;
			this->listView_PacketRules->FullRowSelect = true;
			this->listView_PacketRules->GridLines = true;
			this->listView_PacketRules->Location = System::Drawing::Point(6, 29);
			this->listView_PacketRules->Name = L"listView_PacketRules";
			this->listView_PacketRules->Size = System::Drawing::Size(226, 185);
			this->listView_PacketRules->TabIndex = 8;
			this->listView_PacketRules->UseCompatibleStateImageBehavior = false;
			this->listView_PacketRules->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketRules
			// 
			this->columnHeader_PacketRules->Text = L"Rule";
			// 
			// columnHeader_PacketRulesData
			// 
			this->columnHeader_PacketRulesData->Text = L"Packet/Opcode";
			this->columnHeader_PacketRulesData->Width = 148;
			// 
			// contextMenuStrip_PacketRules
			// 
			this->contextMenuStrip_PacketRules->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->removeRuleToolStripMenuItem });
			this->contextMenuStrip_PacketRules->Name = L"contextMenuStrip_PacketRules";
			this->contextMenuStrip_PacketRules->Size = System::Drawing::Size(144, 26);
			// 
			// removeRuleToolStripMenuItem
			// 
			this->removeRuleToolStripMenuItem->Name = L"removeRuleToolStripMenuItem";
			this->removeRuleToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->removeRuleToolStripMenuItem->Text = L"Remove Rule";
			this->removeRuleToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::removeRuleToolStripMenuItem_Click);
			// 
			// button_ModifyPacket
			// 
			this->button_ModifyPacket->Location = System::Drawing::Point(148, 272);
			this->button_ModifyPacket->Name = L"button_ModifyPacket";
			this->button_ModifyPacket->Size = System::Drawing::Size(84, 20);
			this->button_ModifyPacket->TabIndex = 7;
			this->button_ModifyPacket->Text = L"Modify";
			this->button_ModifyPacket->UseVisualStyleBackColor = true;
			this->button_ModifyPacket->Click += gcnew System::EventHandler(this, &MainForm::button_ModifyPacket_Click);
			// 
			// textBox_PacketRule2
			// 
			this->textBox_PacketRule2->Location = System::Drawing::Point(7, 246);
			this->textBox_PacketRule2->Name = L"textBox_PacketRule2";
			this->textBox_PacketRule2->Size = System::Drawing::Size(225, 20);
			this->textBox_PacketRule2->TabIndex = 5;
			this->textBox_PacketRule2->Text = L"Replacement (Modify)";
			// 
			// textBox_PacketRule1
			// 
			this->textBox_PacketRule1->Location = System::Drawing::Point(7, 220);
			this->textBox_PacketRule1->Name = L"textBox_PacketRule1";
			this->textBox_PacketRule1->Size = System::Drawing::Size(225, 20);
			this->textBox_PacketRule1->TabIndex = 4;
			this->textBox_PacketRule1->Text = L"Pattern (\?\? = wildcard)";
			// 
			// checkBox_HookSend
			// 
			this->checkBox_HookSend->AutoSize = true;
			this->checkBox_HookSend->Location = System::Drawing::Point(7, 7);
			this->checkBox_HookSend->Name = L"checkBox_HookSend";
			this->checkBox_HookSend->Size = System::Drawing::Size(80, 17);
			this->checkBox_HookSend->TabIndex = 3;
			this->checkBox_HookSend->Text = L"Hook Send";
			this->checkBox_HookSend->UseVisualStyleBackColor = true;
			this->checkBox_HookSend->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_HookSend_CheckedChanged);
			// 
			// tabPage_Misc
			// 
			this->tabPage_Misc->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_Misc->Controls->Add(this->groupBox4);
			this->tabPage_Misc->Controls->Add(this->groupBox_AutoLogin);
			this->tabPage_Misc->Controls->Add(this->groupBox2);
			this->tabPage_Misc->Controls->Add(this->button1);
			this->tabPage_Misc->Location = System::Drawing::Point(4, 22);
			this->tabPage_Misc->Name = L"tabPage_Misc";
			this->tabPage_Misc->Size = System::Drawing::Size(238, 297);
			this->tabPage_Misc->TabIndex = 2;
			this->tabPage_Misc->Text = L"Hacks";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->numericUpDown_DungeonMultiplier);
			this->groupBox4->Controls->Add(this->checkBox_SilverFarmBot);
			this->groupBox4->Location = System::Drawing::Point(3, 223);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(229, 71);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Silver farm bot";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(70, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Multiplier";
			// 
			// numericUpDown_DungeonMultiplier
			// 
			this->numericUpDown_DungeonMultiplier->Location = System::Drawing::Point(6, 42);
			this->numericUpDown_DungeonMultiplier->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				System::Int32::MinValue,
					0, 0, 0
			});
			this->numericUpDown_DungeonMultiplier->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, System::Int32::MinValue });
			this->numericUpDown_DungeonMultiplier->Name = L"numericUpDown_DungeonMultiplier";
			this->numericUpDown_DungeonMultiplier->Size = System::Drawing::Size(59, 20);
			this->numericUpDown_DungeonMultiplier->TabIndex = 1;
			// 
			// checkBox_SilverFarmBot
			// 
			this->checkBox_SilverFarmBot->AutoSize = true;
			this->checkBox_SilverFarmBot->Location = System::Drawing::Point(7, 21);
			this->checkBox_SilverFarmBot->Name = L"checkBox_SilverFarmBot";
			this->checkBox_SilverFarmBot->Size = System::Drawing::Size(59, 17);
			this->checkBox_SilverFarmBot->TabIndex = 0;
			this->checkBox_SilverFarmBot->Text = L"Enable";
			this->checkBox_SilverFarmBot->UseVisualStyleBackColor = true;
			this->checkBox_SilverFarmBot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_SilverFarmBot_CheckedChanged);
			// 
			// groupBox_AutoLogin
			// 
			this->groupBox_AutoLogin->Controls->Add(this->checkBox_AutoLogin);
			this->groupBox_AutoLogin->Controls->Add(this->label_CharIndex);
			this->groupBox_AutoLogin->Controls->Add(this->label_Channel);
			this->groupBox_AutoLogin->Controls->Add(this->numericUpDown_CharID);
			this->groupBox_AutoLogin->Controls->Add(this->numericUpDown_ChannelID);
			this->groupBox_AutoLogin->Location = System::Drawing::Point(3, 128);
			this->groupBox_AutoLogin->Name = L"groupBox_AutoLogin";
			this->groupBox_AutoLogin->Size = System::Drawing::Size(229, 94);
			this->groupBox_AutoLogin->TabIndex = 10;
			this->groupBox_AutoLogin->TabStop = false;
			this->groupBox_AutoLogin->Text = L"Auto-Login";
			// 
			// checkBox_AutoLogin
			// 
			this->checkBox_AutoLogin->AutoSize = true;
			this->checkBox_AutoLogin->Location = System::Drawing::Point(6, 72);
			this->checkBox_AutoLogin->Name = L"checkBox_AutoLogin";
			this->checkBox_AutoLogin->Size = System::Drawing::Size(59, 17);
			this->checkBox_AutoLogin->TabIndex = 4;
			this->checkBox_AutoLogin->Text = L"Enable";
			this->checkBox_AutoLogin->UseVisualStyleBackColor = true;
			this->checkBox_AutoLogin->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_AutoLogin_CheckedChanged);
			// 
			// label_CharIndex
			// 
			this->label_CharIndex->AutoSize = true;
			this->label_CharIndex->Location = System::Drawing::Point(73, 48);
			this->label_CharIndex->Name = L"label_CharIndex";
			this->label_CharIndex->Size = System::Drawing::Size(58, 13);
			this->label_CharIndex->TabIndex = 3;
			this->label_CharIndex->Text = L"Char Index";
			// 
			// label_Channel
			// 
			this->label_Channel->AutoSize = true;
			this->label_Channel->Location = System::Drawing::Point(73, 20);
			this->label_Channel->Name = L"label_Channel";
			this->label_Channel->Size = System::Drawing::Size(46, 13);
			this->label_Channel->TabIndex = 2;
			this->label_Channel->Text = L"Channel";
			// 
			// numericUpDown_CharID
			// 
			this->numericUpDown_CharID->Location = System::Drawing::Point(6, 46);
			this->numericUpDown_CharID->Name = L"numericUpDown_CharID";
			this->numericUpDown_CharID->Size = System::Drawing::Size(61, 20);
			this->numericUpDown_CharID->TabIndex = 1;
			// 
			// numericUpDown_ChannelID
			// 
			this->numericUpDown_ChannelID->Location = System::Drawing::Point(6, 18);
			this->numericUpDown_ChannelID->Name = L"numericUpDown_ChannelID";
			this->numericUpDown_ChannelID->Size = System::Drawing::Size(61, 20);
			this->numericUpDown_ChannelID->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->textBox11);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->label_X);
			this->groupBox2->Controls->Add(this->label_Y);
			this->groupBox2->Controls->Add(this->label_Z);
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(229, 119);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Coord Hacks";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 88);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(217, 22);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Teleport";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(147, 63);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(76, 20);
			this->textBox11->TabIndex = 5;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(147, 39);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(76, 20);
			this->textBox10->TabIndex = 4;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(147, 13);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(76, 20);
			this->textBox9->TabIndex = 3;
			// 
			// label_X
			// 
			this->label_X->AutoSize = true;
			this->label_X->Location = System::Drawing::Point(8, 19);
			this->label_X->Name = L"label_X";
			this->label_X->Size = System::Drawing::Size(20, 13);
			this->label_X->TabIndex = 0;
			this->label_X->Text = L"X: ";
			// 
			// label_Y
			// 
			this->label_Y->AutoSize = true;
			this->label_Y->Location = System::Drawing::Point(8, 42);
			this->label_Y->Name = L"label_Y";
			this->label_Y->Size = System::Drawing::Size(20, 13);
			this->label_Y->TabIndex = 1;
			this->label_Y->Text = L"Y: ";
			// 
			// label_Z
			// 
			this->label_Z->AutoSize = true;
			this->label_Z->Location = System::Drawing::Point(8, 65);
			this->label_Z->Name = L"label_Z";
			this->label_Z->Size = System::Drawing::Size(20, 13);
			this->label_Z->TabIndex = 2;
			this->label_Z->Text = L"Z: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(150, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(8, 8);
			this->button1->TabIndex = 7;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_SummonFireSpirit);
			this->groupBox1->Controls->Add(this->button_SummonVelcoffer);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->checkBox_AdminBuffs);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(446, 311);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Skill Hacks";
			// 
			// button_SummonFireSpirit
			// 
			this->button_SummonFireSpirit->Location = System::Drawing::Point(12, 282);
			this->button_SummonFireSpirit->Name = L"button_SummonFireSpirit";
			this->button_SummonFireSpirit->Size = System::Drawing::Size(135, 23);
			this->button_SummonFireSpirit->TabIndex = 13;
			this->button_SummonFireSpirit->Text = L"Summon Fire Spirit";
			this->button_SummonFireSpirit->UseVisualStyleBackColor = true;
			this->button_SummonFireSpirit->Click += gcnew System::EventHandler(this, &MainForm::button_SummonFireSpirit_Click);
			// 
			// button_SummonVelcoffer
			// 
			this->button_SummonVelcoffer->Location = System::Drawing::Point(12, 257);
			this->button_SummonVelcoffer->Name = L"button_SummonVelcoffer";
			this->button_SummonVelcoffer->Size = System::Drawing::Size(135, 23);
			this->button_SummonVelcoffer->TabIndex = 12;
			this->button_SummonVelcoffer->Text = L"Summon Velcoffer Army";
			this->button_SummonVelcoffer->UseVisualStyleBackColor = true;
			this->button_SummonVelcoffer->Click += gcnew System::EventHandler(this, &MainForm::button_SummonVelcoffer_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill7);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill6);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill5);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill4);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill3);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills7);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills6);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills5);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills4);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills3);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills7);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills6);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills5);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills4);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills3);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills1);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill1);
			this->groupBox3->Controls->Add(this->checkBox_CustomSkill2);
			this->groupBox3->Controls->Add(this->comboBox_CustomSkills2);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills2);
			this->groupBox3->Controls->Add(this->textBox_CustomSkills1);
			this->groupBox3->Location = System::Drawing::Point(6, 18);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(279, 214);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Custom Skills";
			// 
			// checkBox_CustomSkill7
			// 
			this->checkBox_CustomSkill7->AutoSize = true;
			this->checkBox_CustomSkill7->Location = System::Drawing::Point(202, 180);
			this->checkBox_CustomSkill7->Name = L"checkBox_CustomSkill7";
			this->checkBox_CustomSkill7->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill7->TabIndex = 25;
			this->checkBox_CustomSkill7->Text = L"Activate";
			this->checkBox_CustomSkill7->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill7->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill7_CheckedChanged);
			// 
			// checkBox_CustomSkill6
			// 
			this->checkBox_CustomSkill6->AutoSize = true;
			this->checkBox_CustomSkill6->Location = System::Drawing::Point(202, 154);
			this->checkBox_CustomSkill6->Name = L"checkBox_CustomSkill6";
			this->checkBox_CustomSkill6->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill6->TabIndex = 24;
			this->checkBox_CustomSkill6->Text = L"Activate";
			this->checkBox_CustomSkill6->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill6->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill6_CheckedChanged);
			// 
			// checkBox_CustomSkill5
			// 
			this->checkBox_CustomSkill5->AutoSize = true;
			this->checkBox_CustomSkill5->Location = System::Drawing::Point(202, 127);
			this->checkBox_CustomSkill5->Name = L"checkBox_CustomSkill5";
			this->checkBox_CustomSkill5->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill5->TabIndex = 23;
			this->checkBox_CustomSkill5->Text = L"Activate";
			this->checkBox_CustomSkill5->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill5->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill5_CheckedChanged);
			// 
			// checkBox_CustomSkill4
			// 
			this->checkBox_CustomSkill4->AutoSize = true;
			this->checkBox_CustomSkill4->Location = System::Drawing::Point(202, 101);
			this->checkBox_CustomSkill4->Name = L"checkBox_CustomSkill4";
			this->checkBox_CustomSkill4->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill4->TabIndex = 22;
			this->checkBox_CustomSkill4->Text = L"Activate";
			this->checkBox_CustomSkill4->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill4_CheckedChanged);
			// 
			// checkBox_CustomSkill3
			// 
			this->checkBox_CustomSkill3->AutoSize = true;
			this->checkBox_CustomSkill3->Location = System::Drawing::Point(202, 75);
			this->checkBox_CustomSkill3->Name = L"checkBox_CustomSkill3";
			this->checkBox_CustomSkill3->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill3->TabIndex = 21;
			this->checkBox_CustomSkill3->Text = L"Activate";
			this->checkBox_CustomSkill3->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill3_CheckedChanged);
			// 
			// textBox_CustomSkills7
			// 
			this->textBox_CustomSkills7->Location = System::Drawing::Point(133, 178);
			this->textBox_CustomSkills7->Name = L"textBox_CustomSkills7";
			this->textBox_CustomSkills7->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills7->TabIndex = 20;
			this->textBox_CustomSkills7->Text = L"Delay (Seconds)";
			// 
			// textBox_CustomSkills6
			// 
			this->textBox_CustomSkills6->Location = System::Drawing::Point(133, 151);
			this->textBox_CustomSkills6->Name = L"textBox_CustomSkills6";
			this->textBox_CustomSkills6->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills6->TabIndex = 19;
			this->textBox_CustomSkills6->Text = L"Delay (Seconds)";
			// 
			// textBox_CustomSkills5
			// 
			this->textBox_CustomSkills5->Location = System::Drawing::Point(133, 124);
			this->textBox_CustomSkills5->Name = L"textBox_CustomSkills5";
			this->textBox_CustomSkills5->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills5->TabIndex = 18;
			this->textBox_CustomSkills5->Text = L"Delay (Seconds)";
			// 
			// textBox_CustomSkills4
			// 
			this->textBox_CustomSkills4->Location = System::Drawing::Point(133, 98);
			this->textBox_CustomSkills4->Name = L"textBox_CustomSkills4";
			this->textBox_CustomSkills4->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills4->TabIndex = 17;
			this->textBox_CustomSkills4->Text = L"Delay (Seconds)";
			// 
			// textBox_CustomSkills3
			// 
			this->textBox_CustomSkills3->Location = System::Drawing::Point(133, 72);
			this->textBox_CustomSkills3->Name = L"textBox_CustomSkills3";
			this->textBox_CustomSkills3->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills3->TabIndex = 16;
			this->textBox_CustomSkills3->Text = L"Delay (Seconds)";
			// 
			// comboBox_CustomSkills7
			// 
			this->comboBox_CustomSkills7->FormattingEnabled = true;
			this->comboBox_CustomSkills7->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills7->Location = System::Drawing::Point(6, 178);
			this->comboBox_CustomSkills7->Name = L"comboBox_CustomSkills7";
			this->comboBox_CustomSkills7->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills7->TabIndex = 15;
			this->comboBox_CustomSkills7->Text = L"Mitris AOE";
			// 
			// comboBox_CustomSkills6
			// 
			this->comboBox_CustomSkills6->FormattingEnabled = true;
			this->comboBox_CustomSkills6->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills6->Location = System::Drawing::Point(6, 151);
			this->comboBox_CustomSkills6->Name = L"comboBox_CustomSkills6";
			this->comboBox_CustomSkills6->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills6->TabIndex = 14;
			this->comboBox_CustomSkills6->Text = L"Ice Vac";
			// 
			// comboBox_CustomSkills5
			// 
			this->comboBox_CustomSkills5->FormattingEnabled = true;
			this->comboBox_CustomSkills5->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills5->Location = System::Drawing::Point(6, 124);
			this->comboBox_CustomSkills5->Name = L"comboBox_CustomSkills5";
			this->comboBox_CustomSkills5->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills5->TabIndex = 13;
			this->comboBox_CustomSkills5->Text = L"Fast Run Speed";
			// 
			// comboBox_CustomSkills4
			// 
			this->comboBox_CustomSkills4->FormattingEnabled = true;
			this->comboBox_CustomSkills4->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills4->Location = System::Drawing::Point(6, 98);
			this->comboBox_CustomSkills4->Name = L"comboBox_CustomSkills4";
			this->comboBox_CustomSkills4->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills4->TabIndex = 12;
			this->comboBox_CustomSkills4->Text = L"Rain Poop";
			// 
			// comboBox_CustomSkills3
			// 
			this->comboBox_CustomSkills3->FormattingEnabled = true;
			this->comboBox_CustomSkills3->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills3->Location = System::Drawing::Point(6, 72);
			this->comboBox_CustomSkills3->Name = L"comboBox_CustomSkills3";
			this->comboBox_CustomSkills3->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills3->TabIndex = 11;
			this->comboBox_CustomSkills3->Text = L"EXP Boost";
			// 
			// comboBox_CustomSkills1
			// 
			this->comboBox_CustomSkills1->FormattingEnabled = true;
			this->comboBox_CustomSkills1->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills1->Location = System::Drawing::Point(6, 19);
			this->comboBox_CustomSkills1->Name = L"comboBox_CustomSkills1";
			this->comboBox_CustomSkills1->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills1->TabIndex = 5;
			this->comboBox_CustomSkills1->Text = L"God Shield";
			// 
			// checkBox_CustomSkill1
			// 
			this->checkBox_CustomSkill1->AutoSize = true;
			this->checkBox_CustomSkill1->Location = System::Drawing::Point(202, 23);
			this->checkBox_CustomSkill1->Name = L"checkBox_CustomSkill1";
			this->checkBox_CustomSkill1->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill1->TabIndex = 7;
			this->checkBox_CustomSkill1->Text = L"Activate";
			this->checkBox_CustomSkill1->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill1_CheckedChanged);
			// 
			// checkBox_CustomSkill2
			// 
			this->checkBox_CustomSkill2->AutoSize = true;
			this->checkBox_CustomSkill2->Location = System::Drawing::Point(202, 49);
			this->checkBox_CustomSkill2->Name = L"checkBox_CustomSkill2";
			this->checkBox_CustomSkill2->Size = System::Drawing::Size(65, 17);
			this->checkBox_CustomSkill2->TabIndex = 10;
			this->checkBox_CustomSkill2->Text = L"Activate";
			this->checkBox_CustomSkill2->UseVisualStyleBackColor = true;
			this->checkBox_CustomSkill2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_CustomSkill2_CheckedChanged);
			// 
			// comboBox_CustomSkills2
			// 
			this->comboBox_CustomSkills2->FormattingEnabled = true;
			this->comboBox_CustomSkills2->Items->AddRange(gcnew cli::array< System::Object^  >(29) {
				L"God Shield", L"STR Buff", L"Taunt",
					L"Reward", L"Quicken", L"Lightning AOE", L"EXP Bonus", L"Attack Bonus", L"Statue of Vakarine", L"Haste", L"Big red AOE Circle",
					L"Mitris AOE", L"Ice Vac", L"Swell Body", L"Clairvoyance", L"Resetting", L"Double Pay Earn", L"Aukuras", L"Daino", L"Rain Poop",
					L"Super Acid Man", L"Double Earthquake", L"Pink Planet", L"Shock Absorption", L"Star Attack", L"Fire Pillar", L"Ultimate AOE",
					L"Divine Aura", L"Super Mario Star"
			});
			this->comboBox_CustomSkills2->Location = System::Drawing::Point(6, 45);
			this->comboBox_CustomSkills2->Name = L"comboBox_CustomSkills2";
			this->comboBox_CustomSkills2->Size = System::Drawing::Size(121, 21);
			this->comboBox_CustomSkills2->TabIndex = 8;
			this->comboBox_CustomSkills2->Text = L"Quicken";
			// 
			// textBox_CustomSkills2
			// 
			this->textBox_CustomSkills2->Location = System::Drawing::Point(133, 46);
			this->textBox_CustomSkills2->Name = L"textBox_CustomSkills2";
			this->textBox_CustomSkills2->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills2->TabIndex = 9;
			this->textBox_CustomSkills2->Text = L"Delay (Seconds)";
			// 
			// textBox_CustomSkills1
			// 
			this->textBox_CustomSkills1->Location = System::Drawing::Point(133, 20);
			this->textBox_CustomSkills1->Name = L"textBox_CustomSkills1";
			this->textBox_CustomSkills1->Size = System::Drawing::Size(63, 20);
			this->textBox_CustomSkills1->TabIndex = 6;
			this->textBox_CustomSkills1->Text = L"Delay (Seconds)";
			// 
			// checkBox_AdminBuffs
			// 
			this->checkBox_AdminBuffs->AutoSize = true;
			this->checkBox_AdminBuffs->Location = System::Drawing::Point(12, 239);
			this->checkBox_AdminBuffs->Name = L"checkBox_AdminBuffs";
			this->checkBox_AdminBuffs->Size = System::Drawing::Size(90, 17);
			this->checkBox_AdminBuffs->TabIndex = 1;
			this->checkBox_AdminBuffs->Text = L"Get GM Buffs";
			this->checkBox_AdminBuffs->UseVisualStyleBackColor = true;
			this->checkBox_AdminBuffs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox_AdminBuffs_CheckedChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(12, 6);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(460, 346);
			this->tabControl1->TabIndex = 8;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage1->Controls->Add(this->listView_PacketLog);
			this->tabPage1->Controls->Add(this->textBox_SendPacket);
			this->tabPage1->Controls->Add(this->button_SendPacket);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(452, 320);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Send";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->Controls->Add(this->button_RecvPacket);
			this->tabPage2->Controls->Add(this->textBox_RecvPacket);
			this->tabPage2->Controls->Add(this->listView_RecvPacketLog);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(452, 320);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Recv";
			// 
			// button_RecvPacket
			// 
			this->button_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_RecvPacket->Location = System::Drawing::Point(391, 294);
			this->button_RecvPacket->Name = L"button_RecvPacket";
			this->button_RecvPacket->Size = System::Drawing::Size(55, 22);
			this->button_RecvPacket->TabIndex = 7;
			this->button_RecvPacket->Text = L"Recv";
			this->button_RecvPacket->UseVisualStyleBackColor = true;
			this->button_RecvPacket->Click += gcnew System::EventHandler(this, &MainForm::button_RecvPacket_Click);
			// 
			// textBox_RecvPacket
			// 
			this->textBox_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_RecvPacket->Location = System::Drawing::Point(7, 295);
			this->textBox_RecvPacket->Name = L"textBox_RecvPacket";
			this->textBox_RecvPacket->Size = System::Drawing::Size(379, 20);
			this->textBox_RecvPacket->TabIndex = 3;
			this->textBox_RecvPacket->Text = L"Enter Packet...";
			// 
			// listView_RecvPacketLog
			// 
			this->listView_RecvPacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_RecvPacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader1,
					this->columnHeader2
			});
			this->listView_RecvPacketLog->ContextMenuStrip = this->contextMenuStrip_LogRecvPackets;
			this->listView_RecvPacketLog->FullRowSelect = true;
			this->listView_RecvPacketLog->GridLines = true;
			this->listView_RecvPacketLog->Location = System::Drawing::Point(6, 5);
			this->listView_RecvPacketLog->Name = L"listView_RecvPacketLog";
			this->listView_RecvPacketLog->Size = System::Drawing::Size(440, 284);
			this->listView_RecvPacketLog->TabIndex = 2;
			this->listView_RecvPacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_RecvPacketLog->View = System::Windows::Forms::View::Details;
			this->listView_RecvPacketLog->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listView_RecvPacketLog_MouseDoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Length";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Data";
			this->columnHeader2->Width = 854;
			// 
			// contextMenuStrip_LogRecvPackets
			// 
			this->contextMenuStrip_LogRecvPackets->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2
			});
			this->contextMenuStrip_LogRecvPackets->Name = L"contextMenuStrip_LogPackets";
			this->contextMenuStrip_LogRecvPackets->Size = System::Drawing::Size(150, 48);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(149, 22);
			this->toolStripMenuItem1->Text = L"Copy Selected";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(149, 22);
			this->toolStripMenuItem2->Text = L"Clear Log";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem2_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Controls->Add(this->button_EndScript);
			this->tabPage3->Controls->Add(this->button_RunScript);
			this->tabPage3->Controls->Add(this->textBox_ScriptText);
			this->tabPage3->ForeColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(452, 320);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"LUA Scripting";
			// 
			// button_EndScript
			// 
			this->button_EndScript->BackColor = System::Drawing::Color::Chocolate;
			this->button_EndScript->Location = System::Drawing::Point(343, 293);
			this->button_EndScript->Name = L"button_EndScript";
			this->button_EndScript->Size = System::Drawing::Size(104, 23);
			this->button_EndScript->TabIndex = 4;
			this->button_EndScript->Text = L"End Script";
			this->button_EndScript->UseVisualStyleBackColor = false;
			this->button_EndScript->Click += gcnew System::EventHandler(this, &MainForm::button_EndScript_Click);
			// 
			// button_RunScript
			// 
			this->button_RunScript->BackColor = System::Drawing::Color::YellowGreen;
			this->button_RunScript->Location = System::Drawing::Point(3, 293);
			this->button_RunScript->Name = L"button_RunScript";
			this->button_RunScript->Size = System::Drawing::Size(336, 23);
			this->button_RunScript->TabIndex = 3;
			this->button_RunScript->Text = L"Run Script";
			this->button_RunScript->UseVisualStyleBackColor = false;
			this->button_RunScript->Click += gcnew System::EventHandler(this, &MainForm::button_RunScript_Click);
			// 
			// textBox_ScriptText
			// 
			this->textBox_ScriptText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ScriptText->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_ScriptText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_ScriptText->Location = System::Drawing::Point(2, 0);
			this->textBox_ScriptText->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox_ScriptText->Multiline = true;
			this->textBox_ScriptText->Name = L"textBox_ScriptText";
			this->textBox_ScriptText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ScriptText->Size = System::Drawing::Size(448, 287);
			this->textBox_ScriptText->TabIndex = 2;
			this->textBox_ScriptText->Text = L"Enter script here (or Download Script)\r\n";
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage4->Controls->Add(this->groupBox1);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(452, 320);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Hacks";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 360);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox_Options);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"TOS Cross-Region PE (X.)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->contextMenuStrip_LogPackets->ResumeLayout(false);
			this->groupBox_Options->ResumeLayout(false);
			this->tabControl_PacketOptions->ResumeLayout(false);
			this->tabPage_SendTools->ResumeLayout(false);
			this->tabPage_SendTools->PerformLayout();
			this->tabPage_LogTools->ResumeLayout(false);
			this->tabPage_LogTools->PerformLayout();
			this->contextMenuStrip_PacketRules->ResumeLayout(false);
			this->tabPage_Misc->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_DungeonMultiplier))->EndInit();
			this->groupBox_AutoLogin->ResumeLayout(false);
			this->groupBox_AutoLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharID))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChannelID))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->contextMenuStrip_LogRecvPackets->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	public: System::Void UpdateGUI() {

		while (1)
		{
				Sleep(50);

				if (hiddenActorCoords != 0)
				{
					FLOAT CharZ = ReadPointer<FLOAT>(dwActorBase, Actor::dwZ);
					String^ ZString = gcnew String(String::Format("Z: {0}", CharZ));
					this->label_Z->Text = ZString;

					FLOAT CharY = *(FLOAT*)(hiddenActorCoords);
					String^ YString = gcnew String(String::Format("Y: {0}", CharY));
					this->label_Y->Text = YString;

					FLOAT CharX = ReadPointer<FLOAT>(dwActorBase, Actor::dwX);
					String^ XString = gcnew String(String::Format("X: {0}", CharX));
					this->label_X->Text = XString;
				}
		}


	}
	public: System::Void ProcessSendQueue() {

		while (this->checkBox_HookSend->Checked == TRUE) {

			if (SendPacketQueue.size() > 0) {

				PacketWriter* sendPacket = SendPacketQueue.front();

				wchar_t *pwDataText;
				wchar_t pwLengthText[10];

				CHAR* packetString = convertPacketFormatToString((unsigned char*)sendPacket->GetBuffer(), sendPacket->GetSize());

				DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString, -1, NULL, 0);
				_itow_s(sendPacket->GetSize(), pwLengthText, 10);

				pwDataText = new wchar_t[dwNum];
				MultiByteToWideChar(CP_UTF8, 0, packetString, -1, pwDataText, dwNum);

				String ^dataString = gcnew String(pwDataText);
				String ^lengthString = gcnew String(pwLengthText);

				array<String^>^ subItems = gcnew array<String^>(2);
				subItems[0] = gcnew String(lengthString);
				subItems[1] = gcnew String(dataString);

				ListViewItem^ itm = gcnew ListViewItem(subItems);
				this->listView_PacketLog->Items->Add(itm);

				SendPacketQueue.pop();
				delete sendPacket;
				delete[] pwDataText;
				free(packetString);
			}	
			else
				Thread::Sleep(300);
		}
	}
	public: System::Void ProcessRecvQueue() {

		while (this->checkBox_HookRecv->Checked == TRUE) {

			if (RecvPacketQueue.size() > 0) {

				PacketWriter* recvPacket = RecvPacketQueue.front();

				wchar_t *pwDataText;
				wchar_t pwLengthText[10];

				CHAR* packetString = convertPacketFormatToString((unsigned char*)recvPacket->GetBuffer(), recvPacket->GetSize());

				DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString, -1, NULL, 0);
				_itow_s(recvPacket->GetSize(), pwLengthText, 10);

				pwDataText = new wchar_t[dwNum];
				MultiByteToWideChar(CP_UTF8, 0, packetString, -1, pwDataText, dwNum);

				String ^dataString = gcnew String(pwDataText);
				String ^lengthString = gcnew String(pwLengthText);

				array<String^>^ subItems = gcnew array<String^>(2);
				subItems[0] = gcnew String(lengthString);
				subItems[1] = gcnew String(dataString);

				ListViewItem^ itm = gcnew ListViewItem(subItems);
				this->listView_RecvPacketLog->Items->Add(itm);

				RecvPacketQueue.pop();
				delete recvPacket;
				delete[] pwDataText;
				free(packetString);
			}
			else
				Thread::Sleep(300);
		}
	}
	private: System::Void button_SendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ Pocket = gcnew String(this->textBox_SendPacket->Text);
		char* string_packet = (char*)(void*)Marshal::StringToHGlobalAnsi(Pocket);
		Send(string_packet);
		//free(string_packet); todo, test after
	}

private: System::Void button_RecvPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ Pocket = gcnew String(this->textBox_RecvPacket->Text);
	char* string_packet = (char*)(void*)Marshal::StringToHGlobalAnsi(Pocket);
	Recv(string_packet);
	//free(string_packet); todo, test after

}
private: System::Void checkBox_HookSend_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_HookSend->Checked == TRUE)
	{
		WriteHookBytes(hkSend, SendHook, TRUE);
		SendLogThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::ProcessSendQueue));
		SendLogThread->Start();
	}
	else
	{
		WriteHookBytes(hkSend, SendHook, FALSE);
	}
}
private: System::Void listView_PacketLog_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_PacketLog->Items->Count; i++) {
		selectedItem = listView_PacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			this->textBox_SendPacket->Text = packetString;
		}
	}
}
private: System::Void clearLogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listView_PacketLog->Items->Clear();
}

private: System::Void copySendPacket() {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_PacketLog->Items->Count; i++) {
		selectedItem = listView_PacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			Clipboard::SetDataObject(packetString, true);
		}
	}
}

private: System::Void copyRecvPacket() {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_RecvPacketLog->Items->Count; i++) {
		selectedItem = listView_RecvPacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			Clipboard::SetDataObject(packetString, true);
		}
	}
}

private: System::Void copySelectedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::copySendPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}
private: System::Void removeRuleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	ListViewItem^ selectedItem;
	uint16_t opcode;

	for (int i = 0; i < listView_PacketRules->Items->Count; i++) {

		selectedItem = listView_PacketRules->Items[i];

		if (selectedItem->Selected == true) {

			if (selectedItem->SubItems[0]->Text->Equals("Ignore") == true)
			{
				opcode = Convert::ToInt16(selectedItem->SubItems[1]->Text, 16);

				//remove from ignore vector
				vector<uint16_t>::iterator it = IgnoredList.begin();

				while (it != IgnoredList.end()) {

					if ((short)opcode == (short)*it) {
						it = IgnoredList.erase(it);
					}
					else ++it;
				}
			}
			else if (selectedItem->SubItems[0]->Text->Equals("Block") == true) {

				opcode = Convert::ToInt16(selectedItem->SubItems[1]->Text, 16);

				//remove from ignore vector
				vector<uint16_t>::iterator it = BlockedList.begin();

				while (it != BlockedList.end()) {

					if ((short)opcode == (short)*it) {
						it = BlockedList.erase(it);
					}
					else ++it;
				}
			}
			else if (selectedItem->SubItems[0]->Text->Equals("Modify") == true) {

				char* packet = (char*)(void*)Marshal::StringToHGlobalAnsi(selectedItem->SubItems[1]->Text);

				packet[5] = '\0'; //mem leak LOL WHO CARES

				unsigned char* _packet = convertStringToPacketFormat(packet);

				memcpy(&opcode, (void*)&_packet[0], sizeof(uint16_t));

				opcode = (opcode << 8) |          // left-shift always fills with zeros
					((opcode >> 8) & 0x00ff);

				vector<ModifyRule*>::iterator it = ModifyList.begin();

				while (it != ModifyList.end()) {

					if ((uint16_t)(*it)->opcode == (uint16_t)opcode) {
						it = ModifyList.erase(it);
					}
					else ++it;
				}

				free(packet);

			}
			listView_PacketRules->Items->Remove(listView_PacketRules->Items[i]);
		}
	}
}

private: void SpamPacket() {

	String^ delayTime = gcnew String(this->textBox_SpamPacketDelay->Text);
	char* ascii_delay = (char*)(void*)Marshal::StringToHGlobalAnsi(delayTime);
	int sleepTime = atoi(ascii_delay);

	while (this->checkBox_SpamPacket->Checked == TRUE) {
		String^ packetToSend = textBox_SendPacket->Text;
		char* ascii_multi_packets = (char*)(void*)Marshal::StringToHGlobalAnsi(packetToSend);
		Send(ascii_multi_packets);
		Sleep(sleepTime);
	}

}

private: System::Void checkBox_SpamPacket_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->checkBox_SpamPacket->Checked == TRUE) {
		SpamPacketThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::SpamPacket));
		SpamPacketThread->Start();
	}
	else {
		SpamPacketThread->Abort();
	}
}
private: System::Void button_IgnorePacket_Click(System::Object^  sender, System::EventArgs^  e) {

	IgnoredList.push_back(Convert::ToInt16(this->textBox_PacketRule1->Text->Replace(" ", String::Empty), 16));

	array<String^>^ subItems = gcnew array<String^>(2);
	subItems[0] = gcnew String("Ignore");
	subItems[1] = gcnew String(this->textBox_PacketRule1->Text->Replace(" ", String::Empty));

	ListViewItem^ itm = gcnew ListViewItem(subItems);
	this->listView_PacketRules->Items->Add(itm);
}
private: System::Void button_BlockPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	BlockedList.push_back(Convert::ToInt16(this->textBox_PacketRule1->Text->Replace(" ", String::Empty), 16));

	array<String^>^ subItems = gcnew array<String^>(2);
	subItems[0] = gcnew String("Block");
	subItems[1] = gcnew String(this->textBox_PacketRule1->Text->Replace(" ", String::Empty));

	ListViewItem^ itm = gcnew ListViewItem(subItems);
	this->listView_PacketRules->Items->Add(itm);
}
private: System::Void button_ModifyPacket_Click(System::Object^  sender, System::EventArgs^  e) {
	
	ModifyRule* mod = new ModifyRule;

	char* pattern = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_PacketRule1->Text);
	mod->pattern = new char[strlen(pattern) + 1];
	strcpy(mod->pattern, pattern);

	char* _packetToSend = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_PacketRule2->Text);

	if (strcmp(pattern, _packetToSend) == 0) {
		MessageBoxA(0, "Can't modify, replacement matches pattern", 0, 0);
		delete mod;
		return;
	}

	mod->replacement = convertStringToPacketFormat(_packetToSend);

	memcpy(&mod->opcode, (void*)&mod->replacement[0], sizeof(uint16_t));

	mod->opcode = (mod->opcode << 8) |          // left-shift always fills with zeros
		((mod->opcode >> 8) & 0x00ff);

	mod->direction = PacketDirection::out;

	ModifyList.push_back(mod);

	array<String^>^ subItems = gcnew array<String^>(2);
	subItems[0] = gcnew String("Modify");
	subItems[1] = gcnew String(this->textBox_PacketRule1->Text);

	ListViewItem^ itm = gcnew ListViewItem(subItems);
	this->listView_PacketRules->Items->Add(itm);

}

private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//init_lua(); //Startup LUA
	InitializeSkillMap();
}

private: System::Void checkBox_HookRecv_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_HookRecv->Checked == TRUE)
	{
		WriteHookBytes(hkRecv, RecvHook, TRUE);
		RecvLogThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::ProcessRecvQueue));
		RecvLogThread->Start();
	}
	else
	{
		WriteHookBytes(hkRecv, RecvHook, FALSE);
	}
}
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::copyRecvPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listView_RecvPacketLog->Items->Clear();
}
private: System::Void listView_RecvPacketLog_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_RecvPacketLog->Items->Count; i++) {
		selectedItem = listView_RecvPacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			this->textBox_SendPacket->Text = packetString;
		}
	}
}

private: System::Void checkBox_AdminBuffs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_AdminBuffs->Checked == TRUE)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&CastAdminBuffs, 0, 0, 0);
	}
	else
	{

	}
}
private: System::Void button_RunScript_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button_EndScript_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void checkBox_CustomSkill1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->checkBox_CustomSkill1->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills1->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;
		
		String^ Delay = textBox_CustomSkills1->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill1 = SkillID;
				CustomSkillThread1 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill1, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread1, 0);
		CustomSkill1 = 0;
	}
}
private: System::Void checkBox_CustomSkill2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill2->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills2->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills2->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill2 = SkillID;
				CustomSkillThread2 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill2, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		CustomSkill2 = 0;
		TerminateThread(CustomSkillThread2, 0);
	}
}
private: System::Void checkBox_CustomSkill3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill3->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills3->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills3->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill3 = SkillID;
				CustomSkillThread3 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill3, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread3, 0);
		CustomSkill3 = 0;
	}
}
private: System::Void checkBox_CustomSkill4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill4->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills4->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills4->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill4 = SkillID;
				CustomSkillThread3 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill4, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread4, 0);
		CustomSkill4 = 0;
	}
}
private: System::Void checkBox_CustomSkill5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill5->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills5->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills5->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill5 = SkillID;
				CustomSkillThread5 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill5, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread5, 0);
		CustomSkill5 = 0;
	}
}
private: System::Void checkBox_CustomSkill6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill6->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills6->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills6->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill6 = SkillID;
				CustomSkillThread6 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill6, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread6, 0);
		CustomSkill6 = 0;
	}
}
private: System::Void checkBox_CustomSkill7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CustomSkill7->Checked == TRUE)
	{
		String^ Skill = comboBox_CustomSkills7->Text;
		char* asciiSkill = (char*)(void*)Marshal::StringToHGlobalAnsi(Skill);
		string strSkill = string(asciiSkill);
		uint32_t SkillID = 0;

		String^ Delay = textBox_CustomSkills7->Text;
		char* asciiDelay = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
		int delay = atoi(asciiDelay);
		printf("%d\n", delay);
		int* ptr_delay = new int();
		*ptr_delay = delay;

		for (auto it = SkillMap.begin(); it != SkillMap.end(); ++it)
		{
			if (it->first == strSkill)
			{
				SkillID = it->second;
				CustomSkill7 = SkillID;
				CustomSkillThread5 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&UseCustomSkill7, ptr_delay, 0, 0);
			}
		}
	}
	else
	{
		TerminateThread(CustomSkillThread7, 0);
		CustomSkill7 = 0;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox_AutoLogin_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_AutoLogin->Checked == TRUE)
	{
		isAutoLogin = TRUE;
		channelID = (short)numericUpDown_ChannelID->Value;
		charIndex = (byte)numericUpDown_CharID->Value;
	}
	else
	{
		isAutoLogin = FALSE;
	}
}
private: System::Void checkBox_SilverFarmBot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_SilverFarmBot->Checked == TRUE)
	{
		DungeonMultiplier = (byte)numericUpDown_DungeonMultiplier->Value;
		isBottingSilver = TRUE;
		BotThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Bot360Dungeon, 0, 0, 0);
	}
	else
	{
		isBottingSilver = FALSE;
		TerminateThread(BotThread, 0);
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ Delay = textBox9->Text;
	char* ascii = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
	FLOAT X = atof(ascii);

	Delay = textBox10->Text;
	ascii = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
	FLOAT Y = atof(ascii);

	Delay = textBox11->Text;
	ascii = (char*)(void*)Marshal::StringToHGlobalAnsi(Delay);
	FLOAT Z = atof(ascii);

    byte Packet[] = "\x54\x0e\x54\x0E\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
	memcpy(&Packet[14], &X, sizeof(char)* 4);
	memcpy(&Packet[18], &Y, sizeof(char)* 4);
	memcpy(&Packet[22], &Z, sizeof(char)* 4);

	SendPacket(Packet, 26);
}
private: System::Void button_SummonVelcoffer_Click(System::Object^  sender, System::EventArgs^  e) {

		PacketWriter* p = new PacketWriter();
		p->Write<SHORT>(0x0C6B); //opcode
		p->Write<UINT64>(0);
		p->Write<BYTE>(0);
		p->Write<SHORT>(62754);
		p->Write<UINT64>(0);
		p->Write<SHORT>(0);
		SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
		delete p;
}
private: System::Void button_SummonFireSpirit_Click(System::Object^  sender, System::EventArgs^  e) {
	
	PacketWriter* p = new PacketWriter();
	p->Write<SHORT>(0x0C6B); //opcode
	p->Write<UINT64>(0);
	p->Write<BYTE>(0);
	p->Write<SHORT>(20707);
	p->Write<UINT64>(0);
	p->Write<SHORT>(0);
	SendPacket((LPBYTE)p->GetBuffer(), p->GetSize());
	delete p;

}
};
}

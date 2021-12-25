#include "MainForm.h"

using namespace TOSPE;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew MainForm());
	Sleep(1000);

	return 0;
}
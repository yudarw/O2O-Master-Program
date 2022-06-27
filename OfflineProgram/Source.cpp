#include "MainForm.h"
#include "CoppeliaForm1.h"
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

int main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::Run(gcnew MainForm());
	//System::Windows::Forms::Application::Run(gcnew CoppeliaForm());
	return 0;
}
#include "MyForm.h"
#include "PositionInputForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace OfflineProgram;

void MyForm::btn_show_position_input() {
	PositionInputForm ^ form = gcnew PositionInputForm;
	form->Show();
}
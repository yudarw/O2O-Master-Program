#include "MyForm.h"
#include "PositionInputForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace OfflineProgram;


// On timer program - Update UI -
void MyForm::on_timer() {
		
}



void MyForm::btn_show_position_input() {
	PositionInputForm ^ form = gcnew PositionInputForm;
	form->Show();
}
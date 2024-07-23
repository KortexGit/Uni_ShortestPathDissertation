#include "View.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MVCLatest::View view;

	Application::Run(% view);
	return 0;
}

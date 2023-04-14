#include "MyForm.h"

using namespace FARELCLRv02;

[STAThread]
void Main(array<System::String^>^ args)
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}

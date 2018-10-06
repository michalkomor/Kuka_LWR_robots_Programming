// FRI_GuiApp.cpp : main project file.

#include "stdafx.h"
//#pragma unmanaged
// Dirty Trick, um der Microsoft Managed-unmanaged Code Problematik zu entgehen
#include "FRIRemote.h"
#include "FRIUdp.cpp"
#include "FRIRemote.cpp"

//#pragma managed
namespace FRI_GuiApp {
	// Workaround unmanaged code
			// filled by background worker ....
		tFriMsrData msr;
		tFriCmdData cmd;

	bool flagDoJntSpeed = false;
	float jntSpeed[LBR_MNJ];
	float jntLastIncrement[LBR_MNJ];
};

#include "Form1.h"

using namespace FRI_GuiApp;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Set priority
	System::Threading::Thread::CurrentThread->Priority=System::Threading::ThreadPriority::AboveNormal;
	//System.Diagnostics.Process.GetCurrentProcess().PriorityClass = System.Diagnostics.ProcessPriorityClass.High;

	System::Diagnostics::Process::GetCurrentProcess()->PriorityClass = System::Diagnostics::ProcessPriorityClass::RealTime;
	//System::Diagnostics::Process::GetCurrentProcess()->BasePriority  = System::Diagnostics::ProcessPriorityClass::RealTime;


	FRI_GuiApp::Form1^ theMainForm = gcnew Form1();
	// Create the main window and run it
	Application::Run(theMainForm);
	return 0;
}

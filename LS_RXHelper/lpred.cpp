#include "stdafx.h"

PSDK_CONTEXT SDK_CONTEXT_GLOBAL;

//
// Colors in the BGRA format.
//

SDKCOLOR _g_ColorWhite = { 255, 255, 255, 255 };
SDKCOLOR _g_ColorYellow = { 0, 255, 255, 255 };
SDKCOLOR _g_ColorGreen = { 0, 255, 0, 255 };
SDKCOLOR _g_ColorRed = { 0, 0, 255, 255 };
SDKCOLOR _g_ColorPurple = { 128, 0, 128, 255 };

 struct lpredOptions
{

	 bool bPred;

}m_Options;


BOOL 
WINAPI 
DllMain(
	_In_ HINSTANCE hinstDLL, 
	_In_ DWORD fdwReason, 
	_In_ LPVOID lpvReserved
)

{
	UNREFERENCED_PARAMETER(hinstDLL);

	//
	// We're only interested when the DLL attaches to the process.
	//
	if (fdwReason != DLL_PROCESS_ATTACH)
		return TRUE;

	//
	// This macro extracts the pointer to the SDK context from the lpvReserved
	// parameter.
	//
	SDK_EXTRACT_CONTEXT(lpvReserved);
	if (!SDK_CONTEXT_GLOBAL)
		return FALSE;

	//
	// Every module loaded by Rift should have a call to SdkNotifyLoadedModule
	// as soon as possible to ensure that other SDK API can be called.
	//
	if (!SDKSTATUS_SUCCESS(SdkNotifyLoadedModule("lpred", SDK_VERSION)))
	{
		//
		// This routine will fail if a module of the same name is already
		// loaded or if there's a mismatch with the target SDK version.
		//
		return FALSE;
	}
	//
	// initialize entitymanager
	//
	EntityManager::Initialize();


	//
	// When the overlay is being drawn (e.g. hack menu is up), invoke
	// our function.
	//
	SdkRegisterOverlayScene(DrawOverlayScene, NULL);

	//
	// Each frame, the SDK will call into this function where we can 
	// add draw additional visuals before it's dispatched to the GPU
	// to render.
	//
	SdkRegisterGameScene(DrawGameScene, NULL);

	//
	// The base 'game frame' sits below our extra visuals (the 'game
	// scene'). The 'overlay scene' sits atop both of these, but is
	// only visible when the end user presses the required hotkey.
	//
	return TRUE;
}


void __cdecl DrawOverlayScene(_In_ void* UserData)
{
	UNREFERENCED_PARAMETER(UserData);
	// menu 
	SdkUiCheckbox("Test", &m_Options.bPred, NULL);

}

void __cdecl DrawGameScene( _In_ void* UserData)
{
	UNREFERENCED_PARAMETER(UserData);
	if (!m_Options.bPred)
		return;

	//
	// Update entitymanager
	//

	EntityManager::Update();

	
	for (auto object : EntityManager::GetEnemyMinions())
	{
		if (EntityManager::GetLocalPlayer().GetPosition().Distance(object.GetPosition()) > 1000)
			continue;

		
		SdkDrawLine(&object.GetPosition(), &EntityManager::GetLocalPlayer().GetPosition(), 5, &_g_ColorRed, NULL);
	}

}

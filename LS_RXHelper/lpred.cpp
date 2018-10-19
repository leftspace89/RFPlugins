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

	 bool showwindow;
	 bool bPred;

}m_Options;

 EEvent<void, int, int>testevent_args;
 EEvent<void>testevent_noargs;
 void OnTestEventArgs(int arg1, int arg2)
 {
	 printf("Args : %d,%d\n", arg1, arg2);
 }
 void OnTestEvent_NO_Args()
 {
	 printf("NO args\n");
 }

 int eventexample(void)
 {
	 bindEEvent(testevent_args, OnTestEventArgs, 1, 2);
	 int eventid2 = bindEEvent(testevent_noargs, OnTestEvent_NO_Args);


	 notifyEEvent(testevent_args, 1, 2); // with infinite args
	 notifyEEvent(testevent_noargs); // no args

	 if (GetAsyncKeyState(VK_SPACE))
		 unbindEEvent(testevent_noargs, eventid2);
	 return 0;
 }


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
	eventexample();


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

	bool ObjectExpanded = false;
	SdkUiBeginTree("Test Helper",&ObjectExpanded);
	if (ObjectExpanded)
	{
		SdkUiCheckbox("Test", &m_Options.bPred, NULL);
		SdkUiEndTree();
	}

	
}


double CalcAttackTime()
{
	typedef float(__cdecl* fnGetAttackDelay)(void* pObj, int index);
	fnGetAttackDelay stGet = reinterpret_cast<fnGetAttackDelay>((DWORD)(GetModuleHandleA(0)) + 0x64C5C0); // 1.  57 8B 7C 24 08 8B 87 ? ? ? ? 8D 8F ? ? ? ?
	float delay = stGet(EntityManager::GetLocalPlayer().GetObjectPTR(), 64); 
	float ChampionAttackSpeed = 1.0f / delay; // Like 2.50 
	float Div = EntityManager::GetLocalPlayer().GetAttackSpeed(); // like 4.12
	float BaseMult = ChampionAttackSpeed / Div; //Like 0.600 
	return BaseMult;
}
double CalcWindup()
{
	typedef float(__cdecl* fnGetAttackDelay)(void* pObj, int index);
	fnGetAttackDelay stGet = reinterpret_cast<fnGetAttackDelay>((DWORD)(GetModuleHandleA(0)) + 0x64C440); // 83 ec ? 53 8b 5c ? ? 8b cb 56 ---- 2.  57 8B 7C 24 08 8B 87 ? ? ? ? 8D 8F ? ? ? ?
	auto delay = stGet(EntityManager::GetLocalPlayer().GetObjectPTR(), 1);
	float pDelay = delay * 2 ;
	SdkUiConsoleWrite("pDelay : %f delay : %f from rift attackspeed : %f", pDelay, delay, EntityManager::GetLocalPlayer().GetAttackSpeed());

	return pDelay;
}


void __cdecl DrawGameScene( _In_ void* UserData)
{
	UNREFERENCED_PARAMETER(UserData);


	//
	// Update entitymanager
	//

    // 
	// event examples
	// 


	EntityManager::Update();
	if (!m_Options.bPred)
		return;
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		auto windup = CalcWindup();
		auto attdelay = CalcAttackTime();
		//SdkUiConsoleWrite("windup : %f attack delay : %f", windup,attdelay);
	}
	

	//"League of Legends.exe"+64C5C0
	//"League of Legends.exe"+64C440
	//"League of Legends.exe"+62CFE0
	//"League of Legends.exe"+2C3C60
	//"League of Legends.exe"+646120
	/*
	BUFF EXAMPLE
	DRAW BUFF NAMES OF TARGET
	*/
	
	auto EnemyHeroes = EntityManager::GetEnemyHeroes();
	for (size_t i = 0; i < EnemyHeroes.size(); i++)
	{
		auto hero = EnemyHeroes[i];
		if (!hero.isAlive() || !hero.isVisible())
			continue;

		auto net = hero.GetNeutralKills();

		auto buffs = hero.GetBuffs();
		
		for (size_t i = 0; i < buffs.size(); i++)
		{
			auto buff = buffs[i];
			if (!buff.IsValid())
				continue;

			auto Pos = hero.GetPosition();
			Pos.z += (i * 15);

			SdkDrawText(&Pos, NULL, buff.Name, "Arial", &_g_ColorWhite, 18, 5, 0, false);

			
		}
	}
	



	//for (auto object : EntityManager::GetEnemyMinions())
	//{
	//	if (EntityManager::GetLocalPlayer().GetPosition().Distance(object.GetPosition()) > 1000)
	//		continue;
	//	
	//}

}


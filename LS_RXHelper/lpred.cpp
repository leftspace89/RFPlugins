#include "stdafx.h"
#include "AntiAFK.h"

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
	 bool bAntiAFK;
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
	
	if (fdwReason != DLL_PROCESS_ATTACH)
		return TRUE;

	SDK_EXTRACT_CONTEXT(lpvReserved);
	if (!SDK_CONTEXT_GLOBAL)
		return FALSE;

	if (!SDKSTATUS_SUCCESS(SdkNotifyLoadedModule("lpred", SDK_VERSION))) {
		return FALSE;
	}


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



	return TRUE;
}

void __cdecl AntiAFKTick(void* UserData) {
	UNREFERENCED_PARAMETER(UserData);		
	if (!EntityManager::initialized)
		return;
	if (m_Options.bAntiAFK) {
		AntiAFK::Execute();
	}
}



void __cdecl DrawOverlayScene(_In_ void* UserData)
{
	UNREFERENCED_PARAMETER(UserData);


	bool ObjectExpanded = false;
	SdkUiBeginTree("Test Helper",&ObjectExpanded);
	if (ObjectExpanded)
	{
		SdkUiCheckbox("Test", &m_Options.bPred, NULL);
		SdkUiCheckbox("AntiAFK", &m_Options.bAntiAFK, NULL);
		SdkUiEndTree();
	}

	
}


void __cdecl DrawGameScene( _In_ void* UserData)
{
	UNREFERENCED_PARAMETER(UserData);


	//
	// Update entitymanager
	//

	EntityManager::Update();
	AntiAFKTick(UserData);

	if (!m_Options.bPred)
		return;
	


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
	
	auto AllyHeroes = EntityManager::GetAllyHeroes();
	for (size_t i = 0; i < AllyHeroes.size(); i++)
	{
		auto hero = AllyHeroes[i];
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


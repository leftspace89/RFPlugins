#pragma once
#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

class EntityManager
{
public:
	
	static bool
		__cdecl
		AwObjectLoop(
			_In_ void* Object,
			_In_opt_ void* UserData
		);
	
	//
	// CALLED AT DLLMAIN
	//
	static void Initialize();
	static void Clear();
	//
	// CALLED EVERY FRAME
	//
	static void Update();

	static std::vector<AIHeroClient> GetEnemyHeroes();
	static std::vector<AIHeroClient> GetAllyHeroes();
	static std::vector<AIMinionClient> GetAllyMinions();
	static std::vector<AIMinionClient> GetEnemyMinions();
	static std::vector<AITurretClient> GetAllyTurrets();
	static std::vector<AITurretClient> GetEnemyTurrets();
	static std::vector<AIMinionClient> GetJungleMonsters();

	static AIHeroClient GetLocalPlayer();
	static bool initialized;
private:
	static std::vector<AIMinionClient>m_AllyMinions;
	static std::vector<AIMinionClient>m_EnemyMinions;

	static std::vector<AITurretClient>m_EnemyTurrets;
	static std::vector<AITurretClient>m_AllyTurrets;

	static std::vector<AIHeroClient>m_EnemyHeroes;
	static std::vector<AIHeroClient>m_AllyHeroes;

	static std::vector<AIMinionClient>m_JungleMonsters;

	static AIHeroClient LocalPlayer;
	
};


#endif
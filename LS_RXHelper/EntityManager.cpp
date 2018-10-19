#include "stdafx.h"

void*g_LocalPlayer;

AIHeroClient EntityManager::LocalPlayer;
std::vector<AIMinionClient> EntityManager::m_AllyMinions;
std::vector<AIMinionClient> EntityManager::m_EnemyMinions;

std::vector<AITurretClient> EntityManager::m_EnemyTurrets;
std::vector<AITurretClient> EntityManager::m_AllyTurrets;

std::vector<AIHeroClient> EntityManager::m_EnemyHeroes;
std::vector<AIHeroClient> EntityManager::m_AllyHeroes;

std::vector<AIMinionClient> EntityManager::m_JungleMonsters;
bool EntityManager::initialized;
//
// CALLED EVERY FRAME
//


//
// CALLED AT DLLMAIN
//

bool EntityManager::AwObjectLoop(void * Object, void * UserData)
{
	UNREFERENCED_PARAMETER(UserData);

	//
	// For Hero
	//
	if (SDKSTATUS_SUCCESS(SdkIsObjectHero(Object)))
	{
		AIHeroClient tmpObject(Object);

		if (tmpObject.isEnemy())
		{
			m_EnemyHeroes.push_back(tmpObject);
			return true;
		}
		else
		{
			m_AllyHeroes.push_back(tmpObject);
			return true;
		}
	}

	//
	// For Minions
	//
	if (SDKSTATUS_SUCCESS(SdkIsObjectMinion(Object)))
	{
		int miniontype = 0;
		SdkGetMinionType(Object, &miniontype);
		AIMinionClient tmpObject(Object);
		if (miniontype == MINION_TYPE_JUNGLE_MONSTER)
		{
			m_JungleMonsters.push_back(tmpObject);
			return true;
		}
		else if (miniontype == MINION_TYPE_LANE_MINION)
		{

			if (tmpObject.isEnemy())
			{
				m_EnemyMinions.push_back(tmpObject);
				return true;
			}
			else
			{
				m_AllyMinions.push_back(tmpObject);
				return true;
			}
		}
	}

	//
	// For Turrets
	//
	if (SDKSTATUS_SUCCESS(SdkIsObjectTurret(Object)))
	{
		AITurretClient tmpObject(Object);

		if (tmpObject.isEnemy())
		{
			m_EnemyTurrets.push_back(tmpObject);
			return true;
		}
		else
		{
			m_AllyTurrets.push_back(tmpObject);
			return true;
		}
	}

	return true;
}

 void EntityManager::Initialize()
{
	SdkGetLocalPlayer(&g_LocalPlayer);

	if (g_LocalPlayer)
	{
		LocalPlayer = AIHeroClient(g_LocalPlayer);
	}
}

void EntityManager::Clear()
{

	m_AllyMinions.clear();
	m_EnemyMinions.clear();
	m_EnemyTurrets.clear();
	m_AllyTurrets.clear();
	m_EnemyHeroes.clear();
	m_AllyHeroes.clear();
	m_JungleMonsters.clear();

}
 void EntityManager::Update()
{
	initialized = true;
	static auto tick = GetTickCount();
	if (GetTickCount() - tick > 100)
	{
		Clear(); // clear every obj
		SdkEnumGameObjects(AwObjectLoop, NULL);
	 // update again
		tick = GetTickCount();
	}

}

 std::vector<AIHeroClient> EntityManager::GetEnemyHeroes()
{
	return m_EnemyHeroes;
}

 std::vector<AIHeroClient> EntityManager::GetAllyHeroes()
{
	return m_AllyHeroes;
}

 std::vector<AIMinionClient> EntityManager::GetAllyMinions()
{
	return m_AllyMinions;
}

 std::vector<AIMinionClient> EntityManager::GetEnemyMinions()
{
	return m_EnemyMinions;
}

 std::vector<AITurretClient> EntityManager::GetAllyTurrets()
{
	return m_AllyTurrets;
}

 std::vector<AITurretClient> EntityManager::GetEnemyTurrets()
{
	return m_EnemyTurrets;
}

 std::vector<AIMinionClient> EntityManager::GetJungleMonsters()
{
	return m_JungleMonsters;
}

AIHeroClient EntityManager::GetLocalPlayer()
{
	return LocalPlayer;
}

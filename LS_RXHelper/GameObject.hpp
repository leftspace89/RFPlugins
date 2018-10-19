#pragma once

class GameObject
{
public:
	GameObject()
	{
	};
	GameObject(void*obj) : Object(obj) {};
	~GameObject(){
		Object = NULL;
	};

	MAKE_GET(Position, SDKVECTOR, SdkGetObjectPosition)
	MAKE_GET(Orientation, SDKVECTOR, SdkGetObjectOrientation)
	MAKE_GET(BBox, SDKBOX, SdkGetObjectBoundingBox)
	MAKE_GET(TeamID, int, SdkGetObjectTeamID)
	MAKE_GET(TypeFlags, int, SdkGetObjectTypeFlags)
	MAKE_RAW(isZombie, bool, SdkIsObjectZombie)
	
	bool isEnemy()
	{
		LSFail
		int tmpID;
		CHECKFAIL(SdkGetObjectTeamID(g_LocalPlayer, &tmpID));

		return tmpID != GetTeamID();
	}
	bool isAlly()
	{
		LSFail
		int tmpID;
		CHECKFAIL(SdkGetObjectTeamID(g_LocalPlayer, &tmpID));
		return tmpID == GetTeamID();
	}
	bool isAlive()
	{
		LSFail
		bool tmpb;
		CHECKFAIL(SdkIsObjectDead(Object, &tmpb));
		return !tmpb;
	}
	std::string GetName()
	{
		LSFail
		const char* Name = NULL;
		CHECKFAIL(SdkGetObjectName(Object, &Name));
		return std::string(Name);
	}
	const char* GetRawName()
	{
		LSFail
		const char* Name = NULL;
		CHECKFAIL(SdkGetObjectName(Object, &Name));
		return Name;
	}
	void* GetObjectPTR()
	{
		LSFail
		return Object;
	}
	void*Object; // object ptr
private:
	//std::shared_ptr<AttackableUnit> Unit;
	//std::shared_ptr<AIBaseClient> AI;
	//std::shared_ptr<AIHeroClient> Hero;
	//std::shared_ptr<AIMinionClient> Minion;
	//std::shared_ptr<AITurretClient> Turret;
	
};


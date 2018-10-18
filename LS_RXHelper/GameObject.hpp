#pragma once
#define LSFail assert(Object !=NULL);
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

	SDKVECTOR GetPosition()
	{
		LSFail
		SDKVECTOR Position;
		SdkGetObjectPosition(Object, &Position);
		return Position;
	}
	SDKVECTOR GetOrientation()
	{
		LSFail
		SDKVECTOR tmp1;
		SdkGetObjectOrientation(Object, &tmp1);
		return tmp1;
	}
	SDKBOX GetBBox()
	{
		LSFail
		SDKBOX tmp1;
		SdkGetObjectBoundingBox(Object, &tmp1);
		return tmp1;
	}
	int GetTeamID()
	{
		LSFail
		int tmpID;
		SdkGetObjectTeamID(Object, &tmpID);
		return tmpID;
	}
	int GetTypeFlags()
	{
		int tmp1;
		SdkGetObjectTypeFlags(Object, &tmp1);
		return tmp1;
	}
	bool isZombie()
	{
		LSFail
		bool tmp1;
		SdkIsObjectZombie(Object, &tmp1);
		return tmp1;
	}
	bool isEnemy()
	{
		LSFail
		int tmpID;
		SdkGetObjectTeamID(g_LocalPlayer, &tmpID);
		return tmpID != GetTeamID();
	}
	bool isAlly()
	{
		LSFail
		int tmpID;
		SdkGetObjectTeamID(g_LocalPlayer, &tmpID);
		return tmpID == GetTeamID();
	}
	bool isAlive()
	{
		LSFail
		bool tmpb;
		SdkIsObjectDead(Object, &tmpb);
		return !tmpb;
	}
	std::string GetName()
	{
		LSFail
		const char* Name = NULL;
		SdkGetObjectName(Object, &Name);
		return std::string(Name);
	}
	const char* GetRawName()
	{
		LSFail
		const char* Name = NULL;
		SdkGetObjectName(Object, &Name);
		return Name;
	}
	void* GetObjectPTR()
	{
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


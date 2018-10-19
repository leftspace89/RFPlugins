#pragma once
class AIHeroClient : public AIBaseClient
{
public:
	
	AIHeroClient(void* obj) : AIBaseClient(obj)
	{
	};
	AIHeroClient()
	{
	};
	~AIHeroClient()
	{
	};
	


	int GetLevel() {
		int Level = NULL;
		CHECKFAIL(SdkGetHeroExperience(Object, NULL, &Level));
		return Level;
	}
	float GetExperience() {
		float Exp = NULL;
		CHECKFAIL(SdkGetHeroExperience(Object, &Exp, NULL));
		return Exp;
	}

	
	MAKE_GET(NeutralKills, int,SdkGetHeroNeutralKills)

private:

};


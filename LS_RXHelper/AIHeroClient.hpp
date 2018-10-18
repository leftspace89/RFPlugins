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
	

	int GetLevel()
	{
		LSFail
		int tmp1;
		SdkGetHeroExperience(Object,NULL, &tmp1);
		return tmp1;
	}
	float GetExperience()
	{
		LSFail
		float tmp1;
		SdkGetHeroExperience(Object, &tmp1, NULL);
		return tmp1;
	}
	MAKE_GET(NeutralKills, int,SdkGetHeroNeutralKills)

private:

};


#pragma once
class AttackableUnit : public GameObject
{
public:
	AttackableUnit()
	{
	};
	AttackableUnit(void* obj) : GameObject(obj) {
	};
	~AttackableUnit()
	{
	};

	MAKE_RAW(isVisible, bool, SdkIsUnitVisible)
	MAKE_RAW(isMouseOver,bool, SdkGetUnitIsMouseOver)
	MAKE_GET(DeathTime,float, SdkGetUnitDeathTime)
	MAKE_GET(GetHealth, SDK_HEALTH, SdkGetUnitHealth)


	SDK_ABILITY_RESOURCE GetAbilitySlots(unsigned char index)
	{
		SDK_ABILITY_RESOURCE tmp1;
		CHECKFAIL(SdkGetUnitAbilityResource(Object, index, &tmp1));
		return tmp1;
	}
	 
	struct BuffInstance
	{
		const char* Name;
		unsigned char Type;
		float StartTime;
		float EndTime;
		
		int Count;

		// TODO: CHECKTHAT SHIIIIIIIIIIIT REXY
		bool IsValid()
		{
			float time;
			SdkGetGameTime(&time);
			return time < EndTime;
		}
	};

private:


};
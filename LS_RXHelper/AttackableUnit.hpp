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

	bool isVisible()
	{
		LSFail
			bool tmp1;
		SdkIsUnitVisible(Object, &tmp1);
		return tmp1;
	}
	bool isMouseOver()
	{
		bool tmp1;
		SdkGetUnitIsMouseOver(Object, &tmp1);
		return tmp1;
	}
	float GetDeathTime()
	{
		LSFail
		float tmp1;
		SdkGetUnitDeathTime(Object, &tmp1);
		return tmp1;
	}
	SDK_HEALTH GetHealth()
	{
		LSFail
		SDK_HEALTH tmp1;
		SdkGetUnitHealth(Object, &tmp1);
		return tmp1;
	}
	SDK_ABILITY_RESOURCE GetAbilitySlots(int index)
	{
		LSFail
		SDK_ABILITY_RESOURCE tmp1;
		SdkGetUnitAbilityResource(Object, index, &tmp1);
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
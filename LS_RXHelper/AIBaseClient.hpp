#pragma once
class AIBaseClient : public AttackableUnit
{
public:
	AIBaseClient()
	{
	};
	AIBaseClient(void* obj) : AttackableUnit(obj) {
	};
	~AIBaseClient()
	{
	};

	MAKE_GET(SkinID, int, SdkGetAISkinID)
	MAKE_RAW(PlayerControlled, bool, SdkIsAIPlayerControlled)
	MAKE_RAW(CanAttack, bool, SdkCanAIAttack)
	MAKE_RAW(CanCrit, bool, SdkCanAICrit)
	MAKE_RAW(CanCast, bool, SdkCanAICast)
	MAKE_RAW(CanMove, bool, SdkCanAIMove)
	MAKE_RAW(Stealthed, bool, SdkIsAIStealthed)
	MAKE_RAW(Taunted, bool, SdkIsAITaunted)
	MAKE_RAW(Feared, bool,SdkIsAIFeared )
	MAKE_RAW(Fleeing, bool, SdkIsAIFleeing)
	MAKE_RAW(Suppressed, bool, SdkIsAISuppressed)
	MAKE_RAW(Sleeping, bool,SdkIsAISleeping )
	MAKE_RAW(NearSighted, bool,SdkIsAINearSighted )
	MAKE_RAW(Ghosted, bool, SdkIsAIGhosted)
	MAKE_RAW(Charmed, bool,SdkIsAICharmed )
	MAKE_RAW(Slowed, bool,SdkIsAISlowed )
	MAKE_RAW(Selectable, bool,SdkIsAISelectable )
	MAKE_RAW(CritImmune, bool,SdkIsAICritImmune )
	MAKE_RAW(Grounded, bool,SdkIsAIGrounded )
	MAKE_RAW(Obscured, bool, SdkIsAIObscured)
	MAKE_RAW(Killable, bool,SdkIsAIKillable )
	MAKE_GET(Armor, float, SdkGetAIArmor)
	MAKE_GET(Lethality, float, SdkGetAILethality)
	MAKE_GET(ArmorPenetration, float, SdkGetAIArmorPenetration)
	MAKE_GET(AttackSpeed, float, SdkGetAIAttackSpeed)
	MAKE_GET(AbilityPower, float, SdkGetAIAbilityPower)
	MAKE_GET(AttackDamage, float, SdkGetAIAttackDamage)
	MAKE_GET(AttackRange, float, SdkGetAIAttackRange)
	MAKE_GET(MagicResist, float, SdkGetAIMagicResist)
	MAKE_GET(Tenacity, float, SdkGetAITenacity)
	MAKE_GET(MovementSpeed, float, SdkGetAIMovementSpeed)
	MAKE_GET(CritChance, float, SdkGetAICritChance)
	MAKE_GET(CritDamageMultiplier, float, SdkGetAICritDamageMultiplier)
	MAKE_GET(DodgeChance, float, SdkGetAIDodgeChance)
	MAKE_GET(HealthRegen, float, SdkGetAIHealthRegen)
	MAKE_GET(MagicPenetration, float, SdkGetAIMagicPenetration)
	MAKE_GET(LifeSteal, float, SdkGetAILifeSteal)
	MAKE_GET(SpellVamp, float, SdkGetAISpellVamp)
	float GetAbilityResourceRegens(unsigned char index)
	{
		float tmp;
		SdkGetAIAbilityResourceRegen(Object,index,&tmp);
		return tmp;
	}
	MAKE_GET(CooldownReduction, float, SdkGetAICooldownReduction)
	MAKE_RAW(isBot, bool, SdkIsAIBot)
	float GetCurrentGold() {
	float Gold = NULL;
	if (Object == NULL || !SDKSTATUS_SUCCESS(SdkGetAIGold(Object, &Gold, NULL))) {
			SdkUiConsoleWrite("[SDK] Error! Could not retrieve Experience.\n");
		}
		return Gold;
	}
	float GetTotalGold() {
	float Gold = NULL;
		if (Object == NULL || !SDKSTATUS_SUCCESS(SdkGetAIGold(Object, NULL, &Gold))) {
			SdkUiConsoleWrite("[SDK] Error! Could not retrieve Level.\n");
		}
		return Gold;
	}
	MAKE_GET(CombatType, int, SdkGetAICombatType)
	MAKE_GET(Name, const char*, SdkGetAIName)

	std::vector<SDK_SPELL> GetSpells()
	{
		LSFail
		std::vector<SDK_SPELL> spells;
		for (uint8_t i = 0; i < SPELL_SLOT_MAX; ++i)
		{
			SDK_SPELL Spell;
			SdkGetAISpell(Object, i, &Spell);
			spells.push_back(Spell);
		}
		return spells;
	}

	MAKE_GET(DeathDuration, float, SdkGetAIDeathDuration)
	MAKE_RAW(Attacking, bool, SdkIsAIAttacking)
	MAKE_RAW(Moving, bool, SdkIsAIMoving)

	std::vector<BuffInstance> GetBuffs()
	{
		LSFail
		std::vector<BuffInstance> output;

		SdkEnumAIBuffs
		(
			Object,
			[](unsigned char Type, float StartTime, float EndTime, int Counter, void* UserData)  -> bool
		{
			//
			// This callback is invoked for every buff
			// attached to this AI object.
			//

			std::vector<BuffInstance>* Buffs = (std::vector<BuffInstance>*)UserData;

			BuffInstance Buff;
			Buff.Type = Type;
			Buff.StartTime = StartTime;
			Buff.EndTime = EndTime;
			Buff.Count = Counter;

			SdkBuffToString(Buff.Type, &Buff.Name);

			Buffs->push_back(Buff);

			return true;
		},
			&output
			);

		return output;
	}
	bool HasBuff(const char* input,bool isEqual=true)
	{
		auto buffs = GetBuffs();
		for (size_t i = 0; i < buffs.size(); i++)
		{
			auto buff = buffs[i];
			if (!buff.IsValid())
				continue;
			std::string buffname(buff.Name);
			for (auto& buffnamelower : buffname)
			{
				buffnamelower = tolower(buffnamelower);
			}

			if (isEqual)
			{
				if (!strstr(buffname.c_str(), input))
					return true;
			}
			else
			{
				if (!strcmp(buffname.c_str(), input) == 0)
					return true;

			}
	
		}
	}
};

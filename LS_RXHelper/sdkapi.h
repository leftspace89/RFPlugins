/*++

Module Name:

   sdkapi.h

Abstract:

    Exposes the Rift API to developers.

--*/

#pragma once

///
/// Typedefs.
///

//
// All SDK related functions return a status result, an SDKSTATUS.
//
typedef int SDKSTATUS;

///
/// Macros.
///

//////////////////////////////////////////////////////////////////////////
//
// All the possible SDK status codes.
//

//
// The operation completed successfully.
//
#define SDKSTATUS_NO_ERROR							((SDKSTATUS)0)

//
// Returned from SdkNotifyLoadedModule if a module of the specified
// name is already loaded in memory.
//
#define SDKSTATUS_MODULE_ALREADY_LOADED				((SDKSTATUS)1)

//
// Returned from SdkNotifyLoadedModule if the current SDK version is
// not compatible with the version of the module that the SDK was 
// built with.
//
#define SDKSTATUS_MODULE_VERSION_INCOMPATIBLE		((SDKSTATUS)2)

//
// A bad argument was passed into an SDK function.
//
#define SDKSTATUS_BAD_ARGUMENTS						((SDKSTATUS)3)

//
// The module tried to use an SDK function without calling 
// SdkNotifyLoadedModule first.
//
#define SDKSTATUS_MODULE_NOT_REGISTERED				((SDKSTATUS)4)

//
// An unknown error has occurred.
//
#define SDKSTATUS_INTERNAL_ERROR					((SDKSTATUS)5)

//
// An object was passed into a function that is not of the 
// appropriate type.
//
#define SDKSTATUS_OBJECT_TYPE_MISMATCH				((SDKSTATUS)6)

//
// Checks the return status of the SDK to determine if 
// the function was successful.
//
#define SDKSTATUS_SUCCESS(Status)					((Status == SDKSTATUS_NO_ERROR))
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Ability power related.
//

//
// Used by the SdkGetUnitAbilityResource and SdkGetAIAbilityResourceRegen
// functions to retrieve information about the primary and secondary
// ability resource of a specific AI object.
//
#define ABILITY_SLOT_PRIMARY						0
#define ABILITY_SLOT_SECONDARY						1

//
// The different types of ability resources.
//
// NOTE: SdkAbilityResourceToString will take in an ABILITY_TYPE_###
// value and convert it to a human readable string.
//

//
// SDK_ABILITY_RESOURCE.Type values.
//
#define ABILITY_TYPE_MANA							0
#define ABILITY_TYPE_ENERGY							1
#define ABILITY_TYPE_NONE							2
#define ABILITY_TYPE_SHIELD							3
#define ABILITY_TYPE_BATTLE_FURY					4
#define ABILITY_TYPE_DRAGON_FURY					5
#define ABILITY_TYPE_RAGE							6
#define ABILITY_TYPE_HEAT							7
#define ABILITY_TYPE_PRIMAL_FURY					8
#define ABILITY_TYPE_FEROCITY						9
#define ABILITY_TYPE_BLOOD_WELL						10
#define ABILITY_TYPE_WIND							11
#define ABILITY_TYPE_AMMO							12
#define ABILITY_TYPE_OTHER							13
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Buffs and debuffs.
//

//
// The different types of buffs and debuffs.
//
// NOTE: SdkBuffToString will take in an BUFF_TYPE_### value 
// and convert it to a human readable string.
//

//
// Retrieved from the SdkEnumAIBuffs callback: AIBUFFSCALLBACK.
//
#define BUFF_TYPE_INTERNAL							0
#define BUFF_TYPE_AURA								1
#define BUFF_TYPE_COMBAT_ENHANCEMENT				2
#define BUFF_TYPE_COMBAT_DEBUFF						3
#define BUFF_TYPE_SPELL_SHIELD						4
#define BUFF_TYPE_STUN								5
#define BUFF_TYPE_INVISIBILITY						6
#define BUFF_TYPE_SILENCE							7
#define BUFF_TYPE_TAUNT								8
#define BUFF_TYPE_POLYMORPH							9
#define BUFF_TYPE_SLOW								10
#define BUFF_TYPE_SNARE								11
#define BUFF_TYPE_DAMAGE							12
#define BUFF_TYPE_HEAL								13
#define BUFF_TYPE_HASTE								14
#define BUFF_TYPE_SPELL_IMMUNE						15
#define BUFF_TYPE_PHYSICAL_IMMUNE					16
#define BUFF_TYPE_INVULNERABILITY					17
#define BUFF_TYPE_ATTACK_SPEED_DEBUFF				18
#define BUFF_TYPE_NEAR_SIGHT						19
#define BUFF_TYPE_SHOP								20
#define BUFF_TYPE_FEAR								21
#define BUFF_TYPE_CHARM								22
#define BUFF_TYPE_POISON							23
#define BUFF_TYPE_SUPPRESSION						24
#define BUFF_TYPE_BLIND								25
#define BUFF_TYPE_COUNTER							26
#define BUFF_TYPE_SHRED								27
#define BUFF_TYPE_FLEE								28
#define BUFF_TYPE_KNOCKUP							29
#define BUFF_TYPE_KNOCKBACK							30
#define BUFF_TYPE_DISARM							31
#define BUFF_TYPE_GROUNDED							32
#define BUFF_TYPE_DROWSY							33
#define BUFF_TYPE_ASLEEP							34
#define BUFF_TYPE_OBSCURED							35
#define BUFF_TYPE_CLICK_PROOF						36
#define BUFF_TYPE_UNKILLABLE						37
#define BUFF_TYPE_INVALID							38
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Combat types.
//

//
// Retrieved from SdkGetAICombatType.
//
#define COMBAT_TYPE_UNKNOWN							0
#define COMBAT_TYPE_MELEE							1
#define COMBAT_TYPE_RANGED							2
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Spell slots.
// 

//
// Used by spell related API: SdkGetAISpell, SdkCastSpellLocalPlayer, and
// SdkLevelSpellLocalPlayer.
//
#define SPELL_SLOT_MAX								65
#define SPELL_SLOT_START							0
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Spell cast state.
//

//
// Used by SdkCastSpellLocalPlayer.
//
#define SPELL_CAST_START							0
#define SPELL_CAST_COMPLETE							1

//////////////////////////////////////////////////////////////////////////
// 
// SDK_SPELL.ToggleState values.
//
#define SPELL_TOGGLE_STATE_NONE						0
#define SPELL_TOGGLE_STATE_OFF						1
#define SPELL_TOGGLE_STATE_ON						2
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// SDK_SPELL.Flags bitwise mask.
//
#define SPELL_FLAG_NONE								0x0
#define SPELL_FLAG_INSTANT_CAST						0x4
#define SPELL_FLAG_PERSIST_THROUGH_DEATH			0x8
#define SPELL_FLAG_NOT_DISPELLABLE					0x10
#define SPELL_FLAG_NOT_CLICKABLE					0x20
#define SPELL_FLAG_AFFECT_IMPORTANT_BOTS			0x40
#define SPELL_FLAG_ALLOW_WHILE_TAUNTED				0x80
#define SPELL_FLAG_IGNORE_VISIBILITY_CHECK			0x400000
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// SDK_SPELL.AffectsFlags bitwise mask.
//
#define SPELL_AFFECTS_FLAG_NONE						0x0
#define SPELL_AFFECTS_FLAG_ALLIED_CHAMPIONS			0x1
#define SPELL_AFFECTS_FLAG_ENEMY_CHAMPIONS			0x2
#define SPELL_AFFECTS_FLAG_ALLIED_MINIONS			0x4
#define SPELL_AFFECTS_FLAG_ENEMY_MINIONS			0x8
#define SPELL_AFFECTS_FLAG_ALLIED_WARDS				0x10
#define SPELL_AFFECTS_FLAG_ENEMY_WARDS				0x20
#define SPELL_AFFECTS_FLAG_ALLIED_TURRETS			0x40
#define SPELL_AFFECTS_FLAG_ENEMY_TURRETS			0x80
#define SPELL_AFFECTS_FLAG_ALLIED_BUILDINGS			0x100
#define SPELL_AFFECTS_FLAG_ENEMY_BUILDINGS			0x200
#define SPELL_AFFECTS_FLAG_ALLIED_NPCS				0x400
#define SPELL_AFFECTS_FLAG_NEUTRAL_NPCS				0x800
#define SPELL_AFFECTS_FLAG_ENEMY_NPCS				0x1000
#define SPELL_AFFECTS_FLAG_MYSELF					0x2000
#define SPELL_AFFECTS_FLAG_OTHERS					0x4000

#define SPELL_AFFECTS_ALLIES						(SPELL_AFFECTS_FLAG_ALLIED_CHAMPIONS | \
													SPELL_AFFECTS_FLAG_ALLIED_MINIONS | \
													SPELL_AFFECTS_FLAG_ALLIED_WARDS | \
													SPELL_AFFECTS_FLAG_ALLIED_TURRETS | \
													SPELL_AFFECTS_FLAG_ALLIED_BUILDINGS | \
													SPELL_AFFECTS_FLAG_ALLIED_NPCS)

#define SPELL_AFFECTS_ENEMIES						(SPELL_AFFECTS_FLAG_ENEMY_CHAMPIONS | \
													SPELL_AFFECTS_FLAG_ENEMY_MINIONS | \
													SPELL_AFFECTS_FLAG_ENEMY_WARDS | \
													SPELL_AFFECTS_FLAG_ENEMY_TURRETS | \
													SPELL_AFFECTS_FLAG_ENEMY_BUILDINGS | \
													SPELL_AFFECTS_FLAG_ENEMY_NPCS)

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// SDK_SPELL.AffectsFlags2 bitwise mask.
//
#define SPELL_AFFECTS_FLAG2_NONE					0x0
#define SPELL_AFFECTS_FLAG2_IGNORE_CLONES			0x1
#define SPELL_AFFECTS_FLAG2_IGNORE_ZOMBIES			0x2
#define SPELL_AFFECTS_FLAG2_IGNORE_PET				0x4
#define SPELL_AFFECTS_FLAG2_ALLOW_DEAD				0x8
#define SPELL_AFFECTS_FLAG2_ALLOW_UNTARGETABLE		(0x10 | 0x20)
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// SDK_SPELL.CastType values.
//
#define SPELL_CAST_TYPE_INSTANT						0
#define SPELL_CAST_TYPE_MISSILE						1
#define SPELL_CAST_TYPE_CHAIN						2
#define SPELL_CAST_TYPE_ARC							3
#define SPELL_CAST_TYPE_CIRCLE						4
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Minion types.
//

//
// Retrieved from SdkGetMinionType.
//
#define MINION_TYPE_NONE							0
#define MINION_TYPE_PET								1
#define MINION_TYPE_LANE_MINION						2
#define MINION_TYPE_JUNGLE_MONSTER					3
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Turrets.
//

//
// Position defines. Retrieved from SdkGetTurretInfo.
//
#define TURRET_POSITION_FOUNTAIN					0
#define TURRET_POSITION_BASE						1
#define TURRET_POSITION_INNER						2
#define TURRET_POSITION_OUTER						3
#define TURRET_POSITION_NEXUS_1						4
#define TURRET_POSITION_NEXUS_2						5

//
// Lane defines. Retrieved from SdkGetTurretInfo.
//
#define TURRET_LANE_RIGHT							0
#define TURRET_LANE_CENTER							1
#define TURRET_LANE_LEFT							2
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Emote types.
//

//
// Used by SdkShowEmoteLocalPlayer.
//
#define EMOTE_TYPE_DANCE							0
#define EMOTE_TYPE_TAUNT							1
#define EMOTE_TYPE_LAUGH							2
#define EMOTE_TYPE_JOKE								3
#define EMOTE_TYPE_TOGGLE							4
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Ping types.
//

//
// Used by SdkPingMap.
//
#define PING_TYPE_DEFAULT							0
#define PING_TYPE_CHARGE							1
#define PING_TYPE_DANGER							2
#define PING_TYPE_MISSING							3
#define PING_TYPE_ON_MY_WAY							4
#define PING_TYPE_BACK								5
#define PING_TYPE_COME								6
#define PING_TYPE_WARDED							7
#define PING_TYPE_SMALL_ICON						8
#define PING_TYPE_BIG_ICON							9

//////////////////////////////////////////////////////////////////////////

///
/// Enums.
///

//
// Flags for SdkUiInputText and SdkUiInputMultiLineText.
//
enum INPUT_TEXT_FLAGS : int
{
	//
	// Allow 0123456789.+-*/
	//
	TEXT_FLAGS_CHARS_DECIMAL = 1 << 0,

	//
	// Allow 0123456789ABCDEFabcdef
	//
	TEXT_FLAGS_CHARS_HEXADECIMAL = 1 << 1,

	//
	// Turn a..z into A..Z
	//
	TEXT_FLAGS_CHARS_UPPERCASE = 1 << 2,

	//
	// Filter out spaces, tabs
	//
	TEXT_FLAGS_CHARS_NO_BLANKS = 1 << 3,

	//
	// Select entire text when first taking mouse focus
	//
	TEXT_FLAGS_AUTO_SELECT_ALL = 1 << 4, 

	//
	// Return 'true' when Enter is pressed (as opposed to when the value was modified)
	//
	TEXT_FLAGS_ENTER_RETURNS_TRUE = 1 << 5,

	//
	// Pressing TAB input a '\t' character into the text field
	//
	TEXT_FLAGS_ALLOW_TAB_INPUT = 1 << 10,

	//
	// In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter)
	//
	TEXT_FLAGS_CTRL_ENTER_FOR_NEW_LINE = 1 << 11,

	//
	// Disable following the cursor horizontally
	//
	TEXT_FLAGS_NO_HORIZONTAL_SCROLL = 1 << 12,

	//
	// Insert mode
	//
	TEXT_FLAGS_ALWAYS_INSERT_MODE = 1 << 13,

	//
	// Read-only mode
	//
	TEXT_FLAGS_READ_ONLY = 1 << 14,

	//
	// Password mode, display all characters as '*'
	//
	TEXT_FLAGS_PASSWORD = 1 << 15,

	//
	// Disable undo/redo. Note that input text owns the text data while active.
	//
	TEXT_FLAGS_NO_UNDO_REDO = 1 << 16,
};

///
/// Structures.
///

//
// An SDKVECTOR (x, y, z) is typically used for world (in-game) 
// position calculations. 3D math.
//
#ifndef SDKVECTOR_EXTEND
typedef struct _SDKVECTOR
{
	float x, y, z;
} SDKVECTOR, *PSDKVECTOR;
static_assert(sizeof(SDKVECTOR) == 12, "Size mismatch.");

#else
//Extended custom vectors  using right now 
#endif

//
// An SDKPOINT (x, y) is typically used for screen (e.g. mouse)
// position calculations. 2D math.
//
typedef struct _SDKPOINT
{
	float x, y;
} SDKPOINT, *PSDKPOINT;
static_assert(sizeof(SDKPOINT) == 8, "Size mismatch.");

//
// An SDKBOX { (x0, y0, z0) (x1, y1, z1) } is typically used
// for world (in-game) bounding box calculations. 3D math.
//
typedef struct _SDKBOX
{
	SDKVECTOR Min;
	SDKVECTOR Max;
} SDKBOX, *PSDKBOX;
static_assert(sizeof(SDKBOX) == 24, "Size mismatch.");

//
// Byte-order color encoding used by the SDK.
//
#pragma warning(push)
#pragma warning(disable: 4201)
typedef union _SDKCOLOR
{
	struct
	{
		unsigned char B;
		unsigned char G;
		unsigned char R;
		unsigned char A;
	};

	unsigned int BGRA;
} SDKCOLOR, *PSDKCOLOR;
static_assert(sizeof(SDKCOLOR) == 4, "Size mismatch.");
#pragma warning(pop)

//
// Retrieves a unit's ability resource information. Used by 
// SdkGetUnitAbilityResource.
//
typedef struct _SDK_ABILITY_RESOURCE
{
	bool Enabled;
	//
	// An ABILITY_TYPE_### value.
	//
	unsigned char Type;
	float Current;
	float Max;
} SDK_ABILITY_RESOURCE, *PSDK_ABILITY_RESOURCE;

//
// Retrieves a unit's health state. Used by SdkGetUnitHealth.
//
typedef struct _SDK_HEALTH
{
	float Current;
	float Max;
	float AllShield;
	float PhysicalShield;
	float MagicalShield;
} SDK_HEALTH, *PSDK_HEALTH;

//
// Retrieves information about a specific spell slot. Used by
// SdkGetAISpell.
//
typedef struct _SDK_SPELL
{
	//
	// >= SPELL_SLOT_START and < SPELL_SLOT_MAX.
	//
	unsigned char Slot;
	bool Learned;
	bool Castable;
	int Level;
	float CastTime;
	float ManaCost;
	float TotalCooldown;
	float BaseCooldown;
	float CooldownExpires;
	float CooldownReductionPercent;
	int CurrentAmmo;
	int MaxAmmo;
	int AmmoUsage;
	float TimeForNextAmmoRecharge;
	float TotalAmmoRechargeTime;
	
	//
	// A SPELL_TOGGLE_STATE_### value.
	//
	int ToggleState;
	float ChannelDuration;
	float CastRange;
	float CastRadius;
	float SpellDamageRatio;
	float PhysicalDamageRatio;
	float MissileSpeed;

	//
	// Bitwise mask of SPELL_FLAG_###.
	//
	int Flags;

	//
	// Bitwise mask of SPELL_AFFECTS_FLAG_###.
	//
	int AffectsFlags;

	//
	// Bitwise mask of SPELL_AFFECTS_FLAG2_###.
	//
	int AffectsFlags2;

	//
	// A SPELL_CAST_TYPE_### value.
	//
	int CastType;
	const char* DisplayName;
	const char* AlternateName;
	const char* Description;
} SDK_SPELL, *PSDK_SPELL;

///
/// Callbacks.
///

//
// Used by SdkRegisterOverlayScene and SdkRegisterGameScene.
// 
typedef void (__cdecl* RENDERSCENECALLBACK)(void* UserData);

//
// Used by SdkEnumChampionSkinNames.
//
typedef bool (__cdecl* CHAMPIONSKINNAMESCALLBACK)(const char* SkinName, int SkinID, void* UserData);

// 
// Used by SdkEnumGameObjects, SdkRegisterGameObjectCreate, and SdkRegisterGameObjectDelete.
// 
typedef bool (__cdecl* GAMEOBJECTSCALLBACK)(void* Object, void* UserData);

//
// Used by SdkEnumAIBuffs.
//
typedef bool (__cdecl* AIBUFFSCALLBACK)(unsigned char Type, float StartTime, float EndTime, int Counter, void* UserData);

//////////////////////////////////////////////////////////////////////////
//
// SDK API.
//

//
// Function definitions. Do not use these directly, instead go through
// the provided macros for ease.
//
typedef SDKSTATUS (__cdecl *SdkNotifyLoadedModule_t)(const char* ModuleName, unsigned int SdkVersion);
typedef SDKSTATUS (__cdecl *SdkUiConsoleWrite_t)(const char* Format, ...);
typedef SDKSTATUS (__cdecl* SdkUiConsoleClear_t)();
typedef SDKSTATUS (__cdecl* SdkGetLocalPlayer_t)(void** Player);
typedef SDKSTATUS (__cdecl* SdkGetAISkinID_t)(void* AI, int* SkinID);
typedef SDKSTATUS (__cdecl* SdkUiBeginCombo_t)(const char* Label, const char* PreviewValue, bool* Clicked);
typedef SDKSTATUS (__cdecl* SdkUiEndCombo_t)();
typedef SDKSTATUS (__cdecl* SdkUiAddSelection_t)(const char* Label, bool Selected, bool* Clicked);
typedef SDKSTATUS (__cdecl* SdkUiSetItemDefaultFocus_t)();
typedef SDKSTATUS (__cdecl* SdkUiText_t)(const char* Format, ...);
typedef SDKSTATUS (__cdecl* SdkUiButton_t)(const char* Label, bool* Clicked);
typedef SDKSTATUS (__cdecl* SdkSetAISkinID_t)(void* AI, int SkinID);
typedef SDKSTATUS (__cdecl* SdkRegisterOverlayScene_t)(RENDERSCENECALLBACK Scene, void* UserData);
typedef SDKSTATUS (__cdecl* SdkEnumChampionSkinNames_t)(const char* ChampionName, CHAMPIONSKINNAMESCALLBACK Callback, void* UserData);
typedef SDKSTATUS (__cdecl* SdkGetAIName_t)(void* AI, const char** Name);
typedef SDKSTATUS (__cdecl* SdkUiForceOnSameLine_t)();
typedef SDKSTATUS (__cdecl* SdkUiSetNextWindowPos_t)(PSDKPOINT Position);
typedef SDKSTATUS (__cdecl* SdkUiGetWindowDim_t)(PSDKPOINT Position, PSDKPOINT Size);
typedef SDKSTATUS (__cdecl* SdkUiBeginWindow_t)(const char* WindowName, bool* Visible, bool* Collapsed);
typedef SDKSTATUS (__cdecl* SdkUiEndWindow_t)();
typedef SDKSTATUS (__cdecl* SdkUiInputPoint_t)(const char* Label, PSDKPOINT Point, int Precision, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiInputVector_t)(const char* Label, PSDKVECTOR Vector, int Precision, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiCheckbox_t)(const char* Label, bool* Checked, bool* Clicked);
typedef SDKSTATUS (__cdecl* SdkUiGetWindow_t)(HWND* Window);
typedef SDKSTATUS (__cdecl* SdkScreenToWorld_t)(PSDKPOINT ScreenPoint, PSDKVECTOR WorldCoordinates);
typedef SDKSTATUS (__cdecl* SdkUiColorPicker_t)(const char* Label, PSDKVECTOR Color, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiSmallButton_t)(const char* Label, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkGetObjectPosition_t)(void* Object, PSDKVECTOR Position);
typedef SDKSTATUS (__cdecl* SdkUiInputFloat_t)(const char* Label, float* Value, int Precision, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiColoredText_t)(PSDKCOLOR Color, const char* Format, ...);
typedef SDKSTATUS (__cdecl* SdkUiDragFloat_t)(const char* Label, float* Value, float Min, float Max, const char* Format, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiCombo_t)(const char* Label, int* Selection, const char* const* Items, int Entries, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkUiBeginTree_t)(const char* Label, bool* Expanded);
typedef SDKSTATUS (__cdecl* SdkUiEndTree_t)();
typedef SDKSTATUS (__cdecl* SdkUiBeginTreeEx_t)(bool* Expanded, const void* Id, const char* Format, ...);
typedef SDKSTATUS (__cdecl* SdkUiBulletText_t)(const char* Format, ...);
typedef SDKSTATUS (__cdecl* SdkUiBulletPoint_t)();
typedef SDKSTATUS (__cdecl* SdkRegisterGameScene_t)(RENDERSCENECALLBACK Scene, void* UserData);
typedef SDKSTATUS (__cdecl* SdkDrawLine_t)(PSDKVECTOR StartWorld, PSDKVECTOR EndWorld, float Width, PSDKCOLOR Color, int Texture);
typedef SDKSTATUS (__cdecl* SdkDrawCircle_t)(PSDKVECTOR OriginWorld, float Radius, PSDKCOLOR Color, int Texture, PSDKVECTOR Direction);
typedef SDKSTATUS (__cdecl* SdkDrawCone_t)(PSDKVECTOR OriginWorld, float Length, float Angle, PSDKVECTOR Direction, PSDKCOLOR Color, int Texture);
typedef SDKSTATUS (__cdecl* SdkGetNumberOfGameObjects_t)(int* NumberOfObjects);
typedef SDKSTATUS (__cdecl* SdkEnumGameObjects_t)(GAMEOBJECTSCALLBACK Callback, void* UserData);
typedef SDKSTATUS (__cdecl* SdkGetObjectTypeFlags_t)(void* Object, int* TypeFlags);
typedef SDKSTATUS (__cdecl* SdkGetObjectTypeName_t)(void* Object, const char** TypeName);
typedef SDKSTATUS (__cdecl* SdkGetObjectID_t)(void* Object, unsigned int* ID);
typedef SDKSTATUS (__cdecl* SdkGetObjectTeamID_t)(void* Object, int* TeamID);
typedef SDKSTATUS (__cdecl* SdkIsObjectZombie_t)(void* Object, bool* Zombie);
typedef SDKSTATUS (__cdecl* SdkIsObjectDead_t)(void* Object, bool* Dead);
typedef SDKSTATUS (__cdecl* SdkGetObjectName_t)(void* Object, const char** Name);
typedef SDKSTATUS (__cdecl* SdkGetObjectOrientation_t)(void* Object, PSDKVECTOR Orientation);
typedef SDKSTATUS (__cdecl* SdkGetObjectBoundingBox_t)(void* Object, PSDKBOX BBox);
typedef SDKSTATUS (__cdecl* SdkIsObjectVisibleOnScreen_t)(void* Object, bool* Visible);
typedef SDKSTATUS (__cdecl* SdkGetObjectRespawns_t)(void* Object, unsigned int* Respawns);
typedef SDKSTATUS (__cdecl* SdkIsObjectUnit_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkIsUnitVisible_t)(void* Unit, bool* Visible);
typedef SDKSTATUS (__cdecl* SdkGetUnitDeathTime_t)(void* Unit, float* Time);
typedef SDKSTATUS (__cdecl* SdkGetUnitAbilityResource_t)(void* Unit, unsigned char Slot, PSDK_ABILITY_RESOURCE AbilityResource);
typedef SDKSTATUS (__cdecl* SdkGetUnitIsMouseOver_t)(void* Unit, bool* MouseOver);
typedef SDKSTATUS (__cdecl* SdkGetUnitHealth_t)(void* Unit, PSDK_HEALTH Health);
typedef SDKSTATUS (__cdecl* SdkIsObjectAI_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkIsAIPlayerControlled_t)(void* AI, bool* Human);
typedef SDKSTATUS (__cdecl* SdkCanAIAttack_t)(void* AI, bool* Attack);
typedef SDKSTATUS (__cdecl* SdkCanAICrit_t)(void* AI, bool* Crit);
typedef SDKSTATUS (__cdecl* SdkCanAICast_t)(void* AI, bool* Cast);
typedef SDKSTATUS (__cdecl* SdkCanAIMove_t)(void* AI, bool* Move);
typedef SDKSTATUS (__cdecl* SdkIsAIStealthed_t)(void* AI, bool* Stealthed);
typedef SDKSTATUS (__cdecl* SdkIsAITaunted_t)(void* AI, bool* Taunted);
typedef SDKSTATUS (__cdecl* SdkIsAIFeared_t)(void* AI, bool* Feared);
typedef SDKSTATUS (__cdecl* SdkIsAIFleeing_t)(void* AI, bool* Fleeing);
typedef SDKSTATUS (__cdecl* SdkIsAISuppressed_t)(void* AI, bool* Suppressed);
typedef SDKSTATUS (__cdecl* SdkIsAISleeping_t)(void* AI, bool* Sleeping);
typedef SDKSTATUS (__cdecl* SdkIsAINearSighted_t)(void* AI, bool* NearSighted);
typedef SDKSTATUS (__cdecl* SdkIsAIGhosted_t)(void* AI, bool* Ghosted);
typedef SDKSTATUS (__cdecl* SdkIsAICharmed_t)(void* AI, bool* Charmed);
typedef SDKSTATUS (__cdecl* SdkIsAISlowed_t)(void* AI, bool* Slowed);
typedef SDKSTATUS (__cdecl* SdkIsAISelectable_t)(void* AI, bool* Selectable);
typedef SDKSTATUS (__cdecl* SdkIsAICritImmune_t)(void* AI, bool* CritImmune);
typedef SDKSTATUS (__cdecl* SdkIsAIGrounded_t)(void* AI, bool* Grounded);
typedef SDKSTATUS (__cdecl* SdkIsAIObscured_t)(void* AI, bool* Obscured);
typedef SDKSTATUS (__cdecl* SdkIsAIKillable_t)(void* AI, bool* Killable);
typedef SDKSTATUS (__cdecl* SdkGetAIArmor_t)(void* AI, float* Armor);
typedef SDKSTATUS (__cdecl* SdkGetAILethality_t)(void* AI, float* Lethality);
typedef SDKSTATUS (__cdecl* SdkGetAIArmorPenetration_t)(void* AI, float* ArmorPenetration);
typedef SDKSTATUS (__cdecl* SdkGetAIAttackSpeed_t)(void* AI, float* AttackSpeed);
typedef SDKSTATUS (__cdecl* SdkGetAIAbilityPower_t)(void* AI, float* AbilityPower);
typedef SDKSTATUS (__cdecl* SdkGetAIAttackDamage_t)(void* AI, float* AttackDamage);
typedef SDKSTATUS (__cdecl* SdkGetAIAttackRange_t)(void* AI, float* AttackRange);
typedef SDKSTATUS (__cdecl* SdkGetAIMagicResist_t)(void* AI, float* MagicResist);
typedef SDKSTATUS (__cdecl* SdkGetAITenacity_t)(void* AI, float* Tenacity);
typedef SDKSTATUS (__cdecl* SdkGetAIMovementSpeed_t)(void* AI, float* MovementSpeed);
typedef SDKSTATUS (__cdecl* SdkGetAICritChance_t)(void* AI, float* CritChance);
typedef SDKSTATUS (__cdecl* SdkGetAICritDamageMultiplier_t)(void* AI, float* CritDamageMultiplier);
typedef SDKSTATUS (__cdecl* SdkGetAIDodgeChance_t)(void* AI, float* DodgeChance);
typedef SDKSTATUS (__cdecl* SdkGetAIHealthRegen_t)(void* AI, float* HealthRegen);
typedef SDKSTATUS (__cdecl* SdkGetAIMagicPenetration_t)(void* AI, float* MagicPenetration);
typedef SDKSTATUS (__cdecl* SdkGetAILifeSteal_t)(void* AI, float* LifeSteal);
typedef SDKSTATUS (__cdecl* SdkGetAISpellVamp_t)(void* AI, float* SpellVamp);
typedef SDKSTATUS (__cdecl* SdkGetAIAbilityResourceRegen_t)(void* AI, unsigned char Slot, float* AbilityResourceRegen);
typedef SDKSTATUS (__cdecl* SdkGetAICooldownReduction_t)(void* AI, float* CooldownReduction);
typedef SDKSTATUS (__cdecl* SdkIsAIBot_t)(void* AI, bool* Bot);
typedef SDKSTATUS (__cdecl* SdkGetAIGold_t)(void* AI, float* CurrentGold, float* TotalGold);
typedef SDKSTATUS (__cdecl* SdkEnumAIBuffs_t)(void* AI, AIBUFFSCALLBACK Callback, void* UserData);
typedef SDKSTATUS (__cdecl* SdkAbilityResourceToString_t)(unsigned char Type, const char** String);
typedef SDKSTATUS (__cdecl* SdkBuffToString_t)(unsigned char Type, const char** String);
typedef SDKSTATUS (__cdecl* SdkGetAICombatType_t)(void* AI, int* CombatType);
typedef SDKSTATUS (__cdecl* SdkGetAISpell_t)(void* AI, unsigned char Slot, PSDK_SPELL Spell);
typedef SDKSTATUS (__cdecl* SdkGetAIDeathDuration_t)(void* AI, float* DeathDuration);
typedef SDKSTATUS (__cdecl* SdkIsAIAttacking_t)(void* AI, bool* Attacking);
typedef SDKSTATUS (__cdecl* SdkIsAIMoving_t)(void* AI, bool* Moving);
typedef SDKSTATUS (__cdecl* SdkIsObjectHero_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkGetHeroExperience_t)(void* Hero, float* Experience, int* Level);
typedef SDKSTATUS (__cdecl* SdkGetHeroNeutralKills_t)(void* Hero, int* Kills);
typedef SDKSTATUS (__cdecl* SdkIsObjectMinion_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkGetMinionSpawnTime_t)(void* Minion, float* Time);
typedef SDKSTATUS (__cdecl* SdkGetMinionCampNumber_t)(void* Minion, int* Camp);
typedef SDKSTATUS (__cdecl* SdkIsMinionLaneMinion_t)(void* Minion, bool* LaneMinion);
typedef SDKSTATUS (__cdecl* SdkGetMinionType_t)(void* Minion, int* Type);
typedef SDKSTATUS (__cdecl* SdkGetMinionLevel_t)(void* Minion, int* Level);
typedef SDKSTATUS (__cdecl* SdkIsMinionWard_t)(void* Minion, bool* Ward);
typedef SDKSTATUS (__cdecl* SdkIsObjectTurret_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkGetTurretInfo_t)(void* Turret, int* Position, int* Lane);
typedef SDKSTATUS (__cdecl* SdkIsObjectSpellMissile_t)(void* Object);
typedef SDKSTATUS (__cdecl* SdkWorldToScreen_t)(PSDKVECTOR WorldCoordinates, PSDKPOINT ScreenPoint);
typedef SDKSTATUS (__cdecl* SdkStopLocalPlayer_t)(bool Pet);
typedef SDKSTATUS (__cdecl* SdkMoveLocalPlayer_t)(PSDKVECTOR Destination, bool Pet);
typedef SDKSTATUS (__cdecl* SdkAttackTargetLocalPlayer_t)(void* Unit, bool Pet);
typedef SDKSTATUS (__cdecl* SdkUiInputText_t)(const char* Label, char* Buffer, size_t Elements, int Flags, bool* Triggered);
typedef SDKSTATUS (__cdecl* SdkAttackMoveLocalPlayer_t)(PSDKVECTOR Destination);
typedef SDKSTATUS (__cdecl* SdkCastSpellLocalPlayer_t)(void* Unit, PSDKVECTOR Destination, unsigned char Slot, unsigned char State);
typedef SDKSTATUS (__cdecl* SdkUiInputNumber_t)(const char* Label, int* Number, bool* Changed);
typedef SDKSTATUS (__cdecl* SdkMoveMouse_t)(PSDKVECTOR WorldCoordinates);
typedef SDKSTATUS (__cdecl* SdkGetGameTime_t)(float* Time);
typedef SDKSTATUS (__cdecl* SdkLevelSpellLocalPlayer_t)(unsigned char Slot, bool* Leveled);
typedef SDKSTATUS (__cdecl* SdkShowEmoteLocalPlayer_t)(unsigned char Emote);
typedef SDKSTATUS (__cdecl* SdkSendChatLocalPlayer_t)(const char* Text);
typedef SDKSTATUS (__cdecl* SdkUiInputMultiLineText_t)(const char* Label, char* Buffer, size_t Elements, PSDKPOINT Size, int Flags, bool* Triggered);
typedef SDKSTATUS (__cdecl* SdkDrawText_t)(PSDKVECTOR WorldCoordinates, PSDKPOINT ScreenPoint, const char* Text, const char* Face, PSDKCOLOR Color, int Height, int Width, int Weight, bool Italic);
typedef SDKSTATUS (__cdecl* SdkSetSettingString_t)(const char* Key, const char* Value);
typedef SDKSTATUS (__cdecl* SdkGetSettingString_t)(const char* Key, char* Buffer, size_t Elements, const char* Default);
typedef SDKSTATUS (__cdecl* SdkSetSettingBool_t)(const char* Key, bool Value);
typedef SDKSTATUS (__cdecl* SdkGetSettingBool_t)(const char* Key, bool* Value, bool Default);
typedef SDKSTATUS (__cdecl* SdkSetSettingFloat_t)(const char* Key, float Value);
typedef SDKSTATUS (__cdecl* SdkGetSettingFloat_t)(const char* Key, float* Value, float Default);
typedef SDKSTATUS (__cdecl* SdkSetSettingNumber_t)(const char* Key, int Value);
typedef SDKSTATUS (__cdecl* SdkGetSettingNumber_t)(const char* Key, int* Value, int Default);
typedef SDKSTATUS (__cdecl* SdkGetMinionVisionRadius_t)(void* Minion, float* Radius);
typedef SDKSTATUS (__cdecl* SdkPingMap_t)(PSDKVECTOR WorldCoordinates, unsigned char Type, bool PlayAudio);
typedef SDKSTATUS (__cdecl* SdkDisableInput_t)();
typedef SDKSTATUS (__cdecl* SdkEnableInput_t)();
typedef SDKSTATUS (__cdecl* SdkGetD3DDevice_t)(void** Device);
typedef SDKSTATUS (__cdecl* SdkWorldToMinimap_t)(PSDKVECTOR WorldCoordinates, PSDKPOINT ScreenPoint);
typedef SDKSTATUS (__cdecl* SdkGetObjectVelocity_t)(void* Object, PSDKVECTOR Velocity);
typedef SDKSTATUS (__cdecl* SdkGetObjectAcceleration_t)(void* Object, PSDKVECTOR Acceleration);
typedef SDKSTATUS (__cdecl* SdkRegisterGameObjectCreate_t)(GAMEOBJECTSCALLBACK Callback, void* UserData);
typedef SDKSTATUS (__cdecl* SdkRegisterGameObjectDelete_t)(GAMEOBJECTSCALLBACK Callback, void* UserData);

//
// The SDK context structure, which contains a reference to the 
// function pointers defined above. Do not access these fields 
// directly. The provided macros will do the work for you,
// while maintaining much more readable code.
//
typedef struct _SDK_CONTEXT
{
	SdkNotifyLoadedModule_t _SdkNotifyLoadedModule;
	SdkUiConsoleWrite_t _SdkConsoleWrite;
	SdkUiConsoleClear_t _SdkConsoleClear;
	SdkGetLocalPlayer_t _SdkGetLocalPlayer;
	SdkGetAISkinID_t _SdkGetAISkinID;
	SdkUiBeginCombo_t _SdkUiBeginCombo;
	SdkUiEndCombo_t _SdkUiEndCombo;
	SdkUiAddSelection_t _SdkUiAddSelection;
	SdkUiSetItemDefaultFocus_t _SdkUiSetItemDefaultFocus;
	SdkUiText_t _SdkUiText;
	SdkUiButton_t _SdkUiButton;
	SdkSetAISkinID_t _SdkSetAISkinID;
	SdkRegisterOverlayScene_t _SdkRegisterOverlayScene;
	SdkEnumChampionSkinNames_t _SdkEnumChampionSkinNames;
	SdkGetAIName_t _SdkGetAIName;
	SdkUiForceOnSameLine_t _SdkUiForceOnSameLine;
	SdkUiSetNextWindowPos_t _SdkUiSetNextWindowPos;
	SdkUiGetWindowDim_t _SdkUiGetWindowDim;
	SdkUiBeginWindow_t _SdkUiBeginWindow;
	SdkUiEndWindow_t _SdkUiEndWindow;
	SdkUiInputPoint_t _SdkUiInputPoint;
	SdkUiInputVector_t _SdkUiInputVector;
	SdkUiCheckbox_t _SdkUiCheckbox;
	SdkUiGetWindow_t _SdkUiGetWindow;
	SdkScreenToWorld_t _SdkScreenToWorld;
	SdkUiColorPicker_t _SdkUiColorPicker;
	SdkUiSmallButton_t _SdkUiSmallButton;
	SdkGetObjectPosition_t _SdkGetObjectPosition;
	SdkUiInputFloat_t _SdkUiInputFloat;
	SdkUiColoredText_t _SdkUiColoredText;
	SdkUiDragFloat_t _SdkUiDragFloat;
	SdkUiCombo_t _SdkUiCombo;
	SdkUiBeginTree_t _SdkUiBeginTree;
	SdkUiEndTree_t _SdkUiEndTree;
	SdkUiBeginTreeEx_t _SdkUiBeginTreeEx;
	SdkUiBulletText_t _SdkUiBulletText;
	SdkUiBulletPoint_t _SdkUiBulletPoint;
	SdkRegisterGameScene_t _SdkRegisterGameScene;
	SdkDrawLine_t _SdkDrawLine;
	SdkDrawCircle_t _SdkDrawCircle;
	SdkDrawCone_t _SdkDrawCone;
	SdkGetNumberOfGameObjects_t _SdkGetNumberOfGameObjects;
	SdkEnumGameObjects_t _SdkEnumGameObjects;
	SdkGetObjectTypeFlags_t _SdkGetObjectTypeFlags;
	SdkGetObjectTypeName_t _SdkGetObjectTypeName;
	SdkGetObjectID_t _SdkGetObjectID;
	SdkGetObjectTeamID_t _SdkGetObjectTeamID;
	SdkIsObjectZombie_t _SdkIsObjectZombie;
	SdkIsObjectDead_t _SdkIsObjectDead;
	SdkGetObjectName_t _SdkGetObjectName;
	SdkGetObjectOrientation_t _SdkGetObjectOrientation;
	SdkGetObjectBoundingBox_t _SdkGetObjectBoundingBox;
	SdkIsObjectVisibleOnScreen_t _SdkIsObjectVisibleOnScreen;
	SdkGetObjectRespawns_t _SdkGetObjectRespawns;
	SdkIsObjectUnit_t _SdkIsObjectUnit;
	SdkIsUnitVisible_t _SdkIsUnitVisible;
	SdkGetUnitDeathTime_t _SdkGetUnitDeathTime;
	SdkGetUnitAbilityResource_t _SdkGetUnitAbilityResource;
	SdkGetUnitIsMouseOver_t _SdkGetUnitIsMouseOver;
	SdkGetUnitHealth_t _SdkGetUnitHealth;
	SdkIsObjectAI_t _SdkIsObjectAI;
	SdkIsAIPlayerControlled_t _SdkIsAIPlayerControlled;
	SdkCanAIAttack_t _SdkCanAIAttack;
	SdkCanAICrit_t _SdkCanAICrit;
	SdkCanAICast_t _SdkCanAICast;
	SdkCanAIMove_t _SdkCanAIMove;
	SdkIsAIStealthed_t _SdkIsAIStealthed;
	SdkIsAITaunted_t _SdkIsAITaunted;
	SdkIsAIFeared_t _SdkIsAIFeared;
	SdkIsAIFleeing_t _SdkIsAIFleeing;
	SdkIsAISuppressed_t _SdkIsAISuppressed;
	SdkIsAISleeping_t _SdkIsAISleeping;
	SdkIsAINearSighted_t _SdkIsAINearSighted;
	SdkIsAIGhosted_t _SdkIsAIGhosted;
	SdkIsAICharmed_t _SdkIsAICharmed;
	SdkIsAISlowed_t _SdkIsAISlowed;
	SdkIsAISelectable_t _SdkIsAISelectable;
	SdkIsAICritImmune_t _SdkIsAICritImmune;
	SdkIsAIGrounded_t _SdkIsAIGrounded;
	SdkIsAIObscured_t _SdkIsAIObscured;
	SdkIsAIKillable_t _SdkIsAIKillable;
	SdkGetAIArmor_t _SdkGetAIArmor;
	SdkGetAILethality_t _SdkGetAILethality;
	SdkGetAIArmorPenetration_t _SdkGetAIArmorPenetration;
	SdkGetAIAttackSpeed_t _SdkGetAIAttackSpeed;
	SdkGetAIAbilityPower_t _SdkGetAIAbilityPower;
	SdkGetAIAttackDamage_t _SdkGetAIAttackDamage;
	SdkGetAIAttackRange_t _SdkGetAIAttackRange;
	SdkGetAIMagicResist_t _SdkGetAIMagicResist;
	SdkGetAITenacity_t _SdkGetAITenacity;
	SdkGetAIMovementSpeed_t _SdkGetAIMovementSpeed;
	SdkGetAICritChance_t _SdkGetAICritChance;
	SdkGetAICritDamageMultiplier_t _SdkGetAICritDamageMultiplier;
	SdkGetAIDodgeChance_t _SdkGetAIDodgeChance;
	SdkGetAIHealthRegen_t _SdkGetAIHealthRegen;
	SdkGetAIMagicPenetration_t _SdkGetAIMagicPenetration;
	SdkGetAILifeSteal_t _SdkGetAILifeSteal;
	SdkGetAISpellVamp_t _SdkGetAISpellVamp;
	SdkGetAIAbilityResourceRegen_t _SdkGetAIAbilityResourceRegen;
	SdkGetAICooldownReduction_t _SdkGetAICooldownReduction;
	SdkIsAIBot_t _SdkIsAIBot;
	SdkGetAIGold_t _SdkGetAIGold;
	SdkEnumAIBuffs_t _SdkEnumAIBuffs;
	SdkAbilityResourceToString_t _SdkAbilityResourceToString;
	SdkBuffToString_t _SdkBuffToString;
	SdkGetAICombatType_t _SdkGetAICombatType;
	SdkGetAISpell_t _SdkGetAISpell;
	SdkGetAIDeathDuration_t _SdkGetAIDeathDuration;
	SdkIsAIAttacking_t _SdkIsAIAttacking;
	SdkIsAIMoving_t _SdkIsAIMoving;
	SdkIsObjectHero_t _SdkIsObjectHero;
	SdkGetHeroExperience_t _SdkGetHeroExperience;
	SdkGetHeroNeutralKills_t _SdkGetHeroNeutralKills;
	SdkIsObjectMinion_t _SdkIsObjectMinion;
	SdkGetMinionSpawnTime_t _SdkGetMinionSpawnTime;
	SdkGetMinionCampNumber_t _SdkGetMinionCampNumber;
	SdkIsMinionLaneMinion_t _SdkIsMinionLaneMinion;
	SdkGetMinionType_t _SdkGetMinionType;
	SdkGetMinionLevel_t _SdkGetMinionLevel;
	SdkIsMinionWard_t _SdkIsMinionWard;
	SdkIsObjectTurret_t _SdkIsObjectTurret;
	SdkGetTurretInfo_t _SdkGetTurretInfo;
	SdkIsObjectSpellMissile_t _SdkIsObjectSpellMissile;
	SdkWorldToScreen_t _SdkWorldToScreen;
	SdkStopLocalPlayer_t _SdkStopLocalPlayer;
	SdkMoveLocalPlayer_t _SdkMoveLocalPlayer;
	SdkAttackTargetLocalPlayer_t _SdkAttackTargetLocalPlayer;
	SdkUiInputText_t _SdkUiInputText;
	SdkAttackMoveLocalPlayer_t _SdkAttackMoveLocalPlayer;
	SdkCastSpellLocalPlayer_t _SdkCastSpellLocalPlayer;
	SdkUiInputNumber_t _SdkUiInputNumber;
	SdkMoveMouse_t _SdkMoveMouse;
	SdkGetGameTime_t _SdkGetGameTime;
	SdkLevelSpellLocalPlayer_t _SdkLevelSpellLocalPlayer;
	SdkShowEmoteLocalPlayer_t _SdkShowEmoteLocalPlayer;
	SdkSendChatLocalPlayer_t _SdkSendChatLocalPlayer;
	SdkUiInputMultiLineText_t _SdkUiInputMultiLineText;
	SdkDrawText_t _SdkDrawText;
	SdkSetSettingString_t _SdkSetSettingString;
	SdkGetSettingString_t _SdkGetSettingString;
	SdkSetSettingBool_t _SdkSetSettingBool;
	SdkGetSettingBool_t _SdkGetSettingBool;
	SdkSetSettingFloat_t _SdkSetSettingFloat;
	SdkGetSettingFloat_t _SdkGetSettingFloat;
	SdkSetSettingNumber_t _SdkSetSettingNumber;
	SdkGetSettingNumber_t _SdkGetSettingNumber;
	SdkGetMinionVisionRadius_t _SdkGetMinionVisionRadius;
	SdkPingMap_t _SdkPingMap;
	SdkDisableInput_t _SdkDisableInput;
	SdkEnableInput_t _SdkEnableInput;
	SdkGetD3DDevice_t _SdkGetD3DDevice;
	SdkWorldToMinimap_t _SdkWorldToMinimap;
	SdkGetObjectVelocity_t _SdkGetObjectVelocity;
	SdkGetObjectAcceleration_t _SdkGetObjectAcceleration;
	SdkRegisterGameObjectCreate_t _SdkRegisterGameObjectCreate;
	SdkRegisterGameObjectDelete_t _SdkRegisterGameObjectDelete;
} SDK_CONTEXT, *PSDK_CONTEXT;

//
// The version of the sdkapi header that the module was built with. 
// This value is passed to the SdkNotifyLoadedModule function to
// ensure that versions are compatible at runtime.
//
#define SDK_VERSION 2

//
// The symbolic name of the SDK context. This name is not very 
// important and doesn't need to be changed cross module.
//
#define SDK_CONTEXT_GLOBAL _g_SdkContext

//++
//
// VOID
// SDK_EXTRACT_CONTEXT(
//		_In_ PVOID lpvReserved
// )
//
// Routine Description:
//
//		The SDK_EXTRACT_CONTEXT macro takes in the lpvReserved parameter
//		from your module's entry point (DllMain). It extracts the pointer
//		to the SDK_CONTEXT data structure and stores it in the global
//		symbol defined by the SDK_CONTEXT_GLOBAL macro.
//
// Arguments:
//
//		lpvReserved - Contains a pointer to the SDK_CONTEXT structure 
//			that can be retrieved via the SDK_EXTRACT_CONTEXT macro. This
//			structure contains all the necessary function pointers 
//			required to interface with the Rift SDK.
//
// Return Value:
//
//		None.
//
//--
#define SDK_EXTRACT_CONTEXT(lpvReserved) SDK_CONTEXT_GLOBAL = ((PSDK_CONTEXT)(*(void**)lpvReserved))

//++
//
// SDKSTATUS
// SdkNotifyLoadedModule(
//		_In_ const char* ModuleName,
//		_In_ unsigned int SdkVersion
// )
//
// Routine Description:
//
//		This function should be called very early in your module entry
//		point. This allows you to interface with other SDK API.
//
// Arguments:
//
//		ModuleName - A unique name for the loaded module. If there's
//			already a module of the same name loaded in memory, the 
//			function will fail with the status code 
//			SDKSTATUS_MODULE_ALREADY_LOADED.
//
//		SdkVersion - Pass in the SDK_VERSION macro. This ensures that
//			the SDK, which is loaded in memory, is compatible with the
//			version of the sdkapi header that your module was built with.
//			On error, the status code SDKSTATUS_MODULE_VERSION_INCOMPATIBLE
//			is returned.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkNotifyLoadedModule(ModuleName, SdkVersion) SDK_CONTEXT_GLOBAL->_SdkNotifyLoadedModule(ModuleName, SdkVersion)

//++
//
// SDKSTATUS
// SdkUiConsoleWrite(
//		_In_ const char* Format,
//		...
// )
//
// Routine Description:
//
//		This function logs a message to the Rift console which is
//		only visible when the cheat overlay is up.
//
// Arguments:
//
//		Format - A C-style format string.
//
//		... - Variadic arguments.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiConsoleWrite(Format, ...) SDK_CONTEXT_GLOBAL->_SdkConsoleWrite(Format, __VA_ARGS__)

//++
//
// SDKSTATUS
// SdkUiConsoleClear(
//		void
// )
//
// Routine Description:
//
//		This function clears all the messages from the Rift console.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiConsoleClear() SDK_CONTEXT_GLOBAL->_SdkConsoleClear()

//++
//
// SDKSTATUS
// SdkGetLocalPlayer(
//		_Out_ void** Player 
// )
//
// Routine Description:
//
//		This function retrieves the local player's hero (champion) object.
//
// Arguments:
//
//		Player - Stores the pointer to the local player object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetLocalPlayer(Player) SDK_CONTEXT_GLOBAL->_SdkGetLocalPlayer(Player)

//++
//
// SDKSTATUS
// SdkGetAISkinID(
//		_In_ void* AI,
//		_Out_ int* SkinID
// )
//
// Routine Description:
//
//		This function retrieves the current visual skin of an artificially 
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		SkinID - Stores the current skin ID of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAISkinID(AI, SkinID) SDK_CONTEXT_GLOBAL->_SdkGetAISkinID(AI, SkinID)

//++
//
// SDKSTATUS
// SdkUiBeginCombo(
//		_In_ const char* Label,
//		_In_ const char* PreviewValue,
//		_Out_opt_ bool* Clicked
// )
//
// Routine Description:
//
//		This function creates a combo box UI element.
//
// Arguments:
//
//		Label - The name of the combo box.
//
//		PreviewValue - The initial item.
//
//		Clicked - Whether or not the combo box was clicked.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBeginCombo(Label, PreviewValue, Clicked) SDK_CONTEXT_GLOBAL->_SdkUiBeginCombo(Label, PreviewValue, Clicked)

//++
//
// SDKSTATUS
// SdkUiEndCombo(
//		void
// )
//
// Routine Description:
//
//		This function completes a previous call to SdkUiBeginCombo.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiEndCombo() SDK_CONTEXT_GLOBAL->_SdkUiEndCombo()

//++
//
// SDKSTATUS
// SdkUiAddSelection(
//		_In_ const char* Label,
//		_In_ bool Selected,
//		_Out_opt_ bool* Clicked
// )
//
// Routine Description:
//
//		This function adds an item into a combo box.
//
// Arguments:
//
//		Label - The name of the item.
//
//		Selected - Whether the item is currently selected.
//
//		Clicked - Whether or not the item was clicked.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiAddSelection(Label, Selected, Clicked) SDK_CONTEXT_GLOBAL->_SdkUiAddSelection(Label, Selected, Clicked)

//++
//
// SDKSTATUS
// SdkUiSetItemDefaultFocus(
//		void
// )
//
// Routine Description:
//
//		This function sets focus to the selected item in a combo box.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiSetItemDefaultFocus() SDK_CONTEXT_GLOBAL->_SdkUiSetItemDefaultFocus()

//++
//
// SDKSTATUS
// SdkUiText(
//		_In_ const char* Format,
//		...
// )
//
// Routine Description:
//
//		This function creates a text UI element.
//
// Arguments:
//
//		Format - A C-style format string.
//
//		... - Variadic arguments.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiText(Format, ...) SDK_CONTEXT_GLOBAL->_SdkUiText(Format, __VA_ARGS__)

//++
//
// SDKSTATUS
// SdkUiButton(
//		_In_ const char* Label,
//		_Out_opt_ bool* Clicked
// )
//
// Routine Description:
//
//		This function creates a button UI element.
//
// Arguments:
//
//		Label - The name of the button.
//
//		Clicked - Whether or not the button was clicked.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiButton(Label, Clicked) SDK_CONTEXT_GLOBAL->_SdkUiButton(Label, Clicked)

//++
//
// SDKSTATUS
// SdkSetAISkinID(
//		_In_ void* AI,
//		_In_ int SkinID
// )
//
// Routine Description:
//
//		This function sets the current visual skin of an artificially 
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		SkinID - The desired skin ID.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSetAISkinID(AI, SkinID) SDK_CONTEXT_GLOBAL->_SdkSetAISkinID(AI, SkinID)

//++
//
// SDKSTATUS
// SdkRegisterOverlayScene(
//		_In_ RENDERSCENECALLBACK Scene,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function registers a callback that is invoked every frame
//		when the overlay is visible.
//
// Arguments:
//
//		Scene - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkRegisterOverlayScene(Scene, UserData) SDK_CONTEXT_GLOBAL->_SdkRegisterOverlayScene(Scene, UserData)

//++
//
// SDKSTATUS
// SdkEnumChampionSkinNames(
//		_In_ const char* ChampionName,
//		_In_ CHAMPIONSKINNAMESCALLBACK Callback,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function enumerates all available skins for a given hero
//		(champion) name.
//
// Arguments:
//
//		ChampionName - The name of the hero we're enumerating skins for.
//
//		Callback - The user-defined callback that is invoked for each skin
//			that the target hero has.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkEnumChampionSkinNames(ChampionName, Callback, UserData) SDK_CONTEXT_GLOBAL->_SdkEnumChampionSkinNames(ChampionName, Callback, UserData)

//++
//
// SDKSTATUS
// SdkGetAIName(
//		_In_ void* AI,
//		_Out_ const char** Name
// )
//
// Routine Description:
//
//		This function retrieves the current name of an artificially 
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Name - Stores a pointer to the name of the object on success.
//
//			WARNING: To avoid object life-time issues, duplicate this 
//			string if you need to access it past the frame in which
//			it was retrieved.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIName(AI, Name) SDK_CONTEXT_GLOBAL->_SdkGetAIName(AI, Name)

//++
//
// SDKSTATUS
// SdkUiForceOnSameLine(
//		void
// )
//
// Routine Description:
//
//		This function forces the next UI element to be drawn on the
//		same line as the previous. This overrides the default behavior
//		in which each UI element appears on a new line.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiForceOnSameLine() SDK_CONTEXT_GLOBAL->_SdkUiForceOnSameLine()

//++
//
// SDKSTATUS
// SdkUiSetNextWindowPos(
//		_In_ PSDKPOINT Position
// )
//
// Routine Description:
//
//		This function forces the next window UI element to be at the
//		given position.
//
// Arguments:
//
//		Position - The position, relative to the parent window, where the
//			new window will appear.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiSetNextWindowPos(Position) SDK_CONTEXT_GLOBAL->_SdkUiSetNextWindowPos(Position)

//++
//
// SDKSTATUS
// SdkUiGetWindowDim(
//		_Out_ PSDKPOINT Position,
//		_Out_ PSDKPOINT Size
// )
//
// Routine Description:
//
//		This function retrieves the position and the size of the current
//		window.
//
// Arguments:
//
//		Position - The position, relative to the parent window.
//
//		Size - The size of the window.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiGetWindowDim(Position, Size) SDK_CONTEXT_GLOBAL->_SdkUiGetWindowDim(Position, Size)

//++
//
// SDKSTATUS
// SdkUiBeginWindow(
//		_In_ const char* WindowName,
//		_Inout_ bool* Visible,
//		_Out_opt_ bool* Collapsed
// )
//
// Routine Description:
//
//		This function creates a window UI element.
//
// Arguments:
//
//		WindowName - The name of the window.
//
//		Visible - Whether or not the window is currently visible.
//
//		Collapsed - Whether or not the window is currently collapsed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBeginWindow(WindowName, Visible, Collapsed) SDK_CONTEXT_GLOBAL->_SdkUiBeginWindow(WindowName, Visible, Collapsed)

//++
//
// SDKSTATUS
// SdkUiEndWindow(
//		void
// )
//
// Routine Description:
//
//		This function completes a previous call to SdkUiBeginWindow.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiEndWindow() SDK_CONTEXT_GLOBAL->_SdkUiEndWindow()

//++
//
// SDKSTATUS
// SdkUiInputPoint(
//		_In_ const char* Label,
//		_Inout_ PSDKPOINT Point,
//		_In_ int Precision,
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates two floating-point input box UI elements.
//
// Arguments:
//
//		Label - The name of the input boxes.
//
//		Point - The numeric values (x, y) of the boxes.
//
//		Precision - Number of decimals.
//
//		Changed - Whether or not an input box was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputPoint(Label, Point, Precision, Changed) SDK_CONTEXT_GLOBAL->_SdkUiInputPoint(Label, Point, Precision, Changed)

//++
//
// SDKSTATUS
// SdkUiInputVector(
//		_In_ const char* Label,
//		_Inout_ PSDKVECTOR Vector,
//		_In_ int Precision,
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates three floating-point input box UI elements.
//
// Arguments:
//
//		Label - The name of the input boxes.
//
//		Vector - The numeric values (x, y, z) of the boxes.
//
//		Precision - Number of decimals.
//
//		Changed - Whether or not an input box was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputVector(Label, Vector, Precision, Changed) SDK_CONTEXT_GLOBAL->_SdkUiInputVector(Label, Vector, Precision, Changed)

//++
//
// SDKSTATUS
// SdkUiCheckbox(
//		_In_ const char* Label,
//		_Inout_ bool* Checked,
//		_Out_opt_ bool* Clicked
// )
//
// Routine Description:
//
//		This function creates a check box UI element.
//
// Arguments:
//
//		Label - The name of the check box.
//
//		Checked - Whether or not the check box is currently checked.
//
//		Clicked - Whether or not the check box was clicked.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiCheckbox(Label, Checked, Clicked) SDK_CONTEXT_GLOBAL->_SdkUiCheckbox(Label, Checked, Clicked)

//++
//
// SDKSTATUS
// SdkUiGetWindow(
//		_Out_ HWND* Window
// )
//
// Routine Description:
//
//		This function returns a handle to the primary game window.
//
// Arguments:
//
//		Window - Stores the handle to the window on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiGetWindow(Window) SDK_CONTEXT_GLOBAL->_SdkUiGetWindow(Window)

//++
//
// SDKSTATUS
// SdkScreenToWorld(
//		_In_ PSDKPOINT ScreenPoint,
//		_Out_ PSDKVECTOR WorldCoordinates
// )
//
// Routine Description:
//
//		This function converts a set of screen points (x, y) to
//		world coordinates (x, y, z).
//
// Arguments:
//
//		ScreenPoint - Input (x, y) coordinates.
//
//		WorldCoordinates - Output (x, y, z) coordinates.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkScreenToWorld(ScreenPoint, WorldCoordinates) SDK_CONTEXT_GLOBAL->_SdkScreenToWorld(ScreenPoint, WorldCoordinates)

//++
//
// SDKSTATUS
// SdkUiColorPicker(
//		_In_ const char* Label,
//		_In_out_ PSDKVECTOR Color,
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates a color picker UI element.
//
// Arguments:
//
//		Label - The name of the color picker.
//
//		Color - The currently selected color on the wheel.
//
//		Changed - Whether or not the color wheel was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiColorPicker(Label, Color, Changed) SDK_CONTEXT_GLOBAL->_SdkUiColorPicker(Label, Color, Changed)

//++
//
// SDKSTATUS
// SdkUiSmallButton(
//		_In_ const char* Label,
//		_Out_opt_ bool* Clicked
// )
//
// Routine Description:
//
//		This function creates a small button UI element.
//
// Arguments:
//
//		Label - The name of the small button.
//
//		Clicked - Whether or not the small button was clicked.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiSmallButton(Label, Clicked) SDK_CONTEXT_GLOBAL->_SdkUiSmallButton(Label, Clicked)

//++
//
// SDKSTATUS
// SdkGetObjectPosition(
//		_In_ void* Object,
//		_Out_ PSDKVECTOR Position
// )
//
// Routine Description:
//
//		This function retrieves the world position of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Position - Stores the world position (x, y, z) of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectPosition(Object, Position) SDK_CONTEXT_GLOBAL->_SdkGetObjectPosition(Object, Position)

//++
//
// SDKSTATUS
// SdkUiInputFloat(
//		_In_ const char* Label,
//		_Inout_ float* Value,
//		_In_ int Precision,
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates a floating-point input box UI element.
//
// Arguments:
//
//		Label - The name of the input box.
//
//		Value - The numeric value of the box.
//
//		Precision - Number of decimals.
//
//		Changed - Whether or not the input box was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputFloat(Label, Value, Precision, Changed) SDK_CONTEXT_GLOBAL->_SdkUiInputFloat(Label, Value, Precision, Changed)

//++
//
// SDKSTATUS
// SdkUiColoredText(
//		_In_ PSDKCOLOR Color,
//		_In_ const char* Format,
//		...
// )
//
// Routine Description:
//
//		This function creates a colored text UI element.
//
// Arguments:
//
//		Color - The desired BGRA color of the string.
//
//		Format - A C-style format string.
//
//		... - Variadic arguments.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiColoredText(Color, Format, ...) SDK_CONTEXT_GLOBAL->_SdkUiColoredText(Color, Format, __VA_ARGS__)

//++
//
// SDKSTATUS
// SdkUiDragFloat(
//		_In_ const char* Label, 
//		_Inout_ float* Value, 
//		_In_ float Min, 
//		_In_ float Max, 
//		_In_ const char* Format, 
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates a drag float UI element.
//
// Arguments:
//
//		Label - The name of the drag float.
//
//		Value - The numeric value of the control.
//
//		Min - The minimum value of the float.
//
//		Max - The maximum value of the float.
//
//		Format - The formatting of the displayed floating point value.
//
//		Changed - Whether or not the drag float was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiDragFloat(Label, Value, Min, Max, Format, Changed) SDK_CONTEXT_GLOBAL->_SdkUiDragFloat(Label, Value, Min, Max, Format, Changed)

//++
//
// SDKSTATUS
// SdkUiCombo(
//		_In_ const char* Label, 
//		_Inout_  int* Selection, 
//		_In_ const char* const* Items, 
//		_In int Entries, 
//		_Out_opt_ bool* Changed)
//
// Routine Description:
//
//		This function creates a combo box UI element.
//
// Arguments:
//
//		Label - The name of the combo box.
//
//		Selection - The index of the selected item.
//
//		Items - A list of entries, where each entry is a NULL 
//			terminated string.
//
//		Entries - The number of items.
//
//		Changed - Whether or not the combo box was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiCombo(Label, Selection, Items, Entries, Changed) SDK_CONTEXT_GLOBAL->_SdkUiCombo(Label, Selection, Items, Entries, Changed)

//++
//
// SDKSTATUS
// SdkUiBeginTree(
//		_In_ const char* Label, 
//		_Out_opt_ bool* Expanded)
//
// Routine Description:
//
//		This function creates an expandable tree UI element.
//
// Arguments:
//
//		Label - The name of the tree.
//
//		Expanded - Whether or not the tree was expanded.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBeginTree(Label, Expanded) SDK_CONTEXT_GLOBAL->_SdkUiBeginTree(Label, Expanded)

//++
//
// SDKSTATUS
// SdkUiEndTree(
//		void)
//
// Routine Description:
//
//		This function completes a previous call to SdkUiBeginTree
//		or SdkUiBeginTreeEx.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiEndTree() SDK_CONTEXT_GLOBAL->_SdkUiEndTree()

//++
//
// SDKSTATUS
// SdkUiBeginTreeEx(
//		_Out_opt bool* Expanded, 
//		_In_ const void* Id,
//		_In_ const char* Format,
//		...)
//
// Routine Description:
//
//		This function creates an expandable tree UI element.
//
// Arguments:
//
//		Expanded - Whether or not the tree was expanded.
//
//		Id - A unique identifier for the tree. Use this function
//			instead of SdkUiBeginTree when you have colliding labels.
//
//		Format - A C-style format string.
//
//		... - Variadic arguments.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBeginTreeEx(Expanded, Id, Format, ...) SDK_CONTEXT_GLOBAL->_SdkUiBeginTreeEx(Expanded, Id, Format, __VA_ARGS__)

//++
//
// SDKSTATUS
// SdkUiBulletText(
//		_In_ const char* Format,
//		...
// )
//
// Routine Description:
//
//		This function creates a text UI element that has a bullet
//		point preceding its content.
//
// Arguments:
//
//		Format - A C-style format string.
//
//		... - Variadic arguments.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBulletText(Format, ...) SDK_CONTEXT_GLOBAL->_SdkUiBulletText(Format, __VA_ARGS__)

//++
//
// SDKSTATUS
// SdkUiBulletPoint(
//		void)
//
// Routine Description:
//
//		This function inserts a bullet point before the next UI 
//		control.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiBulletPoint() SDK_CONTEXT_GLOBAL->_SdkUiBulletPoint()

//++
//
// SDKSTATUS
// SdkRegisterGameScene(
//		_In_ RENDERSCENECALLBACK Scene,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function registers a callback that is invoked every frame.
//
// Arguments:
//
//		Scene - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkRegisterGameScene(Scene, UserData) SDK_CONTEXT_GLOBAL->_SdkRegisterGameScene(Scene, UserData)

//++
//
// SDKSTATUS
// SdkDrawLine(
//		_In_ PSDKVECTOR StartWorld, 
//		_In_ PSDKVECTOR EndWorld, 
//		_In_ float Width, 
//		_In_ PSDKCOLOR Color, 
//		_In_ int Texture
// )
//
// Routine Description:
//
//		This function draws a 3D line on the game frame.
//
// Arguments:
//
//		StartWorld - The starting world (in-game) position (x, y, z)
//			of the line.
//
//		EndWorld - The ending world (in-game) position (x, y, z)
//			of the line.
//			
//		Width - The line thickness.
//
//		Color - The desired BGRA color of the line.
//
//		Texture - The style of line to draw.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkDrawLine(StartWorld, EndWorld, Width, Color, Texture) SDK_CONTEXT_GLOBAL->_SdkDrawLine(StartWorld, EndWorld, Width, Color, Texture)

//++
//
// SDKSTATUS
// SdkDrawCircle(
//		_In_ PSDKVECTOR OriginWorld, 
//		_In_ float Radius, 
//		_In_ PSDKCOLOR Color, 
//		_In_ int Texture,
//		_In_ PSDKVECTOR Direction
// )
//
// Routine Description:
//
//		This function draws a 3D circle on the game frame.
//
// Arguments:
//
//		OriginWorld - The center position (x, y, z) in world 
//			(in-game) coordinates of the circle.
//
//		Radius - The radius of the circle.
//			
//		Color - The desired BGRA color of the circle.
//
//		Texture - The style of circle to draw.
//
//		Direction - The direction of the circle's expansion
//			(x, y, z).
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkDrawCircle(OriginWorld, Radius, Color, Texture, Direction) SDK_CONTEXT_GLOBAL->_SdkDrawCircle(OriginWorld, Radius, Color, Texture, Direction)

//++
//
// SDKSTATUS
// SdkDrawCone(
//		_In_ PSDKVECTOR OriginWorld, 
//		_In_ float Length, 
//		_In_ float Angle,
//		_In_ PSDKVECTOR Direction,
//		_In_ PSDKCOLOR Color, 
//		_In_ int Texture
// )
//
// Routine Description:
//
//		This function draws a 3D cone on the game frame.
//
// Arguments:
//
//		OriginWorld - The center position (x, y, z) in world 
//			(in-game) coordinates of the cone.
//
//		Length - The length of the cone.
//			
//		Angle - The angle of the cone.
//
//		Direction - The direction of the cone's expansion
//			(x, y, z).
//
//		Color - The desired BGRA color of the cone.
//
//		Texture - The style of circle to cone.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkDrawCone(OriginWorld, Length, Angle, Direction, Color, Texture) SDK_CONTEXT_GLOBAL->_SdkDrawCone(OriginWorld, Length, Angle, Direction, Color, Texture)

//++
//
// SDKSTATUS
// SdkGetNumberOfGameObjects(
//		_Out_ int* NumberOfObjects 
// )
//
// Routine Description:
//
//		This function returns the number of game objects in the
//		world.
//
// Arguments:
//
//		NumberOfObjects - Stores the number of game objects in this
//			frame upon success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetNumberOfGameObjects(NumberOfObjects) SDK_CONTEXT_GLOBAL->_SdkGetNumberOfGameObjects(NumberOfObjects)

//++
//
// SDKSTATUS
// SdkEnumGameObjects(
//		_In_ GAMEOBJECTSCALLBACK Callback,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function invokes your user-defined callback for each game
//		object that is present in the world for this frame.
//
// Arguments:
//
//		Callback - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkEnumGameObjects(Callback, UserData) SDK_CONTEXT_GLOBAL->_SdkEnumGameObjects(Callback, UserData)

//++
//
// SDKSTATUS
// SdkGetObjectTypeFlags(
//		_In_ void* Object,
//		_Out_ int* TypeFlags
// )
//
// Routine Description:
//
//		This function retrieves the type flags for a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		TypeFlags - Stores the type flags of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectTypeFlags(Object, TypeFlags) SDK_CONTEXT_GLOBAL->_SdkGetObjectTypeFlags(Object, TypeFlags)

//++
//
// SDKSTATUS
// SdkGetObjectTypeName(
//		_In_ void* Object,
//		_Out_ const char** TypeName
// )
//
// Routine Description:
//
//		This function retrieves the type name for a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Name - Stores a pointer to the type name of the object on success.
//
//			WARNING: To avoid object life-time issues, duplicate this 
//			string if you need to access it past the frame in which
//			it was retrieved.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectTypeName(Object, TypeName) SDK_CONTEXT_GLOBAL->_SdkGetObjectTypeName(Object, TypeName)

//++
//
// SDKSTATUS
// SdkGetObjectID(
//		_In_ void* Object,
//		_Out_ unsigned int* ID
// )
//
// Routine Description:
//
//		This function retrieves the ID of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		ID - Stores the unique ID of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectID(Object, ID) SDK_CONTEXT_GLOBAL->_SdkGetObjectID(Object, ID)

//++
//
// SDKSTATUS
// SdkGetObjectTeamID(
//		_In_ void* Object,
//		_Out_ int* TeamID
// )
//
// Routine Description:
//
//		This function retrieves the team ID of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		TeamID - Stores the team ID of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectTeamID(Object, TeamID) SDK_CONTEXT_GLOBAL->_SdkGetObjectTeamID(Object, TeamID)

//++
//
// SDKSTATUS
// SdkIsObjectZombie(
//		_In_ void* Object,
//		_Out_ bool* Zombie
// )
//
// Routine Description:
//
//		This function retrieves the zombie state of a game object.
//		Zombies are considered pseudo-dead game objects. Examples 
//		include Karthas and Kog'maw upon being killed. Zombies can 
//		be controlled before truly dying and having to wait for 
//		respawn.
//
// Arguments:
//
//		Object - The game object.
//
//		Zombie - Stores the zombie state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectZombie(Object, Zombie) SDK_CONTEXT_GLOBAL->_SdkIsObjectZombie(Object, Zombie)

//++
//
// SDKSTATUS
// SdkIsObjectDead(
//		_In_ void* Object,
//		_Out_ bool* Dead
// )
//
// Routine Description:
//
//		This function retrieves the dead state of a game object.
//		Dead game objects cannot be controlled. 
//
// Arguments:
//
//		Object - The game object.
//
//		Dead - Stores the dead state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectDead(Object, Dead) SDK_CONTEXT_GLOBAL->_SdkIsObjectDead(Object, Dead)

//++
//
// SDKSTATUS
// SdkGetObjectName(
//		_In_ void* Object,
//		_Out_ const char** Name
// )
//
// Routine Description:
//
//		This function retrieves the name of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Name - Stores a pointer to the name of the object on success.
//
//			WARNING: To avoid object life-time issues, duplicate this 
//			string if you need to access it past the frame in which
//			it was retrieved.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectName(Object, Name) SDK_CONTEXT_GLOBAL->_SdkGetObjectName(Object, Name)

//++
//
// SDKSTATUS
// SdkGetObjectOrientation(
//		_In_ void* Object,
//		_Out_ PSDKVECTOR Orientation
// )
//
// Routine Description:
//
//		This function retrieves the orientation of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Orientation - Stores the orientation (x, y, z) of the object
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectOrientation(Object, Orientation) SDK_CONTEXT_GLOBAL->_SdkGetObjectOrientation(Object, Orientation)

//++
//
// SDKSTATUS
// SdkGetObjectBoundingBox(
//		_In_ void* Object,
//		_Out_ PSDKBOX BBox
// )
//
// Routine Description:
//
//		This function retrieves the bounding box of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Orientation - Stores the bounding box { (x0, y0, z0) (x1, y1, z1) }
//			of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectBoundingBox(Object, BBox) SDK_CONTEXT_GLOBAL->_SdkGetObjectBoundingBox(Object, BBox)

//++
//
// SDKSTATUS
// SdkIsObjectVisibleOnScreen(
//		_In_ void* Object,
//		_Out_ bool* Visible
// )
//
// Routine Description:
//
//		This function retrieves the screen visibility state of a game 
//		object. An object is considered 'screen visible' if your GPU is
//		rendering the object. Objects in fog-of-war and objects that are
//		visible but not screen visible have this field set to false.
//
// Arguments:
//
//		Object - The game object.
//
//		Visible - Stores the screen visibility state of the object on
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectVisibleOnScreen(Object, Visible) SDK_CONTEXT_GLOBAL->_SdkIsObjectVisibleOnScreen(Object, Visible)

//++
//
// SDKSTATUS
// SdkGetObjectRespawns(
//		_In_ void* Object,
//		_Out_ unsigned int* Respawns
// )
//
// Routine Description:
//
//		This function retrieves the respawn count of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Respawns - Stores the number of respawns for the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectRespawns(Object, Respawns) SDK_CONTEXT_GLOBAL->_SdkGetObjectRespawns(Object, Respawns)

//++
//
// SDKSTATUS
// SdkIsObjectUnit(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also an attackable unit object. Otherwise, this 
//		function returns SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectUnit(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectUnit(Object)

//++
//
// SDKSTATUS
// SdkIsUnitVisible(
//		_In_ void* Unit,
//		_Out_ bool* Visible
// )
//
// Routine Description:
//
//		This function retrieves the visibility state of an attackable
//		unit. An object is considered 'visible' if it is not in the
//		fog-of-war, even if you're unable to see them on your screen.
//
// Arguments:
//
//		Unit - The attackable unit.
//
//		Visible - Stores the visibility state of the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsUnitVisible(Unit, Visible) SDK_CONTEXT_GLOBAL->_SdkIsUnitVisible(Unit, Visible)

//++
//
// SDKSTATUS
// SdkGetUnitDeathTime(
//		_In_ void* Unit,
//		_Out_ float* Time
// )
//
// Routine Description:
//
//		This function retrieves the time of death of an attackable
//		unit.
//
// Arguments:
//
//		Unit - The attackable unit.
//
//		Time - Stores the time of death of the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetUnitDeathTime(Unit, Time) SDK_CONTEXT_GLOBAL->_SdkGetUnitDeathTime(Unit, Time)

//++
//
// SDKSTATUS
// SdkGetUnitAbilityResource(
//		_In_ void* Unit,
//		_In_ unsigned char Slot,
//		_Out_ PSDK_ABILITY_RESOURCE AbilityResource
// )
//
// Routine Description:
//
//		This function retrieves an attackable unit's ability
//		resource information. This can be mana, energy, or rage
//		state.
//
// Arguments:
//
//		Unit - The attackable unit.
//
//		Slot - Currently, only ABILITY_SLOT_PRIMARY and 
//			ABILITY_SLOT_SECONDARY are allowed for input.
//
//		AbilityResource - Stores information regarding the ability 
//			resource of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetUnitAbilityResource(Unit, Slot, AbilityResource) SDK_CONTEXT_GLOBAL->_SdkGetUnitAbilityResource(Unit, Slot, AbilityResource)

//++
//
// SDKSTATUS
// SdkGetUnitIsMouseOver(
//		_In_ void* Unit,
//		_Out_ bool* MouseOver
// )
//
// Routine Description:
//
//		This function retrieves the mouse over state of an
//		attackable unit. Specifically, if the mouse cursor is
//		over the attackable unit, this value will be true.
//
// Arguments:
//
//		Unit - The attackable unit.
//
//		MouseOver - Stores the mouse over state of the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetUnitIsMouseOver(Unit, MouseOver) SDK_CONTEXT_GLOBAL->_SdkGetUnitIsMouseOver(Unit, MouseOver)

//++
//
// SDKSTATUS
// SdkGetUnitHealth(
//		_In_ void* Unit,
//		_Out_ PSDK_HEALTH Health
// )
//
// Routine Description:
//
//		This function retrieves an attackable unit's health
//		information.
//
// Arguments:
//
//		Unit - The attackable unit.
//
//		Health - Stores information regarding the health of the
//			the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetUnitHealth(Unit, Health) SDK_CONTEXT_GLOBAL->_SdkGetUnitHealth(Unit, Health)

//++
//
// SDKSTATUS
// SdkIsObjectAI(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also an artificially intelligent object. Otherwise, 
//		this function returns SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectAI(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectAI(Object)

//++
//
// SDKSTATUS
// SdkIsAIPlayerControlled(
//		_In_ void* AI,
//		_Out_ bool* Human
// )
//
// Routine Description:
//
//		This function retrieves whether or not this artificially
//		intelligent object is controlled by a player.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Human - Stores the controlled by player state of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIPlayerControlled(AI, Human) SDK_CONTEXT_GLOBAL->_SdkIsAIPlayerControlled(AI, Human)

//++
//
// SDKSTATUS
// SdkCanAIAttack(
//		_In_ void* AI,
//		_Out_ bool* Attack
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object can attack.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Attack - Stores the can attack state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkCanAIAttack(AI, Attack) SDK_CONTEXT_GLOBAL->_SdkCanAIAttack(AI, Attack)

//++
//
// SDKSTATUS
// SdkCanAICrit(
//		_In_ void* AI,
//		_Out_ bool* Crit
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object can crit.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Crit - Stores the can crit state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkCanAICrit(AI, Crit) SDK_CONTEXT_GLOBAL->_SdkCanAICrit(AI, Crit)

//++
//
// SDKSTATUS
// SdkCanAICast(
//		_In_ void* AI,
//		_Out_ bool* Cast
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object can cast spells.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Cast - Stores the can cast state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkCanAICast(AI, Cast) SDK_CONTEXT_GLOBAL->_SdkCanAICast(AI, Cast)

//++
//
// SDKSTATUS
// SdkCanAIMove(
//		_In_ void* AI,
//		_Out_ bool* Move
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object can move.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Move - Stores the can move state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkCanAIMove(AI, Move) SDK_CONTEXT_GLOBAL->_SdkCanAIMove(AI, Move)

//++
//
// SDKSTATUS
// SdkIsAIStealthed(
//		_In_ void* AI,
//		_Out_ bool* Stealthed
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is stealthed.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Stealthed - Stores the stealth state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIStealthed(AI, Stealthed) SDK_CONTEXT_GLOBAL->_SdkIsAIStealthed(AI, Stealthed)

//++
//
// SDKSTATUS
// SdkIsAITaunted(
//		_In_ void* AI,
//		_Out_ bool* Taunted
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is taunted.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Taunted - Stores the taunt state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAITaunted(AI, Taunted) SDK_CONTEXT_GLOBAL->_SdkIsAITaunted(AI, Taunted)

//++
//
// SDKSTATUS
// SdkIsAIFeared(
//		_In_ void* AI,
//		_Out_ bool* Feared
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is feared.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Feared - Stores the fear state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIFeared(AI, Feared) SDK_CONTEXT_GLOBAL->_SdkIsAIFeared(AI, Feared)

//++
//
// SDKSTATUS
// SdkIsAIFleeing(
//		_In_ void* AI,
//		_Out_ bool* Fleeing
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is fleeing.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Fleeing - Stores the flee state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIFleeing(AI, Fleeing) SDK_CONTEXT_GLOBAL->_SdkIsAIFleeing(AI, Fleeing)

//++
//
// SDKSTATUS
// SdkIsAISuppressed(
//		_In_ void* AI,
//		_Out_ bool* Suppressed
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is suppressed.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Suppressed - Stores the suppress state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAISuppressed(AI, Suppressed) SDK_CONTEXT_GLOBAL->_SdkIsAISuppressed(AI, Suppressed)

//++
//
// SDKSTATUS
// SdkIsAISleeping(
//		_In_ void* AI,
//		_Out_ bool* Sleeping
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is sleeping.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Sleeping - Stores the sleep state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAISleeping(AI, Sleeping) SDK_CONTEXT_GLOBAL->_SdkIsAISleeping(AI, Sleeping)

//++
//
// SDKSTATUS
// SdkIsAINearSighted(
//		_In_ void* AI,
//		_Out_ bool* NearSighted
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is near sighted.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		NearSighted - Stores the near sight state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAINearSighted(AI, NearSighted) SDK_CONTEXT_GLOBAL->_SdkIsAINearSighted(AI, NearSighted)

//++
//
// SDKSTATUS
// SdkIsAIGhosted(
//		_In_ void* AI,
//		_Out_ bool* Ghosted
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is ghosted (no unit collision).
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Ghosted - Stores the ghost state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIGhosted(AI, Ghosted) SDK_CONTEXT_GLOBAL->_SdkIsAIGhosted(AI, Ghosted)

//++
//
// SDKSTATUS
// SdkIsAICharmed(
//		_In_ void* AI,
//		_Out_ bool* Charmed
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is charmed.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Charmed - Stores the charm state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAICharmed(AI, Charmed) SDK_CONTEXT_GLOBAL->_SdkIsAICharmed(AI, Charmed)

//++
//
// SDKSTATUS
// SdkIsAISlowed(
//		_In_ void* AI,
//		_Out_ bool* Slowed
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is slowed.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Slowed - Stores the slow state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAISlowed(AI, Slowed) SDK_CONTEXT_GLOBAL->_SdkIsAISlowed(AI, Slowed)

//++
//
// SDKSTATUS
// SdkIsAISelectable(
//		_In_ void* AI,
//		_Out_ bool* Selectable
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is selectable.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Selectable - Stores the selectability state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAISelectable(AI, Selectable) SDK_CONTEXT_GLOBAL->_SdkIsAISelectable(AI, Selectable)

//++
//
// SDKSTATUS
// SdkIsAICritImmune(
//		_In_ void* AI,
//		_Out_ bool* CritImmune
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is immune to crits.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CritImmune - Stores the crit immune state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAICritImmune(AI, CritImmune) SDK_CONTEXT_GLOBAL->_SdkIsAICritImmune(AI, CritImmune)

//++
//
// SDKSTATUS
// SdkIsAIGrounded(
//		_In_ void* AI,
//		_Out_ bool* Grounded
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is grounded.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Grounded - Stores the grounded state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIGrounded(AI, Grounded) SDK_CONTEXT_GLOBAL->_SdkIsAIGrounded(AI, Grounded)

//++
//
// SDKSTATUS
// SdkIsAIObscured(
//		_In_ void* AI,
//		_Out_ bool* Obscured
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is obscured.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Obscured - Stores the obscured state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIObscured(AI, Obscured) SDK_CONTEXT_GLOBAL->_SdkIsAIObscured(AI, Obscured)

//++
//
// SDKSTATUS
// SdkIsAIKillable(
//		_In_ void* AI,
//		_Out_ bool* Killable
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is killable.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Killable - Stores the killable state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIKillable(AI, Killable) SDK_CONTEXT_GLOBAL->_SdkIsAIKillable(AI, Killable)

//++
//
// SDKSTATUS
// SdkGetAIArmor(
//		_In_ void* AI,
//		_Out_ float* Armor
// )
//
// Routine Description:
//
//		This function retrieves the current armor of the artificially
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Armor - Stores the current armor of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIArmor(AI, Armor) SDK_CONTEXT_GLOBAL->_SdkGetAIArmor(AI, Armor)

//++
//
// SDKSTATUS
// SdkGetAILethality(
//		_In_ void* AI,
//		_Out_ float* Lethality
// )
//
// Routine Description:
//
//		This function retrieves the lethality of the artificially
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Lethality - Stores the current lethality of the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAILethality(AI, Lethality) SDK_CONTEXT_GLOBAL->_SdkGetAILethality(AI, Lethality)

//++
//
// SDKSTATUS
// SdkGetAIArmorPenetration(
//		_In_ void* AI,
//		_Out_ float* ArmorPenetration
// )
//
// Routine Description:
//
//		This function retrieves the current armor penetration of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		ArmorPenetration - Stores the current armor penetration of 
//			the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIArmorPenetration(AI, ArmorPenetration) SDK_CONTEXT_GLOBAL->_SdkGetAIArmorPenetration(AI, ArmorPenetration)

//++
//
// SDKSTATUS
// SdkGetAIAttackSpeed(
//		_In_ void* AI,
//		_Out_ float* AttackSpeed
// )
//
// Routine Description:
//
//		This function retrieves the current attack speed of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		AttackSpeed - Stores the current attack speed of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIAttackSpeed(AI, AttackSpeed) SDK_CONTEXT_GLOBAL->_SdkGetAIAttackSpeed(AI, AttackSpeed)

//++
//
// SDKSTATUS
// SdkGetAIAbilityPower(
//		_In_ void* AI,
//		_Out_ float* AbilityPower
// )
//
// Routine Description:
//
//		This function retrieves the current ability power of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		AbilityPower - Stores the current ability power of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIAbilityPower(AI, AbilityPower) SDK_CONTEXT_GLOBAL->_SdkGetAIAbilityPower(AI, AbilityPower)

//++
//
// SDKSTATUS
// SdkGetAIAttackDamage(
//		_In_ void* AI,
//		_Out_ float* AttackDamage
// )
//
// Routine Description:
//
//		This function retrieves the current attack damage of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		AttackDamage - Stores the current attack damage of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIAttackDamage(AI, AttackDamage) SDK_CONTEXT_GLOBAL->_SdkGetAIAttackDamage(AI, AttackDamage)

//++
//
// SDKSTATUS
// SdkGetAIAttackRange(
//		_In_ void* AI,
//		_Out_ float* AttackRange
// )
//
// Routine Description:
//
//		This function retrieves the current attack range of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		AttackRange - Stores the current attack range of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIAttackRange(AI, AttackRange) SDK_CONTEXT_GLOBAL->_SdkGetAIAttackRange(AI, AttackRange)

//++
//
// SDKSTATUS
// SdkGetAIMagicResist(
//		_In_ void* AI,
//		_Out_ float* MagicResist
// )
//
// Routine Description:
//
//		This function retrieves the current magic resistance of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		MagicResist - Stores the current magic resistance of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIMagicResist(AI, MagicResist) SDK_CONTEXT_GLOBAL->_SdkGetAIMagicResist(AI, MagicResist)

//++
//
// SDKSTATUS
// SdkGetAITenacity(
//		_In_ void* AI,
//		_Out_ float* Tenacity
// )
//
// Routine Description:
//
//		This function retrieves the current tenacity of the 
//		artificially intelligent object. Tenacity reduces crowd
//		control duration.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Tenacity - Stores the current tenacity of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAITenacity(AI, Tenacity) SDK_CONTEXT_GLOBAL->_SdkGetAITenacity(AI, Tenacity)

//++
//
// SDKSTATUS
// SdkGetAIMovementSpeed(
//		_In_ void* AI,
//		_Out_ float* MovementSpeed
// )
//
// Routine Description:
//
//		This function retrieves the current movement speed of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		MovementSpeed - Stores the current movement speed of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIMovementSpeed(AI, MovementSpeed) SDK_CONTEXT_GLOBAL->_SdkGetAIMovementSpeed(AI, MovementSpeed)

//++
//
// SDKSTATUS
// SdkGetAICritChance(
//		_In_ void* AI,
//		_Out_ float* CritChance
// )
//
// Routine Description:
//
//		This function retrieves the current crit chance of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CritChance - Stores the current crit chance of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAICritChance(AI, CritChance) SDK_CONTEXT_GLOBAL->_SdkGetAICritChance(AI, CritChance)

//++
//
// SDKSTATUS
// SdkGetAICritDamageMultiplier(
//		_In_ void* AI,
//		_Out_ float* CritDamageMultiplier
// )
//
// Routine Description:
//
//		This function retrieves the current crit damage multiplier 
//		of the artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CritDamageMultiplier - Stores the current crit damage multiplier 
//			of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAICritDamageMultiplier(AI, CritDamageMultiplier) SDK_CONTEXT_GLOBAL->_SdkGetAICritDamageMultiplier(AI, CritDamageMultiplier)

//++
//
// SDKSTATUS
// SdkGetAIDodgeChance(
//		_In_ void* AI,
//		_Out_ float* DodgeChance
// )
//
// Routine Description:
//
//		This function retrieves the current dodge chance of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		DodgeChance - Stores the current dodge chance of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIDodgeChance(AI, DodgeChance) SDK_CONTEXT_GLOBAL->_SdkGetAIDodgeChance(AI, DodgeChance)

//++
//
// SDKSTATUS
// SdkGetAIHealthRegen(
//		_In_ void* AI,
//		_Out_ float* HealthRegen
// )
//
// Routine Description:
//
//		This function retrieves the current health regeneration of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		HealthRegen - Stores the current health regeneration of the 
//			object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIHealthRegen(AI, HealthRegen) SDK_CONTEXT_GLOBAL->_SdkGetAIHealthRegen(AI, HealthRegen)

//++
//
// SDKSTATUS
// SdkGetAIMagicPenetration(
//		_In_ void* AI,
//		_Out_ float* MagicPenetration
// )
//
// Routine Description:
//
//		This function retrieves the current magic penetration of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		MagicPenetration - Stores the current magic penetration of the 
//			object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIMagicPenetration(AI, MagicPenetration) SDK_CONTEXT_GLOBAL->_SdkGetAIMagicPenetration(AI, MagicPenetration)

//++
//
// SDKSTATUS
// SdkGetAILifeSteal(
//		_In_ void* AI,
//		_Out_ float* LifeSteal
// )
//
// Routine Description:
//
//		This function retrieves the current life steal of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		LifeSteal - Stores the current life steal of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAILifeSteal(AI, LifeSteal) SDK_CONTEXT_GLOBAL->_SdkGetAILifeSteal(AI, LifeSteal)

//++
//
// SDKSTATUS
// SdkGetAISpellVamp(
//		_In_ void* AI,
//		_Out_ float* SpellVamp
// )
//
// Routine Description:
//
//		This function retrieves the current spell vamp of the 
//		artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		SpellVamp - Stores the current spell vamp of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAISpellVamp(AI, SpellVamp) SDK_CONTEXT_GLOBAL->_SdkGetAISpellVamp(AI, SpellVamp)

//++
//
// SDKSTATUS
// SdkGetAIAbilityResourceRegen(
//		_In_ void* AI,
//		_In_ unsigned char Slot,
//		_Out_ float* AbilityResourceRegen
// )
//
// Routine Description:
//
//		This function retrieves an attackable unit's ability
//		regeneration rate. This can be mana regen, energy regen, or 
//		rage regen.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Slot - Currently, only ABILITY_SLOT_PRIMARY and 
//			ABILITY_SLOT_SECONDARY are allowed for input.
//
//		AbilityResourceRegen - Stores the ability regeneration rate
//			of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIAbilityResourceRegen(AI, Slot, AbilityResourceRegen) SDK_CONTEXT_GLOBAL->_SdkGetAIAbilityResourceRegen(AI, Slot, AbilityResourceRegen)

//++
//
// SDKSTATUS
// SdkGetAICooldownReduction(
//		_In_ void* AI,
//		_Out_ float* CooldownReduction
// )
//
// Routine Description:
//
//		This function retrieves the current cooldown reduction
//		of the artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CooldownReduction - Stores the current cooldown reduction of 
//			the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAICooldownReduction(AI, CooldownReduction) SDK_CONTEXT_GLOBAL->_SdkGetAICooldownReduction(AI, CooldownReduction)

//++
//
// SDKSTATUS
// SdkIsAIBot(
//		_In_ void* AI,
//		_Out_ bool* Bot
// )
//
// Routine Description:
//
//		This function retrieves whether or not this artificially
//		intelligent object is controlled by a computer.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Bot - Stores the controlled by computer state of the object 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIBot(AI, Bot) SDK_CONTEXT_GLOBAL->_SdkIsAIBot(AI, Bot)


//++
//
// SDKSTATUS
// SdkGetAIGold(
//		_In_ void* AI,
//		_Out_opt_ float* CurrentGold,
//		_Out_opt_ float* TotalGold
// )
//
// Routine Description:
//
//		This function retrieves the current and absolute total gold
//		acquired by the artificially intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CurrentGold - Stores the current gold of the object on success.
//
//		TotalGold - Stores the absolute total gold acquired by the 
//			object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIGold(AI, CurrentGold, TotalGold) SDK_CONTEXT_GLOBAL->_SdkGetAIGold(AI, CurrentGold, TotalGold)

//++
//
// SDKSTATUS
// SdkEnumAIBuffs(
//		_In_ void* AI,
//		_In_ AIBUFFSCALLBACK Callback,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function invokes your user-defined callback for each buff
//		that a given artificially intelligent object has present for this
//		frame.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Callback - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkEnumAIBuffs(AI, Callback, UserData) SDK_CONTEXT_GLOBAL->_SdkEnumAIBuffs(AI, Callback, UserData)

//++
//
// SDKSTATUS
// SdkAbilityResourceToString(
//		_In_ unsigned char Type,
//		_Out_ const char** String
// )
//
// Routine Description:
//
//		This function will take in an ABILITY_TYPE_### value and 
//		convert it to a human readable string.
//
// Arguments:
//
//		Type - An ABILITY_TYPE_### value.
//
//		String - A human readable string representing the 
//			ABILITY_TYPE_### value.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkAbilityResourceToString(Type, String) SDK_CONTEXT_GLOBAL->_SdkAbilityResourceToString(Type, String)

//++
//
// SDKSTATUS
// SdkBuffToString(
//		_In_ unsigned char Type,
//		_Out_ const char** String
// )
//
// Routine Description:
//
//		This function will take in an BUFF_TYPE_### value and 
//		convert it to a human readable string.
//
// Arguments:
//
//		Type - An BUFF_TYPE_### value.
//
//		String - A human readable string representing the 
//			BUFF_TYPE_### value.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkBuffToString(Type, String) SDK_CONTEXT_GLOBAL->_SdkBuffToString(Type, String)

//++
//
// SDKSTATUS
// SdkGetAICombatType(
//		_In_ void* AI,
//		_Out_ int* CombatType
// )
//
// Routine Description:
//
//		This function retrieves the combat type of an artificially
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		CombatType - Stores the combat type of the object on success.
//			This will be one of the values from COMBAT_TYPE_###.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAICombatType(AI, CombatType) SDK_CONTEXT_GLOBAL->_SdkGetAICombatType(AI, CombatType)

//++
//
// SDKSTATUS
// SdkGetAISpell(
//		_In_ void* AI,
//		_In_ unsigned char Slot,
//		_Out_ PSDK_SPELL Spell
// )
//
// Routine Description:
//
//		This function retrieves an artificially intelligent object's 
//		spell information for a given spell slot.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Slot - The spell slot. This must be >= SPELL_SLOT_START
//			and < SPELL_SLOT_MAX.
//
//		Spell - Stores information regarding the spell slot of the
//			object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAISpell(AI, Slot, Spell) SDK_CONTEXT_GLOBAL->_SdkGetAISpell(AI, Slot, Spell)

//++
//
// SDKSTATUS
// SdkGetAIDeathDuration(
//		_In_ void* AI,
//		_Out_ float* DeathDuration
// )
//
// Routine Description:
//
//		This function retrieves the death duration of an artificially
//		intelligent object.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		DeathDuration - Stores the death duration of the object on 
//			success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetAIDeathDuration(AI, DeathDuration) SDK_CONTEXT_GLOBAL->_SdkGetAIDeathDuration(AI, DeathDuration)

//++
//
// SDKSTATUS
// SdkIsAIAttacking(
//		_In_ void* AI,
//		_Out_ bool* Attacking
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is attacking.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Attacking - Stores the attacking state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIAttacking(AI, Attacking) SDK_CONTEXT_GLOBAL->_SdkIsAIAttacking(AI, Attacking)

//++
//
// SDKSTATUS
// SdkIsAIMoving(
//		_In_ void* AI,
//		_Out_ bool* Moving
// )
//
// Routine Description:
//
//		This function retrieves whether or not the artificially 
//		intelligent object is moving.
//
// Arguments:
//
//		AI - The artificially intelligent object.
//
//		Moving - Stores the moving state of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsAIMoving(AI, Moving) SDK_CONTEXT_GLOBAL->_SdkIsAIMoving(AI, Moving)

//++
//
// SDKSTATUS
// SdkIsObjectHero(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also a hero (champion). Otherwise, this function 
//		returns SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectHero(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectHero(Object)

//++
//
// SDKSTATUS
// SdkGetHeroExperience(
//		_In_ void* Hero,
//		_Out_opt_ float* Experience,
//		_Out_opt_ float* Level
// )
//
// Routine Description:
//
//		This function retrieves the current experience and level of
//		a hero.
//
// Arguments:
//
//		Hero - The hero.
//
//		Experience - Stores the current experience of the object on success.
//
//		Level - Stores the current level of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetHeroExperience(Hero, Experience, Level) SDK_CONTEXT_GLOBAL->_SdkGetHeroExperience(Hero, Experience, Level)

//++
//
// SDKSTATUS
// SdkGetHeroNeutralKills(
//		_In_ void* Hero,
//		_Out_ int* Kills
// )
//
// Routine Description:
//
//		This function retrieves the number of minion and jungle monsters
//		killed by a hero.
//
// Arguments:
//
//		Hero - The hero.
//
//		Kills - Stores the number of neutral units killed by the 
//			object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetHeroNeutralKills(Hero, Kills) SDK_CONTEXT_GLOBAL->_SdkGetHeroNeutralKills(Hero, Kills)

//++
//
// SDKSTATUS
// SdkIsObjectMinion(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also a minion. Otherwise, this function returns
//		SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectMinion(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectMinion(Object)

//++
//
// SDKSTATUS
// SdkGetMinionSpawnTime(
//		_In_ void* Minion,
//		_Out_ float* Time
// )
//
// Routine Description:
//
//		This function retrieves the spawn time of a minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		Time - Stores the spawn time of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetMinionSpawnTime(Minion, Time) SDK_CONTEXT_GLOBAL->_SdkGetMinionSpawnTime(Minion, Time)

//++
//
// SDKSTATUS
// SdkGetMinionCampNumber(
//		_In_ void* Minion,
//		_Out_ int* Camp
// )
//
// Routine Description:
//
//		This function retrieves the camp number of a minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		Camp - Stores the camp number of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetMinionCampNumber(Minion, Camp) SDK_CONTEXT_GLOBAL->_SdkGetMinionCampNumber(Minion, Camp)

//++
//
// SDKSTATUS
// SdkIsMinionLaneMinion(
//		_In_ void* Minion,
//		_Out_ bool* LaneMinion
// )
//
// Routine Description:
//
//		This function retrieves whether or not the minion is a lane
//		minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		LaneMinion - Stores whether or not the object is a lane minion 
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsMinionLaneMinion(Minion, LaneMinion) SDK_CONTEXT_GLOBAL->_SdkIsMinionLaneMinion(Minion, LaneMinion)

//++
//
// SDKSTATUS
// SdkGetMinionType(
//		_In_ void* Minion,
//		_Out_ int* Type
// )
//
// Routine Description:
//
//		This function retrieves the type of a minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		Type - Stores the MINION_TYPE_### of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetMinionType(Minion, Type) SDK_CONTEXT_GLOBAL->_SdkGetMinionType(Minion, Type)

// SDKSTATUS
// SdkGetMinionLevel(
//		_In_ void* Minion,
//		_Out_ int* Level
// )
//
// Routine Description:
//
//		This function retrieves the level of a minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		Level - Stores the level of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetMinionLevel(Minion, Level) SDK_CONTEXT_GLOBAL->_SdkGetMinionLevel(Minion, Level)

//++
//
// SDKSTATUS
// SdkIsMinionWard(
//		_In_ void* Minion,
//		_Out_ bool* Ward
// )
//
// Routine Description:
//
//		This function retrieves whether or not the minion is a ward.
//
// Arguments:
//
//		Minion - The minion.
//
//		Ward - Stores whether or not the object is a ward on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsMinionWard(Minion, Ward) SDK_CONTEXT_GLOBAL->_SdkIsMinionWard(Minion, Ward)

//++
//
// SDKSTATUS
// SdkIsObjectTurret(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also a turret (tower). Otherwise, this function 
//		returns SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectTurret(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectTurret(Object)

//++
//
// SDKSTATUS
// SdkGetTurretInfo(
//		_In_ void* Turret,
//		_Out_opt_ int* Position,
//		_Out_opt_ int* Lane
// )
//
// Routine Description:
//
//		This function retrieves the position and lane of a turret.
//
// Arguments:
//
//		Turret - The turret.
//
//		Position - Stores the TURRET_POSITION_### of the object on 
//			success.
//
//		Lane - Stores the TURRET_LANE_### of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetTurretInfo(Turret, Position, Lane) SDK_CONTEXT_GLOBAL->_SdkGetTurretInfo(Turret, Position, Lane)

//++
//
// SDKSTATUS
// SdkIsObjectSpellMissile(
//		_In_ void* Object
// )
//
// Routine Description:
//
//		This function returns SDKSTATUS_SUCCESS if the input game
//		object is also a spell missile (projectile). Otherwise, this
//		function returns SDKSTATUS_OBJECT_TYPE_MISMATCH.
//
// Arguments:
//
//		Object - The game object.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkIsObjectSpellMissile(Object) SDK_CONTEXT_GLOBAL->_SdkIsObjectSpellMissile(Object)

//++
//
// SDKSTATUS
// SdkWorldToScreen(
//		_In_ PSDKVECTOR WorldCoordinates,
//		_Out_ PSDKPOINT ScreenPoint
// )
//
// Routine Description:
//
//		This function converts a set of world coordinates (x, y, z) to
//		screen points (x, y).
//
// Arguments:
//
//		WorldCoordinates - Input (x, y, z) coordinates.
//
//		ScreenPoint - Output (x, y) coordinates.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkWorldToScreen(WorldCoordinates, ScreenPoint) SDK_CONTEXT_GLOBAL->_SdkWorldToScreen(WorldCoordinates, ScreenPoint)

//++
//
// SDKSTATUS
// SdkStopLocalPlayer(
//		_In_ bool Pet
// )
//
// Routine Description:
//
//		This function stops the local player (or their pet) from 
//		moving or attacking.
//
// Arguments:
//
//		Pet - If true, the target of the command will be the local
//			player's pet, not the actual player.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkStopLocalPlayer(Pet) SDK_CONTEXT_GLOBAL->_SdkStopLocalPlayer(Pet)

//++
//
// SDKSTATUS
// SdkMoveLocalPlayer(
//		_In_ PSDKVECTOR Destination,
//		_In_ bool Pet
// )
//
// Routine Description:
//
//		This function moves the local player (or their pet) to the
//		target world (x, y, z) location.
//
// Arguments:
//
//		Destination - The target world location (x, y, z) to move to.
//
//		Pet - If true, the target of the command will be the local
//			player's pet, not the actual player.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkMoveLocalPlayer(Destination, Pet) SDK_CONTEXT_GLOBAL->_SdkMoveLocalPlayer(Destination, Pet)

//++
//
// SDKSTATUS
// SdkAttackTargetLocalPlayer(
//		_In_ void* Unit,
//		_In_ bool Pet
// )
//
// Routine Description:
//
//		This function causes the local player (or their pet) to
//		attack the target attackable unit.
//
// Arguments:
//
//		Unit - The target attackable unit.
//
//		Pet - If true, the target of the command will be the local
//			player's pet, not the actual player.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkAttackTargetLocalPlayer(Unit, Pet) SDK_CONTEXT_GLOBAL->_SdkAttackTargetLocalPlayer(Unit, Pet)

//++
//
// SDKSTATUS
// SdkUiInputText(
//		_In_ const char* Label,
//		_Inout_ char* Buffer,
//		_In_ size_t Elements,
//		_In_ int Flags,
//		_Out_opt_ bool* Triggered
// )
//
// Routine Description:
//
//		This function creates an input text box UI element.
//
// Arguments:
//
//		Label - The name of the input box.
//
//		Buffer - The contents of the box.
//
//		Elements - Maximum number of bytes that the previously passed
//			in buffer can hold.
//
//		Flags - A bitwise mask of INPUT_TEXT_FLAGS options.
//
//		Triggered - Whether or not the input box was changed (or, 
//			alternatively, if the enter button was pressed if
//			TEXT_FLAGS_ENTER_RETURNS_TRUE is set).
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputText(Label, Buffer, Elements, Flags, Triggered) SDK_CONTEXT_GLOBAL->_SdkUiInputText(Label, Buffer, Elements, Flags, Triggered)

//++
//
// SDKSTATUS
// SdkAttackMoveLocalPlayer(
//		_In_ PSDKVECTOR Destination
// )
//
// Routine Description:
//
//		This function performs the attack-move maneuver for the local 
//		player at the target world (x, y, z) location.
//
// Arguments:
//
//		Destination - The target world location (x, y, z) of the
//			attack-move maneuver.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkAttackMoveLocalPlayer(Destination) SDK_CONTEXT_GLOBAL->_SdkAttackMoveLocalPlayer(Destination)

//++
//
// SDKSTATUS
// SdkCastSpellLocalPlayer(
//		_In_opt_ void* Unit,
//		_In_opt_ PSDKVECTOR WorldCoordinates,
//		_In_ unsigned char Slot,
//		_In_ unsigned char State
// )
//
// Routine Description:
//
//		This function causes the local player to cast a spell at the
//		target attackable unit or world location.
//
// Arguments:
//
//		Unit - The target attackable unit. If this is NULL, the provided
//			world coordinates are used.
//
//		WorldCoordinates - The world coordinates (x, y, z) of the 
//			cast location. If this is NULL, the provided attackable unit
//			becomes the target.
//
//		Slot - The spell slot. This must be >= SPELL_SLOT_START
//			and < SPELL_SLOT_MAX.
//
//		State - Either SPELL_CAST_START or SPELL_CAST_COMPLETE. For 
//			most spells this should be SPELL_CAST_START. SPELL_CAST_COMPLETE
//			should only be used if you, prematurely, want to complete 
//			a charged spell.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkCastSpellLocalPlayer(Unit, Destination, Slot, State) SDK_CONTEXT_GLOBAL->_SdkCastSpellLocalPlayer(Unit, Destination, Slot, State)

//++
//
// SDKSTATUS
// SdkUiInputNumber(
//		_In_ const char* Label,
//		_Inout_ int* Number,
//		_Out_opt_ bool* Changed
// )
//
// Routine Description:
//
//		This function creates a numeric input box UI element.
//
// Arguments:
//
//		Label - The name of the input box.
//
//		Number - The value of the box.
//
//		Changed - Whether or not the input box was changed.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputNumber(Label, Number, Changed) SDK_CONTEXT_GLOBAL->_SdkUiInputNumber(Label, Number, Changed)

//++
//
// SDKSTATUS
// SdkMoveMouse(
//		_In_ PSDKVECTOR WorldCoordinates
// )
//
// Routine Description:
//
//		This function moves the mouse to the target world 
//		location (x, y, z), which must be visible on 
//		the screen.
//
// Arguments:
//
//		WorldCoordinates - The target world location (x, y, z).
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkMoveMouse(WorldCoordinates) SDK_CONTEXT_GLOBAL->_SdkMoveMouse(WorldCoordinates)

//++
//
// SDKSTATUS
// SdkGetGameTime(
//		_Out_ float* Time
// )
//
// Routine Description:
//
//		This function retrieves the current game time.
//
// Arguments:
//
//		Time - The current game time.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetGameTime(Time) SDK_CONTEXT_GLOBAL->_SdkGetGameTime(Time)

//++
//
// SDKSTATUS
// SdkLevelSpellLocalPlayer(
//		_In_ unsigned char Slot,
//		_Out_opt_ bool* Leveled
// )
//
// Routine Description:
//
//		This function levels up the target spell for the local player.
//
// Arguments:
//
//		Slot - The spell slot. This must be >= SPELL_SLOT_START
//			and < SPELL_SLOT_MAX.
//
//		Leveled - Stores whether or not the spell slot was leveled
//			successfully.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkLevelSpellLocalPlayer(Slot, Leveled) SDK_CONTEXT_GLOBAL->_SdkLevelSpellLocalPlayer(Slot, Leveled)

//++
//
// SDKSTATUS
// SdkShowEmoteLocalPlayer(
//		_In_ unsigned char Emote
// )
//
// Routine Description:
//
//		This function causes the local player to perform an emote.
//
// Arguments:
//
//		Emote - The EMOTE_TYPE_### to perform.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkShowEmoteLocalPlayer(Emote) SDK_CONTEXT_GLOBAL->_SdkShowEmoteLocalPlayer(Emote)

//++
//
// SDKSTATUS
// SdkSendChatLocalPlayer(
//		_In_ const char* Text
// )
//
// Routine Description:
//
//		This function sends a chat message from the local player.
//
// Arguments:
//
//		Text - The chat to send. Prefix the chat with a "/all" to 
//			send the message to non-friendly players as well as 
//			teammates.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSendChatLocalPlayer(Text) SDK_CONTEXT_GLOBAL->_SdkSendChatLocalPlayer(Text)

//++
//
// SDKSTATUS
// SdkUiInputMultiLineText(
//		_In_ const char* Label,
//		_Inout_ char* Buffer,
//		_In_ size_t Elements,
//		_In_ int Flags,
//		_Out_opt_ bool* Triggered
// )
//
// Routine Description:
//
//		This function creates a multi-line input text box UI element.
//
// Arguments:
//
//		Label - The name of the input box.
//
//		Buffer - The contents of the box.
//
//		Elements - Maximum number of bytes that the previously passed
//			in buffer can hold.
//
//		Flags - A bitwise mask of INPUT_TEXT_FLAGS options.
//
//		Triggered - Whether or not the input box was changed (or, 
//			alternatively, if the enter button was pressed if
//			TEXT_FLAGS_ENTER_RETURNS_TRUE is set).
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkUiInputMultiLineText(Label, Buffer, Elements, Size, Flags, Triggered) SDK_CONTEXT_GLOBAL->_SdkUiInputMultiLineText(Label, Buffer, Elements, Size, Flags, Triggered)

//++
//
// SDKSTATUS
// SdkDrawText(
//		_In_opt_ PSDKVECTOR WorldCoordinates, 
//		_In_opt_ PSDKPOINT ScreenPoint,
//		_In_ const char* Text,
//		_In_ const char* Face,
//		_In_ PSDKCOLOR Color, 
//		_In_ int Height,
//		_In_ int Width,
//		_In_ int Weight,
//		_In_ bool Italic
// )
//
// Routine Description:
//
//		This function draws a text message on the game frame.
//
// Arguments:
//
//		WorldCoordinates - The position (x, y, z) in world (in-
//			game) coordinates of the text message. If this is NULL,
//			the screen point is used.
//
//		ScreenPoint - The position (x, y) in screen coordinates of
//			the text message. If this is NULL, world coordinates 
//			are used.
//
//		Text - The message contents.
//
//		Face - The font face, e.g. Arial, Verdana, Consolas, etc...
//			
//		Color - The desired BGRA color of the circle.
//
//		Height - The height of the font.
//
//		Width - The width of the font.
//
//		Weight - The boldness of the font.
//
//		Italic - Whether to render the font as italicized or not.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkDrawText(WorldCoordinates, ScreenPoint, Text, Face, Color, Height, Width, Weight, Italic) SDK_CONTEXT_GLOBAL->_SdkDrawText(WorldCoordinates, ScreenPoint, Text, Face, Color, Height, Width, Weight, Italic)

//++
//
// SDKSTATUS
// SdkSetSettingString(
//		_In_ const char* Key,
//		_In_ const char* Value
// )
//
// Routine Description:
//
//		This function saves the provided null-terminated string to a
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - The null-terminated string. It will be associated 
//			with the module and provided key pair. To retrieve this 
//			value, call the appropriate SdkGetSetting#### 
//			function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSetSettingString(Key, Value) SDK_CONTEXT_GLOBAL->_SdkSetSettingString(Key, Value)

//++
//
// SDKSTATUS
// SdkGetSettingString(
//		_In_ const char* Key,
//		_In_ char* Buffer,
//		_In_ size_t Elements,
//		_In_ const char* Default
// )
//
// Routine Description:
//
//		This function retrieves a previously saved value from the
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Buffer - Stores the previously saved value (from a 
//			SdkSetSetting#### call) on success.
//
//		Elements - Maximum number of bytes that the previously passed
//			in buffer can hold.
//
//		Default - If there is no value associated with the module and
//			provided key pair, this value is retrieved instead.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetSettingString(Key, Buffer, Elements, Default) SDK_CONTEXT_GLOBAL->_SdkGetSettingString(Key, Buffer, Elements, Default)

//++
//
// SDKSTATUS
// SdkSetSettingBool(
//		_In_ const char* Key,
//		_In_ bool Value
// )
//
// Routine Description:
//
//		This function saves the provided boolean (true/false) to a
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - The boolean. It will be associated with the module 
//			and provided key pair. To retrieve this value, call the 
//			appropriate SdkGetSetting#### function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSetSettingBool(Key, Value) SDK_CONTEXT_GLOBAL->_SdkSetSettingBool(Key, Value)

//++
//
// SDKSTATUS
// SdkGetSettingBool(
//		_In_ const char* Key,
//		_In_ bool* Value,
//		_In_ bool Default
// )
//
// Routine Description:
//
//		This function retrieves a previously saved value from the
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - Stores the previously saved value (from a 
//			SdkSetSetting#### call) on success.
//
//		Default - If there is no value associated with the module and
//			provided key pair, this value is retrieved instead.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetSettingBool(Key, Value, Default) SDK_CONTEXT_GLOBAL->_SdkGetSettingBool(Key, Value, Default)

//++
//
// SDKSTATUS
// SdkSetSettingBool(
//		_In_ const char* Key,
//		_In_ float Value
// )
//
// Routine Description:
//
//		This function saves the provided float to a module-specific 
//		configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - The float. It will be associated with the module 
//			and provided key pair. To retrieve this value, call the 
//			appropriate SdkGetSetting#### function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSetSettingFloat(Key, Value) SDK_CONTEXT_GLOBAL->_SdkSetSettingFloat(Key, Value)

//++
//
// SDKSTATUS
// SdkGetSettingFloat(
//		_In_ const char* Key,
//		_In_ float* Value,
//		_In_ float Default
// )
//
// Routine Description:
//
//		This function retrieves a previously saved value from the
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - Stores the previously saved value (from a 
//			SdkSetSetting#### call) on success.
//
//		Default - If there is no value associated with the module and
//			provided key pair, this value is retrieved instead.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetSettingFloat(Key, Value, Default) SDK_CONTEXT_GLOBAL->_SdkGetSettingFloat(Key, Value, Default)

//++
//
// SDKSTATUS
// SdkSetSettingBool(
//		_In_ const char* Key,
//		_In_ int Value
// )
//
// Routine Description:
//
//		This function saves the provided number to a module-specific 
//		configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - The number. It will be associated with the module 
//			and provided key pair. To retrieve this value, call the 
//			appropriate SdkGetSetting#### function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkSetSettingNumber(Key, Value) SDK_CONTEXT_GLOBAL->_SdkSetSettingNumber(Key, Value)

//++
//
// SDKSTATUS
// SdkGetSettingNumber(
//		_In_ const char* Key,
//		_In_ int* Value,
//		_In_ int Default
// )
//
// Routine Description:
//
//		This function retrieves a previously saved value from the
//		module-specific configuration store.
//
// Arguments:
//
//		Key - A unique variable name.
//
//		Value - Stores the previously saved value (from a 
//			SdkSetSetting#### call) on success.
//
//		Default - If there is no value associated with the module and
//			provided key pair, this value is retrieved instead.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetSettingNumber(Key, Value, Default) SDK_CONTEXT_GLOBAL->_SdkGetSettingNumber(Key, Value, Default)

//++
//
// SDKSTATUS
// SdkGetMinionVisionRadius(
//		_In_ void* Minion,
//		_Out_ float* Radius
// )
//
// Routine Description:
//
//		This function retrieves the vision radius of a minion.
//
// Arguments:
//
//		Minion - The minion.
//
//		Radius - Stores the vision radius of the object on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetMinionVisionRadius(Minion, Radius) SDK_CONTEXT_GLOBAL->_SdkGetMinionVisionRadius(Minion, Radius)

//++
//
// SDKSTATUS
// SdkPingMap(
//		_In_ PSDKVECTOR WorldCoordinates,
//		_In_ unsigned char Type,
//		_In_ bool PlayAudio
// )
//
// Routine Description:
//
//		This function pings the target location's world coordinates 
//		(x, y, z).
//
// Arguments:
//
//		WorldCoordinates - The target location's world coordinates
//			(x, y, z).
//
//		Type - The type of ping to use. Use one of the values in 
//			PING_TYPE_####.
//
//		PlayAudio - Whether or not to play an audible sound associated
//			with the ping.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkPingMap(WorldCoordinates, Type, PlayAudio) SDK_CONTEXT_GLOBAL->_SdkPingMap(WorldCoordinates, Type, PlayAudio)

//++
//
// SDKSTATUS
// SdkDisableInput(
//		void
// )
//
// Routine Description:
//
//		This function blocks all user input until SdkEnableInput is
//		called.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkDisableInput() SDK_CONTEXT_GLOBAL->_SdkDisableInput()

//++
//
// SDKSTATUS
// SdkEnableInput(
//		void
// )
//
// Routine Description:
//
//		This function restores all user input that was previously 
//		disabled by an SdkDisableInput call. For every SdkDisableInput
//		call, you must invoke SdkEnableInput an equivalent number of
//		times to allow user interaction.
//
// Arguments:
//
//		None.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkEnableInput() SDK_CONTEXT_GLOBAL->_SdkEnableInput()

//++
//
// SDKSTATUS
// SdkGetD3DDevice(
//		_Out_ void** Device
// )
//
// Routine Description:
//
//		This function retrieves the game's Direct X device object
//		(IDirect3DDevice9). Try to avoid using this function. Instead,
//		request any missing SDK features to the website.
//
// Arguments:
//
//		Device - The IDirect3DDevice9 object pointer.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetD3DDevice(Device) SDK_CONTEXT_GLOBAL->_SdkGetD3DDevice(Device)

//++
//
// SDKSTATUS
// SdkWorldToMinimap(
//		_In_ PSDKVECTOR WorldCoordinates,
//		_Out_ PSDKPOINT ScreenPoint
// )
//
// Routine Description:
//
//		This function converts a set of world coordinates (x, y, z) to
//		screen points (x, y) that indicate a position on the minimap.
//
// Arguments:
//
//		WorldCoordinates - Input (x, y, z) coordinates.
//
//		ScreenPoint - Output (x, y) coordinates.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkWorldToMinimap(WorldCoordinates, ScreenPoint) SDK_CONTEXT_GLOBAL->_SdkWorldToMinimap(WorldCoordinates, ScreenPoint)

//++
//
// SDKSTATUS
// SdkGetObjectVelocity(
//		_In_ void* Object,
//		_Out_ PSDKVECTOR Velocity
// )
//
// Routine Description:
//
//		This function retrieves the velocity of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Velocity - Stores the velocity (x, y, z) of the object
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectVelocity(Object, Velocity) SDK_CONTEXT_GLOBAL->_SdkGetObjectVelocity(Object, Velocity)

//++
//
// SDKSTATUS
// SdkGetObjectAcceleration(
//		_In_ void* Object,
//		_Out_ PSDKVECTOR Acceleration
// )
//
// Routine Description:
//
//		This function retrieves the acceleration of a game object.
//
// Arguments:
//
//		Object - The game object.
//
//		Acceleration - Stores the acceleration (x, y, z) of the object
//			on success.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkGetObjectAcceleration(Object, Acceleration) SDK_CONTEXT_GLOBAL->_SdkGetObjectAcceleration(Object, Acceleration)

//++
//
// SDKSTATUS
// SdkRegisterGameObjectCreate(
//		_In_ GAMEOBJECTSCALLBACK Callback,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function invokes your user-defined callback for each game
//		object that is created in the world for this frame. 
//
//		WARNING: It is possible for you to receive incomplete data if
//			your plugin is loaded after the start of the game.
//
// Arguments:
//
//		Callback - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkRegisterGameObjectCreate(Callback, UserData) SDK_CONTEXT_GLOBAL->_SdkRegisterGameObjectCreate(Callback, UserData)

//++
//
// SDKSTATUS
// SdkRegisterGameObjectDelete(
//		_In_ GAMEOBJECTSCALLBACK Callback,
//		_In_opt_ void* UserData
// )
//
// Routine Description:
//
//		This function invokes your user-defined callback for each game
//		object that is about to be deleted from the world in the
//		next frame.
//
//		WARNING: It is possible for you to receive incomplete data if
//			your plugin is loaded after the start of the game.
//
// Arguments:
//
//		Callback - The user-defined callback.
//
//		UserData - A pointer to an arbitrary data structure, provided
//			by the user, that is passed to the callback function.
//
// Return Value:
//
//		An SDKSTATUS code.
//
//--
#define SdkRegisterGameObjectDelete(Callback, UserData) SDK_CONTEXT_GLOBAL->_SdkRegisterGameObjectDelete(Callback, UserData)
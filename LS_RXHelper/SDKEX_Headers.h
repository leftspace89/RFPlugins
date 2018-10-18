#pragma once

#define MAKE_GET(NAME,TYPE,FUNCTIONDEF) \
TYPE Get##NAME (){					\
TYPE T;						\
FUNCTIONDEF(Object,&T);						\
return T;					\
}

#define MAKE_RAW(NAME,TYPE,FUNCTIONDEF) \
TYPE NAME (){					\
TYPE T;						\
FUNCTIONDEF(Object,&T);						\
return T;					\
}
#include "rVectors.hpp"
#include "../../sdkapi.h"
extern PSDK_CONTEXT SDK_CONTEXT_GLOBAL;
extern  void* g_LocalPlayer; // for every gameobject
#include "GameObject.hpp"
#include "AttackableUnit.hpp"
#include "AIBaseClient.hpp"
#include "AITurretClient.hpp"
#include "AIMinionClient.hpp"
#include "AIHeroClient.hpp"
#include "EntityManager.hpp"
#include "lpred.h"
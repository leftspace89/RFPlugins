#pragma once

#include "rVectors.hpp"
//SDKVECTOR_EXTEND MUST BE DEFINED AT PREPROCESSORS
#include "../SDKRift/sdkapi.h"

#define LSFail if(!Object){SdkUiConsoleWrite("Object issue, %s",__FUNCTION__);}//assert(Object !=NULL);



extern PSDK_CONTEXT SDK_CONTEXT_GLOBAL;
extern  void* g_LocalPlayer; // for every gameobject

#define CHECKFAIL(CODE)\
if (Object == NULL || !SDKSTATUS_SUCCESS(CODE)) { \
SdkUiConsoleWrite("[SDK] Error! %s\n", __FUNCTION__);\
}

#define MAKE_GET(NAME,TYPE,FUNCTIONDEF)                    \
TYPE Get##NAME##(){                                        \
    TYPE _##NAME;                                        \
    SDKSTATUS _STATE = FUNCTIONDEF(Object,&_##NAME);    \
    if (!SDKSTATUS_SUCCESS(_STATE)) {                    \
        SdkUiConsoleWrite(" [SDK] Error! MAKE_GET Could not retrieve %s for obj %p errorCode: %i.\n", __FUNCTION__, Object, (int)_STATE); \
    }                                                    \
    return _##NAME;                                     \
}

#define MAKE_RAW(NAME,TYPE,FUNCTIONDEF)                    \
TYPE NAME##(){                                        \
    TYPE _##NAME;                                        \
    SDKSTATUS _STATE = FUNCTIONDEF(Object,&_##NAME);    \
    if (!SDKSTATUS_SUCCESS(_STATE)) {                    \
        SdkUiConsoleWrite(" [SDK] MAKE_RAW Error! Could not retrieve %s for obj %p errorCode: %i.\n", __FUNCTION__, Object, (int)_STATE); \
    }                                                    \
    return _##NAME;                                     \
}

#include "GameObject.hpp"
#include "AttackableUnit.hpp"
#include "AIBaseClient.hpp"
#include "AITurretClient.hpp"
#include "AIMinionClient.hpp"
#include "AIHeroClient.hpp"
#include "EntityManager.hpp"
#include "lpred.h"


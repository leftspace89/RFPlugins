#pragma once
class AIMinionClient : public AIBaseClient
{
public:
	AIMinionClient(void* obj) : AIBaseClient(obj) {
	};
	~AIMinionClient()
	{};
	MAKE_GET(SpawnTime, float, SdkGetMinionSpawnTime)
	MAKE_GET(CampNumber, int, SdkGetMinionCampNumber)
	MAKE_RAW(LaneMinion, bool, SdkIsMinionLaneMinion)
	MAKE_GET(Type, int, SdkGetMinionType)
	MAKE_GET(Level, int, SdkGetMinionLevel)
	MAKE_RAW(Ward, bool, SdkIsMinionWard)
};

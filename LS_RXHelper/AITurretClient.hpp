#pragma once

class AITurretClient : public AIBaseClient
{
public:
	AITurretClient(void* obj) : AIBaseClient(obj) {
	};
	~AITurretClient()
	{};
	
	int GetPosition()
	{
		LSFail
		int tmp1;
		CHECKFAIL(SdkGetTurretInfo(Object, &tmp1, NULL));
		return tmp1;
	}
	int GetLane()
	{
		LSFail
		int tmp1;
		CHECKFAIL(SdkGetTurretInfo(Object, NULL, &tmp1));
		return tmp1;
	}

};

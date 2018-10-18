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
		int tmp1;
		SdkGetTurretInfo(Object, &tmp1, NULL);
		return tmp1;
	}
	int GetLane()
	{
		int tmp1;
		SdkGetTurretInfo(Object, NULL, &tmp1);
		return tmp1;
	}

};

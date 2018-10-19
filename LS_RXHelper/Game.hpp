#pragma once

enum PingType
{
	Default,
	Charge,
	Danger,
	Missing,
	OnMyWay,
	Back,
	Come,
	Warded,
	SmallIcon,
	BigIcon
};

class Game {
public:
	//
	//	Game.Time
	//
	//	Get Game's time as float
	//
	//
	static float Time()
	{
		float time;
		CHECKRAWFAIL(SdkGetGameTime(&time));
		return time;
	}

	//
	//	Ping map function
	//
	//  SDKVECTOR coordinate: World coordinates vector of ping place
	//
	//	PingType: Type of ping enum (There are 10 types of ping)
	//
	//	bool playAudio: If you want to play an audio on client change this to true
	//
	//
	static bool PingMap(SDKVECTOR coordinate, PingType type, bool playAudio)
	{
		return SDKSTATUS_SUCCESS(SdkPingMap(&coordinate, type, playAudio));
	}
};
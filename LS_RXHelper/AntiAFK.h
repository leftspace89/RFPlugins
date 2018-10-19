#pragma once

#include "SDKEX_Headers.h"
#include <random>

namespace AntiAFK {
	constexpr int WarningTime = 100;
	float lastAction;

	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> randTime(-45, +45);
	int rValue = 0;

	void ResetSeed() {
		rng.seed(std::random_device()());
	}

	void ResetActionTimer() {
		lastAction = Game::Time();
	}

	void Execute() {
		if (Game::Time() - lastAction >= WarningTime + rValue) {
			rValue = (int)randTime(rng);
			SdkUiConsoleWrite(" [AntiAFK] Moving To Avoid Inactivity. TimePassed: %f Next Move In: %d.\n", Game::Time() - lastAction, WarningTime + rValue);
			SdkMoveLocalPlayer(&(EntityManager::GetLocalPlayer().GetPosition()), false);
			lastAction = Game::Time();
		}
	}
};
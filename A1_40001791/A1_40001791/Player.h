#pragma once
#pragma once
class Race;
class Region;
class Special_Power;
#include "Race.h"
#include "Special_Power.h"
#include "Region.h"
#include "Dice_Roll.h"
#include <cstdlib>
class Player
{

private:
	Dice_Roll * dr;
	Region * regions;
	int currencyTokens[4] = { 0,0,0,5};
	Race  * r;
	Special_Power * sp;
public:
	Player();
	~Player();
	void picks_race();
	void conquers();
	void scores();
	int totalMoney();
};
#pragma once
#pragma once
class Race;
class Region;
class Special_Power;
class Map;
#include "Race.h"
#include "Special_Power.h"
#include "Region.h"
#include "Dice_Roll.h"
#include <cstdlib>
#include "Map.h"
class Player
{

private:
	Dice_Roll * dr;
	vector<Region *> regions;
	int currencyTokens[4] = { 0,0,0,5};
	Race  * r[2];
	Special_Power * sp[2];
	int reinforcements = 0;
	int remainingReinforcements = 0;
	int currentRace = 0;
	int conqueredRegionsNotEmpty = 0;
	int playerNumber;
	int nbOfConquests = 0;
	bool inDecline = false;
	bool troopRedeployment = false;
public:
	Player();
	~Player();
	void picks_race(vector<Race *> raceVector,vector<Special_Power *> powerVector);
	bool conquers(Region *& r);
	void scores();
	bool getDeclineStatus();
	void setDeclineStatus(bool status);
	void setRedeploymentStatus(bool status);
	bool getRedeploymentStatus();
	Race * getRace();
	Race * getDeclineRace();
	Special_Power * getPower();
	Special_Power * getDeclinePower();
	int totalMoney();
	void setCurrencyTokens();
	void firstConquest(Map *&m);
	void findAllPossibleConquests(Map *&m);
	int getPlayerNumber();
	void setPlayerNumber(int n);
	void goIntoDecline();
	void readyTroops();
	void abandonRegion();
	void redeploy();
};
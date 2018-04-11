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
#include "PhaseObserver.h"
#include "Strategy.h"
#include "GameStatisticObserver.h"
class Strategy;
using namespace std;
class Player : PhaseObserver ,GameStatisticObserver
{

private:
	Strategy * strat;
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
	string phase;
public:
	Player();
	~Player();
	void setStrategy(Strategy * strategy);
	void Update(int turn);
	void Update(string phase);
	void Update(vector<double> percent);
	void Update(vector<string>scoreResult);
	bool continueConquest();
	vector<Region*> getAvailableRegions(Map *& m);
	void showAvailableRegions(vector<Region*> av);
	void AIOtherConquest(Map *& m);
	void AIFirstConquest(Map *& m);
	void picks_race(vector<Race *> raceVector,vector<Special_Power *> powerVector);
	bool conquers(Region *& r);
	vector<string> scores();
	bool getDeclineStatus();
	void setDeclineStatus(bool status);
	void setRedeploymentStatus(bool status);
	bool getRedeploymentStatus();
	Race * getRace();
	Race * getDeclineRace();
	Special_Power * getPower();
	Special_Power * getDeclinePower();
	vector<Region *> getRegions();
	int totalMoney();
	void setCurrencyTokens();
	void firstConquest(Map *&m);
	void findAllPossibleConquests(Map *&m);
	int getPlayerNumber();
	void setPlayerNumber(int n);
	void goIntoDecline();
	void readyTroops();
	void abandonRegion(Map *& m);
	void redeploy(Map *& m);
};
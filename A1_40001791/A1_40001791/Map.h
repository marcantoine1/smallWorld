#pragma once
class Player;
class Region;
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Region.h"
#include <string>
#include "GameStatisticObserver.h"
using namespace std;
class Map
{

private:
	int numberRegions;
	vector <Region*> regions;
	vector <Player *> players;
	Player * playerObs;
	Map * mapObs;
	int currentPlayer = 0;
	int numberTurns = 0;
	int currentTurn = 1;
	vector<double> percentOwnership;
	vector<double> oldPercent;
	
public:
	Map();
	~Map();
	int getNumberMembers();
	void setNumberMembers(int);
	void Attach(Player * p);
	void Attach(Map *& m);
	void Detach(Player * p);
	void Detach(Map * m);
	void Notify(string phase);
	void Notify(vector<double> percent);
	void Notify(int turn);
	void Notify(vector<string> scoreResult);
	Region* getRegionMembersAt(int);
	void setRegionMembersAt(int, Region*);

	void setMap(vector <Region *> newRegion);
	void setPlayers(vector <Player *> newPlayer);
	vector<Player *> getPlayers();


	void nextTurn();
	int getCurrentTurn();
	void setNumberTurns(int nbturn);
	int getNumberTurns();
	void setNextPlayer();
	int getCurrentPlayer();
	vector<Region *> getRegions();
	void setPhase(string phase);
	vector<double> calculatePercentOwnership();
	Map * getMapObs();
	vector<double> getOld();
	void setOld(vector<double> old);
	bool isDifferent(vector<double> old, vector<double> newV);
};


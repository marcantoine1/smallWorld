#pragma once
class Player;
class Region;
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Region.h"
using namespace std;
class Map
{

private:
	int numberRegions;
	vector <Region*> regions;
	vector <Player *> players;
	int currentPlayer = 0;
	int numberTurns = 0;
	int currentTurn = 1;
public:
	Map();
	~Map();
	int getNumberMembers();
	void setNumberMembers(int);

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
};


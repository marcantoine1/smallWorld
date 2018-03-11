#include "stdafx.h"
#include "Map.h"


Map::Map()
{

}

Map::~Map()
{
}

int Map::getNumberMembers()
{
	return numberRegions;
}

void Map::setNumberMembers(int number)
{
	numberRegions = number;
}

Region * Map::getRegionMembersAt(int x)
{
	return regions.at(x);
}

void Map::setRegionMembersAt(int x, Region * region)
{
	regions.at(x) = region;
}

void Map::setMap(vector<Region*> newRegion)
{
	regions = newRegion;
}

void Map::setPlayers(vector<Player*> newPlayer)
{
	players = newPlayer;
}

vector<Player*> Map::getPlayers()
{
	return players;
}

void Map::nextTurn()
{
	currentTurn++;
}

int Map::getCurrentTurn()
{
	return currentTurn;
}

void Map::setNumberTurns(int nbturn)
{
	numberTurns = nbturn;
}

int Map::getNumberTurns()
{
	return numberTurns;
}

void Map::setNextPlayer()
{
	if (currentPlayer == players.size()) {
		currentPlayer = 0;
	}
	else {
		currentPlayer++;
	}
}

int Map::getCurrentPlayer()
{
	return currentPlayer;
}

vector<Region*> Map::getRegions()
{
	return regions;
}






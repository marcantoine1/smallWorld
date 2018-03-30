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

void Map::Attach(Player * p)
{
	playerObs = p;
}

void Map::Attach(Map *& m)
{
	mapObs = m;
}

void Map::Detach(Player * p)
{
	playerObs = nullptr;
}

void Map::Detach(Map * m)
{
	mapObs = nullptr;
}

void Map::Notify(string phase)
{
	playerObs->Update(phase);
}

void Map::Notify(vector<double> percent)
{
	this->mapObs->players.at(currentPlayer)->Update(percent);
}
void Map::Notify(int turn) {
	this->currentTurn = turn;
	playerObs->Update(turn);
}
void Map::Notify(vector<string> scoreResult) {
	playerObs->Update(scoreResult);
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
	percentOwnership.resize(players.size());
	oldPercent.resize(players.size());
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
	if (currentPlayer == players.size() -1) {
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

void Map::setPhase(string phase) {
	getPlayers().at(getCurrentPlayer())->Update(phase);
}


vector<double> Map::calculatePercentOwnership() {
	for (size_t i = 0; i < getPlayers().size(); i++)
	{
		percentOwnership.at(i) =(double) getPlayers().at(i)->getRegions().size() / getRegions().size() * 100;
	}
	return percentOwnership;
}

Map * Map::getMapObs()
{
	return mapObs;
}

vector<double> Map::getOld()
{
	return oldPercent;
}

void Map::setOld(vector<double> old)
{
	oldPercent = old;
}

bool Map::isDifferent(vector<double> old, vector<double> newV) {
	bool diff = false;
	for (size_t i = 0; i < old.size(); i++)
	{
		if (old.at(i) != newV.at(i))
			diff = true;
	}

	return diff;
}
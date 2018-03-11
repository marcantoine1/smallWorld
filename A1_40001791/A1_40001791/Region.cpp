#include "stdafx.h"
#include "Region.h"
#include "RegionType.h"
class RegionType;
Region::Region()
{
}
Region::Region(RegionType * aType, Special_Tile *stile)
{
	type = aType;
	Map;
	numberAdjacency = 0;
	 st= stile;
	linked = false;
	owner = NULL;
}

Region::Region(RegionType * aType, Special_Tile *stile, int initialArmy)
{
	type = aType;
	numberOfArmy = initialArmy;
	Map;
	st = stile;
	numberAdjacency = 0;
	linked = false;
	owner = NULL;
}

Region::Region(RegionType * aType,Special_Tile *stile, int initialArmy, int adjSize)
{
	type = aType;
	Map;
	st = stile;
	linked = false;
	owner = NULL;
	numberAdjacency = adjSize;
	adjacency.resize(adjSize);
}

Region::~Region()
{
}

int Region::getArmy()
{
	return numberOfArmy;
}

void Region::setArmy(int army)
{
	numberOfArmy = army;
}

int Region::getNumberAdjacency()
{
	return numberAdjacency;
}

void Region::setNumberAdjacency(int adj)
{
	numberAdjacency = adj;
}

Region * Region::getAdjacencyAt(int adj)
{
	return adjacency.at(adj);
}

bool Region::isAdjacent(Region * region)
{
	for (size_t i = 0; i < getNumberAdjacency(); i++)
	{
		if (getAdjacencyAt(i) == region)
			return true;
	}
	return false;
}

void Region::printAdjacents()
{
}

void Region::setAdjacencyAt(int x, Region * region)
{
	numberAdjacency++;
	adjacency.resize(numberAdjacency);
	adjacency.at(x) = region;
}

void Region::setRegionType(RegionType * aType)
{
	type = aType;
}

void Region::setRegionSpecial(Special_Tile * aSpecial)
{
	st = aSpecial;
}

void Region::setOtherTypeTile(vector<OtherTiles*> ot)
{
	otherTileTypes = ot;
}

vector<Region*> Region::getAdjacencies()
{
	return adjacency;
}


bool Region::isLinked()
{
	return linked;
}

void Region::setLinked(bool isLinked)
{
	linked = isLinked;
}

Player * Region::getOwner()
{
	return owner;
}

void Region::setOwner(Player * player)
{
	owner = player;
}

int Region::getAdjacencySize()
{
	return numberAdjacency;
}

vector<OtherTiles*> Region::getOtherTiles()
{
	return otherTileTypes;
}

RaceTokens * Region::getRaceToken()
{
	return rt;
}

void Region::setRaceToken(RaceTokens * raceToken)
{
	rt = raceToken;
}

RegionType * Region::getRegionType()
{
	return type;
}

Special_Power_Tile * Region::getSpecialPowerTile()
{
	return spt;
}

Special_Tile * Region::getSpecialTile()
{
	return st;
}

void Region::setSpecialPowerTile(Special_Power_Tile * s)
{
	spt = s;
}

bool Region::getIsEdge()
{
	return isEdge;
}

void Region::setIsEdge(bool edge)
{
	isEdge = edge;
}



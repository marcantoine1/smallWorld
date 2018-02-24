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

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
	return regionMembers.at(x);
}

void Map::setRegionMembersAt(int x, Region * region)
{
	regionMembers.at(x) = region;
}




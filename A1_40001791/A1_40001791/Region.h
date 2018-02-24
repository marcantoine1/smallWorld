#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "RegionType.h"
#include "Special_Tile.h"
class Player;
class Map;
class RegionType;
using namespace std;
class Region
{

private:
	int numberOfTokens;
	int numberOfArmy;
	int numberAdjacency;
	Map* map;
	vector <Region*> adjacency;
	Player* owner;
	RegionType* type;
	Special_Tile *st;
	string tile_type;
	bool linked;

public:
	Region();
	Region(RegionType*,Special_Tile *);
	Region(RegionType*,Special_Tile *, int);
	Region(RegionType*, Special_Tile * ,int, int);
	~Region();

	int getArmy();
	void setArmy(int);

	int getNumberAdjacency();
	void setNumberAdjacency(int);

	Region* getAdjacencyAt(int);
	bool isAdjacent(Region*);
	void printAdjacents();
	void setAdjacencyAt(int, Region*);

	void setRegionType(RegionType *);
	void setRegionSpecial(Special_Tile *);
	bool isLinked();
	void setLinked(bool);

	Player* getOwner();
	void setOwner(Player*);

	int getAdjacencySize();

};
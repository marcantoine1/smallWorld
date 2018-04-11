#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "RegionType.h"
#include "Special_Tile.h"
#include "OtherTiles.h"
#include "RaceTokens.h"
#include "Special_Power_Tile.h"
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
	RaceTokens * rt;
	Map* map;
	vector <Region*> adjacency;
	vector <OtherTiles *> otherTileTypes;
	Player* owner;
	RegionType* type;
	Special_Tile *st;
	string tile_type;
	bool linked;
	Special_Power_Tile * spt;
	bool isEdge;

public:
	int regionNumber;
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
	void setOtherTypeTile(vector<OtherTiles *> ot);
	vector<Region *> getAdjacencies();
	bool isLinked();
	void setLinked(bool);

	Player* getOwner();
	void setOwner(Player*);

	int getAdjacencySize();
	vector<OtherTiles *> getOtherTiles();
	RaceTokens * getRaceToken();
	void setRaceToken(RaceTokens * raceToken);
	RegionType * getRegionType();
	Special_Power_Tile * getSpecialPowerTile();
	Special_Tile * getSpecialTile();
	void setSpecialPowerTile(Special_Power_Tile * s);
	bool getIsEdge();
	void setIsEdge(bool edge);
};
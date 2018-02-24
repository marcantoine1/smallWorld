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
	vector <Region*> regionMembers;
public:
	Map();
	~Map();
	int getNumberMembers();
	void setNumberMembers(int);

	Region* getRegionMembersAt(int);
	void setRegionMembersAt(int, Region*);

};


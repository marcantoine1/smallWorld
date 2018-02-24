#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Region.h"


using namespace std;

class MapChecker
{
private:
	vector <Region*> regionVector;
	int numberRegion;

public:
	MapChecker(vector <Region*>);
	~MapChecker();

	bool areNodesConnectedBothWays();
	bool isMapLinked();
};

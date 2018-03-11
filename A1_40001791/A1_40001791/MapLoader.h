#pragma once
#include <string>
#include "Map.h"
#include<iostream>
#include<fstream>
#include <regex>
#include <vector>
using namespace std;
class MapLoader {
private:
	vector<Region *> mapRegion;
public:
	MapLoader();
	~MapLoader();
	bool validMap(string path);
	vector<Region*> loadMap();

};
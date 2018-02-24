#pragma once
#include <string>
#include "Map.h"
#include<iostream>
#include<fstream>
#include <regex>
using namespace std;
class MapLoader {
private:
	
public:
	MapLoader();
	~MapLoader();
	bool validMap(string path);
	Map * loadMap();

};
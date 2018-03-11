#include "stdafx.h"
#include "MapLoader.h"
#include "MapChecker.h"
#include <sstream>
MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

bool MapLoader::validMap(string path)
{
	vector <Region*> regions;
	ifstream myReadFile;
	myReadFile.open(path);
	string output;
	string numRegion;
	int numberOfRegions = 0;
	regex r("^[0-9]{1,2};[0-9]{1,2}(,[0-9]{1,2})*;[0-1]{1};[1-9]{1,2};[1-9]{1,2};[0-9]{1,2}(,[0-9]{1,2})*;[0-1]{1}$");
	//First run to verify format of the file
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> output;
			if (!regex_match(output, r))
			{
				cout << "The map format is invalid" << endl;
				myReadFile.close();
				return false;
			}
			numberOfRegions++;

		}
	}
	myReadFile.close();
	string arr[7];
	regions.resize(numberOfRegions);
	for (size_t l = 0; l < numberOfRegions; l++)
	{
		regions.at(l) = new Region();
	}
	myReadFile.open(path);
	//Second run through the file to verify if the information is correct
	if (myReadFile.is_open()) {
		
		int i = 0;

		
		while (!myReadFile.eof()) {
			int j = 0;
			myReadFile >> output;
			std::replace(output.begin(), output.end(), ';', ' ');
			stringstream ssin(output);
			while (ssin.good() && j < 7) {
				ssin >> arr[j];
				++j;
			}
			int value = 0;
			stringstream x(arr[0]);
			x >> value;
			if (value > i) {
				cout << "The map format is invalid" << endl;
				for (size_t b = 0; b < regions.size(); b++)
				{
					delete(regions.at(b));
				}
				regions.clear();
				myReadFile.close();
				return false;
			}
			vector<int> array;
			std::replace(arr[1].begin(), arr[1].end(), ',', ' ');
			stringstream ssin2(arr[1]);
			string temp= "";
			int adj = 0;
			while (ssin2>>temp) {
				stringstream v(temp);
				v >> adj;
				array.push_back(adj);
			}

			for (size_t k = 0; k < array.size(); k++)
			{
				if (array.at(k) == i || array.at(k)>numberOfRegions) {
					cout << "The region points to itself or to a region that doesnt exist" << endl;
					for (size_t b = 0; b < regions.size(); b++)
					{
						delete(regions.at(b));
					}
					regions.clear();
					myReadFile.close();
					return false;
				}
			}
			int armyUnit = 0;
			stringstream army(arr[2]);
			army >> armyUnit;

			int regionType = 0;
			stringstream region(arr[3]);
			region >> regionType;


			int specialType = 0;
			stringstream special(arr[4]);
			special >> specialType;

			if (regionType < 1 || regionType > 6) {
				cout << "The region type is invalid" << endl;
				for (size_t b = 0; b < regions.size(); b++)
				{
					delete(regions.at(b));
				}
				regions.clear();
				myReadFile.close();
				return false;
			}
			if (specialType < 1 || specialType > 6) {
				cout << "The region special tile is invalid" << endl;
				for (size_t b = 0; b < regions.size(); b++)
				{
					delete(regions.at(b));
				}
				regions.clear();
				myReadFile.close();
				return false;
			}
			vector<int> arrayOtherTiles;
			std::replace(arr[5].begin(), arr[5].end(), ',', ' ');
			stringstream ssin3(arr[5]);
			string temp2 = "";
			int other = 0;
			while (ssin3 >> temp2) {
				stringstream v(temp2);
				v >> other;
				arrayOtherTiles.push_back(other);
			}
			for (size_t g = 0; g < arrayOtherTiles.size(); g++)
			{
				if (arrayOtherTiles.at(g) < 1 || arrayOtherTiles.at(g) > 5) {
					cout << "The region other tile is invalid" << endl;
					for (size_t b = 0; b < regions.size(); b++)
					{
						delete(regions.at(b));
					}
					regions.clear();
					myReadFile.close();
					return false;
				}
			}
			if(arr[6] =="1"){
				regions.at(i)->setIsEdge(true);
			}
			else if (arr[6] == "0") {
				regions.at(i)->setIsEdge(false);
			}
			else {
				cout << "The region special tile is invalid" << endl;
				for (size_t b = 0; b < regions.size(); b++)
				{
					delete(regions.at(b));
				}
				regions.clear();
				myReadFile.close();
				return false;
			}

			vector<OtherTiles *> ot;
			ot.resize(arrayOtherTiles.size());
			for (size_t a = 0; a < arrayOtherTiles.size(); a++)
			{
				switch (arrayOtherTiles.at(a)) {
				case 1:
					ot.at(a) = new Standard();
					break;
				case 2:
					ot.at(a) = new Mine();
					break;
				case 3:
					ot.at(a) = new Magic();
					break;
				case 4:
					ot.at(a) = new FarmLand();
					break;
				case 5:
					ot.at(a) = new Cavern();
					break;
				};
			}
			RegionType * rt;
			Special_Tile * st;
			switch (regionType) {
			case 1:
				rt = new Mountain();
				break;
			case 2:
				rt = new Hill();
				break;
			case 3: 
				rt = new Swamp();
				break;
			case 4 :
				rt = new Field();
				break;
			case 5 :
				rt = new Water();
				break;
			case 6:
				rt = new Forest_Type();
			default:
				break;
			};
			switch (specialType) {
			case 1:
				st = new Normal();
				break;
			case 2:
				st = new Troll_Lair();
				break;
			case 3 :
				st = new Fortress();
				break;
			case 4:
				st = new Mountain_Tile();
				break;
			case 5:
				st = new Encampment();
				break;
			case 6:
				st = new Hole_In_Ground();
				break;
			default:
				break;
			};
			regions.at(i)->setArmy(armyUnit);
			regions.at(i)->setRegionSpecial(st);
			regions.at(i)->setRegionType(rt);
			regions.at(i)->setOtherTypeTile(ot);
			for (size_t n = 0; n < array.size(); n++)
			{
				regions.at(i)->setAdjacencyAt(n, regions.at(array.at(n)));
			}
			
			i++;

		}
	}
	myReadFile.close();
	MapChecker * mc = new MapChecker(regions);
	if (!mc->areNodesConnectedBothWays() || !mc->isMapLinked()) {
		cout << "The map is invalid" << endl;
		for (size_t b = 0; b < regions.size(); b++)
		{
			delete(regions.at(b));
		}
		regions.clear();
		return false;
	}
	
	cout << "The map is valid" << endl;
	mapRegion = regions;
	return true;
}

vector<Region *>  MapLoader::loadMap()
{
	return mapRegion;
}

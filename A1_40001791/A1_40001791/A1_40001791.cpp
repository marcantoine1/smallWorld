// Assignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Map.h"
#include "Region.h"
#include "MapChecker.h"
#include "Dice_Roll.h"
#include "RegionType.h"
#include <ctime>
#include "MapLoader.h"
#include "DeckOfCards.h"
using namespace std;
int main()
{
	srand(time(NULL));
	bool validMapNumber = false;
	bool validMap = false;
	bool validPlayerNumber = false;
	int number;
	int numberPlayers;
	Map * map = new Map();
	vector<Player *> players ;
	MapLoader * ml = new MapLoader();
	cout << "Welcome to SmallWorld windows application version 2.0" << endl;
	cout << "Which map will you pick?" << endl;
	cout << "Map1 : 1" << endl;
	cout << "Map2 : 2" << endl;
	cout << "Map3 : 3" << endl;
	cout << "Map4 : 4" << endl;
	do {
	
	cin >> number;
	if (cin.good())
	{
		switch (number) {
		case 1:
			validMapNumber = true;
			if (ml->validMap("Maps/map1.txt") ){
				map->setMap(ml->loadMap());
				validMap = true;
			}
			else {
				cout << "The map you have chosen is invalid. Please make sure the map format is valid or choose another map" << endl;
			}
			break;
		case 2:
			validMapNumber = true;
			if (ml->validMap("Maps/map2.txt")) {
				map->setMap(ml->loadMap());
				validMap = true;
			}
			else {
				cout << "The map you have chosen is invalid. Please make sure the map format is valid or choose another map" << endl;
			}
			break;
		case 3:
			validMapNumber = true;
			if (ml->validMap("Maps/map3.txt")) {
				map->setMap(ml->loadMap());
				validMap = true;
			}
			else {
				cout << "The map you have chosen is invalid. Please make sure the map format is valid or choose another map" << endl;
			}
			break;
		case 4:
			validMapNumber = true;
			if (ml->validMap("Maps/map4.txt")) {
				map->setMap(ml->loadMap());
				validMap = true;
			}
			else {
				cout << "The map you have chosen is invalid. Please make sure the map format is valid or choose another map" << endl;
			}
			break;
		default:
			cout << "Please enter a number between 1 and 4" << endl;
			break;
		}
	}
	else {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a number between 1 and 4" << endl;
	}
	} while (!validMapNumber || !validMap);
	cout << "How many people will play?" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;
	cout << "5" << endl;
	do {

		cin >> numberPlayers;
		if (cin.good())
		{
			switch (numberPlayers) {
			case 2:
				validPlayerNumber = true;
				players.resize(2);
				players.at(0) = new Player();
				players.at(1) = new Player();
				map->setPlayers(players);
				map->setNumberTurns(10);
				break;
			case 3:
				validPlayerNumber = true;
				players.resize(3);
				players.at(0) = new Player();
				players.at(1) = new Player();
				players.at(2) = new Player();
				map->setPlayers(players);
				map->setNumberTurns(10);
				break;
			case 4:
				validPlayerNumber = true;
				players.resize(4);
				players.at(0) = new Player();
				players.at(1) = new Player();
				players.at(2) = new Player();
				players.at(3) = new Player();
				map->setPlayers(players);
				map->setNumberTurns(9);
				break;
			case 5:
				validPlayerNumber = true;
				players.resize(5);
				players.at(0) = new Player();
				players.at(1) = new Player();
				players.at(2) = new Player();
				players.at(3) = new Player();
				players.at(4) = new Player();
				map->setPlayers(players);
				map->setNumberTurns(8);
				break;
			default:
				cout << "Please enter a number between 2 and 5" << endl;
				break;
			}
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a number between 2 and 5" << endl;
		}
	} while (!validPlayerNumber);
	vector<Race *> vectorRace;
	vectorRace.resize(14);
	vector<Special_Power *> vectorPower;
	vectorPower.resize(20);
	vectorRace.at(0) = new Amazon();
	vectorRace.at(1) = new Dwarves();
	vectorRace.at(2) = new Elves();
	vectorRace.at(3) = new Ghouls();
	vectorRace.at(4) = new Giants();
	vectorRace.at(5) = new Halflings();
	vectorRace.at(6) = new Humans();
	vectorRace.at(7) = new Orcs();
	vectorRace.at(8) = new Ratmen();
	vectorRace.at(9) = new Skeletons();
	vectorRace.at(10) = new Sorcerers();
	vectorRace.at(11) = new Tritons();
	vectorRace.at(12) = new Trolls();
	vectorRace.at(13) = new Wizards();

	vectorPower.at(0) = new Alchemist();
	vectorPower.at(1) = new Berserk();
	vectorPower.at(2) = new Bivouacking();
	vectorPower.at(3) = new Commando();
	vectorPower.at(4) = new Diplomat();
	vectorPower.at(5) = new DragonMaster();
	vectorPower.at(6) = new Flying();
	vectorPower.at(7) = new Forest();
	vectorPower.at(8) = new Fortified();
	vectorPower.at(9) = new Heroic();
	vectorPower.at(10) = new Hill_SP();
	vectorPower.at(11) = new Merchant();
	vectorPower.at(12) = new Mounted();
	vectorPower.at(13) = new Pillaging();
	vectorPower.at(14) = new Seafaring();
	vectorPower.at(15) = new Spirit();
	vectorPower.at(16) = new Stout();
	vectorPower.at(17) = new Swamp_SP();
	vectorPower.at(18) = new Underworld();
	vectorPower.at(19) = new Wealthy();

	cout << "Turn number: 1" << endl;
	for (size_t i = 0; i < map->getPlayers().size(); i++)
	{
		
		map->getPlayers().at(i)->setPlayerNumber(i + 1);
		cout << "Player " << map->getPlayers().at(i)->getPlayerNumber() << "'s turn" << endl;
		map->getPlayers().at(i)->picks_race(vectorRace,vectorPower);
		int l = 0;
		for (size_t j = 0; j < vectorRace.size(); j++)
		{
			if (vectorRace.at(j)->getName() == map->getPlayers().at(i)->getRace()->getName()) {
				l = j;
			}
		}
		vectorRace.erase(vectorRace.begin() + l);
		for (size_t k = 0; k < vectorPower.size(); k++)
		{
			if (vectorPower.at(k)->getName() == map->getPlayers().at(i)->getPower()->getName()) {
				l = k;
			}
		}
		vectorPower.erase(vectorPower.begin() + l);
		map->getPlayers().at(i)->setPlayerNumber(i+1);
		map->getPlayers().at(i)->firstConquest(map);
		
		bool continueConquest = true;
		bool validInputConquest = false;
		while (continueConquest) {
			if (!map->getPlayers().at(i)->getDeclineStatus() && !map->getPlayers().at(i)->getRedeploymentStatus()) {
			cout << "Would you like to do more conquests?" << endl;
			cout << "0 : No" << endl;
			cout << "1 : Yes" << endl;
			do {
				cin >> continueConquest;
				if (cin.good())
				{
					validInputConquest = true;

					if (continueConquest) {

						map->getPlayers().at(i)->findAllPossibleConquests(map);
					}
					else {
						map->getPlayers().at(i)->redeploy();
						map->getPlayers().at(i)->scores();
					}
				}
				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Please enter a number between 0 and 1" << endl;
				}
			} while (!validInputConquest);
		}
			else {
				continueConquest = false;
			}
		}
		
		
	}
	map->nextTurn();
	while (map->getCurrentTurn() <= map->getNumberTurns()) {
		for (size_t i = 0; i < map->getPlayers().size(); i++)
		{
			
			cout << "Player " << i+1<< "'s turn"<< endl;
			map->getPlayers().at(i)->readyTroops();
			map->getPlayers().at(i)->abandonRegion();
			if (map->getPlayers().at(i)->getDeclineStatus()) {
				map->getPlayers().at(i)->goIntoDecline();
				map->getPlayers().at(i)->firstConquest(map);
			}
			else {
				map->getPlayers().at(i)->findAllPossibleConquests(map);
			}
			bool continueConquest = true;
			bool validInputConquest = false;

			while (continueConquest) {
				if (!map->getPlayers().at(i)->getDeclineStatus() && !map->getPlayers().at(i)->getRedeploymentStatus()) {
					cout << "Would you like to do more conquests?" << endl;
					cout << "0 : No" << endl;
					cout << "1 : Yes" << endl;
					do {
						cin >> continueConquest;
						if (cin.good())
						{
							validInputConquest = true;

							if (continueConquest) {

								map->getPlayers().at(i)->findAllPossibleConquests(map);
							}
							else {
								map->getPlayers().at(i)->redeploy();
								map->getPlayers().at(i)->scores();
							}
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cout << "Please enter a number between 0 and 1" << endl;
						}
					} while (!validInputConquest);
				}
				else {
					continueConquest = false;
				}
			}
			map->nextTurn();
		}
	}
	return 0;
}


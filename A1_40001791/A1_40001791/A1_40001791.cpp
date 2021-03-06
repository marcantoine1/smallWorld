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
#include "PlayerDummy.h"
#include "StatisticDummy.h"
#include "Agressive.h"
#include "Random.h"
#include "Defensive.h"
#include "Moderate.h"
#include "StatisticDummy2.h"
#include "StatisticDummy23.h"
#include "StatisticDummy3.h"
#include <stdexcept>
#include "InvalidInputException.h"
class PlayerDummy;
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
	cout << "Welcome to SmallWorld windows application version 3.0" << endl;
	cout << "Which map will you pick?" << endl;
	cout << "Map1 : 1" << endl;
	cout << "Map2 : 2" << endl;
	cout << "Map3 : 3" << endl;
	cout << "Map4 : 4" << endl;
	do {
		try {
			cin >> number;
			if (cin.good())
			{
				switch (number) {
				case 1:
					validMapNumber = true;
					if (ml->validMap("Maps/map1.txt")) {
						map->setMap(ml->loadMap());
						validMap = true;
					}
					else {
						throw std::runtime_error("The map you have chosen is invalid. Please make sure the map format is valid or choose another map");
					}
					break;
				case 2:
					validMapNumber = true;
					if (ml->validMap("Maps/map2.txt")) {
						map->setMap(ml->loadMap());
						validMap = true;
					}
					else {
						throw std::runtime_error("The map you have chosen is invalid. Please make sure the map format is valid or choose another map");
					}
					break;
				case 3:
					validMapNumber = true;
					if (ml->validMap("Maps/map3.txt")) {
						map->setMap(ml->loadMap());
						validMap = true;
					}
					else {
						throw std::runtime_error("The map you have chosen is invalid. Please make sure the map format is valid or choose another map");
					}
					break;
				case 4:
					validMapNumber = true;
					if (ml->validMap("Maps/map4.txt")) {
						map->setMap(ml->loadMap());
						validMap = true;
					}
					else {
						throw std::runtime_error("The map you have chosen is invalid. Please make sure the map format is valid or choose another map");
						
					}
					break;
				default:
					throw std::runtime_error("Please enter a number between 1 and 4");
					break;
				}
			}
			else {
				
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw std::runtime_error("Please enter a number between 1 and 4");
				//cout << "Please enter a number between 1 and 4" << endl;
			}
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what() << endl;;
		}
	} while (!validMapNumber || !validMap);
	cout << "How many people will play?" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;
	cout << "5" << endl;
	do {
		try {
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
					throw std::runtime_error("Please enter a number between 2 and 5");
					break;
				}
			}
			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				throw std::runtime_error("Please enter a number between 2 and 5");
				//cout << "Please enter a number between 2 and 5" << endl;
			}
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what() << endl;;
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

	bool notifyForObs = true;
	bool activeObs2 = false;
	bool activeObs3 = false;
	PlayerDummy * dummyP = new PlayerDummy(); ;
	StatisticDummy * dummyS = new StatisticDummy();
	dummyS->Attach(map);
	dummyS->changeTurn(1);
	switch (map->getPlayers().size()) {
	case 5:
		map->getPlayers().at(4)->setStrategy(new Random());
	case 4:
		map->getPlayers().at(3)->setStrategy(new Moderate());
	case 3:
		map->getPlayers().at(2)->setStrategy(new Defensive());
	case 2:
		map->getPlayers().at(1)->setStrategy(new Agressive());
		break;
	};
	int option = 0;
	bool validInputObs = false;
	bool breakLoop = false;
	for (size_t i = 0; i < map->getPlayers().size(); i++)
	{
		dummyP->Attach(map->getPlayers().at(i));
		if(i == 0){
			if (notifyForObs) {
				cout << "Which observers would you like to activate/deactivate" << endl;
				cout << "1 : Observer 2 : Player dominion observer to display map conquests percentage" << endl;
				cout << "2 : Observer 3 : Victory coin display" << endl;
				cout << "3 : exit and not get notified for other turns" << endl;
				cout << "4 : exit and get notified for other turns" << endl;
				do {
					try {
						cin >> option;
						if (cin.good()) {
							switch (option) {
							case 1:
								if (activeObs2) {
									activeObs2 = false;
									cout << "Observer 2 has been deactivated" << endl;
								}
								else {
									activeObs2 = true;
									cout << "Observer 2 has been activated" << endl;
								}

								validInputObs = true;


								break;
							case 2:
								if (activeObs3) {
									activeObs3 = false;
									cout << "Observer 3 has been deactivated" << endl;
								}
								else {
									activeObs3 = true;
									cout << "Observer 3 has been activated" << endl;
								}
								validInputObs = true;
								break;
							case 3:
								notifyForObs = false;
								breakLoop = true;
								validInputObs = true;
								break;
							case 4:
								breakLoop = true;
								validInputObs = true;
								break;
							default:
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								throw std::runtime_error("Please enter a number between 1 and 4");
								break;
							};
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							throw std::runtime_error("Please enter a number between 1 and 4");
						
						}
					}
					catch (const std::runtime_error& e) {
						std::cout << e.what() << endl;;
					}
				} while (!validInputObs || !breakLoop);
				if (!activeObs2 && !activeObs3) {
					dummyS = new StatisticDummy();
					dummyS->Attach(map);
				}
				if (activeObs2 && !activeObs3) {
					dummyS = new StatisticDummy2();
					dummyS->Attach(map);
				}
				if (activeObs3 && !activeObs2) {
					dummyS = new StatisticDummy3();
					dummyS->Attach(map);
				}
				if (activeObs2 && activeObs3) {
					dummyS = new StatisticDummy23();
					dummyS->Attach(map);
				}
			}

		}
		map->getPlayers().at(i)->setPlayerNumber(i + 1);
		cout << "Player " << map->getPlayers().at(i)->getPlayerNumber() << "'s turn" << endl;
		dummyP->changePhase("Pick Race");
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
		dummyP->changePhase("Conquest");
		if (i == 0) {

		
		map->getPlayers().at(i)->firstConquest(map);
		dummyS->changeConquestPercent(dummyS->getMapObs()->calculatePercentOwnership());
		bool continueConquest = true;
		bool validInputConquest = false;
		while (continueConquest) {
			if (!map->getPlayers().at(i)->getDeclineStatus() && !map->getPlayers().at(i)->getRedeploymentStatus()) {
			cout << "Would you like to do more conquests?" << endl;
			cout << "0 : No" << endl;
			cout << "1 : Yes" << endl;
			do {
				try {
				cin >> continueConquest;
				if (cin.good())
				{
					validInputConquest = true;

					if (continueConquest) {

						map->getPlayers().at(i)->findAllPossibleConquests(map);
						dummyS->changeConquestPercent(dummyS->getMapObs()->calculatePercentOwnership());
					}
					else {
						dummyP->changePhase("Redeploy");
						map->getPlayers().at(i)->redeploy(map);
						dummyP->changePhase("Score");
						vector<string> s = map->getPlayers().at(i)->scores();
						dummyS->showConquestResult(s);
					}
				}
				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					throw std::runtime_error("Please enter a number between 0 and 1");
					
				}
			}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << endl;;
				}
			} while (!validInputConquest);
		}
			else {
				continueConquest = false;
				if (map->getPlayers().at(i)->getDeclineStatus()) {
					dummyP->changePhase("Decline");
					Race * racePutBack = map->getPlayers().at(i)->getRace();
					Special_Power * spPutBack = map->getPlayers().at(i)->getPower();
					map->getPlayers().at(i)->goIntoDecline();
					map->getPlayers().at(i)->picks_race(vectorRace, vectorPower);
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
					vectorPower.push_back(spPutBack);
					vectorRace.push_back(racePutBack);
				}
			}
		}
		}
		else {
			map->getPlayers().at(i)->AIFirstConquest(map);
			dummyP->changePhase("Redeploy");
			map->getPlayers().at(i)->redeploy(map);
			if (map->getPlayers().at(i)->getDeclineStatus()) {
				dummyP->changePhase("Decline");
				Race * racePutBack = map->getPlayers().at(i)->getRace();
				Special_Power * spPutBack = map->getPlayers().at(i)->getPower();
				map->getPlayers().at(i)->goIntoDecline();
				dummyP->changePhase("Pick Race");
				map->getPlayers().at(i)->picks_race(vectorRace, vectorPower);
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
				vectorPower.push_back(spPutBack);
				vectorRace.push_back(racePutBack);
			}
			dummyP->changePhase("Scores");
			map->getPlayers().at(i)->scores();
		}
		
		dummyP->Detach(map->getPlayers().at(i));
	}
	map->nextTurn();
	int turnNumber = 1;
	while (map->getCurrentTurn() <= map->getNumberTurns()) {
		dummyS->changeTurn(turnNumber +1);
		for (size_t i = 0; i < map->getPlayers().size(); i++)
		{
			if (i == 0) {
				validInputObs = false;
			    breakLoop = false;
				if (notifyForObs) {
					cout << "Which observers would you like to activate/deactivate" << endl;
					cout << "1 : Observer 2 : Player dominion observer to display map conquests percentage" << endl;
					cout << "2 : Observer 3 : Victory coin display" << endl;
					cout << "3 : exit and not get notified for other turns" << endl;
					cout << "4 : exit and get notified for other turns" << endl;
					do {
						try {
							cin >> option;
							if (cin.good()) {
								switch (option) {
								case 1:
									if (activeObs2) {
										activeObs2 = false;
										cout << "Observer 2 has been deactivated" << endl;
									}
									else {
										activeObs2 = true;
										cout << "Observer 2 has been activated" << endl;
									}

									validInputObs = true;


									break;
								case 2:
									if (activeObs3) {
										activeObs3 = false;
										cout << "Observer 3 has been deactivated" << endl;
									}
									else {
										activeObs3 = true;
										cout << "Observer 3 has been activated" << endl;
									}
									validInputObs = true;
									break;
								case 3:
									notifyForObs = false;
									breakLoop = true;
									validInputObs = true;
									break;
								case 4:
									breakLoop = true;
									validInputObs = true;
									break;
								default:
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									throw std::runtime_error("Please enter a number between 1 and 4");
									break;
								};
							}
							else {
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								throw std::runtime_error("Please enter a number between 1 and 4");

							}
						}
						catch (const std::runtime_error& e) {
							std::cout << e.what() << endl;;
						}
					} while (!validInputObs || !breakLoop);
					if (!activeObs2 && !activeObs3) {
						dummyS = new StatisticDummy();
						dummyS->Attach(map);
					}
					if (activeObs2 && !activeObs3) {
						dummyS = new StatisticDummy2();
						dummyS->Attach(map);
					}
					if (activeObs3 && !activeObs2) {
						dummyS = new StatisticDummy3();
						dummyS->Attach(map);
					}
					if (activeObs2 && activeObs3) {
						dummyS = new StatisticDummy23();
						dummyS->Attach(map);
					}
				}

			}
			
			dummyP->Attach(map->getPlayers().at(i));
			cout << "Player " << i+1<< "'s turn"<< endl;
			dummyP->changePhase("ReadyTroops");
			map->getPlayers().at(i)->readyTroops();
			dummyP->changePhase("Abandon region");
			if (i == 0) {
				map->getPlayers().at(i)->abandonRegion(map);
			}
			if (map->getPlayers().at(i)->getDeclineStatus()) {
				dummyP->changePhase("Decline");
				Race * racePutBack = map->getPlayers().at(i)->getRace();
				Special_Power * spPutBack = map->getPlayers().at(i)->getPower();
				map->getPlayers().at(i)->goIntoDecline();
				dummyP->changePhase("Pick Race");
				map->getPlayers().at(i)->picks_race(vectorRace, vectorPower);
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
				vectorPower.push_back(spPutBack);
				vectorRace.push_back(racePutBack);
			}
			else {
				if (i == 0) {
					if (map->getPlayers().at(i)->getRegions().size() == 0) {
						map->getPlayers().at(i)->firstConquest(map);
					}
					else {
						map->getPlayers().at(i)->findAllPossibleConquests(map);
					}
					dummyS->changeConquestPercent(dummyS->getMapObs()->calculatePercentOwnership());
				}
			}
			bool continueConquest = true;
			bool validInputConquest = false;
			if (i == 0) {
				while (continueConquest) {
					if (!map->getPlayers().at(i)->getDeclineStatus() && !map->getPlayers().at(i)->getRedeploymentStatus()) {
						dummyP->changePhase("Conquest");
						cout << "Would you like to do more conquests?" << endl;
						cout << "0 : No" << endl;
						cout << "1 : Yes" << endl;
						do {
							try {
								cin >> continueConquest;
								if (cin.good())
								{
									validInputConquest = true;

									if (continueConquest) {
										map->getPlayers().at(i)->findAllPossibleConquests(map);
										dummyS->changeConquestPercent(dummyS->getMapObs()->calculatePercentOwnership());
									}
									else {
										dummyP->changePhase("Redeploy");
										map->getPlayers().at(i)->redeploy(map);
										dummyP->changePhase("Score");
										vector<string> s = map->getPlayers().at(i)->scores();
										dummyS->showConquestResult(s);
									}
								}
								else {
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									throw std::runtime_error("Please enter a number between 0 and 1");
									
								}
							}
							catch (const std::runtime_error& e) {
								std::cout << e.what() << endl;;
							}
						} while (!validInputConquest);
					}
					else {
						continueConquest = false;
						if (map->getPlayers().at(i)->getDeclineStatus()) {
							dummyP->changePhase("Decline");
							Race * racePutBack = map->getPlayers().at(i)->getRace();
							Special_Power * spPutBack = map->getPlayers().at(i)->getPower();
							map->getPlayers().at(i)->goIntoDecline();
							dummyP->changePhase("Pick Race");
							map->getPlayers().at(i)->picks_race(vectorRace, vectorPower);
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
							
							vectorPower.push_back(spPutBack);
							vectorRace.push_back(racePutBack);
						}
					}
				}
			}
			else {
				dummyP->changePhase("Conquest");
				map->getPlayers().at(i)->AIOtherConquest(map);
				dummyP->changePhase("Redeploy");
				map->getPlayers().at(i)->redeploy(map);
				if (map->getPlayers().at(i)->getDeclineStatus()) {
					dummyP->changePhase("Decline");
					Race * racePutBack = map->getPlayers().at(i)->getRace();
					Special_Power * spPutBack = map->getPlayers().at(i)->getPower();
					map->getPlayers().at(i)->goIntoDecline();
					dummyP->changePhase("Pick Race");
					map->getPlayers().at(i)->picks_race(vectorRace, vectorPower);
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
					vectorPower.push_back(spPutBack);
					vectorRace.push_back(racePutBack);
				}
				dummyP->changePhase("Scores");
				map->getPlayers().at(i)->scores();
			}
			dummyP->Detach(map->getPlayers().at(i));
		}
		turnNumber++;
		map->nextTurn();
	}
	int max = 0;
	for (size_t i = 0; i < map->getPlayers().size(); i++)
	{
		if (map->getPlayers().at(i)->totalMoney() > max) {
			max = i;
		}
	}
	cout << "Player " << max + 1 << " wins !" << endl;
	dummyS->Detach(map);
	system("PAUSE");
	return 0;
}


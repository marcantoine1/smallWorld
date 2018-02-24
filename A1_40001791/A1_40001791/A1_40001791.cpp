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
	int number;
	cout << "Welcome to SmallWorld windows application version 1.0" << endl;
	cout << "How many players will play the game? Select the appropriate number and press enter" << endl;
	cout << "(2)" << endl;
	cout << "(3)" << endl;
	cout << "(4)" << endl;
	cout << "(5)" << endl;
	cin >> number;
	/*
	Valid Map both ways test
	*/
	vector <Region*> regions;
	regions.resize(3);
	regions.at(0) = new Region(new Hill,new Hole_In_Ground);
	regions.at(1) = new Region(new Mountain,new Mountain_Tile);
	regions.at(2) = new Region(new Swamp,new Fortress, 1);
	regions.at(0)->setAdjacencyAt(0, regions.at(1));
	regions.at(0)->setAdjacencyAt(1, regions.at(2));
	regions.at(1)->setAdjacencyAt(0, regions.at(0));
	regions.at(1)->setAdjacencyAt(1, regions.at(2));
	regions.at(2)->setAdjacencyAt(0, regions.at(1));
	regions.at(2)->setAdjacencyAt(1, regions.at(0));




	MapChecker * mapC = new MapChecker(regions);
	mapC->areNodesConnectedBothWays();

	/*
	Invalid map both ways test
	*/
	vector <Region*> regions2;
	regions2.resize(3);
	regions2.at(0) = new Region(new Hill, new Normal);
	regions2.at(1) = new Region(new Mountain,new Mountain_Tile);
	regions2.at(2) = new Region(new Swamp,new Normal, 1);
	regions2.at(0)->setAdjacencyAt(0, regions2.at(1));
	regions2.at(0)->setAdjacencyAt(1, regions2.at(2));
	regions2.at(1)->setAdjacencyAt(0, regions2.at(0));
	regions2.at(1)->setAdjacencyAt(1, regions2.at(2));
	regions2.at(2)->setAdjacencyAt(0, regions2.at(1));

	MapChecker * mapC2 = new MapChecker(regions2);
	mapC2->areNodesConnectedBothWays();

	/*
	Valid all nodes linked
	*/
	mapC->isMapLinked();

	/*
	Invalid not all nodes linked
	*/

	vector <Region*> regions3;
	regions3.resize(5);
	regions3.at(0) = new Region(new Hill,new Normal);
	regions3.at(1) = new Region(new Mountain, new Mountain_Tile);
	regions3.at(2) = new Region(new Swamp,new Normal, 1);
	regions3.at(3) = new Region(new Water, new Normal, 1);
	regions3.at(4) = new Region(new Field, new Normal, 1);
	regions3.at(0)->setAdjacencyAt(0, regions3.at(1));
	regions3.at(0)->setAdjacencyAt(1, regions3.at(2));
	regions3.at(1)->setAdjacencyAt(0, regions3.at(0));
	regions3.at(1)->setAdjacencyAt(1, regions3.at(2));
	regions3.at(2)->setAdjacencyAt(0, regions3.at(1));
	regions3.at(2)->setAdjacencyAt(1, regions3.at(0));
	regions3.at(3)->setAdjacencyAt(0, regions3.at(4));
	regions3.at(4)->setAdjacencyAt(0, regions3.at(3));
	MapChecker * mapC3 = new MapChecker(regions3);
	mapC3->areNodesConnectedBothWays();
	mapC3->isMapLinked();

	Dice_Roll * dr = new Dice_Roll();
	dr->roll();

	dr->roll();
	dr->roll();
	dr->roll();

	dr->print_results();

	Player * p = new Player();
	p->picks_race();
	

	MapLoader * ml = new MapLoader();
	ml->validMap("map2.txt");
	ml->validMap("map3.txt");
	ml->validMap("map4.txt");


	DeckOfCards * doc = new DeckOfCards();
	doc->drawAllPowers();
	doc->drawAllRaces();
	doc->drawAllSpecialPowerTiles();
	doc->drawAllTiles();
	doc->drawAllTokens();

	delete(doc);
	do {

	} while (true);
	return 0;
}


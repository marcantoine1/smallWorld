#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Race.h"
#include "Special_Power.h"
#include "Special_Tile.h"
#include "Special_Power_Tile.h"
#include "RaceTokens.h"
using namespace std;
class DeckOfCards {
private:
	vector<Race *> raceDeck;
	vector<Special_Power *> powerDeck;
	vector<Special_Tile *> tileDeck;
	vector<RaceTokens *> tokenDeck;
	vector<Special_Power_Tile *> specialPowerTileDeck;
public:

	DeckOfCards();
	~DeckOfCards();

	void drawAllRaces();
	void drawAllPowers();
	void drawAllTiles();
	void drawAllTokens();
	void drawAllSpecialPowerTiles();



};

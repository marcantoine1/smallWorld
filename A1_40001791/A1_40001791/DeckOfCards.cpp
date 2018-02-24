#include "stdafx.h"
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	raceDeck.resize(14);
	powerDeck.resize(20);
	tokenDeck.resize(14);
	tileDeck.resize(6);
	specialPowerTileDeck.resize(2);

	raceDeck.at(0) = new Amazon();
	raceDeck.at(1) = new Halflings();
	raceDeck.at(2) = new Dwarves();
	raceDeck.at(3) = new Humans();
	raceDeck.at(4) = new Orcs();
	raceDeck.at(5) = new Ratmen();
	raceDeck.at(6) = new Elves();
	raceDeck.at(7) = new Skeletons();
	raceDeck.at(8) = new Ghouls();
	raceDeck.at(9) = new Sorcerers();
	raceDeck.at(10) = new Tritons();
	raceDeck.at(11) = new Trolls();
	raceDeck.at(12) = new Wizards();
	raceDeck.at(13) = new Giants();

	powerDeck.at(0) = new Alchemist();
	powerDeck.at(1) = new Bivouacking();
	powerDeck.at(2) = new Berserk();
	powerDeck.at(3) = new Commando();
	powerDeck.at(4) = new Diplomat();
	powerDeck.at(5) = new DragonMaster();
	powerDeck.at(6) = new Merchant();
	powerDeck.at(7) = new Mounted();
	powerDeck.at(8) = new Flying();
	powerDeck.at(9) = new Pillaging();
	powerDeck.at(10) = new Forest();
	powerDeck.at(11) = new Seafaring();
	powerDeck.at(12) = new Fortified();
	powerDeck.at(13) = new Spirit();
	powerDeck.at(14) = new Heroic();
	powerDeck.at(15) = new Stout();
	powerDeck.at(16) = new Hill_SP();
	powerDeck.at(17) = new Swamp_SP();
	powerDeck.at(18) = new Underworld();
	powerDeck.at(19) = new Wealthy();

	tileDeck.at(0) = new Normal();
	tileDeck.at(1) = new Troll_Lair();
	tileDeck.at(2) = new Fortress();
	tileDeck.at(3) = new Mountain_Tile();
	tileDeck.at(4) = new Encampment();
	tileDeck.at(5) = new Hole_In_Ground();


	tokenDeck.at(0) = new AmazonTokens();
	tokenDeck.at(1) = new HalflingsTokens();
	tokenDeck.at(2) = new DwarvesTokens();
	tokenDeck.at(3) = new HumansTokens();
	tokenDeck.at(4) = new OrcsTokens();
	tokenDeck.at(5) = new RatmenTokens();
	tokenDeck.at(6) = new ElvesTokens();
	tokenDeck.at(7) = new SkeletonsTokens();
	tokenDeck.at(8) = new GhoulsTokens();
	tokenDeck.at(9) = new SorcerersTokens();
	tokenDeck.at(10) = new TritonsTokens();
	tokenDeck.at(11) = new TrollsTokens();
	tokenDeck.at(12) = new WizardsTokens();
	tokenDeck.at(13) = new GiantsTokens();

	specialPowerTileDeck.at(0) = new Dragon();
	specialPowerTileDeck.at(1) = new Hero();
}

DeckOfCards::~DeckOfCards()
{
	for (size_t i = 0; i < raceDeck.size(); i++)
	{
		delete(raceDeck.at(i));
	}
	raceDeck.clear();
	for (size_t i = 0; i < tokenDeck.size(); i++)
	{
		delete(tokenDeck.at(i));
	}
	tokenDeck.clear();
	for (size_t i = 0; i < powerDeck.size(); i++)
	{
		delete(powerDeck.at(i));
	}
	powerDeck.clear();
	for (size_t i = 0; i < tileDeck.size(); i++)
	{
		delete(tileDeck.at(i));
	}
	tileDeck.clear();
	for (size_t i = 0; i < specialPowerTileDeck.size(); i++)
	{
		delete(specialPowerTileDeck.at(i));
	}
	specialPowerTileDeck.clear();
}

void DeckOfCards::drawAllRaces()
{
	for (size_t i = 0; i < raceDeck.size(); i++)
	{
		cout << "Drew a new race :" << raceDeck.at(i)->getName() << endl;
	}
}

void DeckOfCards::drawAllPowers()
{
	for (size_t i = 0; i < powerDeck.size(); i++)
	{
		cout << "Drew a new power :" << powerDeck.at(i)->getName() << endl;
	}
}

void DeckOfCards::drawAllTiles()
{
	for (size_t i = 0; i < tileDeck.size(); i++)
	{
		cout << "Drew a new tile :" << tileDeck.at(i)->getName() << endl;
	}
}

void DeckOfCards::drawAllTokens()
{
	for (size_t i = 0; i < tokenDeck.size(); i++)
	{
		cout << "Drew a new token :" << tokenDeck.at(i)->getName() << endl;
	}
}

void DeckOfCards::drawAllSpecialPowerTiles()
{
	for (size_t i = 0; i < specialPowerTileDeck.size(); i++)
	{
		cout << "Drew a new special power tile modifier :" << specialPowerTileDeck.at(i)->getName() << endl;
	}
}

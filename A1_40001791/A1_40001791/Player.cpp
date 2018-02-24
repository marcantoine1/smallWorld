#include "stdafx.h"
#include "Player.h"




Player::Player()
{
}

Player::~Player()
{
}

void Player::picks_race()
{
	vector<Race *> choiceRace;
	choiceRace.resize(6);
	vector<Special_Power *> choicePower;
	choicePower.resize(6);
	int valRace = (rand() % 14 + 1);
	int valPower = (rand() % 20 + 1);
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


	choiceRace.at(0) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace-1);
	valRace = (rand() % 13 + 1);

	choiceRace.at(1) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % 12 + 1);

	choiceRace.at(2) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % 11 + 1);

	choiceRace.at(3) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % 10 + 1);

	choiceRace.at(4) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % 9 + 1);

	choiceRace.at(5) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);

	choicePower.at(0) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % 19 + 1);

	choicePower.at(1) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % 18 + 1);

	choicePower.at(2) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % 17 + 1);

	choicePower.at(3) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % 16 + 1);

	choicePower.at(4) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % 15 + 1);

	choicePower.at(5) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);

	for (size_t i = 0; i < vectorPower.size(); i++)
	{
		vectorPower.at(i) = nullptr;
		delete(vectorPower.at(i));
		
	}
	for (size_t i = 0; i < vectorRace.size(); i++)
	{
		vectorRace.at(i) = nullptr;
		delete(vectorRace.at(i));
		
	}
	vectorPower.clear();
	vectorRace.clear();
	bool valid = true;
	do {
		cout << "Pick a race and special ability combo" << endl;
		cout << "1 : " << choiceRace.at(0)->getName() << " and " << choicePower.at(0)->getName() << endl;
		cout << "2 : " << choiceRace.at(1)->getName() << " and " << choicePower.at(1)->getName() << endl;
		cout << "3 : " << choiceRace.at(2)->getName() << " and " << choicePower.at(2)->getName() << endl;
		cout << "4 : " << choiceRace.at(3)->getName() << " and " << choicePower.at(3)->getName() << endl;
		cout << "5 : " << choiceRace.at(4)->getName() << " and " << choicePower.at(4)->getName() << endl;
		cout << "6 : " << choiceRace.at(5)->getName() << " and " << choicePower.at(5)->getName() << endl;
		int number;
		cin >> number;
		switch (number) {
		case 1:
			r = choiceRace.at(0);
			sp = choicePower.at(0);
			break;
		case 2:
			if (totalMoney() >= 1) {
				r = choiceRace.at(1);
				sp = choicePower.at(1);

			}
			else {
				cout << "Not enough money" << endl;
				valid = false;
			}
			break;
		case 3:
			if (totalMoney() >= 2) {
				r = choiceRace.at(2);
				sp = choicePower.at(2);
			}
			else {
				cout << "Not enough money" << endl;
				valid = false;
			}
			break;
		case 4:
			if (totalMoney() >= 3) {
				r = choiceRace.at(3);
				sp = choicePower.at(3);
			}
			else {
				cout << "Not enough money" << endl;
				valid = false;
			}
			break;
		case 5:
			if (totalMoney() >= 4) {
				r = choiceRace.at(4);
				sp = choicePower.at(4);
			}
			else {
				cout << "Not enough money" << endl;
				valid = false;
			}
			break;
		case 6:
			if (totalMoney() >= 5) {
				r = choiceRace.at(5);
				sp = choicePower.at(5);
			}
			else {
				cout << "Not enough money" << endl;
				valid = false;
			}
			break;
		default:
			cout << "invalid input" << endl;
			valid = false;
			break;
		};
	} while (valid != true);
	for (size_t i = 0; i < choicePower.size(); i++)
	{
		if (!(choicePower.at(i)->getName() == sp->getName())) {
			choicePower.at(i) = nullptr;
			delete(choicePower.at(i));
			choiceRace.at(i) = nullptr;
			delete(choiceRace.at(i));
		}
	}
}

void Player::conquers()
{
}

void Player::scores()
{
}

int Player::totalMoney()
{
	return currencyTokens[0]*10 + currencyTokens[1]*5 + currencyTokens[2]*3 + currencyTokens[3];
}

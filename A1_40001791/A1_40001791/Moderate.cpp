#include "stdafx.h"
#include "Moderate.h"

void Moderate::scores()
{
}

string Moderate::get_name()
{
	return name;
}

int Moderate::conquer(vector<Region *> av, int & unitToSpend, int reinforcements)
{
	if (numberConq != 0) {
		numberConq = 0;
		return 100;
	}
	int choice = 100;
	int minAttckNeed = 100;
	
	for (size_t i = 0; i < av.size(); i++)
	{
		int DefenderToken = av.at(i)->getArmy();
		if (DefenderToken != 0) {
			if (av.at(i)->getRegionType()->getName() == "Mountain") {
				DefenderToken++;
			}
			if (av.at(i)->getSpecialTile()->getName() == "Encampment") {
				DefenderToken++;
			}
			if (av.at(i)->getSpecialTile()->getName() == "Troll_Lair") {
				DefenderToken++;
			}
			if (av.at(i)->getSpecialTile()->getName() == "Fortress") {
				DefenderToken++;
			}
		}
		if (DefenderToken < minAttckNeed) {
			minAttckNeed = DefenderToken;
			unitToSpend = minAttckNeed + 1;
			choice = i;
		}
	}
	numberConq++;
	return choice;
}

int Moderate::pick_race(vector<Race *> r, vector<Special_Power *>sp, int money)
{
	int tier = 0;

	int max = 0;
	int result = 0;

	for (size_t i = 0; i < r.size(); i++)
	{
		tier = 0;
		if (r.at(i)->getName() == "Humans" || r.at(i)->getName() == "Dwarves" || r.at(i)->getName() == "Wizards") {
			tier += 3;
		}
		else {
			tier++;
		}
		if (sp.at(i)->getName() == "Wealthy") {
			tier += 2;
		}
		else if (sp.at(i)->getName() == "Hill" || sp.at(i)->getName() == "Swamp") {
			tier += 3;
		}
		else {
			tier++;
		}
		if (tier > max && money >= i) {
			max = tier;
			result = i;
		}

	}
	return result;
}

Moderate::Moderate(Player * pl)
{
	p = pl;
}

Moderate::Moderate()
{
}

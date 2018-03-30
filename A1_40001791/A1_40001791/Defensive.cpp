#include "stdafx.h"
#include "Defensive.h"

void Defensive::scores()
{
}

int Defensive::conquer(vector<Region *> av, int & unitToSpend, int reinforcements)
{
	int choice = 100;
	int minAttckNeed = 100;
	int minAdj = 100;
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
		if (av.at(i)->getAdjacencies().size() < minAdj && reinforcements >= DefenderToken + 1) {
			minAdj = av.at(i)->getAdjacencies().size();
			minAttckNeed = DefenderToken;
			unitToSpend = minAttckNeed + 1;
			choice = i;
			
		}
	}
	return choice;
}

int Defensive::pick_race(vector<Race *> r, vector<Special_Power *> sp, int money)
{
	int tier = 0;
	int max = 0;
	int result = 0;

	for (size_t i = 0; i < r.size(); i++)
	{
		tier = 0;
		if (r.at(i)->getName() == "Trolls" || r.at(i)->getName() == "Halflings") {
			tier += 3;
		}
		else {
			tier++;
		}
		if (sp.at(i)->getName() == "Fortified") {
			tier += 2;
		}
		else if (sp.at(i)->getName() == "Heroic" || sp.at(i)->getName() == "Seafaring") {
			tier += 3;
		}
		else {
			tier++;
		}
		tier -= i;
		if (tier > max && money >= i) {
			max = tier;
			result = i;
		}

	}
	return result;
}

string Defensive::get_name()
{
	return name;
}

Defensive::Defensive(Player * pl)
{
	p = pl;
}

Defensive::Defensive()
{
}

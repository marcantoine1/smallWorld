#include "stdafx.h"
#include "Agressive.h"

void Agressive::scores()
{

}

int Agressive::conquer(vector<Region *>av, int & unitToSpend, int reinforcements)
{
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
	return choice;
}

int Agressive::pick_race(vector<Race *>r , vector<Special_Power *>sp, int money)
{
	int max = 0;
	int result = 0;
	for (size_t i = 0; i < r.size(); i++)
	{
		if ((r.at(i)->getReinforcements() + sp.at(i)->getReinforcements() > max) && money >= i) {
			max = r.at(i)->getReinforcements() + sp.at(i)->getReinforcements();
			result = i;
		}

	}
	return result;
}

string Agressive::get_name()
{
	return name;
}

Agressive::Agressive(Player * pl)
{
	p = pl;
	name = "agressive";
}

Agressive::Agressive()
{
}

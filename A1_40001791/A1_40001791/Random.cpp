#include "stdafx.h"
#include "Random.h"

string Random::get_name()
{
	return name;
}

Random::Random(Player * pl)
{
	p = pl;
}

Random::Random()
{

}

void Random::scores()
{
}

int Random::conquer(vector<Region *>av, int & unitToSpend, int reinforcements)
{
	int random = rand() % av.size();
	if (av.size() > 0) {
	int DefenderToken = av.at(random)->getArmy();
	if (DefenderToken != 0) {
		if (av.at(random)->getRegionType()->getName() == "Mountain") {
			DefenderToken++;
		}
		if (av.at(random)->getSpecialTile()->getName() == "Encampment") {
			DefenderToken++;
		}
		if (av.at(random)->getSpecialTile()->getName() == "Troll_Lair") {
			DefenderToken++;
		}
		if (av.at(random)->getSpecialTile()->getName() == "Fortress") {
			DefenderToken++;
		}
	}
	if (unitToSpend <= reinforcements) {
		unitToSpend = DefenderToken + 1;
	}
	else {
		return 100;
	}
}
else {
	return 100;
}
	return random;
}

int Random::pick_race(vector<Race *>r , vector<Special_Power *>sp,int money)
{
	return 0;
}

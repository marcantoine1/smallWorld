#pragma once
#include "Strategy.h"
class Agressive : public Strategy {
private :
	Player * p;
	string name = "Agressive";
public:
	
	void scores();
	int conquer(vector<Region *>, int & unitToSpend, int reinforcements);
	int pick_race(vector<Race *>, vector<Special_Power *>, int money);
	string get_name();
	Agressive(Player * pl);
	Agressive();
};
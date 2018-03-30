#pragma once
#include "Strategy.h"
class Defensive : public Strategy {
private:
	Player * p;
	string name = "Defensive";
public:
	
	void scores();
	int conquer(vector<Region *>, int & unitToSpend, int reinforcements);
	int pick_race(vector<Race *>, vector<Special_Power *>, int money);
	string get_name();
	Defensive(Player * pl);
	Defensive();
};
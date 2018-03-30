#pragma once
#include "Strategy.h"
class Random : public Strategy {
private:
	Player * p;
	string name = "Random";
public:
	string get_name();
	Random(Player * pl);
	Random();
	void scores();
	int conquer(vector<Region *>, int & unitToSpend, int reinforcements);
	int pick_race(vector<Race *>, vector<Special_Power *>, int money);
};
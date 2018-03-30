#pragma once
#include "Strategy.h"
class Moderate :public Strategy {
private:
	Player * p;
	int numberConq = 0;
	string name = "Moderate";
public:
	
	void scores();
	string get_name();
	int conquer(vector<Region *>, int & unitToSpend, int reinforcements);
	int pick_race(vector<Race *>, vector<Special_Power *>, int money);
	Moderate(Player * pl);
	Moderate();
};
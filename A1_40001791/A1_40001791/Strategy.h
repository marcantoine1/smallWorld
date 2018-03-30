#pragma once
#include "Player.h"
class Strategy {
private:
	Player * p;

public:
	
	Strategy(Player * player);
	Strategy();
	string name;
	virtual string get_name() = 0;
	virtual int pick_race(vector<Race *>,vector<Special_Power *>, int money) = 0;
	virtual int conquer(vector<Region *> av,int & unitToSpend,int reinforcements) = 0;
	virtual void scores() = 0;
};
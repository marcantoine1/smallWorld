#pragma once
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Dice_Roll {
private:
	int dice = 0;
	vector<int> value_count;
	vector<double> value_percent;
	int diceRollCount;
public:
	Dice_Roll();
	~Dice_Roll();
	int roll();
	void set_percentage();
	vector<double>  get_percentage();
	vector<int> get_values();
	int getDiceRollCount();
	int getDice();
	void print_results();


};

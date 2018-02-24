#include "stdafx.h"
#include "Dice_Roll.h"

Dice_Roll::Dice_Roll()
{
	diceRollCount = 0;
	value_count.resize(4);
	value_percent.resize(4);
	value_count.at(0) = 0;
	value_count.at(1) = 0;
	value_count.at(2) = 0;
	value_count.at(3) = 0;
	value_percent.at(0) = 0;
	value_percent.at(1) = 0;
	value_percent.at(2) = 0;
	value_percent.at(3) = 0;
}

Dice_Roll::~Dice_Roll()
{

}

void Dice_Roll::roll()
{
	int val = (rand() % 6 + 1);
	if (val == 4 || val == 5 || val == 6)
		val = 0;
	value_count[val]++;
	++diceRollCount;
	set_percentage();
}

void Dice_Roll::set_percentage()
{
	value_percent[0] = 100.0 * (value_count[0]) / static_cast<double>(diceRollCount);
	value_percent[1] = 100.0 * (value_count[1]) / static_cast<double>(diceRollCount);
	value_percent[2] = 100.0 * (value_count[2]) / static_cast<double>(diceRollCount);
	value_percent[3] = 100.0 * (value_count[3]) / static_cast<double>(diceRollCount);
}
vector<double> Dice_Roll::get_percentage() {
	return value_percent;
}
vector<int> Dice_Roll::get_values()
{
	return value_count;
}

int Dice_Roll::getDiceRollCount()
{
	return diceRollCount;
}

int  Dice_Roll::getDice()
{
	return dice;
}

void Dice_Roll::print_results()
{
	cout << "You have rolled the dice " << getDiceRollCount() << " times" << endl;
	vector <double> percent = get_percentage();
	vector<int> count = get_values();
	for (size_t i = 0; i < percent.size(); i++)
	{
		cout << "Chance to roll a " << i  << " is : " << percent.at(i) << "%" << endl;
	}
	for (size_t i = 0; i < count.size(); i++)
	{
		cout << "You have rolled  a " << i  << " " << count.at(i) << " times" << endl;
	}

}



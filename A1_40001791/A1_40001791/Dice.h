#pragma once
#include <iostream>
#include <cstdlib>


class Dice {
private:
	int value;
public:
	Dice();
	~Dice();
	void roll();
	void setValue(int);
	int getValue();
};
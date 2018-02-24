#include "stdafx.h"
#include "Dice.h"

Dice::Dice()
{

}

Dice::~Dice()
{
}

void Dice::roll()
{
	int val = (rand() % 6 + 1);
	if (val == 4 || val == 5 || val == 6)
		val = 0;
	setValue(val);
}

void Dice::setValue(int x)
{
	value = x;
}

int Dice::getValue()
{
	return value;
}

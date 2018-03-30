#pragma once

#include "Map.h"

class StatisticDummy : public Map
{
public:
	virtual void changeTurn(int turn);
	virtual void changeConquestPercent(vector<double> percent );
	virtual void showConquestResult(vector<string> scores);
};
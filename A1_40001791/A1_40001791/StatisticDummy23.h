#pragma once

#include "Map.h"
#include "StatisticDummy.h"
class StatisticDummy23 : public StatisticDummy
{
public:
	virtual void changeTurn(int turn);
	virtual void changeConquestPercent(vector<double> percent);
	virtual void showConquestResult(vector<string> scores);
};
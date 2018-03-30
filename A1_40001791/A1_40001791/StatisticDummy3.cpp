#include "stdafx.h"
#include "StatisticDummy3.h"

void StatisticDummy3::changeTurn(int turn)
{
	Notify(turn);
}

void StatisticDummy3::changeConquestPercent(vector<double> percent)
{
}

void StatisticDummy3::showConquestResult(vector<string> scores)
{
	Notify(scores);
}

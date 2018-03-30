#include "stdafx.h"
#include "StatisticDummy23.h"

void StatisticDummy23::changeTurn(int turn)
{
	Notify(turn);
}

void StatisticDummy23::changeConquestPercent(vector<double> percent)
{
	if (this->getMapObs()->isDifferent(this->getMapObs()->getOld(), percent)) {
		Notify(percent);
		getMapObs()->setOld(percent);
	}
}

void StatisticDummy23::showConquestResult(vector<string> scores)
{
	Notify(scores);
}

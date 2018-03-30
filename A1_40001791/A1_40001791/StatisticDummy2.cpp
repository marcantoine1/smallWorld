#include "stdafx.h"
#include "StatisticDummy2.h"

void StatisticDummy2::changeTurn(int turn)
{
	Notify(turn);
}

void StatisticDummy2::changeConquestPercent(vector<double> percent)
{
	if (this->getMapObs()->isDifferent(this->getMapObs()->getOld(), percent)) {
		Notify(percent);
		getMapObs()->setOld(percent);
	}
}

void StatisticDummy2::showConquestResult(vector<string> scores)
{
}

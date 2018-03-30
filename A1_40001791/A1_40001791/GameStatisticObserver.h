#pragma once
#include <string>
#include <vector>
using namespace std;
class GameStatisticObserver
{
public:
	virtual void Update(vector<double> ) = 0;
};
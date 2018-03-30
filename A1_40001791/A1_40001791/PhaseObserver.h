#pragma once
#include "Phases.h"
#include <string>
using namespace std;
class PhaseObserver
{
public:
	virtual void Update(string phase) = 0;
};
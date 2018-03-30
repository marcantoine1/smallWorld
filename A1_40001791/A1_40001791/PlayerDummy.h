#pragma once
#include "Map.h"

class PlayerDummy : public Map
{
public:
	void changePhase(string phase);
};
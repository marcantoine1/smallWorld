#include "stdafx.h"
#include "MapChecker.h"

MapChecker::MapChecker(vector<Region*> region)
{
	regionVector = region;
}

MapChecker::~MapChecker()
{
}

bool MapChecker::areNodesConnectedBothWays()
{
	for (int i = 0; i < regionVector.size(); i++) 
	{
		Region* tempRegion = regionVector.at(i);

		for (int j = 0; j < (tempRegion->getNumberAdjacency()); j++) 
		{
			Region* tempRegion2 = tempRegion->getAdjacencyAt(j);
			if (tempRegion2->getAdjacencySize() == 0)
			{
				cout << "One of the nodes is not connected both ways" << endl;
				tempRegion = NULL;
				tempRegion2 = NULL;
				delete tempRegion;
				delete tempRegion2;
				return false;
			}
			for (int k = 0; k < tempRegion2->getNumberAdjacency(); k++)
			{
				Region* tempRegion3 = tempRegion2->getAdjacencyAt(k);

				if (tempRegion == tempRegion3) 
				{

					break;
				}
				else if (tempRegion2->getAdjacencySize() == k + 1)
				{
					cout << "One of the nodes is not connected both ways" << endl;
					tempRegion = NULL;
					tempRegion2 = NULL;
					tempRegion3 = NULL;
					delete tempRegion;
					delete tempRegion2;
					delete tempRegion3;
					return false;
				}
				tempRegion3 = NULL;
				delete tempRegion3;
			}


			tempRegion2 = NULL;
			delete tempRegion2;
		}

		tempRegion = NULL;
		delete tempRegion;
	}

	cout << "All paths are two way" << endl; 
	return true;
}

bool MapChecker::isMapLinked()
{
	regionVector.at(0)->setLinked(true); // set first region as "linked"
	int linkedCounter = 1; // set a counter that add to himself everytime a country is linked to the "linked graph"
	int initCounter = 0;

	while (initCounter < linkedCounter) // if linkedCounter keeps growing, keep going
	{
		initCounter = linkedCounter; //update inital counter
		for (int i = 0; i < numberRegion; i++) // Cycle through all the region nodes
		{
			if (regionVector.at(i)->isLinked()) // if country is linked -----------------------------
			{
				for (int j = 0; j < regionVector.at(i)->getNumberAdjacency(); j++) // for all the adjacent regions to the previous region
				{
					if (regionVector.at(i)->getAdjacencyAt(j)->isLinked() == false) // if they are not linked
					{
						regionVector.at(i)->getAdjacencyAt(j)->setLinked(true); // link them
						linkedCounter++;										// add to the counter

						if (linkedCounter == numberRegion)						//if counter is equal to the number of region exit function
						{
							cout << "all regions are linked" << endl;
							return true;
						}
					}
				}
			}

			else if (!regionVector.at(i)->isLinked()) // if region is not linked ---------------------
			{
				for (int j = 0; j < regionVector.at(i)->getNumberAdjacency(); j++) // cycle through the region adjacent countries
				{
					if (regionVector.at(i)->getAdjacencyAt(j)->isLinked()) //if one of them is linked
					{
						regionVector.at(i)->setLinked(true); // set the region to linked
						linkedCounter++;					// add to the counter

						if (linkedCounter == numberRegion)	// if number of linked regions is equal to the total number of regions return true
						{
							cout << "all regions are linked" << endl;
							return true;
						}

						i--;	// remove one i so that the newly linked region goes through the first "isLinked" condition and cycle through its adjacent regions and link them if they need to be linked
						break;
					}
				}
			}
		}
	}

	if (linkedCounter < numberRegion)
	{
		cout << "Not all regions are linked" << endl;
		return false;
	}
}


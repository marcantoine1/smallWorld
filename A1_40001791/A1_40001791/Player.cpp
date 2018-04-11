#include "stdafx.h"
#include "Player.h"




Player::Player()
{
	dr = new Dice_Roll();
}

Player::~Player()
{
}

void Player::setStrategy(Strategy * strategy)
{
	strat = strategy;
}

void Player::picks_race(vector<Race *> raceVector, vector<Special_Power *> powerVector)
{
	
	vector<Race *> choiceRace;
	choiceRace.resize(6);
	vector<Special_Power *> choicePower;
	choicePower.resize(6);
	int valRace = (rand() % raceVector.size() + 1);
	int valPower = (rand() % powerVector.size() + 1);
	vector<Race *> vectorRace;
	vectorRace = raceVector;
	vector<Special_Power *> vectorPower;
	vectorPower = powerVector;
	
	choiceRace.at(0) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace-1);
	valRace = (rand() % vectorRace.size() + 1);

	choiceRace.at(1) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % vectorRace.size() + 1);

	choiceRace.at(2) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % vectorRace.size() + 1);

	choiceRace.at(3) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % vectorRace.size() + 1);

	choiceRace.at(4) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);
	valRace = (rand() % vectorRace.size() + 1);

	choiceRace.at(5) = vectorRace.at(valRace - 1);
	vectorRace.erase(vectorRace.begin() + valRace - 1);

	choicePower.at(0) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % vectorPower.size()+ 1);

	choicePower.at(1) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % vectorPower.size() + 1);

	choicePower.at(2) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % vectorPower.size() + 1);

	choicePower.at(3) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % vectorPower.size() + 1);

	choicePower.at(4) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);
	valPower = (rand() % vectorPower.size() + 1);

	choicePower.at(5) = vectorPower.at(valPower - 1);
	vectorPower.erase(vectorPower.begin() + valPower - 1);

	vectorRace.resize(vectorRace.size() + 5);
	vectorPower.resize(vectorPower.size() + 5);
	bool valid = true;
	cout << "Pick a race and special ability combo" << endl;
	cout << "1 : " << choiceRace.at(0)->getName() << " and " << choicePower.at(0)->getName() << endl;
	cout << "2 : " << choiceRace.at(1)->getName() << " and " << choicePower.at(1)->getName() << endl;
	cout << "3 : " << choiceRace.at(2)->getName() << " and " << choicePower.at(2)->getName() << endl;
	cout << "4 : " << choiceRace.at(3)->getName() << " and " << choicePower.at(3)->getName() << endl;
	cout << "5 : " << choiceRace.at(4)->getName() << " and " << choicePower.at(4)->getName() << endl;
	cout << "6 : " << choiceRace.at(5)->getName() << " and " << choicePower.at(5)->getName() << endl;
	if (strat == nullptr) {
		int number;
		do {
			try {
				cin >> number;
				if (cin.good())
				{
					switch (number) {
					case 1:
						if (r[0] == nullptr) {
							r[0] = choiceRace.at(0);
							sp[0] = choicePower.at(0);
							reinforcements = r[0]->getReinforcements();
							reinforcements += sp[0]->getReinforcements();
							if (sp[0]->getName() == "Wealthy") {
								currencyTokens[3] += 7;
							}
							currentRace = 0;
						}
						else {
							if (r[1] == nullptr) {
								r[1] = choiceRace.at(0);
								sp[1] = choicePower.at(0);
								reinforcements = r[1]->getReinforcements();
								reinforcements += sp[1]->getReinforcements();
								if (sp[1]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 1;
							}
							else {
								r[0] = choiceRace.at(0);
								sp[0] = choicePower.at(0);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
						}
						remainingReinforcements = reinforcements;
						valid = true;
						break;
					case 2:
						if (totalMoney() >= 1) {
							if (r[0] == nullptr) {
								r[0] = choiceRace.at(1);
								sp[0] = choicePower.at(1);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
							else {
								if (r[1] == nullptr) {
									r[1] = choiceRace.at(1);
									sp[1] = choicePower.at(1);
									reinforcements = r[1]->getReinforcements();
									reinforcements += sp[1]->getReinforcements();
									if (sp[1]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 1;
								}
								else {
									r[0] = choiceRace.at(1);
									sp[0] = choicePower.at(1);
									reinforcements = r[0]->getReinforcements();
									reinforcements += sp[0]->getReinforcements();
									if (sp[0]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 0;
								}
							}
							remainingReinforcements = reinforcements;
							currencyTokens[3] -= 1;
							valid = true;
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n'); 
							valid = false;
							throw std::runtime_error("Not enough money");
							
						}
						break;
					case 3:
						if (totalMoney() >= 2) {
							if (r[0] == nullptr) {
								r[0] = choiceRace.at(2);
								sp[0] = choicePower.at(2);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
							else {
								if (r[1] == nullptr) {
									r[1] = choiceRace.at(2);
									sp[1] = choicePower.at(2);
									reinforcements = r[1]->getReinforcements();
									reinforcements += sp[1]->getReinforcements();
									if (sp[1]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 1;
								}
								else {
									r[0] = choiceRace.at(2);
									sp[0] = choicePower.at(2);
									reinforcements = r[0]->getReinforcements();
									reinforcements += sp[0]->getReinforcements();
									if (sp[0]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 0;
								}
							}
							remainingReinforcements = reinforcements;
							currencyTokens[3] -= 2;
							valid = true;
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n'); 
							valid = false;
							throw std::runtime_error("Not enough money");
							
						}
						break;
					case 4:
						if (totalMoney() >= 3) {
							if (r[0] == nullptr) {
								r[0] = choiceRace.at(3);
								sp[0] = choicePower.at(3);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
							else {
								if (r[1] == nullptr) {
									r[1] = choiceRace.at(3);
									sp[1] = choicePower.at(3);
									reinforcements = r[1]->getReinforcements();
									reinforcements += sp[1]->getReinforcements();
									if (sp[1]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 1;
								}
								else {
									r[0] = choiceRace.at(3);
									sp[0] = choicePower.at(3);
									reinforcements = r[0]->getReinforcements();
									reinforcements += sp[0]->getReinforcements();
									if (sp[0]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 0;
								}
							}
							remainingReinforcements = reinforcements;
							currencyTokens[3] -= 3;
							valid = true;
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							valid = false;
							throw std::runtime_error("Not enough money");
							
						}
						break;
					case 5:
						if (totalMoney() >= 4) {
							if (r[0] == nullptr) {
								r[0] = choiceRace.at(4);
								sp[0] = choicePower.at(4);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
							else {
								if (r[1] == nullptr) {
									r[1] = choiceRace.at(4);
									sp[1] = choicePower.at(4);
									reinforcements = r[1]->getReinforcements();
									reinforcements += sp[1]->getReinforcements();
									if (sp[1]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 1;
								}
								else {
									r[0] = choiceRace.at(4);
									sp[0] = choicePower.at(4);
									reinforcements = r[0]->getReinforcements();
									reinforcements += sp[0]->getReinforcements();
									if (sp[0]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 0;
								}
							}
							remainingReinforcements = reinforcements;
							currencyTokens[3] -= 4;
							valid = true;
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							valid = false;
							throw std::runtime_error("Not enough money");
							
						}
						break;
					case 6:
						if (totalMoney() >= 5) {
							if (r[0] == nullptr) {
								r[0] = choiceRace.at(5);
								sp[0] = choicePower.at(5);
								reinforcements = r[0]->getReinforcements();
								reinforcements += sp[0]->getReinforcements();
								if (sp[0]->getName() == "Wealthy") {
									currencyTokens[3] += 7;
								}
								currentRace = 0;
							}
							else {
								if (r[1] == nullptr) {
									r[1] = choiceRace.at(5);
									sp[1] = choicePower.at(5);
									reinforcements = r[1]->getReinforcements();
									reinforcements += sp[1]->getReinforcements();
									if (sp[1]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 1;
								}
								else {
									r[0] = choiceRace.at(5);
									sp[0] = choicePower.at(5);
									reinforcements = r[0]->getReinforcements();
									reinforcements += sp[0]->getReinforcements();
									if (sp[0]->getName() == "Wealthy") {
										currencyTokens[3] += 7;
									}
									currentRace = 0;
								}
							}
							remainingReinforcements = reinforcements;
							currencyTokens[3] -= 5;
							valid = true;
						}
						else {
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							valid = false;
							throw std::runtime_error("Not enough money");
							
							
						}
						break;
					default:
						valid = false;
						throw std::runtime_error("Please enter a number between 1 and 6");
						
						break;
					};
				}
				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					valid = false;
					throw std::runtime_error("Please enter a number between 1 and 6");
					
				}
			}
			catch (const std::runtime_error& e) {
				std::cout << e.what() << endl;;
			}
		} while (valid != true);
	}
	else {
		int result = strat->pick_race(choiceRace,choicePower,currencyTokens[3]);
		if (r[0] == nullptr) {
			r[0] = choiceRace.at(result);
			sp[0] = choicePower.at(result);
			reinforcements = r[0]->getReinforcements();
			reinforcements += sp[0]->getReinforcements();
			if (sp[0]->getName() == "Wealthy") {
				currencyTokens[3] += 7;
			}
			currentRace = 0;
		}
		else {
			if (r[1] == nullptr) {
				r[1] = choiceRace.at(result);
				sp[1] = choicePower.at(result);
				reinforcements = r[1]->getReinforcements();
				reinforcements += sp[1]->getReinforcements();
				if (sp[1]->getName() == "Wealthy") {
					currencyTokens[3] += 7;
				}
				currentRace = 1;
			}
			else {
				r[0] = choiceRace.at(result);
				sp[0] = choicePower.at(result);
				reinforcements = r[0]->getReinforcements();
				reinforcements += sp[0]->getReinforcements();
				if (sp[0]->getName() == "Wealthy") {
					currencyTokens[3] += 7;
				}
				currentRace = 0;
			}
		}
		remainingReinforcements = reinforcements;
		currencyTokens[3] -= result;
	}
}

bool Player::conquers(Region *& r)
{
	int DefenderToken = r->getArmy();
	if (r->getRegionType()->getName() == "Mountain") {
		DefenderToken++;
	}
	if (r->getSpecialTile()->getName() == "Encampment") {
		DefenderToken++;
	}
	if (r->getSpecialTile()->getName() == "Troll_Lair") {
		DefenderToken++;
	}
	if (r->getSpecialTile()->getName() == "Fortress") {
		DefenderToken++;
	}
	bool validNumber = false;
	cout << "How many tokens will you spend ? 0 to go back" << endl;
	for (size_t i = 0; i < remainingReinforcements; i++)
	{
		cout << i + 1 << endl;
	}
	int numberUnitToSpend;
	do {
		try {
			cin >> numberUnitToSpend;
			if (cin.good())
			{
				if (numberUnitToSpend == 0) {
					cout << "Going back to region selection" << endl;
					return false;
				}

				if (numberUnitToSpend > 0 && numberUnitToSpend <= remainingReinforcements) {
					validNumber = true;

				}
				else {
					string msg = "Please enter a number between 1 and ";
					msg += remainingReinforcements;
					throw std::runtime_error(msg);
					
				}
			}
			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				string msg = "Please enter a number between 1 and ";
				msg += remainingReinforcements;
				throw std::runtime_error(msg);

			}
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what() << endl;;
		}
	} while (!validNumber);
	int attackerToken = numberUnitToSpend;
	bool adjMountain = false;
	bool adjWater = false;
	bool isCavern = false;
	for (size_t i = 0; i < r->getNumberAdjacency(); i++)
	{
		if (r->getAdjacencyAt(i)->getRegionType()->getName() == "Mountain") {
			adjMountain = true;
		}
		if (r->getAdjacencyAt(i)->getRegionType()->getName() == "Water") {
			adjWater = true;
		}
	}
	for (size_t i = 0; i < r->getOtherTiles().size(); i++)
	{
		if (r->getOtherTiles().at(i)->getName() == "Cavern") {
			isCavern = true;
		}
	}
	bool possibleConquest = false;
	bool notEmpty = false;
	bool conquestPossibleWithTokensRemaining = false;
	if ((getRace()->getName() == "Giants" && adjMountain) || (getRace()->getName() == "Tritons" && adjWater) || (getPower()->getName() == "Commando") ||(getPower()->getName() == "Underworld" && isCavern)) {
		attackerToken++;
		if (DefenderToken == 1) {
			if (remainingReinforcements >= 1) {
				conquestPossibleWithTokensRemaining = true;
			}
			if (attackerToken >= 1) {
				possibleConquest = true;
				notEmpty = true;
			}
			
		}
		else if (DefenderToken > 1) {
			if (remainingReinforcements + 1> DefenderToken) {
				conquestPossibleWithTokensRemaining = true;
			}
			if (attackerToken  > DefenderToken) {
				possibleConquest = true;
				notEmpty = true;
			}
			
		}
		else {
			if (remainingReinforcements >= 1) {
				conquestPossibleWithTokensRemaining = true;
			}
			possibleConquest = true;
			
		}
	}
	else{
		if (remainingReinforcements > DefenderToken) {
			conquestPossibleWithTokensRemaining = true;
		}
		if (attackerToken > DefenderToken) {
			possibleConquest = true;
			notEmpty = true;
		}
		
	}
	if (!conquestPossibleWithTokensRemaining) {
		cout << "You are about to roll the reinforcement die to see if you can conquer this region because your remaining units are too low to conquer it by itself" << endl;
		int rollValue = dr->roll();
		if (attackerToken + rollValue > DefenderToken) {
			attackerToken = remainingReinforcements;
			possibleConquest = true;
			inDecline = true;
		}
		else {
			bool validInputDecline = false;
			troopRedeployment = true;
			cout << "Would you like to go into decline ? 0 for no 1 for yes" << endl;
			bool goIntoDecline = false;
			do {
				try {
					cin >> goIntoDecline;
					if (cin.good())
					{
						validInputDecline = true;
						inDecline = goIntoDecline;
						return true;
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						throw std::runtime_error("Please enter a number between 0 and 1");
					}
				}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << endl;;
				}
			} while (!validInputDecline);
		}
	}
	if (possibleConquest) {
		if (r->getOwner() != nullptr) {
			for (size_t k = 0; k < r->getOwner()->regions.size(); k++)
			{
				if (r->getOwner()->regions.at(k) == r) {
					r->getOwner()->regions.erase(r->getOwner()->regions.begin() + k);
				}
			}
			
		}
		r->setOwner(this);
		r->setArmy(attackerToken);
		this->regions.resize(regions.size() + 1);
		this->regions.at(regions.size() - 1) = r;
		this->remainingReinforcements -= attackerToken;
		if (this->remainingReinforcements == 0) {
			inDecline = true;
		}
		if (getRace()->getName() == "Amazon") {
			r->setRaceToken(new AmazonTokens());
		}
		if (getRace()->getName() == "Halflings") {
			r->setRaceToken(new HalflingsTokens());
		}
		if (getRace()->getName() == "Dwarves") {
			r->setRaceToken(new DwarvesTokens());
		}
		if (getRace()->getName() == "Humans") {
			r->setRaceToken(new HumansTokens());
		}
		if (getRace()->getName() == "Orcs") {
			r->setRaceToken(new OrcsTokens());
		}
		if (getRace()->getName() == "Ratmen") {
			r->setRaceToken(new RatmenTokens());
		}
		if (getRace()->getName() == "Elves") {
			r->setRaceToken(new ElvesTokens());
		}
		if (getRace()->getName() == "Skeletons") {
			r->setRaceToken(new SkeletonsTokens());
		}
		if (getRace()->getName() == "Ghouls") {
			r->setRaceToken(new GhoulsTokens());
		}
		if (getRace()->getName() == "Sorcerers") {
			r->setRaceToken(new SorcerersTokens());
		}
		if (getRace()->getName() == "Tritons") {
			r->setRaceToken(new TritonsTokens());
		}
		if (getRace()->getName() == "Trolls") {
			r->setRaceToken(new TrollsTokens());
		}
		if (getRace()->getName() == "Wizards") {
			r->setRaceToken(new WizardsTokens());
		}
		if (getRace()->getName() == "Giants") {
			r->setRaceToken(new GiantsTokens());
		}
		if (notEmpty) {
			conqueredRegionsNotEmpty++;
		}
		return true;
	}
	else {
		cout << "The number of units is either too low to conquer the region or an error occured sending you back to the more conquer choice option" << endl;
		return false;
	}
	
}

vector<string> Player::scores()
{
	vector<string> vs;
	string s;
	s = "Player ";
	s += to_string(getPlayerNumber());
	s += " has ";
	s += to_string(currencyTokens[3]);
	s += " victory coins";
	vs.push_back(s);
		//cout << "Player " << getPlayerNumber() << " has " << currencyTokens[3] << " victory coins" << endl;
		for (size_t i = 0; i < regions.size(); i++)
		{
			currencyTokens[3]++;
			s = "Player ";
			s += to_string(getPlayerNumber());
			s += " Scored a victory point because he owned a region";
			vs.push_back(s);
			//cout << "Player " << getPlayerNumber() << " Scored a victory point because he owned a region" << endl;
			if (getPower()->getName() == "Merchant") {
				currencyTokens[3]++;
				s = "Player ";
				s += to_string(getPlayerNumber());
				s += " Scored a victory point because he owned a region and had the merchant power";
				vs.push_back(s);
				//cout << "Player " << getPlayerNumber() << " Scored a victory point because he owned a region and had the merchant power" << endl;
			}
			if (getRace()->getName() == "Humans") {
				for (size_t j = 0; j < regions.at(i)->getOtherTiles().size(); j++)
				{
					if (regions.at(i)->getOtherTiles().at(j)->getName() == "FarmLand") {
						currencyTokens[3]++;
						s = "Player ";
						s += to_string(getPlayerNumber());
						s += " Scored a victory point because he owned a farmland and was human";
						vs.push_back(s);
						//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a farmland and was human" << endl;
					}
				}
			}
			if (getPower()->getName() == "Forest") {
				if (regions.at(i)->getRegionType()->getName() == "Forest") {
					//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a forest and had the forest power" << endl;
					s = "Player ";
					s += to_string(getPlayerNumber());
					s += " Scored a victory point because he owned a forest and had the forest power";
					vs.push_back(s);
					currencyTokens[3]++;
				}
			}
			if (getPower()->getName() == "Hill") {
				if (regions.at(i)->getRegionType()->getName() == "Hill") {
					//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a Hill and had the hill power" << endl;
					s = "Player ";
					s += to_string(getPlayerNumber());
					s += " Scored a victory point because he owned a Hill and had the hill power";
					vs.push_back(s);
					currencyTokens[3]++;
				}
			}
			if (getPower()->getName() == "Swamp") {
				if (regions.at(i)->getRegionType()->getName() == "Swamp") {
					//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a swamp and had the swamp power" << endl;
					s = "Player ";
					s += to_string(getPlayerNumber());
					s += " Scored a victory point because he owned a swamp and had the swamp power";
					vs.push_back(s);
					currencyTokens[3]++;
				}
			}
			if (regions.at(i)->getRaceToken() != nullptr) {
				if (regions.at(i)->getRaceToken()->getName() == "Dwarves") {
					for (size_t j = 0; j < regions.at(i)->getOtherTiles().size(); j++)
					{
						if (regions.at(i)->getOtherTiles().at(j)->getName() == "Mine") {
							//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a mine and had the dwarves race active or in decline" << endl;
							s = "Player ";
							s += to_string(getPlayerNumber());
							s += " Scored a victory point because he owned a mine and had the dwarves race active or in decline";
							vs.push_back(s);
							currencyTokens[3]++;
						}
					}
				}
			}
			if (getRace()->getName() == "Wizards") {
				for (size_t j = 0; j < regions.at(i)->getOtherTiles().size(); j++)
				{
					if (regions.at(i)->getOtherTiles().at(j)->getName() == "Magic") {
						//cout << "Player " << getPlayerNumber() << "Scored a victory point because he owned a Magic region and had the Wizards race" << endl;
						s = "Player ";
						s += to_string(getPlayerNumber());
						s += " Scored a victory point because he owned a Magic region and had the Wizards race";
						vs.push_back(s);
						currencyTokens[3]++;
					}
				}
			}

		}
		if (getRace()->getName() == "Orcs") {
			currencyTokens[3] += conqueredRegionsNotEmpty;
			s = "Player ";
			s += to_string(getPlayerNumber());
			s += " Scored ";
			s += to_string(conqueredRegionsNotEmpty);
			s += " victory points because he conquered non empty regions and had the orc race";
			vs.push_back(s);
			//cout << "Player " << getPlayerNumber() << "Scored " << conqueredRegionsNotEmpty << " victory points because he conquered non empty regions and had the orc race" << endl;
		}
		if (getPower()->getName() == "Pillaging") {
			currencyTokens[3] += conqueredRegionsNotEmpty;
			//cout << "Player " << getPlayerNumber() << "Scored " << conqueredRegionsNotEmpty << " victory points because he conquered non empty regions and had the pillaging power" << endl;
			s = "Player ";
			s += to_string(getPlayerNumber());
			s += " Scored ";
			s += to_string(conqueredRegionsNotEmpty);
			s += " victory points because he conquered non empty regions and had the pillaging power";
			vs.push_back(s);
		}
		if (getPower()->getName() == "Alchemist") {
			s = "Player ";
			s += to_string(getPlayerNumber());
			s += " Scored 2 victory points because he had the alchemist power";
			vs.push_back(s);
			//cout << "Player " << getPlayerNumber() << "Scored 2 victory points because he had the alchemist power" << endl;
			currencyTokens[3] += 2;
		}
		s = "Player ";
		s += to_string(getPlayerNumber());
		s += " has ";
		s += to_string(currencyTokens[3]);
		s += " victory coins";
		vs.push_back(s);
		return vs;
}

bool Player::getDeclineStatus()
{
	return inDecline;
}

void Player::setDeclineStatus(bool status)
{
	inDecline = status;
}

void Player::setRedeploymentStatus(bool status)
{
	troopRedeployment = status;
}

bool Player::getRedeploymentStatus()
{
	return troopRedeployment;
}


Race * Player::getRace()
{
	return r[currentRace];
}

Race * Player::getDeclineRace()
{
	Race * d;
	if (currentRace == 0) {
		d = r[1];
	}
	else {
		d = r[0];
	}
	return d;
}

Special_Power * Player::getPower()
{
	return sp[currentRace];
}

Special_Power * Player::getDeclinePower()
{
	Special_Power * d;
	if (currentRace == 0) {
		d = sp[1];
	}
	else {
		d = sp[0];
	}
	return d;
}

vector<Region*> Player::getRegions()
{
	return regions;
}

int Player::totalMoney()
{
	return currencyTokens[0]*10 + currencyTokens[1]*5 + currencyTokens[2]*3 + currencyTokens[3];
}

void Player::setCurrencyTokens()
{
	currencyTokens[3]++;
}

void Player::firstConquest(Map *& m)
{
	Map* temp = m;
	vector<Region *> availableRegion;
	vector<Region *> allRegions = temp->getRegions();
	
	for (size_t i = 0; i < allRegions.size(); i++)
	{

		if (allRegions.at(i)->getRegionType()->getName() == "Water") {
			if (allRegions.at(i)->getOwner() != nullptr)
			{

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {
					if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {

					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);

				}
			}
		}
		else {
			if (allRegions.at(i)->getOwner() != nullptr)
			{
				if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
					if (getRace()->getName()== "Halfling" ||getPower()->getName() == "Flying" || allRegions.at(i)->getIsEdge() == true) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {
				if (getRace()->getName() == "Halfling" || getPower()->getName() == "Flying" || allRegions.at(i)->getIsEdge() == true) {
					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
				}
			}
			
		}
	}
	cout << "All possible Conquests you can do" << endl;
	for (size_t i = 0; i < availableRegion.size(); i++)
	{
		cout << "Conquest # " << i + 1 << ": " << " , Owned by :";
		if (availableRegion.at(i)->getOwner() != nullptr && availableRegion.at(i)->getSpecialPowerTile() == nullptr) {
			cout << " Player " << availableRegion.at(i)->getOwner()->getPlayerNumber() << " , Army count : " << availableRegion.at(i)->getArmy() << " , Army type : " << availableRegion.at(i)->getRaceToken()->getName() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : " ; 
			for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
			{
				cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
			} 
			cout << endl;
		}
		else {
			if (availableRegion.at(i)->getArmy() != 0)
			{
				cout << "Lost tribes , Army count : " << availableRegion.at(i)->getArmy() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
			else {
				cout << "No one , Army count : 0" << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
		}

	}
	if (strat == nullptr) {


		int number;
		bool validInput = false;
		cout << "Which region will you conquer ?" << endl;
		do {
			try {
				cin >> number;
				if (cin.good())
				{
					if (number > 0 && number <= availableRegion.size()) {
						bool worked = conquers(availableRegion.at(number - 1));
						while (!worked) {
							cout << "The first conquest failed you need to retry" << endl;
							do {
								for (size_t i = 0; i < availableRegion.size(); i++)
								{
									cout << "Conquest # " << i + 1 << ": " << " , Owned by :";
									if (availableRegion.at(i)->getOwner() != nullptr && availableRegion.at(i)->getSpecialPowerTile() == nullptr) {
										cout << " Player " << availableRegion.at(i)->getOwner()->getPlayerNumber() << " , Army count : " << availableRegion.at(i)->getArmy() << " , Army type : " << availableRegion.at(i)->getRaceToken() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
										for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
										{
											cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
										}
										cout << endl;
									}
									else {
										if (availableRegion.at(i)->getArmy() != 0)
										{
											cout << "Lost tribes , Army count : " << availableRegion.at(i)->getArmy() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
											for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
											{
												cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
											}
											cout << endl;
										}
										else {
											cout << "No one , Army count : 0" << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
											for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
											{
												cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
											}
											cout << endl;
										}
									}

								}
								cin >> number;
								if (cin.good())
								{
									if (number > 0 && number < availableRegion.size()) {

										worked = conquers(availableRegion.at(number - 1));
										validInput = true;
									}
									else {
										string msg ="Please enter a number between 1 and " ;
										msg += std::to_string(availableRegion.size());
										throw std::runtime_error(msg);
										validInput = false;
									}
								}
								else {
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									string msg = "Please enter a number between 1 and ";
									msg += std::to_string(availableRegion.size());
									throw std::runtime_error(msg);
								}
							} while (!validInput);

						}
						validInput = true;
					}
					else {
						string msg = "Please enter a number between 1 and ";
						msg += availableRegion.size();
						throw std::runtime_error(msg);
						validInput = false;
					}
				}
				else {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					string msg = "Please enter a number between 1 and ";
					msg += availableRegion.size();
					throw std::runtime_error(msg);
					
				}
			}
			catch (const std::runtime_error& e) {
				std::cout << e.what() << endl;;
			}

		} while (!validInput);
	}
	else {
		
	}
}


void Player::findAllPossibleConquests(Map *& m)
{
	Map* temp = m;
	vector<Region *> availableRegion;
	vector<Region *> allRegions = temp->getRegions();
	cout << "All possible Conquests you can do" << endl;
	for (size_t i = 0; i < allRegions.size(); i++)
	{

		if (allRegions.at(i)->getRegionType()->getName() == "Water") {
			if (allRegions.at(i)->getOwner() != nullptr)
			{

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {
					if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {

					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);

				}
			}
		}
		else {
			if (allRegions.at(i)->getOwner() != nullptr)
			{
				if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
					if (getPower()->getName() == "Flying") {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {
				if (getPower()->getName() == "Flying") {
					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
				}
			}

		}
	}
	if (getPower()->getName() != "Flying") {
		for (size_t i = 0; i < regions.size(); i++)
		{
			for (size_t j = 0; j < regions.at(i)->getAdjacencies().size(); j++)
			{
				if (regions.at(i)->getAdjacencies().at(j)->getRegionType()->getName() != "Water") {
					if (regions.at(i)->getAdjacencies().at(j)->getOwner() != nullptr)
					{

						if (regions.at(i)->getAdjacencies().at(j)->getOwner()->getPlayerNumber() != playerNumber) {
							availableRegion.resize(availableRegion.size() + 1);
							availableRegion.at(availableRegion.size() - 1) = regions.at(i)->getAdjacencies().at(j);
						}
					}
					else {

						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = regions.at(i)->getAdjacencies().at(j);

					}
				}
			}
		}
	}
	for (size_t i = 0; i < availableRegion.size(); i++)
	{
		cout << "Conquest # " << i + 1 << ": " << " , Owned by :";
		if (availableRegion.at(i)->getOwner() != nullptr && availableRegion.at(i)->getSpecialPowerTile() == nullptr) {
			cout << " Player " << availableRegion.at(i)->getOwner()->getPlayerNumber() << " , Army count : " << availableRegion.at(i)->getArmy() << " , Army type : " << availableRegion.at(i)->getRaceToken()->getName() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
			for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
			{
				cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
			}
			cout << endl;
		}
		else {
			if (availableRegion.at(i)->getArmy() != 0)
			{
				cout << "Lost tribes , Army count : " << availableRegion.at(i)->getArmy() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
			else {
				cout << "No one , Army count : 0" << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
		}

	}
	int number;
	bool validInput = false;
	cout << "Which region will you conquer ?" << endl;
	do {
		try {
			cin >> number;
			if (cin.good())
			{
				if (number > 0 && number <= availableRegion.size()) {
					conquers(availableRegion.at(number - 1));
					validInput = true;
				}
				else {
					string msg = "Please enter a number between 1 and ";
					msg += std::to_string(availableRegion.size());
					throw std::runtime_error(msg);
					validInput = false;
				}
			}
			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				string msg = "Please enter a number between 1 and ";
				msg += std::to_string(availableRegion.size());
				throw std::runtime_error(msg);
			}
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what() << endl;;
		}
	} while (!validInput);
}

int Player::getPlayerNumber()
{
	return playerNumber;
}

void Player::setPlayerNumber(int n)
{
	playerNumber = n;
}

void Player::goIntoDecline()
{
	if (currentRace == 0) {
		if (r[1] != nullptr) {
			vector<int> regDel;
			for (size_t i = 0; i < regions.size(); i++)
			{
				if (regions.at(i)->getRaceToken()->getName() == r[1]->getName()) {
					regDel.push_back(i);
				}
			}
			for (size_t i = 0; i < regDel.size(); i++)
			{
				regions.at(i)->setOwner(nullptr);
				regions.at(i)->setArmy(0);
				regions.erase(regions.begin() + i);
			}
		}
		currentRace = 1;
	}else{
		if (r[0] != nullptr) {
			vector<int> regDel;
			for (size_t i = 0; i < regions.size(); i++)
			{
				if (regions.at(i)->getRaceToken()->getName() == r[0]->getName()) {
					regDel.push_back(i);
				}
			}
			for (size_t i = 0; i < regDel.size(); i++)
			{
				regions.at(i)->setOwner(nullptr);
				regions.at(i)->setArmy(0);
				regions.erase(regions.begin() + i);
			}
		}
		currentRace = 0;
	}
	inDecline = false;
}

void Player::readyTroops()
{
}

void Player::abandonRegion(Map *& m)
{
	bool endAbandon = false;
	while (!endAbandon) {
		vector<Region *> av;
		bool validRegion = false;
		cout << "List of regions you can abandon : 0 to go back" << endl;
		for (size_t i = 0; i < regions.size(); i++)
		{
			if (regions.at(i)->getRaceToken()->getName() == r[currentRace]->getName()) {
				av.push_back(regions.at(i));
			}
		}if (av.size() > 1) {
			do {
				for (size_t i = 0; i < av.size(); i++)
				{
					cout << i + 1 << " :" << " , Army count : " << av.at(i)->getArmy() << " , Army type : " << av.at(i)->getRaceToken()->getName() << " Region type : " << av.at(i)->getRegionType()->getName() << " , Special region trait : ";
					for (size_t m = 0; m < av.at(i)->getOtherTiles().size(); m++)
					{
						cout << av.at(i)->getOtherTiles().at(m)->getName() << " ,";
					}
					cout << endl;
				}
				int regionChoice = 0;
				
				try {
					cin >> regionChoice;
					if (cin.good())
					{
						if (regionChoice == 0) {
							validRegion = true;
							endAbandon = true;
						}
						else if (regionChoice > 0 && regionChoice <= av.size()) {
							regionChoice -= 1;
							for (size_t i = 0; i < regions.size(); i++)
							{
								if (regions.at(i)->regionNumber == av.at(regionChoice)->regionNumber) {
									remainingReinforcements += regions.at(i)->getArmy();
									regions.at(i)->setArmy(0);
									regions.at(i)->setOwner(nullptr);
									regions.at(i)->setRaceToken(nullptr);
									regions.erase(regions.begin() + i);
								}
							}
							validRegion = true;
						}


						else {
							string msg = "Please enter a number between 0 and ";
							msg += std::to_string(av.size());

							throw std::runtime_error(msg);

						}
					}
					else {
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						string msg = "Please enter a number between 0 and ";
						msg += std::to_string(av.size());
						throw std::runtime_error(msg);

					}
				}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << endl;;
				}

			} while (!validRegion);

		}
		else {
			endAbandon = true;
		}
	}
}

void Player::redeploy(Map *& m)
{
	int numberUnitToRedeploy = 0;
	if (playerNumber == 1) {
		bool validReinf = false;
		bool endReinf = false;
		while (!endReinf) {
				if (remainingReinforcements != 0) {
					vector<Region *> av;
					cout << "List of regions you can reinforce : 0 to go back" << endl;
					for (size_t i = 0; i < regions.size(); i++)
					{
						if (regions.at(i)->getRaceToken()->getName() == r[currentRace]->getName()) {
							av.push_back(regions.at(i));
						}
					}
					for (size_t i = 0; i < av.size(); i++)
					{
						cout<< "Region "<< i + 1 << " : Army count : "<< av.at(i)->getArmy()<< endl;
					}
					bool validRegion = false;
					int regionChoice = 0;
					do {
						try {
							cin >> regionChoice;
							if (cin.good())
							{
								if (regionChoice == 0) {
									validRegion = true;
									endReinf = true;
								}
								else if (regionChoice > 0 && regionChoice <= av.size()) {
									regionChoice -= 1;
									validRegion = true;
								}


								else {
									string msg = "Please enter a number between 0 and ";
									msg += std::to_string(av.size());
									
									throw std::runtime_error(msg);

								}
							}
							else {
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								string msg = "Please enter a number between 0 and ";
								msg += std::to_string(av.size());
								throw std::runtime_error(msg);

							}
						}
						catch (const std::runtime_error& e) {
							std::cout << e.what() << endl;;
						}
					} while (!validRegion);
					if (!endReinf) {
						bool validunit = false;
						cout << "remaining Units : " << remainingReinforcements << endl;
						do {
							try {
								cin >> numberUnitToRedeploy;
								if (cin.good())
								{
									if (numberUnitToRedeploy == 0) {
										validunit = true;
									}
									if (numberUnitToRedeploy > 0 && numberUnitToRedeploy <= remainingReinforcements) {
										av.at(regionChoice)->setArmy(av.at(regionChoice)->getArmy() + numberUnitToRedeploy);
										remainingReinforcements -= numberUnitToRedeploy;
										validunit = true;
									}


									else {
										string msg = "Please enter a number between 0 and ";
										msg += remainingReinforcements;
										throw std::runtime_error(msg);

									}
								}
								else {
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									string msg = "Please enter a number between 0 and ";
									msg += remainingReinforcements;
									throw std::runtime_error(msg);

								}
							}
							catch (const std::runtime_error& e) {
								std::cout << e.what() << endl;;
							}
						} while (!validunit);
					}
				}
				else {
					endReinf = true;
				}
			
		}
	}
	else {
		if (playerNumber != 4) {
			vector<Region *> av;
			for (size_t i = 0; i < regions.size(); i++)
			{
				if (regions.at(i)->getRaceToken()->getName() == r[currentRace]->getName()) {
					av.push_back(regions.at(i));
				}
			}
			if (av.size() > 0) {
				av.at(0)->setArmy(av.at(0)->getArmy() + remainingReinforcements);
			}
		}
	}
}

void Player::Update(int turn) {
	cout << "New turn" << endl;
	cout << "Turn #" << turn << endl;
}
void Player::Update(string phase)
{
	this->phase = phase;
	cout << "Player " << this->playerNumber << " Is now entering the phase: " << phase << endl;
}
void Player::Update(vector<double> percent)
{
	for (size_t i = 0; i < percent.size(); i++)
	{
		cout << "Percent of the map player " << i + 1 << " owns : ";

		for (size_t j = 0; j < (int)percent.at(i); j++)
		{
			cout << "|";
		}
		cout << " : "<< percent.at(i) << "%" <<endl;
	}
}
void Player::Update(vector<string> resultConquest) {
	for (size_t i = 0; i < resultConquest.size(); i++)
	{
		cout << resultConquest.at(i) << endl;
	}
}

bool Player::continueConquest() {
	return true;
}
vector<Region *> Player::getAvailableRegions(Map *& m) {
	Map* temp = m;
	vector<Region *> availableRegion;
	vector<Region *> allRegions = temp->getRegions();

	for (size_t i = 0; i < allRegions.size(); i++)
	{
		if (allRegions.at(i)->getRegionType()->getName() == "Water") {
			if (allRegions.at(i)->getOwner() != nullptr)
			{

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {
					if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {

					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);

				}
			}
		}
		else {
			if (allRegions.at(i)->getOwner() != nullptr)
			{
				if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
					if (getPower()->getName() == "Flying") {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {
				if (getPower()->getName() == "Flying") {
					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
				}
			}

		}
	}
	if (getPower()->getName() != "Flying") {
		for (size_t i = 0; i < regions.size(); i++)
		{
			
				for (size_t j = 0; j < regions.at(i)->getAdjacencies().size(); j++)
				{
					if (!(std::find(availableRegion.begin(), availableRegion.end(), regions.at(i)->getAdjacencies().at(j)) != availableRegion.end())) {
					if (regions.at(i)->getAdjacencies().at(j)->getRegionType()->getName() != "Water") {
						if (regions.at(i)->getAdjacencies().at(j)->getOwner() != nullptr)
						{

							if (regions.at(i)->getAdjacencies().at(j)->getOwner()->getPlayerNumber() != playerNumber) {
								availableRegion.resize(availableRegion.size() + 1);
								availableRegion.at(availableRegion.size() - 1) = regions.at(i)->getAdjacencies().at(j);
							}
						}
						else {

							availableRegion.resize(availableRegion.size() + 1);
							availableRegion.at(availableRegion.size() - 1) = regions.at(i)->getAdjacencies().at(j);

						}
					}
				}
			}
		}
	}
	
	return availableRegion;
}
void Player::showAvailableRegions(vector<Region *> availableRegion) {
	cout << "All possible Conquests you can do" << endl;
	for (size_t i = 0; i < availableRegion.size(); i++)
	{
		cout << "Conquest # " << i + 1 << ": " << " , Owned by :";
		if (availableRegion.at(i)->getOwner() != nullptr && availableRegion.at(i)->getSpecialPowerTile() == nullptr) {
			cout << " Player " << availableRegion.at(i)->getOwner()->getPlayerNumber() << " , Army count : " << availableRegion.at(i)->getArmy() << " , Army type : " << availableRegion.at(i)->getRaceToken()->getName() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
			for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
			{
				cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
			}
			cout << endl;
		}
		else {
			if (availableRegion.at(i)->getArmy() != 0)
			{
				cout << "Lost tribes , Army count : " << availableRegion.at(i)->getArmy() << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
			else {
				cout << "No one , Army count : 0" << " Region type : " << availableRegion.at(i)->getRegionType()->getName() << " , Special region trait : ";
				for (size_t m = 0; m < availableRegion.at(i)->getOtherTiles().size(); m++)
				{
					cout << availableRegion.at(i)->getOtherTiles().at(m)->getName() << " ,";
				}
				cout << endl;
			}
		}

	}
}
void Player::AIOtherConquest(Map *& m) {
	vector<Region *> availableRegion = getAvailableRegions(m);
	showAvailableRegions(availableRegion);
	
	int unitToSpend = 0;
	int choice = strat->conquer(availableRegion, unitToSpend, remainingReinforcements);
	while (choice != 100) {
		bool adjMountain = false;
		bool adjWater = false;
		bool isCavern = false;
		for (size_t i = 0; i < availableRegion.at(choice)->getNumberAdjacency(); i++)
		{
			if (availableRegion.at(choice)->getAdjacencyAt(i)->getRegionType()->getName() == "Mountain") {
				adjMountain = true;
			}
			if (availableRegion.at(choice)->getAdjacencyAt(i)->getRegionType()->getName() == "Water") {
				adjWater = true;
			}
		}
		for (size_t i = 0; i < availableRegion.at(choice)->getOtherTiles().size(); i++)
		{
			if (availableRegion.at(choice)->getOtherTiles().at(i)->getName() == "Cavern") {
				isCavern = true;
			}
		}
		if ((getRace()->getName() == "Giants" && adjMountain) || (getRace()->getName() == "Tritons" && adjWater) || (getPower()->getName() == "Commando") || (getPower()->getName() == "Underworld" && isCavern)) {
			unitToSpend--;
		}
		if (unitToSpend <= remainingReinforcements) {
			if (availableRegion.at(choice)->getOwner() != nullptr) {
				for (size_t k = 0; k < availableRegion.at(choice)->getOwner()->regions.size(); k++)
				{
					if (availableRegion.at(choice)->getOwner()->regions.at(k) == availableRegion.at(choice)) {
						availableRegion.at(choice)->getOwner()->regions.erase(availableRegion.at(choice)->getOwner()->regions.begin() + k);
					}
				}

			}
			bool notEmpty = false;
			if (availableRegion.at(choice)->getArmy() != 0) {
				notEmpty = true;
			}
			else {
				unitToSpend = 1;
			}
			availableRegion.at(choice)->setOwner(this);
			availableRegion.at(choice)->setArmy(unitToSpend);
			this->regions.resize(regions.size() + 1);
			this->regions.at(regions.size() - 1) = availableRegion.at(choice);
			this->remainingReinforcements -= unitToSpend;
			if (getRace()->getName() == "Amazon") {
				availableRegion.at(choice)->setRaceToken(new AmazonTokens());
			}
			if (getRace()->getName() == "Halflings") {
				availableRegion.at(choice)->setRaceToken(new HalflingsTokens());
			}
			if (getRace()->getName() == "Dwarves") {
				availableRegion.at(choice)->setRaceToken(new DwarvesTokens());
			}
			if (getRace()->getName() == "Humans") {
				availableRegion.at(choice)->setRaceToken(new HumansTokens());
			}
			if (getRace()->getName() == "Orcs") {
				availableRegion.at(choice)->setRaceToken(new OrcsTokens());
			}
			if (getRace()->getName() == "Ratmen") {
				availableRegion.at(choice)->setRaceToken(new RatmenTokens());
			}
			if (getRace()->getName() == "Elves") {
				availableRegion.at(choice)->setRaceToken(new ElvesTokens());
			}
			if (getRace()->getName() == "Skeletons") {
				availableRegion.at(choice)->setRaceToken(new SkeletonsTokens());
			}
			if (getRace()->getName() == "Ghouls") {
				availableRegion.at(choice)->setRaceToken(new GhoulsTokens());
			}
			if (getRace()->getName() == "Sorcerers") {
				availableRegion.at(choice)->setRaceToken(new SorcerersTokens());
			}
			if (getRace()->getName() == "Tritons") {
				availableRegion.at(choice)->setRaceToken(new TritonsTokens());
			}
			if (getRace()->getName() == "Trolls") {
				availableRegion.at(choice)->setRaceToken(new TrollsTokens());
			}
			if (getRace()->getName() == "Wizards") {
				availableRegion.at(choice)->setRaceToken(new WizardsTokens());
			}
			if (getRace()->getName() == "Giants") {
				availableRegion.at(choice)->setRaceToken(new GiantsTokens());
			}
			if (notEmpty) {
				conqueredRegionsNotEmpty++;
			}
			availableRegion = getAvailableRegions(m);
			choice = strat->conquer(availableRegion, unitToSpend, remainingReinforcements);
		}
		else {
			break;
		}
	}
}
void Player::AIFirstConquest(Map *& m) {
	Map* temp = m;
	vector<Region *> availableRegion;
	vector<Region *> allRegions = temp->getRegions();

	for (size_t i = 0; i < allRegions.size(); i++)
	{

		if (allRegions.at(i)->getRegionType()->getName() == "Water") {
			if (allRegions.at(i)->getOwner() != nullptr)
			{

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {
					if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {

				if (m->getPlayers().at(m->getCurrentPlayer())->getPower()->getName() == "Seafaring") {

					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);

				}
			}
		}
		else {
			if (allRegions.at(i)->getOwner() != nullptr)
			{
				if (allRegions.at(i)->getOwner()->getPlayerNumber() != playerNumber) {
					if (getRace()->getName() == "Halfling" || getPower()->getName() == "Flying" || allRegions.at(i)->getIsEdge() == true) {
						availableRegion.resize(availableRegion.size() + 1);
						availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
					}
				}
			}
			else {
				if (getRace()->getName() == "Halfling" || getPower()->getName() == "Flying" || allRegions.at(i)->getIsEdge() == true) {
					availableRegion.resize(availableRegion.size() + 1);
					availableRegion.at(availableRegion.size() - 1) = allRegions.at(i);
				}
			}

		}
	}
	showAvailableRegions(availableRegion);
	int unitToSpend = 0;
	int choice = strat->conquer(availableRegion, unitToSpend, remainingReinforcements);
		bool adjMountain = false;
		bool adjWater = false;
		bool isCavern = false;
		for (size_t i = 0; i < availableRegion.at(choice)->getNumberAdjacency(); i++)
		{
			if (availableRegion.at(choice)->getAdjacencyAt(i)->getRegionType()->getName() == "Mountain") {
				adjMountain = true;
			}
			if (availableRegion.at(choice)->getAdjacencyAt(i)->getRegionType()->getName() == "Water") {
				adjWater = true;
			}
		}
		for (size_t i = 0; i < availableRegion.at(choice)->getOtherTiles().size(); i++)
		{
			if (availableRegion.at(choice)->getOtherTiles().at(i)->getName() == "Cavern") {
				isCavern = true;
			}
		}
		if ((getRace()->getName() == "Giants" && adjMountain) || (getRace()->getName() == "Tritons" && adjWater) || (getPower()->getName() == "Commando") || (getPower()->getName() == "Underworld" && isCavern)) {
			if(unitToSpend != 1)
				unitToSpend--;
		}
		if (unitToSpend <= remainingReinforcements) {
			if (availableRegion.at(choice)->getOwner() != nullptr) {
				for (size_t k = 0; k < availableRegion.at(choice)->getOwner()->regions.size(); k++)
				{
					if (availableRegion.at(choice)->getOwner()->regions.at(k) == availableRegion.at(choice)) {
						availableRegion.at(choice)->getOwner()->regions.erase(availableRegion.at(choice)->getOwner()->regions.begin() + k);
					}
				}

			}
			bool notEmpty = false;
			if (availableRegion.at(choice)->getArmy() != 0) {
				notEmpty = true;
			}
			else {
				unitToSpend = 1;
			}
			availableRegion.at(choice)->setOwner(this);
			availableRegion.at(choice)->setArmy(unitToSpend);
			this->regions.resize(regions.size() + 1);
			this->regions.at(regions.size() - 1) = availableRegion.at(choice);
			this->remainingReinforcements -= unitToSpend;
			if (getRace()->getName() == "Amazon") {
				availableRegion.at(choice)->setRaceToken(new AmazonTokens());
			}
			if (getRace()->getName() == "Halflings") {
				availableRegion.at(choice)->setRaceToken(new HalflingsTokens());
			}
			if (getRace()->getName() == "Dwarves") {
				availableRegion.at(choice)->setRaceToken(new DwarvesTokens());
			}
			if (getRace()->getName() == "Humans") {
				availableRegion.at(choice)->setRaceToken(new HumansTokens());
			}
			if (getRace()->getName() == "Orcs") {
				availableRegion.at(choice)->setRaceToken(new OrcsTokens());
			}
			if (getRace()->getName() == "Ratmen") {
				availableRegion.at(choice)->setRaceToken(new RatmenTokens());
			}
			if (getRace()->getName() == "Elves") {
				availableRegion.at(choice)->setRaceToken(new ElvesTokens());
			}
			if (getRace()->getName() == "Skeletons") {
				availableRegion.at(choice)->setRaceToken(new SkeletonsTokens());
			}
			if (getRace()->getName() == "Ghouls") {
				availableRegion.at(choice)->setRaceToken(new GhoulsTokens());
			}
			if (getRace()->getName() == "Sorcerers") {
				availableRegion.at(choice)->setRaceToken(new SorcerersTokens());
			}
			if (getRace()->getName() == "Tritons") {
				availableRegion.at(choice)->setRaceToken(new TritonsTokens());
			}
			if (getRace()->getName() == "Trolls") {
				availableRegion.at(choice)->setRaceToken(new TrollsTokens());
			}
			if (getRace()->getName() == "Wizards") {
				availableRegion.at(choice)->setRaceToken(new WizardsTokens());
			}
			if (getRace()->getName() == "Giants") {
				availableRegion.at(choice)->setRaceToken(new GiantsTokens());
			}
			if (notEmpty) {
				conqueredRegionsNotEmpty++;
			}
			
			AIOtherConquest(m);
		}
		if(remainingReinforcements < 2){
			inDecline = true;
		}
}
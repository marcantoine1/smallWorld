#pragma once
#include <string>
using namespace std;
class Special_Power_Tile
{
private:

public:
	virtual ~Special_Power_Tile() {}
	virtual string getName() = 0;
};
class Dragon : public Special_Power_Tile
{
private:
	string name = "Dragon";
public:
	virtual string getName() {
		return name;
	}
};
class Hero : public Special_Power_Tile
{
private:
	string name = "Hero";
public:
	virtual string getName() {
		return name;
	}
};
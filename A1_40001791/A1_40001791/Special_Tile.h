#pragma once
using namespace std;
class Special_Tile
{
private:

public:
	virtual ~Special_Tile() {}
	virtual string getName() = 0;
	
};
class Normal : public Special_Tile
{
private:
	string name = "Normal";
public:
	virtual string getName() {
		return name;
	}
};
class Troll_Lair : public Special_Tile
{
private:
	string name = "Troll_Lair";
public:
	virtual string getName() {
		return name;
	}
};
class Fortress : public Special_Tile
{
private:
	string name = "Fortress";
public:
	virtual string getName() {
		return name;
	}
};
class Mountain_Tile : public Special_Tile
{
private:
	string name = "Mountain";
public:
	virtual string getName() {
		return name;
	}
};
class Encampment : public Special_Tile
{
private:
	string name = "Encampment";
public:
	virtual string getName() {
		return name;
	}
};
class Hole_In_Ground : public Special_Tile
{
private:
	string name = "Hole in the ground";
public:
	virtual string getName() {
		return name;
	}
};

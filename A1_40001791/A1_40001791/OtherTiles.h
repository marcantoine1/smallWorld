#pragma once
#include <string>
using namespace std;
class OtherTiles
{
public:
	virtual ~OtherTiles() {}
	virtual void type() = 0;
	virtual string getName() = 0;
};
class FarmLand : public OtherTiles
{
private :
	string name = "FarmLand";
public:
	virtual void type()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Mine : public OtherTiles
{
private:
	string name = "Mine";
public:
	virtual void type()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Magic : public OtherTiles
{
private:
	string name = "Magic";
public:
	virtual void type()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Cavern : public OtherTiles
{
private:
	string name = "Cavern";
public:
	virtual void type()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Standard : public OtherTiles
{
private:
	string name = "Standard";
public:
	virtual void type()
	{

	}
	virtual string getName() {
		return name;
	}
};


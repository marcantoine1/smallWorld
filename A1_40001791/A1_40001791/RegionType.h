#pragma once
#include <string>
using namespace std;
class RegionType
{
public:
	virtual ~RegionType() {}
	
	virtual string getName() = 0;
};
class Mountain : public RegionType
{
private:
	string name = "Mountain";
public:
	virtual string getName() {
		return name;
	}
};
class Hill : public RegionType
{
private:
	string name = "Hill";
public:
	virtual string getName() {
		return name;
	}
};
class Swamp : public RegionType
{
private:
	string name = "Swamp";
public:
	virtual string getName() {
		return name;
	}
};
class Field : public RegionType
{
private:
	string name = "Field";
public:
	virtual string getName() {
		return name;
	}
};
class Water : public RegionType
{
private:
	string name = "Water";
public:
	virtual string getName() {
		return name;
	}
};
class Forest_Type : public RegionType
{
private:
	string name = "Forest";
public:
	virtual string getName() {
		return name;
	}
};
#pragma once
#include <string>
using namespace std;
class Race
{
private:
	
public:
	virtual ~Race() {}
	virtual void specialAbility() = 0;
	virtual string getName() = 0;
};
class Amazon : public Race
{
private:
	string name = "Amazon";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Halflings : public Race
{
private:
	string name = "Halflings";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Dwarves : public Race
{
private:
	string name = "Dwarves";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Humans : public Race
{
private:
	string name = "Humans";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Orcs : public Race
{
private:
	string name = "Orcs";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Ratmen : public Race
{
private:
	string name = "Ratment";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Elves : public Race
{
private:
	string name = "Elves";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Skeletons : public Race
{
private:
	string name = "Skeletons";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Ghouls : public Race
{
private:
	string name = "Ghouls";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Sorcerers : public Race
{
private:
	string name = "Sorcerers";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Tritons : public Race
{
private:
	string name = "Tritons";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Trolls : public Race
{
private:
	string name = "Trolls";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Wizards : public Race
{
private:
	string name = "Wizards";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};
class Giants : public Race
{
private:
	string name = "Giants";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
};












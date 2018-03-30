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
	virtual int getReinforcements() = 0;
};
class Amazon : public Race
{
private:
	string name = "Amazon";
	int reinforcements = 10;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Halflings : public Race
{
private:
	string name = "Halflings";
	int reinforcements = 6;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Dwarves : public Race
{
private:
	string name = "Dwarves";
	int reinforcements = 3;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Humans : public Race
{
private:
	string name = "Humans";
	int reinforcements = 5;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Orcs : public Race
{
private:
	int reinforcements = 5;
	string name = "Orcs";
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Ratmen : public Race
{
private:
	string name = "Ratmen";
	int reinforcements = 8;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Elves : public Race
{
private:
	string name = "Elves";
	int reinforcements = 6;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Skeletons : public Race
{
private:
	string name = "Skeletons";
	int reinforcements = 6;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Ghouls : public Race
{
private:
	string name = "Ghouls";
	int reinforcements = 5;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Sorcerers : public Race
{
private:
	string name = "Sorcerers";
	int reinforcements = 5;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Tritons : public Race
{
private:
	string name = "Tritons";
	int reinforcements = 6;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Trolls : public Race
{
private:
	string name = "Trolls";
	int reinforcements = 5;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Wizards : public Race
{
private:
	string name = "Wizards";
	int reinforcements = 5;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};
class Giants : public Race
{
private:
	string name = "Giants";
	int reinforcements = 6;
public:
	virtual void specialAbility()
	{

	}
	virtual string getName() {
		return name;
	}
	virtual int getReinforcements() {
		return reinforcements;
	}
};












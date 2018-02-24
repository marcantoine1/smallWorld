#pragma once
#include <string>
using namespace std;
class RaceTokens
{
private:

public:
	virtual ~RaceTokens() {}
	virtual string getName() = 0;
};
class AmazonTokens : public RaceTokens
{
private:
	string name = "Amazon";
public:
	virtual string getName() {
		return name;
	}
};
class HalflingsTokens : public RaceTokens
{
private:
	string name = "Halflings";
public:
	virtual string getName() {
		return name;
	}
};
class DwarvesTokens : public RaceTokens
{
private:
	string name = "Dwarves";
public:
	virtual string getName() {
		return name;
	}
};
class HumansTokens : public RaceTokens
{
private:
	string name = "Humans";
public:
	virtual string getName() {
		return name;
	}
};
class OrcsTokens : public RaceTokens
{
private:
	string name = "Orcs";
public:
	virtual string getName() {
		return name;
	}
};
class RatmenTokens : public RaceTokens
{
private:
	string name = "Ratment";
public:
	virtual string getName() {
		return name;
	}
};
class ElvesTokens : public RaceTokens
{
private:
	string name = "Elves";
public:
	virtual string getName() {
		return name;
	}
};
class SkeletonsTokens : public RaceTokens
{
private:
	string name = "Skeletons";
public:
	virtual string getName() {
		return name;
	}
};
class GhoulsTokens : public RaceTokens
{
private:
	string name = "Ghouls";
public:
	virtual string getName() {
		return name;
	}
};
class SorcerersTokens : public RaceTokens
{
private:
	string name = "Sorcerers";
public:
	virtual string getName() {
		return name;
	}
};
class TritonsTokens : public RaceTokens
{
private:
	string name = "Tritons";
public:
	virtual string getName() {
		return name;
	}
};
class TrollsTokens : public RaceTokens
{
private:
	string name = "Trolls";
public:
	virtual string getName() {
		return name;
	}
};
class WizardsTokens : public RaceTokens
{
private:
	string name = "Wizards";
public:
	virtual string getName() {
		return name;
	}
};
class GiantsTokens : public RaceTokens
{
private:
	string name = "Giants";
public:
	virtual string getName() {
		return name;
	}
};












#pragma once
class Special_Power
{
public:
	virtual ~Special_Power() {}
	virtual void power() = 0;
	virtual string getName() = 0;
	virtual int getReinforcements() = 0;
};
class Alchemist : public Special_Power
{
private:
	int reinforcements = 4;
	string name = "Alchemist";
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Bivouacking : public Special_Power
{
private:
	string name = "Bivouacking";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Berserk : public Special_Power
{
private:
	string name = "Berserk";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Commando : public Special_Power
{
private:
	string name = "Commando";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Diplomat : public Special_Power
{
private:
	string name = "Diplomat";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class DragonMaster : public Special_Power
{
private:
	string name = "Dragon Master";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Merchant : public Special_Power
{
private:
	string name = "Merchant";
	int reinforcements = 2;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Mounted : public Special_Power
{
private:
	string name = "Mounted";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Flying : public Special_Power
{
private:
	string name = "Flying";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Pillaging : public Special_Power
{
private:
	string name = "Pillaging";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Forest : public Special_Power
{
private:
	string name = "Forest";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Seafaring : public Special_Power
{
private:
	string name = "Seafaring";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Fortified : public Special_Power
{
private:
	string name = "Fortified";
	int reinforcements = 3;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Spirit : public Special_Power
{
private:
	string name = "Spirit";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Heroic : public Special_Power
{
private:
	string name = "Heroic";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Stout : public Special_Power
{
private:
	string name = "Stout";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Hill_SP : public Special_Power
{
private:
	string name = "Hill";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Swamp_SP : public Special_Power
{
private:
	string name = "Swamp";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Underworld : public Special_Power
{
private:
	string name = "Underworld";
	int reinforcements = 5;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
class Wealthy : public Special_Power
{
private:
	string name = "Wealthy";
	int reinforcements = 4;
public:
	virtual void power()
	{

	}
	virtual int getReinforcements() {
		return reinforcements;
	}
	virtual string getName() {
		return name;
	}
};
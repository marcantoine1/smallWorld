#pragma once

class RegionType
{
public:
	virtual ~RegionType() {}
	virtual void type() = 0;
};
class Mountain : public RegionType
{
public:
	virtual void type()
	{

	}
};
class Hill : public RegionType
{
public:
	virtual void type()
	{

	}
};
class Swamp : public RegionType
{
public:
	virtual void type()
	{

	}
};
class Field : public RegionType
{
public:
	virtual void type()
	{

	}
};
class Water : public RegionType
{
public:
	virtual void type()
	{

	}
};
#pragma once
#include <iostream>
#include <exception>
using namespace std;

class InvalidInputException : public exception
{
private:
	string message;
public :
	InvalidInputException(const string msg);
	// OVERIDE BASE CLASS VIRTUAL METHOD

	virtual const char* what() const throw() override
	{
		return message.c_str();
	}
};
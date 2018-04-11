#include "stdafx.h"
#include "InvalidInputException.h"

InvalidInputException::InvalidInputException(const string msg)
{
	message = msg;
}

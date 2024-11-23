#include "Location.h"

Location::Location()
{
	mLocationX = 0;
	mLocationY = 0;
}

Location::Location(int x, int y)
{
	mLocationX = x;
	mLocationY = y;
}

int Location::getXcoordinate()
{
	return mLocationX;
}

int Location::getYcoordinate()
{
	return mLocationY;
}


#include "TableTop.h"
#include <iostream>
TableTop::TableTop(unsigned maxX, unsigned maxY)
{
	mMaxWidth = maxX;
	mMaxHeight = maxY;
}

bool TableTop::isWithinBounds(Location& loc) 
{
	bool withinBounds = true;

	int x = loc.getXcoordinate();
	int y = loc.getYcoordinate();

	if (x < 0 || x >= (int) mMaxWidth)
		withinBounds = false;

	if (y < 0 || y >= (int) mMaxHeight)
		withinBounds = false;

	return withinBounds;
}



#include "Board.h"
#include <iostream>
bool Board::isWithinBounds(Location& loc)
{
	return true;
}

bool Board::canPlace(Location& l)
{
	bool can = false;

	if (isWithinBounds(l))
		can = true;

	return can;
}

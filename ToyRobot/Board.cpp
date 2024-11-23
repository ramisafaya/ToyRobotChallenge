#include "Board.h"
#include <iostream>

bool Board::canPlace(Location& loc)
{
	bool can = false;

	if (isWithinBounds(loc))
		can = true;

	return can;
}

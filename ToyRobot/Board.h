#pragma once

#include "Location.h"
#include "Direction.h"

class Board
{
	protected:
		virtual bool isWithinBounds(Location& loc) = 0;

	public:
		virtual bool canPlace(Location& loc);
};


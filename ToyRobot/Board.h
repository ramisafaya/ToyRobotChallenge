#pragma once

#include "Location.h"
#include "Direction.h"

class Board
{
	protected:
		virtual bool isWithinBounds(Location& loc);

	public:
		virtual bool canPlace(Location& l);
};


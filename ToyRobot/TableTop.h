#pragma once
#include "Location.h"
#include "DIrection.h"
#include "Entity.h"

class TableTop : public Board
{
	unsigned int mMaxWidth;
	unsigned int mMaxHeight;

	protected:
		virtual bool isWithinBounds(Location& loc) override;

	public:
		TableTop(unsigned maxX, unsigned maxY);
};


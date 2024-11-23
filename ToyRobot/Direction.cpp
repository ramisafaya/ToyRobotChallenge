#include "Direction.h"

Direction::Direction()
{
	mFacingDirection = Direction::Facing::north;
}

Direction::Direction(Direction::Facing dir)
{
	mFacingDirection = dir;
}

void Direction::turnLeft()
{
	if (mFacingDirection == Direction::Facing::west)
	{
		mFacingDirection = Direction::Facing::south;
	}
	else
	{
		mFacingDirection = static_cast<Direction::Facing>(static_cast<int>(mFacingDirection) - 1);
	}
}

void Direction::turnRight()
{
	if (mFacingDirection == Direction::Facing::south)
	{
		mFacingDirection = Direction::Facing::west;
	}
	else
	{
		mFacingDirection = static_cast<Direction::Facing>(static_cast<int>(mFacingDirection) + 1);
	}
}

Direction::Facing Direction::getDirection()
{
	return mFacingDirection;
}

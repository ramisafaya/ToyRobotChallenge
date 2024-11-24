#include "Robot.h"
#include <memory>

bool Robot::move()
{
	bool moved = false;

	if (isPlaced())
	{
		Location& loc = getLocation();
		Direction& dir = getDirection();
		std::shared_ptr<Board> board = getBoard();

		int x = loc.getXcoordinate();
		int y = loc.getYcoordinate();

		bool valid = true;
		switch (dir.getDirection())
		{
			case Direction::Facing::east:
				x++;
				break;
			case Direction::Facing::north:
				y++;
				break;
			case Direction::Facing::south:
				y--;
				break;
			case Direction::Facing::west:
				x--;
				break;
			default:
				valid = false;
				break;
		}

		Location newLoc(x, y);
		if (valid && board != nullptr && board->canPlace(newLoc))
		{
			setLocation(newLoc);
			moved = true;
		}
	}

	return moved;
}

bool Robot::rotateLeft()
{
	bool rotated = false;

	if (isPlaced())
	{
		Direction& dir = getDirection();
		dir.turnLeft();
		rotated = true;
	}
	return rotated;
}

bool Robot::rotateRight()
{
	bool rotated = false;

	if (isPlaced())
	{
		Direction& dir = getDirection();
		dir.turnRight();
		rotated = true;
	}
	return rotated;
}

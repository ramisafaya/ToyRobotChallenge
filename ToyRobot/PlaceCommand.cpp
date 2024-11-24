#include "PlaceCommand.h"

PlaceCommand::PlaceCommand(std::shared_ptr<Entity> entity, std::shared_ptr<Board> board, Location loc, Direction dir)
	: Command(entity)
{
	mLocation = loc;
	mDirection = dir;
	mBoard = board;
}

bool PlaceCommand::action()
{
	bool actioned = false;
	std::shared_ptr<Entity> entity = getEntity();
	if (entity != nullptr && mBoard != nullptr)
	{
		actioned = entity->place(mBoard, mLocation, mDirection);
	}

	return actioned;
}

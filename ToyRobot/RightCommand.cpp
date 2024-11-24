#include "RightCommand.h"

RightCommand::RightCommand(std::shared_ptr<Entity> entity)
	: Command(entity)
{
}

bool RightCommand::action()
{
	bool actioned = false;
	std::shared_ptr<Entity> entity = getEntity();
	if (entity != nullptr)
	{
		actioned = entity->rotateRight();
	}

	return actioned;
}

#include "LeftCommand.h"

LeftCommand::LeftCommand(std::shared_ptr<Entity> entity)
	: Command(entity)
{
}

bool LeftCommand::action()
{
	bool actioned = false;
	std::shared_ptr<Entity> entity = getEntity();
	if (entity != nullptr)
	{
		actioned = entity->rotateLeft();
	}

	return actioned;
}

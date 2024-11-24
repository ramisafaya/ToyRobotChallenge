#include "Command.h"

Command::Command(std::shared_ptr<Entity> entity)
{
	mEntity = entity;
}

std::shared_ptr<Entity> Command::getEntity()
{
	return mEntity;
}

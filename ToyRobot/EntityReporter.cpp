#include "EntityReporter.h"

EntityReporter::EntityReporter(std::shared_ptr<Entity> entity)
{
	mEntity = entity;
}

std::shared_ptr<Entity> EntityReporter::getEntity()
{
	return mEntity;
}

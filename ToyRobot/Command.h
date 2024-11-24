#pragma once
#include <memory>
#include "Entity.h"

class Command
{
	std::shared_ptr<Entity> mEntity;

	protected:
		std::shared_ptr<Entity> getEntity();

	public:
		Command(std::shared_ptr<Entity> entity);
		virtual bool action() = 0;
};


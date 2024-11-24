#pragma once
#include <memory>
#include "Entity.h"

class EntityReporter
{
	std::shared_ptr<Entity> mEntity;

	public:
		EntityReporter(std::shared_ptr<Entity> entity);
		
		std::shared_ptr<Entity> getEntity();

		virtual bool report() = 0;
};


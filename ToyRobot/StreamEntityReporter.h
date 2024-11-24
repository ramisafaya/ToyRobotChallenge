#pragma once
#include <ostream>
#include "EntityReporter.h"

class StreamEntityReporter : public EntityReporter
{
	std::shared_ptr<std::ostream> mStream;

	public:
		StreamEntityReporter(std::shared_ptr<Entity> entity, std::shared_ptr<std::ostream> stream);
		virtual bool report() override;
};


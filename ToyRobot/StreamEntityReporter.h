#pragma once
#include <ostream>
#include "EntityReporter.h"

class StreamEntityReporter : public EntityReporter
{
	static const std::string REPORT_STRING_NORTH;
	static const std::string REPORT_STRING_SOUTH;
	static const std::string REPORT_STRING_EAST;
	static const std::string REPORT_STRING_WEST;

	std::shared_ptr<std::ostream> mStream;

	public:
		StreamEntityReporter(std::shared_ptr<Entity> entity, std::shared_ptr<std::ostream> stream);
		virtual bool report() override;
};


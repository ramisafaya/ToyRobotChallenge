#pragma once
#include "Command.h"
#include "EntityReporter.h"

class ReportCommand : public Command
{
	std::shared_ptr<EntityReporter> mReporter;

	public:
		ReportCommand(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter);
		virtual bool action() override;
};


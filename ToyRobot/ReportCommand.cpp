#include "ReportCommand.h"

ReportCommand::ReportCommand(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter)
	: Command(entity)
{
	mReporter = reporter;
}

bool ReportCommand::action()
{
	bool actioned = false;

	std::shared_ptr<Entity> entity = getEntity();
	if (entity != nullptr && mReporter != nullptr)
	{
		actioned = mReporter->report();
	}

	return actioned;
}

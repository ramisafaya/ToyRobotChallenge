#pragma once
#include "Command.h"
class LeftCommand : public Command
{
	public:
		LeftCommand(std::shared_ptr<Entity> entity);
		virtual bool action() override;
};


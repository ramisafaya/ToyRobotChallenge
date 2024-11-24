#pragma once
#include "Command.h"
class MoveCommand : public Command
{
	public:
		MoveCommand(std::shared_ptr<Entity> entity);
		virtual bool action() override;
};


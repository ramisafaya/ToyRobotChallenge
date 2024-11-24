#pragma once
#include "Command.h"
class RightCommand : public Command
{
	public:
		RightCommand(std::shared_ptr<Entity> entity);
		virtual bool action() override;
};


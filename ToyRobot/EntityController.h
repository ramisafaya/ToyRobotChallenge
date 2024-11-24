#pragma once
#include "Command.h"
#include "EntityReporter.h"
#include "Entity.h"

class EntityController
{
	std::shared_ptr<Entity> mEntity;
	std::shared_ptr<EntityReporter> mReporter;
	std::shared_ptr<Board> mBoard;

	protected:
		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<EntityReporter> getReporter();
		std::shared_ptr<Board> getBoard();
	
	public:
		EntityController(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter, std::shared_ptr<Board> board);

		virtual std::shared_ptr<Command> nextCommand() = 0;
};


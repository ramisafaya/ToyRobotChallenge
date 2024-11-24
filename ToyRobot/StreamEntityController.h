#pragma once
#include "EntityController.h"
#include "Command.h"
#include "Direction.h"
#include "Location.h"
#include <istream>

class StreamEntityController : public EntityController
{
	std::shared_ptr<std::istream> mStream;

	static std::shared_ptr<Location> getLocationFromPlaceLine(std::string line);
	static std::shared_ptr<Direction> getDirectionFromPlaceLine(std::string line);

	public:
		StreamEntityController(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter, std::shared_ptr<Board> board, std::shared_ptr<std::istream> stream);
		virtual std::shared_ptr<Command> nextCommand() override;
};


#pragma once
#include "EntityController.h"
#include "Command.h"
#include "Direction.h"
#include "Location.h"
#include <istream>

class StreamEntityController : public EntityController
{
	static const std::string COMMAND_STRING_PLACE;
	static const std::string COMMAND_STRING_MOVE;
	static const std::string COMMAND_STRING_LEFT;
	static const std::string COMMAND_STRING_RIGHT;
	static const std::string COMMAND_STRING_REPORT;

	static const std::string COMMAND_STRING_NORTH;
	static const std::string COMMAND_STRING_SOUTH;
	static const std::string COMMAND_STRING_EAST;
	static const std::string COMMAND_STRING_WEST;

	std::shared_ptr<std::istream> mStream;

	static std::shared_ptr<Location> getLocationFromPlaceLine(std::string line);
	static std::shared_ptr<Direction> getDirectionFromPlaceLine(std::string line);

	public:
		StreamEntityController(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter, std::shared_ptr<Board> board, std::shared_ptr<std::istream> stream);
		virtual std::shared_ptr<Command> nextCommand() override;
};


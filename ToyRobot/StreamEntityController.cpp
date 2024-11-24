#include "StreamEntityController.h"
#include <string>
#include "MoveCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "PlaceCommand.h"
#include "ReportCommand.h"

StreamEntityController::StreamEntityController(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter, std::shared_ptr<Board> board, std::shared_ptr<std::istream> stream)
	: EntityController(entity, reporter, board)
{
	mStream = stream;
}

std::shared_ptr<Location> StreamEntityController::getLocationFromPlaceLine(std::string line)
{
	// line is expected to be PLACE X,Y,F
	std::shared_ptr<Location> loc = nullptr;
	int x = 0;
	int y = 0;

	int startX = line.find("PLACE") + 5;
	int endX = line.find_first_of(',', startX);
	int startY = endX + 1;
	int endY = line.find_first_of(',', endX+1);
	if (startX != std::string::npos && endX != std::string::npos && startY != std::string::npos && endY != std::string::npos)
	{
		try
		{
			x = stoi(line.substr(startX, endX - 1));
			y = stoi(line.substr(startY, endY - 1));
			loc = std::shared_ptr<Location>(new Location(x, y));
		}
		catch (const std::invalid_argument& e)
		{
			loc = nullptr;
		}
		catch (const std::out_of_range& e)
		{
			loc = nullptr;
		}
	}

	return loc;
}

std::shared_ptr<Direction> StreamEntityController::getDirectionFromPlaceLine(std::string line)
{
	// line is expected to be PLACE X,Y,F
	std::shared_ptr<Direction> dir = nullptr;

	int lastComma = line.find_last_of(',');
	if (lastComma != std::string::npos)
	{
		std::string dirStr = line.substr(lastComma + 1);
		
		if (dirStr.find("NORTH") != std::string::npos)
		{
			dir = std::shared_ptr<Direction>(new Direction(Direction::Facing::north));
		}
		else if (dirStr.find("SOUTH") != std::string::npos)
		{
			dir = std::shared_ptr<Direction>(new Direction(Direction::Facing::south));
		}
		else if (dirStr.find("EAST") != std::string::npos)
		{
			dir = std::shared_ptr<Direction>(new Direction(Direction::Facing::east));
		}
		else if (dirStr.find("WEST") != std::string::npos)
		{
			dir = std::shared_ptr<Direction>(new Direction(Direction::Facing::west));
		}
	}
	return dir;
}

std::shared_ptr<Command> StreamEntityController::nextCommand()
{
	std::shared_ptr<Command> cmd = nullptr;
	if (mStream != nullptr)
	{
		std::string line;
		std::getline(*mStream, line);
		// ignore the command (return nullptr) if any of the text is unexpected
		// if we get what we expect, we process, even if there are extra characters on the line
		if (line.find("MOVE") != std::string::npos)
		{
			cmd = std::shared_ptr<MoveCommand>(new MoveCommand(getEntity()));
		}
		else if (line.find("LEFT") != std::string::npos)
		{
			cmd = std::shared_ptr<LeftCommand>(new LeftCommand(getEntity()));
		}
		else if (line.find("RIGHT") != std::string::npos)
		{
			cmd = std::shared_ptr<RightCommand>(new RightCommand(getEntity()));
		}
		else if (line.find("PLACE") != std::string::npos)
		{
			std::shared_ptr<Location> location = getLocationFromPlaceLine(line);
			std::shared_ptr<Direction> direction = getDirectionFromPlaceLine(line);
			if (location != nullptr && direction != nullptr)
				cmd = std::shared_ptr<PlaceCommand>(new PlaceCommand(getEntity(), getBoard(), *location, *direction));
		}
		else if (line.find("REPORT") != std::string::npos)
		{
			cmd = std::shared_ptr<ReportCommand>(new ReportCommand(getEntity(), getReporter()));
		}
	}

	return cmd;
}

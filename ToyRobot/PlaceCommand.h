#pragma once
#include "Command.h"
#include "Location.h"
#include "Direction.h"
#include "Board.h"
#include <memory>

class PlaceCommand : public Command
{
	Location mLocation;
	Direction mDirection;
	std::shared_ptr<Board> mBoard;

	public:
		PlaceCommand(std::shared_ptr<Entity> entity, std::shared_ptr<Board> board, Location loc, Direction dir);
		virtual bool action() override;
};


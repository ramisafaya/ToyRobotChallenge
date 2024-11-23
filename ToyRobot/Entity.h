#pragma once
#include "Board.h"
#include "Location.h"
#include "Direction.h"

#include <memory>

class Entity
{
	std::shared_ptr<Board> mBoard;
	Direction mDirection;
	Location mLocation;
	bool mPlaced;

	protected:
		void setDirection(Direction& dir);
		void setLocation(Location& loc);

	public:
		Entity();

		bool isPlaced() const;

		Direction& getDirection();
		Location& getLocation();
		std::shared_ptr<Board> getBoard();

		virtual bool place(std::shared_ptr<Board> board, Location& loc, Direction& dir);
		virtual bool move() = 0;
		virtual bool rotateLeft() = 0;
		virtual bool rotateRight() = 0;
};


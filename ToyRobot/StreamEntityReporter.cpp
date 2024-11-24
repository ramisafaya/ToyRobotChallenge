#include "StreamEntityReporter.h"

StreamEntityReporter::StreamEntityReporter(std::shared_ptr<Entity> entity, std::shared_ptr<std::ostream> stream)
	: EntityReporter(entity)
{
	mStream = stream;
}

bool StreamEntityReporter::report()
{
	bool reported = false;

	// print X,Y,F to output stream
	std::shared_ptr<Entity> entity = getEntity();
	if (entity != nullptr && entity->isPlaced())
	{
		Location& loc = entity->getLocation();
		Direction& dir = entity->getDirection();

		std::string dirString = "";
		bool valid = true;
		switch (dir.getDirection())
		{
			case Direction::Facing::north:
				dirString = "NORTH";
				break;
			case Direction::Facing::south:
				dirString = "SOUTH";
				break;
			case Direction::Facing::east:
				dirString = "EAST";
				break;
			case Direction::Facing::west:
				dirString = "WEST";
				break;
			default:
				valid = false;
				break;
		}

		if (valid)
		{
			*mStream << loc.getXcoordinate() << "," << loc.getYcoordinate() << "," << dirString << std::endl;
			reported = true;
		}
	}

	return reported;
}

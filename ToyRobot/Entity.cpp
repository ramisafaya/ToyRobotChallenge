#include "Entity.h"

Entity::Entity()
{
    mPlaced = false;
    mBoard = nullptr;
}

void Entity::setDirection(Direction& dir)
{
    mDirection = dir;
}

Direction& Entity::getDirection()
{
    return mDirection;
}

Location& Entity::getLocation()
{
    return mLocation;
}

std::shared_ptr<Board> Entity::getBoard()
{
    return mBoard;
}

void Entity::setLocation(Location& loc)
{
    mLocation = loc;
}


bool Entity::isPlaced() const
{
    return mPlaced;
}

bool Entity::place(std::shared_ptr<Board> board, Location& loc, Direction& dir)
{
    bool placed = false;
    if (board != nullptr && board->canPlace(loc))
    {
        mPlaced = true;
        mBoard = board;
        mLocation = loc;
        mDirection = dir;
        placed = true;
    }
    return placed;
}

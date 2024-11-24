#include "MoveCommand.h"

MoveCommand::MoveCommand(std::shared_ptr<Entity> entity)
    : Command(entity)
{
}

bool MoveCommand::action()
{
    bool actioned = false;
    std::shared_ptr<Entity> entity = getEntity();
    if (entity != nullptr)
    {
        actioned = entity->move();
    }

    return actioned;
}

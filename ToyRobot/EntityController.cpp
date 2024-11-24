#include "EntityController.h"

EntityController::EntityController(std::shared_ptr<Entity> entity, std::shared_ptr<EntityReporter> reporter, std::shared_ptr<Board> board)
{
    mEntity = entity;
    mReporter = reporter;
    mBoard = board;
}

std::shared_ptr<Entity> EntityController::getEntity()
{
    return mEntity;
}

std::shared_ptr<EntityReporter> EntityController::getReporter()
{
    return mReporter;
}

std::shared_ptr<Board> EntityController::getBoard()
{
    return mBoard;
}

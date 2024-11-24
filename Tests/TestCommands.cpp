#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Command.h"
#include "../ToyRobot/MoveCommand.h"
#include "../ToyRobot/LeftCommand.h"
#include "../ToyRobot/RightCommand.h"
#include "../ToyRobot/PlaceCommand.h"
#include "../ToyRobot/ReportCommand.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/TableTop.h"
#include "../ToyRobot/Location.h"
#include "../ToyRobot/Direction.h"
#include "../ToyRobot/StreamEntityReporter.h"
#include <memory>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCommands
{
	TEST_CLASS(TestCommands)
	{
	public:

		TEST_METHOD(TestMoveCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(t, l, d);
			std::unique_ptr<MoveCommand> cmd(new MoveCommand(r));
			cmd->action();
			Location result = r->getLocation();
			Assert::AreEqual(2, result.getYcoordinate());
		}

		TEST_METHOD(TestMoveCommandNotPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			std::unique_ptr<MoveCommand> cmd(new MoveCommand(r));
			cmd->action();
			Location result = r->getLocation();
			Assert::AreEqual(0, result.getYcoordinate());
		}

		TEST_METHOD(TestLeftCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(t, l, d);
			std::unique_ptr<LeftCommand> cmd(new LeftCommand(r));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(static_cast<int>(Direction::Facing::west), static_cast<int>(result.getDirection()));
		}

		TEST_METHOD(TestLeftCommandNotPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			std::unique_ptr<LeftCommand> cmd(new LeftCommand(r));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(static_cast<int>(Direction::Facing::north), static_cast<int>(result.getDirection()));
		}

		TEST_METHOD(TestRightCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(t, l, d);
			std::unique_ptr<RightCommand> cmd(new RightCommand(r));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(static_cast<int>(Direction::Facing::east), static_cast<int>(result.getDirection()));
		}

		TEST_METHOD(TestRightCommandNotPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			std::unique_ptr<RightCommand> cmd(new RightCommand(r));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(static_cast<int>(Direction::Facing::north), static_cast<int>(result.getDirection()));
		}

		TEST_METHOD(TestPlaceCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			std::unique_ptr<PlaceCommand> cmd(new PlaceCommand(r, t, l, d));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(true, r->isPlaced());
		}

		TEST_METHOD(TestPlaceCommandOutofBounds)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(5, 1);
			Direction d(Direction::Facing::north);
			std::unique_ptr<PlaceCommand> cmd(new PlaceCommand(r, t, l, d));
			cmd->action();
			Direction result = r->getDirection().getDirection();
			Assert::AreEqual(false, r->isPlaced());
		}

		TEST_METHOD(TestReportCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(t, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::unique_ptr<ReportCommand> cmd(new ReportCommand(r, reporter));
			cmd->action();
			Assert::AreEqual(std::string("1,1,NORTH\n"), actual->str());
		}

		TEST_METHOD(TestReportCommandNotPlaced)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> t(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::unique_ptr<ReportCommand> cmd(new ReportCommand(r, reporter));
			cmd->action();
			Assert::AreEqual(std::string(""), actual->str());
		}
	};
}

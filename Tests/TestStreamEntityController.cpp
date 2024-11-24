#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/StreamEntityController.h"
#include "../ToyRobot/StreamEntityReporter.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/TableTop.h"
#include "../ToyRobot/Command.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestStreamEntityController
{
	TEST_CLASS(TestStreamEntityController)
	{
	public:

		TEST_METHOD(TestValidMove)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("MOVE\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string("1,2,NORTH\n"), actual->str());
		}

		TEST_METHOD(TestValidLeft)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("LEFT\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string("1,1,WEST\n"), actual->str());
		}

		TEST_METHOD(TestValidRight)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("RIGHT\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string("1,1,EAST\n"), actual->str());
		}

		TEST_METHOD(TestValidReport)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("REPORT\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
			}
			Assert::AreEqual(std::string("1,1,NORTH\n"), actual->str());
		}

		TEST_METHOD(TestAcceptableCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("REPORT abcd\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
			}
			Assert::AreEqual(std::string("1,1,NORTH\n"), actual->str());
		}
		TEST_METHOD(TestInvalidCommand)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			Location l(1, 1);
			Direction d(Direction::Facing::north);
			r->place(table, l, d);
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("REPOR\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
			}
			Assert::AreEqual(std::string(""), actual->str());
		}

		TEST_METHOD(TestValidPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE 1, 1, NORTH\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string("1,1,NORTH\n"), actual->str());
		}

		TEST_METHOD(TestInvalidPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE a,1,NORTH\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string(""), actual->str());
		}

		TEST_METHOD(TestOutofBoundsPlace)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE -1,1,NORTH\n"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			if (cmd != nullptr)
			{
				cmd->action();
				reporter->report();
			}
			Assert::AreEqual(std::string(""), actual->str());
		}

		/*
		 * PLACE 0,0,NORTH
		 * MOVE
		 * REPORT
		 * Output: 0,1,NORTH
		 */
		TEST_METHOD(TestExampleA)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE 0,0,NORTH\nMOVE\nREPORT"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			while (cmd != nullptr)
			{
				cmd->action();
				cmd = controller->nextCommand();
			}
			Assert::AreEqual(std::string("0,1,NORTH\n"), actual->str());
		}

		/*
		 * PLACE 0,0,NORTH
		 * LEFT
		 * REPORT
		 * Output: 0,0,WEST
		 */
		TEST_METHOD(TestExampleB)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE 0,0,NORTH\nLEFT\nREPORT"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			while (cmd != nullptr)
			{
				cmd->action();
				cmd = controller->nextCommand();
			}
			Assert::AreEqual(std::string("0,0,WEST\n"), actual->str());
		}

		/*
		 * PLACE 1,2,EAST
		 * MOVE
		 * MOVE
		 * LEFT
		 * MOVE
		 * REPORT
		 * Output: 3,3,NORTH
		*/
		TEST_METHOD(TestExampleC)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(r, actual));
			std::shared_ptr<std::istringstream> input(new std::istringstream("PLACE 1,2,EAST\nMOVE\nMOVE\nLEFT\nMOVE\nREPORT"));
			std::unique_ptr<StreamEntityController> controller(new StreamEntityController(r, reporter, table, input));
			std::shared_ptr<Command> cmd = controller->nextCommand();
			while (cmd != nullptr)
			{
				cmd->action();
				cmd = controller->nextCommand();
			}
			Assert::AreEqual(std::string("3,3,NORTH\n"), actual->str());
		}
	};
}

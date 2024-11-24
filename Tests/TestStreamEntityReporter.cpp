#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/StreamEntityReporter.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/TableTop.h"
#include <sstream>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestStreamEntityReporter
{
	TEST_CLASS(TestStreamEntityReporter)
	{
	public:

		TEST_METHOD(TestReportValidNorth)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(1, 2));
			bool placed = r->place(table, Location(0, 1), Direction(Direction::Facing::north));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			StreamEntityReporter reporter(r, actual);
			reporter.report();
			Assert::AreEqual(std::string("0,1,NORTH\n"), actual->str());
		}

		TEST_METHOD(TestReportValidSouth)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(3, 2));
			bool placed = r->place(table, Location(2, 1), Direction(Direction::Facing::south));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			StreamEntityReporter reporter(r, actual);
			reporter.report();
			Assert::AreEqual(std::string("2,1,SOUTH\n"), actual->str());
		}

		TEST_METHOD(TestReportValidEast)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 2));
			bool placed = r->place(table, Location(4, 0), Direction(Direction::Facing::east));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			StreamEntityReporter reporter(r, actual);
			reporter.report();
			Assert::AreEqual(std::string("4,0,EAST\n"), actual->str());
		}

		TEST_METHOD(TestReportValidWest)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<TableTop> table(new TableTop(5, 2));
			bool placed = r->place(table, Location(4, 0), Direction(Direction::Facing::west));
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			StreamEntityReporter reporter(r, actual);
			reporter.report();
			Assert::AreEqual(std::string("4,0,WEST\n"), actual->str());
		}

		TEST_METHOD(TestReportNotPlaced)
		{
			std::shared_ptr<Robot> r(new Robot());
			std::shared_ptr<std::stringstream> actual(new std::stringstream());
			StreamEntityReporter reporter(r, actual);
			reporter.report();
			Assert::AreEqual(std::string(""), actual->str());
		}
	};
}

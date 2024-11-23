#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Robot.h"
#include "../ToyRobot/TableTop.h"
#include "../ToyRobot/Direction.h"
#include "../ToyRobot/Location.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestRobot
{
	TEST_CLASS(TestRobot)
	{
	public:

		TEST_METHOD(TestPlaceRobot)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(1, 2));
			bool placed = r.place(table, Location(0, 1), Direction(Direction::Facing::north));
			Assert::AreEqual(placed, true);
			Direction::Facing f = r.getDirection().getDirection();
			Direction::Facing e = Direction::Facing::north;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f));
			Location robotLocation = r.getLocation();
			Assert::AreEqual(0, robotLocation.getXcoordinate());
			Assert::AreEqual(1, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestRotateLeft)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(1, 1));
			r.place(table, Location(0, 0), Direction(Direction::Facing::north));
			bool rotated = r.rotateLeft();
			Assert::AreEqual(true, rotated);
			Direction::Facing f = r.getDirection().getDirection();
			Direction::Facing e = Direction::Facing::west;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f));
		}

		TEST_METHOD(TestRotateRight)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(1, 1));
			r.place(table, Location(0, 0), Direction(Direction::Facing::north));
			bool rotated = r.rotateRight();
			Assert::AreEqual(true, rotated);
			Direction::Facing f = r.getDirection().getDirection();
			Direction::Facing e = Direction::Facing::east;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f));
		}

		TEST_METHOD(TestMoveNorth)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(1, 1), Direction(Direction::Facing::north));
			bool moved = r.move();
			Assert::AreEqual(true, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(1, robotLocation.getXcoordinate());
			Assert::AreEqual(2, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestMoveSouth)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(1, 1), Direction(Direction::Facing::south));
			bool moved = r.move();
			Assert::AreEqual(true, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(1, robotLocation.getXcoordinate());
			Assert::AreEqual(0, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestMoveEast)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(1, 1), Direction(Direction::Facing::east));
			bool moved = r.move();
			Assert::AreEqual(true, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(2, robotLocation.getXcoordinate());
			Assert::AreEqual(1, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestMoveWest)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(1, 1), Direction(Direction::Facing::west));
			bool moved = r.move();
			Assert::AreEqual(true, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(0, robotLocation.getXcoordinate());
			Assert::AreEqual(1, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestMoveInvalidWest)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(0, 2), Direction(Direction::Facing::west));
			bool moved = r.move();
			Assert::AreEqual(false, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(0, robotLocation.getXcoordinate());
			Assert::AreEqual(2, robotLocation.getYcoordinate());
		}
		
		TEST_METHOD(TestMoveInvalidEast)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(4, 3), Direction(Direction::Facing::east));
			bool moved = r.move();
			Assert::AreEqual(false, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(4, robotLocation.getXcoordinate());
			Assert::AreEqual(3, robotLocation.getYcoordinate());
		}
		
		TEST_METHOD(TestMoveInvalidNorth)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(2, 4), Direction(Direction::Facing::north));
			bool moved = r.move();
			Assert::AreEqual(false, moved);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(2, robotLocation.getXcoordinate());
			Assert::AreEqual(4, robotLocation.getYcoordinate());
		}

		TEST_METHOD(TestMoveInvalidSouth)
		{
			Robot r;
			std::shared_ptr<TableTop> table(new TableTop(5, 5));
			r.place(table, Location(4, 0), Direction(Direction::Facing::south));
			bool moved = r.move();
			Assert::AreEqual(moved, false);
			Location robotLocation = r.getLocation();
			Assert::AreEqual(4, robotLocation.getXcoordinate());
			Assert::AreEqual(0, robotLocation.getYcoordinate());
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDirection
{
	TEST_CLASS(TestDirection)
	{
	public:

		TEST_METHOD(TestLeftFromWest)
		{
			Direction f(Direction::Facing::west);
			f.turnLeft();
			Direction::Facing e = Direction::Facing::south;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestLeftFromNorth)
		{
			Direction f; // north is default
			f.turnLeft();
			Direction::Facing e = Direction::Facing::west;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestLeftFromEast)
		{
			Direction f(Direction::Facing::east);
			f.turnLeft();
			Direction::Facing e = Direction::Facing::north;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestLeftFromSouth)
		{
			Direction f(Direction::Facing::south);
			f.turnLeft();
			Direction::Facing e = Direction::Facing::east;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestLeft4Times)
		{
			Direction f(Direction::Facing::south);
			f.turnLeft();
			f.turnLeft();
			f.turnLeft();
			f.turnLeft();
			Direction::Facing e = Direction::Facing::south;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestRightFromWest)
		{
			Direction f(Direction::Facing::west);
			f.turnRight();
			Direction::Facing e = Direction::Facing::north;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestRightFromNorth)
		{
			Direction f; // north is default
			f.turnRight();
			Direction::Facing e = Direction::Facing::east;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestRightFromEast)
		{
			Direction f(Direction::Facing::east);
			f.turnRight();
			Direction::Facing e = Direction::Facing::south;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestRightFromSouth)
		{
			Direction f(Direction::Facing::south);
			f.turnRight();
			Direction::Facing e = Direction::Facing::west;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}

		TEST_METHOD(TestRight4Times)
		{
			Direction f(Direction::Facing::east);
			f.turnRight();
			f.turnRight();
			f.turnRight();
			f.turnRight();
			Direction::Facing e = Direction::Facing::east;
			Assert::AreEqual(static_cast<int>(e), static_cast<int>(f.getDirection()));
		}
	};
}

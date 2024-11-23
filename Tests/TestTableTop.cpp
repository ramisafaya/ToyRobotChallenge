#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/TableTop.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTableTop
{
	TEST_CLASS(TestTableTop)
	{
	public:

		TEST_METHOD(TestCanPlace)
		{
			TableTop table(5, 5);
			bool can = table.canPlace(Location(1, 2));
			Assert::AreEqual(can, true);
		}

		TEST_METHOD(TestCanPlaceAtEdge)
		{
			TableTop table(5, 5);
			bool can = table.canPlace(Location(4, 4));
			Assert::AreEqual(can, true);
		}

		TEST_METHOD(TestCannotPlacePositive)
		{
			TableTop table(5, 5);
			bool can = table.canPlace(Location(1, 6));
			Assert::AreEqual(can, false);
		}

		TEST_METHOD(TestCannotPlaceBoundary)
		{
			TableTop table(5, 5);
			bool can = table.canPlace(Location(1, 5));
			Assert::AreEqual(can, false);
		}

		TEST_METHOD(TestCannotPlaceNegative)
		{
			TableTop table(5, 5);
			bool can = table.canPlace(Location(-1, 3));
			Assert::AreEqual(can, false);
		}
	};
}

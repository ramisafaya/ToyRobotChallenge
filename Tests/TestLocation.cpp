#include "pch.h"
#include "CppUnitTest.h"
#include "../ToyRobot/Location.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLocation
{
	TEST_CLASS(TestLocation)
	{
	public:

		TEST_METHOD(TestLocationDefault)
		{
			Location l;
			Assert::AreEqual(0, l.getXcoordinate());
			Assert::AreEqual(0, l.getYcoordinate());
		}

		TEST_METHOD(TestLocationPositiveValues)
		{
			Location l(1,5);
			Assert::AreEqual(1, l.getXcoordinate());
			Assert::AreEqual(5, l.getYcoordinate());
		}

		TEST_METHOD(TestLocationNegativeValues)
		{
			Location l(1, -5);
			Assert::AreEqual(1, l.getXcoordinate());
			Assert::AreEqual(-5, l.getYcoordinate());
		}
	};
}

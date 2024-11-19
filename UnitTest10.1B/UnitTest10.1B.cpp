#include "pch.h"
#include "CppUnitTest.h"
#include "../laboratory10.1B/lab10.1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:

		TEST_METHOD(TestPhisicFine)
		{
			const int N = 3;
			Student students[N] = {
				{"Іваненко", 1, KN, 5, 4, {5}},
				{"Петренко", 2, INF, 4, 3, {4}},
				{"Сидоренко", 3, PH, 5, 5, {5}}
			};

	
			int result = PhisicFine(students, N);

			Assert::AreEqual(2, result);
		}
	};
}
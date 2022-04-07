#include "pch.h"
#include "CppUnitTest.h"
#include "../pkr_laba_3.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pkrUnitTest31a
{
	TEST_CLASS(pkrUnitTest31a)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "kvitka";
			s[0].kyrs = 2;
			s[0].specialty = ²Ò;
			s[0].physics = 5;
			s[0].math = 5;
			s[0].informatics = 5;

			int p = Percent(s, N);
			Assert::AreEqual(p, 100);
		}
	};
}

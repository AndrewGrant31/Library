#include "pch.h"
#include "CppUnitTest.h"

import TestStrings;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringsTests
{
	TEST_CLASS(StringsTests)
	{
	private:

		std::string result{};

		void Reset()
		{
			result.clear();
			TestStrings::testString.reset();
		}



	public:
		
		TEST_METHOD(EmptyStringPassedAndReturned)
		{
			Reset();
			result.assign(std::string{ "" });

			TestStrings::testString = 
				std::make_unique<Strings::StringType<std::string>>(std::string{ "" });

			Assert::AreEqual(result, TestStrings::testString->Get());
		}

		TEST_METHOD(HelloWorldPassedAndReturned)
		{
			std::string hello_{ "Hello World!" };
			std::string helloTest{ "Hello World!" };
			Reset();
			result.assign(hello_);

			TestStrings::testString =
				std::make_unique<Strings::StringType<std::string>>(helloTest);

			Assert::AreEqual(result, TestStrings::testString->Get());
		}
	};
}

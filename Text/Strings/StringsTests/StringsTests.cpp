#include "pch.h"
#include "CppUnitTest.h"

import TestStrings;
import ResultStrings;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringsTests
{
	TEST_CLASS ( StringsTests )
	{
	private:

	public:

		TEST_METHOD ( EmptyStringPassedAndReturned )
		{
			Assert::AreEqual ( 
				ResultStrings::EmptyStringResult ( ), 
				TestStrings::EmptyStringTest ( ) );
		}

		TEST_METHOD ( HelloWorldPassedAndReturned )
		{
			Assert::AreEqual ( 
				ResultStrings::HelloWorldStringResult ( ), TestStrings::HelloWorldStringTest() );
		}

		TEST_METHOD ( SymbolsPassedAndReturned )
		{
			Assert::AreEqual ( 
				ResultStrings::SymbolStringResult ( ), 
				TestStrings::SymbolStringTest() );
		}

		TEST_METHOD ( UsingObjectForString_Returns_HelloWorld )
		{
			Assert::AreEqual ( 
				ResultStrings::HelloWorldStringResult ( ),
				TestStrings::StringUsingObjectContainer ( ) );
		}
	};
}
export module TestStrings;

import String;
import std;

std::unique_ptr<String> testString;

namespace StringsForTesting
{
	const std::string empty { "" };
	const std::string helloWorld_ { "Hello World!" };
	const std::string x_is_greater_than_y { "x > y" };

	class Test
	{
	private:
		std::unique_ptr<String> testString;
	public:
		explicit Test ( const std::string& _ ) :
			testString { std::make_unique<String> ( _ ) }
		{

		}

		auto ToString ( ) noexcept -> const std::string
		{
			return testString->ToString ( );
		}
	};
}

export namespace TestStrings
{
	auto EmptyStringTest ( ) noexcept -> const std::string
	{
		testString.reset ( );
		testString = std::make_unique<String> ( StringsForTesting::empty );
		return testString->ToString ( );
	}

	auto HelloWorldStringTest ( ) noexcept -> const std::string
	{
		testString.reset ( );
		testString = std::make_unique<String> ( StringsForTesting::helloWorld_ );
		return testString->ToString ( );
	}

	auto SymbolStringTest ( ) noexcept -> const std::string
	{
		testString.reset ( );
		testString = std::make_unique<String> ( StringsForTesting::x_is_greater_than_y );
		return testString->ToString ( );
	}

	auto StringUsingObjectContainer ( ) noexcept -> const std::string
	{
		StringsForTesting::Test test ( StringsForTesting::helloWorld_ );
		return test.ToString ( );
	}
}
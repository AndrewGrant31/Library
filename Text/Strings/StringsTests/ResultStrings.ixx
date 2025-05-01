export module ResultStrings;

import std;

namespace ConstStringResult
{
	const std::string emptyString { "" };
	const std::string helloWorld { "Hello World!" };
	const std::string symbolStringResult { "x > y" };
}

export namespace ResultStrings
{
	auto EmptyStringResult ( ) noexcept -> const std::string
	{
		return ConstStringResult::emptyString;
	}

	auto HelloWorldStringResult ( ) noexcept -> const std::string
	{
		return ConstStringResult::helloWorld;
	}

	auto SymbolStringResult ( ) noexcept -> const std::string
	{
		return ConstStringResult::symbolStringResult;
	}
}
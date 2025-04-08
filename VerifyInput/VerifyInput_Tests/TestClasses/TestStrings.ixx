export module TestStrings;

import std;

export namespace TestStrings
{
	auto String(const std::optional<std::string>& _ = std::nullopt) 
		noexcept -> const std::string
	{
		return _.value_or(std::string{ "" });
	}
}
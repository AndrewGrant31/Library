export module Immutable;

export import std;

namespace ConstVariables
{
	const std::string exclamation_ { "!" };
	const std::string hello_ { "Hello " };
	const std::string world_ { "World!" };
}

export namespace Immutable
{
	auto Exclamation ( ) noexcept -> const std::string
	{
		return ConstVariables::exclamation_;
	}

	auto Hello ( ) noexcept -> decltype ( ConstVariables::hello_ )
	{
		return ConstVariables::hello_;
	}

	auto World ( ) noexcept -> auto
	{
		return ConstVariables::world_;
	}
}
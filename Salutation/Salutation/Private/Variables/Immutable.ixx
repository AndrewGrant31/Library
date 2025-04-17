export module Immutable;

export import std;

export namespace AG31::Variables
{
	class ImmutableVariables
	{
	private:
		std::string exclamation_ { "!" };
		std::string hello_ { "Hello " };
		std::string world_ { "World!" };

	public:
		explicit ImmutableVariables ( ) = default;

		auto Exclamation ( ) noexcept -> const std::string
		{
			return exclamation_;
		}

		auto Hello ( ) noexcept -> const std::string
		{
			return hello_;
		}

		auto World ( ) noexcept -> const std::string
		{
			return world_;
		}
	};
}
export module Immutable;

export import std;

export namespace AG31::Variables
{
	class ImmutableVariables
	{
	private:
		std::string hello_ { "Hello " };

	public:
		explicit ImmutableVariables ( ) = default;

		auto Hello ( ) noexcept -> const std::string
		{
			return hello_;
		}
	};
}
export module Single_Source_File;

import std;

export namespace Hello
{
	class HelloToWhom
	{
	private:
		const std::string exclamation_ { "!" };
		const std::string hello_ { "Hello " };
		const std::string world_ { "World!" };
		std::string who_;

		auto AddExclamation ( const std::string& _ ) noexcept -> const auto;

		auto Set ( const std::string& _ ) noexcept -> const auto;

		auto ConstructGreeting ( );

	public:
		explicit HelloToWhom ( const std::optional<std::string>& _ = std::nullopt );

		auto Greetings ( ) noexcept -> const std::string;
	};
}
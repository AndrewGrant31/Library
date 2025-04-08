export module Multiple_Files;

export import :Mutable;

export import std;

#pragma region Public Interface
export namespace Hello
{	
	class HelloToWhom
	{
	private:

		std::unique_ptr<Mutable::Value> who_;

		auto AddExclamation ( const std::string& _ ) 
			noexcept -> const std::string;

		auto Set ( const std::string& _ ) noexcept -> const std::string;

		auto ConstructGreetings ( ) noexcept -> const std::string;

	public:
		explicit HelloToWhom ( const std::optional<std::string>& _ = std::nullopt );

		auto Greetings ( ) noexcept -> const std::string;

	};
}
#pragma endregion Public Interface

#pragma region Private Partition
module : private;

import Immutable;

auto Hello::HelloToWhom::Greetings ( ) noexcept -> const std::string
{
	return ConstructGreetings ( );
}
#pragma endregion Private Partition
export module Private_Partition;

import std;

#pragma region Public Facing
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
		explicit HelloToWhom ( const std::optional<std::string>& _=
			std::nullopt );

		auto Greetings ( ) noexcept -> const std::string;
	};
}
#pragma endregion Public Facing

#pragma region Private Partition
module : private;

auto Hello::HelloToWhom::AddExclamation ( const std::string& _ ) noexcept -> const auto
{
	return _.ends_with ( exclamation_ ) ? _ : _ + exclamation_;
}

auto Hello::HelloToWhom::Set ( const std::string& _ ) noexcept -> const auto
{
	return _.empty ( ) ? world_ : AddExclamation ( _ );
}

auto Hello::HelloToWhom::ConstructGreeting ( )
{
	return hello_ + who_;
}

Hello::HelloToWhom::HelloToWhom ( const std::optional<std::string>& _  ) :
	who_ { Set ( _.value_or ( std::string{} ) ) }
{

}

auto Hello::HelloToWhom::Greetings ( ) noexcept -> const std::string
{
	return ConstructGreeting ( );
}
#pragma endregion Private Partition
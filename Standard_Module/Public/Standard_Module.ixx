export module Standard_Module;

export import std;

export namespace Hello
{	
	class HelloToWhom
	{
	private:
		const std::string exclamation_ { "!" };
		const std::string hello_ { "Hello " };
		const std::string world_ { "World!" };
		std::string who_;

		auto AddExclamation ( const std::string& _ ) noexcept -> const auto
		{
			return _.ends_with ( exclamation_ ) ? _ : _ + exclamation_;
		}
		auto Set ( const std::string& _ ) noexcept -> const auto
		{
			return _.empty ( ) ? world_ : AddExclamation ( _ );
		}
		auto ConstructGreeting ( )
		{
			return hello_ + who_;
		}

	public:
		explicit HelloToWhom ( const std::optional<std::string>& _ = 
			std::nullopt ) :
			who_ { Set ( _.value_or ( std::string{} ) ) }
		{

		}

		auto Greetings ( ) noexcept -> const std::string
		{
			return ConstructGreeting ( );
		}
	};
}
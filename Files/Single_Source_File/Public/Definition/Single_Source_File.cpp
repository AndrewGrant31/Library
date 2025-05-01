module Single_Source_File;

import std;

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

Hello::HelloToWhom::HelloToWhom ( const std::optional<std::string>& _ ) :
	who_ { Set ( _.value_or ( std::string{} ) ) }
{

}

auto Hello::HelloToWhom::Greetings ( ) noexcept -> const std::string
{
	return ConstructGreeting ( );
}
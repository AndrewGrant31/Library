export module VerifyInput;

import :Acceptable;
export import std;

export namespace VerifyInput
{
	/// <summary>
	/// Checks the given input against a set of predefined characteristics
	/// </summary>
	class Validate
	{
	private:
		std::string value_ {};

		/// <summary>
		/// Validates the acceptability of the input character
		/// </summary>
		/// <param name="_">datatype const char</param>
		/// <returns>true if acceptable, otherwise false</returns>
		auto Validator ( const char& _ ) noexcept -> const bool;

		/// <summary>
		/// Verifies the input string
		/// </summary>
		/// <param name="_">datatype is const std::string</param>
		/// <returns>The input string if good, otherwise returns an empty string </returns>
		auto Set ( const std::string& _ ) noexcept -> const std::string;

	public:
		/// <summary>
		/// Constructor for the validation process
		/// </summary>
		/// <param name="_">is of datatype std::string</param>
		explicit Validate ( const std::string& _ ) :
			value_ { Set ( _ ) }
		{

		}

		/// <summary>
		/// Returns the value of the internal data store (value_)
		/// </summary>
		/// <returns>Returns the std::string value_</returns>
		auto ToString ( ) noexcept -> const decltype( value_ );
	};
}

module : private;

std::optional<char> previous_ {};

std::unique_ptr<VerifyInput::List> list_uptr { 
	std::make_unique<VerifyInput::List> ( ) };

auto VerifyInput::Validate::Validator ( const char& _ )
noexcept -> const bool
{
	switch ( std::isalpha ( _ ) )
	{
	case true:
		if ( previous_.has_value ( ) )
			previous_.reset ( );
		break;
	case false:
		switch ( list_uptr->Contains ( _ ) )
		{
		case true:
			switch ( previous_.has_value ( ) )
			{
			case true:
				return list_uptr->IsAcceptable ( previous_.value ( ), _ );
			default:
				previous_.reset ( );
				previous_.emplace ( _ );
			}
			break;
		case false:
			return false;
			break;
		}
		break;
	}

	return true;
}

auto VerifyInput::Validate::Set ( const std::string& _ ) noexcept -> const std::string
{
	for ( auto& c : _ )
	{
		if ( not Validator ( c ) )
		{
			return std::string {};
		}
	}
	return _;
}

auto VerifyInput::Validate::ToString ( ) 
	noexcept -> const decltype( value_ )
{
	return value_;
}
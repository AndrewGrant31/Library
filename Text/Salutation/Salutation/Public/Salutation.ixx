export module Salutation;

import Immutable;
export import std;

export namespace Salutation
{
	class Message
	{
	private:
		std::unique_ptr<AG31::Variables::ImmutableVariables> variables { 
			std::make_unique< AG31::Variables::ImmutableVariables> ( ) };

		std::string value_ {};

		auto Set ( const std::string& _ )
		{
			return _;
		}

	public:
		explicit Message ( ) = default;
		/*explicit Message (
			const std::same_as<std::string> auto& _ ) :
			value_ { Set ( _ ) }
		{

		}*/

		/// <summary>
		/// Returns the relevant salutation
		/// </summary>
		/// <returns>const std::string</returns>
		auto Get ( ) noexcept -> const std::string
		{
			return variables->Hello ( );
			//return value_;
		}

	};
}
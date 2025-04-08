export module Multiple_Files:Mutable;

export import std;

export namespace Mutable
{
	class Value
	{
	private:
		std::string value_ {};

		auto Set ( auto& _ ) -> auto
		{
			return _;
		}

	public:
		explicit Value ( const std::string& _ ) :
			value_ { _ }
		{

		}

		auto Get ( ) noexcept -> const std::string
		{
			return value_;
		}

	};
}
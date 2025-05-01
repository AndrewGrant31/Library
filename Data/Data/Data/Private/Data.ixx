export module Data;

export import std;

export namespace Data
{
	template <typename T>
	class Value
	{
	private:
		T value_ {};

		auto Set ( const T& _ ) noexcept -> const T
		{
			return _;
		}

	public:
		explicit Value ( const T& _ ) :
			value_ { Set ( _ ) }
		{

		}

		auto Get ( ) noexcept -> const T
		{
			return value_;
		}

		auto ToString ( ) noexcept -> const std::string
		{
			if constexpr ( std::same_as<T, std::string> )
				return value_;
			else if constexpr ( std::convertible_to<T, std::string> )
				return std::to_string ( value_ );

			return std::string {};
		}
	};
} // namespace TValue

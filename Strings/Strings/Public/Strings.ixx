export module String:Strings;

export import std;
// public facing and declarations
export namespace Strings
{	
	/// <summary>
	/// Creates a string datatype 
	/// </summary>
	/// <typeparam name="T">Has to be either a std::string or a datatype easily convertible to std::string</typeparam>
	template <typename T> requires
		std::same_as<T, std::string> or
		std::convertible_to<T, std::string>
	class StringType
	{
	private:
		std::string value_{};

		auto Set ( const auto _ )
		{
			if constexpr ( std::same_as<T, std::string> )
				return _;
			else if constexpr ( std::convertible_to<T, std::string> )
				return std::to_string ( std::remove_cvref_t<decltype(_)>(_) );

			return std::string { "" };
		}

	public:
		/// <summary>
		/// Constructor, accepts T (std::string) or a data type easily convertible to std::string
		/// </summary>
		/// <example>
		/// <code>
		/// explicit [Strings::]StringType<std::string> Text text=[Strings::]StringType<std::string>( input );
		/// </code>
		/// </example>
		/// <param name="_">optional of type T</param>
		explicit StringType(const std::optional<T>& _ = std::nullopt) :
			value_{ Set(_.value_or(std::string{""}))}
		{

		}

		/// <summary>
		///  Returns contents of object
		/// </summary>
		/// <returns>datatype of stored object</returns>
		auto Get() noexcept -> const decltype(value_)
		{
			return std::move(value_);
		}

		/// <summary>
		/// Returns contents of object as std::string
		/// </summary>
		/// <returns>internal value as a std::string</returns>
		auto ToString() noexcept -> const std::string
		{
			return value_;
		}
	};
}
export module Text;

import std;

export namespace Text
{
	template <typename T>
	class Library
	{
	private:
		T value_ {};

	public:
		explicit Library ( const T& _ ) :
			value_ { _ }
		{

		}

		auto Get ( ) noexcept -> const T
		{
			return value_;
		}
	};
}
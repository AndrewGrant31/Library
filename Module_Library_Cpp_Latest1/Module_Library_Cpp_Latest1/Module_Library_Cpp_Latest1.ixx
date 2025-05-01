export module Module_Library_Cpp_Latest1;

import Data;

import std;

export namespace Module_Library_Cpp_Latest1
{
	template <typename T>
	class TModule_Library_Cpp_Latest1
	{
	private:
		std::unique_ptr<TData::Value<T>> value_;

		auto Set( const T& _ ) noexcept -> const T
		{
			return _;
		}

	public:
		explicit TModule_Library_Cpp_Latest1 ( const T& _ ) :
			value_ { std::make_unique<TData::Value<T>>(Set( _ )) }
		{

		}

		auto Get ( ) noexcept -> const T
		{
			return value_->Get();
		}

		auto ToString() noexcept -> const std::string
		{
			return value_->ToString();
		}
	};
}
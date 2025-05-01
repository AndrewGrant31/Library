export module DataStore;

import Data;

import std;

export namespace DataStore
{
	template <typename T>
	class Container
	{
	private:
		std::unique_ptr<Data::Value<T>> value_;

		auto Set( const T& _ ) noexcept -> const T
		{
			return _;
		}

	public:
		explicit Container ( const T& _ ) :
			value_ { std::make_unique<Data::Value<T>>(Set( _ )) }
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
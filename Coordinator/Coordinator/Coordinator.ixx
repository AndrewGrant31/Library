export module Coordinator;

import Data;

import std;

export namespace Coordinator
{
	template <typename T>
	class TCoordinator
	{
	private:
		std::unique_ptr<TData::Value<T>> value_;

		auto Set( const T& _ ) noexcept -> const T
		{
			return _;
		}

	public:
		explicit TCoordinator ( const auto& _ ) :
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
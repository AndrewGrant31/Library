module Multiple_Files;

import Immutable;
import :Mutable;

import std;

auto Hello::HelloToWhom::AddExclamation ( const std::string& _ ) 
	noexcept -> const std::string
{
	return _.ends_with ( Immutable::Exclamation ( ) ) ?
		 _ :
		 _ + Immutable::Exclamation ( ) ;
}
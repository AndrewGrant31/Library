module Multiple_Files;

import Immutable;
import :Mutable;

import std;

auto Hello::HelloToWhom::Set ( const std::string& _ ) 
noexcept -> const std::string
{
	return _.empty ( ) ? Immutable::World ( ) : AddExclamation ( _ );
}
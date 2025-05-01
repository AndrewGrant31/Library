module Multiple_Files;

import Immutable;
import :Mutable;
import std;

auto Hello::HelloToWhom::ConstructGreetings ( ) 
noexcept -> const std::string
{
	return Immutable::Hello ( ) + who_->Get ( );
}
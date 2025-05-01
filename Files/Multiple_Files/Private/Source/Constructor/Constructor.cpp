module Multiple_Files;

import :Mutable;
import std;

Hello::HelloToWhom::HelloToWhom ( const std::optional<std::string>& _ ) :
	who_ { std::make_unique<Mutable::Value> ( 
		Set ( _.value_or ( std::string{} ) ) ) }
{

}
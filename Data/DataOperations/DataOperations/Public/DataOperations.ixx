export module DataOperations;

export import :Text;

export namespace DataOperations
{	
	/// <summary>
	/// Create a text message from multiple sources
	/// </summary>
	/// <param name="...args">Inputs have to be of the same datatype</param>
	/// <example>
	/// <code>
	/// std::string string1{"message"};
	/// std::string string2{"message"};
	/// 
	/// auto message{DataOperations::Message(
	///		string1, string2, otherNamespace::Message());
	/// </code>
	/// </example>
	/// <returns>The desired message</returns>
	auto Message(auto ...args)
	{
		return Data::Operations::Text::Join(args...);
	}
}
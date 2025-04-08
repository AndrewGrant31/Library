export module DataOperations:Text;

export import std;

export namespace Data::Operations::Text
{
	/// <summary>
	/// Joins the input into a single string output
	/// </summary>
	/// <param name="...args">inputs have to be of the same datatype</param>
	/// <returns>the concatenated input strings</returns>
	auto Join(auto ...args)
	{
		return (... + args);
	}
}
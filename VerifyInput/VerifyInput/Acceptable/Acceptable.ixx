export module VerifyInput:Acceptable;

export import std;

export namespace VerifyInput
{
	/// <summary>
	/// Creates a list of the characters allowed in an input string
	/// </summary>
	
	/// @brief Creates a list of characters allowed or acceptable within an input string
	class List
	{
	private:
		char apostrophe_{ '\'' };
		char hyphen_{ '-' };
		char period_{ '.' };
		char space_{ ' ' };

		std::list<char> list_
		{
			apostrophe_,
			hyphen_,
			period_,
			space_
		};

	public:
		List() = default;

		/// <summary>
		/// Checks if the passed in character is in the list of acceptable characters
		/// </summary>
		/// <param name="_">Character for checking. Should be a [const] char</param>
		/// <returns>Returns true if acceptable, otherwise false</returns>
		auto Contains(auto& _)
		{
			return std::find(list_.begin(),
				list_.end(),
				_ ) != list_.end();
		}

		/// <summary>
		/// Checks to see if two acceptable characters 
		/// next to each other is okay or not
		/// </summary>
		/// <param name="first_">Should be of type [const] char. 
		/// Let the compiler decide...</param>
		/// <param name="second_">Should be of type [const] char.
		/// Let the compiler decide...</param>
		/// <returns>Returns true if acceptable, otherwise false</returns>
		/// <example>How to use
		/// <code>
		/// if(IsAcceptable(previous.value(), current))
		/// </code>
		/// </example>
		auto IsAcceptable(auto& first_, auto second_)
		{
			return first_ == period_ and second_ == space_;
		}
	};
}
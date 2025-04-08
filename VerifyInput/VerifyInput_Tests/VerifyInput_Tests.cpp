#include "CppUnitTest.h"

import VerifyInput;
import VerifyInput_Init;
import TestStrings;
import std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerifyInputTests
{

	TEST_CLASS(VerifyInputTests)
	{
	private:
		std::string out_{};
		std::string in_{};
		std::unique_ptr<VerifyInput::Validate> validate_;



		void Reset()
		{
			out_.clear();
			in_.clear();
			validate_.reset();
		}
	 
	void Set(const std::string& out__,
		const std::string& in__)
	{
		out_.assign(out__);
		in_.assign(in__);
		validate_ = std::make_unique<VerifyInput::Validate>(in_);
	}

	void Combined(const std::string& out_, const std::string& in_)
	{
		Reset();
		Set(out_, in_);
	}

public:

	TEST_METHOD(VerifyInput_EmptyStrings)
	{
		auto tstr{ TestStrings::String("") };
		Test_VerifyInput::Test_Validation test{ "" };

		Assert::AreEqual(tstr, test.Result());
	}

	TEST_METHOD(VerifyInput_ValidInputAllCharacters)
	{
		auto tstr{ TestStrings::String("YouTubers") };
		Test_VerifyInput::Test_Validation test{ "YouTubers" };

		Assert::AreEqual(tstr, test.Result());
	}

	TEST_METHOD(VerifyInput_InvalidInput)
	{
		auto tstr{ TestStrings::String("") };
		Test_VerifyInput::Test_Validation test{ "123" };

		Assert::AreEqual(tstr, test.Result());

	}

	TEST_METHOD(VerifyInput_ValidInputWithPeriodAndSpace)
	{
		auto tstr{ TestStrings::String("Mr. B. Lara") };
		Test_VerifyInput::Test_Validation test{ "Mr. B. Lara" };

		Assert::AreEqual(tstr, test.Result());
	}

	TEST_METHOD(VerifyInput_ValidInputWithHyphenatedName)
	{
		auto tstr{ TestStrings::String("Ms. C. Zeta-Jones") };
		Test_VerifyInput::Test_Validation test{ "Ms. C. Zeta-Jones" };

		Assert::AreEqual(tstr, test.Result());
	}



};
}

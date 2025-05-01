export module VerifyInput_Init;

import VerifyInput;
import std;

export namespace Test_VerifyInput
{
	class Test_Validation
	{
	private:
		std::unique_ptr<VerifyInput::Validate> vfv_;
		std::string value_{};

		auto Set(const std::string& _) noexcept -> const std::string
		{
			if (_.empty())
				return std::string{ "" };

			return _;
		}

	public:
		explicit Test_Validation(const std::string& _) :
			vfv_{ std::make_unique<VerifyInput::Validate>(_) }
		{

		}

		auto Result() noexcept -> const std::string
		{
			return vfv_->ToString();
		}


	};
}
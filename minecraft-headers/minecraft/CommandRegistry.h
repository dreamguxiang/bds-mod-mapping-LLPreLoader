#pragma once

class CommandRegistry{
public:
	class Symbol{
	public:
		int val;


		Symbol(int value) : val(value) {}

		MCAPI Symbol(unsigned __int64 = -1);
		MCAPI Symbol(class Symbol const&);
		MCAPI unsigned __int64 toIndex() const;
		MCAPI int value() const;
		inline bool operator==(Symbol const& right) const {
			return val == right.val;
		}
	};

	MCAPI std::string describe(class CommandRegistry::Symbol) const;
	MCAPI std::string symbolToString(class CommandRegistry::Symbol) const;
	MCAPI bool isValid(class CommandRegistry::Symbol) const;

};

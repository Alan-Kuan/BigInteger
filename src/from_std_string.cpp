#include "big_integer.hpp"

namespace {

	inline bool isWhiteSpace(char ch){ return ch == ' ' || ch == '\t' || ch == '\n'; }

	inline bool isDigit(char ch){ return ch >= '0' && ch <= '9'; }

};

void BigInteger::fromStdString(string s)
{
	num_literal.clear();

	// whether meet the first non-whitespace character
	bool meet_nonspace = false;

	for(int i = 0; i < s.length(); i++){

		if(!meet_nonspace){

			if(isWhiteSpace(s[i]))
				continue;

			// If it's the first time to meet the first non-whitespace character,
			// we should check whether it starts with a sign character or any digit.
			meet_nonspace = true;

			if(s[i] == '+')
				continue;
			else if(s[i] == '-')
				is_negative = true;
			else if(isDigit(s[i]))
				num_literal.push_back(s[i]);
			else{
				num_literal.push_back(0);
				break;
			}

		}else{

			// If we meet another non-whitespace character again,
			// we just ignore those characters behind.
			if(!isDigit(s[i]))
				break;

			num_literal.push_back(s[i]);

		}

	}

}

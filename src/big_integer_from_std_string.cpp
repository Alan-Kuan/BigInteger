#include "big_integer.hpp"

BigInteger BigInteger::fromStdString(string s)
{
	int len = s.length();

	// TODO: make this function work as BigInteger version atoi

	if(s[0] == '-'){

		is_negative = true;

		num_literal.resize(len - 1);

	}else{

		is_negative = false;

		num_literal.resize(len);

	}

	for(int i = 0; i < len; i++)
		num_literal[i] = s[len - i - 1];
	
	return *this;
}

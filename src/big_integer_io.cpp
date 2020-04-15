
#include "big_integer.hpp"

istream& operator>>(istream& is, BigInteger& n)
{
	string s;

	is >> s;

	int len = s.length();

	if(s[0] == '-'){

		n.is_negative = true;

		n.num_literal.resize(len - 1);

	}else{

		n.is_negative = false;

		n.num_literal.resize(len);

	}

	for(int i = 0; i < len; i++)
		n.num_literal[i] = s[len - i - 1];
	
	return is;
}

ostream& operator<<(ostream& os, const BigInteger& n)
{
	if(n.is_negative)
		os << '-';

	for(int i = n.num_literal.size(); i >= 0; i--)
		os << n.num_literal[i];

	return os;
}

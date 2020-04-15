
#include "big_integer.hpp"

istream& operator>>(istream& is, BigInteger& n)
{
	string s;

	is >> s;

	n = s;

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

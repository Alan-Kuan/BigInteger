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
	if(n.is_negative && n.num_literal[0] != '0')
		os << '-';

	for(size_t i = n.num_literal.size() - 1; i < n.num_literal.size(); i--)
		os << n.num_literal[i];

	return os;
}

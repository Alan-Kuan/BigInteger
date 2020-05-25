#include "big_integer.hpp"

BigInteger::BigInteger(void)
{
	is_negative = false;
	num_literal.push_back('0');
}

BigInteger::BigInteger(const BigInteger& n)
{
	*this = n;
}

BigInteger::BigInteger(int n)
{
	*this = n;
}

BigInteger::BigInteger(string s)
{
	*this = s;
}

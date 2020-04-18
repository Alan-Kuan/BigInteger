#include "big_integer.hpp"

BigInteger& BigInteger::operator++(void)
{
	*this += 1;
	return *this;
}

BigInteger BigInteger::operator++(int _)
{
	BigInteger tmp(*this);
	*this += 1;
	return tmp;
}

BigInteger& BigInteger::operator--(void)
{
	*this -= 1;
	return *this;
}

BigInteger BigInteger::operator--(int _)
{
	BigInteger tmp(*this);
	*this -= 1;
	return tmp;
}

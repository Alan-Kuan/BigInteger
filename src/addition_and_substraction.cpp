#include "big_integer.hpp"

// unary minus
BigInteger BigInteger::operator-(void)
{
	is_negative = !is_negative;

	return *this;
}

BigInteger BigInteger::operator+(BigInteger b)
{
	if(is_negative && !b.is_negative)
		return b - (-(*this));
	if(!is_negative && b.is_negative)
		return *this - (-b);

	// if both this and b are positive or negative
	// it is okay to use the plus function
	return plus(b);
}

BigInteger BigInteger::operator+(int b)
{
	BigInteger tmp(b);

	return *this + tmp;
}

BigInteger BigInteger::operator-(BigInteger b)
{
	// either this is negative or b is negative
	// but not both
	if(!is_negative != !b.is_negative)
		return *this + (-b);	

	return minus(b);
}

BigInteger BigInteger::operator-(int b)
{
	BigInteger tmp(b);

	return *this - tmp;
}

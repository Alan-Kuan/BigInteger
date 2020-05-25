#include "big_integer.hpp"

BigInteger BigInteger::operator+(const BigInteger& b) const
{
	if(is_negative && !b.is_negative)
		return b - (-(*this));
	if(!is_negative && b.is_negative)
		return *this - (-b);

	// if both this and b are positive or negative
	// it is okay to use the plus function
	return plus(b);
}

BigInteger BigInteger::operator+(int b) const
{
	BigInteger tmp(b);

	return *this + tmp;
}

BigInteger BigInteger::operator-(const BigInteger& b) const
{
	// either this is negative or b is negative
	// but not both
	if(!is_negative != !b.is_negative)
		return *this + (-b);

	return minus(b);
}

BigInteger BigInteger::operator-(int b) const
{
	BigInteger tmp(b);

	return *this - tmp;
}

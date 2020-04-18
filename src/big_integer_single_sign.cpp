#include "big_integer.hpp"

// unary minus
BigInteger BigInteger::operator-(void)
{
	is_negative = !is_negative;

	return *this;
}

BigInteger BigInteger::operator+(BigInteger b)
{


}

BigInteger BigInteger::operator+(int b)
{
	BigInteger tmp(b);

	return *this + tmp;
}

BigInteger BigInteger::operator-(BigInteger b)
{

	if(b.is_negative)


}

BigInteger BigInteger::operator-(int b)
{
	BigInteger tmp(b);

	return *this - tmp;
}

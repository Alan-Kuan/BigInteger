#include "big_integer.hpp"

// unary plus
BigInteger BigInteger::operator+(void) const
{
	return *this;
}

// unary minus
BigInteger BigInteger::operator-(void) const
{
    BigInteger tmp(*this);

    if(tmp != 0)
        tmp.is_negative = !is_negative;

	return tmp;
}

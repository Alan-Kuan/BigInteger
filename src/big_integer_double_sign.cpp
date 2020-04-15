#include "big_integer.hpp"

BigInteger& BigInteger::operator++(void)
{
	*this += 1;
	return *this;
}

BigInteger BigInteger::operator++(int _)
{
	return *this + 1;
}

BigInteger& BigInteger::operator--(void)
{

}

BigInteger BigInteger::operator--(int _)
{
	return *this - 1;
}

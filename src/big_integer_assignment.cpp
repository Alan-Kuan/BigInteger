#include "big_integer.hpp"

// make this function can only be access in this file
namespace {

	inline int ABS(int n){ return n < 0 ? -n : n; }

}

BigInteger& BigInteger::operator=(BigInteger n)
{
	is_negative = n.is_negative;
	num_literal = n.num_literal;

	return *this;
}

BigInteger& BigInteger::operator=(int n)
{
	is_negative = n < 0;

	n = ABS(n);

	while(n > 0){

		num_literal.push_back(n % 10);

		n /= 10;

	}

	return *this;
}

BigInteger& BigInteger::operator=(string s)
{
	*this = fromStdString(s);
	return *this;
}

BigInteger& BigInteger::operator+=(BigInteger b)
{
	*this = *this + b;
	return *this;
}

BigInteger& BigInteger::operator+=(int b)
{
	*this = *this + b;
	return *this;
}

BigInteger& BigInteger::operator-=(BigInteger b)
{
	*this = *this - b;
	return *this;
}

BigInteger& BigInteger::operator-=(int b)
{
	*this = *this - b;
	return *this;
}

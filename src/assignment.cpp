#include "big_integer.hpp"

// make this function can only be access in this file
namespace {

	inline int ABS(int n){ return n < 0 ? -n : n; }

}

BigInteger& BigInteger::operator=(const BigInteger& n)
{
	is_negative = n.is_negative;
	num_literal = n.num_literal;

	return *this;
}

BigInteger& BigInteger::operator=(int n)
{
    if(n == 0){

        num_literal.push_back('0');

        is_negative = false;

        return *this;

    }

	num_literal.clear();

	is_negative = n < 0;

	n = ABS(n);

	while(n > 0){

		num_literal.push_back(n%10 + '0');

		n /= 10;

	}

	return *this;
}

BigInteger& BigInteger::operator=(const string& s)
{
	fromStdString(s);
	return *this;
}

BigInteger& BigInteger::operator+=(const BigInteger& b)
{
	*this = *this + b;
	return *this;
}

BigInteger& BigInteger::operator+=(int b)
{
	*this = *this + b;
	return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& b)
{
	*this = *this - b;
	return *this;
}

BigInteger& BigInteger::operator-=(int b)
{
	*this = *this - b;
	return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& b)
{
	*this = *this * b;
	return *this;
}

BigInteger& BigInteger::operator*=(int b)
{
	*this = *this * b;
	return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& b)
{
	*this = *this / b;
	return *this;
}

BigInteger& BigInteger::operator/=(int b)
{
	*this = *this / b;
	return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger& b)
{
	*this = *this % b;
	return *this;
}

BigInteger& BigInteger::operator%=(int b)
{
	*this = *this % b;
	return *this;
}

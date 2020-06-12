#include "big_integer.hpp"

BigInteger BigInteger::operator*(const BigInteger& b) const
{
    BigInteger res;

    return times(b);
}

BigInteger BigInteger::operator*(int b) const
{
    BigInteger tmp(b);

    return *this * tmp;
}

BigInteger BigInteger::operator/(const BigInteger& b) const
{
    if(b == 0)
        throw(string("divided by zero!"));

    BigInteger res = divides(b).first;

    // res is negative when *this is negative xor b is negative
    res.is_negative = !is_negative != !b.is_negative;

    return res;
}

BigInteger BigInteger::operator/(int b) const
{
    BigInteger tmp(b);

    return *this / tmp;
}

BigInteger BigInteger::operator%(const BigInteger& b) const
{
    if(b == 0)
        throw(string("divided by zero!"));

    BigInteger res = divides(b).second;

    // res is negative when *this is negative
    res.is_negative = is_negative;

    return res;
}

BigInteger BigInteger::operator%(int b) const
{
    BigInteger tmp(b);

    return *this % tmp;
}

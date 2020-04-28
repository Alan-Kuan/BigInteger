#include "big_integer.hpp"


bool BigInteger::operator==(const BigInteger& b) const
{
    if(is_negative != b.is_negative)
        return false;

    if(num_literal.size() != b.num_literal.size())
        return false;

    for(size_t i = 0; i < num_literal.size(); i++)
        if(num_literal[i] != b.num_literal[i])
            return false;

    return true;
}

bool BigInteger::operator==(int b) const
{
    BigInteger tmp(b);
    return *this == tmp;
}

bool BigInteger::operator!=(const BigInteger& b) const
{
    return !(*this == b);
}

bool BigInteger::operator!=(int b) const
{
    BigInteger tmp(b);
    return !(*this == tmp);
}

bool BigInteger::operator>(const BigInteger& b) const
{
    if(!is_negative && b.is_negative)
        return true;
    if(is_negative && !b.is_negative)
        return false;

    // if len1 > len2 and both numbers are negative, num1 is not greater
    // if len1 > len2 and both numbers are positive, num1 is greater
    if(num_literal.size() > b.num_literal.size())
        return !is_negative;

    // wheter |num1| > |num2|
    bool abs_val_is_greater = false;

    for(size_t i = num_literal.size() - 1; i >= 0; i--){

        if(num_literal[i] > b.num_literal[i]){

            abs_val_is_greater = true;

            break;

        }

    }

    // this is abs_is_greater XOR is_negative
    // if |num1| > |num2| and num1 >= 0, num1 is greater
    // if |num1| > |num2| and num1 < 0, num1 is not greater
    return (!abs_val_is_greater != !is_negative);
}

bool BigInteger::operator>(int b) const
{
    BigInteger tmp(b);
    return *this > tmp;
}

bool BigInteger::operator<(const BigInteger& b) const
{
    return b > *this;
}

bool BigInteger::operator<(int b) const
{
    BigInteger tmp(b);
    return tmp > *this;
}

bool BigInteger::operator>=(const BigInteger& b) const
{
    return *this > b || *this == b;
}

bool BigInteger::operator>=(int b) const
{
    BigInteger tmp(b);
    return *this > tmp || *this == tmp;
}

bool BigInteger::operator<=(const BigInteger& b) const
{
    return b > *this || *this == b;
}

bool BigInteger::operator<=(int b) const
{
    BigInteger tmp(b);
    return tmp > *this || *this == tmp;
}

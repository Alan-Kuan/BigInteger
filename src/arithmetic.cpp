#include "big_integer.hpp"

// make this function can only be access in this file
namespace {

	inline int MAX(int a, int b){ return a > b ? a : b; }

    const Digit DIGIT_10 = '0' + 10;

}

BigInteger BigInteger::plus(const BigInteger& b) const
{
	BigInteger res;

	size_t len1 = num_literal.size();
	size_t len2 = b.num_literal.size();

	size_t max_len = MAX(len1, len2);

	res.num_literal.resize(max_len);

    res.is_negative = is_negative;

	int carry = 0;

	for(size_t i = 0; i < max_len; i++){

		if(i >= len1 && i < len2)
			res.num_literal[i] = b.num_literal[i] + carry;
		else if(i < len1 && i >= len2)
			res.num_literal[i] = num_literal[i] + carry;
		else
			res.num_literal[i] = num_literal[i] + b.num_literal[i] + carry - '0';
            // == (num_literal[i]-'0' + b.num_literal[i]-'0' + carry) + '0'

		if(res.num_literal[i] >= DIGIT_10){

			res.num_literal[i] -= 10;

			carry = 1;

		}else
			carry = 0;

	}

	if(carry == 1)
		res.num_literal.push_back('1');

	return res;
}

BigInteger BigInteger::minus(const BigInteger& b) const
{
    BigInteger res;

    size_t len1 = num_literal.size();
    size_t len2 = b.num_literal.size();

    size_t max_len = MAX(len1, len2);

    res.num_literal.resize(max_len);

    if(*this >= b){

        int borrow = 0;

        for(size_t i = 0; i < len1; i++){

            if(i >= len2)
                res.num_literal[i] = num_literal[i] - borrow;
            else
                res.num_literal[i] = num_literal[i] - b.num_literal[i] - borrow + '0';
                // == (num_literal[i]-'0' - (b.num_literal[i]-'0') - borrow) + '0'

            if(res.num_literal[i] < '0'){

                res.num_literal[i] += 10;

                borrow = 1;

            }else
                borrow = 0;

        }

    }else{

        res.is_negative = true;

        Digit borrow = 0;

        for(size_t i = 0; i < len2; i++){

            if(i >= len1)
                res.num_literal[i] = b.num_literal[i] - borrow;
            else
                res.num_literal[i] = b.num_literal[i] - num_literal[i] - borrow + '0';
                // == (num_literal[i]-'0' - (b.num_literal[i]-'0') - borrow) + '0'

            if(res.num_literal[i] < '0'){

                res.num_literal[i] += 10;

                borrow = 1;

            }else
                borrow = 0;

        }

    }

    for(size_t i = max_len - 1; i < max_len; i--){

        if(res.num_literal[i] == '0' && i != 0)
            res.num_literal.pop_back();
        else
            break;

    }

    return res;
}

BigInteger BigInteger::times(const BigInteger& b) const
{
    BigInteger res;

    for(size_t i = 0; i < b.num_literal.size(); i++){

        if(b.num_literal[i] == '0')
            continue;

        BigInteger tmp;

        tmp.num_literal.clear();

        tmp.num_literal.assign(i, '0');

        int carry = 0;

        for(size_t j = 0; j < num_literal.size(); j++){

            int mul = (num_literal[j] - '0') * (b.num_literal[i] - '0') + carry;

            carry = mul / 10;

            mul %= 10;

            tmp.num_literal.push_back(mul + '0');

        }

        if(carry > 0)
            tmp.num_literal.push_back(carry + '0');
    
        res += tmp;

    }

    // result is negative iff either this is negative or b is negative, but not both
    res.is_negative = !is_negative != !b.is_negative;

    return res;
}

// division of two nonnegative value
pair<BigInteger, BigInteger> BigInteger::divides(const BigInteger& b) const
{
    BigInteger quotient, remainder(*this), divisor(b);

    quotient.num_literal.clear();

    // we only want their absolute values
    remainder.is_negative = false;
    divisor.is_negative = false;

    if(remainder < divisor)
        return make_pair(0, remainder);

    divisor.num_literal.insert(divisor.num_literal.begin(), remainder.num_literal.size() - divisor.num_literal.size(), '0');

    int quotient_digit = 0;

    while(remainder >= b){

        if(remainder < divisor){

            divisor.num_literal.erase(divisor.num_literal.begin());

            quotient.num_literal.insert(quotient.num_literal.begin(), '0' + quotient_digit);

            quotient_digit = 0;

        }else{

            remainder -= divisor;

            quotient_digit++;

        }
    
    }

    quotient.num_literal.insert(quotient.num_literal.begin(), '0' + quotient_digit);

    quotient.num_literal.insert(quotient.num_literal.begin(), divisor.num_literal.size() - b.num_literal.size(), '0');

    return make_pair(quotient, remainder);
}

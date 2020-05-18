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

	Digit carry = 0;

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
		res.num_literal.push_back(1);

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

        Digit borrow = 0;

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

        if(res.num_literal[i] == '0')
            res.num_literal.pop_back();
        else
            break;

    }

    return res;
}

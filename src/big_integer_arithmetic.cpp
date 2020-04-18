#include "big_integer.hpp"

// make this function can only be access in this file
namespace {

	inline int MAX(int a, int b){ return a > b ? a : b; }

}

BigInteger BigInteger::add(BigInteger b)
{
	BigInteger res;

	int len1 = num_literal.size();
	int len2 = b.num_literal.size();

	int max_len = MAX(len1, len2);

	res.num_literal.resize(max_len + 1);

	int carry = 0;

	for(int i = 0; i < max_len; i++){

		if(i >= len1 && i < len2)
			res.num_literal[i] = b.num_literal[i] + carry;
		else if(i < len1 && i >= len2)
			res.num_literal[i] = num_literal[i] + carry;
		else
			res.num_literal[i] = num_literal[i] + b.num_literal[i] + carry;

		if(res.num_literal[i] >= 10){

			res.num_literal[i] -= 10;

			carry = 1;

		}else
			carry = 0;

	}

	if(carry == 1)
		res.num_literal[max_len] = 1;
	else
		res.num_literal.pop_back();

	return res;
}


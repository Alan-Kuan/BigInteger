#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <iostream>  // for I/O
#include <vector>    // for storing the number
#include <string>    // for reading input

using std::istream;
using std::ostream;
using std::vector;
using std::string;

typedef char Digit;

class BigInteger
{

protected:
	vector<Digit> num_literal;
	bool is_negative;

	void fromStdString(string);

	BigInteger plus(BigInteger);
	BigInteger minus(BigInteger);

public:
	BigInteger(void);
	BigInteger(const BigInteger&);
	BigInteger(int);
	BigInteger(string);

    bool operator==(BigInteger);
    bool operator==(int);
    bool operator!=(BigInteger);
    bool operator!=(int);
    bool operator>(BigInteger);
    bool operator>(int);
    bool operator<(BigInteger);
    bool operator<(int);
    bool operator>=(BigInteger);
    bool operator>=(int);
    bool operator<=(BigInteger);
    bool operator<=(int);

	BigInteger operator-(void);

	BigInteger operator+(BigInteger);
	BigInteger operator+(int);
	BigInteger operator-(BigInteger);
	BigInteger operator-(int);

	BigInteger& operator++(void);
	BigInteger operator++(int);
	BigInteger& operator--(void);
	BigInteger operator--(int);

	BigInteger& operator=(BigInteger);
	BigInteger& operator=(int);
	BigInteger& operator=(string);

	BigInteger& operator+=(BigInteger);
	BigInteger& operator+=(int);
	BigInteger& operator-=(BigInteger);
	BigInteger& operator-=(int);

	friend istream& operator>>(istream&, BigInteger&);
	friend ostream& operator<<(ostream&, const BigInteger&);

};

#endif    // BIG_INTEGER_HPP

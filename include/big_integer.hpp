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

	void fromStdString(const string&);

	BigInteger plus(const BigInteger&) const;
	BigInteger minus(const BigInteger&) const;

public:
	BigInteger(void);
	BigInteger(const BigInteger&);
	BigInteger(int);
	BigInteger(string);

    bool operator==(const BigInteger&) const;
    bool operator==(int) const;
    bool operator!=(const BigInteger&) const;
    bool operator!=(int) const;
    bool operator>(const BigInteger&) const;
    bool operator>(int) const;
    bool operator<(const BigInteger&) const;
    bool operator<(int) const;
    bool operator>=(const BigInteger&) const;
    bool operator>=(int) const;
    bool operator<=(const BigInteger&) const;
    bool operator<=(int) const;

	BigInteger operator+(void) const;
	BigInteger operator-(void) const;

	BigInteger operator+(const BigInteger&) const;
	BigInteger operator+(int) const;
	BigInteger operator-(const BigInteger&) const;
	BigInteger operator-(int) const;

	BigInteger& operator++(void);
	BigInteger operator++(int);
	BigInteger& operator--(void);
	BigInteger operator--(int);

	BigInteger& operator=(const BigInteger&);
	BigInteger& operator=(int);
	BigInteger& operator=(const string&);

	BigInteger& operator+=(const BigInteger&);
	BigInteger& operator+=(int);
	BigInteger& operator-=(const BigInteger&);
	BigInteger& operator-=(int);

	friend istream& operator>>(istream&, BigInteger&);
	friend ostream& operator<<(ostream&, const BigInteger&);

};

#endif    // BIG_INTEGER_HPP

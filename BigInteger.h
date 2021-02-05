/**
 * @file BigInteger.h
 * @author Ali Ravaee
 * @brief Class definition of Big Integer, used to store large integers.
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#ifndef BIG_INTEGER_H // include guard
#define BIG_INTEGER_H
// maximum number of arbitrary digits we can have
const int MAXIMUM = 500;
class BigInteger
{
public:
    BigInteger(int n);
    BigInteger(const std::string &n);

    std::ostream &print(std::ostream &out) const;

    BigInteger operator++();
    BigInteger operator+=(const BigInteger &R);

private:
    int digits[MAXIMUM];

    static const int BASE;

    friend BigInteger operator+(const BigInteger &L, const BigInteger &R);
    friend BigInteger operator*(const BigInteger &L, const BigInteger &R);
};

std::ostream &operator<<(std::ostream &out, const BigInteger &n);
BigInteger operator+(const BigInteger &L, const BigInteger &R);
BigInteger operator*(const BigInteger &L, const BigInteger &R);

#endif // BIG_INTEGER_H
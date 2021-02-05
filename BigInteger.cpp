/**
 * @file BigInteger.cpp
 * @author Ali Ravaee
 * @brief Implementation of Big Integer, it can handle very large numbers 
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "BigInteger.h"

const int BigInteger::BASE = 10;

BigInteger::BigInteger(int n)
{
    for (int i = MAXIMUM - 1; i >= 0; --i)
    {
        digits[i] = n % BASE;
        n /= BASE;
    }
}

BigInteger::BigInteger(const std::string &n)
{
    if (n.size() <= static_cast<unsigned int>(MAXIMUM))
    {
        unsigned int i = 0;

        for (; i < MAXIMUM - n.length(); ++i)
        {
            this->digits[i] = 0;
        }

        for (; i < static_cast<unsigned int>(MAXIMUM); ++i)
        {
            this->digits[i] = n[i - (MAXIMUM - n.length())] - '0';
        }
    }
}

std::ostream &BigInteger::print(std::ostream &out) const
{
    bool leadingZeros = true;

    for (int i = 0; i < MAXIMUM; ++i)
    {
        if (digits[i] != 0)
        {
            leadingZeros = false;
        }

        if (!leadingZeros || i == MAXIMUM - 1)
        {
            out << digits[i];
        }
    }

    return out;
}

BigInteger BigInteger::operator++()
{
    return *this += 1;
}

BigInteger BigInteger::operator+=(const BigInteger &R)
{
    *this = *this + R;

    return *this;
}

BigInteger operator+(const BigInteger &L, const BigInteger &R)
{
    if (L.digits[0] + R.digits[0] >= BigInteger::BASE)
    {
        std::cout << "Overflow in operator+()." << std::endl;
        return 0;
    }

    BigInteger sum(0);
    int carry = 0;

    for (int i = MAXIMUM - 1; i >= 0; --i)
    {
        int rest = L.digits[i] + R.digits[i] + carry;

        sum.digits[i] = rest % BigInteger::BASE;
        carry = rest / 10;
    }

    return sum;
}

BigInteger operator*(const BigInteger &L, const BigInteger &R)
{
    for (int i = 0; i < MAXIMUM / 2; ++i)
    {
        if (L.digits[i] != 0 || R.digits[i] != 0)
        {
            std::cout << "There is an overflow in *" << std::endl;
            return 0;
        }
    }

    BigInteger prod(0);

    for (int i = MAXIMUM / 2; i < MAXIMUM; ++i)
    {
        BigInteger res(0);

        for (int j = MAXIMUM / 2; j < MAXIMUM; ++j)
        {
            int rest = L.digits[i] * R.digits[j];

            res.digits[i - (MAXIMUM - j)] += rest / BigInteger::BASE;
            res.digits[i - (MAXIMUM - j) + 1] = rest % BigInteger::BASE;
        }

        prod += res;
    }

    return prod;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &n)
{
    return n.print(out);
}

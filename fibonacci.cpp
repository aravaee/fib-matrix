/**
 * @file fibonacci.cpp
 * @author Ali Ravaee
 * @brief Using matrices to achive O(n) complexity when calculating fibonacci numbers
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "fibonacci.h"

/**
 * @brief Multiplies the matrix {{1, 1}, {1, 0}} n times.
 * 
 * @param n nth fibonacci number to be calculated
 * @return BigInteger 
 */
BigInteger fib(int n)
{
    BigInteger M_1[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    power(M_1, n - 1);
    return M_1[0][0];
}
/**
 * @brief Multiply two matrices together
 * 
 * @param M_1 Matrix 2x1
 * @param M_2 Matrix 2x1
 */
void dot_product(BigInteger M_1[2][2], BigInteger M_2[2][2])
{
    BigInteger x = M_1[0][0] * M_2[0][0] + M_1[0][1] * M_2[1][0];
    BigInteger y = M_1[0][0] * M_2[0][1] + M_1[0][1] * M_2[1][1];
    BigInteger z = M_1[1][0] * M_2[0][0] + M_1[1][1] * M_2[1][0];
    BigInteger w = M_1[1][0] * M_2[0][1] + M_1[1][1] * M_2[1][1];

    M_1[0][0] = x;
    M_1[0][1] = y;
    M_1[1][0] = z;
    M_1[1][1] = w;
}
/**
 * @brief Raises the matrix to the power of n
 * 
 * @param M_1 Matrix 2x1
 * @param n exponent
 */
void power(BigInteger M_1[2][2], int n)
{
    int i;
    BigInteger M_2[2][2] = {{1, 1}, {1, 0}};

    for (i = 2; i <= n; i++)
        dot_product(M_1, M_2);
}

/**
 * @file fibonacci.h
 * @author Ali Ravaee
 * @brief calculate fibonacci numbers using matrix multiplication
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "BigInteger.h"
// fibonacci.h
#ifndef FIBONACCI_H // include guard
#define FIBONACCI_H

void dot_product(int F[2][2], int M[2][2]);
void power(BigInteger F[2][2], int n);
BigInteger fib(int n);

#endif // FIBONACCI_H
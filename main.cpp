/**
 * @file main.cpp
 * @author Ali Ravaee
 * @brief Calculates very large fibonacci numbers
 * @version 0.1
 * @date 2021-02-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "fibonacci.h"

/**
 * @brief Prints every 20th fibonacci number from 0 to 500
 * 
 */
int main(int argc, char const *argv[])
{
    std::cout << "Printing every 20th fibonacci number from 0 to 500:" << std::endl;
    for (int i = 0; i <= 25; ++i)
    {
        std::cout << i * 20 << ": " << fib(i * 20) << std::endl;
    }
    return 0;
}

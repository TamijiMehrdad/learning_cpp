/**
 * @file chapter_09_q3.cpp
 * @author Mehrdad Tamiji (mehrdad.tamiji@gmail.com)
 * @brief Write your own function to swap the value of two integer variables. Write a main() function to test it.
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <array>
#include <vector>
#include <string_view>
#include <numeric> 

void swap(int &a, int &b)
{
    a += b;
    b = a - b;
    a = a - b;
}
int main()
{
    int a{2};
    int b{3};
    swap(a, b);
    std::cout << a << "  " << b << '\n';
    return 0;
}
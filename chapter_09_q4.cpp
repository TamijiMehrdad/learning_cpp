/**
 * @file chapter_09_q4.cpp
 * @author Mehrdad Tamiji (mehrdad.tamiji@gmail.com)
 * @brief Write a function to print a C-style string character by character. Use a pointer to step through each character of the string and print that character. Stop when you hit the null terminator. Write a main function that tests the function with the string literal “Hello, world!”.
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

void print_c_string(const char *str)
{
    while (*str != '\0')
    {
        std::cout << *str ;
        ++str;
    }
}
int main()
{
    print_c_string("Hello world!");
    return 0;
}
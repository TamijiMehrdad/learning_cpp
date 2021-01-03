#include "cpp_tools.h"
#include "10_9.h"
#include <functional>
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
#include <cassert>
#include <tuple>


char get_operation()
{
    char operation{};
    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        operation =  get_char_from_user();
    } while (operation != '+' && operation != '/' && operation != '*' && operation != '-');

    return operation;
}
 
int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    assert(b!=0);
    return a/b;
}

aritmethic_function get_arithmetic_function(char op)
{
    switch (op)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return divide;
    default:
        assert(false);
    }
}

int main()
{
    std::cout << "Enter a int number:";
    int a{ get_int_from_user()};
    char op{ get_operation() };
    std::cout << "Enter a int number:";
    int b{ get_int_from_user() };
    aritmethic_function calculator{get_arithmetic_function(op)};
    std::cout << calculator(a, b) << '\n';
 
    return 0;
}
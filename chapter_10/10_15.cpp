#include "cpp_tools.h"
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
#include <chrono>
#include <sstream>
#include <cstdarg>
#include <functional>


void different_types_lambda()
{
    //The only way of using the lambda’s actual type is by means of auto. auto also has the benefit of having no overhead compared to std::function.
    
    // Unfortunately, we can’t always use auto. In cases where the actual lambda is unknown (e.g. because we’re passing a lambda to a function as a parameter and the caller determines what lambda will be passed in), we can’t use auto. In such cases, std::function should be used.

    double (*add_number1)(double, double){[](double a, double b){return (a + b);}};
    auto add_number2{[](double a, double b){return (a+b);}};
    std::function add_number3 {[](double a, double b){return (a+b);}};
}

void print_values(const int repeat, const std::function<void(int)> &fn)
{
    for(int i{0}; i < repeat; ++i)
        fn(i);
}

void pass_lambda_to_fuction()
{
    auto fun{[](int i){std::cout << i << ' ';}};
    print_values(5, fun);
}

void adjacent_compare()
{
    //In the above example, we use auto parameters to capture our strings by const reference. Because all string types allow access to their individual characters via operator[], we don’t need to care whether the user is passing in a std::string, C-style string, or something else. This allows us to write a lambda that could accept any of these, meaning if we change the type of months later, we won’t have to rewrite the lambda.

    constexpr std::array months{ "January","February","March","April","May","June","July","August","September","October", "November", "December"};
    //Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas.
    auto lambda{[](const auto &a, const auto &b){return (a[0]==b[0]);}};
    auto found{std::adjacent_find(months.begin(), months.end(), lambda)};
    if(found != months.end())
        std::cout << *found << '\n';
}


int main(int argc, char *argv[])
{
    pass_lambda_to_fuction();
    std::cout << '\n' << "====================================" << '\n';
    adjacent_compare();
    return 0;
}
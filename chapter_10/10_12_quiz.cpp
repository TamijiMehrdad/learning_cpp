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

int factorial(int a) // answer question 1 
{
    if(a == 0)
        return 1;
    else
    {
        return (factorial(a-1) * a);
    }
    
}

int digit_sum(int a) // answer question 2
{
    if (a<10)
        return a;
    else
        return digit_sum(a/10) + (a%10);
}

int binary_convert(int a)
{
    if(a/2==0)
    {
        return (a%2);
    }
    else
    {
        return (binary_convert(a/2) * 10 + (a%2));
    }
    
}

int main()
{
    std::cout << factorial(5) << '\n';
    std::cout << digit_sum(15563914) << '\n'; // answer: 34
    std::cout << binary_convert(13) << '\n'; // answer: 1101
    
    return 0;
}
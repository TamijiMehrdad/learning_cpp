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


using int32 = int;


int32 fibo(int32 a, int32 &count)
{
    count += 1;
    if(a==0)
        return 0;
    else if(a==1)
    {
        return 1;
    }
    return fibo((a - 1), count) + fibo((a - 2), count);
}

int main()
{
    std::cout << "Warning: If you enter a number above 40 it may take long time or even stack overflow"<< '\n';
    std::cout << "number of sequence: ";
    int32 seq_length{get_int_from_user()};
    // std::cout <<  fibo(50) << ' ';
    int32 count{0};
    int32 count_per_step{0};
    for(int i{0}; i < seq_length; ++i)
    {
        std::cout <<  fibo(i, count_per_step) << "(" << count_per_step << ")  ";
        count += count_per_step;
        count_per_step = 0;
    }
    std::cout << '\n' << count << '\n';
    
    return 0;
}
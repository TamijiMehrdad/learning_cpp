#include "cpp_tools.h"
#include "select_sort_callback_function.h"
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

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

bool evenfirst(int a, int b) // even first in ascending and odd lase with descending
{
    bool a_is_even{a % 2 == 0};
    bool b_is_even{b % 2 == 0};
    if( a_is_even && b_is_even )
    {
        return ascending(a, b);
    }
    else if(!a_is_even && !b_is_even )
    {
        return descending(a, b);
    }
    else if(!a_is_even, b_is_even )
    {
        return true;
    }
    else if(a_is_even, !b_is_even )
    {
        return false;
    }
    assert(1==1);
    return 0;
}

void printArray(int *array, int size)
{
    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }
    
    std::cout << '\n';
}

void select_sort(int *arr, const int length, validate_function ptr_fun)
{
    for(int i{0}; i < length - 1; ++i)
    {
        int best_index{i};
        for(int j{i+1}; j < length; ++j)
        {
            if (ptr_fun(arr[best_index], arr[j]))
            {
                best_index = j;
            }
        }
        std::swap(arr[i], arr[best_index]);
        // printArray(arr, 9);
    }
}


int main()
{
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };
 
    // Sort the array in descending order using the descending() function
    select_sort(array, 9, ascending);
    printArray(array, 9);

    select_sort(array, 9, descending);
    printArray(array, 9);

    select_sort(array, 9, evenfirst);
    printArray(array, 9);

    select_sort(array, 9);
    printArray(array, 9);
 
    return 0;
}
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

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}
void printArray(int *array, int size)
{
    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }
    
    std::cout << '\n';
}
void select_sort(int *arr, const int length, bool (*ptr_fun)(int, int))
{
    for(int i{0}; i < length - 1; ++i)
    {
        int smallest_index{i};
        for(int j{i+1}; j < length; ++j)
        {
            if (ptr_fun(arr[smallest_index], arr[j]))
            {
                smallest_index = j;
            }
        }
        std::swap(arr[i], arr[smallest_index]);
        //  printArray(arr, 9);
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
 
    return 0;
}
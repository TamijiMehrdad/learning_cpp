#include "cpp_tools.h"
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
#include <chrono>
#include <iostream>
#include <chrono>

// note: exp must be non-negative

int_fast64_t powint(int_fast64_t base, int exp)
{
	int_fast64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
 
	return result;
}

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b)
{
	double relEpsilon{1e-8};
	double absEpsilon{1e-12};
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;
 
    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int get_random_number(int min, int max )
{
	static std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	return std::uniform_int_distribution{ min, max }(mersenne);
}

std::string get_string_from_user()
{
    std::string str{};
    std::getline(std::cin, str);
    return str;
}

char get_char_from_user()
{
    char ch{};
    
    while (true)
    {
        std::cin >> ch;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "you should enter a number:";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    return ch;
}

int get_int_from_user()
{
    int num{0};
    while (true)
    {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "you should enter a number:";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    return num;
}

void get_duration_function()
{
    int length{100000000};
    int *arr{new (std::nothrow) int[length]{}};
    auto start{std::chrono::high_resolution_clock::now()};
    for(std::size_t i{0}; i < length; ++i)
    {
        arr[i] = get_random_number(1, 1000000);
    }
    auto end{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::milliseconds>(end - start )};
    std::cout << (duration.count()) << '\n';
    
    delete[] arr;
}
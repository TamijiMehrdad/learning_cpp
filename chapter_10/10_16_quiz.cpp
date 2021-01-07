/**
 * @file 10_16.cpp
 * @author Mehrdad Tamiji (mehrdad.tamiji@gmail.com)
 * @brief We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer with itself (1, 4, 9, 16, 25, …)). Ask the user to input 2 numbers, the first is the square root of the number to start at, the second is the amount of numbers to generate. Generate a random integer from 2 to 4, and square numbers in the range that was chosen by the user. Multiply each square number by the random number. You can assume that the user enters valid numbers. The user has to calculate which numbers have been generated. The program checks if the user guessed correctly and removes the guessed number from the list. If the user guessed wrong, the game is over and the program prints the number that was closest to the user’s final guess, but only if the final guess was not off by more than 4.
 * @version 0.1
 * @date 2021-01-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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

struct Car
{
  std::string make{};
  std::string model{};
};
 
int main()
{
    std::vector<int> vec{};
    std::cout <<  "Start where? ";
    int start{get_int_from_user()};
    std::cout << "How many?"; 
    int many{get_int_from_user()};
    vec.reserve(many);
    int rand{get_random_number(2, 4)};
    for(int i{0}; i < many; ++i)
    {
        vec.push_back( powint(start, 2) * rand);
        ++start;
    }
    std::cout << "I generated " << many << " square numbers. Do you know what each number is after multiplying it by "  << rand <<" ?";
    int guess{};
    bool success{true};
    for(int i{0}; i < many ; ++i )
    {
        guess = get_int_from_user();
        auto found{std::find(vec.begin(), vec.end(),guess)};
        if (found != vec.end())
        {
            vec.erase(found);
            std::cout << "Nice!" << (many - i  - 1) <<" numbers left.";
        }
        else
        {
            int min{};
            auto lambda{[guess](int a, int b){ return std::abs(a-guess) <  std::abs(b-guess);}};
            auto nearest{*std::min_element(vec.begin(), vec.end(), lambda)};
            if (std::abs(nearest - guess) <= 4)
            {
                std::cout <<  guess  <<" is wrong! Try " << nearest << " next time.\n";
            }
            else
            {
                std::cout << '\n';
            }
            // std::cout << guess  <<" is wrong! Try " << *nearest <<"next time.";
            success = false;
            break;
        }
    }
    if (success)
        std::cout << "You found all numbers, good job!\n";
    return 0;
}
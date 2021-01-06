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

struct Student
{
    std::string name{""};
    int point{0};
};

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};

void question_1()
{
    std::array<Student, 8> arr{{ 
    { "Albert", 3 }, 
    { "Ben", 5 }, 
    { "Christine", 2 }, 
    { "Dan", 8 }, 
    { "Enchilada", 4 }, 
    { "Francis", 1 }, 
    { "Greg", 3 }, 
    { "Hagrid", 5 } 
    }};
    auto lambda_max_point{[](const Student &stud1, const Student &stud2){return (stud1.point < stud2.point);}};

    auto result{std::max_element(arr.begin(), arr.end(),lambda_max_point)};
    std::cout << result->name << " is the best student";
}

void question_2()
{

    std::array<Season, 4> seasons{
    {   { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };
    auto lambda_ascending{[](const Season a, const Season b){return (a.averageTemperature < b.averageTemperature);}};
    std::sort(seasons.begin(), seasons.end(), lambda_ascending);
    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }
}
int main(int argc, char *argv[])
{
    question_1();
    std::cout << '\n';
    question_2();
    return 0;
}
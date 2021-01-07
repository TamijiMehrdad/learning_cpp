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

class Date_class
{
public:
    int year{};
    int month{};
    int day{};
    void print()
    {
        std::cout << year << "/ " << month << "/ " << day << '\n';
    }

private:
 
};

class Employee
{
public:
    std::string m_name{};
    int m_id{};
    double m_wage{};
    void print_info()
    {
        std::cout << m_name << "with id: " << m_id << "earn: " << m_wage << '\n';
    }
private:
};

int main()
{
    Date_class today { 2020, 10, 14};
    today.print();
    Employee alex{"Alex", 001, 8000};
    Employee jack{"Jack", 002, 4000};
    alex.print_info();
    jack.print_info();
    std::cout << "Just work and not play make jack a dull boy" << '\n';
    return 0;
}
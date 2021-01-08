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
    int m_year{};
    int m_month{};
    int m_day{};
public:
    void date_set(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void print() 
    {
        std::cout << m_month << '/' << m_day << '/' << m_year << '\n';
    }
    void copy_from(const Date_class &d)
    {
        m_year = d.m_year;
        m_month = d.m_month;
        m_day = d.m_day;
    }
};

int main(int argc, char *argv[])
{
    Date_class today{};
    today.date_set(2020,12,5);
    today.print();
    Date_class another_today{};
    another_today.copy_from(today);
    another_today.print();
    return 0;
}
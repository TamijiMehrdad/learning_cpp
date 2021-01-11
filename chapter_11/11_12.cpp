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

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};
public:
    Date(int year, int month, int day);
    void set(int year, int month, int day);
    int get_year() const {return m_year;}
    int get_month() const {return m_month;}
    int get_day() const {return m_day;}
};

Date::Date(int year, int month, int day)
{
    set(year, month, day);
}

void Date::set(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

int main()
{
    const Date date{2020,3,6};
    std::cout << date.get_year() << '\n';
}
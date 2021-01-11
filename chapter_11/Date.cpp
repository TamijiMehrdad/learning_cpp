#include "cpp_tools.h"
#include "Date.h"
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

    return 0;
}
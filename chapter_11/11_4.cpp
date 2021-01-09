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
    int get_year(){return m_year;}
    void set_year(int year){m_year = year;}

    int get_month(){return m_month;}
    void set_month(int month){m_month = month;}

    int get_day(){return m_day;}
    void set_day(int day){m_day = day;}
};
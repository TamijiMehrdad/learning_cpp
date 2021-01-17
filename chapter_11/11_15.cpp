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

class Value
{
private:
    int m_value;
public:
    Value(int value) {m_value = value;}
    friend bool is_equal(const Value &val1, const Value &val2);
};

bool is_equal(const Value &val1, const Value &val2)
{
    return (val1.m_value == val2.m_value);
}
//===================
class Humidity;
class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp=0){m_temp = temp;}
    friend void print_weather(const Temperature &temperature, const Humidity &humidity);
};

class Humidity
{
private:
    int m_humid;
public:
    Humidity(int humid=0){m_humid = humid;}
    friend void print_weather(const Temperature &temperature, const Humidity &humidity);
};

void print_weather(const Temperature &temperature, const Humidity &humidity)
{
    std::cout << temperature.m_temp << ' ' << humidity.m_humid << '\n';
}

// =========================
class Display;
class Storage
{
private:
    int m_int_val;
    double m_double_val;
public:
    Storage(int int_val, double double_val)
    {
        m_int_val = int_val;
        m_double_val = double_val;
    }
    void print(const Display &display);
};

class Display
{
private:
    bool m_first;
public:
    Display(bool first)
    {
        m_first = first;
    }
    friend void Storage::print(const Display &display);
};

void Storage::print(const Display &display)
{
    if (display.m_first)
        std::cout << m_int_val << '\n';
    else 
    std::cout << m_double_val << '\n';
}
// =========================

void contex1()
{
    Value v1(10);
    Value v2(11);
    std::cout<< is_equal(v1,v2) << '\n';
}

void contex2()
{
    Temperature temp(10);
    Humidity humid(20);
    print_weather(temp, humid);
}

void contex3()
{
    Storage st(2, 4.5);
    Display dp(false);
    st.print(dp);
}
int main()
{
    contex1();
    contex2();
    contex3();
    return 0;
}
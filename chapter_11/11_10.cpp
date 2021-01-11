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

class Calc
{
private:
    int m_result{0};
public:
    Calc():m_result{0}
    {}
    Calc &add(int value) {m_result += value; return *this;}
    Calc &sub(int value) {m_result -= value; return *this;}
    Calc &multi(int value) {m_result *= value; return *this;}
    Calc &div(int value) {m_result /= value; return *this;}
    int get_val(){return m_result;}
};

int main()
{
    Calc a{};
    std::cout << (a.add(5).multi(4).sub(2).div(3).get_val()) << '\n'; //6
    return 0;
}
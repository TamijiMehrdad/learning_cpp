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

class Clac
{
private:
    int m_result{0};
public:
    Clac():m_result{0}
    {}
    Clac &add(int value) {m_result += value; return *this;}
    Clac &sub(int value) {m_result -= value; return *this;}
    Clac &multi(int value) {m_result *= value; return *this;}
    Clac &div(int value) {m_result /= value; return *this;}
    int get_val(){return m_result;}
};

int main()
{
    Clac a{};
    std::cout << (a.add(5).multi(4).sub(2).div(3).get_val()) << '\n'; //6
    return 0;
}
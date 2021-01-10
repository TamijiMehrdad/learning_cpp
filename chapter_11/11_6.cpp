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

class Initializer
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Initializer():m_value1{10}, m_value2{2.3}, m_value3('c')
    {
    }
    void print()
    {
        std::cout << m_value3 << ' ' << m_value2 << ' '<< m_value1 << '\n';
    }

};

int main()
{
    Initializer init;
    init.print();
    return 0;
}
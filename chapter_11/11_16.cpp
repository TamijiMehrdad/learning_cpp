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

class Cents
{
    private:
        int m_cents{};
    public:
        Cents(int cents):m_cents{cents}
        {}
        int get_cent() const {return m_cents;}
};

Cents add(const Cents &cent1,  const Cents &cent2)
{
    return (cent1.get_cent() + cent2.get_cent());
}

int main()
{
    std::cout << add(Cents{5}, Cents{6}).get_cent() << '\n';
    return 0;
}
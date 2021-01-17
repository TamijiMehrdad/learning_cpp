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

class My_class
{
public:
    static std::vector<char> s_init_char;
    class init_cha
    {
    public:
        init_cha()
        {
            for(char ch{'a'}; ch <='z'; ++ch)
                s_init_char.push_back(ch);
        }
    };
private:
    static init_cha s_initialazer;
};
std::vector<char> My_class::s_init_char{};
My_class::init_cha My_class::s_initialazer{};

int main()
{
    My_class cl{};
    std::cout << cl.s_init_char.size();
    return 0;
}
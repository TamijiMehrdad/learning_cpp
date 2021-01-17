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

class Fruit
{
public:
    enum class Fruit_type
    {
        Apple,
        Banana,
        Cherry,
        Max_type
    };
private:
    Fruit_type m_fruit_type{};
    int m_percentage{};
public:
    Fruit(Fruit_type fruit_type=Fruit_type::Apple, int percentage=0):m_fruit_type{fruit_type}, m_percentage{percentage}
    {}
    Fruit_type get_fruit_type(){return m_fruit_type;}
    int get_percentage(){return m_percentage;}
};

int main()
{
    Fruit f{Fruit::Fruit_type::Banana};
    if (f.get_fruit_type() == Fruit::Fruit_type::Apple) 
        std::cout << "apple" << '\n';
    else
        std::cout << "not apple" << '\n';
    
}
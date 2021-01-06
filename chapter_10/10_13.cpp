#include "cpp_tools.h"
#include "10_9.h"
#include <functional>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <array>
#include <vector>
#include <string_view>
#include <numeric>
#include <cassert>
#include <tuple>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        if(argv[0])
            std::cout << "usage: " << argv[0] << " <int_item> <double_item> <string_item>" << '\n';
        else
            std::cout << "usage: <program name> <number>" << '\n';
        return 1;
    }

    int int_item{0};
    double double_item{0};
    std::string string_item{};
    
    for (int i{1}; i < argc ; ++i)
    {
        std::string item{};
        static_cast<std::stringstream>(argv[i]) >> item;

        if (item=="-i" || item=="--item")
        {
            
            if(static_cast<std::stringstream>(argv[i+1]) >> int_item)
                ++i;
            else
                int_item = 0;
        }
        else if (item=="-d" || item=="--double")
        {
            
            if(static_cast<std::stringstream>(argv[i+1]) >> double_item)
                ++i;
            else
                double_item = 0;
        }
        else if (item=="-s" || item=="--string")
        {
            
            if(static_cast<std::stringstream>(argv[i+1]) >> string_item)
                ++i;
            else
                string_item = "";
        }
    }

    std::cout << int_item << '\n';
    std::cout << double_item << '\n';
    std::cout << string_item << '\n';

    return 0;
}
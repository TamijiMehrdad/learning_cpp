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
#include <string>
#include <typeinfo>
#include <array>
#include <vector>
#include <string_view>
#include <numeric>
#include <cassert>
#include <tuple>

void print_vec(const std::vector<int> &vec) // if you forget to put (&) sign actually main pass a copy of vec to function and for optimizing, it pass a vector in size of length rather than capacity.   
{
    for(auto &element:vec)
    {
        std::cout << element << ' ';
    }
    std::cout << '\t' << "cap: " << vec.capacity() << "  length: " << vec.size() << '\n';
}

int main()
{
    std::vector<int> vec{};
    vec.reserve(5);
    vec.push_back(1);
    print_vec(vec);

    vec.push_back(6);
    print_vec(vec);
    std::cout << "back: " << vec.back() << '\n';

    vec.pop_back();
    print_vec(vec);

    vec.pop_back();
    print_vec(vec);

    return 0;
}
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

class Mehrdad_array
{
private:
    int *m_arr{};
    int m_length{};
public:
    Mehrdad_array(int length)
    {
        assert(length > 0);
        m_arr = new int [static_cast<std::size_t>(length)]{};
        m_length = length;
    }
    ~Mehrdad_array()
    {
        delete[] m_arr;
    }
    void set(int index, int value){m_arr[index] = value;}
    int get(int index){return m_arr[index];}
    int get_length(){return m_length;}
};

int main()
{
    Mehrdad_array arr(10);
    for(int i{0}; i < arr.get_length(); ++i)
    {
        arr.set(i, i * i);
    }
    std::cout << arr.get(5);
    return 0;
}
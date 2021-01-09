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

class Ball
{
private:
    std::string m_color{};
    double m_radius{};

public:
    // Ball()
    // {
    //     m_color = "black";
    //     m_radius = 10.0;
    // }

    // Ball(const std::string &color)
    // {
    //     m_color = color;
    // }

    Ball(const double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    Ball(const std::string &color= "black", const double radius=10.5)
    {
        m_color = color;
        m_radius = radius;
    }

    void print()
    {
        std::cout << m_color << ' ' << m_radius << '\n';
    }

};


int main()
{
	Ball def{};
	def.print();
 
	Ball blue{ "blue" };
	blue.print();
	
	Ball twenty{ 20.0 };
	twenty.print();
	
	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
    return 0;
}
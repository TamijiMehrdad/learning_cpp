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

class Rectangle
{
private:
    double m_length{0};
    double m_width{0};

public:
    Rectangle(double length, double width):m_length{length}, m_width{width}
    {}
    Rectangle(double length): m_length{length}
    {}
    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
 

};


class Ball
{
private:
	std::string m_color{"black"};
	double m_radius{10.0};
 
public:

	Ball(double radius):m_radius{radius}
	{
	}
 
	Ball(const std::string &color="black", double radius= 10.0):m_color{color}, m_radius{radius}
	{
	}
 
	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

void contex()
{
    Rectangle x{ 2.0, 3.0 };
    x.print();
 
    Rectangle y{ 4.0 };
    y.print();
}

void question()
{
    Ball def;
	def.print();
 
	Ball blue{ "blue" };
	blue.print();
	
	Ball twenty{ 20.0 };
	twenty.print();
	
	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();
}
int main()
{
    contex();
    question();
    return 0;
}
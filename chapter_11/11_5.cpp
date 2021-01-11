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

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:

    Fraction()=default;
    Fraction(int numerator, int denominator=1)
    {
        assert(denominator!= 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }
    int get_numerator(){return m_numerator;}
    int get_denominator(){return m_denominator;}
    int get_fraction(){return static_cast<double>(m_numerator / m_denominator);}
};

class A
{
    public:
    A(){std::cout << "A\n";}
};

class B
{
    private:
    A m_a{};
    public:
    B(){std::cout << "B\n";}
};

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

void contex()
{
    Fraction frac;
    std::cout << frac.get_numerator() << "/" << frac.get_denominator() << '\n';
    Fraction frac1{2, 3};   
    std::cout << frac1.get_numerator() << "/" << frac1.get_denominator() << '\n';
    Fraction frac2{1};
    Fraction frac3{};
    Fraction frac4{2,2};
    B b{};
}

void question()
{
    Ball def{};
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
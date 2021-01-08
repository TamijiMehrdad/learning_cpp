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

class Point_3d
{
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    void set_values(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print()
    {
        std::cout << '<'<<  m_x << ", "<<  m_y << ", "<< m_z << '>' <<  '\n';
    }
    bool is_equal(const Point_3d &point)
    {
        return (point.m_x == m_x && point.m_y== m_y && point.m_z==m_z);
    }
};

class Stack
{
private:
    int stack_top{0};
    const int length{10};
    int array[10];

public:
    void reset()
    {
        stack_top = 0;
    }

    bool push(int a)
    {
        if (stack_top >= length)
            return false;
        else
        {
            array[stack_top] = a;
            ++stack_top;
            return true;
        }
    }

    int pop()
    {
        assert(stack_top!=0);
        return (array[stack_top--]);
    }

    void print()
    {
        std::cout << '(';
        for(int i{0}; i < stack_top; ++i)
            std::cout << array[i] << ' ';
        std::cout << ')' << '\n';
    }
};

void question_2()
{
    Point_3d point1 {};
    point1.set_values(1, 2, 3);
    point1.print();
    Point_3d point2{};
    point2.set_values(1, 2, 3);
    if (point1.is_equal(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }
 
    Point_3d point3{};
    point3.set_values(3, 4, 5);
 
    if (point1.is_equal(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }
}

void question_3()
{
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
    stack.push(5);
	stack.push(3);
	stack.push(8);
    stack.push(5);
	stack.push(3);
	stack.push(8);
    stack.push(11);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
    stack.pop();
 
	stack.print();
}

int main(int argc, char *argv[])
{
    question_2();
    question_3();
    return 0;
}
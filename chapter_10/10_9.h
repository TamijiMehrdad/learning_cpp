#ifndef Chapter_10_9_H
#define Chapter_10_9_H
#include <functional>

using aritmethic_function = std::function<int(int , int)>;


char get_operation();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
aritmethic_function get_arithmetic_function(char op='+');

#endif
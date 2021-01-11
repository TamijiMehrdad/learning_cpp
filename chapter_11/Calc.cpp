#include "Calc.h"
#include <iostream>
Calc &Calc::add(int val){m_result += val; return *this;}
Calc &Calc::sub(int val){m_result -= val; return *this;}
Calc &Calc::mul(int val){m_result *= val; return *this;}
Calc &Calc::div(int val){m_result /= val; return *this;}
int Calc::get(){return m_result;}

// int main()
// {
//     Calc a{};
//     std::cout << (a.add(5).mul(4).sub(2).div(3).get()) << '\n'; //6
//     return 0;
// }
#ifndef DATE_H
#define DATE_H

class Calc
{
private:
    int m_result{};
public:
    Calc():m_result{0}
    {}
    Calc &add(int val);
    Calc &sub(int val);
    Calc &mul(int val);
    Calc &div(int val);
    int get();
};
#endif
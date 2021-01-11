#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};
public:
    Date(int year, int month, int day);
    ~Date();
    void set(int year, int month, int day);
    int get_year(){return m_year;}
    int get_month(){return m_month;}
    int get_day(){return m_day;}
};
#endif
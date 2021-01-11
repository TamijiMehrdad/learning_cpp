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

class Employee
{
private:
    static int s_id_generator;
    int m_id;
    std::string m_name;
    int m_income;
    void generate_id()
    {
        m_id = s_id_generator++;
    }
public:
    Employee(std::string name="", double income=0)
    {
        generate_id();
        m_name = name;
        m_income = income;
    }
    std::string get_name() const {return m_name;}
    double get_income() const {return m_income;}
    int get_id() const {return m_id;}
};

int Employee::s_id_generator = 1;

int main()
{
    Employee m1{"ali", 300};
    Employee m2{"hassan", 400};
    Employee m3{"mammad", 500};
    std::cout << m1.get_id() << '\n';
    std::cout << m2.get_id() << '\n';
    std::cout << m3.get_id() << '\n';
    return 0;
}
#include <iostream>

//+++++++++++ contex1
template<class T>

const T& max(const T& x, const T& y)
{
    return (x > y)? x:y;
}

class Cent
{
private:
    int m_cents;
public:
    Cent(int cents):m_cents{cents}
    {}
    int get_value() const {return m_cents;}
    
    friend bool operator>(const Cent& c1, const Cent& c2)
    {
        return (c1.m_cents > c2.m_cents);
    }

    friend std::ostream& operator<< (std::ostream &out, const Cent &cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }
        Cent& operator+=(const Cent &cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }
 
    Cent& operator/=(int value)
    {
        m_cents /= value;
        return *this;
    }
};

void contex1()
{
    Cent a1{10};
    Cent a2{20};
    auto a3{max(a1, a2)};
    std::cout << a3.get_value() << '\n';
}

//+++++++++++++ contex2
template<class T, class C1>
T average_array(T *array, int length)
{
    T sum{0};
    for(int i{0}; i < length; ++i)
    {
        sum += array[i];
    }
    sum /= length;
    return sum;

}

void contex2()
{
    int  arr_int[]{1,2,3,4,5};
    std::cout << average_array(arr_int, 5) << '\n';
    double arr_double[]{ 3.12, 3.45, 9.23, 6.34 };
    std::cout << average_array(arr_double, 4) << '\n';

    Cent array3[]{ Cent(5), Cent(10), Cent(15), Cent(14) };
    std::cout << average_array(array3, 4) << '\n';
}

int main()
{
    // contex1();
    contex2();
    return 0;
}
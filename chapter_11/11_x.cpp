#include <iostream>
#include <cmath>


class Point2d
{
private:
    double m_x{};
    double m_y{};
public:
    Point2d(double x=0.0, double y=0.0):m_x{x}, m_y{y}
    {}

    void print() const 
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")" << '\n';
    }

    double distance_to(const Point2d & point2d) const
    {
        return std::sqrt(std::pow((m_x - point2d.m_x), 2) + std::pow((m_y - point2d.m_y), 2));
    }
    friend double distance_from(const Point2d & point2d_1, const Point2d & point2d_2);
};

double distance_from(const Point2d & point2d_1, const Point2d & point2d_2)
{
    return std::sqrt(std::pow((point2d_2.m_x - point2d_1.m_x), 2) + std::pow((point2d_2.m_y - point2d_1.m_y), 2));
}

// ================================
void question1()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distance_to(second) << '\n';
    std::cout << "Distance between two points: " << distance_from(first, second) << '\n';
}

void question2()
{

}

void question3()
{
    
}

void question4()
{
    
}


int main()
{
    question1();
    question2();
    question3();
    question4();

 
    return 0;
}
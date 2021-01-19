#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <vector>
class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    std::vector<std::chrono::time_point<clock_t>> m_intervals{}; 
public:
    Timer();
    void interval();
    void elapsed();
};

#endif
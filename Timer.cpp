#include "Timer.h"
#include <iostream>

Timer::Timer()
{
    m_intervals.push_back(clock_t::now());
}

void Timer::interval()
{
    m_intervals.push_back(clock_t::now());
}

void Timer::elapsed()
{
    m_intervals.push_back(clock_t::now());
    for(int i{1}; i < m_intervals.size(); ++i)
    {
        std::cout << "interval "<< (i) << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(m_intervals[i] - m_intervals[i-1]).count() << " milliseconds."  << '\n';
        if(i == (m_intervals.size() -1))
            std::cout << "total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(m_intervals[i] - m_intervals[0]).count() << " milliseconds." << '\n';
    }     
}

#include <algorithm> // for std::sort
#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota
#include <random>

class Timer
{
private:
    using  clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::vector<std::chrono::time_point<clock_t>> m_time_vec{};
public:
    Timer()
    {
        m_time_vec.push_back(clock_t::now());
    }
    // void reset(){m_start = clock_t::now();}
    void interval() 
    {
        m_time_vec.push_back(clock_t::now());
    }

    void elapsed()
    {
        m_time_vec.push_back(clock_t::now());
        for(int i{1}; i < m_time_vec.size(); ++i)
        {
            std::cout << "interval "<< (i) << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(m_time_vec[i] - m_time_vec[i-1]).count() << " milliseconds."  << '\n';
            if(i == (m_time_vec.size() -1))
                std::cout << "total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(m_time_vec[i] - m_time_vec[0]).count() << " milliseconds." << '\n';

        }     
    }
};
// (m_time_vec[0].__d.__r % 100000000000) / 10000000

int main()
{
    Timer t;
    std::array<int, 1000000> array;
    // fill the array with 10000 to 1
    std::iota(array.rbegin(), array.rend(), 1);
    t.interval();
        std::array<int, 1000000> array1;
    // fill the array with 10000 to 1
    std::iota(array1.rbegin(), array.rend(), 1);
    std::sort(array.begin(), array.end());
    t.interval();
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(array.begin(), array.end(),g);
    t.interval();
    std::sort(array.begin(), array.end());
    t.interval();
    std::shuffle(array.begin(), array.end(),g);
    t.interval();
    

  
 
    //   std::ranges::sort(array); // Since C++20
    // If your compiler isn't C++20-capable
    std::sort(array.begin(), array.end());
 
    t.elapsed();
 
  return 0;
}
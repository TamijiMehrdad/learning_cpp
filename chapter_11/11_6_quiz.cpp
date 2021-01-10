#include "cpp_tools.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>
#include <cstdint>
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

class RGBA
{
    using comp_type = std::uint_fast8_t; 
private:
    comp_type m_red;
    comp_type m_green;
    comp_type m_blue;
    comp_type m_alpha;
public:
    RGBA(comp_type red=0, comp_type green=0, comp_type blue=0, comp_type alpha=255):
    m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
    {

    }
	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red) <<
			" g=" << static_cast<int>(m_green) <<
			" b=" << static_cast<int>(m_blue) <<
			" a=" << static_cast<int>(m_alpha) << '\n';
	}
};

int main()
{
    RGBA teal{ 0, 127, 127 };
	teal.print();
 
	return 0;
}
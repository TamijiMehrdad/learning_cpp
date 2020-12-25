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
#include <numeric> // std::reduce


enum class Items
{
	health_potions,
	torches,
	arrows
};

int countTotalItems(const std::array<int,3> &arr)
{
	return std::reduce(arr.begin(), arr.end());

}
int main()
{
	std::cout << "hello";
	std::array player{2,5,10};
    return 0;
}

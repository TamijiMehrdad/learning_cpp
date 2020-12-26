/*
Pretend you’re writing a game where the player can hold 3 types 
of items: health potions, torches, and arrows. Create an enum to identify the different types 
of items, and an std::array to store the number of each item the player is carrying (The enumerators 
are used as indexes of the array). The player should start with 2 health potions, 5 torches, and 
10 arrows. Write a function called countTotalItems() that returns how many items the player 
has in total. Have your main() function print the output of countTotalItems() 
as well as the number of torches.
*/

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


enum Items
{
	item_health_potions,
	item_torches,
	item_arrows,
	max_item
};

int countTotalItems(const inventory_item &arr)
{
	return std::reduce(arr.begin(), arr.end());

}

using inventory_item = std::array<int, max_item>;

inventory_item init()
{
	constexpr int init_health_potions{2};
	constexpr int init_torches{5};
	constexpr int init_arrows{10};

	return inventory_item{init_health_potions, init_torches, init_arrows};
}
int main()
{
	inventory_item player{init()};
	

	auto total{countTotalItems(player)};

	std::cout << total << '\n';
	std::cout << player[item_torches] << '\n';
    return 0;
	
}

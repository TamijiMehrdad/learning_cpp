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


enum class Ranks
{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,
    max_ranks
};

enum class Suits
{
    club,
    diamond,
    heart,
    spades,
    max_suits
};

struct Card
{
    Ranks rank{};
    Suits suit{};
};

void print_card(const Card &card)
{
    std::string out{};
    switch (card.rank)
    { 
    case (Ranks::two) :
        out = "2";
        break;
    case (Ranks::three) :
        out = "3";
        break;
    case (Ranks::four) :
        out = "4";
        break;
    case (Ranks::five) :
        out = "5";
        break;
    case (Ranks::six) :
        out = "6";
        break;
    case (Ranks::seven) :
        out = "7";
        break;
    case (Ranks::eight) :
        out = "8";
        break;
    case (Ranks::nine) :
        out = "9";
        break;
    case (Ranks::ten) :
        out = "10";
        break;
    case (Ranks::jack) :
        out = "J";
        break;
    case (Ranks::queen) :
        out = "Q";
        break;
    case (Ranks::king) :
        out = "K";
        break;
    case (Ranks::ace) :
        out = "A";
        break;
    default:
        out = "error";
        break;
    }

    switch (card.suit)
    { 
    case (Suits::club) :
        out += "C";
        break;
    case (Suits::spades) :
        out += "S";
        break;
    case (Suits::diamond) :
        out += "D";
        break;
    case (Suits::heart) :
        out += "H";
        break;
    default:
        out = "error";
        break;
    }
    std::cout << out << '\n';
}

using deck_type = std::array<Card, 52>;
using player_deck_type = std::array<Card, 11>; // 11 because at most player can get 11 cards(4 aces + 4 two + 3 three. equal 21)

deck_type creat_deck()
{
    deck_type deck{};
    int max_suits{static_cast<int>(Suits::max_suits)};
    int max_ranks{static_cast<int>(Ranks::max_ranks)};
    for(int suit{0}; suit< max_suits; ++suit)
    {
        for(int rank{0}; rank < max_ranks; ++rank)
        {
            deck[(suit * 13) + rank].suit = static_cast<Suits>(suit) ;
            deck[(suit * 13) + rank].rank = static_cast<Ranks>(rank);
        }
    }
    return deck;
}

int get_card_value(const Card &card)
{
    if(card.rank <= Ranks::ten)
    {
        return (static_cast<int>(card.rank) + 2);
    }
    switch (card.rank)
    {
    case Ranks::jack:
    case Ranks::queen:
    case Ranks::king:
        return 10;
        break;
    case Ranks::ace:
        return 11;
        break;
    default:
    // error handler
        return 0;
        break;
    }
}

void init(deck_type &deck, int &num_player)
{
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
    std::cout << "Number of player:";
    num_player = get_int_from_user();
}

void init_player(deck_type deck)
{

    get_random_number(int min, int max );
}

void init_dealer(deck_type deck)
{
    int a {};
}

int main()
{
    Card card{Ranks::five, Suits::club};
    std::cout << get_card_value(card) << '\n';
    print_card(card);
    deck_type deck{creat_deck()};
    int num_player{1};
    init(deck, num_player);
    std::vector<player_deck_type> players_deck{};
    players_deck.resize(num_player);
    for(auto &element:players_deck)
    {
        init_player(element);
    }
    
    
    init_player(deck);
    for(auto &element: deck)
    {
        print_card(element);
    }

    return 0;
}
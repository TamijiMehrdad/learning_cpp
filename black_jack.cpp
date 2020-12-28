#include "cpp_tools.h"
#include "black_jack.h"
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
    bool is_available{false};
};

std::string print_card(const Card &card)
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
        out += "Club";
        break;
    case (Suits::spades) :
        out += "Spades";
        break;
    case (Suits::diamond) :
        out += "Diamond";
        break;
    case (Suits::heart) :
        out += "Heart";
        break;
    default:
        out = "error";
        break;
    }
    return out;
}


struct Player
{
    std::array<Card, 11> deck{}; // 11 because at most player can get 11 cards(4 aces + 4 two + 3 three. equal 21)
    std::string name{""};
    int bank{0};
    int gambling_money{0};
    int value_cards{0};
    bool multi{false};
    bool stand{false};
    bool hit{false};
    bool insurance{false};
};

using deck_type = std::array<Card, 52>;
using player_vec = std::vector<Player>;

deck_type creat_deck()
{
    deck_type deck{};
    int max_suits{static_cast<int>(Suits::max_suits)};
    int max_ranks{static_cast<int>(Ranks::max_ranks)};
    for(int suit{0}; suit< max_suits; ++suit)
    {
        for(int rank{0}; rank < max_ranks; ++rank)
        {
            deck[(suit * 13) + rank].suit = static_cast<Suits>(suit);
            deck[(suit * 13) + rank].rank = static_cast<Ranks>(rank);
            deck[(suit * 13) + rank].is_available = true;
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
    
    while(true)
    {
        std::cout << "Enter number of players below " << const_play::MAX_NUM_PLAYERS <<":";
        num_player = get_int_from_user() ;
        if (num_player < const_play::MAX_NUM_PLAYERS && num_player > 0)
        {
            break;
        }
        else
        {
            std::cout << "Your number is not valid. ";
        }
    }
}

void name_and_money_of_player(player_vec &vec, const int &num_player)
{
    for(int player_idx{0};auto &element:vec)
    {
        if (player_idx < num_player)
        {
            element.bank = const_play::Player_INIT_MONEY;
            std::cout << "Please insert name of player #" << (player_idx + 1) <<": ";
            element.name =  get_string_from_user();
            int gambling_money{0};
            while(true)
            {
                std::cout << element.name << " bank is: " << element.bank << "$. Enter how much money you want to play: ";
                gambling_money = get_int_from_user();
                if (gambling_money <= element.bank && gambling_money > 0)
                {
                    break;
                }
                else
                {
                    std::cout << "Your number is not valid. ";
                }
            }
            element.bank -= gambling_money;
            element.gambling_money = gambling_money;
        }
        else if (player_idx == num_player) // This is because of setting money of dealer that should be infinitive
        {
            element.name = "Dealer";
            element.bank = const_play::DEALER_MONEY;
            element.gambling_money = const_play::DEALER_MONEY;
        }
        ++player_idx;
    }
}

player_vec init_players(deck_type &deck, const int &num_player)
{
    player_vec vec{};
    vec.resize(num_player + 1); // we add with one because we have dealer. dealer would be last element of vector.
    name_and_money_of_player(vec, num_player);
    int indx_deck{0};
    for(int player_idx{0}; auto &element:vec)
    {
        assert(indx_deck < const_play::NUM_CARDS);
        element.deck[0].is_available = true;
        element.deck[0].rank = deck[indx_deck].rank;
        element.deck[0].suit = deck[indx_deck].suit;
        element.value_cards += get_card_value(element.deck[0]);
        deck[indx_deck].is_available = false;
        ++indx_deck;
        element.deck[1].is_available = true;
        element.deck[1].rank = deck[indx_deck].rank;
        element.deck[1].suit = deck[indx_deck].suit;
        deck[indx_deck].is_available = false;
        
        if (player_idx != num_player) // if it is dealer, we should hide its second card and it's value 
        {
            element.value_cards += get_card_value(element.deck[1]);
        }
        ++indx_deck;
        ++player_idx;
    }
    return vec;
}

std::string show_info_player(const Player element,const bool &is_dealer)
{
    std::string msg{""};
    msg += element.name;
    msg += " cards: ";
    msg += print_card(element.deck[0]);
    msg += " ";
    if(!is_dealer)
    {
    msg += print_card(element.deck[1]);
    msg += "\t Gambling money: ";
    msg += std::to_string(element.gambling_money);
    }
    msg += "\t value of cards: ";
    msg += std::to_string(element.value_cards);
    msg += "\n";
    return msg;
}

void show_players_cards(const deck_type &deck, const player_vec &vec, const int &num_player)
{
    std::string msg{""};
    for(int player_idx{0}; auto &element: vec)
    {
        msg = "";
        if (player_idx < num_player)
        {
            msg = show_info_player(element, false);            
            std::cout << msg;
        }
        else if (player_idx == num_player) // This is because of dealer
        {
            msg = show_info_player(element, true);
            std::cout << msg;
        }
        ++player_idx;
    }
}

void player_play(deck_type &deck, player_vec &vec, const int &num_player)
{
    for(int player_idx{0}; auto &element: vec)
    {
        if (player_idx < num_player)
        {
            
        }
        else if (player_idx == num_player) // This is because of dealer
        {

        }
        ++player_idx;
    }

}

void general_play(deck_type &deck, player_vec &vec, const int &num_player)
{
    show_players_cards(deck, vec, num_player);
    // for(int player_idx{0}; auto &element: vec)
    // {
    //     if (player_idx < num_player)
    //     {
    //         player_play(deck, vec, num_player);
    //     }
    //     else if (player_idx == num_player) // This is because of dealer
    //     {
    //         dealer_play()
    //     }
    //     ++player_idx;
    // }
    // finish_play()
}

int main()
{
    // Card card{Ranks::five, Suits::club};
    // std::cout << get_card_value(card) << '\n';
    // print_card(card);
    deck_type deck{creat_deck()};
    int num_player{1};
    init(deck, num_player);
    player_vec vec{init_players( deck, num_player)};
    general_play(deck, vec, num_player);
    // play_again();
    return 0;
}
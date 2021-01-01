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
};

enum class Status
{
    hit,
    stand,
    bust,
    lost,
    insurance,
    push,
    win,
    black_jack,
    max_status
};

enum class Player_move
{
    multi,
    stand,
    hit,
    insurance,
    max_Player_move
};

struct Choices
{
    bool multi{false};
    bool stand{false};
    bool hit{false};
    bool insurance{false};
};

struct Deck
{
    std::array<Card, 52> set{};
    int indx_first{0};
};

struct Card_str
{
    std::array<Card, 11> set{};
    int indx{0};
};

struct Player
{
    Card_str deck{};
    std::string name{""};
    std::string msg{};
    Choices choices{};
    Player_move move{Player_move::stand};
    Status status{Status::bust};
    int indx_first{0}; // index of firs free card.
    int bank{0}; // TODO: convert to double
    int gambling_money{0}; // TODO: convert to double
    int value_cards{0};
};

using player_vec = std::vector<Player>;

std::string name_card(const Card &card)
{
    std::string out{};
    switch (card.rank)
    {
    case (Ranks::two):
        out = "2";
        break;
    case (Ranks::three):
        out = "3";
        break;
    case (Ranks::four):
        out = "4";
        break;
    case (Ranks::five):
        out = "5";
        break;
    case (Ranks::six):
        out = "6";
        break;
    case (Ranks::seven):
        out = "7";
        break;
    case (Ranks::eight):
        out = "8";
        break;
    case (Ranks::nine):
        out = "9";
        break;
    case (Ranks::ten):
        out = "10";
        break;
    case (Ranks::jack):
        out = "J";
        break;
    case (Ranks::queen):
        out = "Q";
        break;
    case (Ranks::king):
        out = "K";
        break;
    case (Ranks::ace):
        out = "A";
        break;
    default:
        out = "error";
        break;
    }

    switch (card.suit)
    {
    case (Suits::club):
        out += "Club";
        break;
    case (Suits::spades):
        out += "Spades";
        break;
    case (Suits::diamond):
        out += "Diamond";
        break;
    case (Suits::heart):
        out += "Heart";
        break;
    default:
        out = "error";
        break;
    }
    return out;
}

Deck creat_deck()
{
    Deck deck{};
    int max_suits{static_cast<int>(Suits::max_suits)};
    int max_ranks{static_cast<int>(Ranks::max_ranks)};
    for (int suit{0}; suit < max_suits; ++suit)
    {
        for (int rank{0}; rank < max_ranks; ++rank)
        {
            deck.set[(suit * 13) + rank].suit = static_cast<Suits>(suit);
            deck.set[(suit * 13) + rank].rank = static_cast<Ranks>(rank);
        }
    }
    return deck;
}

void get_cards_value(Player &player) 
{
    int num_aces{0};
    int value{0};
    for(int i{0}; i <player.indx_first; ++i)
    {
        Card card{player.deck.set[i]};
        if (card.rank <= Ranks::ten)
        {
            value += (static_cast<int>(card.rank) + 2);
        }
        else
        {
            switch (card.rank)
            {
            case Ranks::jack:
            case Ranks::queen:
            case Ranks::king:
                 value += 10;
                break;
            case Ranks::ace:
            {
                ++num_aces;
                break;
            }
            default:
                //TODO: error handler
                exit(1);
                break;
            }
        }
    }
    int max{0};
    max = value;
    if (num_aces)
    {
        std::vector<int> possible_values{};
        possible_values.resize(num_aces + 1);
        for(int i{0}; i < (num_aces + 1) ;++i)
        {
            possible_values[i] = (i * 1) + ((num_aces -i) * 11) + value;
            if (possible_values[i] <= const_play::BLACK_JACK_NUMB && possible_values[i] > max)
            {
                max = possible_values[i];
            }
        }
    }
    player.value_cards = max;
}

void shuffle_deck(Deck &deck)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.set.begin(), deck.set.end(), mt);

}

void init(Deck &deck, int &num_player)
{
    shuffle_deck(deck);
    while (true)
    {
        std::cout << "Enter number of players below " << const_play::MAX_NUM_PLAYERS << ":";
        num_player = get_int_from_user();
        if (num_player < const_play::MAX_NUM_PLAYERS && num_player > 0)
            break;
        else
            std::cout << "Your number is not valid. ";
    }
}

void get_name_player(Player &player, const int player_idx)
{
    player.bank = const_play::PLAYER_INIT_MONEY;
    std::cout << "Please insert name of player #" << (player_idx + 1) << ": ";
    player.name = get_string_from_user();
}

void get_money_player(Player &player)
{
    int gambling_money{0};
    while (true)
    {
        std::cout << player.name << " bank is: " << player.bank << "$. Enter how much money you want to play: ";
        gambling_money = get_int_from_user();
        if (gambling_money <= player.bank && gambling_money > 0)
            break;
        else
            std::cout << "Your number is not valid. ";
    }
    player.bank -= gambling_money;
    player.gambling_money = gambling_money;
}

void get_name_money_dealer(Player &dealer)
{
    dealer.name = "Dealer";
    dealer.bank = const_play::DEALER_MONEY;
    dealer.gambling_money = const_play::DEALER_MONEY; // TODO: we should choose a safe system to wirk with money. For example when it is int have problem with divide and overflow.
}

void assign_card(Deck &deck, Player &player)
{
    player.deck.set[player.indx_first].rank = deck.set[deck.indx_first].rank;
    player.deck.set[player.indx_first].suit = deck.set[deck.indx_first].suit;
    ++(player.indx_first);
    ++(deck.indx_first);
    get_cards_value(player);
    assert(deck.indx_first < const_play::NUM_CARDS);
}

void show_info_player(Player &player,const bool &final_result)
{
    std::string msg{""};
    msg += player.name;
    msg += " cards: ";
    for (int i{0}; i < player.indx_first; ++i)
    {
        msg += name_card(player.deck.set[i]);
        msg += " ";
    }
    msg += "\t value of cards: ";
    msg += std::to_string(player.value_cards);
    if (!final_result)
    {
        msg += "\t Gambling money: ";
        msg += std::to_string(player.gambling_money);
    }
    else
    {
        msg += "\t final status: ";
        if(player.status == Status::win)
            msg += "win";
        else if (player.status == Status::lost)
            msg += "lost";
        else if (player.status == Status::push)
            msg += "push";
        msg += "\t final bank: ";
        msg += std::to_string(player.bank);
    }

    msg += "\n";

    player.msg = msg;
    std::cout << player.msg;
}

void show_info_dealer(Player &dealer, const bool &show_all_cards)
{
    std::string msg{""};
    msg += dealer.name;
    msg += " cards: ";
    if (show_all_cards)
    {
        for (int i{0}; i < dealer.indx_first; ++i)
        {
            msg += name_card(dealer.deck.set[i]);
            msg += " ";
        }
        msg += "\t\t value of cards: ";
        msg += std::to_string(dealer.value_cards);
    }
    else
    {
        msg += name_card(dealer.deck.set[0]);
        msg += " ";
        msg += "\t\t value of cards: ";
        dealer.indx_first -= 1;
        get_cards_value(dealer);
        msg += std::to_string(dealer.value_cards);
        dealer.indx_first += 1;
        get_cards_value(dealer);
        
         // we subtract second card from dealer.value_cards because second cart is hidden.
    }
    msg += "\n";
    dealer.msg = msg;
    std::cout << dealer.msg;
}

void print_breakline()
{
    std::cout << "\n=====================================\n\n";
}

player_vec init_players(Deck &deck, const int &num_player)
{
    player_vec vec{};
    vec.resize(num_player + 1); // we add with one because we have dealer. dealer would be last element of vector.
    for (int player_idx{0}; auto &player : vec)
    {
        if (player_idx < num_player)
        {
            get_name_player(player, player_idx);
        }
        else if (player_idx == num_player) // This is because of dealer
        {
            get_name_money_dealer(player);
        }
        ++player_idx;
    }
    return vec;
}

player_vec assign_players_cards(Deck &deck,player_vec &vec, const int &num_player)
{
    for (int player_idx{0}; auto &player : vec)
    {
        if (player_idx < num_player)
        {
            get_money_player(player);
            assign_card(deck, player); // give first card
            assign_card(deck, player); // give second card
            show_info_player(player, false);
            print_breakline();
        }
        else if (player_idx == num_player) // This is because of dealer
        {
            assign_card(deck, player);       // give first card
            assign_card(deck, player);       // give second card
            show_info_dealer(player, false); // don't show all card and just show first card
        }
        ++player_idx;
    }
    return vec;
}

void player_choices(Player &player, Player &dealer, const bool &round_1)
{
    player.choices.hit = true;
    player.choices.stand = true;
    std::cout << player.msg;
    if (round_1 && player.gambling_money < player.bank)
        player.choices.multi = true;
    else
        player.choices.multi = false;

    if (dealer.deck.set[0].rank == Ranks::ace && round_1)
        player.choices.insurance = true;
    else
        player.choices.insurance = false;
    // TODO: add option of splite
}

void get_player_move(Player &player)
{
    char move{};
    std::string msg{(player.name + " can do: \t")};
    if (player.choices.hit)
        msg += "hit(press h)\t";
    if (player.choices.multi)
        msg += "multi(press m)\t";
    if (player.choices.insurance)
        msg += "insurance(press i)\t";
    if (player.choices.stand)
        msg += "stand(press s)\t";
    msg += "your choice: ";

    while (true)
    {
        std::cout << msg;
        move = get_char_from_user(); 

        if (move == 'h' && player.choices.hit)
        {
            player.move = Player_move::hit;
            break;
        }
        else if (move == 'i' && player.choices.insurance)
        {
            player.move = Player_move::insurance;
            break;
        }
        else if (move == 's' && player.choices.stand)
        {
            player.move = Player_move::stand;
            break;
        }
        else if (move == 'm' && player.choices.multi)
        {
            player.move = Player_move::multi;
            break;
        }
        else
        {
            std::cout << "You input is not valid. ";
        }
    }
}

void do_play(Deck &deck, Player &player)
{
    switch (player.move)
    {
    case Player_move::hit:
    {
        assign_card(deck, player);
        if (player.value_cards > const_play::BLACK_JACK_NUMB)
            player.status = Status::bust;
        else if (player.value_cards == const_play::BLACK_JACK_NUMB)
            player.status = Status::stand;
        else
            player.status = Status::hit;
        break;
    }

    case Player_move::multi:
    {
        assign_card(deck, player);
        player.bank -= player.gambling_money;
        player.gambling_money += player.gambling_money;
        if (player.value_cards > const_play::BLACK_JACK_NUMB)
            player.status = Status::bust;
        else if (player.value_cards <= const_play::BLACK_JACK_NUMB)
            player.status = Status::stand; // because it is multi don't have hit optioin anymore
        break;
    }

    case Player_move::insurance:
    {
        player.status = Status::insurance;
        break;
    }

    case Player_move::stand:
    {
        player.status = Status::stand;
        break;
    }

    default:
        std::cerr << "error"; // TODO: error handling
        break;
    }
}

void player_play(Deck &deck, player_vec &vec, const int &num_player)
{
    for (int player_idx{0}; auto &player : vec)
    {
        if (player_idx < num_player)
        {
            print_breakline();
            bool round_1{true};
            while (player.value_cards < const_play::BLACK_JACK_NUMB)
            {
                Player dealer = vec[vec.size() - 1];
                player_choices(player, dealer, round_1);
                get_player_move(player);
                do_play(deck, player);
                show_info_player(player, false);
                round_1 = false;
                if (player.status != Status::hit)
                    break;
            }

            if (player.value_cards == const_play::BLACK_JACK_NUMB && round_1) // black jack situation
            {
                player.status = Status::black_jack;
            }
            assert(player.status != Status::hit);
        }
        else if (player_idx == num_player) // This is because of dealer
        {
            //
        }
        ++player_idx;
    }
}

void dealer_play(Deck &deck, Player &dealer, const int &num_player)
{
    print_breakline();
    show_info_dealer(dealer, true); // true because we want to show second card of dealer.
    bool round_1{true};
    dealer.status = Status::stand;
    while (dealer.value_cards < const_play::DEALER_CEIL)
    {
        round_1 = false;
        dealer.choices.hit = true;
        dealer.choices.stand = false;
        dealer.move = Player_move::hit;
        do_play(deck, dealer);
        show_info_dealer(dealer, true);
        if (dealer.value_cards >= const_play::DEALER_CEIL && dealer.value_cards <= const_play::BLACK_JACK_NUMB)
        {
            dealer.status = Status::stand;
        }
    }

    if (dealer.value_cards == const_play::BLACK_JACK_NUMB && round_1) // black jack situation
    {
        dealer.status = Status::black_jack;
    }
    assert(dealer.status != Status::hit);
}

void win_lost_status(Player &player, const Player &dealer)
{
    if (player.status == Status::bust)
        player.status = Status::lost;

    else if (player.status == Status::stand)
    {
        if (dealer.status == Status::black_jack)
            player.status = Status::lost;

        else if (dealer.status == Status::bust)
            player.status = Status::win;

        else if (dealer.status == Status::stand)
        {
            if (dealer.value_cards == player.value_cards)
                player.status = Status::push;
            else if (dealer.value_cards > player.value_cards)
                player.status = Status::lost;
            else if (dealer.value_cards < player.value_cards)
                player.status = Status::win;
        }
    }
    else if (player.status == Status::black_jack)
    {
        if (dealer.status == Status::black_jack)
            player.status = Status::push;

        else if (dealer.status != Status::black_jack)
            player.status = Status::win;
    }
    // Status::insurance not come here because it releated to accounting
}

void accounting(Player &player, Player &dealer)
{
    if (player.status == Status::insurance)
    {
        int half_money{static_cast<int>(player.gambling_money / 2)}; // TODO: convert to double. we lose some data here because player.bank and player.gambling_money are not double type
        player.bank += half_money;
        dealer.bank += half_money;
    }
    else if (player.status == Status::lost)
    {
        dealer.bank += player.gambling_money;
    }
    else if (player.status == Status::win)
    {
        player.bank += (2 * player.gambling_money);
        dealer.bank -= player.gambling_money;
    }
    else if (player.status == Status::push)
    {
        player.bank += player.gambling_money;
    }
}

void reset_player(Player &player, Deck deck)
{
    player.indx_first = 0;
    player.msg = "";
    player.gambling_money = 0;
    player.value_cards = 0;
    player.choices.hit = false;
    player.choices.stand = false;
    player.choices.insurance = false;
    player.choices.multi = false;
    player.move = Player_move::stand;
    player.status = Status::bust;
    Card_str temp_card_arr;
    player.deck = temp_card_arr;
    

}

void finish_play(Deck &deck, player_vec &vec, Player &dealer, const int &num_player)
{
    for (int player_idx{0}; auto &player : vec)
    {
        if (player_idx < num_player)
        {
            win_lost_status(player, dealer);
            accounting(player, dealer);
            print_breakline();
            show_info_player(player, true); // true means show final result
            reset_player(player, deck);
        }
        else if (player_idx == num_player) // This is because of dealer
        {
            reset_player(player, deck);
        }
        ++player_idx;
    }
}

int main()
{
    // Card card{Ranks::five, Suits::club};
    // std::cout << get_card_value(card) << '\n';
    // name_card(card);
    Deck deck{creat_deck()};
    int num_player{1};
    init(deck, num_player);
    player_vec vec{init_players(deck, num_player)};
    while (true)
    {
        assign_players_cards(deck, vec, num_player);
        player_play(deck, vec, num_player);
        dealer_play(deck, vec[vec.size() - 1], num_player);
        finish_play(deck, vec, vec[vec.size() - 1], num_player);
        
        std::cout << "\n Do you want play again?(y, n) ";
        char move {get_char_from_user()}; 

        if (move == 'n')
        {
            std::cout << "by\n";
            break;
        }
        else if (move == 'y') // TODO: should handle the problem of if money of an user has finished, because if never can come out of loop get money.
        {
            deck.indx_first = 0;
            shuffle_deck(deck);
            std::cout << "start\n";
        }
    }
    return 0;
}
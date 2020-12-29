#ifndef BLACK_JACK_H
#define BLACK_JACK_H

namespace const_play
{
    constexpr int NUM_CARDS{52};
    constexpr int MAX_NUM_PLAYERS{5};
    constexpr int BLACK_JACK_NUMB{21};
    constexpr int DEALER_CEIL{17};
    constexpr int DEALER_MONEY{std::numeric_limits<int>::max()};
    constexpr int PLAYER_INIT_MONEY{1000};
}

#endif
#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H

#include <vector>
#include <array>
#include "Structs.h"

class Deck {
private:
    std::uint8_t width, height;
    CardDeck cards;

public:
    void init();

    Deck(std::uint8_t width, std::uint8_t height);

    CardDeck get_cards();

    void swap_hand_with_expected_pos();

    bool is_ace_of_spades_in_right_down_corner();

    bool is_board_valid();
};

#endif //UNTITLED_DECK_H

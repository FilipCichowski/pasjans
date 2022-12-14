#ifndef UNTITLED_DECK_H
#define UNTITLED_DECK_H

#include <vector>
#include <array>
#include "Structs.h"

class Deck {
private:
    std::uint8_t width, height;
    std::vector<std::vector<Card>> cards;

public:
    std::vector<std::vector<Card>> get_cards();

    void init();

    Deck(std::uint8_t width, std::uint8_t height);

    std::vector<Card> get_row(uint8_t index);

    void swap_hand_with_expected_pos();

    bool is_ace_of_spades_in_right_down_corner();

    bool is_board_valid();

    void log_cards();
};

#endif //UNTITLED_DECK_H

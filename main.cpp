#include <iostream>

#include "headers/deck.h"

int main() {
    Deck d(4, 6);
    d.log_cards();
    while (1) {
        d.swap_hand_with_expected_pos();
        d.log_cards();
        if (d.is_ace_of_spades_in_right_down_corner()) {
            if (d.is_board_valid()) {
                std::cout << "Win! \n";
                break;
            } else {
                d.init();
                std::cout << "Looose! Starting new game... \n";
            }
        }
    }
}

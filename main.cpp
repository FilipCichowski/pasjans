#include <iostream>
#include <iomanip>

#include "headers/deck.h"

void log_deck(std::uint8_t width, std::uint8_t height, std::vector<std::vector<Card>> &cards) {
    for (std::uint8_t i = 0; i < height; i++) {
        for (std::uint8_t j = 0; j < width; j++) {
            std::cout << std::left << std::setw(4);
            if (cards[j][i].is_hidden) {
                std::cout << "XX";
            } else {
                std::cout << static_cast<int>(cards[j][i].id);
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<std::vector<Card>>> cards;
    Deck d(4, 6);
    //d.log_cards();
    while (1) {
        d.swap_hand_with_expected_pos();
        cards.push_back(d.get_cards());
//        d.log_cards();
        if (d.is_ace_of_spades_in_right_down_corner()) {
            if (d.is_board_valid()) {
                std::cout << "Win! \n";
                for (auto &e: cards) {
                    log_deck(4, 6, e);
                }
                cards.clear();
                break;
            } else {
                d.init();
                std::cout << "Looose! Starting new game... \n";
                cards.clear();
            }
        }
    }
}

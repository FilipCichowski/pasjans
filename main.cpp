#include <iostream>
#include <iomanip>
#include "headers/deck.h"

void log_deck(std::uint8_t width, std::uint8_t height, CardDeck &cards) {
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
    std::uint8_t width = 4;
    std::uint8_t height = 6;
    std::vector<CardDeck> cards;
    Deck d(width, height);
    while (1) {
        cards.emplace_back(d.get_cards());
        d.swap_hand_with_expected_pos();
        if (d.is_ace_of_spades_in_right_down_corner()) {
            if (d.is_board_valid()) {
                cards.emplace_back(d.get_cards());
                for (auto &e: cards) {
                    log_deck(width, height, e);
                }
                break;
            } else {
                d.init();
                cards.clear();
            }
        }
    }
    return 0;
}

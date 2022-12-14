#include <random>
#include <iostream>
#include <iomanip>
#include "../headers/Deck.h"

Deck::Deck(std::uint8_t width, std::uint8_t height) : width(width), height(height) {
    init();
}

void Deck::init() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<Card> temp;
    temp.resize(width * height);

    cards.resize(width); // allocate 4 columns

    for (auto &col: cards) {
        col.resize(height); // each column contains 6 cards
    }

    // fill 1D vector with values for further shuffling
    for (std::uint8_t i = 0; i < width * height; i++) {
        temp[i].id = i;
    }

    std::shuffle(temp.begin(), temp.end(), g);

    // fill 2D vector with shuffled values
    for (std::uint8_t i = 0; i < width; i++) {
        for (std::uint8_t j = 0; j < height; j++) {
            cards[i][j] = temp[i * height + j];
        }
    }
}

std::vector<Card> Deck::get_row(uint8_t index) {
    std::vector<Card> temp;
    temp.resize(width);
    for (int8_t i = 0; i < width; i++) {
        temp[i] = cards[i][index];
    }
    return temp;
}

void Deck::log_cards() {
    for (std::uint8_t i = 0; i < height; i++) {
        for (auto &el: this->get_row(i)) {
//            std::cout << static_cast<int>(el.id) << " " << el.is_hidden << "\n";

            std::cout << std::left << std::setw(4);
            if (el.is_hidden) {
                std::cout << "XX";
            } else {
                std::cout << static_cast<int>(el.id);
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Deck::swap_hand_with_expected_pos() {
    const std::uint8_t hand_card_value = cards[width - 1][height - 1].id;
    const std::uint8_t expected_x = hand_card_value % width;
    const std::uint8_t expected_y = (hand_card_value - expected_x) / width;


    cards[width - 1][height - 1].is_hidden = false;
    cards[expected_x][expected_y].is_hidden = false;
    //cards[0][0].is_hidden = false;

    std::swap(cards[width - 1][height - 1], cards[expected_x][expected_y]);

}

bool Deck::is_ace_of_spades_in_right_down_corner() {
    return cards[width - 1][height - 1].id == (width * height - 1);
}

bool Deck::is_board_valid() {
    bool is_valid = true;
    for (std::uint8_t i = 0; i < height; i++) {
        for (std::uint8_t j = 0; j < width; j++) {
            if (cards[j][i].id != (j + i * width)) {
                is_valid = false;
                break;
            }
        }
    }
    return is_valid;
}

std::vector<std::vector<Card>> Deck::get_cards() {
    return cards;
}
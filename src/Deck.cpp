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
    std::vector<std::uint8_t> temp;
    temp.resize(width * height);

    cards.resize(width); // allocate 4 columns

    for (auto &col: cards) {
        col.resize(height); // each column contains 6 cards
    }

    // fill 1D vector with values for further shuffling
    for (std::uint8_t i = 0; i < width * height; i++) {
        temp[i] = i;
    }

    std::shuffle(temp.begin(), temp.end(), g);

    // fill 2D vector with shuffled values
    for (std::uint8_t i = 0; i < width; i++) {
        for (std::uint8_t j = 0; j < height; j++) {
            cards[i][j] = temp[i * height + j];
        }
    }
}

std::vector<std::uint8_t> Deck::get_row(uint8_t index) {
    std::vector<std::uint8_t> temp;
    temp.resize(width);
    for (int8_t i = 0; i < width; i++) {
        temp[i] = cards[i][index];
    }
    return temp;
}

void Deck::log_cards() {
    for (std::uint8_t i = 0; i < height; i++) {
        for (auto &el: this->get_row(i)) {
            std::cout << std::left << std::setw(4);
            std::cout << static_cast<int>(el);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Deck::swap_hand_with_expected_pos() {
    const std::uint8_t hand_card_value = cards[width - 1][height - 1];
    const std::uint8_t expected_x = hand_card_value % width;
    const std::uint8_t expected_y = (hand_card_value - expected_x) / width;
    std::swap(cards[width - 1][height - 1], cards[expected_x][expected_y]);
}

bool Deck::is_ace_of_spades_in_right_down_corner() {
    return cards[width - 1][height - 1] == (width * height - 1);
}

bool Deck::is_board_valid() {
    bool is_valid = true;
    for (std::uint8_t i = 0; i < height; i++) {
        for (std::uint8_t j = 0; j < width; j++) {
            if (cards[j][i] != (j + i * width)) {
                is_valid = false;
                break;
            }
        }
    }
    return is_valid;
}
#include <random>
#include "../headers/Deck.h"

Deck::Deck(std::uint8_t width, std::uint8_t height) : width(width), height(height) {
    init();
}

void Deck::init() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<Card> temp;

    temp.resize(width * height);

    cards.resize(width);

    for (auto &col: cards) {
        col.resize(height);
    }

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

void Deck::swap_hand_with_expected_pos() {
    const std::uint8_t hand_card_value = cards[width - 1][height - 1].id;
    const std::uint8_t expected_x = hand_card_value % width;
    const std::uint8_t expected_y = (hand_card_value - expected_x) / width;

    cards[width - 1][height - 1].is_hidden = false;
    cards[expected_x][expected_y].is_hidden = false;

    std::swap(cards[width - 1][height - 1], cards[expected_x][expected_y]);
}

bool Deck::is_ace_of_spades_in_right_down_corner() {
    return cards[width - 1][height - 1].id == (width * height - 1);
}

bool Deck::is_board_valid() {
    for (std::uint8_t i = 0; i < height; i++) {
        for (std::uint8_t j = 0; j < width; j++) {
            if (cards[j][i].id != (j + i * width)) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<Card>> Deck::get_cards() {
    return cards;
}

void Deck::make_all_cards_visible() {
    for (auto &e: cards) {
        for (auto &f: e) {
            f.is_hidden = true;
        }
    }
}
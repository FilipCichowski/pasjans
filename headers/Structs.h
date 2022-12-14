#ifndef UNTITLED_STRUCTS_H
#define UNTITLED_STRUCTS_H

#include <cstdint>

struct Card {
    std::uint8_t id = 0;
    bool is_hidden = true;
};

typedef std::vector<std::vector<Card>> CardDeck;

#endif

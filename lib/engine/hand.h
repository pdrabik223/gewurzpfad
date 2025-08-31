#ifndef hand_h
#define hand_h
#pragma once
using namespace std;

#include <iostream>
#include <vector>
#include <sstream>
#include <array>
#include <initializer_list>

#include "lib/console_tools/console_tools.h"
#include "lib/engine/spice_array.h"
#include "lib/engine/cards/card.h"

class Hand
{
public:
    vector<Card *> active;
    vector<Card *> resting_cards;

    SpiceArray held_spices;

    unsigned held_coins = 0;

    unsigned currentPoints()
    {
        return held_coins;
    };

    ~Hand()
    {
        for (Card *card : this->active)
        {
            delete card;
        }

        for (Card *card : this->resting_cards)
        {
            delete card;
        }
    }

    Hand(initializer_list<Card *> active, SpiceArray held_spices) : active(active), held_spices(held_spices)
    {
        for (Card *card : this->active)
        {
            printf(card->show().c_str());
        }
    }

    Hand(const Hand &other)
    {
        if (this == &other)
            return;

        this->active = other.active;
        this->held_coins = other.held_coins;
        this->resting_cards = other.resting_cards;
        this->held_spices = other.held_spices;
    }

    Hand &operator=(const Hand &other)
    {
        if (this == &other)
            return *this;

        this->active = other.active;
        this->held_coins = other.held_coins;
        this->resting_cards = other.resting_cards;
        this->held_spices = other.held_spices;

        return *this;
    }
};

#endif
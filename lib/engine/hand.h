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
#include "lib/engine/cards/card_base.h"

class Hand
{
public:
    vector<CardBase *> active, resting_cards;

    SpiceArray held_spices;

    unsigned held_coins = 0;

    unsigned currentPoints()
    {
        return held_coins;
    };

    ~Hand()
    {

        for (auto i = this->active.size() - 1; i--;)
        {
            delete this->active[i];
        }

        for (auto i = this->resting_cards.size(); i--;)
        {
            delete this->resting_cards[i];
        }
    }

    Hand(initializer_list<CardBase *> active, SpiceArray held_spices) : held_spices(held_spices)
    {

        for (auto card : active)
        {
            this->active.push_back(card->Clone());
        }
        // verify weather we need to delete active pointers now.
    }
    void Show()
    {
        printf("Player 1\n");
        printf("Spices:\t");
        printf(this->held_spices.show().c_str());
        printf("\n");
        printf("Points:\t");
        printf(ft(this->held_coins, FGC::BrightYellow, BGC::Black).c_str());
        printf("\n");
        printf("Active cards:\n");
        if (this->active.size() > 0)
            for (auto card : this->active)
            {
                printf(card->Show().c_str());
                printf("\t");
            }
        else
            printf("Empty");

        printf("\n");
        printf("Resting cards:\n");
        if (this->resting_cards.size() > 0)
            for (auto card : this->resting_cards)
            {
                printf(card->Show().c_str());
                printf("\t");
            }
        else
            printf("Empty");
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
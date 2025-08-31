#ifndef upgrade_card_h
#define upgrade_card_h
#pragma once
using namespace std;
#include <sstream>
#include "../spice_array.h"
#include "card.h"

class UpgradeCard : public Card
{
public:
    unsigned upgrade_level;
    UpgradeCard(unsigned upgrade_level) : upgrade_level(upgrade_level) {}

    UpgradeCard(const UpgradeCard &other)
    {
        this->upgrade_level = other.upgrade_level;
    }

    UpgradeCard operator=(const UpgradeCard &other)
    {
        if (this == &other)
            return *this;

        this->upgrade_level = other.upgrade_level;

        return *this;
    }
    string show() override
    {
        return ft(upgrade_level, FGC::Black, BGC::BrightWhite) + " -> " + ft(upgrade_level, FGC::Black, BGC::BrightWhite);
    }
};


#endif
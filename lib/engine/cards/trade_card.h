#ifndef trade_card_h
#define trade_card_h
#pragma once
using namespace std;
#include <sstream>
#include "../spice_array.h"
#include "card_base.h"

class TradeCard : public CardBase
{
public:
    SpiceArray cost;
    SpiceArray result;

    TradeCard(SpiceArray cost, SpiceArray result) : cost(cost), result(result) {}
    ~TradeCard() override {}

    TradeCard(const TradeCard &other)
    {
        if (this == &other)
            return;

        this->cost = other.cost;
        this->result = other.result;
    }
    TradeCard operator=(const TradeCard &other)
    {
        if (this == &other)
            return *this;

        this->cost = other.cost;
        this->result = other.result;

        return *this;
    }
    string show() override
    {
        return "Not yet implemented";
    }
};

#endif
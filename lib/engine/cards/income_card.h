#ifndef income_card_h
#define income_card_h
#pragma once
using namespace std;
#include <sstream>
#include "../spice_array.h"
#include "card.h"
class IncomeCard : public Card
{
public:
    SpiceArray income;

    IncomeCard(SpiceArray income) : income(income) {}

    IncomeCard(const IncomeCard &other)
    {
        if (this == &other)
            return;

        this->income = other.income;
    }

    IncomeCard operator=(const IncomeCard &other)
    {
        if (this == &other)
            return *this;

        this->income = other.income;

        return *this;
    }

    string show() override
    {
        printf(ft(income.spices.size()).c_str());
        return "  -> " + income.show();
    }
};


#endif
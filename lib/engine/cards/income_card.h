#ifndef income_card_h
#define income_card_h
#pragma once
using namespace std;
#include <sstream>
#include "../spice_array.h"
#include "card_base.h"
class IncomeCard : public CardBase
{
public:
    SpiceArray income;

    IncomeCard(const SpiceArray &income) : income(income) {}

    ~IncomeCard() override = default;

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
    IncomeCard *Clone() { return new IncomeCard(*this); }
    
    string Show() override { return "#  -> " + income.show(); }
    CardType GetCardType() const override { return type_; }

private:
    const CardType type_ = CardType::INCOME_CARD;
};

#endif
#ifndef base_card_h
#define base_card_h
#pragma once
using namespace std;
#include <sstream>

enum class CardType
{
    NONE,
    INCOME_CARD,
    POINTS_CARD,
    TRADE_CARD,
    UPGRADE_CARD

};

class CardBase
{
public:
    CardBase() = default;
    CardBase(const CardBase &other) = default;
    CardBase &operator=(const CardBase &other) { return *this; }

    virtual ~CardBase() = default;
    virtual CardBase *Clone() { return new CardBase(*this); }

    virtual string Show() { return "base card error"; };
    virtual CardType GetCardType() const { return type_; }

private:
    const CardType type_ = CardType::NONE;
};
#endif
#ifndef points_card_h
#define points_card_h
#pragma once
using namespace std;
#include <sstream>
#include "../spice_array.h"
#include "card_base.h"

class PointsCard : public CardBase
{
public:
    unsigned points;
    SpiceArray cost;

    PointsCard(SpiceArray cost, unsigned points) : cost(cost), points(points) {}

    ~PointsCard() override = default;

    PointsCard *Clone() { return new PointsCard(*this); }

    string Show() override { return cost.show() + " -> " + ft(points, FGC::BrightYellow, BGC::Black).c_str(); }

    PointsCard(const PointsCard &other)
    {
        this->points = other.points;
        this->cost = other.cost;
    }

    PointsCard operator=(const PointsCard &other)
    {
        if (this == &other)
            return *this;

        this->points = other.points;
        this->cost = other.cost;

        return *this;
    }

    CardType GetCardType() const override { return type_; }

private:
    const CardType type_ = CardType::POINTS_CARD;
};

#endif
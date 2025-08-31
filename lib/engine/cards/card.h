#ifndef card_h
#define card_h
#pragma once
using namespace std;
#include <sstream>

class Card
{
public:
    virtual string show() = 0;

    // virtual Card(const Card &) = 0;
};
#endif
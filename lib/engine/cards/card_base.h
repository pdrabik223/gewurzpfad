#ifndef base_card_h
#define base_card_h
#pragma once
using namespace std;
#include <sstream>

class CardBase
{
public:
    // Card();
    virtual string show() = 0;
    virtual ~CardBase() =0;
};
#endif
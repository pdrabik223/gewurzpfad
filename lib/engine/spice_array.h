#ifndef spice_array_h
#define spice_array_h
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

#include <initializer_list>
#include "lib/console_tools/console_tools.h"
#include "spice.h"
// #include "console_tools.h"

using namespace std;

class SpiceArray
{
public:
    vector<unsigned> spices = {0, 0, 0, 0};

    SpiceArray() {};

    SpiceArray(unsigned spices[4])
    {
        for (int i = 0; i < 4; i++)
        {
            this->spices[i] = spices[i];
        }
    };

    SpiceArray(initializer_list<unsigned> spices) : spices(spices)
    {
        if (this->spices.size() != 4)
            throw exception("Incorrect vector size");
    };

    unsigned &operator[](Spice index)
    {
        switch (index)
        {
        case Spice::Yellow:
            return this->spices[0];
        case Spice::Red:
            return this->spices[1];
        case Spice::Green:
            return this->spices[2];
        case Spice::Brown:
            return this->spices[3];
        }
    }

#pragma warning(push)
#pragma warning(disable : 4715)
    unsigned get(Spice index) const
    {
        switch (index)
        {
        case Spice::Yellow:
            return this->spices[0];
        case Spice::Red:
            return this->spices[1];
        case Spice::Green:
            return this->spices[2];
        case Spice::Brown:
            return this->spices[3];
        }
    }
#pragma warning(pop)

    SpiceArray(const SpiceArray &other)
    {
        if (this == &other)
            return;

        this->spices[0] = other.get(Spice::Yellow);
        this->spices[1] = other.get(Spice::Red);
        this->spices[2] = other.get(Spice::Green);
        this->spices[3] = other.get(Spice::Brown);
    };

    const SpiceArray &operator=(const SpiceArray &other)
    {
        if (this == &other)
            return *this;

        this->spices[0] = other.get(Spice::Yellow);
        this->spices[1] = other.get(Spice::Red);
        this->spices[2] = other.get(Spice::Green);
        this->spices[3] = other.get(Spice::Brown);

        return *this;
    }

    string show()
    {
        return ft(spices[0], FGC::Black, BGC::BrightYellow) + " " +
               ft(spices[1], FGC::Black, BGC::BrightRed) + " " +
               ft(spices[2], FGC::Black, BGC::BrightGreen) + " " +
               ft(spices[3], FGC::Black, BGC::Yellow);
    }
};
#endif
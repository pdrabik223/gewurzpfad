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
    SpiceArray(const string &spices)
    {
        for (char c : spices)
        {
            switch (c)
            {
            case 'y':
                this->spices[Spice::Yellow]++;
                break;

            case 'r':
                this->spices[Spice::Red]++;
                break;
            case 'g':
                this->spices[Spice::Green]++;
                break;
            case 'b':
                this->spices[Spice::Brown]++;
                break;
            }
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
    bool operator==(const SpiceArray &other)
    {

        return this->spices[0] == other.spices[0] &&
               this->spices[1] == other.spices[1] &&
               this->spices[2] == other.spices[2] &&
               this->spices[3] == other.spices[3];
    }
    bool operator!=(const SpiceArray &other)
    {

        return !this->operator==(other);
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
        string result = ft(" ", FGC::White, BGC::White);

        if (spices[0] != 0)
            result += ft(spices[0], FGC::Black, BGC::BrightYellow);

        if (spices[1] != 0)
            result += ft(spices[1], FGC::Black, BGC::BrightRed);

        if (spices[2] != 0)
            result += ft(spices[2], FGC::Black, BGC::BrightGreen);

        if (spices[3] != 0)
            result += ft(spices[3], FGC::Black, BGC::Blue);

        result += ft(" ", FGC::White, BGC::White);
        return result;
    }
};
#endif
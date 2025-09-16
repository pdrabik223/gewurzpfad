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
class OrderedSpiceArray
{

public:
    vector<Spice> spices_;
    OrderedSpiceArray(initializer_list<Spice> spices) : spices_(spices) {}
    unsigned Count() const noexcept { return spices_.size(); }
};

// const SpiceArray operator-(const SpiceArray &first, const SpiceArray &other)
// {
//     if (other.spices[0] > first.spices[0])
//         throw exception("Spice array does not contain enough of spices");
//     auto yellow = first.spices[0] - other.spices[0];

//     if (other.spices[1] > first.spices[1])
//         throw exception("Spice array does not contain enough of spices");
//     auto red = first.spices[1] - other.spices[1];

//     if (other.spices[2] > first.spices[2])
//         throw exception("Spice array does not contain enough of spices");
//     auto green = first.spices[2] - other.spices[2];

//     if (other.spices[3] > first.spices[3])
//         throw exception("Spice array does not contain enough of spices");
//     auto brown = first.spices[3] - other.spices[3];

//     return SpiceArray({yellow, red, green, brown});
// }

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
#pragma warning(push)
#pragma warning(disable : 4715)
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
#pragma warning(pop)
    const bool operator==(const SpiceArray &other)
        const
    {

        return this->spices[0] == other.spices[0] &&
               this->spices[1] == other.spices[1] &&
               this->spices[2] == other.spices[2] &&
               this->spices[3] == other.spices[3];
    }
    const bool operator!=(const SpiceArray &other)
        const
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
    void operator+=(const SpiceArray &other)
    {
        this->spices[0] += other.spices[0];
        this->spices[1] += other.spices[1];
        this->spices[2] += other.spices[2];
        this->spices[3] += other.spices[3];
    }

    void operator-=(const SpiceArray &other)
    {
        if (other.spices[0] > this->spices[0])
            throw exception("Spice array does not contain enough of spices");
        this->spices[0] -= other.spices[0];

        if (other.spices[1] > this->spices[1])
            throw exception("Spice array does not contain enough of spices");
        this->spices[1] -= other.spices[1];

        if (other.spices[2] > this->spices[2])
            throw exception("Spice array does not contain enough of spices");
        this->spices[2] -= other.spices[2];

        if (other.spices[3] > this->spices[3])
            throw exception("Spice array does not contain enough of spices");
        this->spices[3] -= other.spices[3];
    }
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
    };

    const unsigned CountSpices() const
    {
        return spices[0] + spices[1] + spices[2] + spices[3];
    }

    const unsigned Value() const
    {
        return spices[0] + spices[1] * 2 + spices[2] * 3 + spices[3] * 4;
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
#ifndef board_h
#define board_h
#pragma once
#include <fstream>
#include <vector>
#include <sstream>

#include "lib/engine/cards/card_base.h"
#include "lib/engine/cards/points_card.h"
#include "lib/engine/cards/income_card.h"
#include "lib/engine/cards/upgrade_card.h"
#include "lib/engine/cards/trade_card.h"

bool CheckIfValueIsAllowed(char character, bool allow_numbers = false)
{
    const char allowed_json_characters[7] = {
        '"',
        '{',
        '}',
        '[',
        ']',
        ':',
        ','};

    const char allowed_spice_characters[4] = {
        'y',
        'r',
        'g',
        'b',
    };

    const char allowed_number_characters[10] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
    };

    for (auto c : allowed_json_characters)
    {
        if (character == c)
            return true;
    }

    for (auto c : allowed_spice_characters)
    {
        if (character == c)
            return true;
    }

    if (allow_numbers)
        for (auto c : allowed_number_characters)
        {
            if (character == c)
                return true;
        }

    return false;
}

vector<string> LoadCardInfo(string path, bool allow_numbers)
{
    vector<string> data;
    std::ifstream file(path);

    string word = "";
    typedef std::istream_iterator<char> CharIter;
    for (CharIter it(file); it != CharIter(); ++it)
    {
        char c = *it;

        if (CheckIfValueIsAllowed(c, allow_numbers))

            switch (c)
            {
            case ',':
            case ':':
                // delim character
                data.push_back(word);
                word = "";

                break;

            case '"':
            case '{':
            case '}':
            case '[':
            case ']':
                break;

            default:
                word.push_back(c);
                break;
            }
    }

    data.push_back(word);

    file.close();
    return data;
}
class Board
{
public:
    Board()
    {
        // load cards from file

        auto trading_cards_data = LoadCardInfo("wiki/trading_cards.json", false);
        for (size_t i = 0; i < trading_cards_data.size(); i += 2)
        {
            this->trading_cards.push_back(TradeCard(SpiceArray(trading_cards_data[i]), SpiceArray(trading_cards_data[i + 1])).Clone());
        }

        for (auto word : LoadCardInfo("wiki/income_cards.json", false))
        {
            this->trading_cards.push_back(IncomeCard(SpiceArray(word)).Clone());
        }

        auto point_cards_data = LoadCardInfo("wiki/points_cards.json", true);
        for (size_t i = 0; i < point_cards_data.size(); i += 2)
        {
            this->points_cards.push_back(PointsCard(SpiceArray(point_cards_data[i]), stoi(point_cards_data[i + 1])));
        }
        // singular upgrade 3 card
        trading_cards.push_back(&UpgradeCard(3));
        // TODO randomize order of both points and trading cards
        
        // lay out cards
        for (unsigned i = 0; i < table_length_; i++)
        {
            laid_out_trading_cards.push_back(this->trading_cards[i]->Clone());
            laid_out_points_cards.push_back(this->points_cards[i]);
            bonus_spices.push_back(SpiceArray());
        }
    };
    ~Board()
    {

        for (auto i = this->trading_cards.size(); i--;)
        {
            delete this->trading_cards[i];
        }

        for (auto i = this->laid_out_trading_cards.size(); i--;)
        {
            delete this->laid_out_trading_cards[i];
        }
    }

    void Show()
    {
        printf("Board state\n");
        printf("Points Cards:\t");
        for (unsigned i = 0; i < table_length_; i++)
        {
            printf(this->laid_out_points_cards[i].Show().c_str());
            printf(" ");
            if (i == table_length_ - 1)
            {
                printf("+ ");
                printf(ft(3, FGC::BrightYellow).c_str());
            }
            if (i == table_length_ - 2)
            {
                printf("+ ");
                printf(ft(1, FGC::BrightYellow).c_str());
            }
            printf("\t\t");
        }

        printf("\nTrading Cards:\t");
        for (unsigned i = 0; i < table_length_; i++)
        {
            printf(this->laid_out_trading_cards[i]->Show().c_str());
            printf(" ");
            if (bonus_spices[i] != SpiceArray({0, 0, 0, 0}))
            {
                printf("+ ");
                printf(this->bonus_spices[i].show().c_str());
            }
            printf("\t\t");
        }
    }
    vector<CardBase *> trading_cards;
    vector<PointsCard> points_cards;

    vector<CardBase *> laid_out_trading_cards;
    vector<PointsCard> laid_out_points_cards;
    vector<SpiceArray> bonus_spices;

    unsigned TableLength() { return table_length_; }

    CardBase *GetTradingCard(const unsigned card_id)
    {
        if (card_id > this->TableLength())
            return nullptr;

        return laid_out_trading_cards[card_id]->Clone();
    }

    PointsCard GetPointsCard(const unsigned card_id)
    {
        // rase index error
        return laid_out_points_cards[card_id];
    }

    void RemoveTradingCard(const unsigned card_id)
    {
        if (card_id > this->TableLength())
            return;

        delete laid_out_trading_cards[card_id];

        if (card_id > 0)
            // move all cards with their bonus spices to the "right"
            for (int i = card_id; i >= 1; i--)
            {
                cout << i;
                laid_out_trading_cards[i] = laid_out_trading_cards[i - 1];
                bonus_spices[i] = bonus_spices[i - 1];
            }

        bonus_spices[0] = SpiceArray();
        laid_out_trading_cards[0] = trading_cards[trading_cards.size() - 1]->Clone();

        delete trading_cards[trading_cards.size() - 1];
    }
    void RemovePointsCard(const unsigned card_id)
    {
        if (card_id > this->TableLength())
            return;

        if (card_id > 0)
            // move all cards to the "right"
            for (int i = card_id; i >= 1; i--)
            {

                laid_out_points_cards[i] = laid_out_points_cards[i - 1];
            }

        laid_out_points_cards[0] = points_cards[points_cards.size() - 1];
    }
    CardBase *PopPointsCard(const unsigned card_id)
    {
        if (card_id > this->TableLength())
            return nullptr;

        return laid_out_trading_cards[card_id]->Clone();
    }

private:
    const unsigned table_length_ = 5;
};
#endif
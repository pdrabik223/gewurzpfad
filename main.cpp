#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <array>
#include <initializer_list>

#include "lib/console_tools/console_tools.h"
#include "lib/engine/spice_array.h"
#include "lib/engine/cards/card_base.h"
#include "lib/engine/cards/points_card.h"
#include "lib/engine/cards/income_card.h"
#include "lib/engine/cards/upgrade_card.h"
#include "lib/engine/cards/trade_card.h"

#include "lib/engine/board.h"
#include "lib/engine/hand.h"

using namespace std;

namespace Engine
{

    // buy card
    void BuyTradingCard(Board &board, Hand &hand, const OrderedSpiceArray &cost)
    {
        if (cost.Count() > board.TableLength())
            return;

        CardBase *bout_card = board.GetTradingCard(cost.Count());
        SpiceArray bonus_spices = board.bonus_spices[cost.Count()];

        // pay for the card
        for (int i = 0; i < cost.spices_.size(); i++)
        {
            board.bonus_spices[i][cost.spices_[i]]++;
        }
        // remove card from table, and move cards around

        board.RemoveTradingCard(cost.Count());

        // add card and bonus spices to user's hand

        hand.held_spices += bonus_spices;
        hand.active.push_back(bout_card);
    }
    void BuyPointsCard(Board &board, Hand &hand, const unsigned id)
    {
        if (id > board.TableLength())
            return;

        PointsCard bout_card = board.GetPointsCard(id);

        unsigned bonus_points = 0;

        if (id == board.TableLength() - 1)
            bonus_points += 3;

        else if (id == board.TableLength() - 2)
            bonus_points += 1;

        SpiceArray cost = bout_card.cost;

        // pay for the card
        try
        {
            hand.held_spices -= bout_card.cost;
        }
        catch (exception ex)
        {
        }
        // remove card from table, and move cards around

        board.RemovePointsCard(id);

        // add card and bonus spices to user's hand
        cout<<bout_card.points;

        hand.held_coins += bout_card.points + bonus_points;
    }
    // sleep
    // use card

};

int main()
{

    auto board = Board();
    board.Show();
    printf("\n\n");
    Hand hand1({
                   &UpgradeCard(2),
                   &IncomeCard({2, 0, 0, 0}),
               },
               {10, 10, 10, 10});
    //
    hand1.Show();
    Engine::BuyPointsCard(board, hand1, 4);

    printf("\n\n");
    board.Show();

    printf("\n\n");
    hand1.Show();

    return 0;
}
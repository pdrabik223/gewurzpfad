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

        // add card points

        hand.held_coins += bout_card.points + bonus_points;
    }
    // sleep
    void Rest(Hand &hand)
    {
        for (auto card_ptr : hand.resting_cards)
        {
            hand.active.push_back(card_ptr);
            card_ptr = nullptr;
        }
        hand.resting_cards.clear();
    }
    // use card
    void UseUpgradeCard(Hand &hand, unsigned card_id, const SpiceArray upgrade_spices = SpiceArray(), const SpiceArray upgrade_spices_result = SpiceArray())
    {
        if (upgrade_spices.CountSpices() == 0)
            return;

        if (upgrade_spices_result.CountSpices() == 0)
            return;

        if (upgrade_spices_result == upgrade_spices)
            return;

        if (upgrade_spices_result.Value() - upgrade_spices.Value() > static_cast<UpgradeCard *>(hand.active[card_id])->upgrade_level)
            return;

        hand.held_spices -= upgrade_spices;
        hand.held_spices += upgrade_spices_result;

        hand.resting_cards.push_back(hand.active[card_id]);
        hand.active[card_id] = nullptr;
        hand.active.erase(hand.active.begin() + card_id);
    }
    void UseTradeCard(Hand &hand, unsigned card_id, unsigned no_uses = 1)
    {
        auto card_cost = static_cast<TradeCard *>(hand.active[card_id])->cost;
        auto spices_copy = hand.held_spices;
        auto iterations = 0;
        for (int i = 0; i < no_uses; i++)
        {
            try
            {
                spices_copy -= card_cost;
            }
            catch (exception)
            {
                break;
            }
            iterations++;
        }

        if (iterations == 0)
            return;

        for (int i = 0; i < iterations; i++)
        {
            hand.held_spices -= card_cost;
        }

        hand.resting_cards.push_back(hand.active[card_id]);
        hand.active[card_id] = nullptr;
        hand.active.erase(hand.active.begin() + card_id);
    }

    void UseCard(Hand &hand, unsigned card_id, unsigned no_uses = 1, const SpiceArray upgrade_spices = SpiceArray(), const SpiceArray upgrade_spices_result = SpiceArray())
    {
        switch (hand.active[card_id]->GetCardType())
        {
        case CardType::INCOME_CARD:
            hand.held_spices += static_cast<IncomeCard *>(hand.active[card_id])->income;

            hand.resting_cards.push_back(hand.active[card_id]);
            hand.active[card_id] = nullptr;
            hand.active.erase(hand.active.begin() + card_id);
            break;

        case CardType::TRADE_CARD:
            UseTradeCard(hand, card_id, no_uses);
            break;

        case CardType::UPGRADE_CARD:
            UseUpgradeCard(hand, card_id, upgrade_spices, upgrade_spices_result);
            break;

        default:
            throw exception("error, incorrect card");
        }
    }

};

// Add error handling to every function in Engine stack
// Make main game loop function for testing purposes
// Some Simple UI would be nice -> we can leverage AI I guess

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
    Engine::UseCard(hand1, 1);
    printf("\n\n");
    hand1.Show();
    Engine::Rest(hand1);
    printf("\n\n");
    hand1.Show();

    Engine::UseCard(hand1, 0, 1, {1, 0, 0, 0}, {0, 0, 1, 0});
    printf("\n\n");
    hand1.Show();

    return 0;
}
#ifndef game_state_h
#define game_state_h
#pragma once    
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <array>
#include <initializer_list>
#include "../console_tools/console_tools.h"
#include "spice_array.h"
#include "cards/card.h"
#include "cards/points_card.h"
#include "cards/income_card.h"
#include "cards/upgrade_card.h"
#include "hand.h"
using namespace std;

class GameState
{
public:
    vector<Hand> players;
    vector<CardBase*> displayed_trade_cards;
    vector<PointsCard> displayed_points_cards;
    unsigned round_index = 0;

    // game begin constructor
    GameState(unsigned no_players)
    {
        unsigned first_hand[4] = {3, 0, 0, 0};
        unsigned second_hand[4] = {4, 0, 0, 0};
        unsigned forth_hand[4] = {4, 1, 0, 0};

        switch (no_players)
        {
        case 2:
            players = {Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, first_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand)};
            break;
        case 3:
            players = {Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, first_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand)};
            break;
        case 4:
            players = {
                Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, first_hand),
                Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand),
                Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand),
                Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, forth_hand),
            };
            break;
        case 5:
            players = {Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, first_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, second_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, forth_hand),
                       Hand({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, forth_hand)};
            break;
        default:
            throw invalid_argument("no_players must be in range <2,5>");
        }
    }
    void displayGameState()
    {
    }
};
#endif
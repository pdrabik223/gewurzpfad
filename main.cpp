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

#include "lib/engine/hand.h"
using namespace std;

int main()
{
    Hand hand1({&UpgradeCard(2),
                &IncomeCard({2, 0, 0, 0}),
                &PointsCard({2, 3, 4, 5}, 5),
                &TradeCard({2, 3, 4, 5}, {2, 3, 4, 5})},
               {4, 1, 0, 0});

    hand1.Show();

    return 0;
}
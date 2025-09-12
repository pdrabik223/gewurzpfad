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
#include "lib/engine/hand.h"
using namespace std;

int main()
{
    IncomeCard ic({2, 0, 0, 0});

    Hand hand1({&UpgradeCard(2), &ic}, {4, 1, 0, 0});

    printf("Player 1\n");
    printf("Spices:\t");
    printf(hand1.held_spices.show().c_str());
    printf("\n");
    printf("Points:\t");
    printf(ft(12, FGC::BrightYellow, BGC::Black).c_str());
    printf(" Active cards:\n");

    for (auto card : hand1.active)
    {
        printf(card->Show().c_str());
        printf("\t");
    }

    return 0;
}
// #include <json/value.h>
// #include <fstream>

// std::ifstream people_file("people.json", std::ifstream::binary);
// Json::Value people;
// people_file >> people;

// cout<<people; //This will print the entire json object.

// //The following lines will let you access the indexed objects.
// cout<<people["Anna"]; //Prints the value for "Anna"
// cout<<people["ben"]; //Prints the value for "Ben"
// cout<<people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

// cout<<people["profession"]; //N
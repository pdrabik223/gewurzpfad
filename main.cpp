#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <array>
#include <initializer_list>
#include "lib/console_tools/console_tools.h"
#include "lib/engine/spice_array.h"
#include "lib/engine/cards/card.h"
#include "lib/engine/cards/points_card.h"
#include "lib/engine/cards/income_card.h"
#include "lib/engine/cards/upgrade_card.h"
#include "lib/engine/hand.h"
using namespace std;
// format text using



int main()
{

    Hand hand1({&UpgradeCard(2), &IncomeCard({2, 0, 0, 0})}, {4, 1, 0, 0});

    printf("Player 1\n");
    printf("Spices:\t");
    printf(hand1.held_spices.show().c_str());
    printf("\n");
    printf("Points:\t");
    printf(ft(12, FGC::BrightYellow, BGC::Black).c_str());
    printf(" Active cards:  ");

    for (Card *card : hand1.active)
    {
        printf(card->show().c_str());
        printf("  ");
    }
    // printf("hand1\n");
    // printf("\033[3;43;30m0\033[0m ");
    // printf("\033[3;43;30m1\033[0m ");
    // printf("\033[3;43;30m2\033[0m ");
    // printf("\033[3;43;30m3\033[0m ");

    // printf("\x1B[31mTexting\033[0m\t\t");
    // printf("\x1B[32mTexting\033[0m\t\t");
    // printf("\x1B[33mTexting\033[0m\t\t");
    // printf("\x1B[34mTexting\033[0m\t\t");
    // printf("\x1B[35mTexting\033[0m\n");

    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[37mTexting\033[0m\t\t");
    // printf("\x1B[93mTexting\033[0m\n");

    // printf("\033[3;42;30mTexting\033[0m\t\t");
    // printf("\033[3;43;30mTexting\033[0m\t\t");
    // printf("\033[3;44;30mTexting\033[0m\t\t");
    // printf("\033[3;104;30mTexting\033[0m\t\t");
    // printf("\033[3;100;30mTexting\033[0m\n");

    // printf("\033[3;47;35mTexting\033[0m\t\t");
    // printf("\033[2;47;35mTexting\033[0m\t\t");
    // printf("\033[1;47;35mTexting\033[0m\t\t");
    // printf("\t\t");
    // printf("\n");
    // cout << BG::Black;
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
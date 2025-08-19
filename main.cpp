#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
// format text using

namespace FGC
{

    const char *Black = "30";
    const char *Red = "31";
    const char *Green = "32";
    const char *Yellow = "33";
    const char *Blue = "34";
    const char *Magenta = "35";
    const char *Cyan = "36";
    const char *White = "37";
    const char *BrightBlack = "90";
    const char *BrightRed = "91";
    const char *BrightGreen = "92";
    const char *BrightYellow = "93";
    const char *BrightBlue = "94";
    const char *BrightMagenta = "95";
    const char *BrightCyan = "96";
    const char *BrightWhite = "97";
}
namespace BGC
{
    const char *Black = "40";
    const char *Red = "41";
    const char *Green = "42";
    const char *Yellow = "43";
    const char *Blue = "44";
    const char *Magenta = "45";
    const char *Cyan = "46";
    const char *White = "47";
    const char *BrightBlack = "100";
    const char *BrightRed = "101";
    const char *BrightGreen = "102";
    const char *BrightYellow = "103";
    const char *BrightBlue = "104";
    const char *BrightMagenta = "105";
    const char *BrightCyan = "106";
    const char *BrightWhite = "107";
};
namespace TEF
{
    const char *Default = "0"; // 1
    const char *Bright = "0";  // 1
    const char *ItalicBright = "3";
    const char *BrightUnderlined = "4";
    const char *AnimatedDimming = "5"; // 6
    const char *ReversedBGFGColors = "7";
    const char *NoDisplayOrBlack = "8";
    const char *LineInTheMiddle = "9";

}

// Name            FG  BG
// Black           30  40
// Red             31  41
// Green           32  42
// Yellow          33  43
// Blue            34  44
// Magenta         35  45
// Cyan            36  46
// White           37  47
// Bright Black    90  100
// Bright Red      91  101
// Bright Green    92  102
// Bright Yellow   93  103
// Bright Blue     94  104
// Bright Magenta  95  105
// Bright Cyan     96  106
// Bright White    97  107

string
ft(string text, const char *foreground_color = FGC::White, const char *background_color = BGC::Black)
{
    string resp("\033[0;");
    resp.append(foreground_color);
    resp.append(";");
    resp.append(background_color);
    resp.append("m");
    resp.append(text);
    resp.append("\033[0m");
    return resp;
};

enum Spice
{
    Yellow = 0,
    Red = 1,
    Green = 2,
    Brown = 3

};

enum Coins
{
    Silver = 1,
    Gold = 3

};

class Card
{
};
class TradeCard : public Card
{

    TradeCard(vector<Spice> cost, vector<Spice> result)
    {
    }
};
class IncomeCard : public Card
{
public:
    vector<Spice> income;
    IncomeCard(vector<Spice> result) : income(result) {}
};

class PointsCard : public Card
{
public:
    PointsCard(vector<Spice> cost) {}
};

class UpgradeCard : public Card
{
public:
    UpgradeCard(int upgrade_level) {}
};

class Hand
{
public:
    vector<Card> active;
    vector<Card> resting_cards;
    vector<Spice> held_spices;
    vector<Coins> held_coins;

    unsigned currentPoints()
    {
        return 12;
    };

    Hand(vector<Card> active,
         vector<Spice> held_spices)
    {
        this->active = active;
        this->held_spices = held_spices;
    }
};

class GameState
{
public:
    vector<Hand> players;
    vector<Card> displayed_trade_cards;
    vector<PointsCard> displayed_points_cards;
    unsigned round_index = 0;

    // game begin constructor
    GameState(unsigned no_players)
    {
        switch (no_players)
        {
        case 2:
            players = {Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow})};
            break;
        case 3:
            players = {Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow})};
            break;
        case 4:
            players = {
                Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Red}),
            };
            break;
        case 5:
            players = {Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Yellow}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Red}),
                       Hand({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow, Spice::Red})};
            break;
        default:
            throw invalid_argument("no_players must be in range <2,5>");
        }
    }
    void displayGameState()
    {
    }
};

int main()
{

    Hand hand1({UpgradeCard(2), IncomeCard({Spice::Yellow, Spice::Yellow})}, {Spice::Yellow, Spice::Yellow, Spice::Yellow});

    // printf("hand1\n");
    // printf("\033[3;43;30m0\033[0m ");
    // printf("\033[3;43;30m1\033[0m ");
    // printf("\033[3;43;30m2\033[0m ");
    // printf("\033[3;43;30m3\033[0m ");
    printf(ft("test", FGC::Yellow, BGC::Black).c_str());

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
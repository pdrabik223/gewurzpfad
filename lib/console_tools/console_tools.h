#ifndef console_tools_h
#define console_tools_h
#pragma once

#include <sstream>
using namespace std;

namespace FGC 
{

    static const char *Black = "30";
    static const char *Red = "31";
    static const char *Green = "32";
    static const char *Yellow = "33";
    static const char *Blue = "34";
    static const char *Magenta = "35";
    static const char *Cyan = "36";
    static const char *White = "37";
    static const char *BrightBlack = "90";
    static const char *BrightRed = "91";
    static const char *BrightGreen = "92";
    static const char *BrightYellow = "93";
    static const char *BrightBlue = "94";
    static const char *BrightMagenta = "95";
    static const char *BrightCyan = "96";
    static const char *BrightWhite = "97";
}
namespace BGC
{
    static const char *Black = "40";
    static const char *Red = "41";
    static const char *Green = "42";
    static const char *Yellow = "43";
    static const char *Blue = "44";
    static const char *Magenta = "45";
    static const char *Cyan = "46";
    static const char *White = "47";
    static const char *BrightBlack = "100";
    static const char *BrightRed = "101";
    static const char *BrightGreen = "102";
    static const char *BrightYellow = "103";
    static const char *BrightBlue = "104";
    static const char *BrightMagenta = "105";
    static const char *BrightCyan = "106";
    static const char *BrightWhite = "107";
};
namespace TEF
{
    static const char *Default = "0"; // 1
    static const char *Bright = "0";  // 1
    static const char *ItalicBright = "3";
    static const char *BrightUnderlined = "4";
    static const char *AnimatedDimming = "5"; // 6
    static const char *ReversedBGFGColors = "7";
    static const char *NoDisplayOrBlack = "8";
    static const char *LineInTheMiddle = "9";

}


string ft(string text, const char *foreground_color = FGC::White, const char *background_color = BGC::Black);

string ft(int value, const char *foreground_color = FGC::White, const char *background_color = BGC::Black);


#endif
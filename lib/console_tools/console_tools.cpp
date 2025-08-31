#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <array>
#include <initializer_list>

#include "console_tools.h"
using namespace std;

string
ft(string text, const char *foreground_color, const char *background_color)
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

string
ft(int value, const char *foreground_color, const char *background_color)
{
    return ft(to_string(value), foreground_color, background_color);
};

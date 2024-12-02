#include "ui.h"
#include <iostream>
#include <string>

std::string createLine(char ch, int width) {
    return std::string(width, ch);
}

std::string centerText(const std::string& text, int width) {
    int spaces = (width - text.length()) / 2;
    return std::string(spaces, ' ') + text + std::string(spaces, ' ');
}

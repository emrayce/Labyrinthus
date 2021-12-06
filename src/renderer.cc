#include "renderer.h"

#include <iostream>

using namespace std;

string Renderer::createPixel(char c) {
    string pixel = "";
    switch (c) {
        case '#':
            pixel += "22-0-0";
            break;
        case ' ':
            pixel += "209-0-0";
            break;
        default:
            pixel += "255-0-0";
    }

    return pixel;
}

void Renderer::setScreenFromMapCell(MapCell mapCell) {
    for (size_t row = 0; row < WIDTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            string pixel = createPixel(mapCell.getChar(row, col));
            setPixel(row, col, pixel);
        }
    }
}

void Renderer::setPixel(size_t row, size_t col, string pixel) {
    if (row < WIDTH && col <= LENGTH) {
        screen.at(row * LENGTH + col) = pixel;
    }
}

string Renderer::getPixel(size_t row, size_t col) {
    return screen.at(row * LENGTH + col);
}

string Renderer::resetFlags() {
    string flags = ESC + "0m";
    cout << ESC << "0m";

    return flags;
}

string Renderer::resetCursor
string Renderer::getBackgroundColor(string pixel) {
    size_t pos = pixel.find("-");

    string background = pixel.substr(0, pos);
    //cout << background << endl;

    return background;
}

string Renderer::getForeGroundColor(string pixel) {
    size_t pos1 = pixel.find("-");
    size_t pos2 = pixel.rfind("-");

    string foreground = pixel.substr(pos1 + 1, pos2 - pos1);
    //cout << foreground << endl;

    return foreground;
}

string Renderer::getAsciiChar(string pixel) {
    size_t pos = pixel.rfind("-");

    string ascii = pixel.substr(pos + 1);
    //cout << ascii << endl;

    return ascii;
}

string Renderer::setBgColor(string colorID) {
    string bgColor = "";
    bgColor += ESC + "48;5;" + colorID + "m";

    cout << ESC << "48;5;" << colorID << "m";
    return bgColor;
}

string Renderer::setFgColor(string colorID) {
    string fgColor = "";
    fgColor += ESC + "38;5;" + colorID + "m";

    cout << ESC << "38;5;" << colorID << "m";

    return fgColor;
}

void Renderer::displayLine(size_t row) {
    string to_display = "";
    to_display += ESC + to_string(row) + ";OH";                  // set the cursor at the start of the row
    cout << ESC << row+1 << ";1H";

    for (size_t col = 0; col < LENGTH; col++) {
        string bgColor = getBackgroundColor(getPixel(row, col));
        string fgColor = getBackgroundColor(getPixel(row, col));
        string ascii = getAsciiChar(getPixel(row, col));

        to_display += setBgColor(bgColor);
        to_display += setFgColor(fgColor);
        to_display += ascii;
        cout << ascii;
    }

    resetFlags();

    //cout << to_display;
}

void Renderer::display() {
    cout << ESC << "2J";
    for (size_t row = 0; row < WIDTH; row++) {
        displayLine(row);
    }
}

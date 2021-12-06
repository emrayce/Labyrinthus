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


void Renderer::displayLine(size_t row) {
    string to_display = "";
    to_display += ESC + to_string(row) + ";OH";                  // set the cursor at the start of the row
    cout << ESC << row+1 << ";1H";

    for (size_t col = 0; col < LENGTH; col++) {
        string bgColor = getBgColor(getPixel(row, col));
        string fgColor = getBgColor(getPixel(row, col));
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

    resetFlags();
    resetCursor();
}

/*
*   Basic and useful methods for others renderer methods
*/

#include "renderer.h"

#include <iostream>

using namespace std;

// Reset all flags (eg: fg/bg color)
string Renderer::resetFlags() {
    string flags = ESC + "0m";
    cout << ESC << "0m";

    return flags;
}

// Reset the cursor position to 22;0 after the map display
string Renderer::resetCursor() {
    string cursor = ESC + to_string(DEFAULT_ROW) + ";0H";
    cout << ESC << DEFAULT_ROW << ";0H";

    return cursor;
}


/*
 * The following 3 methods are used to retrieve info from a pixel:
 *      - Background color
 *      - Foreground color
 *      - Ascii character
*/
string Renderer::getBgColor(string pixel) {
    size_t pos = pixel.find("-");

    string background = pixel.substr(0, pos);

    return background;
}

string Renderer::getFgColor(string pixel) {
    size_t pos1 = pixel.find("-");
    size_t pos2 = pixel.rfind("-");

    string foreground = pixel.substr(pos1 + 1, pos2 - pos1);

    return foreground;
}

string Renderer::getAsciiChar(string pixel) {
    size_t pos = pixel.rfind("-");

    string ascii = pixel.substr(pos + 1);

    return ascii;
}

/*
* The following 2 methods are used to set up pixel data:
*       - Background color
*       - Foreground color
*/
string Renderer::setBgColor(string colorID) {
    string bgColor = "";
    bgColor += ESC + "48;5;" + colorID + "m";

    cout << ESC << "48;5;" << colorID << "m";
    return bgColor;
}

string Renderer::setFgColor(string colorID) {
    string fgColor = ESC + "38;5;" + colorID + "m";

    cout << ESC << "38;5;" << colorID << "m";

    return fgColor;
}

// GETTER SETTER FOR SCREEN
void Renderer::setPixel(size_t row, size_t col, string pixel) {
    if (row < WIDTH && col <= LENGTH) {
        screen.at(row * LENGTH + col) = pixel;
    }
}

string Renderer::getPixel(size_t row, size_t col) {
    return screen.at(row * LENGTH + col);
}

// Delete line specified by row
string Renderer::deleteLine(size_t row) {
    string del = ESC + to_string(row) + ";0H";
    del += ESC + "2K";
    cout << ESC << row << ";0H" << ESC << "2K";

    return del;
}


void Renderer::debug() {
    for (size_t row = 0; row < WIDTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            cout << getPixel(row, col) << "|";
        }
        cout << endl;
    }
}

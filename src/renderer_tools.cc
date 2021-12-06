/*
*   Basic and useful methods for others renderer methods
*/

#include "renderer.h"

#include <iostream>

using namespace std;

// Reset all flags (eg: fg/bg color)
void Renderer::resetFlags() {
    cout << ESC << "0m";
}

// Reset the cursor position to 22;0 after the map display
void Renderer::resetCursor() {
    cout << ESC << DEFAULT_ROW << ";0H";
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
void Renderer::setBgColor(string colorID) {
    cout << ESC << "48;5;" << colorID << "m";
}

void Renderer::setFgColor(string colorID) {
    cout << ESC << "38;5;" << colorID << "m";
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
void Renderer::deleteLine(size_t row) {
    cout << ESC << row + 1<< ";0H" << ESC << "2K";
}


void Renderer::debug() {
    for (size_t row = 0; row < WIDTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            cout << getPixel(row, col) << "|";
        }
        cout << endl;
    }
}

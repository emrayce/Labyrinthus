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

// Add inside the map
// We don't need the value only the key
// Because we only want the unicity
void Renderer::insertLineToDisplay(size_t row) {
    to_display[row];
}

// Add the entire map in to_display
// Usually used when change of map occures
void Renderer::insertAllLinesToDisplay() {
    for (size_t i = 0; i < WIDTH; i++) {
        to_display[i];
    }
}

void Renderer::cleanToDisplay() {
    to_display.clear();
}

void Renderer::clearScreen() {
    cout << ESC << "2J";
}

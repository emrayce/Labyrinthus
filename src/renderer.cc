#include "renderer.h"

#include <unistd.h>
#include <iostream>

using namespace std;

// Disable raw mode by resetting the original terminal
void Renderer::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Set raw mode for the terminal
// Disable ECHO and canonical mode
void Renderer::enableRawMode() {
    tcgeattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

string Renderer::createPixel(char c) {
    string pixel = "";
    switch (c) {
        case '#':
            pixel += "22-0- ";
            break;
        case ' ':
            pixel += "209-0- ";
            break;
        case 'P':
            pixel += "2-0- ";
            break;
        default:
            pixel += "255-0- ";
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

void Renderer::setPlayer(size_t row, size_t col) {
    string pixel_player = createPixel('P');

    setPixel(row, col, pixel_player);
}


void Renderer::displayLine(size_t row) {
    string to_display = "";
    to_display += ESC + to_string(row) + ";OH";                  // set the cursor at the start of the row
    cout << ESC << row+1 << ";1H";

    for (size_t col = 0; col < LENGTH; col++) {
        string bgColor = getBgColor(getPixel(row, col));
        string fgColor = getFgColor(getPixel(row, col));
        string ascii = getAsciiChar(getPixel(row, col));

        setBgColor(bgColor);
        setFgColor(fgColor);
        cout << ascii;
    }

    resetFlags();
}

void Renderer::display() {
    cout << ESC << "2J";
    for (size_t row = 0; row < WIDTH; row++) {
        deleteLine(row);
        displayLine(row);
    }

    resetFlags();
    resetCursor();
}

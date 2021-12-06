#ifndef RENDERER_H
#define RENDERER_H

#include "map_cell.h"

#include <iostream>
#include <termios.h>

using namespace std;

class Renderer {
    private:
        static const size_t WIDTH = 20;
        static const size_t LENGTH = 55;

        struct termios orig_termios;

        string ESC = "\x1b[";
        size_t DEFAULT_ROW = 22;

        // matrix of all pixels that will be display to the terminals
        // A "pixel" (case of the array) will contain a string in the following format
        // 255-255-C  where c is an ascii character 
        // background color - foreground color - ascii character

        array<string, LENGTH * WIDTH> screen;

        string getBgColor(string pixel);
        string getFgColor(string pixel);
        string getAsciiChar(string pixel);

        void setBgColor(string);
        void setFgColor(string);

        void resetFlags();
        void resetCursor();

        void deleteLine(size_t row);

        void enableRawMode();
        void disableRawMode();

    public:

        // Getter/Setter of pixel of screen
        void setPixel(size_t row, size_t col, string pixel);
        string getPixel(size_t row, size_t col);

        void setScreenFromMapCell(MapCell mapCell);
        string createPixel(char c);

        void setPlayer(size_t row, size_t col);

        void displayLine(size_t row);
        void display();

        void debug();
};

#endif

#ifndef RENDERER_H
#define RENDERER_H

#include "map_cell.h"

#include <iostream>

using namespace std;

class Renderer {
    private:
        static const size_t WIDTH = 20;
        static const size_t LENGTH = 55;

        string ESC = "\x1b[";

        // matrix of all pixels that will be display to the terminals
        // A "pixel" (case of the array) will contain a string in the following format
        // 255-255-255
        // background color - foreground color - ascii character

        array<string, LENGTH * WIDTH> screen;

        string getBackgroundColor(string pixel);
        string getForeGroundColor(string pixel);
        string getAsciiChar(string pixel);

        string setBgColor(string);
        string setFgColor(string);

        string resetFlags();

    public:

        // Getter/Setter of pixel of screen
        void setPixel(size_t row, size_t col, string pixel);
        string getPixel(size_t row, size_t col);

        void setScreenFromMapCell(MapCell mapCell);
        string createPixel(char c);

        void displayLine(size_t row);
        void display();
};

#endif

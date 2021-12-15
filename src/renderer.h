#ifndef RENDERER_H
#define RENDERER_H

#include "map_cell.h"

#include <iostream>
#include <map>

using namespace std;

class Renderer {
    // PRIVATE ATTRIBUTES
    private:
        // Dimensions of screen
        static const size_t WIDTH = 20;
        static const size_t LENGTH = 55;
        static const size_t DEFAULT_ROW = 22;               // Row where we can safely take input
        string ESC = "\x1b[";                  // Basis of every ANSI escape code


        // matrix of all pixels that will be display to the terminals
        // A "pixel" (case of the array) will contain a string in the following format
        // 255-255-C  where c is an ascii character 
        // background color - foreground color - ascii character

        array<string, LENGTH * WIDTH> screen;

        // Map of lines that we need to display
        // 
        map<size_t,char> to_display;

    // PRIVATE METHODS
    private:

        string getBgColor(string pixel);                    // Retrieve Background color from pixel
        string getFgColor(string pixel);                    // Retrieve Foreground color from pixel
        string getAsciiChar(string pixel);                  // Retrieve Ascii character from pixel

        void setBgColor(string colorID);                    // Set colorID as the background color
        void setFgColor(string colorID);                    // Set colorID as the foreground color

        void resetFlags();                                  // Reset all flags
        void resetCursor();                                 // Put the cursor at DEFAULT_ROW

        void deleteLine(size_t row);                        // Delete line row

    // PUBLIC METHODS
    public:

        void setPixel(size_t row, size_t col, string pixel);    // Pixel setter of screen
        string getPixel(size_t row, size_t col);                // Pixel getter of screen

        string createPixel(char c);                             // Create a pixel from input

        void setScreenFromMapCell(MapCell mapCell);             // Create screen from MapCell

        void setPlayer(size_t row, size_t col);                 // Set the player on screen

        void displayLine(size_t row);                           // Display line row of screen
        void display();                                         // Method to call to display screen

        void insertLineToDisplay(size_t row);                   // Add a line to be displayed
        void insertAllLinesToDisplay();                         // Insert all lines to be displayed
        void cleanToDisplay();                                  // Reset to_display

        void clearScreen();
};

#endif

#include <iostream>
#include "game.h"

#include <termios.h>
#include <unistd.h>

using namespace std;

struct termios orig_termios;                        // Store the original config of the terminal

// Disable raw mode by resetting the original terminal
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Set raw mode for the terminal
// This alow to set off specific flags
// Disable ECHO allow to avoid the display of our input
// Disable ICANON (canonical mode) allow to take input without pressing ENTER
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);                               // Call disableRawMode at the end of the program
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();
    //Iinitialization
    Game game("MapTest/");

    // Run
    game.gameLoop();
    //
   //game.display();

    return 0;
}

#include "game.h"

using std::vector;

void initialize() {
   initscr();              // start curses
   raw();                  // let us deal with input immediately
   keypad(stdscr, TRUE);   // let us use arrow/function keys
   noecho();               // don't display everything we type
   start_color();          // use colors!
   curs_set(0);            // don't want cursor everywhere

   // At some point, set up panel system with "panel.h"
   // or maybe just windows are good enough...

   // Also, might be a good idea to do more color set up here
   init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
   init_pair(RED, COLOR_RED, COLOR_BLACK);
   init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
   init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
   init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
   init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
   init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

void terminate() {
   endwin(); // close the main window
}


int main() {
   initialize(); // set up ncurses

   Game g;
   g.loop(); // run the game loop

   terminate(); // exit ncurses and reset everything
   return 0;
}

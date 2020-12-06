#ifndef __INIT_HPP__
#define __INIT_HPP__

#include "ncurses.h"
#include "Test.hpp"

class Initializer {
    public: 
        void run();
    private:
        void show_menu(int row, int col);

};

// void init() {
//             initscr();
//             int row, col;
//             int ch;
//             getmaxyx(stdscr, row, col);
//             nodelay(stdscr, TRUE);
//             keypad(stdscr, TRUE);
//             cbreak();
//             int h, w, y, x;
//             noecho();
//             getmaxyx(stdscr, h, w);
//             for(;;) {
//                 ch = getch();
//                 switch(ch) {
//                     case KEY_BACKSPACE: //user pressed backspace
//                         printw("Pressed backspace\n");
//                         break;
//                     case 10:
//                         printw("Pressed enter\n");
//                         echo();
//                         break;
//                     case KEY_UP:
//                         mvprintw(row-1, (col-10)/2, "pressed up");
//                         noecho();
//                         break;
//                     case KEY_DOWN:
//                         printw("Pressed down\n");
//                         echo();
//                         break;
//                     case 27:
//                         printw("Goodbye\n");
//                         endwin();
//                         return;
//                 }
//             }        

//         }
#endif
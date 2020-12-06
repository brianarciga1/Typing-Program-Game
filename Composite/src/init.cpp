#include "../header/init.hpp"
#include <cstring>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>

void Initializer::run() {
    Test* test = new Test();
    initscr();
    int row, col, ch;

    // gets the size of the terminal
    getmaxyx(stdscr, row, col);

    // lets program run without waiting for a character input
    nodelay(stdscr, TRUE);

    // enables numpad
    keypad(stdscr, TRUE);

    // allows program to take in input immediately
    cbreak();

    // starts with program not echoing user input
    noecho();

    show_menu(row, col);

    std::string a = "asdf";
    // menu loop
    for(;;) {
        // get user input
        ch = getch();
        if(ch > 0) {
            a += static_cast<char>(ch);
        }
        // a += character;
        switch(ch) {
            case 'l':
            {
                erase();
                attron(A_STANDOUT);
                printw("Login is not yet implemented. Press escape to continue.");
                attroff(A_STANDOUT);
                endwin();
                break;
            }
            case 'e':
            {
                erase();
                std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};
                Passage* a = new Passage(row/3, col/4, ref);
                a->set_max_col(3 * col / 4);
                a->display(a->get_row(), a->get_col());
                break;  
            }
            case 'p':
                test->get_text(row, col);
                erase();
                test->run(row, col);
                break;
            case ' ':
            {
                mvaddstr(0, 0, a.c_str());
                move(row - 1,0);
                clrtoeol();
                move(row-1, col/2);
                break;
            }
            case 's': 
            {
                printw(a.c_str());
                break;
            }
            case 'q':
                move(0, 0);
                endwin();
                return;
        }
    }
}



void Initializer::show_menu(int row, int col) {
    mvprintw(0, 0, "TODO: Get info from Observer class");

    char settings_message[] = "TODO: Implement settings";
    mvprintw(0, col - strlen(settings_message), settings_message);

    std::vector<std::string> welcome;
    welcome.push_back("Welcome to our typing test!");
    welcome.push_back("Press L to login/logout. Press P to play. Press S for settings. Pres Q to quit.");
    welcome.push_back("");
    welcome.push_back("Created by Brian Arciga, Danin Namiranian, and Scott Vo");
    for (unsigned i = 0; i < welcome.size(); ++i) {
        mvprintw(row/3 + i, (col-welcome.at(i).size())/2, welcome.at(i).c_str());
    }
}
#include "../header/init.hpp"
#include <cstring>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>

void Initializer::run() {
    TypingTest* test = new TypingTest();
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

    // menu loop
    for(;;) {
        // get user input
        ch = getch();
        // a += character;
        switch(ch) {
            case 'l':
            {
                show_login(row, col);
                show_menu(row, col);
                break;
            }
            case 'p':
                test->get_text(row, col);
                erase();
                test->run(row, col);
                test->display_results(row, col);
                show_menu(row, col);
                break;
            case 's': 
            {
                show_settings(row, col);
                show_menu(row, col);
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
    erase();
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

void Initializer::show_settings(int row, int col) {
    erase();
    attron(A_STANDOUT);
    printw("Settings is not yet implemented. Press any key to continue.");
    attroff(A_STANDOUT);

    int ch = getch();

    while(ch < 1) {
        ch = getch();
    }
}

void Initializer::show_login(int row, int col) {
    erase();
    attron(A_STANDOUT);
    printw("Login is not yet implemented. Press any key to continue.");
    attroff(A_STANDOUT);

    int ch = getch();

    while(ch < 1) {
        ch = getch();
    }
}
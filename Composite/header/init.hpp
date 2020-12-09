#ifndef __INIT_HPP__
#define __INIT_HPP__

#include "ncurses.h"
#include "TypingTest.hpp"

class Initializer {
    public: 
        void run();
    private:
        void show_menu(int row, int col);
        void show_settings(int row, int col); 

};

#endif
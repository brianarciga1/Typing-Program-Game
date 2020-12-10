#ifndef __INIT_HPP__
#define __INIT_HPP__

#include "ncurses.h"
#include "TypingTest.hpp"
#include "../../Observer/header/Observer.hpp"
#include "../../Observer/header/Subject.hpp"
#include "UserList.hpp"

class Initializer {
    public: 
        void run();
    private:
        UserList* data = new UserList();
        void show_menu(int row, int col);
        void show_settings(int row, int col); 
        
};

#endif
#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "ncurses.h"
#include "Passage.hpp"
#include "Text.hpp"
#include "Word.hpp"
#include <string>

class Test {
    private: 
        Passage* body;
    public: 
        void run(int max_row, int max_col);

        void get_text(int max_row, int max_col);

        std::string get_user_input(int row, int col); 
};


#endif
#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "ncurses.h"
#include "Passage.hpp"
#include "Text.hpp"
#include "Word.hpp"
#include <ctime>
#include <string>

class TypingTest {
    private: 
        Passage* body = nullptr;
        int timer;
        bool running = true;
    public: 
        void run(int max_row, int max_col);

        void get_text(int max_row, int max_col);

        std::string get_user_input(int row, int col, time_t start); 

        time_t start_timer();

        void update_timer(time_t start);

        void display_timer(int time, int max_row, int max_col);

        void display_accuracy(int max_col);

        std::string get_accuracy(); 

        void set_body(Passage* p) { body = p; }

        std::string get_wpm(); 

        void display_results(unsigned row, unsigned col); 
};


#endif
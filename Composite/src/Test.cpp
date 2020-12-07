#include "../header/Test.hpp"

void Test::run(int max_row, int max_col) {
    body->set_max_col(3 * max_col / 4);
    body->display(body->get_row(), body->get_col());

    time_t start = start_timer();

    for(unsigned i = body->get_input_size(); i < body->get_ref_size(); ++i) {
        body->add_word(this->get_user_input(max_row, max_col, start));
        body->display(body->get_row(), body->get_col());
    }
}

void Test::get_text(int max_row, int max_col) {
    std::vector<std::string> ref = {"If", "you", "set", "your", "goals", "ridiculously", "high", "and", "it\'s", "a", "failure,", "you", "will", "fail", "above", "everyone", "else\'s", "success."};
    Passage* a = new Passage(max_row/3, max_col/4, ref);
    body = a;
}

std::string Test::get_user_input(int row, int col, time_t start) {
    int ch;
    std::string ret = "";
    for(;;){
        update_timer(start);
        display_timer(timer, row, col);
        ch = getch();
        mvaddstr(5 * (row-1) / 6, (col-ret.size())/2, ret.c_str());
        if (ch >= 33 && ch <= 126) {
            ret += static_cast<char>(ch);
        }
        switch(ch) {
            case ' ':
            {
                move(5 * (row-1) / 6, 0);
                clrtoeol();
                return ret;
            }
            case KEY_BACKSPACE:
            {
                ret.pop_back();
            }
        }
    
    }
}

time_t Test::start_timer() { 
    time_t timer;
    return time(&timer);

}

void Test::update_timer(time_t start) {
    time_t curr_time;
    time(&curr_time);
    timer = difftime(curr_time, start);
}

void Test::display_timer(int time, int max_row, int max_col) {
    mvaddstr(0, max_col/2, std::to_string(time).c_str());
}
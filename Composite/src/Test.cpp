#include "../header/Test.hpp"

void Test::run(int max_row, int max_col) {
    body->set_max_col(3 * max_col / 4);
    body->display(body->get_row(), body->get_col());

    for(unsigned i = body->get_input_size(); i < body->get_ref_size(); ++i) {
        body->add_word(this->get_user_input(max_row - 1, max_col));
        body->display(body->get_row(), body->get_col());
    }
}

void Test::get_text(int max_row, int max_col) {
    std::vector<std::string> ref = {"If", "you", "set", "your", "goals", "ridiculously", "high", "and", "it\'s", "a", "failure,", "you", "will", "fail", "above", "everyone", "else\'s", "success."};
    Passage* a = new Passage(max_row/3, max_col/4, ref);
    body = a;
}

std::string Test::get_user_input(int row, int col) {
    int ch;
    std::string ret = "";
    for(;;){
        ch = getch();
        mvaddstr(5 * row / 6, (col-ret.size())/2, ret.c_str());
        if (ch >= 33 && ch <= 126) {
            ret += static_cast<char>(ch);
        }
        switch(ch) {
            case ' ':
            {
                move(5 * row / 6, 0);
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

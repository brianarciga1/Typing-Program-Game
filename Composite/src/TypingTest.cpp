#include "../header/TypingTest.hpp"

void TypingTest::run(int max_row, int max_col) {

    body->set_max_col(3 * max_col / 4);
    body->display(false, body->get_row(), body->get_col());

    time_t start = start_timer();

    for(unsigned i = body->get_input_size(); i < body->get_ref_size(); ++i) {
        body->add_word(this->get_user_input(max_row, max_col, start));
        if(!running) {
            erase();
            return;
        }
        body->display(false, body->get_row(), body->get_col());
    }
}

void TypingTest::get_text(int max_row, int max_col) {
    std::vector<std::string> ref = {"Iff", "you", "set", "a", "your", "goals"/*, "ridiculously", "high", "and", "it\'s", "a", "failure,", "you", "will", "fail", "above", "everyone", "else\'s", "success."*/};
    Passage* a = new Passage(max_row/3, max_col/4, ref);
    body = a;
}

std::string TypingTest::get_user_input(int row, int col, time_t start) {
    int ch;
    std::string ret = "";
    ch = getch();
    for(;;){
        attron(A_STANDOUT);
        mvaddstr(5 * (row-1) / 6, col/2, ret.c_str());
        attroff(A_STANDOUT);
        update_timer(start);
        display_timer(timer, row, col);
        display_accuracy(col);
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
                move(5 * (row-1)/6, 0);
                clrtoeol();
                if(ret.size() > 0) ret.pop_back();
            }
            case 27:
            {
                running = false;
                return "";
            }
        }
        ch = getch();
    }
    attroff(A_STANDOUT);
}

time_t TypingTest::start_timer() { 
    time_t timer;
    return time(&timer);

}

void TypingTest::update_timer(time_t start) {
    time_t curr_time;
    time(&curr_time);
    timer = difftime(curr_time, start);
}

void TypingTest::display_timer(int time, int max_row, int max_col) {
    mvaddstr(max_row/4, max_col/2, std::to_string(time).c_str());
}

void TypingTest::display_accuracy(int max_col) {
    std::string accuracy = this->get_accuracy();
    mvaddstr(0, (max_col-accuracy.size())/2+1, this->get_accuracy().c_str());
}

std::string TypingTest::get_accuracy() {
    std::string not_truncated = std::to_string(body->get_accuracy() * 100);

    int dec_index = not_truncated.find(".");

    return not_truncated.substr(0, dec_index + 3) + "%";
    
}

std::string TypingTest::get_wpm() {
    double words = body->get_correct_characters() / 5.0;
    double time = timer;

    std::string ret = std::to_string(words / (timer / 60.0));

    int dec_index = ret.find(".");

    return ret.substr(0,dec_index + 3);
}

void TypingTest::display_results(unsigned row, unsigned col) {
    erase();

    int ch = 0;
    
    for (;;) {
        ch = getch();
        if (ch != -1) { return; }
        std::vector<std::string> msg = {"You have completed your typing test. Here are your results:",
                                        "",
                                        "Accuracy: " + get_accuracy(),
                                        get_wpm() + " WPM",
                                        "",
                                        "Press any key to return to menu"};

        for(unsigned i = 0; i < msg.size(); ++i) {
            mvaddstr(row/3+i, (col-msg.at(i).size())/2, msg.at(i).c_str());
        }
    }
}   
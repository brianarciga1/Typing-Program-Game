#include "../header/Word.hpp"

void Word::set_word(std::string input) {
    word = input;
}

void Word::set_reference(std::string input) {
    reference = input;
}

bool Word::check() {
    return word == reference;
}

unsigned Word::len() {
    return reference.size();
}

void Word::display(unsigned row, unsigned col) {
    mvaddstr(row, col, reference.data());
}

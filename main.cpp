#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "curses_mode.hpp"

#define BACK_COLOR 0
#define TEXT_COLOR 207

// abcdefghijklmnopqrstuvwxyz

// alphabet is 26*7*7
void read_font(const char* file, char*** alphabet) {
    std::ifstream fin;
    fin.open(file);

    char trash;
    
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 26; ++j) {
            
            fin.read(alphabet[j][i], 7);
            
        }
        fin.read(&trash, 1);
    }
}

void print_char(char*** alphabet, int i) {

    for (int j = 0; j < 7; ++j) {
        std::cout.write(alphabet[i][j], 7);
        std::cout << '\n';    
    }

}

void look(char*** alphabet) {
    int i;
    while (1) {
        std::cin >> i;
        print_char(alphabet, i);
    }
}

void cpy_char(char** dst, char** src) {
    for (int i = 0; i < 7; ++i) {
        memcpy(dst[i], src[i], 7);
    }
}

void print_text(char*** text, int n) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout.write(text[j][i], 7);
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void add_to_text(char*** text, char*** alphabet, int i, int& place) {
    cpy_char(text[place], alphabet[i]);
    ++place;
}

int main() {

    int n = 7;

    char*** alphabet = new char**[26];

    char*** text = new char**[n];

    for (int i = 0; i < 7*n; ++i) {
        text[i] = new char*[7];
        for (int j = 0; j < 7; ++j) {
            text[i][j] = new char[7];
        }
    }

    for (int i = 0; i < 26; ++i) {
        alphabet[i] = new char*[7];
        for (int j = 0; j < 7; ++j) {
            alphabet[i][j] = new char[7];
        }
    }


    read_font("./fonts/ascii.txt", alphabet);
    // look(alphabet);
    
    int place = 0;

    add_to_text(text, alphabet, 5, place);
    add_to_text(text, alphabet, 20, place);
    add_to_text(text, alphabet, 2, place);
    add_to_text(text, alphabet, 10, place);
    add_to_text(text, alphabet, 8, place);
    add_to_text(text, alphabet, 13, place);
    add_to_text(text, alphabet, 6, place);




    print_rnbwtext(text, n);

    // char*** 


    // char letter[7][8];
    // for (int i = 0; i < 7; ++i) {
    //     letter[i][8] = 0;
    // }
    
    // initscr();


    // move(10, 5); 
    // start_color();



    // for (int i = 0; i <= 256; ++i) {
    //     init_pair(i , i, BACK_COLOR);
    //     attron(COLOR_PAIR(i));
    //     printw(".");
    //     attroff(COLOR_PAIR(i));
    // }
    // refresh();


    // getch();
    // endwin();
    return 0;
}

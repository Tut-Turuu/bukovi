#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "curses_mode.hpp"

#define BACK_COLOR 0


// abcdefghijklmnopqrstuvwxyz

// alphabet is 26*7*7
void read_font(const char* file, char*** alphabet) {
    std::ifstream fin;
    fin.open(file);

    char trash;
    
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 27; ++j) {
            
            fin.read(alphabet[j][i], 7);
            
        }
        fin.read(&trash, 1);
    }
    fin.close();
}

void print_char(char** const * text, int i) {

    for (int j = 0; j < 7; ++j) {
        std::cout.write(text[i][j], 7);
        std::cout << '\n';    
    }

}

void look(char** const * alphabet) {
    int i;
    while (1) {
        std::cin >> i;
        print_char(alphabet, i);
    }
}

void cpy_char(char** dst, char* const * src) {
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

void add_to_text(char*** text, char** const * alphabet, int i, int& place) {
    cpy_char(text[place], alphabet[i]);
    ++place;
}

int char_to_index(const char c) {
    if (c == ' ') return 26;
    return c - 'a';
}

void create_text(char***& text, char** const * alphabet, const char* str, int& n) {
    n = strlen(str);
    text = new char**[n];

    for (int i = 0; i < n; ++i) {
        text[i] = new char*[7];
        for (int j = 0; j < 7; ++j) {
            text[i][j] = new char[7];
        }
    }
    for (int i = 0; i < n; ++i) {
        cpy_char(text[i], alphabet[char_to_index(str[i])]);
    }
}

int main(int argc, char** argv) {

    if (argc != 2) {
        return -1;
    }

    int n;

    char*** text;

    char*** alphabet = new char**[27];

    for (int i = 0; i < 27; ++i) {
        alphabet[i] = new char*[7];
        for (int j = 0; j < 7; ++j) {
            alphabet[i][j] = new char[7];
        }
    }


    read_font("./ascii.txt", alphabet);


    create_text(text, alphabet, argv[1], n);


    print_rnbwtext(text, n);


    return 0;
}

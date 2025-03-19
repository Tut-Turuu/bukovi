#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <fstream>

// color cycle 46 82 118 119 84 48 47


void init_colors(int* colors, int n) {
    for (int i = 0; i < n; ++i) {
        init_pair(i+1, colors[i], 0);
    }
}

void print_rnbwtext(char*** text, int n) {

    int offset = 0;

    initscr();

    curs_set(0);

    start_color();

    
    int colors[] = {196, 160, 166, 202, 208, 172, 178, 214, 220, 184,
                    190, 226, 220, 184, 190, 154, 148, 112, 118, 82, 
                    76, 40, 46, 40, 41, 47, 48, 42, 43, 49, 50, 44, 
                    45, 51, 87, 81, 45, 39, 75, 69, 33, 37, 63, 57, 
                    21, 27, 63, 57, 93, 99, 135, 129, 165, 171, 207, 
                    201, 206, 200, 199, 205, 204, 198, 197, 203, 202};


    // int colors[] = {52, 88, 89, 125, 161, 197, 198, 199, 163, 127, 91, 55, 54, 53};

    const int COLOR_N = sizeof(colors) / 4;

    init_colors(colors, COLOR_N);

    while (1) {


        for (int i = 0; i < 7 * n ; ++i) {
            attron(COLOR_PAIR((i / 10 + offset) % COLOR_N + 1));

            for (int x = 0, y = i; x < 7 && y > -1; --y, ++x) {
                move(x, y + y/7);
                addch(text[y / 7][x][y%7]);
            }
            attroff(COLOR_PAIR((i / 10 + offset) % COLOR_N + 1));
        }

        for (int i = 0; i < 7; ++i) {
            attron(COLOR_PAIR(((7*n + i) / 10 + offset) % COLOR_N + 1));
            for (int x = i, y = 7 * n - 1; x < 7 && y > -1; ++x, --y) {
                move(x, y + y/7); 
                addch(text[y / 7][x][y%7]);

            }
            attroff(COLOR_PAIR(((7*n + i) / 10 + offset) % COLOR_N + 1));
        }


        refresh();
        ++offset;
        
        timespec time_for;
        time_for.tv_nsec = 100'000'000;
        time_for.tv_sec = 0;
        timespec rem;
        rem.tv_nsec = 0;
        rem.tv_sec = 0;
        nanosleep(&time_for, &rem);

        

        // sleep(1);
    }

    endwin();
}
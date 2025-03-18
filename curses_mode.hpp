#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include <time.h>

// color cycle 46 82 118 119 84 48 47
#define COLOR_N 14

void print_rnbwtext(char*** text, int n) {

    int offset = 0;

    initscr();

    start_color();

    
    init_pair(1, 52, 0);
    init_pair(2, 88, 0);
    init_pair(3, 89, 0);
    init_pair(4, 125, 0);
    init_pair(5, 161, 0);
    init_pair(6, 197, 0);
    init_pair(7, 198, 0);
    init_pair(8, 199, 0);
    init_pair(9, 163, 0);
    init_pair(10, 127, 0);
    init_pair(11, 91, 0);
    init_pair(12, 55, 0);
    init_pair(13, 54, 0);
    init_pair(14, 53, 0);


    

    while (1) {


        for (int i = 0; i < 7 * n ; ++i) {
            attron(COLOR_PAIR((i / 4 + offset) % COLOR_N + 1));

            for (int x = 0, y = i; x < 7 && y > 0; --y, ++x) {
                move(x, y + y/7);
                addch(text[y / 7][x][y%7]);
            }
            attroff(COLOR_PAIR((i / 4 + offset) % COLOR_N + 1));
        }

        for (int i = 0; i < 6; ++i) {
            attron(COLOR_PAIR(((7*n + i + offset) / 4) % COLOR_N + 1));
            for (int x = i, y = 7 * n - 1; x < 7 && y > 0; ++x, --y) {
                move(x, y + y/7);
                addch(text[y / 7][x][y%7]);
            }
            attroff(COLOR_PAIR(((7*n + i + offset) / 4) % COLOR_N + 1));
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < 7; ++j) {
        //         attron(COLOR_PAIR((j + offset) % 7));
        //         for (int x = j, y = 0; x > -1; --x, ++y) {
        //             move(x, y + i*8);
        //             addch(text[i][x][y]);
        //         }

        //         for (int x = j+1, y = 6; x < 7; ++x, --y) {
        //             move(x, y + i*8);
        //             addch(text[i][x][y]);
        //         }
        //         attroff(COLOR_PAIR((j + offset) % 7));
        //     } 
        // }
        refresh();
        ++offset;
        
        timespec time_for;
        time_for.tv_nsec = 150'000'000;
        time_for.tv_sec = 0;
        timespec rem;
        rem.tv_nsec = 0;
        rem.tv_sec = 0;
        nanosleep(&time_for, &rem);

        

        // sleep(1);
    }



    endwin();
}
#include <ncurses.h> 
#include <unistd.h>



int main() {


    initscr();

    start_color();

    move(1,10);
    printw("1");


    move(2,2);
    printw("2");

    refresh();

    sleep(10);
    endwin();
}
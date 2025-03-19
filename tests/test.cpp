#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fstream>


int main(int argc, char** argv) {
    char cmd[100];

    memcpy(cmd, "rm -rf ", 7);

    memcpy(cmd + 7, argv[0]+2, strlen(argv[0]) - 1);

    std::cout << cmd;
    system(cmd);

}
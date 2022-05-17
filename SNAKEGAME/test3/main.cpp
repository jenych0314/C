#include <iostream>
// #include <ncurses.h>
#include <curses.h>

using namespace std;

int main()
{
    // cout << "Hello World!";
    initscr();
    printw("Hello World!");
    refresh();
    getch();
    endwin();
}
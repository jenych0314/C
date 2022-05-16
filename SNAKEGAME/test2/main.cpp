#include <iostream>
#include "stdafx.h"

using namespace std;

int main() {
	//cout << "Hello, World!";
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);

	attron(COLOR_PAIR(1));
	printw("Hello World");
	attroff(COLOR_PAIR(1));

	refresh();
	getch();
	endwin();
}
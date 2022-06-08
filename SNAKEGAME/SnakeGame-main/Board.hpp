#pragma once

#include <ncurses.h>
#include "Drawable.hpp"
#include <time.h>
#include <stdlib.h>

class Board
{
public:
    Board()
    {
        construct(0, 0);
    }

    Board(int height, int width)
    {
        construct(height, width);
    }

    void initialize()
    {
        clear();
        refresh();
    }

    void addBorder()
    {
        box(board_win, 0, 0);
    }

    void add(Drawable draw)
    {
        addAt(draw.getX(), draw.getY(), draw.getIcon());
    }

    void addAt(int y, int x, chtype ch) //  (y, x) 좌표에 ch를 넣어준다.
    {
        mvwaddch(board_win, y, x, ch);
    }

    chtype getInput()
    {
        return wgetch(board_win);
    }

    void getEmptyCoordinates(int &y, int &x)
    {
        while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
            ;
    }

    void clear()
    {
        wclear(board_win);
        addBorder();
    }

    void refresh()
    {
        wrefresh(board_win);
    }

private:
    WINDOW *board_win;
    int height, width;

    void construct(int _height, int _width)
    {
        int xMax, yMax;
        height = _height;
        width = _width;

        getmaxyx(stdscr, yMax, xMax); // 현재 화면의 가로 세로 크기를 구한다. 구한후 저장한다

        board_win = newwin(_height, _width, (yMax / 2) - (_height / 2), (xMax / 2) - (_width / 2));

        // add timeout
        wtimeout(board_win, 500);
    }
};
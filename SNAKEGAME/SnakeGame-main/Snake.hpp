#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include <queue>

enum Direction
{
    up,
    down,
    left,
    right
};

class SnakePiece : public Drawable
{
public :
    SnakePiece()
    {
        x = y = 0;
        icon = '#';
    }

    SnakePiece(int _y, int _x)
    {
        x = _x;
        y = _y;
        icon = '#';
    }
};

class Snake
{
private :
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;

public :
    Snake()
    {
        cur_direction = down;
    }

    void addPiece(SnakePiece piece)
    {
        prev_pieces.push(piece);
    }

    void removePiece()
    {
        prev_pieces.pop();
    }

    SnakePiece tail()
    {
        return prev_pieces.front();
    }

    SnakePiece head()
    {
        return prev_pieces.back();
    }

    Direction getDirection()
    {
        return cur_direction;
    }

    void setDirection(Direction d)
    {
        cur_direction = d;
    }

    SnakePiece nextHead()
    {
        int row = head().getY();
        int col = head().getX();

        switch (cur_direction)
        {
            case down:
                row++;
                break;
            case up:
                row--;
                break;
            case left:
                col--;
                break;
            case right:
                col++;
                break;
        }
        return SnakePiece(row, col);
    }
     
};
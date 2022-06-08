#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include <time.h>
#include <stdlib.h>
#include "Empty.hpp"
#include "Snake.hpp"

class SnakeGame
{
public:
    SnakeGame(int height, int width)
    {
        board = Board(height, width);
        initialize();
    }

    ~SnakeGame()
    {
        delete apple;
    }

    void initialize()
    {
        apple = NULL;
        board.initialize();
        game_over = false;
        srand(time(NULL));

        //Todo : Initialize snake class
        snake.setDirection(down);

        SnakePiece next = SnakePiece(1, 1);
        board.add(next);
        snake.addPiece(next);

        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);

        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);

        snake.setDirection(right);

        next = snake.nextHead();
        board.add(next);
        snake.addPiece(next);
    }

    void processInput()
    {
        chtype input = board.getInput();
        // process input
    }

    void updateState()
    {
        //update state
        if (apple == NULL)
        {
            int y, x;
            board.getEmptyCoordinates(y, x);
            apple = new Apple(y, x);
            board.add(Empty(apple -> getY(), apple -> getX()));
            board.add(*apple);
        }

        SnakePiece next = snake.nextHead();
        if (next.getX() != apple -> getX() && next.getX() != apple -> getY())
        {
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();   
        }
        board.add(next);
        snake.addPiece(next);
    }

    void redraw()
    {
        board.refresh();
    }

    bool isOver()
    {
        return game_over;
    }

private:
    Board board;
    bool game_over;
    Apple *apple;

    Snake snake;
};
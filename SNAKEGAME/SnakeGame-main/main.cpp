#include "Board.hpp"
#include "SnakeGame.hpp"
#include "Apple.hpp"
#include "Drawable.hpp"

#define BOARD_DIM 40
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS (BOARD_DIM * 2.5)

int main(int argc, char **argv)
{
    initscr(); // curses모드 시작
    refresh(); // 화면에 찍은 내용을 갱신한다. refresh전에는 출력함수 출력이 안됨

    noecho(); // 타자가 출력되지않도록

    // ToDo:Turn off cursor
    curs_set(0);

    SnakeGame game(BOARD_ROWS, BOARD_COLS);

    while (!game.isOver())
    {
        game.processInput();

        game.updateState();

        game.redraw();
    }

    //   getch();  // 한 문자를 사용자로부터 입력받는다, getchar은 \n 나올때까지, 얘는 한문자만
    endwin(); // curses모드 종료

    return 0;
}
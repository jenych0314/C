#include <iostream>

using namespace std;

int main()
{
    struct POINT
    {
        int x;
        int y;
    };

    struct RECT
    {
        struct POINT LeftTop;
        struct POINT RightBottom;
        int area = (RightBottom.x - LeftTop.x) * (LeftTop.y - RightBottom.y);
    };

    struct RECT a;
    a.LeftTop.x = 10;
    a.LeftTop.y = 100;
    a.RightBottom.x = 50;
    a.RightBottom.y = 15;

    cout << "rect: " << a.area << endl;
}
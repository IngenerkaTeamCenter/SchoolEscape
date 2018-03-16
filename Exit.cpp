#include "TXLib.h"

struct Exit
{

    int x, y;
    HDC Exit;

};

void drawExit(Exit e)
{

    txTransparentBlt(txDC(), e.x - 61, e.y - 10, 123, 21, e.Exit, 0, 0, RGB(0, 159, 60));

}


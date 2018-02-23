#include "TXLib.h"

struct Pitek
{
    int x, y;
    int width;
    int height;
    HDC picDown;
};

void drawPitek(Pitek pi)
{
    txTransparentBlt(txDC(),  pi.x, pi.y, pi.width, pi.height, pi.picDown, 0, 0, RGB(255, 255, 255));
}

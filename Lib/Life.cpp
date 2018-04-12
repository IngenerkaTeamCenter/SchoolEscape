#include "TXLib.h"

struct LifeLane
{
    int x;
    int y;
    int width;
    int height;
    HDC picDown;
};

void drawLifeLane(LifeLane pi)
{
    txTransparentBlt(txDC(),  pi.x, pi.y, pi.width, pi.height, pi.picDown, 0, 0, RGB(255, 255, 255));
}

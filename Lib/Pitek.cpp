#include "TXLib.h"


struct Pitek
{
    int x, y;
    int width;
    int height;
    HDC picDown;
    CrashZone crash;
};

void drawPitek(Pitek pi)
{
    txTransparentBlt(txDC(),  pi.x - pi.width / 2, pi.y - pi.height / 2, pi.width, pi.height, pi.picDown, 0, 0, RGB(255, 255, 255));
}

void fillCrashZone(Pitek* pi)
{
    pi->crash.x1 = pi->x - 90;
    pi->crash.y1 = pi->y - 29;
    pi->crash.x2 = pi->x + 90;
    pi->crash.y2 = pi->y + 40;
}

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
    txTransparentBlt(txDC(),  pi.x, pi.y, pi.width, pi.height, pi.picDown, 0, 0, RGB(255, 255, 255));
}

void fillCrashZone(Pitek* pi)
{
    pi->crash.x1 = pi->x - 27;
    pi->crash.y1 = pi->y - 12;
    pi->crash.x2 = pi->x + 27;
    pi->crash.y2 = pi->y + 12;
}

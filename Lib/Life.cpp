#include "TXLib.h"

struct LifeLane
{
    int x;
    int y;
    int width;
    int height;
    HDC picDown;
};

LifeLane ll;
LifeLane sl;
int energy = 100000;

void drawLifeLane(LifeLane ll)
{
    txTransparentBlt(txDC(),  ll.x, ll.y, ll.width, ll.height, ll.picDown, 0, 0, RGB(255, 255, 255));
}

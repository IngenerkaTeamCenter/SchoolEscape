#pragma once

#include "TXLib.h"
#include "consmenu.cpp"

struct CrashZone
{
    int x1, y1;
    int x2, y2;
};

bool intersect(int al, int ar, int bl, int br)
{
    return ((al <= bl && bl <= ar) || (bl <= al && al <= br));
}

bool intersect(CrashZone a, CrashZone bi)
{
    return (intersect(a.x1, a.x2, bi.x1, bi.x2) && intersect(a.y1, a.y2, bi.y1, bi.y2));
}

struct Bomzh
{
    int x, y;
    int speed;
    int manyframeUp;
    int manyframeDown;
    int manyframeLeft;
    int manyframeRight;
    int width;
    int height;
    int PointStartX1;
    int PointStartX2;
    int PointStartY;
    int direction; // 0 Down   1  Up   2 Left    3 Right
    HDC picDown;
    HDC picUp;
    HDC picLeft;
    HDC picRight;
    int frame;
    int frameTimer;
    CrashZone crash;
    int predX;
    int predY;
};

void drawBomzh(Bomzh b)
{
    if (b.direction == DIRECTION_DOWN)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX1 /*- abs_x*/, b.y - b.PointStartY, b.width, b.height, b.picDown, b.frame * 65, 0, RGB(255, 255, 255));
    }
    else if (b.direction == DIRECTION_UP)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX1 /*- abs_x*/, b.y - b.PointStartY, b.width, b.height, b.picUp, b.frame * 65, 0, RGB(255, 255, 255));
    }
    else if (b.direction == DIRECTION_LEFT)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX2 /*- abs_x*/, b.y - b.PointStartY, b.width - 6, b.height, b.picLeft, b.frame * 64, 0, RGB(255, 255, 255));
    }
    else if (b.direction == DIRECTION_RIGHT)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX2 /*- abs_x*/, b.y - b.PointStartY, b.width - 6, b.height, b.picRight, b.frame * 64, 0, RGB(255, 255, 255));
    }

    //abs_x = b.x - 300;
}

void moveBomzh(Bomzh* b)
{
    int predX = b->x;
    int predY = b->y;
    int maxCountOfFrames = 0;

    if (GetAsyncKeyState(VK_UP))
    {
        b->y -= b->speed;
        b->direction = DIRECTION_UP;
        maxCountOfFrames = b->manyframeUp;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        b->y += b->speed;
        b->direction = DIRECTION_DOWN;
        maxCountOfFrames = b->manyframeDown;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        b->x += b->speed;
        b->direction = DIRECTION_RIGHT;
        maxCountOfFrames = b->manyframeRight;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        b->x -= b->speed;
        b->direction = DIRECTION_LEFT;
        maxCountOfFrames = b->manyframeLeft;
    }

    if (predX != b->x || predY != b->y)
    {
        if (b->frame == 0)
        {
            b->frame = 1;
            b->frameTimer = 0;
        }
        else
        {
            b->frameTimer++;
            if (b->frameTimer >= 20)
            {
                b->frame++;
                if (b->frame >= maxCountOfFrames)
                    b->frame = 1;
                b->frameTimer = 0;
            }
        }
    }
}

void fillCrashZone(Bomzh* b)
{
    b->crash.x1 = b->x - 10;
    b->crash.y1 = b->y - 10;
    b->crash.x2 = b->x + 20;
    b->crash.y2 = b->y + 10;
}

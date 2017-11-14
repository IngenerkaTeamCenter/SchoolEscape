#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.h"

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
};

void drawBomzh(Bomzh b)
{
    if (b.direction == 0)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX1, b.y - b.PointStartY, b.width, b.height, b.picDown, b.frame * 54, 0, RGB(255, 255, 255));
    }
    else if (b.direction == 1)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX1, b.y - b.PointStartY, b.width, b.height, b.picUp, b.frame * 54, 0, RGB(255, 255, 255));
    }
    else if (b.direction == 2)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX2, b.y - b.PointStartY, b.width - 6, b.height, b.picLeft, b.frame * 48, 0, RGB(255, 255, 255));
    }
    else if (b.direction == 3)
    {
        txTransparentBlt(txDC(), b.x - b.PointStartX2, b.y - b.PointStartY, b.width - 6, b.height, b.picRight, b.frame * 48, 0, RGB(255, 255, 255));
    }
}

void moveBomzh(Bomzh* b)
{
    int predX = b->x;
    int predY = b->y;
    int maxCountOfFrames = 0;

    if (GetAsyncKeyState(VK_UP))
    {
        b->y -= b->speed;
        b->direction = 1;
        maxCountOfFrames = b->manyframeUp;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        b->y += b->speed;
        b->direction = 0;
        maxCountOfFrames = b->manyframeDown;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        b->x += b->speed;
        b->direction = 3;
        maxCountOfFrames = b->manyframeRight;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        b->x -= b->speed;
        b->direction = 2;
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

 void scene1(Bomzh b/*, Director d*/)
 {
     while (!GetAsyncKeyState(VK_ESCAPE))
     {
         txSetFillColor(TX_BLACK);
         txRectangle(0, 0, 1200, 900);
         moveBomzh(&b);
         drawBomzh(b);
         //moveDirector(&d);
         //drawDirector(d);
         txSleep(10);
     }
 }

 int main()
 {
     txCreateWindow (1090, 654);
     txBegin();

     //Director d;
     //d.x = 50;
     //...
     //d.picRight = ...

     Bomzh b;
     b.x = 400;
     b.y = 300;
     b.width = 54;
     b.height = 86;
     b.speed = 2;
     b.manyframeRight = 3;
     b.manyframeLeft = 3;
     b.PointStartX1 = 27;
     b.PointStartX2 = 24;
     b.PointStartY = 74;
     b.manyframeUp = 5;
     b.manyframeDown = 5;
     b.direction = 0;
     b.frame = 0;
     b.frameTimer = 0;
     b.picDown = txLoadImage("IMG\\Men\\Homeless\\HomelessDown.bmp");
     b.picUp = txLoadImage("IMG\\Men\\Homeless\\HomelessUp.bmp");
     b.picLeft = txLoadImage("IMG\\Men\\Homeless\\HomelessLeft.bmp");
     b.picRight = txLoadImage("IMG\\Men\\Homeless\\HomelessRight.bmp");

     scene1(b/*, d*/);
     txDeleteDC(b.picDown);
     txDeleteDC(b.picUp);
     txDeleteDC(b.picLeft);
     txDeleteDC(b.picRight);
 }

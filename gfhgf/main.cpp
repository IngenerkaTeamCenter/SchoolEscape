#include "TXLib.h"

struct Bomzh
{
    int x, y;
    int direction; // 0 вниз   1  вверх   2 влево    3 вправо
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
txBitBlt(txDC(), b.x - 27, b.y - 74, 54, 86, b.picDown, b.frame * 54, 0, RGB(255, 255, 255));
}

if (b.direction == 1)
{
txTransparentBlt(txDC(), b.x - 27, b.y - 74, 54, 86, b.picUp, b.frame * 54, 0, RGB(255, 255, 255));
}

if (b.direction == 2)
{
txTransparentBlt(txDC(), b.x - 24, b.y - 74, 48, 86, b.picLeft, b.frame * 48, 0, RGB(255, 255, 255));
}
if (b.direction == 3)
{
txTransparentBlt(txDC(), b.x - 24, b.y - 74, 48, 86, b.picRight, b.frame * 48, 0, RGB(255, 255, 255));
}
}

void moveBomzh(Bomzh b)
{
    int predX = b.x;
    int predY = b.y;

    if (GetAsyncKeyState(VK_UP))
    {
        b.y -= 2;
        b.direction = 1;

        if (b.frame == 0)
        {
            b.frame = 1;
            b.frameTimer = 0;
        }
        else
        {
            b.frameTimer++;
            if (b.frameTimer >= 14)
            {
                b.frame++;
                if (b.frame == 5)
                b.frame = 1;
                b.frameTimer = 0;
            }
        }
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        b.y += 2;
        b.direction = 0;

        if (b.frame == 0)
        {
            b.frame = 1;
            b.frameTimer = 0;
        }
        else
        {
            b.frameTimer++;
            if (b.frameTimer >= 14)
            {
                b.frame++;
                if (b.frame == 5)
                    b.frame = 1;
                b.frameTimer = 0;
            }
        }
    }


    if (GetAsyncKeyState(VK_RIGHT))
    {
        b.x += 2;
        b.direction = 3;

        if (b.frame == 0)
        {
            b.frame = 1;
            b.frameTimer = 0;
        }
        else
        {
            b.frameTimer++;
            if (b.frameTimer >= 20)
            {
                b.frame++;
                if (b.frame == 5)
                    b.frame = 1;
                b.frameTimer = 0;
            }
        }
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
        b.x -= 2;
        b.direction = 2;

        if (b.frame == 0)
        {
            b.frame = 1;
            b.frameTimer = 0;
        }
        else
        {
            b.frameTimer++;
            if (b.frameTimer >= 20)
            {
                b.frame++;
                if (b.frame == 5)
                b.frame = 1;
                b.frameTimer = 0;
            }
        }
    }
}

 void scene1(Bomzh b)
 {
     while (!GetAsyncKeyState(VK_ESCAPE))
     {
         txSetFillColor(TX_BLACK);
         txRectangle(0, 0, 1200, 900);
         moveBomzh(b);
         drawBomzh(b);
         txSleep(10);
     }
 }

 int main()

 {
     txCreateWindow (1090, 654);
     txBegin();

     Bomzh b;
     b.x = 400;
     b.y = 300;
     b.direction = 0;
     b.picDown = txLoadImage("BomzhDown.bmp");
     b.picUp = txLoadImage("BomzhUp.bmp");
     b.picLeft = txLoadImage("BomzhLeft.bmp");
     b.picRight = txLoadImage("BomzhRight.bmp");

     scene1(b);
     txDeleteDC(b.picDown);
     txDeleteDC(b.picUp);
     txDeleteDC(b.picLeft);
     txDeleteDC(b.picRight);

 }

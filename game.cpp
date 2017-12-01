#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.cpp"
#include "Lib\\Director.cpp"
#include "Lib\\Cleaner.cpp"

 void scene1(Bomzh b, Director d, Point p)
 {
    int x = 700;
    int y = 0;
    int direction = 0;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_WHITE);
        txRectangle(0, 0, 1200, 900);
        moveBomzh(&b);
        drawBomzh(b);

        txSetColor(TX_RED, 3);
        txCircle(p.x, p.y, 5);
        txCircle(p.x1, p.y1, 5);
        txCircle(p.x2, p.y2, 5);

        drawDirector(d);
        moveDirector(&d, &p);

        txSetColor(TX_RED);
        txSetFillColor(TX_RED);
        txCircle(x, y, 10);


        if (direction == 0)
        {
            x += 4;
        }
        else if (direction == 1)
        {
            x -= 4;
        }
        else if (direction == 2)
        {
            y += 4;
        }
        else
        {
            y -= 4;
        }

        if (x > txGetExtentX() - 50)
        {
            while (direction == 0)
            {
                direction = random(4);
            }
            x -= 65;
        }
        if (x < 0 + 50)
        {
            while (direction == 1)
            {
                direction = random(4);
            }
            x += 90;
        }

        if (y > txGetExtentY() - 40)
        {
            while (direction == 2)
            {
                direction = random(4);
            }
            y -= 10;
        }
        if (y < 0 + 70)
        {
            while (direction == 3)
            {
                direction = random(4);
            }
            y += 10;
        }

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
    b.width = 54;
    b.height = 100;
    b.speed = 1;
    b.manyframeRight = 2;
    b.manyframeLeft = 2;
    b.PointStartX1 = 27;
    b.PointStartX2 = 24;
    b.PointStartY = 74;
    b.manyframeUp = 4;
    b.manyframeDown = 4;
    b.direction = 0;
    b.frame = 0;
    b.frameTimer = 0;
    b.picDown = txLoadImage("IMG\\Men\\Homeless\\HomelessDown.bmp");
    b.picUp = txLoadImage("IMG\\Men\\Homeless\\HomelessUp.bmp");
    b.picLeft = txLoadImage("IMG\\Men\\Homeless\\HomelessLeft.bmp");
    b.picRight = txLoadImage("IMG\\Men\\Homeless\\HomelessRight.bmp");


    Director d;
    d.x = 500;
    d.y = 600;
    d.speed = 2;
    d.width = 54;
    d.height = 86;
    d.manyframeRight = 3;
    d.manyframeLeft = 3;
    d.PointStartX1 = 27;
    d.PointStartX2 = 24;
    d.PointStartY = 74;
    d.manyframeUp = 5;
    d.manyframeDown = 5;
    d.direction = 0;
    d.frame = 0;
    d.frameTimer = 0;
    d.picDown = txLoadImage ("IMG\\Men\\Girl\\GirlDown.bmp");
    d.picUp = txLoadImage ("IMG\\Men\\Girl\\GirlUp.bmp");
    d.picLeft = txLoadImage ("IMG\\Men\\Girl\\GirlLeft.bmp");
    d.picRight = txLoadImage ("IMG\\Men\\Girl\\GirlRight.bmp");
    d.radius = 170;
    //d.exit_time = 100000;

    Point p;
    p.x = 100;
    p.y = 100;
    p.x1 = 600;
    p.y1 = 100;
    p.x2 = 270;
    p.y2 = 250;
    p.nomerPoint = 1;

    scene1(b, d, p);
    txDeleteDC(b.picDown);
    txDeleteDC(b.picUp);
    txDeleteDC(b.picLeft);
    txDeleteDC(b.picRight);
    txDeleteDC(d.picDown);
    txDeleteDC(d.picUp);
    txDeleteDC(d.picLeft);
    txDeleteDC(d.picRight);
}

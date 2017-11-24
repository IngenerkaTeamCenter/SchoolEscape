#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.cpp"

 void scene1(Bomzh b/*, Director d*/)
 {
    int x = 700;
    int y = 0;
    int direction = 0;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txRectangle(0, 0, 1200, 900);
        moveBomzh(&b);
        drawBomzh(b);

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

         //moveDirector(&d);
         //drawDirector(d);
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

     scene1(b/*, d*/);
     txDeleteDC(b.picDown);
     txDeleteDC(b.picUp);
     txDeleteDC(b.picLeft);
     txDeleteDC(b.picRight);
 }

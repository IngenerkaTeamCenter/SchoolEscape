#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.cpp"
#include "Lib\\Robot.cpp"

 void scene1(Bomzh b, Robot r)
 {

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txRectangle(0, 0, 1200, 900);
        moveBomzh(&b);
        drawBomzh(b);

        moveRobot(&r);
        drawRobot(r);

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

     Robot r;
     r.x = 700;
     r.y = 100;
     r.width = 48;
     r.height = 62;
     r.manyframeRight = 2;
     r.manyframeLeft = 2;
     r.manyframeUp = 4;
     r.manyframeDown = 4;
     r.direction = 0;
     r.frame = 0;
     r.frameTimer = 0;
     r.picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
     r.picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
     r.picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
     r.picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");

     scene1(b, r);

     txDeleteDC(r.picDown);
     txDeleteDC(r.picUp);
     txDeleteDC(r.picLeft);
     txDeleteDC(r.picRight);

     txDeleteDC(b.picDown);
     txDeleteDC(b.picUp);
     txDeleteDC(b.picLeft);
     txDeleteDC(b.picRight);
 }

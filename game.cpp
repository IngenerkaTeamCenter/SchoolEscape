#include "Lib\\TXLib.h"
#include "Lib\\Bomzh.cpp"
#include "Lib\\Robot.cpp"
#include "Lib\\Director.cpp"

 void scene1(Bomzh b, Robot r, Director d, Point p)
 {

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txRectangle(0, 0, 1200, 900);
        moveBomzh(&b);
        drawBomzh(b);

        moveRobot(&r);
        drawRobot(r);

        p.x2 = b.x;
        p.y2 = b.y;

        drawDirector(d);
        moveDirector(&d, &p);

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
    b.speed = 5;
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
    p.x2 = 230;
    p.y2 = 200;
    p.nomerPoint = 1;

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
    r.picDown = txLoadImage ("IMG\\Men\\Girl\\GirlDown.bmp");
    r.picUp = txLoadImage ("IMG\\Men\\Girl\\GirlUp.bmp");
    r.picLeft = txLoadImage ("IMG\\Men\\Girl\\GirlLeft.bmp");
    r.picRight = txLoadImage ("IMG\\Men\\Girl\\GirlRight.bmp");
    /*r.picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
    r.picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
    r.picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
    r.picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");*/

    scene1(b, r, d, p);

    txDeleteDC(r.picDown);
    txDeleteDC(r.picUp);
    txDeleteDC(r.picLeft);
    txDeleteDC(r.picRight);

    txDeleteDC(b.picDown);
    txDeleteDC(b.picUp);
    txDeleteDC(b.picLeft);
    txDeleteDC(b.picRight);

    txDeleteDC(d.picDown);
    txDeleteDC(d.picUp);
    txDeleteDC(d.picLeft);
    txDeleteDC(d.picRight);
}

#include "Lib\\TXLib.h"
#include "Lib\\Robot.cpp"
#include "Lib\\Director.cpp"
#include "Lib\\Bomzh.cpp"
#include "Lib\\consmenu.cpp"


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Director d;
Bomzh b;
Robot r;
 void scene1(Bomzh b, Robot r, Director d, Point p)
 {

    HDC fon = txLoadImage("IMG\\Maps\\Level1\\canteen.bmp");
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        //txSetFillColor(TX_WHITE);
        //txRectangle(0, 0, 1200, 900);
        txBitBlt(txDC(), 0, 0, 1200, 900, fon, 0, 0);

        if(GameMode == 1)
        {
            txCircle(d.x, d.y, d.radius);
        }

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
    txDeleteDC(fon);
 }

 void directionFrameFrameTimer(int *direction, int *frame, int *frameTimer)
 {
    *direction = 0;
    *frame = 0;
    *frameTimer = 0;
 }

void DeletePics(HDC* picDown, HDC* picUp, HDC* picLeft, HDC* picRight)
{
    txDeleteDC(*picDown);
    txDeleteDC(*picUp);
    txDeleteDC(*picLeft);
    txDeleteDC(*picRight);
 }

void MapSchitivanie()
{
    d.x = 100;
    d.y = 100;
    b.x = 300;
    b.y = 500;
    r.x = 700;
    r.y = 100;
    ifstream Map;
    string stroka_Personage;
    string stroka_X;
    string stroka_Y;
    Map.open("Lib\\Map.txt");

    while (Map.good()) {

        getline (Map, stroka_Personage);

        if (strcmp(stroka_Personage.c_str(), "director") == 0)
        {
            getline (Map, stroka_X);
            d.x = atoi(stroka_X.c_str());
            getline (Map, stroka_Y);
            d.y = atoi(stroka_Y.c_str());
        }

        if (strcmp(stroka_Personage.c_str(), "bomzh") == 0)
        {
            getline (Map, stroka_X);
            b.x = atoi(stroka_X.c_str());
            getline (Map, stroka_Y);
            b.y = atoi(stroka_Y.c_str());
        }

        if (strcmp(stroka_Personage.c_str(), "robot") == 0)
        {
            getline (Map, stroka_X);
            r.x = atoi(stroka_X.c_str());
            getline (Map, stroka_Y);
            r.y = atoi(stroka_Y.c_str());
        }
            }

    Map.close();
}

int main(int argc, char *argv[])
{
    const char* nomerPerson;
    if (argc > 1)
    {
        nomerPerson = argv[1];
    }
    else
    {
        nomerPerson = "2";
    }

    MapSchitivanie();
    txCreateWindow (1090, 654);
    txBegin();

    b.width = 62;
    b.height = 84;
    b.speed = 7;
    b.PointStartX1 = 27;
    b.PointStartX2 = 24;
    b.PointStartY = 74;
    b.manyframeRight = 4;
    b.manyframeLeft = 4;
    b.manyframeUp = 4;
    b.manyframeDown = 4;
    directionFrameFrameTimer(&b.direction, &b.frame, &b.frameTimer);
    b.frameTimer = 0;
    b.picDown = txLoadImage("IMG\\Men\\Homeless\\HomelessDown.bmp");
    b.picUp = txLoadImage("IMG\\Men\\Homeless\\HomelessUp.bmp");
    b.picLeft = txLoadImage("IMG\\Men\\Homeless\\HomelessLeft.bmp");
    b.picRight = txLoadImage("IMG\\Men\\Homeless\\HomelessRight.bmp");


    d.speed = 2;
    d.width = 58;
    d.height = 55;
    d.PointStartX1 = 27;
    d.PointStartX2 = 24;
    d.PointStartY = 74;
    d.manyframeRight = 4;
    d.manyframeLeft = 4;
    d.manyframeUp = 4;
    d.manyframeDown = 4;
    directionFrameFrameTimer(&d.direction, &d.frame, &d.frameTimer);
    if(strcmp(nomerPerson, "2") == 0)
    {
        d.picDown = txLoadImage ("IMG\\Men\\Robot\\RobotDown.bmp");
        d.picUp = txLoadImage ("IMG\\Men\\Robot\\RobotUp.bmp");
        d.picLeft = txLoadImage ("IMG\\Men\\Robot\\RobotLeft.bmp");
        d.picRight = txLoadImage ("IMG\\Men\\Robot\\RobotRight.bmp");
    } else if(strcmp(nomerPerson, "1") == 0)
    {
        d.picDown = txLoadImage ("IMG\\Men\\Homeless\\HomelessDown.bmp");
        d.picUp = txLoadImage ("IMG\\Men\\Homeless\\HomelessUp.bmp");
        d.picLeft = txLoadImage ("IMG\\Men\\Homeless\\HomelessLeft.bmp");
        d.picRight = txLoadImage ("IMG\\Men\\Homeless\\HomelessRight.bmp");
    } else if(strcmp(nomerPerson, "3") == 0)
    {
        d.picDown = txLoadImage ("IMG\\Men\\Girl\\GirlDown.bmp");
        d.picUp = txLoadImage ("IMG\\Men\\Girl\\GirlUp.bmp");
        d.picLeft = txLoadImage ("IMG\\Men\\Girl\\GirlLeft.bmp");
        d.picRight = txLoadImage ("IMG\\Men\\Girl\\GirlRight.bmp");
    }
    d.radius = 170;



    Point p;
    p.x = 100;
    p.y = 100;
    p.x1 = 600;
    p.y1 = 100;
    p.x2 = 230;
    p.y2 = 200;
    p.nomerPoint = 1;


    r.width = 50;
    r.height = 62;
    r.speed = 3;
    r.manyframeRight = 4;
    r.manyframeLeft = 4;
    r.manyframeUp = 4;
    r.manyframeDown = 4;
    directionFrameFrameTimer(&r.direction, &r.frame, &r.frameTimer);
    r.picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
    r.picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
    r.picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
    r.picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");

    scene1(b, r, d, p);

    DeletePics(&d.picDown, &d.picUp, &d.picLeft, &d.picRight);
    DeletePics(&b.picDown, &b.picUp, &b.picLeft, &b.picRight);
    DeletePics(&r.picDown, &r.picUp, &r.picLeft, &r.picRight);
}

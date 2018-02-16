#include "Lib\\TXLib.h"
#include "Lib\\Robot.cpp"
#include "Lib\\Director.cpp"
#include "Lib\\Bomzh.cpp"
#include "Lib\\consmenu.cpp"


#include <iostream>
#include <fstream>
#include <string>

/*void CatchCheck(Bomzh b, Director d)
{
    if((d.x - b.x) * (d.x - b.x) + (d.y - b.y) * (d.y - b.y) <= 75)
        {
            cout << "ты облажался";
            exit(1);
            txDestroyWindow();
        }
}*/

using namespace std;

Point p[100];
    /*p.x = 100;
    p.y = 100;
    p.x1 = 600;
    p.y1 = 100;*/

    //point[0].x2 = 230;
    //point[0].y2 = 200;
    //point[0].nomerPoint = 1;

Director director[15];
int nomerDirector = 0;

/*void collisionCheckDirector (Director* d, Point* p)
{
    if(&d[nomer].x == &d[nomer - 1])
    {
        d[nomer].x++// or d[nomer].speed = 0*
    }
}*/

Bomzh b;
Robot robots[100];
int nomerRobota = 0;

 void scene1(Bomzh b, Robot* r, Director* d, Point* p, int nomer_robotov, int nomer_directorov)
 {

    for (int nomer = 0; nomer < nomer_directorov; nomer++)
    {
        p[nomer].x = 100;
        p[nomer].y = 100;
        p[nomer].x1 = 600;
        p[nomer].y1 = 100;
        p[nomer].x2 = b.x;
        p[nomer].y2 = b.y;
        p[nomer].nomerPoint = 1;
    }

    HDC fon = txLoadImage("IMG\\Maps\\Level1\\canteen.bmp");
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        //txSetFillColor(TX_WHITE);
        //txRectangle(0, 0, 1200, 900);
        txBitBlt(txDC(), 0, 0, 1200, 900, fon, 0, 0);

        if(GameMode == 1)
        {
            txCircle(director[0].x, director[0].y, director[0].radius);
        }

        //CatchCheck(b, director[nomerDirector], nomer);

        moveBomzh(&b);
        drawBomzh(b);

        for (int nomer = 0; nomer < nomer_robotov; nomer++)
        {
            moveRobot(&r[nomer]);
            drawRobot(r[nomer]);
        }

        for (int nomer = 0; nomer < nomer_directorov; nomer++)
        {
            p[nomer].x2 = b.x;
            p[nomer].y2 = b.y;
            CatchCheck(b, &director[nomer], nomer);
            drawDirector(d[nomer]);
            moveDirector(&d[nomer], &p[nomer]);
        }
        for (int nomer = 0; nomer < nomer_directorov - 1; nomer++)
        {
            for (int nomer1 = nomer + 1; nomer1 < nomer_directorov; nomer1++)
            {
                while ( abs (d[nomer].x - d[nomer1].x) < 15 && abs (d[nomer].y - d[nomer1].y) < 15)
                {
                    d[nomer1].x = d[nomer1].x + random(-5, 5);
                    d[nomer1].y = d[nomer1].y + random(-5, 5);

                }
            }
        }
/*
        Стул стулья[100];
        for (int номер_стула = 0; номер_стула < 100; номер_стула++)
        {
            стулья[номер_стула].координата_х =
            стулья[номер_стула].масса =
        }
        for (int номер_стула = 0; номер_стула < 100; номер_стула++)
        {
            if ()
        }*/

        /*drawDirector(d);
        moveDirector(&d, &p);*/


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
    director[nomerDirector].x = 100;
    director[nomerDirector].y = 100;
    b.x = 300;
    b.y = 500;
    robots[nomerRobota].x = 700;
    robots[nomerRobota].y = 100;
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
            //d.x = atoi(stroka_X.c_str());
            director[nomerDirector].x = atoi(stroka_X.c_str());
            getline (Map, stroka_Y);
            //d.y = atoi(stroka_Y.c_str());
            robots[nomerDirector].y = atoi(stroka_X.c_str());
            nomerDirector++;
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
            robots[nomerRobota].x = atoi(stroka_X.c_str());
            getline (Map, stroka_Y);
            robots[nomerRobota].y = atoi(stroka_Y.c_str());
            nomerRobota++;
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
    if(strcmp(nomerPerson, "3") == 0)
    {
        b.picDown = txLoadImage ("IMG\\Men\\Robot\\RobotDown.bmp");
        b.picUp = txLoadImage ("IMG\\Men\\Robot\\RobotUp.bmp");
        b.picLeft = txLoadImage ("IMG\\Men\\Robot\\RobotLeft.bmp");
        b.picRight = txLoadImage ("IMG\\Men\\Robot\\RobotRight.bmp");
    } else if(strcmp(nomerPerson, "2") == 0)
    {
        b.picDown = txLoadImage ("IMG\\Men\\Homeless\\HomelessDown.bmp");
        b.picUp = txLoadImage ("IMG\\Men\\Homeless\\HomelessUp.bmp");
        b.picLeft = txLoadImage ("IMG\\Men\\Homeless\\HomelessLeft.bmp");
        b.picRight = txLoadImage ("IMG\\Men\\Homeless\\HomelessRight.bmp");
    } else if(strcmp(nomerPerson, "1") == 0)
    {
        b.picDown = txLoadImage ("IMG\\Men\\Girl\\GirlDown.bmp");
        b.picUp = txLoadImage ("IMG\\Men\\Girl\\GirlUp.bmp");
        b.picLeft = txLoadImage ("IMG\\Men\\Girl\\GirlLeft.bmp");
        b.picRight = txLoadImage ("IMG\\Men\\Girl\\GirlRight.bmp");
    }

    for (int nomer = 0; nomer < nomerRobota; nomer++)
    {
    director[nomer].speed = 2;
    director[nomer].width = 62;
    director[nomer].height = 84;
    director[nomer].PointStartX1 = 27;
    director[nomer].PointStartX2 = 24;
    director[nomer].PointStartY = 74;
    director[nomer].manyframeRight = 4;
    director[nomer].manyframeLeft = 4;
    director[nomer].manyframeUp = 4;
    director[nomer].manyframeDown = 4;
    directionFrameFrameTimer(&director[nomer].direction, &director[nomer].frame, &director[nomer].frameTimer);
    director[nomer].radius = 170;
    if (nomer > 0)
        {
            director[nomer].picDown = director[0].picDown;
            director[nomer].picUp = director[0].picUp;
            director[nomer].picLeft = director[0].picLeft;
            director[nomer].picRight = director[0].picRight;
        }
        else
        {
            director[nomer].picDown = txLoadImage ("IMG\\Men\\Girl\\GirlDown.bmp");
            director[nomer].picUp = txLoadImage ("IMG\\Men\\Girl\\GirlUp.bmp");
            director[nomer].picLeft = txLoadImage ("IMG\\Men\\Girl\\GirlLeft.bmp");
            director[nomer].picRight = txLoadImage ("IMG\\Men\\Girl\\GirlRight.bmp");
        }
    }






    for ( int nomer = 0; nomer < nomerRobota; nomer++)
    {
        robots[nomer].height = 62;
        robots[nomer].speed = 10;
        robots[nomer].manyframeRight = 4;
        robots[nomer].manyframeLeft = 4;
        robots[nomer].manyframeUp = 4;
        robots[nomer].manyframeDown = 4;
        directionFrameFrameTimer(&robots[nomer].direction, &robots[nomer].frame, &robots[nomer].frameTimer);
        robots[nomer].width = 50;
        if (nomer > 0)
        {
            robots[nomer].picDown = robots[0].picDown;
            robots[nomer].picUp = robots[0].picUp;
            robots[nomer].picLeft = robots[0].picLeft;
            robots[nomer].picRight = robots[0].picRight;
        }
        else
        {
            robots[nomer].picDown = txLoadImage("IMG\\Men\\Robot\\RobotDown.bmp");
            robots[nomer].picUp = txLoadImage("IMG\\Men\\Robot\\RobotUp.bmp");
            robots[nomer].picLeft = txLoadImage("IMG\\Men\\Robot\\RobotLeft.bmp");
            robots[nomer].picRight = txLoadImage("IMG\\Men\\Robot\\RobotRight.bmp");
        }
        //robots[nomer].width = 50;

    }

    scene1(b, robots, director, p, nomerRobota, nomerDirector);

    //DeletePics(&d.picDown, &d.picUp, &d.picLeft, &d.picRight);
    DeletePics(&b.picDown, &b.picUp, &b.picLeft, &b.picRight);
    for (int nomer = 0; nomer < nomerRobota; nomer++)
    {
        DeletePics(&robots[nomer].picDown, &robots[nomer].picUp, &robots[nomer].picLeft, &robots[nomer].picRight);
    }

    for (int nomer = 0; nomer < nomerDirector; nomer++)
    {
        DeletePics(&director[nomer].picDown, &director[nomer].picUp, &director[nomer].picLeft, &director[nomer].picRight);
    }
}
